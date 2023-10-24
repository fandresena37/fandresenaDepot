
char *mois(char date1[200]){
    int i = 0;
    char mois[12][20] = {"Janv" , "Févr" , "Mars" , "Avril" , "Mai" , "Juin" , "Juill" , "Aout" , "Sept" , "Oct" , "Nov" , "Dec"};
    char vraie[12][20] = {"Janoary" , "Febroary" , "Martsa" , "Aprily" , "May" , "Jona" , "Jolay" , "Aogostra" , "Septambra" , "Oktobra" , "Novambra" , "Decambra"};
    while(i<12){
    if(strcmp(date1,mois[i])==0){
    break;
    }
    i++;
    }
    char *resultat = malloc(sizeof(char)*30);
    strcpy(resultat,vraie[i]);
    return resultat;
}

int indexde(char table[12][20] , char* str , int taille){
    int ind = -1;
    for (int i=0;i<taille;i++){
        if (strcmp(table[i],str)==0){
            ind = i;
        }
    }
    return ind;
}

char *jour(char date1[200],char date2[200]){
char mois[12][20] = {"Janv" , "Fevr" , "Mars" , "Avril" , "Mai" , "Juin" , "Juill" , "Aout" , "Sept" , "Oct" , "Nov" , "Dec"};
char js[7][12] = {"Sabotsy" , "Alahady","Alatsinainy" , "Talata" , "Alarobia" , "Alakamisy" , "Zoma"};
    int m = 0;
    int j = 0;
    int a = 2023;
    int resultat = 0;
    char moi[7];
    j = atoi(date2); 
    m = indexde(mois,date1,12)+1;
    if(m<3){
        m += 12;
        a -= 1;
    }
    int c = a/100;
    int y = a%100;
    resultat = (j + (int)((26 *(m + 1)) / 10) + y + (int)(y/4) + (int)(c/4) + (5*c)) % 7;
    //printf("%d  %s\n",resultat,js[resultat]);
    char *res  = malloc(sizeof(char)*200);
    sprintf(res,"%s %s",js[resultat],date2);
    return res;
}