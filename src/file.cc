// Copyright (c) 2020 Frostin (@FR0ST1N). All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for details.

#include <fstream>

#include "include/file.h"

namespace file {
std::string Read(std::string file_path) {
  std::ifstream ifs(file_path);
  std::string content;
  content.assign((std::istreambuf_iterator<char>(ifs)),
                 (std::istreambuf_iterator<char>()));
  return content;
}

void Write(std::string file_path, std::string content) {}
}  // namespace file
