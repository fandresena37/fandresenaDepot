/****connexion****/

void authentification(int a,int b){
    printf("<body class=\"body\">");
    printf("<h1 style=\"margin-top:30px;font-family:cursive;font-size:50px;color:rgb(70, 75, 52)\">CONNEXION</h1>");
    printf("<div class=\"auth\">");
    printf("<form action=\"http://www.fand.com/cgi-bin/auth/testDynamique/SearchAuth.cgi\" method=\"get\">");
    printf("<input class = \"user\" type=\"text\" name=\"utilisateur\" placeholder=\"Entrez le votre Nom\"/>");
    if(a == 1){
    printf("<p style=\"margin-top:10px;text-align:center;color:red;\">login incorrect</p>");
    }
    printf("<input class = \"pass\" type=\"password\" name=\"pass\"/ placeholder=\"Entrez le mot de pass\">");
    if(b == 1){
      printf("<p style=\"margin-top:10px;text-align:center;color:red;\">mot de passe incorrect</p>");  
    }
    printf("<input class=\"connect\" type=\"submit\" value=\"se connecter\" name=\"connect\"/>");
    printf("<a style=\"color:red;margin-left:70px\" href=\"http://www.fand.com/cgi-bin/auth/testDynamique/SearchAuth.cgi?inscription\">inscription</a>");
    printf("</form>");
    printf("</div>");
    printf("</body>");
}


/****inscription****/


void inscription(int n){
    printf("<body class=\"body\">");
    printf("<h1 style=\"margin-top:30px;font-family:cursive;font-size:50px;color:rgb(70, 75, 52)\">INSCRIPTION</h1>");
    printf("<div class=\"auth\">");
    printf("<form action=\"http://www.fand.com/cgi-bin/auth/testDynamique/SearchAuth.cgi\" method=\"get\">");
    printf("<input class = \"user\" type=\"text\" name=\"utilisateur\" placeholder=\"Entrez le votre Nom\"/>");
    if(n == 2){
    printf("<p style=\"color:red;margin-top:20px;text-align:center;\">le Login exixte deja</p>");
    }
    printf("<input class = \"pass\" type=\"password\" name=\"pass\"/ placeholder=\"Entrez le mot de pass\">");
    printf("<input class = \"pass\" type=\"password\" name=\"passRetape\"/ placeholder=\"Retapez le mot de pass\">");
    if(n == 1){
    printf("<p style=\"color:red;margin-top:20px;text-align:center;\">mot de passe invalide</p>");
    }
    
    printf("<input class=\"inscrire\" type=\"submit\" value=\"s'inscrire\" name=\"inscrire\"/>");
    printf("</form>");
    printf("</div>");
    printf("</body>");
}

/****changer de compte****/

int changeCompte(char *line,char *name,char *pass,int valide,char *ip){
    FILE *compte = NULL;
    int i = 0;
    sprintf(line,"%s/LogConnect.txt",ip);
    compte = fopen(line,"r");
    if(compte == NULL){
        printf("<p>erreur ee </p>");
    }
    else{  
    printf("<body class = \"body\">");    
    printf("<h1 style=\"margin-top:30px;font-family:cursive;font-size:50px;color:rgb(70, 75, 52)\">CHANGER DE COMPTE</h1>"); 
    printf("<div class=\"DivChange\">");
   
    printf("<form action=\"http://www.fand.com/cgi-bin/auth/testDynamique/SearchAuth.cgi\" method=\"get\">");
    while(fgets(line,200,compte)){
        sscanf(line,"%[^:]:%s",name,pass);
        printf("<button class=\"butChange\" type=\"submit\" name=\"change\" value=%s>%s</button>",name,name);
    }
    printf("<button class=\"retour\" type=\"submit\" name=\"change\" value=1>autre compte</button>");
    printf("</form>");
    printf("</div>");
    printf("</body>");
    }
    valide = 0;
    return valide;
}
void compteChanger(FILE *LOGIN,FILE *login,char *line,char *name,char *nameL,char *passL,char *text,char *ip){
    sscanf(text,"change=%s",name);
    login = fopen("login.txt","r");
    sprintf(line,"%s/LOGIN.txt",ip);
    LOGIN = fopen(line,"w");
    if(strcmp(name,"1")!=0){
    while(fgets(line,200,login)){
        sscanf(line,"%[^:]:%s",nameL,passL);
        if(strcmp(name,nameL)==0){
            fprintf(LOGIN,"%s:%s",nameL,passL);
            break;
        }
    }
    fclose(LOGIN);
    }
    else{
        fclose(LOGIN);
    }
    fclose(login);

}
/****verification de login****/

int verification(int valide,char *name,char *nameL,char *pass,char *passL,FILE *login,FILE *LOGIN,char *text,char *line,char *ip){
        valide = 0;
        char cmd[200];
        login = fopen("login.txt","r");
        FILE *compte = NULL;
        sprintf(cmd,"%s/LogConnect.txt",ip);
        compte = fopen(cmd,"a+");
        if(login !=NULL){
        while(fgets(line,200,login)){
        sscanf(line,"%[^:]:%s",nameL,passL);
        if(strstr(text,"utilisateur") || strstr(text,"user")){
            if(strstr(text,"utilisateur") && strstr(text,"connect")){
                sscanf(text,"utilisateur=%[^&]&pass=%[^&]&",name,pass);
                if(strcmp(nameL,name)==0 && strcmp(passL,pass)==0){
                    valide = 1;
                    char cmd[200];
                    sprintf(cmd,"%s/LOGIN.txt",ip);
                    LOGIN = fopen(cmd,"w");
                    if(LOGIN != NULL){
                        fprintf(LOGIN,"%s:%s",name,pass);
                    }
                    if(compte !=NULL){
                        fprintf(compte,"%s:%s\n",name,pass); 
                        fclose(compte);
                    }
                    fclose(LOGIN); 
                    break;
                }
                else if(strcmp(nameL,name)==0 && strcmp(passL,pass)!=0){
                    valide = 3;
                    break;
                }
                else if(strcmp(nameL,name)!=0){
                    valide = 3;
                }
                else{
                    valide = 3;
                }

            }
        }
        }
        fclose(login);
        }
    return valide;
}


/****verification de connexion****/

int verification1(FILE *LOGIN,char *line,int valide,char *ip){
    char cmd[200];
    sprintf(cmd,"%s/LOGIN.txt",ip);
    LOGIN = fopen(cmd,"r");
        if(LOGIN != NULL){
            while(fgets(line,200,LOGIN)){
                valide = 1;
            }
            fclose(LOGIN);
        }
    return valide;
}


/****deconnection****/

void deconnecter(FILE *LOGIN,char *ip,char *name,char *pass,char *nameL,char *passL,char *line){
    char cmd[200];
    FILE *tmp = fopen("tmp.txt","a+");
    sprintf(cmd,"%s/LogConnect.txt",ip);
    FILE *compte = fopen(cmd,"r");
    sprintf(cmd,"%s/LOGIN.txt",ip);
    if(compte == NULL){
        printf("erreur");
    }
    LOGIN = fopen(cmd,"r");
    if(LOGIN!=NULL){
    fscanf(LOGIN,"%[^:]:%s",name,pass);
    }
    if(tmp!=NULL && compte !=NULL){
      while(fgets(line,200,compte)){
        fprintf(tmp,"%s",line); 
    }
    }
    if(compte !=NULL){
    fclose(compte);
    }
    sprintf(cmd,"%s/LogConnect.txt",ip);
    compte = fopen(cmd,"w");
    //compte = fopen("LogConnect.txt","w");
    fclose(compte);
    fclose(tmp);
    sprintf(cmd,"%s/LogConnect.txt",ip);
    compte = fopen(cmd,"a+");
    if(compte == NULL){
        printf("erreur");
    }
    //compte = fopen("LogConnect.txt","a+");
    tmp = fopen("tmp.txt","r");
    if(compte!=NULL){
    while(fgets(line,200,tmp)){
        sscanf(line,"%[^:]:%s",nameL,passL);
        if(strcmp(name,nameL)!=0){
            fprintf(compte,"%s:%s\n",nameL,passL);
        }
    }
    fclose(compte);
    }
    fclose(LOGIN);
    tmp = fopen("tmp.txt","w");
    fclose(tmp);
    sprintf(cmd,"%s/LOGIN.txt",ip);
    LOGIN = fopen(cmd,"w");
    fclose(LOGIN);
}


/****inscription dans le fichier LOGIN.txt****/

int inscrire(char *text,char *line,FILE *login,FILE *LOGIN,int valide){
    char pass[50];
    char name[50];
    char passL[50];
    char nameL[50];    
int ao = 0;
char passtape[50];
sscanf(text,"utilisateur=%[^&]&pass=%[^&]&passRetape=%[^&]&",name,pass,passtape);
login = fopen("login.txt","r");
while(fgets(line,200,login)){
        sscanf(line,"%[^:]:%s",nameL,passL);
        if(strcmp(name,nameL)==0){
            ao = 1;
            printf("%d",ao);
            break;
        }
}
fclose(login);
login = fopen("login.txt","a");
if(strcmp(name,"")!=0 && strcmp(pass,"")!=0 && strcmp(passtape,pass)==0 && ao!=1){
fprintf(login,"%s:%s\n",name,pass);
fclose(login);
valide = 0;
}
else if(strcmp(passtape,pass)!=0 && ao!=1){
    printf("mot de pass");
    inscription(1);
    valide = 4;
}
else if(ao == 1){
    printf("efa ao");
    inscription(2);
    valide = 4;
}
return valide;
}

/*****obtension de l'addresse ip du visiteur*****/


char *addresse(){
    int nb = 0;
	int ao = 0;
	FILE *ls = NULL;
	FILE *doss = NULL;
	char line[200];
	char *ip = malloc(sizeof(char)*50);
	char rest[200];
    ip = getenv("REMOTE_ADDR");
	ls = popen("ls","r");
        if(strcmp(ip,"")==0){
            strcpy(ip,"163.168.1.63");
        }    
		while(fgets(line,200,ls)){
			if(strstr(line,ip)){
				ao = 1;
				}
			}
		if(ao != 1){
			sprintf(line,"mkdir %s;cd %s;touch session.txt;touch LOGIN.txt,touch LogConnect.txt",ip,ip);
			doss = popen(line,"w");
            if(doss == NULL){
                printf("tsy mety");
            }
			}
        pclose(ls);    				
        return ip;
}