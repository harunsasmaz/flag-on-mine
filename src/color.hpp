#pragma once

#include <string>

using COLOR = const std::string;

COLOR red_fg = "\033[1;31m";
COLOR green_fg = "\033[1;32m";
COLOR yellow_fg = "\033[1;33m";
COLOR blue_fg = "\033[1;34m";
COLOR magenta_fg = "\033[1;35m";
COLOR cyan_fg = "\033[1;36m";
COLOR white_fg = "\033[1;37m";
COLOR blue_bg = "\033[44m";
COLOR white_bg = "\033[47m";
COLOR reset = "\033[0m";