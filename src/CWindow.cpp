/*
 * CWindow.cpp
 *
 *  Created on: 11 Feb 2013
 *      Author: dragomir
 */

#include "CWindow.h"

namespace arrow
{
  
  CWindow::CWindow() {
    this->mountainTool = 0;
    this->volcanoTool = 0;
    this->generateTool = 0;
  }
  
  CWindow::CWindow(GtkWindow * cobject, const Glib::RefPtr<Gtk::Builder>& builder) : Gtk::Window(cobject) {

    builder->get_widget_derived("drawingArea", this->drawingArea);
    this->drawingArea->set_size_request(256, 256);

    builder->get_widget_derived("previewArea", this->previewArea);
    this->previewArea->set_size_request(256, 256);

    // Get the toolbar and do some magic to it

    builder->get_widget("volcanoTool", this->volcanoTool);
    volcanoTool->signal_toggled().connect(sigc::mem_fun(*this, &CWindow::on_volcano_tool_select));

    builder->get_widget("mountainTool", this->mountainTool);
    mountainTool->signal_toggled().connect(sigc::mem_fun(*this, &CWindow::on_mountain_tool_select));

    builder->get_widget("generateTool", this->generateTool);
    generateTool->signal_clicked().connect(sigc::mem_fun(*this, &CWindow::on_generate_tool_click));


  }
  
  void CWindow::on_mountain_tool_select() {

    if (this->mountainTool->get_active()) {
      this->volcanoTool->set_active(false);
      this->drawingArea->setTool(2);
    }

  }
  
  void CWindow::on_volcano_tool_select() {

    if (this->volcanoTool->get_active()) {
      this->mountainTool->set_active(false);
      this->drawingArea->setTool(1);
    }

  }
  
  void CWindow::on_generate_tool_click() {
    this->drawingArea->saveSurface("input.png");

    FILE * f = popen("./tripping-archer input.png output.png 1", "r");

    const int BUFSIZE = 1000;
    char buf[ BUFSIZE ];

    while( fgets( buf, BUFSIZE,  f ) ) {
      fprintf( stdout, "%s", buf  );
    }

    fclose(f);

    this->previewArea->loadImage("color.png");

  }

  CWindow::~CWindow() {
    // TODO Auto-generated destructor stub
  }

} /* namespace arrow */
