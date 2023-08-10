#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.1415926254
int main(){
	FILE *fichier = NULL;
	int nb = 0;
	fichier = fopen("tableTRIGO.csv","w+");
	if(fichier == NULL){
		printf("erreur lores de l'ouverture du fichier");
		exit(EXIT_FAILURE);
		}
		printf("/********sinus*********/\n");
		//fprintf(fichier,"x sin(x) cos(x) tan(x) cotan(x)");
		for(int i=0;i<=360;i++){
			if(i%2 == 0|| i == 1|| i == 3){
				nb = PI*i/180;
				printf("%d %f %f %f %f\n",i,sin(nb),cos(nb),tan(nb),(1/tan(nb)));
			}
		}
		
	return 0;
	}
