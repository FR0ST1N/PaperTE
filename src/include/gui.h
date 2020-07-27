// Copyright (c) 2020 Frostin (@FR0ST1N). All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for details.

#ifndef SRC_INCLUDE_GUI_H_
#define SRC_INCLUDE_GUI_H_

#include <gtkmm-3.0/gtkmm/box.h>
#include <gtkmm-3.0/gtkmm/enums.h>
#include <gtkmm-3.0/gtkmm/scrolledwindow.h>
#include <gtkmm-3.0/gtkmm/textview.h>
#include <gtkmm-3.0/gtkmm/window.h>

#include "main.h"

namespace gui {
class Window : public Gtk::Window {
 public:
  explicit Window(AppInfo *app_info);
  virtual ~Window();  // virtual guarantees base class destruction
 private:
  Gtk::Box box;
  Gtk::ScrolledWindow scrolled_window;
  Gtk::TextView text_view;
  Glib::RefPtr<Gtk::TextBuffer> buffer;
};
}  // namespace gui

#endif  // SRC_INCLUDE_GUI_H_
