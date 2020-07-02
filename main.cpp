#include "App.h"
#include "Diary.h"
#include <iostream>

int main(int argc, char *argv[]){
    using namespace std;
    Diary meudiario("meudiario.txt");
    vector<string> search_results;

    addText("Hello there", &meudiario);
    addText("Nice place here", &meudiario);
    addText("What a shame", &meudiario);
    saveText(&meudiario);

    findText("here", &meudiario, &search_results);
    
    vector<string>::iterator it = search_results.begin();
    for(it ; it != search_results.end(); ++it){
        cout << *it << endl;
    }
    
    return 0;
}
