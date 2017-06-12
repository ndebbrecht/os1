#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

int main(void){

     pid_t pid;
     char input[256];
     char *list[256];
     int i;
     char *user;

	for(;;){

	/*Log-Name und current work dirc. Ausgeben + Fehlerbehandlung*/
	printf("> ");
	if((user = getlogin()) == NULL || (getcwd(input, sizeof(input))) == NULL){
		perror("Userinformationen nicht gefunden!!");
		exit(1);
 	}

	printf("%s@%s/:", user, input);

	/*Einlesen des Befehls*/
	fgets(input, 256, stdin);
	user = strchr(input, '\n');

	if(user){
	   *user = '\0';
	}

	/*Ausnahmen Behandeln -> exit*/
	if(strncmp(input, "exit",4)==0){
	   exit(0);
	}

	/*Ausnahme Behandlen -> cd*/
	if(strncmp(input, "cd ",3)==0){
	   strtok(input," ");
	   user = strtok(NULL, "\0");
		if(chdir(user)!=0){
		   perror("Fehler beim Directory wechseln!\n");
		}
		continue;
	}

	if((pid=fork())<0){
	   printf("Fehler!\n");
	}else if(pid == 0){
	   /*Kindprozess*/
	   printf("Kommando: %s ausfuehren\n" , input);
	   /*Eingabe teilen mit strtok()*/
           user = strtok(input, " ");
	   list[0]= user;
	   i = 1;
	   while(i<sizeof(list) && (list[i] = strtok(NULL, " ")) != NULL){
	   	printf("%s\n", list[i]);
		i++;
	   }

	   /*execvp() aufrufen*/
	   if(execvp(user,list) == -1){
     		printf("Befehl unbekannt");
	   }

	  exit(0);

	}

	/*Elterprozess*/
	/*Warten auf Kindprozess*/
	if(pid==waitpid(pid, 0, 0)<0){
	    printf("Fehler!\n");
	}

   }
  return 0;
}
