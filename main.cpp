#include <iostream>
#include "linked_queue.h"
#include "linked_stack.h"
#include <string>


int main() {

    string xmlfilename;
    std::cin >> xmlfilename;  // entrada

    ifstream myfile ("myfile.xml");

    auto pile = structures::LinkedQueue<char> {}
    size_t i;
    size_t e;
    string tag;
    size_t pos = 0;
    int line = 0;

    if(myfile.is_open()){
      while(xmlfilename.getline(xmlfilename, line))  {
        i = xmlfilename.find_first_of('<', pos);
        e = xmlfilename.find_first_of('>', pos);
        lenght = e-i;
        tag = xmlfilename.substr(i,lenght);
        if (xmlfilename.find('/')) {
          tag = xmlfilename.substr(i+1,lenght-1);
          if (strcmp(tag, pile.top()) == 0) {
            pile.pop();
          } else {
            printf("aki da merda");
          }
        } else {
          pile.push(tag);
        }

      }
    }

    return 0;
}
