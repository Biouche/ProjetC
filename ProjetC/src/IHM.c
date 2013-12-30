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



void IHM(void)
{
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
		}
		else
		{
			printf("Erreur de saisie. Cf HELP");
		}
		//recuperation du nom de la table dans le buffer
		CreateTable(buffer);
	}
	else if(strcmp(buffer,"DROP")==0)
	{
		buffer=strtok(NULL," ");
		if(strcmp(buffer,"TABLE")==0)
		{
		buffer=strtok(NULL," ");
		}
		else
		{
			printf("Erreur de saisie. Cf HELP");
		}
		//recuperation du nom de la table dans le buffer
		//DropTable(buffer);
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
		//Select(resquetSelect);
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
		//InsertInto(buffer);
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
		//Delete(resquetSelect);
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
			//printf("requestSelect:<%s>\n",requestSelect);
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
	while(1)
	{
		printf("************Help Menu************\n");
		printf("\tRequest Description:\n");
		printf("\t(0) CREATE TABLE\n");
		printf("\t(1) DROP TABLE\n");
		printf("\t(2) ALTER TABLE\n");
		printf("\t(3) INSERT INTO\n");
		printf("\t(4) SELECT\n");
		printf("\t(5) UPDATE\n");
		printf("\t(6) CREATE INDEX\n");
		printf("\t(7) DELETE\n");
		printf("\t(8) Quitter HELP\n");
		scanf("%d",&i);
		switch(i)
		{
			case 0:printf("*********CREATE TABLE Description*********\n");
				   printf("\Cette request permet la création d'une table\n");
				   printf("*********CREATE TABLE Syntax*********\n");
				   printf("\tExemple : CREATE TABLE <NomTable>\n");
				   break;
			case 1:printf("*********DROP TABLE Description*********\n");
			   	   printf("\tCette request permet la suppression d'une table\n");
			   	   printf("*********DROP TABLE Syntax*********\n");
			   	   printf("\tExemple : DROP TABLE <NomTable>\n");
			   	   break;
			case 2:printf("*********ALTER TABLE Description*********\n");
			   	   printf("\tCette request permet l'ajout d'une colonne via ADD COLUMN au sein d'une table existante\n");
			   	   printf("*********ALTER TABLE Syntax*********\n");
			   	   printf("\tExemple : ALTER TABLE <NomTable> ADD COLUMN <NomColonne> <Type>\n");
			   	   break;
			case 3:printf("*********INSERT INTO Description*********\n");
			   	   printf("\tCette request permet l'ajout d'un enregistrement au sein d'une table existante\n");
			   	   printf("*********INSERT INTO Syntax*********\n");
			   	   printf("\tExemple : INSERT INTO <NomTable> VALUES <ValeursColonne1> <ValeursColonne2>\n");
			   	   break;
			case 4:printf("*********SELECT Description*********\n");
			   	   printf("\tCette request permet la selection partielle ou totale d'une table et l'affiche suivant le souhait de l'utilisateur\n");
			   	   printf("*********SELECT Syntax*********\n");
			   	   printf("\tExemple : SELECT WHERE <NomColonne> = <Valeur> FROM <NomTable>\n");
			   	   break;
			case 5:printf("*********UPDATE Description*********\n");
				   printf("\tCette request permet la modification d'un ou plusieurs enregistrements suivant une condition définie par l'utilisateur\n");
				   printf("*********UPDATE Syntax*********\n");
				   printf("\tExemple : UPDATE <NomTable> SET <NomColonne1> = <Valeur1> <NomColonne2> = <Valeur2> WHERE <NomColonne> = <Valeur>\n");
				   break;
			case 6:printf("*********CREATE INDEX Description*********\n");
			   	   printf("\t\n");
			   	   printf("*********CREATE INDEX Syntax*********\n");
			       printf("\t\n");
			   	   break;
			case 7:printf("*********DELETE Description*********\n");
			   	   printf("\tCette request permet la suppression d'un ou plusieurs enregistrement suivant une condition\n");
			   	   printf("*********DELETE Syntax*********\n");
			   	   printf("\tExemple : DELETE FROM <NomTable WHERE <NomColonne> = <Valeur>\n");
			   	   break;
			case 8:IHM();
			default:printf("Vous devez saisir un chiffre entre 0 et 8.");
		}
	}
}

void PrintError(int errorCode)
{

}


