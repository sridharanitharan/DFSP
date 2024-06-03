#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "print_data.h"
#include "version.h"
#include <openssl/evp.h>
#include <unistd.h>

char* calculate_checksum(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return NULL;
    }

    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;

    md = EVP_sha256();
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);

    while (1) {
        unsigned char buffer[4096];
        size_t bytes_read = fread(buffer, 1, sizeof(buffer), f);
        if (bytes_read == 0) break;
        EVP_DigestUpdate(mdctx, buffer, bytes_read);

        // Introduce a delay of 100 milliseconds (100000 microseconds)
        usleep(100000);
    }

    EVP_DigestFinal_ex(mdctx, hash, &hash_len);

    char* hex_digest = malloc((hash_len * 2) + 1);
    if (hex_digest == NULL) {
        fclose(f);
        EVP_MD_CTX_free(mdctx);
        return NULL;
    }

    for (int i = 0; i < hash_len; i++) {
        sprintf(hex_digest + (i * 2), "%02x", hash[i]);
    }
    hex_digest[hash_len * 2] = '\0';

    fclose(f);
    EVP_MD_CTX_free(mdctx);
    return hex_digest;
}

void verify_integrity() {
    char* expected_checksum = "41d8514b7e3100cab959fd4462afb9e648aa7f9e13167c8c7826e6161a3f46cd";
    char* current_checksum = calculate_checksum("version.h");
    if (current_checksum == NULL) {
        exit(1);
    }

    if (strcmp(current_checksum, expected_checksum) != 0) {
        printf("Error: Code has been modified. Execution halted.\n");
        exit(1);
    }

    free(current_checksum);
}
int main(int argc ,char *argv[]){
  verify_integrity();
        char *dev;
        pcap_t* handle;
        int port;
        char error[PCAP_BUF_SIZE];
        struct bpf_program fp;
        char filter[20];
	bpf_u_int32 ip;
	bpf_u_int32 netmask;
	
  if(argc<3){
	version(argv[0]);
	exit(-1);
    }
        if(strcmp("-p",argv[1]) == 0 || strcmp("--port",argv[1]) == 0){
	    port = atoi(argv[2]);
	    snprintf(filter,sizeof(filter),"port %d",port);
	dev = pcap_lookupdev(error);
	if( dev == NULL){
	  printf("cannot open  the interface ERROR : %s",error);
	  exit(-1);
	  }
	printf("sniffing to %s a device",dev); 
	if(pcap_lookupnet(dev,&ip,&netmask,error) == -1){
	    printf("cannot acquire netmask address ERROR: %s \n",error);
	    exit(-1);
	  }
	
	handle = pcap_open_live(dev,BUFSIZ,1,1,error);
	if(handle == NULL){
	    printf("ERROR %s",error);
	    exit(-1);
	    }
	if(pcap_compile(handle,&fp,filter,1,netmask) == -1){
	    printf("cannot parse a filter \n");
	    exit(-1);
	    }
	if(pcap_setfilter(handle,&fp) == -1){
	  printf("cannot set a filter \t error : %s",pcap_geterr(handle));
	  exit(-1);
	  }
	pcap_loop(handle,0,data_print,NULL);
	pcap_close(handle);
	return 0;
	}else{
	  printf("some went is wrong check your internet connection \n");
	  }

    }
