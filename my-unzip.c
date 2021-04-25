#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char ** argv) {
	int i = 1;
	FILE *file;
	char ch;

	//Checks if there is less than two arguments
	if (argc < 2) {
		printf("my-unzip: file1 [file2...]\n");
		exit(1);
	}
	//Loop file by file
	for (; i<argc; i++) {
		int count = 0;
		size_t read;
			//Exits if reading the file fails
			if ((file = fopen(argv[i], "r")) == NULL) {
				printf("my-unzip: cannot open file\n");
				exit(1);
			}
			//Read count size with fread, then loop and print char until j is equal to count
			//then loop again the next char
			while ((read = fread(&count, sizeof(int), 1, file)) == 1) {
				ch = fgetc(file);
				for (int j = 0; j < count; j++) {
					printf("%c", ch);
				}
			}		
		fclose(file);	
	}			
	printf("\n");
	return 0;
}
//https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm
//https://www.educative.io/edpresso/c-reading-data-from-a-file-using-fread
