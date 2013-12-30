/*
 * IHM.c
 *
 *  Created on: Dec 22, 2013
 *      Author: dev
 */
#include <stdio.h>
#include <string.h>
#include <IHM.h>
#include <Constants.h>
#include <stdlib.h>
#include <FileManip.h>
#include <ParseRequest.h>


void IHM(void)
{
	int errorCode=0;
	char request[TAILLE_REQUEST];
	memset(request,0,sizeof(char)*TAILLE_REQUEST);
	gets(request);
	//recuperation de la requete entiere
	char*buffer=NULL;
	buffer=malloc(50);
	memset(buffer,0,50);
	buffer=strtok(request," ");
	//recuperation du premier mot de la requete dans le buffer puis comparaison
	if(strcmp(buffer,"CREATE")==0)
	{
		buffer=strtok(NULL," ");
		if(strcmp(buffer,"TABLE")==0)
		{
			buffer=strtok(NULL," ");
			errorCode=CreateTable(buffer);
			PrintError(errorCode,1);
		}
		else
		{
			printf("Erreur de saisie. Cf HELP");
		}
		//recuperation du nom de la table dans le buffer

	}

	else if(strcmp(buffer,"DROP")==0)
	{
	
		buffer=strtok(NULL," ");
		if(strcmp(buffer,"TABLE")==0)
		{
		buffer=strtok(NULL," ");
		//errorCode=DropTable(buffer);
		}
		else
		{
			printf("Erreur de saisie. Cf HELP");
		}
		//recuperation du nom de la table dans le buffer
	}
	else if(strcmp(buffer,"SELECT")==0)
	{
		char requestSelect[TAILLE_REQUEST];
		memset(requestSelect,0,sizeof(char)*TAILLE_REQUEST);
		int i=0;
		for(i=0;i<5;i++)
		{
			buffer=strtok(NULL," ");
			//printf("buffer[%d]:<%s>\n",i,buffer);
			strcat(requestSelect,buffer);
			//printf("requestSelect[%d]:<%s>\n",i,requestSelect);
			strcat(requestSelect," ");
			//printf("requestSelect[%d]:<%s>\n",i,requestSelect);
		}
		buffer=strtok(NULL," ");
		strcat(requestSelect,buffer);
		//printf("requestSelect:<%s>\n",requestSelect);
		//errorCode=Select(resquetSelect);
	}
	else if(strcmp(buffer,"INSERT")==0)
	{
		buffer=strtok(NULL," ");
		if(strcmp(buffer,"INTO")==0)
		{
		buffer=strtok(NULL," ");
		}
		else
		{
		printf("Erreur de saisie. Cf HELP");
		}
		//recuperation du nom de la table dans le buffer
		//errorCode=InsertInto(buffer);
	}
	else if(strcmp(buffer,"DELETE")==0)
	{
		char requestSelect[TAILLE_REQUEST];
		memset(requestSelect,0,sizeof(char)*TAILLE_REQUEST);
		int i=0;
		for(i=0;i<5;i++)
		{
			buffer=strtok(NULL," ");
			//printf("buffer[%d]:<%s>\n",i,buffer);
			strcat(requestSelect,buffer);
			//printf("requestSelect[%d]:<%s>\n",i,requestSelect);
			strcat(requestSelect," ");
			//printf("requestSelect[%d]:<%s>\n",i,requestSelect);
		}
		buffer=strtok(NULL," ");
		strcat(requestSelect,buffer);
		//errorCode=Delete(resquetSelect);
	}
	else if(strcmp(buffer,"INDEX")==0)
	{
		printf("Index ok");
	}
	else if(strcmp(buffer,"UPDATE")==0)
	{
		char requestSelect[TAILLE_REQUEST];
		memset(requestSelect,0,sizeof(char)*TAILLE_REQUEST);
		while(strcmp(buffer,"WHERE")!=0)
		{
			buffer=strtok(NULL," ");
			strcat(requestSelect,buffer);
			strcat(requestSelect," ");
			//printf("requestSelectLOOP=<%s>\n",requestSelect);
		}
		buffer=strtok(NULL," ");
		strcat(requestSelect,buffer);
		strcat(requestSelect," ");
		buffer=strtok(NULL," ");
		strcat(requestSelect,buffer);
		strcat(requestSelect," ");
		buffer=strtok(NULL," ");
		strcat(requestSelect,buffer);
		//errorCode=Update(requestSelect);
		//errorCode=Update(requestSelect);
	}
	else if(strcmp(buffer,"ALTER")==0)
	{
		buffer=strtok(NULL," ");
		if(strcmp(buffer,"TABLE")==0)
		{
			char requestSelect[TAILLE_REQUEST];
			memset(requestSelect,0,sizeof(char)*TAILLE_REQUEST);
			int i=0;
			for(i=0;i<4;i++)
			{
				buffer=strtok(NULL," ");
				//printf("buffer[%d]:<%s>\n",i,buffer);
				strcat(requestSelect,buffer);
				//printf("requestSelect[%d]:<%s>\n",i,requestSelect);
				strcat(requestSelect," ");
				//printf("requestSelect[%d]:<%s>\n",i,requestSelect);
			}
			buffer=strtok(NULL," ");
			strcat(requestSelect,buffer);
			errorCode=AlterTable(requestSelect);
			PrintError(errorCode,2);
		}
		else
		{
			printf("Erreur de saisie. Cf HELP");
		}
	}
	else if(strcmp(buffer,"HELP")==0)
	{
		Help();
	}
	else
	{
		printf("Erreur de saisie. Cf HELP");
	}
}
void Help(void)
{
	int i=0;
	int quitter=0;
	do
	{
		printf("************Help Menu************\n\n");
		printf("\tRequest Description:\n\n");
		printf("\t(0) CREATE TABLE\n");
		printf("\t(1) DROP TABLE\n");
		printf("\t(2) ALTER TABLE\n");
		printf("\t(3) INSERT INTO\n");
		printf("\t(4) SELECT\n");
		printf("\t(5) UPDATE\n");
		printf("\t(6) CREATE INDEX\n");
		printf("\t(7) DELETE\n");
		printf("\t(8) Quitter HELP\n\n\n");
		scanf("%d",&i);
		switch(i)
		{
			case 0:printf("*********CREATE TABLE Description*********\n\n");
				   printf("\tCette request permet la création d'une table\n\n\n");
				   printf("*********CREATE TABLE Syntax*********\n\n");
				   printf("\tExemple : CREATE TABLE <NomTable>\n\n\n");
				   break;
			case 1:printf("*********DROP TABLE Description*********\n\n");
			   	   printf("\tCette request permet la suppression d'une table\n\n\n");
			   	   printf("*********DROP TABLE Syntax*********\n\n");
			   	   printf("\tExemple : DROP TABLE <NomTable>\n\n\n");
			   	   break;
			case 2:printf("*********ALTER TABLE Description*********\n\n");
			   	   printf("\tCette request permet l'ajout d'une colonne via ADD COLUMN au sein d'une table existante\n\n\n");
			   	   printf("*********ALTER TABLE Syntax*********\n\n");
			   	   printf("\tExemple : ALTER TABLE <NomTable> ADD COLUMN <NomColonne> <Type>\n\n\n");
			   	   break;
			case 3:printf("*********INSERT INTO Description*********\n\n");
			   	   printf("\tCette request permet l'ajout d'un enregistrement au sein d'une table existante\n\n\n");
			   	   printf("*********INSERT INTO Syntax*********\n\n");
			   	   printf("\tExemple : INSERT INTO <NomTable> VALUES <ValeursColonne1> <ValeursColonne2>\n\n\n");
			   	   break;
			case 4:printf("*********SELECT Description*********\n\n");
			   	   printf("\tCette request permet la selection partielle ou totale d'une table et l'affiche suivant le souhait de l'utilisateur\n\n\n");
			   	   printf("*********SELECT Syntax*********\n\n");
			   	   printf("\tExemple : SELECT WHERE <NomColonne> = <Valeur> FROM <NomTable>\n\n\n");
			   	   break;
			case 5:printf("*********UPDATE Description*********\n\n");
				   printf("\tCette request permet la modification d'un ou plusieurs enregistrements suivant une condition définie par l'utilisateur\n\n\n");
				   printf("*********UPDATE Syntax*********\n\n");
				   printf("\tExemple : UPDATE <NomTable> SET <NomColonne1> = <Valeur1> <NomColonne2> = <Valeur2> WHERE <NomColonne> = <Valeur>\n\n\n");
				   break;
			case 6:printf("*********CREATE INDEX Description*********\n\n");
			   	   printf("\t\n\n\n");
			   	   printf("*********CREATE INDEX Syntax*********\n\n");
			       printf("\t\n\n\n");
			   	   break;
			case 7:printf("*********DELETE Description*********\n\n");
			   	   printf("\tCette request permet la suppression d'un ou plusieurs enregistrement suivant une condition\n\n\n");
			   	   printf("*********DELETE Syntax*********\n\n");
			   	   printf("\tExemple : DELETE FROM <NomTable WHERE <NomColonne> = <Valeur>\n\n\n");
			   	   break;
			case 8:quitter=1;
				   break;
			default:printf("Vous devez saisir un chiffre entre 0 et 8.");
		}

	}while(quitter!=1);
	getchar();
	IHM();
}

void PrintError(int errorCode,int fonction)
{

	printf ("Code erreur : %d", errorCode);


}


