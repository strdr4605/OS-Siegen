/*****************************************************************************

	FILE:  parent-child.c (AK)
	Bei dem Ablauf des Programms kann nicht vorhergesehen werden, in welcher 
	Reihenfolge die Meldungen der Prozesse auf dem Bildschirm erscheinen (race condition).

	COMPILE (& link) with:	gcc -o parent-child parent-child.c -Wall 

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // fork
#include <sys/wait.h>  // wait

#define MAX 500000  // Konstante

int main()
{
	pid_t pid; 
	int i, j;
	
	pid = fork(); // Kindprozess erzeugen

	// RUECKGABEWERT: Bei Erfolg wird dem Vaterprozess die PID des Kindes 
	// zurueckgegeben und 0 dem Kindprozess. 
	// Bei Fehlern wird dem Vaterprozess -1 zur�ckgegeben.
	
	if (pid<0) {
		printf("Error fork\n"); 
		exit(1);
	}
	if (pid==0) {
		// Kind-Prozess
		for (i=1; i<20; i++) 
		{
			// Last erzeugen: eine Schleife 
			//  die nur Zeit verbraucht
			for ( j=0; j<MAX; j++)
				;
				
			// Buchstabe c ausgeben; und stdout-Puffer leeren
			putchar('c'); fflush(stdout);
		}
		exit(0);
	}
	else {
		// Vater-Prozess
		for (i=1; i<20; i++) 
		{
			// Last erzeugen
			for ( j=0; j<MAX; j++)
				;
			
			// Buchstabe a ausgeben; und stdout-Puffer leeren
			putchar('a'); fflush(stdout); 
		}
	
		int status;
		wait(&status);
		
		printf("\n\tChild State: %d=0x%x\n", status, status);	
	}
	return 0;
}
