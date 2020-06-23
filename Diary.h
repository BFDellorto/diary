#ifndef DIARY_HPP
#define DIARY_HPP

#include <stdio.h>
#include "Message.h"
#include <string.h>

struct Diary{
    std::string filename;
    Message* message;
    size_t msize;
    size_t mcap;
};

#endif
