//
// Created by Xingmin Zhang on 5/13/18.
//

#include <stdio.h>


int main(int argc, char *argv[]) {
    printf("argc: %d\n", argc);
    if (argc != 2) {
        printf("Illegal argument.\n");
        return 1;
    }    
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("cannot open file\n");
        return 1;     
    }
    
    char buffer[128];
    while (fgets(buffer, 128, fp) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(fp);
    return 0;
}
