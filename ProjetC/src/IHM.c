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
		buffer=strtok(NULL," ");
		//recuperation du nom de la table dans le buffer
		CreateTable(buffer);
	}
	if(strcmp(buffer,"DROP")==0)
	{
		buffer=strtok(NULL," ");
		buffer=strtok(NULL," ");
		//recuperation du nom de la table dans le buffer
		//DropTable(buffer);
	}
	if(strcmp(buffer,"SELECT")==0)
	{
		char requestSelect[TAILLE_REQUEST];
		memset(requestSelect,0,sizeof(char)*TAILLE_REQUEST);
		int i=0;
		for(i=0;i<5;i++)
		{
			buffer=strtok(NULL," ");
			strcat(requestSelect,buffer);
			strcat(requestSelect," ");
		}
		buffer=strtok(NULL," ");
		strcat(requestSelect,buffer);
		//Select(resquetSelect);
		}
	if(strcmp(buffer,"INSERT")==0)
	{
		printf("Create ok");
	}
	if(strcmp(buffer,"DELETE")==0)
	{
		printf("Create ok");
	}
	if(strcmp(buffer,"INDEX")==0)
	{
		printf("Index ok");
	}
	if(strcmp(buffer,"UPDATE")==0)
	{
		printf("Create ok");
	}
	if(strcmp(buffer,"CREATE")==0)
	{
		printf("Create ok");
	}
	if(strcmp(buffer,"ALTER")==0)
	{
		printf("Create ok");
	}
	
}

void Help(void)
{

}

void PrintError(int errorCode)
{

}


