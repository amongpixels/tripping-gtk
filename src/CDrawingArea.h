/*
 * CDrawingArea.h
 *
 *  Created on: 11 Feb 2013
 *      Author: dragomir
 */

#ifndef CDRAWINGAREA_H_
#define CDRAWINGAREA_H_

#include <gtkmm-3.0/gtkmm.h>

#include "CSurface.h"

namespace arrow
{
  
  class CDrawingArea : public Gtk::
  {
    private:
      GtkWidget * drawingArea;
      CSurface * surface;

    public:
      CDrawingArea();
      CDrawingArea(GtkWidget * w);
      void init(GtkWidget * w);
      virtual ~CDrawingArea();
  };

} /* namespace arrow */
#endif /* CDRAWINGAREA_H_ */
