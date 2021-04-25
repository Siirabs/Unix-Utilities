#include <stdio.h>
#include <stdlib.h>
#define MAX 512
int main(int argc, char ** argv) {
	char c[MAX];
	FILE *file;
	int i = 1;
	//Checks if there is only one given argument
	if(argc == 1) {
		return 0;
	}
	//Loop file by file
	for (; i<argc; i++) {
		//Exits if reading the file fails
		if ((file = fopen(argv[i], "r")) == NULL) {
			printf("my-cat: cannot open file\n");
			exit(0);
		}
		//Read until end of file
		while ((fgets(c, MAX, file)) != NULL) {
			printf("%s", c);
		}	
		
	}
	fclose(file);

	return 0;
}

//https://stackoverflow.com/questions/5417370/c-warning-statement-with-no-effect
