#include "App.h"
#include "Diary.h"
#include "Message.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

void instructions(const std::string& prog_name){

};
void addText(std::string mess, Diary* diary){
    (*diary).msize++;
    int pos = (*diary).msize-1;
    int cap = (*diary).mcap;
    int i;
    if(pos>=cap){
        cap *= 2;
        Message* new_array = new Message[cap];
        for(i=0; i<pos; i++){
            new_array[i].text = (*diary).message[i].text;
            new_array[i].date = (*diary).message[i].date;
            new_array[i].time = (*diary).message[i].time;
        }
        delete[] (*diary).message;
        (*diary).message = new_array;
        (*diary).mcap = cap;
    }
    (*diary).message[pos].text = mess;
    (*diary).message[pos].date = get_current_date();
    (*diary).message[pos].time = get_current_time();
};

void saveText(Diary* diary){
    std::fstream arquivo;
    std::string lastdate, fileline;
    int i, flag = 0;
    
    arquivo.open((*diary).filename, std::fstream::app);
    if (arquivo.fail()){
        std::cerr << "ERROR0. Nao foi possivel criar o arquivo" << std::endl;
    }
    arquivo.close();

    arquivo.open((*diary).filename, std::fstream::in);
    if (arquivo.fail()){
        std::cerr << "ERROR1. Nao foi possivel abrir o arquivo" << std::endl;
    }
    lastdate = "# " + (*diary).message[0].date;
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
    lastdate = (*diary).message[0].date;
    for(i=0;i<(*diary).msize;i++){
        if (lastdate != (*diary).message[i].date){
            lastdate = (*diary).message[i].date;
            flag = 0;
        }
        if (flag == 1){
            arquivo << "- " << (*diary).message[i].time << " " << (*diary).message[i].text << std::endl;
        }else{
            arquivo << std::endl << "# " << (*diary).message[i].date << std::endl << std::endl;
            arquivo << "- " << (*diary).message[i].time << " " << (*diary).message[i].text << std::endl;
        }
        flag = 1;
    }
    arquivo.close();
};

void findText(std::string text, Diary* diary){
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
            std::cout << fileline << std::endl;
            break;
        }
    }

    arquivo.close();
};

void listText(const std::string& file_name){

};
