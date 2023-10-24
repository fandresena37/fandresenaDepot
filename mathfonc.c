#include <stdio.h>
#include <math.h>
#include <float.h>
#define eps 1e-9

double f(double n){
	
	return log(n)-1;
	}

double derive(double a){
	
	return  (f(a+eps)-f(a))/eps ;
	
	}

void tangente(double a){
	
	double s=a;
    
	while(fabs(f(s))>eps ){
		s=-f(s)/derive(s)+s;
		printf("%lf\n",s);
		}
	
	//printf("%.10lf",derive(s)/f(s)+s);
	
	}


void secante(double a,double b){
	
	double s=b;
	while(f(s)>eps){
		
		if(f(a)*f(s)>0){printf("Tsy misy\n");break;}
		
		s=(fabs(f(a))*s+f(s)*a)/(fabs(f(a))+f(s));
		printf("%lf\n",s);
		
		}
	
	}



void dicho(double a,double b){
	
    double s=0;
	
	  while(fabs(a-b)>eps){
		
	    s=(a+b)/2;
	
		if(f(a)*f(s)<0){b=s;printf("%lf\n",s);}
	   	else if(f(s)*f(b)<0){a=s;printf("%lf\n",s);}
		else{printf("Tsy misy");break;} 
	   
		
		}
	
	}

void inteTrap(double a, double b){
	
	double i;
	double ing=0;
	double inc=(a+b)/10;
	
	printf("inc=%lf\n",inc);
	
	for(i=a;i<b;i+=inc){

		
		ing+=(f(i)*(inc))+((f(i+inc)-f(i)))*(inc)/2;
		printf("%lf\n",ing);
		
		   
		
		}
	
	}

int main(int argc, char **argv)
{
    
    printf("Content-type:text/plain\n\n");
    
    double a=1.5,b=3;
    
     //inteTrap(a,b);
  
  printf("Dich\n\n");
    dicho(a,b);
  printf("Sec\n\n");   
    secante(a,b);
  printf("tan\n\n")  ;
     tangente(a);
   // printf("%.10lf",derive(2));
     	
	return 0;
}

