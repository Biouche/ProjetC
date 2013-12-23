/*
 * FileManip.c
 *
 *  Created on: Dec 18, 2013
 *      Author: dev
 */


#include <stdio.h>
#include <string.h>
#include "FileManip.h"
#include "Constants.h"

int CreateTable (char* request)
{
	char nomTable [TAILLE_NOM_TABLE];
	FILE ficTable;

	strcat(request,".txt");
	//Test de l'existence du fichier
	ficTable = fopen (request,'r');
	if ( ficTable == NULL)
			return -1;



}
