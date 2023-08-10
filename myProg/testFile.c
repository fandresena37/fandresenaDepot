#include <stdio.h>
#include <stdlib.h>

int main(){
	int nomb = 0;
	char carac[216] = "fandresena";
	FILE *fichier = NULL;
	FILE *nb = NULL;
	fichier = fopen("fand.txt","r");
	nb = fopen("nbLigne","r");
	system("touch nbLigne;cat fand.txt|wc -l > nbLigne");
	if(fichier == NULL || nb == NULL){
		printf("erreur lors de l'ouverture");
		exit(1);
		}
	fscanf(nb,"%d",&nomb);	
	for(int i=0;i<nomb;i++){	
		fgets(carac,34,fichier);
		printf("%s",carac);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	fclose(nb);
	fclose(fichier);	
	return 0;
	}
