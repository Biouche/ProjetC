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
	char cheminTable[TAILLE_CHEMIN_TABLE];
	memset(cheminTable,0,sizeof(char)*TAILLE_CHEMIN_TABLE);
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
	fprintf(ficTable,"%d%d%d|000|%d|00|000|",tm.tm_year-100,tm.tm_mon+1,tm.tm_mday,DEFAULT_LENGTH_HEADER);

	//Fermuture du fichier
	fclose (ficTable);

	//Test de l'existence du fichier
	if ((ficTable=fopen(cheminTable,"r+"))==NULL)
		return 0;
	fclose (ficTable);
	return 1;
}

//Arguments : request = nom de la table
int DropTable (char* request)
{

	char cheminTable[TAILLE_NOM_TABLE];
	memset(cheminTable,0,sizeof(char)*TAILLE_NOM_TABLE);
	strcpy(cheminTable, "./Tables/");
	strcat(request,".dbf");
	strcat (cheminTable,request);

	FILE * ficTable = NULL;

	//Test de l'existence du fichier
	if ((ficTable=fopen(cheminTable,"r+"))==NULL)
	{
		fclose (ficTable);
		return -1;
	}
	fclose (ficTable);

	//Suppression du fichier
	remove(cheminTable);

	//Test de l'existence du fichier
	if ((ficTable=fopen(cheminTable,"r+"))!=NULL)
		return 0;
	return 1;
}

int InsertInto (char *request)
{

	char cheminTable[TAILLE_NOM_TABLE];
		memset(cheminTable,0,sizeof(char)*TAILLE_NOM_TABLE);
		strcpy(cheminTable, "./Tables/");
		strcat(request,".dbf");
		strcat (cheminTable,request);
	char*buffer=NULL;
	buffer=malloc(50);
	memset(buffer,0,50);
	int nbColonne=0;

		FILE * ficTable = NULL;

		//Test de l'existence du fichier
		if ((ficTable=fopen(cheminTable,"r+"))==NULL)
		{
			printf("return");
			return 0;
		}
		fseek(ficTable,14,SEEK_SET);
		fgets(buffer,3,ficTable);
		printf("<%s>\n",buffer);
		nbColonne=atoi(buffer);
		printf("<%d>\n",nbColonne);

		return 1;
}


int ExecuteAddColumn(char* nomTable,char* nomCol,char* type,int taille)
{
	FILE * ficTable = NULL;
	printf ("nomTable : %s | nomCOl : %s | type : %s | taille : %d", nomTable,nomCol,type,taille);
	//Test de l'existence de la table
	if ((ficTable=fopen(nomTable,"r+"))==NULL)
		return -1;

	return 0;
}
