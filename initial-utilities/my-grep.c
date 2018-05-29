//
// Created by Xingmin Zhang on 5/13/18.
//
#include <stdio.h>
#include <string.h>

void matchtest(const char *line, const char *pattern) {
    if (strstr(line, pattern) != NULL) {
	    printf(line);
    }
    return;
}

int main(int argc, char *argv[]){

	char *buffer = NULL;
	size_t n = 0;
	if (1 == argc) {
		printf("illegal argument\n");
	} else if (2 == argc) {

		while (getline(&buffer, &n, stdin) != -1) {
			matchtest(buffer, argv[1]);
		}
	} else if (3 == argc) {

		FILE *fp = fopen(argv[2], "r");
		if (fp == NULL) {
			printf("my-grep: failed to open file\n");
			return 1;
		}
		ssize_t t = getline(&buffer, &n, fp);
		while (t != -1) {
			matchtest(buffer, argv[1]);
			t = getline(&buffer, &n, fp);
		}

	} else {
		printf("illegal argument\n");
	}

	return 0;
}
