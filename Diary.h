#ifndef DIARY_HPP
#define DIARY_HPP

#include <iostream>
#include "Message.h"
#include <string.h>
#include <vector>

struct Diary{
    std::string filename;
    std::vector<Message> note;
    
    Diary(const std::string& file_name){
        filename = file_name;
    }
    ~Diary(){
    }
};

#endif
