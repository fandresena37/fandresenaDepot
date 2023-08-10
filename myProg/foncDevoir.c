machine *sortie(machine *PC){
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
void entrez (machine *PC,FILE *liste){
	for (int i=0;i<nb;i++){
	fprintf(liste,"%s;%s;%s",PC[i].marque,PC[i].MAC,PC[i].mpianatra);
	}	
	}
void triName(machine *PC){
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

