#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <fstream>
#include "Diary.h"

void newDiary(std::string file_name, Diary* diary);
void killDiary(Diary* diary);
void addText(std::string text, Diary* diary);
void writeText(const std::string& file_name);
void instructions(const std::string& prog_name);
void listText(const std::string& file_name);

#endif
