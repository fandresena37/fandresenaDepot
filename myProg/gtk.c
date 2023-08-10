#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
int main(int argc,char **argv){
	gtk_init(&argc,&argv);
	GtkWidget *fenetre;
	GtkWidget *fix;
	GtkWidget *bouton;
	GtkWidget *entry;
	gunichar ch = '*';
	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_name(fenetre,"fen");
	gtk_window_set_default_size(GTK_WINDOW(fenetre),700,400);
	gtk_window_set_title(GTK_WINDOW(fenetre),"test");
	fix = gtk_fixed_new();
	bouton = gtk_button_new_with_label("test");
	gtk_widget_set_name(bouton,"bouton");
	entry = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(entry),FALSE);
	gtk_entry_set_invisible_char(GTK_ENTRY(entry),ch);
	gtk_container_add(GTK_CONTAINER(fenetre),fix);
	gtk_widget_set_size_request(GTK_WIDGET(bouton),100,50);
	gtk_widget_set_size_request(GTK_WIDGET(entry),300,50);
	gtk_fixed_put(GTK_FIXED(fix),bouton,300,200);
	gtk_fixed_put(GTK_FIXED(fix),entry,200,150);
	GtkStyleContext *con ;
	con = gtk_widget_get_style_context(bouton);
	gtk_style_context_add_class(con,"bouton");
	GtkCssProvider *pro = gtk_css_provider_new();
	gtk_css_provider_load_from_file(pro,g_file_new_for_path("style.css"),NULL);
	gtk_style_context_add_provider(con,GTK_STYLE_PROVIDER(pro),GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	con = gtk_widget_get_style_context(entry);
	gtk_style_context_add_class(con,"entry");
	gtk_css_provider_load_from_file(pro,g_file_new_for_path("style.css"),NULL);
	gtk_style_context_add_provider(con,GTK_STYLE_PROVIDER(pro),GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	gtk_widget_show_all(fenetre);
	gtk_main();
	
	return 0;
	}
