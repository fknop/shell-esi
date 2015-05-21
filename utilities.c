#include "utilities.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


/*
 * getcwd : nom du dossier courant
 *
 * retourne : 
 *  - une chaine \0 terminée sans erreur
 *  - NULL en cas d'erreur
 *
 * La chaine du directory doit être liberée
 *
 */
void shell_prompt() 
{
	char * directory = NULL;

	if ((directory = getcwd(NULL, 0)) != NULL)
	{
		printf("[ESI-Shell]:%s$ ", directory);
		free(directory);
	}
}

/**
 * Une allocation interne est plus appropriée, peut être que l'utilisateur n'a
 * pas alloué assez de place. A méditer.
 */
int split(char ** tab, char * cmd, char * splitter)
{
	int i = (tab != NULL && cmd != NULL && splitter != NULL) ? 0 : -1;

	if (i == 0)
	{
		tab[i] = strtok(cmd, "\t \n");

		while (tab[i] != NULL) {
			i++;
			tab[i] = strtok(NULL, splitter);
		}
	}

	return i;
}
