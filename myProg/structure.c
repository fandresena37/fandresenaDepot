#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int nb;
	}test3;
typedef struct{
	test3 test4;
	}test;
	
typedef struct {
	char couleur[20];
	char marque[20];
	int prix;
	test test1;
	}stylo;
int main(){
	stylo bic;
	bic.test1.test4.nb = 3;
	printf("\n%d",bic.test1.test4.nb);
	return 0;
	}
