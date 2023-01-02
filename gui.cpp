#include <gtk/gtk.h>
#include <string>
#include "guihelper.h"
#include <fstream>

using namespace std;

// Declare global variables
GtkWidget *window;
GtkWidget *text_view;
GtkTextBuffer *buffer;

void on_run_clicked() {
  // Get the text from the text view
  GtkTextIter start, end;
  gtk_text_buffer_get_bounds(buffer, &start, &end);
  string text = gtk_text_buffer_get_text(buffer, &start, &end, false);

  // Run the guiinterpret function
  guihandler(text);
}

// Function to save the text to a file
void on_save_clicked() {
  // Show a file chooser dialog to select the file to save
  GtkWidget *dialog = gtk_file_chooser_dialog_new("Save File",
                                                   GTK_WINDOW(window),
                                                   GTK_FILE_CHOOSER_ACTION_SAVE,
                                                   "Cancel", GTK_RESPONSE_CANCEL,
                                                   "Save", GTK_RESPONSE_ACCEPT,
                                                   NULL);
  if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
    char *filename;
    filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
    gtk_widget_destroy(dialog);

    // Get the text from the text view
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    string text = gtk_text_buffer_get_text(buffer, &start, &end, false);

    // Save the text to the file
    ofstream out(filename);
    out << text;
    out.close();
  } else {
    gtk_widget_destroy(dialog);
  }
}

// Function to open a file and load its contents into the text view
void on_open_clicked() {
  // Show a file chooser dialog to select the file to open
  GtkWidget *dialog = gtk_file_chooser_dialog_new("Open File",
                                                   GTK_WINDOW(window),
                                                   GTK_FILE_CHOOSER_ACTION_OPEN,
                                                   "Cancel", GTK_RESPONSE_CANCEL,
                                                   "Open", GTK_RESPONSE_ACCEPT,
                                                   NULL);
  if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
    char *filename;
    filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
    gtk_widget_destroy(dialog);

    // Open the file and read its contents
    ifstream in(filename);
    string text((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    // Set the text in the text view
    gtk_text_buffer_set_text(buffer, text.c_str(), -1);
  } else {
    gtk_widget_destroy(dialog);
  }
}

int startGUI(int argc, char *argv[]) {
  // Initialize GTK
  gtk_init(&argc, &argv);

  // Create the window
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Text Editor");
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  // Create the box
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(window), box);

  // Create the text view
  text_view = gtk_text_view_new();
  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
  gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);
  gtk_box_pack_start(GTK_BOX(box), text_view, true, true, 0);

  // Create the "run" button
  GtkWidget *run_button = gtk_button_new_with_label("Run");
  g_signal_connect(run_button, "clicked", G_CALLBACK(on_run_clicked), NULL);
  gtk_box_pack_start(GTK_BOX(box), run_button, false, false, 0);

  // Create the "save" button
  GtkWidget *save_button = gtk_button_new_with_label("Save");
  g_signal_connect(save_button, "clicked", G_CALLBACK(on_save_clicked), NULL);
  gtk_box_pack_start(GTK_BOX(box), save_button, false, false, 0);

  // Create the "open" button
  GtkWidget *open_button = gtk_button_new_with_label("Open");
  g_signal_connect(open_button, "clicked", G_CALLBACK(on_open_clicked), NULL);
  gtk_box_pack_start(GTK_BOX(box), open_button, false, false, 0);

  // Show the window and run the main loop
  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}

