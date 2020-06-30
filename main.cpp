#include "App.h"
#include "Diary.h"
#include <iostream>

int main(int argc, char *argv[]){
    using namespace std;
    Diary meudiario("meudiario.txt");
    addText("Hello there", &meudiario);
    addText("Nice place here", &meudiario);
    addText("What a shame", &meudiario);
    saveText(&meudiario);

    findText("a shame", &meudiario);
    findText("place", &meudiario);

    return 0;
}
