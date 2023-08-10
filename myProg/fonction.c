#include <stdio.h>
#include <stdlib.h>
void calcul (FILE *fichier,int n,double x,double y,float a,float b);
int main(){
FILE *fichier = NULL; 
fichier = fopen("fonc.csv","w");
if(fichier == NULL){
exit(EXIT_FAILURE);
}
	float a = 0;
	float b = 100;
	int n = 20;
	double x = 0;
	double y = 0;
printf("entrez n:");
scanf("%d",&n);
calcul(fichier,n,x,y,a,b);
fclose(fichier);
	return 0;
	}

void calcul(FILE *fichier,int n,double x,double y,float a,float b){
x = a;
float inter = (b-a)/n;
for(int i=0;i<n;i++){
y = 2*(x)+3;
fprintf(fichier,"%f %f\n",x,y);
x = x+inter;
}
}
