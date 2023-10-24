#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double x){
	return x*x;
	}
	
double solution(double a,double b,double epsi){
	double c = 0;
	while(fabs(a-b)>epsi){
		c = (a+b)/2;
		if(f(a)*f(c)<=0){
			b = c;
			}
		else if(f(c)*f(b)<=0){
			a = c;
			}			
		}
	return (a+b)/2;	
	}
	
double integrale(double a,double b){
	double res = 0;
	double ins = (b-a)/50;
	for(double i = a;i<=b;i+=ins){
		res+=f(i)*(ins)+(ins*(ins))/2;
		}
	return res;
	}		
int main(){
	double a = 0,b = 1;
	double epsi = pow(10,-8);
	printf("res %f\n",solution(a,b,epsi));
	printf("%f",integrale(a,b));	
	return 0;
	}
