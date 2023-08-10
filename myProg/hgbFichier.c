#include <stdio.h>
#include <stdlib.h>
#define TAILLE 50
int main(){
	FILE *fichier = NULL;
	fichier = fopen("fi.txt","r");
	if(fichier == NULL)
		exit(1);
	int nb = 0;
	char c = 'a';
	do{
		c = fgetc(fichier);
		printf("%c",c);
		if(c == '\n')
			nb++;
	}while(c != EOF);
	for(int i = 0;i<nb-1;i++)
	{
		fgets(ligne,TAILLE,fichier);
		printf("%s",ligne);
	}
	
	
	return 0;
}
