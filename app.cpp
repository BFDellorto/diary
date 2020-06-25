#include "App.h"
#include "Diary.h"
#include "Message.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

/*void newDiary(std::string file_name, Diary* diary){
    (*diary).filename = file_name;
    (*diary).mcap = 10;
    (*diary).msize = 0;
    (*diary).message = new Message[10];

};

void killDiary(Diary* diary){
    delete[] (*diary).message;
}*/
void instructions(const std::string& prog_name){

};
void addText(std::string mess, Diary* diary){
    int pos = (*diary).msize;
    if(pos>9){
        pos=0;
    }
    (*diary).message[pos].text = mess;
    (*diary).message[pos].date = get_current_date();
    (*diary).message[pos].time = get_current_time();
    (*diary).msize++;
};
void saveText(const std::string& file_name){

};
void listText(const std::string& file_name){

};
