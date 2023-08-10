#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// structure
typedef struct{
	char marque[50];
	char MAC[50];
	char mpianatra[50];
	}machine;
	
typedef struct{
	char nom[255];
	char prenom[255];
	char numero[255];
	char tel[255];
	char email[255];
	char adresse[255];
	char naissance[255];
	char lieu[255];
	char genre[255];
	char cin[255];
	char bacc[255];
	char url[255];
	
	}etudiant;
	
/// declaration fonction	
machine *sortie(machine *PC,int nb);
void entrez (machine *PC,FILE *infoPc,int nb);
void triPC(machine *PC,int nb);
etudiant *sortieEtudiant(etudiant *mpianatra,int nb);
void triEtudiant(etudiant *mpianatra,int nb);
void entrezEtudiant(etudiant *mpianatra,FILE *infoEtudiant,int nb);
