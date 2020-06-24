#include "App.h"
#include "Diary.h"
#include <iostream>

int main(int argc, char *argv[]){
    using namespace std;

    Diary meudiario;
    newDiary("meudiario.txt", &meudiario);
    addText(argv[1], &meudiario);
    cout << meudiario.message[0].text << endl;
    killDiary(&meudiario);
    return 0;
}
