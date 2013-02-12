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
    this->selectedTool = 0;
  }

//  CDrawingArea::~CDrawingArea() {
//    // TODO Auto-generated destructor stub
//  }
  
  bool CDrawingArea::on_configure_event (GdkEventConfigure * event) {


    this->surface = this->get_window()->create_similar_surface(Cairo::CONTENT_COLOR, this->get_allocated_width(), this->get_allocated_height());

    //printf("ON CONFIGURE %d %d\n", this->get_allocated_width(), this->get_allocated_height());

    this->clearSurface();

    return true;

  }
  
  void CDrawingArea::clearSurface() {
    Cairo::RefPtr <Cairo::Context> cr;

    cr = Cairo::Context::create(this->surface);
    cr->set_source_rgb(1.0, 1.0, 1.0);
    cr->paint();

  }
  
  void CDrawingArea::drawBrush(double x, double y, double r, double g, double b) {
    Cairo::RefPtr <Cairo::Context> cr;

    cr = Cairo::Context::create(this->surface);

    cr->set_source_rgb(r, g, b);

    cr->set_antialias(Cairo::ANTIALIAS_NONE);
    cr->rectangle(x - 3, y - 3, 6, 6);
    cr->fill();

    //this->queue_draw_area(x - 3, y - 3, 6, 6);
    this->queue_draw();
  }

  bool CDrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    cr->set_source(this->surface, 0, 0);
    cr->paint();

    return false;
  }
  
  bool CDrawingArea::on_button_press_event(GdkEventButton* event) {

    if (event->button == GDK_BUTTON_PRIMARY)
    {
     this->drawTool(event->x, event->y);
    }
    else if (event->button == GDK_BUTTON_SECONDARY)
    {
      this->drawBrush(event->x, event->y, 1.0, 1.0, 1.0);
      //this->clearSurface();
      //this->queue_draw();
    }

    return true;

  }
  
  void CDrawingArea::on_realize() {
    this->set_events(Gdk::BUTTON_PRESS_MASK | Gdk::POINTER_MOTION_MASK);

    Gtk::DrawingArea::on_realize();
  }
  
  void CDrawingArea::setTool(int t) {
    this->selectedTool = t;
  }
  
  void CDrawingArea::drawTool(double x, double y) {
    if (this->selectedTool == 1) {
      this->drawBrush(x, y, 1.0, 0.0, 0.0);
    }
    else if (this->selectedTool == 2) {
      this->drawBrush(x, y, 0.0, 1.0, 0.0);
    }
  }
  
  void CDrawingArea::saveSurface(const char * path) {
    this->surface->write_to_png(path);
  }

  bool CDrawingArea::on_motion_notify_event(GdkEventMotion* event) {

    if (event->state & GDK_BUTTON1_MASK) {
      this->drawTool(event->x, event->y);
    }
    else if ((event->state & GDK_BUTTON2_MASK) || (event->state & GDK_BUTTON3_MASK)) {
      this->drawBrush(event->x, event->y, 1.0, 1.0, 1.0);
    }

    return true;

  }


} /* namespace arrow */
