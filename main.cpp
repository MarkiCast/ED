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

    string xmlfilename;
    //std::cin >> xmlfilename;  // entrada

    ifstream myfile ("dataset01.xml");

    auto pile = structures::LinkedStack<string> {};
    size_t i;
    size_t e;
    string tag;
    string line;
    size_t pos = 0;
    int lenght = 0;

    cout << "funciona" << "\n" << endl;

    if(myfile.is_open()){
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
              printf("aki da merda");
            }
          }
        } else {

          pile.push(tag);
        }
        pos = e;
      }
      if (pile.empty()) {
        printf("merda d novo");
      }
    }

  return 0;
}
