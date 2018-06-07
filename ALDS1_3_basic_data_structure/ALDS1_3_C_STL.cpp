#include <iostream>
#include <string>
#include <list>
using namespace std;


int main(int argc, char const *argv[]) {
  int n;
  int x;
  string command;
  std::cin >> n;
  list<int> L;

  for (size_t i = 0; i < n; i++) {
    std::cin >> command;

    if (command == "insert") {
      std::cin >> x;
      L.push_front(x);
    }else if(command == "delete"){
      std::cin >> x;
      for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        if( *it==x ){
          L.erase(it);
          break;
        }
      }

    }else if(command == "deleteFirst"){
      L.pop_front();
    }else if(command == "deleteLast"){
      L.pop_back();
    }
  }

  int i;

  for(list<int>::iterator it = L.begin(); it != L.end(); it++){
    if(i++) std::cout << " ";
    std::cout << *it;
  }
  std::cout << '\n';

  return 0;
}
