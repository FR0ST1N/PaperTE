// Copyright (c) 2020 Frostin (@FR0ST1N). All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for details.

#include "include/file.h"
#include "include/gui.h"
#include "include/main.h"

namespace gui {
Window::Window(AppInfo* app_info, std::string file_path)
    : box(Gtk::ORIENTATION_VERTICAL) {
  this->file_path = file_path;
  app_title = app_info->name + ' ' + app_info->version;

  // set app info
  set_title(app_title);
  set_default_size(app_info->default_width, app_info->default_height);

  // only show the scrollbars when they are necessary
  scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  // add textview to the window
  add(box);
  scrolled_window.add(text_view);
  box.pack_start(scrolled_window);

  // init buffer and open file chooser or open file
  buffer = Gtk::TextBuffer::create();
  if (this->file_path == "") {
    OpenFileChooser();
  } else {
    SetBufferText();
  }
  text_view.set_buffer(buffer);

  // add key press event
  add_events(Gdk::KEY_PRESS_MASK);

  show_all_children();
}

Window::~Window() {}

void Window::SetBufferText() {
  buffer->set_text(file::Read(file_path));
  set_title(app_title + " - " + file_path);
}

void Window::OpenFileChooser() {
  Gtk::FileChooserDialog dialog("Please choose a file",
                                Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("_Open", Gtk::RESPONSE_OK);

  // add filters so that only certain file types can be selected
  // show only text files
  auto filter_text = Gtk::FileFilter::create();
  filter_text->set_name("Text files");
  filter_text->add_mime_type("text/plain");
  dialog.add_filter(filter_text);

  // show all files
  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  // show the dialog and wait for a user response:
  int result = dialog.run();

  // handle the response on select
  if (result == Gtk::RESPONSE_OK) {
    file_path = dialog.get_filename();
    SetBufferText();
  }
}

void Window::SaveDialog(bool flag) {
  Gtk::MessageDialog dialog(*this, "Save Info");
  std::string text;
  if (flag) {
    text = "File saved successfully.";
  } else {
    text = "Cannot save.";
  }
  dialog.set_secondary_text(text);
  dialog.run();
}

// key press event listener
bool Window::on_key_press_event(GdkEventKey* key_event) {
  if ((key_event->state & (GDK_SHIFT_MASK | GDK_CONTROL_MASK |
                           GDK_MOD1_MASK)) == GDK_CONTROL_MASK) {
    switch (key_event->keyval) {
      case GDK_KEY_o:  // open event
        OpenFileChooser();
        return true;
      case GDK_KEY_s:  // save event
        if (file_path != "") {
          file::Write(file_path, buffer->get_text());
          SaveDialog(true);
        } else {
          SaveDialog(false);  // called on empty buffer
        }
        return true;
      case GDK_KEY_q:  // quit event
        hide();
        return true;
    }
  }
  return Gtk::Window::on_key_press_event(key_event);
}
}  // namespace gui
