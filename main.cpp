#include "App.h"
#include "Diary.h"
#include <iostream>

int main(int argc, char *argv[]){
    using namespace std;

    Diary meudiario("meudiario.txt");
    addText(argv[1], &meudiario);
    cout << meudiario.message[0].date << endl;
    cout << meudiario.message[0].time << endl;
    cout << meudiario.message[0].text << endl;

    return 0;
}
