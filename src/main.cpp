#include "App.h"
#include "Diary.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    using namespace std;
    int i;
    Diary meudiario("meudiario.txt");

    if (strcmp(argv[1], "add") == 0){
        for (i=2;i<argc;i++){
            addText(argv[i], &meudiario);
        }
        saveText(&meudiario);
    }

    if (strcmp(argv[1], "find") == 0){
        vector<string> search_results;
        
        for (i=2;i<argc;i++){
            findText(argv[i], &meudiario, &search_results);
        }
        for(vector<string>::iterator it = search_results.begin(); it != search_results.end(); ++it){
                cout << *it << endl;
        }
    }
    
    return 0;
}
