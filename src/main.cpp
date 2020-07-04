#include "App.h"
#include "Diary.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]){
    using namespace std;
    int i;
    
    //lendo informacoes do config file
    fstream config_file;
    string path, format;

    config_file.open("config", fstream::in);
    if (config_file.fail()){
        //arquivo config nao existe
        config_file.close();

        //criando config padrao
        config_file.open("config", fstream::out);
        if (config_file.fail()){
            cerr << "ERROR. Arquivo nao criado" << endl;
        }
        config_file << "path=diary.md" << endl;
        config_file << "default_format=%d %t: %m" << endl;
        config_file.close();

        config_file.open("config", fstream::in);
        if (config_file.fail()){
            cerr << "ERROR. Nao foi possivel ler config" << endl;
        }
    }
    //pegando as informacoes de config
    getline(config_file, path);
    getline(config_file, format);

    if (strcmp("path=", path.substr(0, 5).c_str()) == 0){
        path = path.substr(5);
    }else{
        cerr << "ERROR. Arquivo config escrito incorretamente" << endl;
        return 1;
    }

    if (strcmp("default_format=", format.substr(0, 15).c_str()) == 0){
        format = format.substr(15);
    }else{
        cerr << "ERROR. Arquivo config escrito incorretamente" << endl;
        return 1;
    }
    config_file.close();

    //execucao do programa
    Diary meudiario(path);
    getText(&meudiario);

    if (argc == 1){
        instructions();
        return 0;
    }
      
    if (strcmp(argv[1], "list") == 0){
        listText(format, &meudiario);
        return 0;
    }

    if (strcmp(argv[1], "add") == 0){
        for (i=2;i<argc;i++){
            addText(argv[i], &meudiario);
        }
        saveText(&meudiario);
        return 0;
    }

    if (strcmp(argv[1], "find") == 0){
        vector<Message> search_results;
            
        for (i=2;i<argc;i++){
            findText(argv[i], &meudiario, &search_results);
        }
        for(vector<Message>::iterator it = search_results.begin(); it != search_results.end(); ++it){
            Diary diariotemp("temp");
            diariotemp.note = search_results;
            listText(format, &diariotemp);
        }
        return 0;
    }
    

    if (strcmp(argv[1], "interactive") == 0){
        string mensagem;
        cout << "Bem vindo ao diario! Digite 'help' para ver a lista de comandos" << endl;
        while(1){
            cout << "Aguardando comando" << endl;
            getline(cin, mensagem);
            if(strcmp(mensagem.c_str(), "help") == 0){
                cout << "help -> Mostra a lista de comandos" << endl;
                cout << "add  -> Adiciona uma mensagem ao diario" << endl;
                cout << "list -> Lista as mensagens escritas no diario" << endl;
                cout << "find -> Acha mensagens que possuem o texto digitado" << endl;
                cout << "exit -> Encerra o programa" << endl;
                continue;
            }
            if(strcmp(mensagem.c_str(), "add") == 0){
                cout << "Digite sua mensagem" << endl;
                getline(cin, mensagem);
                addText(mensagem, &meudiario);
                saveText(&meudiario);
                continue;
            }
            if(strcmp(mensagem.c_str(), "list") == 0){
                listText(format, &meudiario);
                continue;
            }
            if(strcmp(mensagem.c_str(), "find") == 0){
                Diary diariotemp("temp");
                vector<Message> search_results;
                cout << "Escreva a palavra chave" << endl;
                getline(cin, mensagem);
                findText(mensagem, &meudiario, &search_results);
                diariotemp.note = search_results;
                listText(format, &diariotemp);
                search_results.clear();
                continue;
            }
            if(strcmp(mensagem.c_str(), "exit") == 0){
                cout << "ADEUS..." << endl;
                break;
            }
            cout << "Comando invalido. Digite 'help' para ver a lista de comandos" << endl;
        }
        return 0;
    }
    //fim
    
    return 0;
}
