/*
 * CDrawingArea.h
 *
 *  Created on: 11 Feb 2013
 *      Author: dragomir
 */

#ifndef CDRAWINGAREA_H_
#define CDRAWINGAREA_H_

#include <gtkmm-3.0/gtkmm.h>
#include <cairomm/cairomm.h>

namespace arrow
{
  
  class CDrawingArea : public Gtk::DrawingArea
  {
    private:
      Cairo::RefPtr <Cairo::Surface> surface;

      void clearSurface();
      void drawBrush(double x, double y, double r = 1.0, double g = 1.0, double b = 1.0);
      void drawTool(double x, double y);

      int selectedTool;

    public:
      //CDrawingArea();
      CDrawingArea(GtkDrawingArea * cobject, const Glib::RefPtr<Gtk::Builder>& builder);
      //virtual ~CDrawingArea();

      void setTool(int t);
      void saveSurface(const char * path);

    protected:

      virtual void on_realize();
      virtual bool on_configure_event (GdkEventConfigure * event);
      virtual bool on_draw(const Cairo::RefPtr<Cairo::Context> & cr);
      virtual bool on_button_press_event (GdkEventButton * event);
      virtual bool on_motion_notify_event (GdkEventMotion * event);
  };

} /* namespace arrow */
#endif /* CDRAWINGAREA_H_ */
