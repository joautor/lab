// Compilation: 
// gcc -o simple simple.c `pkg-config --libs --cflags gtk+-2.0`
// gcc -o simple simple.c `pkg-config --libs --cflags gtk+-3.0`

#include <gtk/gtk.h>


GdkPixbuf* create_pixbuf(const char* filename)
{
    GdkPixbuf* pixbuf = NULL;
    GError* error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);
    if (pixbuf == NULL) {
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }
    return pixbuf;
}

void print_msg(GtkWidget* pWidget, gpointer window)
{
    //g_printf("Button-A was clicked!\n");
    g_print("Button-A was clicked!\n");
    printf("using printf\n");
}

int main(int argc, char* argv[])
{
    gtk_init(&argc, &argv);  // MUST be called first before using any other GTK+ functions

    GtkWidget *pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    if (pWindow == NULL) {
        printf("pWindow is NULL!");
        exit(-1); 
    }
    // Set main window
    gtk_window_set_title(GTK_WINDOW(pWindow), "Autorun"); // If title is not set, GTK will use the source filename as title
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 230, 150); // Client area
    gtk_window_set_position(GTK_WINDOW(pWindow), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(pWindow), 15); // Not working?

    //Set  Icon
    GdkPixbuf* pIcon = create_pixbuf("robot.png");
    if (pIcon == NULL) {
        printf("pIcon is NULL!");
        exit(-1);
    }
    gtk_window_set_icon(GTK_WINDOW(pWindow), pIcon);

    // Add button
    GtkWidget* pButton = gtk_button_new_with_label("Button A");
    if (pButton == NULL) {
        printf("pButton is NULL!");
        exit(-1);
    }
    gtk_widget_set_tooltip_text(pButton, "I am a Button. Now you know.");

    // Add Container
    // This is deprecated
    /*GtkWidget* pHAlign = gtk_alignment_new(0, 0, 0, 0);
    gtk_container_add(GTK_CONTAINER(pHAlign), pButton);
    gtk_container_add(GTK_CONTAINER(pWindow), pHAlign); */

    // Add Container (gtk 3)
    /*
    Notes:
    GtkAlign enum
        GTK_ALIGN_START: The 'start' of the layout. Vertically this is teh top, horizontal this is left/right according to LTR/RTL
        GTK_ALIGN_END: Opposite of GTK_ALIGN_START
        GTK_ALIGN_CENTER: The middle of the layout
        GTK_ALIGN_FILL: Take all available space
    */
    gtk_widget_set_halign(pButton, GTK_ALIGN_START); // parameters: GtkWidth* widget, GtkAlign align)
    gtk_widget_set_valign(pButton, GTK_ALIGN_START);
    gtk_container_add(GTK_CONTAINER(pWindow), pButton);

    // Make our window visible
    // gtk_widget_show(pWindow);
    gtk_widget_show_all(pWindow);


    // The g_signal_connect() function connects a callback function to a signal for a particular object.
    // This window does not react to the 'destroy' signal by default. We must explicitly terminate
    // the application by connecting the 'destroy' signal to the build-in gtk_main_quit() function,
    // which terminates the application
    g_signal_connect(pWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(pButton, "clicked", G_CALLBACK(print_msg), NULL);

    // The g_object_unref() decreases the reference count of the pixbuf object.
    // When its reference cout drops to 0, the object is finalized(i.e. its memory is freed)
    g_object_unref(pIcon);

    gtk_main();   // Enters the GTK+ main loop

    return 0;
}
