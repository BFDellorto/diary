#ifndef APP_HPP
#define APP_HPP

#include <stdio.h>
#include <fstream>
#include "Diary.h"

void instructions(const std::string& prog_name);
void addText(std::string text);
void writeText(const std::string& file_name);
void listText(const std::string& file_name);

#endif