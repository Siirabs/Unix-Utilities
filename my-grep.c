#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
	char *line;
	size_t bufsize = 0;
	size_t characters;
	int i = 2;
	FILE *file;
	//Checks if there is only one given argument
	if(argc == 1) {
		printf("my-grep: searchterm [file...]\n");
		exit(1);
	}
	//Using stdin instead of file if only two given argument
	if(argc == 2) {
		file = stdin;
		while ((characters = getline(&line, &bufsize, file)) != 1) {
			if (strstr(line, argv[1]))
			printf("%s", line);
		}
	}
	//Search line by line for the term
	else {
		for (; i<argc; i++) {
			//Exits if reading the file fails
			if ((file = fopen(argv[i], "r")) == NULL) {
				printf("my-grep: cannot open file\n");
				exit(1);
			}
			//Read file line by line and print the line if it contains the given term.
			while ((characters = getline(&line, &bufsize, file)) != 1) {
				if (strstr(line, argv[1]))
				printf("%s", line);
			}
		}
	}
	fclose(file);
	free(line);
	return 0;
}

//https://c-for-dummies.com/blog/?p=1112
//https://stackoverflow.com/questions/59014090/warning-implicit-declaration-of-function-getline
//https://www.codingunit.com/c-tutorial-searching-for-strings-in-a-text-file
//https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm
