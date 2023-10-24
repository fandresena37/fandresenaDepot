void recherche(char *cmd,FILE *LOGIN,char *name,char *pass,char *ip,int valide,char *line){
    char utilisateur[50];
sprintf(cmd,"%s/LOGIN.txt",ip);
        LOGIN = fopen(cmd,"r");
        if(LOGIN !=NULL){
            fscanf(LOGIN,"%[^:]:%s",name,pass);
        }
        printf("<body class =\"body1\">");
        printf("<header class=\"entete\">");
        printf("<div style=\"background-color:green;border-radius:100px;text-align:center;margin-left:10px;margin-top:15px;height:50px;width:50px;\">");
        printf("<p style=\"font-size:20px;margin-top:15px;margin-rigth:10px;\">%c</p>",toupper(name[0]));
        printf("</div>");
        printf("<p style=\"margin-top:30px;margin-left:20px\">%s</p>",name);
        printf("<form class=\"form1\" action=\"http://www.fand.com/cgi-bin/auth/testDynamique/SearchAuth.cgi\" method=\"get\">");
        printf("<div class=\"divcherche\">");
        printf("<input type=\"text\" name=\"user\" class=\"recherche\" placeholder=\"Entrez le nom de l'utilisateur\"/>");
        //printf("<input type=\"hidden\" name=\"pseudo\" value=\"%s\"/>");
        printf("<button type=\"submit\" class=\"butSearch\"><svg xmlns=\"http://www.w3.org/2000/svg\" height=\"1.5em\" viewBox=\"0 0 512 512\"><path d=\"M416 208c0 45.9-14.9 88.3-40 122.7L502.6 457.4c12.5 12.5 12.5 32.8 0 45.3s-32.8 12.5-45.3 0L330.7 376c-34.4 25.2-76.8 40-122.7 40C93.1 416 0 322.9 0 208S93.1 0 208 0S416 93.1 416 208zM208 352a144 144 0 1 0 0-288 144 144 0 1 0 0 288z\"/></svg></button>");
        printf("</div>");
        printf("</form>");
        printf("<form action=\"http://www.fand.com/cgi-bin/auth/testDynamique/SearchAuth.cgi\" method=\"get\">");
        printf("<button class = \"deconnecter\" type=\"submit\" value=\"1\" name=\"deconnect\">deconnecter</button>");
        printf("</form>");
        printf("<form action=\"http://www.fand.com/cgi-bin/auth/testDynamique/SearchAuth.cgi\" method=\"get\">");
        printf("<button class = \"change\" type=\"submit\" value=\"2\" name=\"changeCompte\">changer de compte</button>");
        printf("</form>");
        printf("</header>");
        
}

/****recherche user****/

void userSearch(char *text,char *cmd,char *line,char *user,char *ip,char *date1,char *date2,char *heure,char *tsis,char *tisy,char *ts,char *action,char *us,FILE *sess,FILE *log,FILE *res,FILE *nbLine,int misy,float ligne){
    if(strstr(text,"user")){
        sprintf(cmd,"%s/session.txt",ip);
                sess = fopen(cmd,"w");
                if(sess == NULL){
                    printf("<p>erreur de l'ouverture du fichier session</p>");
                }
                else{
                sscanf(text,"user=%s",user);
                while(fgets(line,200,log)){
                if(strstr(line,"opened") || strstr(line,"closed")){
                    sscanf(line,"%[^ ] %[^ ] %[^ ] %[^:]: %[^ ] %[^ ] %[^ ] for user %[^ ]",date1,date2,heure,tsis,tisy,ts,action,us);
                    sscanf(us,"%[^\n]",us);
                if(strstr(us,user) && strcmp(user,"")!=0){
                    misy = 1;
                    strcpy(date2,jour(date1,date2));
                    strcpy(date1,mois(date1));
                    fprintf(sess,"%s %s %s %s %s\n",date2,date1,heure,action,us);
                    }
                if(strcmp(user,"")==0){
                    misy = 2;
                }    
                }
            }
            fclose(log);
            fclose(sess);
                }
            if(misy == 1){
            sprintf(cmd,"wc -l %s/session.txt",ip);
            nbLine = popen(cmd,"r");
            fscanf(nbLine,"%f",&ligne);
            printf("</form>");
            sprintf(cmd,"head -10 %s/session.txt|tail -10",ip);
            res = popen(cmd,"r");
            printf("<div class=\"divTable\">");
            printf("<form action=\"http://www.fand.com/cgi-bin/auth/testDynamique/SearchAuth.cgi\" method=\"get\">");
            for(int i = 1;i<=ceil(ligne/10.0) && i<=6;i++){
                if(i == 1){
                    printf("<button class=\"page\" type=\"sybmit\" name=\"button\" value=\"%d\" disabled>%d</button>",i,i);
                }
                else{
                printf("<button class=\"page\" type=\"sybmit\" name=\"button\" value=\"%d\">%d</button>",i,i);
                }
            }
            pclose(nbLine);
            int i = 0;
            printf("</form>");
            printf("<div class=\"tableau\">");
            printf("<table style=\"color:white;\"><div style=\"background-color:black;border-radius:20px 20px 0px 0px\"><tr style=\"background-color:black\"><td>date</td><td>session</td><td>user</td></tr></div>");
            while(fgets(line,200,res)){
                char date3[200];
                sscanf(line,"%[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %s\n",date2,date1,date3,heure,action,us);
                if(i%2 == 0){
                    if(strcmp(action,"opened")==0){
                    printf("<tr class=\"tr\"><td>%s %s %s %s</td><td><div class=\"session\"><p>%s</p></div></td><td>%s</td></tr>",date2,date1,date3,heure,action,us);
                    }
                    else{
                        printf("<tr class=\"tr\"><td>%s %s %s %s</td><td><div class=\"session1\"><p>%s</p></div></td><td>%s</td></tr>",date2,date1,date3,heure,action,us);
                    }
                }

                else{
                    if(strcmp(action,"opened")==0){
                    printf("<tr style=\"background-color:rgb(230, 230, 167)\" class=\"tr\"><td>%s %s %s %s</td><td><div class=\"session\"><p>%s</p></div></td><td>%s</td></tr>",date2,date1,date3,heure,action,us);
                    }
                    else{
                        printf("<tr style=\"background-color:rgb(230, 230, 167)\" class=\"tr\"><td>%s %s %s %s</td><td><div class=\"session1\"><p>%s</p></div></td><td>%s</td></tr>",date2,date1,date3,heure,action,us);
                    }
                }
                i++;
            }
            printf("</table>");
            printf("</div>");
            printf("</div>");
            }
            else if(misy == 2){
               printf("<div class=\"divTable\">");
                printf("<p style=\"font-size:30px;color:red;margin-left:220px;margin-right:200px\">saisissez l'utilisateur</p>");
                printf("</div>"); 
            }
            else{
                printf("<div class=\"divTable\">");
                printf("<p style=\"font-size:30px;color:red;margin-left:220px;margin-right:200px\">aucune resultat trouver</p>");
                printf("</div>");
            }
            }
}

/**********/

void buttonPagination(char *text,char *cmd,char *line,char *date2,char *date1,char *heure,char *action,char *us,char *ip,float ligne,int button,FILE *nbLine){
if(strstr(text,"button")){
    sscanf(text,"button=%d",&button);
    sprintf(cmd,"head -%d %s/session.txt|tail -10",(button*10),ip);
    FILE *ress = NULL;
    ress = popen(cmd,"r");
                if(ress == NULL){
                    printf("<p>res erreur</p>");

                }
                else{
                sprintf(cmd,"wc -l %s/session.txt",ip);
                nbLine = popen(cmd,"r");
                fscanf(nbLine,"%f",&ligne);
                printf("<div class=\"divTable\">");
                printf("<form action=\"http://www.fand.com/cgi-bin/auth/testDynamique/SearchAuth.cgi\" method=\"get\">");
                int div = ceil(ligne/10.0)/10;
                int a = button - 5;
                int b = button + 5;
                if(a<=0){
                    a = 1;
                }
                if(b>=ceil(ligne/10.0)){
                    b = ceil(ligne/10.0);
                }
                for(int i = a;i<=b;i++){
                    if(i==button){
                    printf("<button class=\"page\" type=\"sybmit\" name=\"button\" value=\"%d\"disabled>%d</button>",i,i);   
                    }
                    else{
                    printf("<button class=\"page\" type=\"sybmit\" name=\"button\" value=\"%d\">%d</button>",i,i);
                    }
                }
                int i = 0;    
                printf("</form>");
                printf("<div class=\"tableau\">");
                printf("<table style=\"color:white;\"><tr style=\"background-color:black;border-radius:20px 20px 0px 0px\"><td>date</td><td>session</td><td>user</td></tr>");
                while(fgets(line,200,ress)){
                    char date3[200];
                sscanf(line,"%[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %s\n",date2,date1,date3,heure,action,us);
                if(i%2 == 0){
                    if(strcmp(action,"opened")==0){
                    printf("<tr class=\"tr\"><td>%s %s %s %s</td><td><div class=\"session\"><p>%s</p></div></td><td>%s</td></tr>",date2,date1,date3,heure,action,us);
                    }
                    else{
                        printf("<tr class=\"tr\"><td>%s %s %s %s</td><td><div class=\"session1\"><p>%s</p></div></td><td>%s</td></tr>",date2,date1,date3,heure,action,us);
                    }
                }

                else{
                    if(strcmp(action,"opened")==0){
                    printf("<tr style=\"background-color:rgb(230, 230, 167)\" class=\"tr\"><td>%s %s %s %s</td><td><div class=\"session\"><p>%s</p></div></td><td>%s</td></tr>",date2,date1,date3,heure,action,us);
                    }
                    else{
                        printf("<tr style=\"background-color:rgb(230, 230, 167)\" class=\"tr\"><td>%s %s %s %s</td><td><div class=\"session1\"><p>%s</p></div></td><td>%s</td></tr>",date2,date1,date3,heure,action,us);
                    }
                }
                i++;
                }
                printf("</table>");
                printf("</div>");
                printf("</div>");
                printf("</div>");
                }
            }
}