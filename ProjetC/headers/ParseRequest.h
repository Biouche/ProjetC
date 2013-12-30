/*
 * RequestParse.h
 *
 *  Created on: Dec 1, 2013
 *      Author: dev
 *  Fonctions de parse des requêtes lues depuis l'IHM
 */

#ifndef REQUESTPARSE_H_
#define REQUESTPARSE_H_

int ParseSELECT (char *);

int ParseINSERT (char *);

int ParseUPDATE (char *);

int AlterTable (char *);



#endif /* REQUESTPARSE_H_ */
