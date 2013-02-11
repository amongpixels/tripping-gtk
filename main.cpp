/*
 * main.cpp
 *
 *  Created on: 8 Feb 2013
 *      Author: dragomir
 */

#include <gtkmm.h>

#include "src/CDrawingArea.h"

using namespace arrow;

int main(int argc, char *argv[])
{
//  Glib::RefPtr<Gtk::Application> app =
//    Gtk::Application::create(argc, argv,
//      "org.gtkmm.examples.base");
//
//  Gtk::ApplicationWindow window;
//
//  return app->run(window);

  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.chuj");
  Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();

  refBuilder->add_from_file("interface.glade");

  Gtk::Window * window;
  refBuilder->get_widget("mainWindow", window);

  CDrawingArea * area;
  refBuilder->get_widget_derived("drawingArea", area);

  area->set_size_request(200, 200);


//  gtk_widget_set_events (da, gtk_widget_get_events (da)
//        | GDK_BUTTON_PRESS_MASK
//        | GDK_POINTER_MOTION_MASK);

  window->show_all();

  return app->run(*window);
}


/*
#include <gtk-3.0/gtk/gtk.h>

// Surface to store current scribbles
static cairo_surface_t *surface = NULL;

static void clear_surface (void) {
  cairo_t *cr;

  cr = cairo_create (surface);

  cairo_set_source_rgb (cr, 1, 1, 1);
  cairo_paint (cr);

  cairo_destroy (cr);
}

// Create a new surface of the appropriate size to store our scribbles
static gboolean configure_event_cb (GtkWidget *widget, GdkEventConfigure *event, gpointer data) {
  if (surface) {
    cairo_surface_destroy (surface);
  }

  surface = gdk_window_create_similar_surface (gtk_widget_get_window (widget),
                                       CAIRO_CONTENT_COLOR,
                                       gtk_widget_get_allocated_width (widget),
                                       gtk_widget_get_allocated_height (widget));

  // Initialize the surface to white
  clear_surface ();

  // We've handled the configure event, no need for further processing.
  return TRUE;
}

// Redraw the screen from the surface. Note that the ::draw
// signal receives a ready-to-be-used cairo_t that is already
// clipped to only draw the exposed areas of the widget
//
static gboolean
draw_cb (GtkWidget *widget,
 cairo_t   *cr,
 gpointer   data)
{
  cairo_set_source_surface (cr, surface, 0, 0);
  cairo_paint (cr);

  return FALSE;
}

// Draw a rectangle on the surface at the given position
static void
draw_brush (GtkWidget *widget,
    gdouble    x,
    gdouble    y)
{
  cairo_t *cr;

  // Paint to the surface, where we store our state
  cr = cairo_create (surface);

  cairo_rectangle (cr, x - 3, y - 3, 6, 6);
  cairo_fill (cr);

  cairo_destroy (cr);

  // Now invalidate the affected region of the drawing area.
  gtk_widget_queue_draw_area (widget, x - 3, y - 3, 6, 6);
}

// Handle button press events by either drawing a rectangle
// or clearing the surface, depending on which button was pressed.
// The ::button-press signal handler receives a GdkEventButton
// struct which contains this information.
//
static gboolean
button_press_event_cb (GtkWidget      *widget,
               GdkEventButton *event,
               gpointer        data)
{
  //paranoia check, in case we haven't gotten a configure event
  if (surface == NULL)
    return FALSE;

  if (event->button == GDK_BUTTON_PRIMARY)
    {
      draw_brush (widget, event->x, event->y);
    }
  else if (event->button == GDK_BUTTON_SECONDARY)
    {
      clear_surface ();
      gtk_widget_queue_draw (widget);
    }

  // We've handled the event, stop processing
  return TRUE;
}
//
// Handle motion events by continuing to draw if button 1 is
// still held down. The ::motion-notify signal handler receives
// a GdkEventMotion struct which contains this information.
//
static gboolean
motion_notify_event_cb (GtkWidget      *widget,
                GdkEventMotion *event,
                gpointer        data)
{
  // paranoia check, in case we haven't gotten a configure event
  if (surface == NULL)
    return FALSE;

  if (event->state & GDK_BUTTON1_MASK)
    draw_brush (widget, event->x, event->y);

  // We've handled it, stop processing
  return TRUE;
}

static void
close_window (void)
{
  if (surface)
    cairo_surface_destroy (surface);

  gtk_main_quit ();
}

int main (int argc, char *argv[])
{
  GtkBuilder *builder;
  GObject *window;
  GObject *button;
  GtkWidget * da;

  gtk_init (&argc, &argv);

  // Construct a GtkBuilder instance and load our UI description
  builder = gtk_builder_new ();
  gtk_builder_add_from_file (builder, "interface.glade", NULL);

  // Connect signal handlers to the constructed widgets.
  window = gtk_builder_get_object (builder, "mainWindow");
  g_signal_connect (window, "destroy", G_CALLBACK (close_window), NULL);

  da = (GtkWidget*)gtk_builder_get_object(builder, "drawingArea");

  gtk_widget_set_size_request (da, 100, 100);

  // Signals used to handle the backing surface
  g_signal_connect (da, "draw",
      G_CALLBACK (draw_cb), NULL);
  g_signal_connect (da,"configure-event",
      G_CALLBACK (configure_event_cb), NULL);

  // Event signals
  g_signal_connect (da, "motion-notify-event",
      G_CALLBACK (motion_notify_event_cb), NULL);
  g_signal_connect (da, "button-press-event",
      G_CALLBACK (button_press_event_cb), NULL);

  //  Ask to receive events the drawing area doesn't normally
  //  subscribe to. In particular, we need to ask for the
  //  button press and motion notify events that want to handle.
  //
  gtk_widget_set_events (da, gtk_widget_get_events (da)
      | GDK_BUTTON_PRESS_MASK
      | GDK_POINTER_MOTION_MASK);

  gtk_widget_show_all((GtkWidget*)window);

  gtk_main ();

  return 0;
}
*/
