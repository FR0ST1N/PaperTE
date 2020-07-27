// Copyright (c) 2020 Frostin (@FR0ST1N). All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for details.

#include <iostream>

#include "include/gui.h"
#include "include/main.h"

namespace gui {
Window::Window(AppInfo *app_info) : box(Gtk::ORIENTATION_VERTICAL) {
  //  set app info
  set_title(app_info->name + ' ' + app_info->version);
  set_default_size(app_info->default_width, app_info->default_height);

  //  only show the scrollbars when they are necessary
  scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  //  add textview to the window
  add(box);
  scrolled_window.add(text_view);
  box.pack_start(scrolled_window);
  buffer = Gtk::TextBuffer::create();
  buffer->set_text("Yo Yoo Yooo!");
  text_view.set_buffer(buffer);
  show_all_children();
}

Window::~Window() {}
}  // namespace gui
