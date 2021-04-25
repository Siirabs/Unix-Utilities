#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char ** argv) {
	int i = 1;
	FILE *file;
	char ch;
	//Checks if there is less than two arguments
	if (argc < 2) {
		printf("my-zip: file1 [file2...]\n");
		exit(1);
	}
	//Loop file by file
	for (; i<argc; i++) {
		int count = 0;
		int previous = -1;
			//Exits if reading the file fails
			if ((file = fopen(argv[i], "r")) == NULL) {
				printf("my-zip: cannot open file\n");
				exit(1);
			}
			//Read file character by character
			while ((ch = fgetc(file)) != EOF) {
				//If the next character is the same then the previous one increase counter.
				if (previous == -1) {				
					previous = ch;
					count++;
				}
				//If the next character is different then the previous one 
				//write the count and char to file + reset the count
				else if ( ch != previous) {
					fwrite(&count, sizeof(int), 1, stdout);
					fputc(previous, stdout);
					count = 1;
				} 
				else {
					count++;
				}
				previous = ch;
			}
		fclose(file);	

	}	
		
	
	return 0;
}
//https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
//https://www.geeksforgeeks.org/fgetc-fputc-c/
//https://www.geeksforgeeks.org/run-length-encoding/
