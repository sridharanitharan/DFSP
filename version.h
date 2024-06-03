#ifndef VERSION_H
#define VERSION_H

#include <stdio.h>

int version(char *bin) {
    // Define the ASCII art as an array of strings
    const char *art[] = {
        "                               /T /I          ",
        "                              / |/ | .-~/    ",
        "                          T\\ Y  I  |/  /  _  ",
        "         /T               | \\I  |  I  Y.-~/  ",
        "        I l   /I       T\\ |  |  l  |  T  /   ",
        "   | \\l   \\l  \\I l __l  l   \\   `  _. |    ",
        " \\ ~-l  `\\   `\\  \\  \\\\ ~\\  \\   `. .-~   |    ",
        "  \\   ~-. \"-.  `  \\  ^._ ^. \"-.  /  \\   |    ",
        ".--~-._  ~-  `  _  ~-_.-\"-.\" ._ /._ .\" ./    ",
        " >--.  ~-.   ._  ~>\"    \"\\\\   7   7   ]     ",
        "^.___~\"--._    ~-{  .-~ .  `\\ Y . /    |     ",
        " < ~\"-.  ~       /_/   \\   \\I  Y   : |",
        "   ^-.           ~(_/   \\   >._:   | l______     ",
        "       ^--.,___.-~\"  /_/   !  `-.~\"--l_ /     ~\"-.  ",
        "              (_/ .  ~(   /'     \"~--,Y   -=b-. _) ",
        "               (_/ .  \\  :           / l      c\"~o \\",
        "                \\ /    `.    .     .^   \\_.-~\"~--.  ) ",
        "                 (_/ .   `  /     /       !       )/  ",
        "                  / / _.   '.   .':      /        ' ",
        "                  ~(_/ .   /    _  `  .-<_      -👾️SRIDHARANITHARAN.B",
        "                    /_/ . ' .-~\" `.  / \\  \\          ,z=.",
        "                    ~( /   '  :   | K   \"-.~-______//",
        "                      \"-,.    l   I/ \\_    {--->._(==.",
        "                       //(     \\  <    ~\"~\"     //",
        "                      /' /\\     \\  \\     ,v=.  ((",
        "                    .^. / /\\     \"  } //===-  `",
        "                   / / ' '  \"-., {---(==-",
        "                 .^ '       :  T  ~\"   ll",
        "                / .  .  . : | :!        \\\\ ",
        "               (_/  /   | | j-\"          ~^",
        "                 ~-<_(_.^-~\"               ",
        
    };
    
    // Calculate the number of lines in the ASCII art
    int lines = sizeof(art) / sizeof(art[0]);

    // Print each line of the ASCII art
    for (int i = 0; i < lines; i++) {
        printf("%s\n", art[i]);
    }
    printf("\t\t 📌️ INVALID OPTION 🔹️\n");
    printf("\t🔹️usage %s -[option] -[port number] \n",bin);
    printf("\t🔹️-p  or --port to use a option \n");
    return 0;
}
#endif
