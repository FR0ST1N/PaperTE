// Copyright (c) 2020 Frostin (@FR0ST1N). All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for details.

#include "include/gui.h"
#include "include/main.h"

namespace gui {
Window::Window(AppInfo *app_info) {
  set_title(app_info->name + ' ' + app_info->version);
  set_default_size(app_info->default_width, app_info->default_height);
}
Window::~Window() {}
}  // namespace gui
