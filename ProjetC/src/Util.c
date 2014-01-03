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

int TestType (char* val,char*colType)
{
	int i,isBoolV,isNumV,isCharV,isIntV,isBoolC,isNumC,isCharC,isIntC=0;

	if(strcmp(colType,"B")==0)
		isBoolC=1;
	else if (strcmp(colType,"I")==0)
		isIntC=1;
	else if (strcmp(colType,"F")==0)
		isNumC=1;
	else if (strcmp(colType,"C")==0)
		isCharC=1;

	printf("Strlen : <%d>\n",strlen(val));
	for (i=0;i<strlen(val);++i)
	{
		//Cas d'un booléen
		if((strlen(val)==1) && ((val[i]==48) || (val[i]==49)))
		{
			isBoolV=1;
			isIntV=1;
			break;
		}
		//On teste s'il y a un point, si oui, c'est surement un float
		else if(val[i]==46 && isIntV==1)
		{
			isNumV=1;
			isIntV=isCharV=0;
			break;
		}
		//Cas d'un int
		else if(48<=val[i] && val[i]<=57)
		{
			if (isNumV==1)
			{
				isCharV=isIntV=0;
			}
			else if (isCharV==1)
			{
				isIntV=isNumV=0;
			}
			else
				isIntV=1;
		}
		//Cas d'un char
		else if ((65<=val[i] && val[i]<=90) || (97<=val[i] && val[i]<=122))
		{
			isIntV=isNumV=0;
			isCharV=1;
		}
	}
	if((isIntV==1 && isIntC==1) || (isCharV==1 && isCharC==1) || (isNumV==1 && isNumC==1) || (isBoolV==1 && isBoolC==1))
		return 1;
	else
		return 0;
}
