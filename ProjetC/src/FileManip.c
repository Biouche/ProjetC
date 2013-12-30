/*
 * FileManip.c
 *
 *  Created on: Dec 18, 2013
 *      Author: dev
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FileManip.h"
#include "Constants.h"
#include "Util.h"

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
	fprintf(ficTable,"%d%d%d|000|0%d|00|000|",tm.tm_year-100,tm.tm_mon+1,tm.tm_mday,DEFAULT_LENGTH_HEADER);

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
	char nomColonne[TAILLE_NOM_TABLE];
	memset(nomColonne,0,sizeof(char)*TAILLE_NOM_TABLE);
	char*buffer=NULL;
	buffer=malloc(50);
	memset(buffer,0,50);
	int nbColonne=0;
	int nbRecord=0;

	FILE * ficTable = NULL;

		//Test de l'existence du fichier
		if ((ficTable=fopen(cheminTable,"r+"))==NULL)
		{
			printf("return");
			return 0;
		}
		fseek(ficTable,15,SEEK_SET); //Déplacement à NbColonne
		fgets(buffer,3,ficTable);  //Récupération NbColonne
		printf("<%s>\n",buffer);
		nbColonne=atoi(buffer);		//Convertion NbColonne en int
		printf("<%d>\n",nbColonne);
		fseek(ficTable,7,SEEK_SET); //Déplacement à nbRecord
		fgets(buffer,4,ficTable);  //Récupération nbRecord
		printf("<%s>\n",buffer);
		nbRecord=atoi(buffer);		//Convertion nbRecord en int
		printf("<%d>\n",nbRecord);
		if(nbColonne>=1)
		{
			fseek(ficTable,0,SEEK_SET);
			fseek(ficTable,22,SEEK_SET);	//recupération nom 1ere colonne
			fgets(nomColonne,31,ficTable);
			printf("<%s>",nomColonne);
			for(i=1;i<nbColonne;i++)		//recupération nom autres colonnes
			{
				fseek(ficTable,-31,SEEK_SET);
				fseek(ficTable,39,SEEK_SET);
				fgets(nomColonne,31,ficTable);
				printf("<%s>",nomColonne);
			}
		}

		nbRecord = nbRecord + 1; //incrémentation nbColonne
		if(nbColonne >= 100)
		{
			fseek(ficTable,7,SEEK_SET);
			fprintf(ficTable,"%d",nbRecord);
		}
		else if(nbRecord>=10)
		{
			fseek(ficTable,7,SEEK_SET);
			fprintf(ficTable,"0%d",nbRecord);
		}
		else
		{
			fseek(ficTable,7,SEEK_SET);
			fprintf(ficTable,"00%d",nbColonne);
		}
		fclose(ficTable);
	return 1;
}


int ExecuteAddColumn(char* nomTable,char* nomCol,char* type,int taille)
{
	FILE * ficTable = NULL;
	//Test de l'existence de la table
	if ((ficTable=fopen(nomTable,"r+"))==NULL)
		return -1;
	//On se déplace dans l'entête du fichier jusqu'à nbCol
	fseek (ficTable,15,SEEK_SET);
	//On récupère nbCOl
	char*buffer=NULL;
	buffer=malloc(50);
	memset(buffer,0,50);
	int nbColonne=0;
	fgets(buffer,3,ficTable);
	nbColonne=atoi(buffer);
	//On vérifie qu'il ne vaut pas 10
	if (nbColonne==10)
		return -3;
	//On vérifie que le nom de la colonne n'est pas > à 31
	 if(strlen(nomCol) > 31)
		 return -4;

	 //Si premier ajout de colonne
	 if (nbColonne==0)
	 {

		 fseek (ficTable,0,SEEK_END);
		 AjoutEspace(nomCol,31);
		 fprintf(ficTable,"%s|0|%s|%d|", nomCol,type,taille);
	 }
	 else
	 {
	 //On vérifie que la colonne n'existe pas
	 }

	return 0;
}
