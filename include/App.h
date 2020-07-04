#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "Diary.h"

//passa instrucoes de utilizacao do programa
void instructions();

//adiciona novas mensagens em um diary
void addText(std::string mess, Diary* diary);

//salva diary em um arquivo
void saveText(Diary* diary);

//acha mensagens em diary que possuem um texto passado
void findText(std::string mess, Diary* diary, std::vector<Message>* results);

//recupera as mensagens do arquivo no formato diary
void getText(Diary* diary);

//lista todas as mensagens de um diary
void listText(std::string format, Diary* diary);

#endif
