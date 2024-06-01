#ifndef PRINT_DATA_H
#define PRINT_DATA_H
#include <ctype.h>
#include <time.h>

void data_print(u_char *count, const struct pcap_pkthdr *header,const u_char *packets){
  printf("\nrecived at %s\n",ctime((const time_t*)&header->ts.tv_sec));
  printf("packet's length %d\n",header->len);
  printf("payload's \n");
  for(int i = 0 ; i < header->len;i++){
    if(isprint(packets[i])){
      printf("%c",packets[i]);
    }else{
      printf(".");
      }
    if(i%32==0 && i!=0 ){
      printf("\n");
      }
    }
  }
#endif 
