#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
typedef struct MenBar{
	GtkWidget *barreMenu;
	GtkWidget *menu;
	}MenBar;
	
int main(int argc,char **argv){
	gtk_init(&argc,&argv);
	GtkWidget *fenetre;
	GtkWidget *item;
	GtkWidget *fixe;
	MenBar fich;
	
/// fenetre
	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(fenetre),"zone");
	gtk_window_set_default_size(GTK_WINDOW(fenetre),900,600);
	
/// widget
	fixe = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(fenetre),fixe);
	fich.barreMenu = gtk_menu_bar_new();
	fich.menu = gtk_menu_new();
	item = gtk_menu_item_new_with_label("Nouveau");
	gtk_menu_shell_append(GTK_MENU_SHELL(fich.menu),item);
	item = gtk_menu_item_new_with_label("Ouvrir");
	gtk_menu_shell_append(GTK_MENU_SHELL(fich.menu),item);
	item = gtk_menu_item_new_with_label("Quitter");
	gtk_menu_shell_append(GTK_MENU_SHELL(fich.menu),item);
	item = gtk_menu_item_new_with_label("fichier");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(item),fich.menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(fich.barreMenu),item);
	gtk_fixed_put(GTK_FIXED(fixe),fich.barreMenu,10,10);
	gtk_widget_show_all(fenetre);
	gtk_main();
	return 0;
	}
