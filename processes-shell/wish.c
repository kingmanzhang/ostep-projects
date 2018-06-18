#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	if (1 == argc) {
		char *promp = "wish> ";
		char exitstring[] = "exit";
		char *input = NULL;
		size_t bfsize = 128;
		size_t exitsize = 4;
		pid_t pid;
		int cmdrs;
		while (1) {
			fputs(promp, stdout);
			ssize_t t = getline(&input, &bfsize, stdin);		
			if (t != -1) {
				//printf("command: %s", input);
				char *inputline;
				char *token;
				inputline = input;
				token = strtok_r(input, " ", &inputline);
				//printf("command is : %s\n", token);
				//printf("token length: %d\n", strlen(token));
				//printf("string length: %d\n", strlen(exitstring));
					if (strncmp(token, "exit", strlen(exitstring)) == 0) {
						exit(0);
					} else if(strncmp(token, "cd", strlen("cd")) == 0) {
						printf("%s\n", "command: cd");
						token = strtok_r(input, " ", &inputline);
						if (token == NULL || (token = strtok_r(input, " ", &inputline)) != NULL) {
							printf("%s\n", "usuage: cd argu");
						} else {
							int rs_chdir = chdir(token);
							if (rs_chdir != 0) {
								printf("%s\n", "error to use chdir");
							}
						}
					} else if (strncmp(token, "path")== 0) {
						printf("%s\n", "command: path");
					} else {
						printf("command: %s\n", token);
						//while (token != NULL) {
						//	printf("%s\n", token);
						//	token = strtok_r(NULL, " ", &inputline);
						//}
						int rs = fork();
						if (rs < 0) {
							printf("fork failed");
						} else	if (rs == 0) {
							//printf("child: processing command\n");
							char *path = "/bin/ls";
							//const char * const lscmd = "ls";
							char *const lscmds[] = {"/bin/ls","-l", "/home/aaron", NULL};
							//lscmds[0] = lscmd;
							cmdrs = execv(path, lscmds);
							char *path2 = "/usr/bin/ls";
							cmdrs = execv(path2, lscmds);
							printf("this should not get printed\n");
						} else  {
							pid = wait(NULL);
						}
						//if (strncmp(input, exitstring, exitsize) == 0) {
						//	exit(0);
						//}
					}
				}
		}
	} else if (2 == argc) {
		printf("addition argument is provided\n");
		printf("second argument is: %s\n", argv[1]);
	}

	exit(0);
}
