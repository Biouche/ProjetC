/*
 * FileManip.h
 *
 *  Created on: Dec 1, 2013
 *      Author: dev
 *      Fonctions de manipulation des fichiers
 */

#ifndef FILEMANIP_H_
#define FILEMANIP_H_

int CreateTable(char*);
int ExecuteAddColumn(char*,char*,char*,int);
int DropTable (char*);
int InsertInto (char *);
int ExecuteDelete(char*,char*,char*,char*);

#endif /* FILEMANIP_H_ */
