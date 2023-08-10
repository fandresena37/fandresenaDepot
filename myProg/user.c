#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    char name[200];
    char mot[100];
    char mot1[400];
    char mot2[500];
    int PID = 0;
    FILE *user = NULL;
    user = fopen("passwd","r");
        if(user == NULL){
            printf("erreur d'ouverture");
            exit(EXIT_FAILURE);
        }
       while(feof(user)!=1){
        fscanf(user,"%s,%s,%d,%s",name,mot,&PID,mot1);
        printf("%s %d \n",name,PID);
       if(PID == 1000){
        break;
       }
       }
    printf("%d\n",PID);
    fclose(user);

    return 0;
}