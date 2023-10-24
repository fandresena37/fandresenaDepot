#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "authentifi.h"
#include "dateTraitement.h"
#include "resultatSearch.h"
int main(){
    FILE *css = NULL;
    char car = 'a';
    css = fopen("SearchCSS.css","r");
    printf("Context-Type:text/html\n\n");
    printf("<html><head>");
    printf("<link rel=\"stylesheet\" href=\"http://www.fand.com/auth/testDynamique/Search1CSS.css\">");
    printf("<style type=text/css>\n");
    printf("</style>");
    printf("<title>AuthLog</title></head>");
    FILE *log = NULL;
    FILE *sess = NULL;
    FILE *nbLine = NULL;
    FILE *res = NULL;
    FILE *login = NULL;
    FILE *LOGIN = NULL;
    char text[100];
    char line[200];
    char user[30];
    char cmd[200];
    char us[100];
    char action[20];
    char date1[200];
    char date2[200];
    char heure[30];
    char tsis[200];
    char tisy[200];
    char ts[200];
    char name[20];
    char pass[20];
    char nameL[20];
    char passL[20];
    char ip[50];
    int button = 0;
    float ligne = 0;
    int misy = 0;
    int valide = 0;
    int insc = 0;
    strcpy(text,getenv("QUERY_STRING"));
    log = fopen("/var/log/auth.log","r");
    strcpy(ip,addresse());
    if(log == NULL){
        printf("<p>erreur de l'ouverture du fichier log</p>");
    }
    else{
        if(strstr(text,"deconnect")){

            /***fonction de deconnection***/
            
            deconnecter(LOGIN,ip,name,pass,nameL,passL,line);
        }
            /***effectue le changement de compte***/
        if(strstr(text,"change=")){
            compteChanger(LOGIN,login,line,name,nameL,passL,text,ip);
        }    
        /****verifit si le login est encore connecter****/
        
        valide = verification1(LOGIN,line,valide,ip);
        
        if(valide!=1){
            if(strstr(text,"connect")){

                /****recherche du login dans le fichier login.txt****/

            valide = verification(valide,name,nameL,pass,passL,login,LOGIN,text,line,ip);
            }
            else if(strstr(text,"inscrire")){

                /****inscit le login dans le login.txt****/

                valide = inscrire(text,line,login,LOGIN,valide);
            }
            else if(strstr(text,"inscription")){

                /****input d'inscription****/

                inscription(0);
            }
            if(!strstr(text,"inscription")){

                /****input de connexion****/
                if(valide!=1 && valide!=3 && valide!=4){
                authentification(0,0);
                }
                else if(strcmp(nameL,name)==0 && strcmp(passL,pass)!=0 && valide!=4){
                    authentification(0,1);
                }
                else if(strcmp(nameL,name)!=0 && strcmp(passL,pass)==0 && valide!=4){
                    authentification(1,0);
                }
                else if(strcmp(nameL,name)!=0 && strcmp(passL,pass)!=0 && valide!=4){
                    authentification(1,1);
                }
            }
        }
        if(strstr(text,"changeCompte")){
            valide = changeCompte(line,name,pass,valide,ip);
            }
        if(valide == 1){

        /***input de recherche***/


        /***change compte***/
        
        recherche(cmd,LOGIN,name,pass,ip,valide,line);    


        if(strcmp(text,"")!=0 || strcmp(text,"user=")!=0 || strcmp(text,"button=")!=0){

            /// user recherche


            userSearch(text,cmd,line,user,ip,date1,date2,heure,tsis,tisy,ts,action,us,sess,log,res,nbLine,misy,ligne);
            

            /// pagination

            buttonPagination(text,cmd,line,date2,date1,heure,action,us,ip,ligne,button,nbLine);
            
        }
        printf("</body>");
        }
    }
    printf("</html>");
    return 0;
}