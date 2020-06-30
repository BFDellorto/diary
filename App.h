#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <fstream>
#include "Diary.h"

void addText(std::string text, Diary* diary);
void saveText(Diary* diary);
void findText(std::string mess, Diary* diary);
void instructions(const std::string& prog_name);
void listText(const std::string& file_name);

#endif
