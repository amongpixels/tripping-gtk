/*
 * CSurface.h
 *
 *  Created on: 11 Feb 2013
 *      Author: dragomir
 */

#ifndef CSURFACE_H_
#define CSURFACE_H_

#include <gtk-3.0/gtk/gtk.h>

namespace arrow
{
  
  class CSurface
  {
    private:

      cairo_surface_t * surface;

    public:
      CSurface();

      void clearSurface();

      virtual ~CSurface();
  };

} /* namespace arrow */
#endif /* CSURFACE_H_ */
