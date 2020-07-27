// Copyright (c) 2020 Frostin (@FR0ST1N). All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for details.

#include <gtkmm-3.0/gtkmm/application.h>

#include <iostream>

#include "include/gui.h"
#include "include/main.h"

int main(int argc, char *argv[]) {
  // App info
  AppInfo app_info;
  app_info.name = "PaperTE";
  app_info.version = "0.1.0";
  app_info.default_width = 640;
  app_info.default_height = 480;

  // GTK
  std::string app_id = "com.github.fr0st1n." + app_info.name;
  auto app = Gtk::Application::create(argc, argv, app_id);
  gui::Window window(&app_info);
  return app->run(window);
}
