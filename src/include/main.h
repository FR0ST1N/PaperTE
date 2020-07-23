// Copyright (c) 2020 Frostin (@FR0ST1N). All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for details.

#ifndef SRC_INCLUDE_MAIN_H_
#define SRC_INCLUDE_MAIN_H_

#include <string>

typedef struct {
  std::string name;
  std::string version;
  int default_height;
  int default_width;
} AppInfo;

int main(int, char**);

#endif  // SRC_INCLUDE_MAIN_H_
