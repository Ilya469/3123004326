#ifndef TEXTUTILS_H
#define TEXTUTILS_H

#include <string>
#include <vector>
#include <stdexcept>

// º¯ÊıÉùÃ÷
std::string read_file(const std::string& file_path);
std::vector<std::string> split_text(const std::string& text);
bool is_utf8(const std::string& str);

#endif