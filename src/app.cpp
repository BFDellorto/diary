#include "App.h"
#include "Diary.h"
#include "Message.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void instructions(){
    std::cout << "Uso do programa:" << std::endl;
    std::cout << "./diary <comando> argumento(s)" << std::endl;
    std::cout << "Lista de comandos: " << std::endl;
    std::cout << "add" << std::endl << "list" << std::endl << "find" << std::endl << "interactive" << std::endl;

}

void getText(Diary* diary){
    std::fstream arquivo;
    std::string fileline;
    Message newmessage;

    //cria um novo arquivo de diario caso ele nao exista
    arquivo.open(((*diary).filename).c_str(), std::fstream::app);
    if (arquivo.fail()){
        std::cerr << "ERROR0. Nao foi possivel criar o arquivo" << std::endl;
    }
    arquivo.close();

    //extrai mensagens do arquivo para um diary
    arquivo.open(((*diary).filename).c_str(), std::fstream::in);
    if (arquivo.fail()){
        std::cerr << "ERROR. Nao foi encontrado um arquivo." << std::endl;
    }
    while (!arquivo.eof()){
        getline(arquivo, fileline);
        if(strcmp(fileline.substr(0, 2).c_str(), "# ") == 0){
            newmessage.date = fileline.substr(2).c_str();
        }
        if(strcmp(fileline.substr(0, 2).c_str(), "- ") == 0){
            newmessage.time = fileline.substr(2, 8).c_str();
            newmessage.text = fileline.substr(11).c_str();
            ((*diary).note).push_back(newmessage);
        }
    }
    arquivo.close();
}

void listText(std::string format, Diary* diary){
    unsigned i;
    std::vector<Message>::iterator it;

    for(it=((*diary).note).begin(); it != ((*diary).note).end(); ++it){
        for(i=0; i<format.length(); i++){
            if(format.substr(i, 2) == "%d"){
                std::cout << (*it).date;
                i++;
            }else if(format.substr(i, 2) == "%t"){
                std::cout << (*it).time;
                i++;
            }else if(format.substr(i, 2) == "%m"){
                std::cout << (*it).text;
                i++;           
            }else{
                std::cout << format.substr(i, 1);
            }
        }
        std::cout << std::endl;
    }

}

void addText(std::string mess, Diary* diary){
    Message newmessage;
    newmessage.text = mess;
    newmessage.date = get_current_date();
    newmessage.time = get_current_time();
    ((*diary).note).push_back(newmessage);
}

void saveText(Diary* diary){
    std::fstream arquivo;
    std::string lastdate, fileline;
    int flag = 0;

    //procura a ultima data de entrada do arquivo
    /*arquivo.open(((*diary).filename).c_str(), std::fstream::in);
    if (arquivo.fail()){
        std::cerr << "ERROR1. Nao foi possivel abrir o arquivo" << std::endl;
    }
    lastdate = "# " + (*diary).note[0].date;
    while (!arquivo.eof()){
        getline(arquivo, fileline);
        //flag que detecta se a data atual ja existe
        if (lastdate == fileline){
            flag = 1;
        }
    }
    arquivo.close();*/

    //salva novas mensagens no arquivo
    arquivo.open(((*diary).filename).c_str(), std::fstream::out);
    if (arquivo.fail()){
        std::cerr << "ERROR2. Nao foi possivel escrever no arquivo" << std::endl;
    }
    std::vector<Message>::iterator it = ((*diary).note).begin();
    lastdate = (*it).date;
    for(it=((*diary).note).begin() ; it != ((*diary).note).end(); ++it){
        if (lastdate != (*it).date){
            lastdate = (*it).date;
            flag = 0;
        }
        if (flag == 1){
            arquivo << "- " << (*it).time << " " << (*it).text << std::endl;
        }else{
            arquivo << std::endl << "# " << (*it).date << std::endl << std::endl;
            arquivo << "- " << (*it).time << " " << (*it).text << std::endl;
        }
        flag = 1;
    }
    arquivo.close();
}

void findText(std::string text, Diary* diary, std::vector<Message>* results){
    std::size_t found;
    std::vector<Message>::iterator it;
    Message newmessage;

    for(it=((*diary).note).begin(); it != ((*diary).note).end(); ++it){
        found = ((*it).text).find(text);
        if (found != std::string::npos){
            newmessage.text = (*it).text;
            newmessage.time = (*it).time;
            newmessage.date = (*it).date;
            (*results).push_back(newmessage);
        }
    }
}