/*
 * FileManip.c
 *
 *  Created on: Dec 18, 2013
 *      Author: dev
 */


#include <stdio.h>
#include <string.h>
#include <time.h>
#include "FileManip.h"
#include "Constants.h"

//Arguments : request = nom de la table
int CreateTable (char* request)
{
	char cheminTable[TAILLE_NOM_TABLE];
	memset(cheminTable,0,sizeof(char)*TAILLE_NOM_TABLE);
	strcpy(cheminTable, "./Tables/");
	strcat(request,".dbf");
	strcat (cheminTable,request);

	FILE * ficTable = NULL;

	//Test de l'existence du fichier
	if ((ficTable=fopen(cheminTable,"r+"))!=NULL)
		return -1;

	//Création du nouveau fichier
	if ((ficTable=fopen(cheminTable,"w+"))==NULL)
		return 0;
	//Récupération de la date
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	//Ajout du header de base dans le fichier
	fprintf(ficTable,"%d%d%d|--0|%d|-0|--0|",tm.tm_year-100,tm.tm_mon+1,tm.tm_mday,DEFAULT_LENGTH_HEADER);

	//Fermuture du fichier
	fclose (ficTable);

	//Test de l'existence du fichier
	if ((ficTable=fopen(cheminTable,"r+"))==NULL)
		return 0;
	return 1;
}
