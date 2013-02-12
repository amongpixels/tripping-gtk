/*
 * CPreviewArea.h
 *
 *  Created on: 12 Feb 2013
 *      Author: dragomir
 */

#ifndef CPREVIEWAREA_H_
#define CPREVIEWAREA_H_

#include <gtkmm-3.0/gtkmm.h>
#include <cairomm/cairomm.h>

namespace arrow
{
  
  class CPreviewArea : public Gtk::DrawingArea
  {
    public:
      CPreviewArea();
      CPreviewArea(GtkDrawingArea * cobject, const Glib::RefPtr<Gtk::Builder>& builder);
      virtual ~CPreviewArea();

      void loadImage(char * path);

    protected:

      Glib::RefPtr<Gdk::Pixbuf> image;

      virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);


  };

} /* namespace arrow */
#endif /* CPREVIEWAREA_H_ */
