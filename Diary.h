#ifndef DIARY_HPP
#define DIARY_HPP

#include <iostream>
#include "Message.h"
#include <string.h>

struct Diary{
    Diary(const std::string& file_name){
        filename = file_name;
        mcap = 10;
        msize = 0;
        message = new Message[mcap];
    }
    ~Diary(){
        delete[] message;
    }

    std::string filename;
    Message* message;
    size_t msize;
    size_t mcap;
};

#endif
