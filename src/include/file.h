// Copyright (c) 2020 Frostin (@FR0ST1N). All rights reserved.
// Licensed under the MIT license.
// See LICENSE file in the project root for details.

#ifndef SRC_INCLUDE_FILE_H_
#define SRC_INCLUDE_FILE_H_

#include <string>

namespace file {
std::string Read(std::string file_path);
void Write(std::string file_path, std::string content);
}  // namespace file

#endif  // SRC_INCLUDE_FILE_H_
