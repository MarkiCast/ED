#include <iostream>
#include <cctype>
#include "linked_stack.h"
#include <string>
#include <fstream>
#include <cstddef>
#include <cstring>
#include <stdio.h>

using namespace std;

string readfilename() {
  cout << "Digite o nome do arquivo xml a ser lido: " << end1;
  string xmlfile;
  cin >> xmlfile;
  return xmlfile;
}

void parser();

int main() {

    string xmlfilename = readfilename();

    //Abre o xml
    ifstream myfile;
    myfile.open(xmlfilename);

    //Cria a pilha
    auto pile = structures::LinkedStack<string> {};

    //Parser deve ser chamado aqui(como fazer?)

    cout << "funciona" << "\n" << endl;


  return 0;
}

void parser() {
  size_t i;
  size_t e;
  string tag;
  string line;
  size_t pos = 0;
  int lenght = 0;
  if (!myfile.is_open()) {
    throw invalid_argument("O arquivo não pode ser aberto.");
  } else {
    while(getline(myfile, line))  {
      i = line.find_first_of('<', pos);
      e = line.find_first_of('>', pos);
      printf("continua funfando");
      lenght = e-i;
      tag =   line.substr(i,lenght);
      printf("tag funciona");
      if (tag.find('/')) {
        tag = line.substr(i+1,lenght-1);
        if (pile.empty()) {
          printf("aki tbm da merda");
        } else {
          printf("ta convertendo pra char*");
          auto first = tag.c_str();
          auto second = pile.top().c_str();
          if (strcmp(first, second) ==  0) {
            cout << tag << "\n" << endl;
            pile.pop();
          } else {
            throw invalid_argument("Topo da pilha incopatível.");
          }
        }
      } else {
        pile.push(tag);
      }
      pos = e;
    }  //Fim do laço while
    if (!pile.empty()) {
      throw invalid_argument("Pilha não finaliza vazia.");
    } else {
      return;
    }
  } //Fim do else "arquivo aberto"
}  //Fim da função parser()
