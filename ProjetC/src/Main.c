#include <stdio.h>
#include <IHM.h>
#include <string.h>
#include "FileManip.h"
#include "Constants.h"

int main (void)
{
	int test = 0;
	char request [TAILLE_REQUEST];
	memset (request, 0, sizeof(char)*TAILLE_REQUEST);
	strcpy(request, "test1");
	test=CreateTable(request);
	printf ("Return test : %d\n", test);
	return 0;
}
