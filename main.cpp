#include <iostream>
#include <cctype>
#include "linked_stack.h"
#include <string>
#include <fstream>
#include <cstddef>
#include <cstring>
#include <stdio.h>

using namespace std;

int main() {

    cout << "Insira nome do arquivo: " << endl;

    string xmlfilename;
    std::cin >> xmlfilename;  // entrada

    ifstream myfile;
    myfile.open(xmlfilename);
    if(!myfile.is_open()) {
      throw invalid_argument("Arquivo não pode ser aberto");
    }

    structures::LinkedStack<string> pilha;
    size_t i;
    size_t e;
    string tag;
    string line;
    size_t pos = 0;
    int lenght;

    while(getline(myfile, line))  {
      i = line.find_first_of('<',pos);
      e = line.find_first_of('>',pos);

      tag = line.substr(i, e-i);

      if (tag.find('/')) {
        tag = line.substr(i+1, e-i-1);
        if (pilha.empty()) {
          throw invalid_argument("Erro no parsing do arquivo");
        } else {
          auto first = tag.c_str();
          auto second = pilha.top().c_str();
          if (strcmp(first, second) ==  0) {
            cout << tag << "\n" << endl;
            pilha.pop();
          } else {
            throw invalid_argument("Erro no parsing do arquivo");
          }
        }
      } else {
        pilha.push(tag);
      }

      pos = e;
    } //  Fim do while

    if (pilha.empty()) {
      cout << "Passou no parsing" << endl;
    } else {
      throw invalid_argument("Erro no parsing do arquivo");
    }






  return 0;
}

