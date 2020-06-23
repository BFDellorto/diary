#include "App.h"

int main(int argc, char *argv[]){

    instructions(argv[0]);
    addText(argv[2]);
    writeText("file.txt");
    listText("file.txt");
    return 0;
}
