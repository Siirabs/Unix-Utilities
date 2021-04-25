all: my-cat my-grep my-zip my-unzip

cat:
	gcc -o my-cat my-cat.c -std=c99 -Wall -Werror

grep:
	gcc -o my-grep my-grep.c -std=c99 -Wall -Werror
	
zip:
	gcc -o my-zip my-zip.c -std=c99 -Wall -Werror
	
unzip:
	gcc -o my-unzip my-unzip.c -std=c99 -Wall -Werror
