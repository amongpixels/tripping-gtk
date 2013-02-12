/*
 * CWindow.h
 *
 *  Created on: 11 Feb 2013
 *      Author: dragomir
 */

#ifndef CWINDOW_H_
#define CWINDOW_H_

#include <cstdio>
#include <gtkmm-3.0/gtkmm.h>

#include "CDrawingArea.h"
#include "CPreviewArea.h"

namespace arrow
{
  
  class CWindow : public Gtk::Window
  {
    private:

      CDrawingArea * drawingArea;
      CPreviewArea * previewArea;

      Gtk::ToggleToolButton * volcanoTool, * mountainTool;
      Gtk::ToolButton * generateTool;

    protected:

      void on_mountain_tool_select();
      void on_volcano_tool_select();
      void on_generate_tool_click();

    public:
      CWindow();
      CWindow(GtkWindow * cobject, const Glib::RefPtr<Gtk::Builder>& builder);
      virtual ~CWindow();
  };

} /* namespace arrow */
#endif /* CWINDOW_H_ */
