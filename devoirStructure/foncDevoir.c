#include "structPC.h"
machine *sortie(machine *PC,int nb){
	FILE *listeFic = NULL;
	listeFic = fopen("PcMIT.csv","r+");
	if(listeFic == NULL){
		printf("erreur lors de l'ouverture");
		exit(EXIT_FAILURE);
	}
	
	for (int i=0;i<nb;i++){
	fscanf(listeFic,"%[^;];%[^;];%s",PC[i].marque,PC[i].MAC,PC[i].mpianatra);	
		}
	fclose(listeFic);	
	return PC;
	}
void entrez (machine *PC,FILE *infoPc,int nb){
	for (int i=0;i<nb;i++){
	fprintf(infoPc,"%s;%s;%s",PC[i].marque,PC[i].MAC,PC[i].mpianatra);
	}	
	}
void triPC(machine *PC,int nb){
	machine tmp;
	for (int i=1;i<nb;i++){
		for (int j=1;j<nb;j++){
	if(strcmp(PC[i].mpianatra,PC[j].mpianatra)<0){
		tmp = PC[i];
		PC[i]=PC[j];
		PC[j]=tmp;
			}
		}
	}
}
etudiant *sortieEtudiant(etudiant *mpianatra,int nb){
	FILE *listeFic = NULL;
	char teny[500];
	listeFic = fopen("data_info.csv","r+");
	if(listeFic == NULL){
		printf("erreur lors de l'ouverture");
		exit(EXIT_FAILURE);
	}
	
	for (int i=0;i<nb;i++){
	fgets(teny,500,listeFic);
	sscanf(teny,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",mpianatra[i].nom,mpianatra[i].prenom,mpianatra[i].numero,mpianatra[i].tel,mpianatra[i].email,mpianatra[i].adresse,mpianatra[i].naissance,mpianatra[i].lieu,mpianatra[i].bacc,mpianatra[i].genre,mpianatra[i].cin,mpianatra[i].url);	
		}
	fclose(listeFic);
	return mpianatra;	
	}
void triEtudiant(etudiant *mpianatra,int nb){
	etudiant tmp;
	for (int i=1;i<nb;i++){
		for (int j=1;j<nb;j++){
	if(strcmp(mpianatra[i].nom,mpianatra[j].nom)<0){
		tmp = mpianatra[i];
		mpianatra[i]=mpianatra[j];
		mpianatra[j]=tmp;
			}
		}
	}
	}
void entrezEtudiant(etudiant *mpianatra,FILE *infoEtudiant,int nb){
	for (int i=0;i<nb;i++){
	fprintf(infoEtudiant,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",mpianatra[i].nom,mpianatra[i].prenom,mpianatra[i].numero,mpianatra[i].tel,mpianatra[i].email,mpianatra[i].adresse,mpianatra[i].naissance,mpianatra[i].lieu,mpianatra[i].bacc,mpianatra[i].genre,mpianatra[i].cin,mpianatra[i].url);	
		}
	}
