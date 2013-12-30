/*
 * ParseRequest.c
 *
 *  Created on: Dec 18, 2013
 *      Author: dev
 */

#include <stdio.h>
#include <string.h>
#include <Constants.h>
#include <stdlib.h>
#include <ParseRequest.h>
#include "FileManip.h"

int AlterTable (char * request)
{
	int errorCode = 0;
	char*buffer=NULL;
	buffer=malloc(TAILLE_BUFFER);
	memset(buffer,0,TAILLE_BUFFER);

	//Récupération du nom de la table
	buffer=strtok(request," ");

	//Création de la variable contenant le chemin de la table
	char cheminTable[TAILLE_CHEMIN_TABLE];
	memset(cheminTable,0,sizeof(char)*TAILLE_CHEMIN_TABLE);
	strcpy(cheminTable, "./Tables/");
	strcat (cheminTable,buffer);
	strcat(cheminTable,".dbf");

	//Vérification de la syntaxe de la requête (On doit récupérer ADD COLUMN)
	char requestAlter[TAILLE_REQUEST];
	memset(requestAlter,0,sizeof(char)*TAILLE_REQUEST);
	int i=0;
	for(i=0;i<2;i++)
	{
		buffer=strtok(NULL," ");
		printf("buffer[%d]:<%s>\n",i,buffer);
		strcat(requestAlter,buffer);
		//printf("requestSelect[%d]:<%s>\n",i,requestSelect);
		strcat(requestAlter," ");
		//printf("requestSelect[%d]:<%s>\n",i,requestSelect);
	}
	if (strcmp(requestAlter,"ADD COLUMN ")!=0)
		return 1;

	//On récupére le prochain token et on vérifie
	char*nomCol=NULL;
	buffer=strtok(NULL," ");
	if (buffer==NULL)
		return 1;
	else //On stocke le nom de la colonne
	{
		nomCol=malloc(TAILLE_BUFFER);
		memset(nomCol,0,TAILLE_BUFFER);
		strcpy(nomCol,buffer);
	}

	//On récupére le prochain token et on vérifie
	buffer=strtok(NULL," ");
	if (buffer==NULL)
		return 1;
	else //On stocke le type de la colonne et on appelle la fonction ExecuteAddColumn
	{
		char*typeCol=NULL;
		typeCol=malloc(TAILLE_BUFFER);
		memset(typeCol,0,TAILLE_BUFFER);
		strcpy(typeCol,buffer);
		//On verifie le type de la colonne
		if (strcmp(typeCol,"I")==0)
			errorCode=ExecuteAddColumn(cheminTable,nomCol,typeCol,TAILLE_INT);
		else if (strcmp(typeCol,"F")==0)
			errorCode=ExecuteAddColumn(cheminTable,nomCol,typeCol,TAILLE_NUM);
		else if (strcmp(typeCol,"B")==0)
			errorCode=ExecuteAddColumn(cheminTable,nomCol,typeCol,TAILLE_BOOL);
		else if (strcmp(typeCol,"C")==0)
			errorCode=ExecuteAddColumn(cheminTable,nomCol,typeCol,TAILLE_CHAR);
		else
			return -6;
	}
	return errorCode;
}
