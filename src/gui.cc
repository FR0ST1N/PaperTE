// Copyright (c) 2020 Frostin (@FR0ST1N). All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for details.

#include <iostream>

#include "include/gui.h"
#include "include/main.h"

namespace gui {
Window::Window(AppInfo* app_info) : box(Gtk::ORIENTATION_VERTICAL) {
  // set app info
  set_title(app_info->name + ' ' + app_info->version);
  set_default_size(app_info->default_width, app_info->default_height);

  // only show the scrollbars when they are necessary
  scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  // add textview to the window
  add(box);
  scrolled_window.add(text_view);
  box.pack_start(scrolled_window);
  buffer = Gtk::TextBuffer::create();
  buffer->set_text("Yo Yoo Yooo!");
  text_view.set_buffer(buffer);
  add_events(Gdk::KEY_PRESS_MASK);
  show_all_children();
}

Window::~Window() {}

// key press event listener
bool Window::on_key_press_event(GdkEventKey* key_event) {
  if ((key_event->state & (GDK_SHIFT_MASK | GDK_CONTROL_MASK |
                           GDK_MOD1_MASK)) == GDK_CONTROL_MASK) {
    switch (key_event->keyval) {
      case GDK_KEY_o:
        std::cout << "Key Event: Open\n";
        return true;
      case GDK_KEY_s:
        std::cout << "Key Event: Save\n";
        return true;
      case GDK_KEY_q:
        std::cout << "Key Event: Quit\n";
        return true;
    }
  }
  return Gtk::Window::on_key_press_event(key_event);
}
}  // namespace gui
