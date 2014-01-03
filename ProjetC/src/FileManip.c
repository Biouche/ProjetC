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
#include <FileManip.h>
#include "Constants.h"
#include "Util.h"

//Arguments : request = nom de la table
int CreateTable(char* request) {
	char cheminTable[TAILLE_CHEMIN_TABLE];
	memset(cheminTable, 0, sizeof(char) * TAILLE_CHEMIN_TABLE);
	strcpy(cheminTable, "./Tables/");
	strcat(request, ".dbf");
	strcat(cheminTable, request);

	FILE * ficTable = NULL;

	//Test de l'existence du fichier
	if ((ficTable = fopen(cheminTable, "r+")) != NULL)
		return -1;
	//Création du nouveau fichier
	if ((ficTable = fopen(cheminTable, "w+")) == NULL)
		return 0;
	//Récupération de la date
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	//Ajout du header de base dans le fichier
	if (tm.tm_mday >= 10 && (tm.tm_mon + 1) >= 10)
		fprintf(ficTable, "%d%d%d|000|0%d|00|000|", tm.tm_year - 100,
				tm.tm_mon + 1, tm.tm_mday, DEFAULT_LENGTH_HEADER);
	else if (tm.tm_mday < 10 && (tm.tm_mon + 1) >= 10)
		fprintf(ficTable, "%d%d0%d|000|0%d|00|000|", tm.tm_year - 100,
				tm.tm_mon + 1, tm.tm_mday, DEFAULT_LENGTH_HEADER);
	else if ((tm.tm_mon + 1) < 10 && tm.tm_mday >= 10)
		fprintf(ficTable, "%d0%d%d|000|0%d|00|000|", tm.tm_year - 100,
				tm.tm_mon + 1, tm.tm_mday, DEFAULT_LENGTH_HEADER);
	else
		fprintf(ficTable, "%d0%d0%d|000|0%d|00|000|", tm.tm_year - 100,
				tm.tm_mon + 1, tm.tm_mday, DEFAULT_LENGTH_HEADER);
	//Fermuture du fichier
	fclose(ficTable);

	//Test de l'existence du fichier
	if ((ficTable = fopen(cheminTable, "r+")) == NULL)
		return 0;
	fclose(ficTable);
	return 1;
}

//Arguments : request = nom de la table
int DropTable(char* request) {

	char cheminTable[TAILLE_NOM_TABLE];
	memset(cheminTable, 0, sizeof(char) * TAILLE_NOM_TABLE);
	strcpy(cheminTable, "./Tables/");
	strcat(request, ".dbf");
	strcat(cheminTable, request);

	FILE * ficTable = NULL;

	//Test de l'existence du fichier
	if ((ficTable = fopen(cheminTable, "r+")) == NULL) {
		fclose(ficTable);
		return -1;
	}
	fclose(ficTable);

	//Suppression du fichier
	remove(cheminTable);

	//Test de l'existence du fichier
	if ((ficTable = fopen(cheminTable, "r+")) != NULL)
		return 0;
	return 1;
}

int InsertInto(char *request) {

	char cheminTable[TAILLE_NOM_TABLE];
	memset(cheminTable, 0, sizeof(char) * TAILLE_NOM_TABLE);
	strcpy(cheminTable, "./Tables/");
<<<<<<< HEAD
	strcat(request,".dbf");
	
	strcat (cheminTable,request);
=======
>>>>>>> branch 'master' of https://github.com/Biouche/ProjetC.git
	strcat(request, ".dbf");

	strcat(cheminTable, request);
	char nomColonne[TAILLE_NOM_TABLE];
<<<<<<< HEAD
	memset(nomColonne,0,sizeof(char)*TAILLE_NOM_TABLE);
	char tailleColonne[TAILLE_NOM_TABLE];
	memset(tailleColonne,0,sizeof(char)*TAILLE_NOM_TABLE);
	char valColonne[TAILLE_NOM_TABLE];
	memset(valColonne,0,sizeof(char)*TAILLE_NOM_TABLE);
	char*buffer=NULL;
	buffer=malloc(50);
	memset(buffer,0,50);
	int taillevalColonne=0;
	int nbColonne=0;
	int nbRecord=0;
	memset(nomColonne, 0, sizeof(char) * TAILLE_NOM_TABLE);
	strcat(cheminTable, request);
	char*buffer = NULL;
	buffer = malloc(50);
	memset(buffer, 0, 50);
	int nbColonne = 0;
	int nbRecord = 0;
	int i=0;
	int tailleColonneNum = 0;
	int tmp = 0;
	int j=0;
=======
	memset(nomColonne, 0, sizeof(char) * TAILLE_NOM_TABLE);
	strcat(cheminTable, request);
	char*buffer = NULL;
	buffer = malloc(50);
	memset(buffer, 0, 50);
	int nbColonne = 0;
	int nbRecord = 0;
>>>>>>> branch 'master' of https://github.com/Biouche/ProjetC.git

	FILE * ficTable = NULL;
	FILE * fictmp = NULL;

<<<<<<< HEAD
		//Test de l'existence du fichier
		if ((ficTable=fopen(cheminTable,"r+"))==NULL)
		{
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
			fictmp=fopen("./Tables/tmp.dbf","w+");	//ouverture fichier temporaire
			fseek(ficTable,0,SEEK_SET);
			fseek(ficTable,22,SEEK_SET);	//recupération nom 1ere colonne
			fgets(nomColonne,31,ficTable);
			printf("<%s>\n",nomColonne);
			fprintf(fictmp,"%s|",nomColonne);	//Ecriture nom 1ere colonne dans le fichier tmp
			fseek(ficTable,6,SEEK_CUR);
			fgets(tailleColonne,3,ficTable);
			printf("<%s>\n",tailleColonne);
			fprintf(fictmp,"%s|",tailleColonne);	//Ecriture taille 1ere colonne dans le fichier tmp
			for(i=1;i<nbColonne;i++)		//recupération nom autres colonnes
			{
				fseek(ficTable,1,SEEK_CUR);
				fgets(nomColonne,31,ficTable);
				printf("<%s>\n",nomColonne);
				fprintf(fictmp,"%s|",nomColonne);	//Ecriture nom autres colonne dans le fichier tmp
				fseek(ficTable,6,SEEK_CUR);
				fgets(tailleColonne,3,ficTable);
				printf("<%s>\n",tailleColonne);
				fprintf(fictmp,"%s|",tailleColonne);	//Ecriture taille autres colonne dans le fichier tmp
			}
		}
		nbRecord = nbRecord + 1; //incrémentation nbRecord
		fseek(ficTable,0,SEEK_END);
		fseek(fictmp,0,SEEK_SET);
		fprintf(ficTable," |");
		if(nbRecord >= 100)
			fprintf(ficTable,"%d|",nbRecord);
		else if(nbRecord>=10)
			fprintf(ficTable,"0%d|",nbRecord);
		else
			fprintf(ficTable,"00%d|",nbRecord);
		for(i=0;i<nbColonne;i++)
		{
			fgets(nomColonne,31,fictmp);
			printf("Entrer la valeur pour la colonne: <%s> \n",nomColonne);
			gets(valColonne);
			taillevalColonne=strlen(valColonne);
			printf("taillevalColonne = <%d> \n",taillevalColonne);
			fseek(fictmp,1,SEEK_CUR);
			fgets(tailleColonne,3,fictmp);
			printf("tailleColonne= <%s> \n",tailleColonne);
			tailleColonneNum=atoi(tailleColonne);
			printf("tailleColonneNum = <%d> \n",tailleColonneNum);
			tmp = tailleColonneNum-taillevalColonne;
			printf("tmp = <%d> \n",tmp);
			for(j=0;j<tmp;j++)
			{
				fprintf(ficTable," ");
			}
			fprintf(ficTable,"%s|",valColonne);
			fseek(fictmp,1,SEEK_CUR);
		}
		if(nbRecord >= 100)
		{
			fseek(ficTable,7,SEEK_SET);
			fprintf(ficTable,"%d",nbRecord);
=======
	//Test de l'existence du fichier
	if ((ficTable = fopen(cheminTable, "r+")) == NULL) {
		printf("return");
		return 0;
	}
	fseek(ficTable, 15, SEEK_SET); //Déplacement à NbColonne
	fgets(buffer, 3, ficTable);  //Récupération NbColonne
	printf("<%s>\n", buffer);
	nbColonne = atoi(buffer);		//Convertion NbColonne en int
	printf("<%d>\n", nbColonne);
	fseek(ficTable, 7, SEEK_CUR); //Déplacement à nbRecord
	fgets(buffer, 4, ficTable);  //Récupération nbRecord
	printf("<%s>\n", buffer);
	nbRecord = atoi(buffer);		//Convertion nbRecord en int
	printf("<%d>\n", nbRecord);
	if (nbColonne >= 1) {
		fseek(ficTable, 0, SEEK_CUR);
		fseek(ficTable, 22, SEEK_CUR);	//recupération nom 1ere colonne
		fgets(nomColonne, 31, ficTable);
		printf("<%s>", nomColonne);
		int i = 0;
		for (i = 1; i < nbColonne; i++)		//recupération nom autres colonnes
				{
			fseek(ficTable, -31, SEEK_CUR);
			fseek(ficTable, 39, SEEK_CUR);
			fgets(nomColonne, 31, ficTable);
			printf("<%s>", nomColonne);
		}
>>>>>>> branch 'master' of https://github.com/Biouche/ProjetC.git
	}
	//Test de l'existence du fichier
	if ((ficTable = fopen(cheminTable, "r+")) == NULL) {
		printf("return");
		return 0;
	}
	fseek(ficTable, 14, SEEK_SET);
	fgets(buffer, 3, ficTable);
	printf("<%s>\n", buffer);
	nbColonne = atoi(buffer);
	printf("<%d>\n", nbColonne);
	nbRecord = nbRecord + 1; //incrémentation nbColonne
	if (nbColonne >= 100) {
		fseek(ficTable, 7, SEEK_SET);
		fprintf(ficTable, "%d", nbRecord);
	} else if (nbRecord >= 10) {
		fseek(ficTable, 7, SEEK_SET);
		fprintf(ficTable, "0%d", nbRecord);
	} else {
		fseek(ficTable, 7, SEEK_SET);
		fprintf(ficTable, "00%d", nbColonne);
	}
	fclose(ficTable);
	return 1;
}

int ExecuteAddColumn(char* nomTable, char* nomCol, char* type, int taille) {
	char*buffer = NULL;
	buffer = malloc(TAILLE_BUFFER);
	memset(buffer, 0, TAILLE_BUFFER);
	FILE * ficTable = NULL;

	//Test de l'existence de la table
	if ((ficTable = fopen(nomTable, "r+")) == NULL)
		return -1;

	//On vérifie que le nom de la colonne n'est pas > à 31
	if (strlen(nomCol) > 31)
		return -4;

	//On se déplace dans l'entête du fichier jusqu'à nbCol
	fseek(ficTable, NB_COL, SEEK_SET);
	//On récupère nbCol
	int nbColonne = 0;
	if (fgets(buffer, 3, ficTable) == NULL)
		return 1;
	nbColonne = atoi(buffer);

	//Si premier ajout de colonne
	if (nbColonne == 0) {
		//On se repositionne au niveau de nbCol
		fseek(ficTable, NB_COL, SEEK_SET);
		//On incrémente nbCol de 1
		fprintf(ficTable, "0%d", nbColonne + 1);

		//On se déplace dans l'entête du fichier jusqu'à lengthHeader
		fseek(ficTable, LENGTH_HEADER, SEEK_SET);
		int lengthHeader = 0;
		//On récupère lengthHeader
		if (fgets(buffer, 4, ficTable) == NULL)
			return 1;
		lengthHeader = atoi(buffer);
		//On se replace au niveau du lengthHeader
		fseek(ficTable, LENGTH_HEADER, SEEK_SET);
		//On incrémente le lengthHeader de 38
		fprintf(ficTable, "0%d", lengthHeader + 38);

		//On se déplace jusqu'à nbRecord
		fseek(ficTable, NB_RECORD, SEEK_SET);
		fprintf(ficTable, "001");
		//On se déplace dans l'entête du fichier jusqu'à lengthRecord
		fseek(ficTable, LENGTH_RECORD, SEEK_SET);
		//On lui affecte sa première valeur et on l'écrit dans le fichier
		int lengthRecord = 7 + taille;
		printf("lengthRecord : <%d>", lengthRecord);
		fprintf(ficTable, "%d", lengthRecord);
		//On ajoute la nouvelle colonne dans le fichier
		fseek(ficTable, 0, SEEK_END);
		CompleterEspace(nomCol, 31);
		fprintf(ficTable, "%s|0|%s|%d|", nomCol, type, taille);
		//On ajoute le squelette du premier enregistrement dans le fichier
		fprintf(ficTable, " |0001|");
		int i = 0;
		while (i < taille) {
			fprintf(ficTable, " ");
			++i;
		}
		fprintf(ficTable, "|");
		fclose(ficTable);
	} else {
		//On récupère nbRecord
		fseek(ficTable, NB_RECORD, SEEK_SET);
		int nbRecord = 0;
		if (fgets(buffer, 4, ficTable) == NULL)
			return 1;
		nbRecord = atoi(buffer);
		//On se replace au début du columnDescription
		fseek(ficTable, COLUMN_DESCRIPTION, SEEK_SET);
		//On vérifie que la colonne n'existe pas
		int i = 0;
		CompleterEspace(nomCol, MAX_COL_NAME);
		while (i < nbColonne) {
			if (fgets(buffer, MAX_COL_NAME + 1, ficTable) == NULL)
				return 1;
			//On compare les deux chaines
			if (strcmp(buffer, nomCol) == 0)
				return -5;
			//On se positionne au début de la prochaine colonne
			fseek(ficTable, 7, SEEK_CUR);
			++i;
		}

		//On vérifie qu'il ne vaut pas 10
		if (nbColonne == 10)
			return -3;
		//On se repositionne au niveau de nbCol
		fseek(ficTable, NB_COL, SEEK_SET);
		//On incrémente nbCol de 1
		if (nbColonne == 9)
			fprintf(ficTable, "%d", nbColonne + 1);
		else
			fprintf(ficTable, "0%d", nbColonne + 1);

		//On se déplace dans l'entête du fichier jusqu'à lengthRecord
		fseek(ficTable, LENGTH_RECORD, SEEK_SET);
		int lengthRecord = 0;
		//On récupère lengthRecord
		if (fgets(buffer, 4, ficTable) == NULL)
			return 1;
		lengthRecord = atoi(buffer);
		int newLengthRecord = 0;
		newLengthRecord = lengthRecord + (taille + 1);
		////On se replace au début de lengthRecord
		fseek(ficTable, LENGTH_RECORD, SEEK_SET);
		//On lui ajoute [tailleType+1]
		if (newLengthRecord >= 99)
			fprintf(ficTable, "%d", newLengthRecord);
		else if (newLengthRecord >= 9)
			fprintf(ficTable, "0%d", newLengthRecord);
		else
<<<<<<< HEAD
		{
			fseek(ficTable,7,SEEK_SET);
			fprintf(ficTable,"00%d",nbRecord);
			fprintf(ficTable, "00%d", newLengthRecord);

		//On se déplace dans l'entête du fichier jusqu'à lengthHeader
		fseek(ficTable, LENGTH_HEADER, SEEK_SET);
		int lengthHeader = 0;
		//On récupère lengthHeader
		if (fgets(buffer, 4, ficTable) == NULL)
			return 1;
		lengthHeader = atoi(buffer);
		//On se replace au niveau du lengthHeader
		fseek(ficTable, LENGTH_HEADER, SEEK_SET);
		//On incrémente le lengthHeader de 38
		if (lengthHeader >= 62)
			fprintf(ficTable, "%d", lengthHeader + 38);
		else
			fprintf(ficTable, "0%d", lengthHeader + 38);

		//On se replace au début du fichier
		rewind(ficTable);

		//On crée et on ouvre un nouveau fichier pour la table
		FILE * ficNewTable = NULL;
		ficNewTable = fopen("./Tables/tmp_alter_table", "w+");
		//On récupère tout le header
		char*header = NULL;
		header = malloc(TAILLE_HEADER_MAX);
		memset(header, 0, TAILLE_HEADER_MAX);
		if (fgets(header, lengthHeader, ficTable) == NULL)
			return 1;
		//On l'écrit dans le nouveau fichier
		fprintf(ficNewTable, "%s", header);
		CompleterEspace(nomCol, 31);
		//On ajoute la nouvelle colonne dans le nouveau fichier
		fprintf(ficNewTable, "|%s|%d|%s|%d|", nomCol, nbColonne, type, taille);
		//On récupère chaque enregistrement et on lui ajoute la nouvelle colonne vide
		fseek(ficTable, 1, SEEK_CUR);
		for (i = 0; i < nbRecord; ++i) {
			if (fgets(header, lengthRecord + 1, ficTable) == NULL)
				return 1;
			fprintf(ficNewTable, "%s", header);

			int j = 0;
			while (j < taille) {
				fprintf(ficNewTable, " ");
				++j;
			}
			fprintf(ficNewTable, "|");
			fseek(ficTable, 1, SEEK_CUR);
		}
		//On supprime l"'ancien fichier en on renomme le nouveau
		fclose(ficTable);
		fclose(fictmp);
	return 1;
=======
			fprintf(ficTable, "00%d", newLengthRecord);

		//On se déplace dans l'entête du fichier jusqu'à lengthHeader
		fseek(ficTable, LENGTH_HEADER, SEEK_SET);
		int lengthHeader = 0;
		//On récupère lengthHeader
		if (fgets(buffer, 4, ficTable) == NULL)
			return 1;
		lengthHeader = atoi(buffer);
		//On se replace au niveau du lengthHeader
		fseek(ficTable, LENGTH_HEADER, SEEK_SET);
		//On incrémente le lengthHeader de 38
		if (lengthHeader >= 62)
			fprintf(ficTable, "%d", lengthHeader + 38);
		else
			fprintf(ficTable, "0%d", lengthHeader + 38);

		//On se replace au début du fichier
		rewind(ficTable);

		//On crée et on ouvre un nouveau fichier pour la table
		FILE * ficNewTable = NULL;
		ficNewTable = fopen("./Tables/tmp_alter_table", "w+");
		//On récupère tout le header
		char*header = NULL;
		header = malloc(TAILLE_HEADER_MAX);
		memset(header, 0, TAILLE_HEADER_MAX);
		if (fgets(header, lengthHeader, ficTable) == NULL)
			return 1;
		//On l'écrit dans le nouveau fichier
		fprintf(ficNewTable, "%s", header);
		CompleterEspace(nomCol, 31);
		//On ajoute la nouvelle colonne dans le nouveau fichier
		fprintf(ficNewTable, "|%s|%d|%s|%d|", nomCol, nbColonne, type, taille);
		//On récupère chaque enregistrement et on lui ajoute la nouvelle colonne vide
		fseek(ficTable, 1, SEEK_CUR);
		for (i = 0; i < nbRecord; ++i) {
			if (fgets(header, lengthRecord + 1, ficTable) == NULL)
				return 1;
			fprintf(ficNewTable, "%s", header);

			int j = 0;
			while (j < taille) {
				fprintf(ficNewTable, " ");
				++j;
			}
			fprintf(ficNewTable, "|");
			fseek(ficTable, 1, SEEK_CUR);
		}
		//On supprime l"'ancien fichier en on renomme le nouveau
		fclose(ficTable);
>>>>>>> branch 'master' of https://github.com/Biouche/ProjetC.git
		remove(nomTable);
		rename("./Tables/tmp_alter_table", nomTable);
		fclose(ficNewTable);
	}
	return 0;
}

int ExecuteDelete(char* nomTable,char* nomCol,char* operateur,char* valeur)
{
	char cheminTable[TAILLE_NOM_TABLE];
	memset(cheminTable, 0, sizeof(char) * TAILLE_NOM_TABLE);
	strcpy(cheminTable, "./Tables/");
	strcat(nomTable, ".dbf");
	strcat(cheminTable, nomTable);
	char*buffer = NULL;
	buffer = malloc(TAILLE_BUFFER);
	memset(buffer, 0, TAILLE_BUFFER);
	FILE * ficTable = NULL;

	//Test de l'existence du fichier
	if ((ficTable = fopen(cheminTable, "r+")) == NULL)
		return -1;

	//On se déplace dans l'entête du fichier jusqu'à nbRecord
	fseek(ficTable, NB_RECORD, SEEK_SET);
	//On récupère nbRecord
	int nbRecord = 0;
	if (fgets(buffer, 4, ficTable) == NULL)
		return 10;
	nbRecord = atoi(buffer);
	//On se déplace dans l'entête du fichier jusqu'à lengthHeader
	fseek(ficTable, LENGTH_HEADER, SEEK_SET);
	//On récupère lengthHeader
	int lengthHeader = 0;
	if (fgets(buffer, 4, ficTable) == NULL)
		return 10;
	lengthHeader = atoi(buffer);
	//On se déplace dans l'entête du fichier jusqu'à nbCol
	fseek(ficTable, NB_COL, SEEK_SET);
	//On récupère nbCol
	int nbColonne = 0;
	if (fgets(buffer, 3, ficTable) == NULL)
		return 10;
	nbColonne = atoi(buffer);
	//On se déplace dans l'entête du fichier jusqu'à lengthRecord
	fseek(ficTable, LENGTH_RECORD, SEEK_SET);
	//On récupère lengthRecord
	int lengthRecord = 0;
	if (fgets(buffer, 3, ficTable) == NULL)
		return 10;
	lengthRecord = atoi(buffer);

	//On vérifie que la colonne existe
	int i,same = 0;
	CompleterEspace(nomCol, MAX_COL_NAME);
	while (i < nbColonne) {
		if (fgets(buffer, MAX_COL_NAME + 1, ficTable) == NULL)
			return 10;
		//On compare les deux chaines
		if (strcmp(buffer, nomCol) == 0)
			same=1;
		else
			same=0;
		//On se positionne au début de la prochaine colonne
		fseek(ficTable, 7, SEEK_CUR);
		++i;
	}
	if(same==0)
		return -2;
	//TESTER TYPE
	TestType(valeur,);

	return 0;
}
