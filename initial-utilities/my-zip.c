//
// Created by Xingmin Zhang on 5/13/18.
//
#include <stdio.h>

void zip(const char* path) {
	FILE *fp = fopen(path, "r");
	if (fp == NULL) {
		printf("my-zip: cannot open file");
		return;
	} else {
		//printf("enter 1111\n");
		int count = 1;
		//printf("count: %d\n", count);
		int character = getc(fp);
		//printf("first character is: %c\n", (char) character);
		//bool in = true;
		int next;
		while (character != EOF) {
			next = getc(fp);
			//printf("next: %d\n", next);
			if (next != character) {
				//write out
				//printf("%d%c", count, (char)character);
				fwrite(&count, sizeof(count), 4, stdout);
				fwrite(&character, sizeof(character), 1, stdout);
				character = next;
				count = 1;
			} else {
				count++;
			}
		}
		fclose(fp);
		return;
	}
}

int main(int argc, char * argv[]) {
	if (1 == argc) {
		printf("my-zip: file1 [file2 ...]\n");
		return 1;
	} else {
		for (int i = 1; i < argc; i++) {
			//FILE *fp = fopen(argv[i], "r");
			zip(argv[i]);
			//printf("zip %s", argv[i]);
		}
		return 0;
	}

}
