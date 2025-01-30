#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

#define HEIGHT_PERCENTAGE 60
#define WIDTH_PERCENTAGE 60

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    WebKitWebContext *web_context = webkit_web_context_new();
    WebKitCookieManager *cookie_manager = webkit_web_context_get_cookie_manager(web_context);
    webkit_cookie_manager_set_persistent_storage(cookie_manager, "cookies.sqlite", WEBKIT_COOKIE_PERSISTENT_STORAGE_SQLITE);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    WebKitWebView *webview = WEBKIT_WEB_VIEW(webkit_web_view_new_with_context(web_context));

    GdkScreen *screen = gdk_screen_get_default();
    int screen_width = gdk_screen_get_width(screen);
    int screen_height = gdk_screen_get_height(screen);

    int window_width = screen_width * 0.6;
    int window_height = screen_height* 0.6;
    gtk_window_set_default_size(GTK_WINDOW(window), window_width * WIDTH_PERCENTAGE / 100, window_height * HEIGHT_PERCENTAGE / 100);

    GdkRGBA color;
    gdk_rgba_parse(&color, "black");
    webkit_web_view_set_background_color(webview, &color);

    webkit_web_view_load_uri(webview, "https://chatgpt.com");

    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(webview));

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
