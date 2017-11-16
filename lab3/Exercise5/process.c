/*****************************************************************************

	FILE:  process.c  (AK)

	COMPILE (& link) with:	  gcc -o process process.c -Wall

******************************************************************************/

#include <sys/types.h>
#include <unistd.h>  // braucht fork
#include <stdio.h>   // printf, puts
#include<sys/wait.h>
#include <stdlib.h>  // exit


int main(int argc,  char** argv)
{
	pid_t retPid;    // Prozess ID
	int stat;

	retPid = fork();
	if (retPid<0) {
		perror("Fehler bei fork\n");
		exit(1);
	}
	if (retPid == 0) {
		/*
		  Code des Kindes (Das Kind laeuft im if-Teil weiter,
		  da der Rueckgabewert von fork() fuer ihn 0 ist.)
		*/

		printf("\nHier ist das Kind\n");
		if(argc==1)
			execlp("ls", "ls", (char *)NULL);
		else {
			sleep(atoi(argv[1]));
			printf("Printed message after sleep from child.\n");
		}
		/*
		// Programmteil parallel zum Vater Prozess ausgefuehrt
		...
		*/

		// Ende des Kindes
		exit(0);

		/*
		  (exit(0) darf nicht vergessen werden,
		  weil der Kind-Prozess sonst dem Code
		  nach der if-else-Anweisung ausfuehren wuerde!
		*/
	}
	else
	{
		/* Code des Vaters
		   Der Vater laeuft nicht in den if-Teil, weil
		   der Rueckgabewert von fork() fuer ihn die
		   PID des Kindess ist, deren Wert stets ungleich 0 ist.
		*/

		printf("\nHier ist der Vater\n\n");
		wait(&stat);
		if (WIFEXITED(stat))
        	printf("Exit status of child: %d\n", WEXITSTATUS(stat));
		/*
		// Programmteil parallel zum Kind-Prozess ausgefuehrt
		...
		*/

		puts("Programmende.");
	}

	exit(0);
}
