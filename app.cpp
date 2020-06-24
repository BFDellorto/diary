#include "App.h"
#include "Diary.h"
#include "Message.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

std::string format_current_date(const std::string& format){
    std::time_t time = std::time(nullptr);
    char result[1024];
    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
    return std::string(result);
}

std::string get_current_date(){
    return format_current_date("%d/%m/%Y");
}

std::string get_current_time(){
    return format_current_date("%H:%M:%S");
}

void newDiary(std::string file_name, Diary* diary){
    (*diary).filename = file_name;
    (*diary).mcap = 10;
    (*diary).msize = 0;
    (*diary).message = new Message[10];

};

void killDiary(Diary* diary){
    delete[] (*diary).message;
}

void instructions(const std::string& prog_name){

};
void addText(std::string mess, Diary* diary){
    int pos = (*diary).msize;
    (*diary).message[pos].text = mess;
    (*diary).message[pos].date = get_current_date();
    (*diary).message[pos].time = get_current_time();
    (*diary).msize++;
};
void writeText(const std::string& file_name){

};
void listText(const std::string& file_name){

};
