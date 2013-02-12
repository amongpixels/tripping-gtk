/*
 * CPreviewArea.cpp
 *
 *  Created on: 12 Feb 2013
 *      Author: dragomir
 */

#include "CPreviewArea.h"

namespace arrow
{
  
  CPreviewArea::CPreviewArea() {
    // TODO Auto-generated constructor stub
    
  }
  
  CPreviewArea::CPreviewArea(GtkDrawingArea* cobject, const Glib::RefPtr<Gtk::Builder>& builder) : Gtk::DrawingArea(cobject) {

  }

  CPreviewArea::~CPreviewArea() {
    // TODO Auto-generated destructor stub
  }
  
  void CPreviewArea::loadImage(char* path) {
    this->image = Gdk::Pixbuf::create_from_file(path);
    this->queue_draw();
  }

  bool CPreviewArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

    if (!this->image) {
      return false;
    }

    Gtk::Allocation allocation = this->get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    Gdk::Cairo::set_source_pixbuf(cr, this->image, 0, 0);
    cr->paint();

    return true;

  }

} /* namespace arrow */
