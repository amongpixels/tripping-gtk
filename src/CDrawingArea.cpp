/*
 * CDrawingArea.cpp
 *
 *  Created on: 11 Feb 2013
 *      Author: dragomir
 */

#include "CDrawingArea.h"

namespace arrow
{
  
//  CDrawingArea::CDrawingArea() {
//    // TODO Auto-generated constructor stub
//
//  }
  
  CDrawingArea::CDrawingArea(GtkDrawingArea * cobject, const Glib::RefPtr<Gtk::Builder>& builder) : Gtk::DrawingArea(cobject) {
    //this->surface = 0;
  }

//  CDrawingArea::~CDrawingArea() {
//    // TODO Auto-generated destructor stub
//  }
  
  bool CDrawingArea::on_configure_event (GdkEventConfigure * event) {


    this->surface = this->get_window()->create_similar_surface(Cairo::CONTENT_COLOR, this->get_allocated_width(), this->get_allocated_height());

    printf("ON CONFIGURE %d %d\n", this->get_allocated_width(), this->get_allocated_height());
//    if (this->surface) {
//      cairo_surface_destroy (surface);
//    }
//
//    surface = gdk_window_create_similar_surface(
//        (_GdkWindow *) gtk_widget_get_window((_GtkWidget *)this->gobject_),
//        CAIRO_CONTENT_COLOR,
//        this->get_allocated_width(),
//        this->get_allocated_height()
//    );

    this->clearSurface();

    return true;



//    surface = gdk_window_create_similar_surface (gtk_widget_get_window (widget),
//        CAIRO_CONTENT_COLOR,
//        gtk_widget_get_allocated_width (widget),
//        gtk_widget_get_allocated_height (widget));
//
//    // Initialize the surface to white
//    clear_surface ();
//
//    // We've handled the configure event, no need for further processing.
//    return TRUE;
  }
  
  void CDrawingArea::clearSurface() {
    Cairo::RefPtr <Cairo::Context> cr;

    cr = Cairo::Context::create(this->surface);
    cr->set_source_rgb(1.0, 1.0, 1.0);
    cr->paint();

  }
  
  void CDrawingArea::drawBrush(double x, double y) {
    Cairo::RefPtr <Cairo::Context> cr;

    cr = Cairo::Context::create(this->surface);

    cr->rectangle(x - 3, y - 3, 6, 6);
    cr->fill();

    this->queue_draw_area(x - 3, y - 3, 6, 6);
  }

  bool CDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    cr->set_source(this->surface, 0, 0);
    cr->paint();

    return false;
  }
  
  bool CDrawingArea::on_button_press_event(GdkEventButton* event) {

    if (event->button == GDK_BUTTON_PRIMARY)
    {
      this->drawBrush(event->x, event->y);
    }
    else if (event->button == GDK_BUTTON_SECONDARY)
    {
      this->clearSurface();
      this->queue_draw();
    }

    return true;

  }
  
  void CDrawingArea::on_realize() {
    this->set_events(Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);

    Gtk::DrawingArea::on_realize();
  }

  bool CDrawingArea::on_motion_notify_event(GdkEventMotion* event) {

    if (event->state & GDK_BUTTON1_MASK) {
      this->drawBrush(event->x, event->y);
    }

    return true;

  }


} /* namespace arrow */
