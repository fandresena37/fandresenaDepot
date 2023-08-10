#include "structPC.h"
int main(){
	machine *PC = malloc(sizeof(machine)*20);
	etudiant *mpianatra = malloc(sizeof(etudiant)*43);
	FILE *infoPc = NULL;
	FILE *infoEtudiant = NULL;
	infoPc = fopen("machine.csv","w+");
	infoEtudiant = fopen("info_etudiant.csv","w+");
	if(infoPc == NULL || infoEtudiant == NULL){
		printf("erreur lors de l'ouverture");
		exit(EXIT_FAILURE);
	}
	PC = sortie(PC,20);
	triPC(PC,20);
	entrez(PC,infoPc,20);
	mpianatra = sortieEtudiant(mpianatra,42);
	triEtudiant(mpianatra,42);
	entrezEtudiant(mpianatra,infoEtudiant,42);
	fclose(infoPc);
	fclose(infoEtudiant);
	return 0;
	}
