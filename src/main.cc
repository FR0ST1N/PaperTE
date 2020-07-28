// Copyright (c) 2020 Frostin (@FR0ST1N). All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for details.

#include "include/gui.h"
#include "include/main.h"

int main(int argc, char **argv) {
  // app info
  AppInfo app_info;
  app_info.name = "PaperTE";
  app_info.version = "0.1.0";
  app_info.default_width = 640;
  app_info.default_height = 480;

  // file path from command line argument
  std::string file_path;
  if (argc == 2) {
    file_path.assign(argv[1], strlen(argv[1]));
  }

  // gtk
  std::string app_id = "com.github.fr0st1n." + app_info.name;
  auto app = Gtk::Application::create(app_id);
  gui::Window window(&app_info, file_path);
  return app->run(window);
}
