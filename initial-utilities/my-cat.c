//
// Created by Xingmin Zhang on 5/13/18.
//

#include <stdio.h>

int print_file_content(const char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
	    printf("my-cat: cannot open file\n");
	    return 1;
    }
    char buffer[128];
    while (fgets(buffer, 128, fp) != NULL){
	    printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    printf("argc: %d\n", argc);
    if (argc == 1) {
	return 0;
    }
    //if (argc != 2) {
    //    printf("Illegal argument.\n");
    //    return 1;
    //}    
    
    for (int i = 1; i < argc; i++) {
	    print_file_content(argv[i]);
    }
    return 0;
    //FILE *fp = fopen(argv[1], "r");
    //if (fp == NULL) {
    //    printf("my-cat: cannot open file\n");
    //    return 1;     
    //}
    
    //char buffer[128];
    //while (fgets(buffer, 128, fp) != NULL) {
    //    printf("%s", buffer);
    //}
    
    //fclose(fp);
    //return print_file_content(argv[1]);
}

