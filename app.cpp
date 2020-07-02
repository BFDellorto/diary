#include "App.h"
#include "Diary.h"
#include "Message.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void instructions(const std::string& prog_name){

};
void addText(std::string mess, Diary* diary){
    Message newmessage;
    newmessage.text = mess;
    newmessage.date = get_current_date();
    newmessage.time = get_current_time();
    ((*diary).note).push_back(newmessage);
};

void saveText(Diary* diary){
    std::fstream arquivo;
    std::string lastdate, fileline;
    int flag = 0;
    
    arquivo.open((*diary).filename, std::fstream::app);
    if (arquivo.fail()){
        std::cerr << "ERROR0. Nao foi possivel criar o arquivo" << std::endl;
    }
    arquivo.close();

    arquivo.open((*diary).filename, std::fstream::in);
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
    arquivo.close();

    arquivo.open((*diary).filename, std::fstream::app);
    if (arquivo.fail()){
        std::cerr << "ERROR2. Nao foi escrever no arquivo" << std::endl;
    }
    std::vector<Message>::iterator it = ((*diary).note).begin();
    lastdate = (*it).date;
    for(it ; it != ((*diary).note).end(); ++it){
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
};

void findText(std::string text, Diary* diary, std::vector<std::string>* results){
    std::fstream arquivo;
    std::string fileline;
    std::size_t found;

    arquivo.open((*diary).filename, std::fstream::in);
    if (arquivo.fail()){
        std::cerr << "ERROR3. Nao foi encontrado um arquivo." << std::endl 
        << "Variavel <diary.filename> deve referenciar um arquivo existente" << std::endl
        << "Sugestao: Use o comando saveText(_endereco de <diary>_) para criar um arquivo." << std::endl;
        exit(EXIT_FAILURE);
    }
    while (!arquivo.eof()){
        getline(arquivo, fileline);
        found = fileline.find(text);
        if (found != std::string::npos){
            (*results).push_back(fileline);
        }
    }
    arquivo.close();
};

void listText(const std::string& file_name){

};
