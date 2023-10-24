#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    printf("Context-Type:text/html\n\n");
    printf("<html><head><title></head></title>");
    printf("<body>");
    printf("<form action=\"http://www.fand.com/cgi-bin/auth/SearchAuth.cgi\" method=\"get\">");
    printf("<input type=\"text\" name=\"utilisateur\"/>");
    printf("<input type=\"text\" name=\"pass\"/>");
    printf("<input type=\"submit\" value=\"connecter\"/>");
    printf("</form>");
    printf("</body></html>");
    return 0;
}