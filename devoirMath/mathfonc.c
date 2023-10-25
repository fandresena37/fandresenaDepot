#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>
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
		printf("<tr><td>%lf</td><tr>\n",s);
		}
	
	
	}


void secante(double a,double b){
	
	double s=b;
	while(f(s)>eps){
		
		if(f(a)*f(s)>0){
		printf("Tsy misy\n");
		break;
		}
		
		s=(fabs(f(a))*s+f(s)*a)/(fabs(f(a))+f(s));
		printf("<tr><td>%lf</td></tr>\n",s);
		
		}
	
	}



void dicho(double a,double b){
	
    double s=0;
	
	  while(fabs(a-b)>eps){
		
	    s=(a+b)/2;
	
		if(f(a)*f(s)<0){
			b=s;
			printf("<tr><td>%lf</td></tr>\n",s);
			}
	   	else if(f(s)*f(b)<0){
			a=s;
			printf("<tr><td>%lf</td></tr>\n",s);
			}
		else{printf("Tsy misy");break;} 
	   
		
		}
	
	}

void inteTrap(double a, double b){
	
	double i;
	double ing=0;
	double inc=(a+b)/10;
	
	//printf("inc=%lf\n",inc);
	
	for(i=a;i<b;i+=inc){

		
		ing+=(f(i)*(inc))+((f(i+inc)-f(i)))*(inc)/2;
		//printf("<tr><td>%lf</td></tr>\n",ing);
		
		}
	printf("%lf",ing);
	
	}

int main(int argc, char **argv)
{
    
    printf("Context-type:text/html\n\n");
	printf("<head>");
	printf("<link href=\"http://www.fand.com/devoirMath/mathCSS.css\" rel=\"stylesheet\" />");
	printf("</head>");
	printf("<body>");
	char *text = getenv("QUERY_STRING");
    double a=1,b=3;
    printf("<form action=\"http://www.fand.com/cgi-bin/devoirMath/mathfonc.cgi\" method=\"get\">");
	printf("<div class=\"input\">");
	printf("<input class=\"borne\" type=\"text\" name=\"a\"/>");
	printf("<input class=\"borne\" type=\"text\" name=\"b\"/>");
	printf("</div>");
	printf("<div class=\"bouton\">");
	printf("<button type=\"submit\" name=\"dichotomie\">dichotomie</button>");
	printf("<button type=\"submit\" name=\"secante\">secante</button>");
	printf("<button type=\"submit\" name=\"tangente\">tangente</button>");
	printf("<button type=\"submit\" name=\"integrale\">integrale</button>");
	printf("</div>");
	printf("</form>");
     //inteTrap(a,b);
  
  	if(strstr(text,"dichotomie")){
		sscanf(text,"a=%lf&b=%lf",&a,&b);
		printf("<table border=\"1\">");
    	dicho(a,b);
		printf("</table>");
	}
  	else if(strstr(text,"secante")){
		sscanf(text,"a=%lf&b=%lf",&a,&b);
		printf("<table border=\"1\">");
    	secante(a,b);
		printf("</table>");
	}
  	else if(strstr(text,"tangente")){
		sscanf(text,"a=%lf&b=%lf",&a,&b);
		printf("<table border=\"1\">");
    	tangente(a);
		printf("</table>");
	}
	else{
		sscanf(text,"a=%lf&b=%lf",&a,&b);
		inteTrap(a,b);
	}
	printf("</body>");
	return 0;
}

