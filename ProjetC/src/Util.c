/*
 * Util.c
 *
 *  Created on: Dec 30, 2013
 *      Author: dev
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constants.h"
#include "Util.h"

void CompleterEspace (char* str,int nbMax)
{
	int nbEspaces=nbMax-strlen(str);
	int i=0;
	for (i=0;i<nbEspaces;i++)
	{
		strcat (str," ");
	}
}

void AjouterEspace (char* str,int nbEspaces)
{
	int i=0;
		for (i=0;i<nbEspaces;i++)
		{
			strcat (str," ");
		}
}
