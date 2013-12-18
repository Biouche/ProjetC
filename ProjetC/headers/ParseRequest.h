/*
 * RequestParse.h
 *
 *  Created on: Dec 1, 2013
 *      Author: dev
 *  Fonctions de parse des requêtes lues depuis l'IHM
 */

#ifndef REQUESTPARSE_H_
#define REQUESTPARSE_H_

int ParseSELECT (char * Request);

int ParseINSERT (char * Request);

int ParseUPDATE (char * Request);

int ParseALTER (char * Request);



#endif /* REQUESTPARSE_H_ */
