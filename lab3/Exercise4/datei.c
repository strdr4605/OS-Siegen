/*****************************************************************************

	FILE:  datei.c (AK)

	COMPILE (& link) with:	gcc -o datei datei.c -Wall -Werror

******************************************************************************/
// 

#include <stdio.h>  // printf, fgets
#include <fcntl.h>
#include <stdlib.h> // exit
#include <string.h> // strlen 
#include <unistd.h> // write

int main() 
{
	int fd, nw;
	char text[100];

	printf("Ausgabetext: ");
	fgets(text, 100, stdin);
		
	fd = open( "datei.txt", O_CREAT | O_WRONLY, 0600);
	if (fd < 0) {
		perror("Fehler bei open"); 
		exit(1);
	}

	printf("fd=%d, text=%s\n", fd, text);
	nw = write(fd, text, strlen(text));    // Achtung: inkl. '\n' 
	if (nw<0) {
		perror("Fehler bei write"); 
		exit(1);
	}
	
	printf("%d Bytes geschrieben\n", nw);
	
	close(fd);
	return 0;
}

