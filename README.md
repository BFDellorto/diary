# diary

Um programa que escreve mensagens em um arquivo salvando a hora e a data de quando foram escritas

#### uso: 
./diary 'comando' 'argumento1' 'argumento2' 'argumento3' ...

#### comandos:
  * add:  Adiciona ao arquivo argumentos como novas linhas de texto
  * find: Acha linhas de texto com os argumentos dados
  * list: Lista todas as mensagens
  * interactive: Modo interativo

#### config
  * O programa possui um arquivo 'config' que permite personalizar o diretorio onde ele salva o arquivo do diario e o formato como ele apresenta as mensagens no programa

#### funcoes
  instructions : Mostra as instrucoes de uso. Chamada quando o usuario nao passa argumentos nem comandos na hora da execucao
  addText      : Funcao responsavel por adicionar mensagems a uma struct 'Diary'
  saveText     : Salva a struct sendo trabalhada no arquivo determinado
  findText     : Acha certas mensagens dentro da struck 'Diary' baseado em um texto passado, retornando um vetor de mensagens contendo as mensagens encontradas
  getText      : Recupera as mensagens do arquivo para a struct 'Diary'
  listText     : Lista todas as mensagens da struck 'Diary'


  
