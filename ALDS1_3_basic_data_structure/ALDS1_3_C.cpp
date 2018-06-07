#include <iostream>
#include <string>
using namespace std;

struct DLL {
  DLL *prev, *next;
  int val;
};

DLL* nil; //番兵

void init(){
  nil = new DLL();
  nil->prev = nil;
  nil->next = nil;
}

void insert(int x){
  DLL* node = new DLL();
  nil->next->prev = node;
  node->val = x;
  node->next = nil->next;
  node->prev = nil;
  nil->next = node;

};

void del(DLL* node){
  if(node==nil){return;}
  node->prev->next = node->next;
  node->next->prev = node->prev;
  delete node;
};

DLL* search(int x){
  DLL* node = nil->next;
  while (node!=nil) {
    if(node->val == x){
      return node;
    }else{
      node = node->next;
    }
  }
  return nil;
}

void delFirst(){
  del(nil->next);
};

void delLast(){
  del(nil->prev);
};

void show(){
  DLL* node = nil->next;
  while (node!=nil) {
    std::cout << node->val;
    node = node->next;
    if (node!=nil) {
      std::cout << " ";
    }
  }
  std::cout << '\n';
};

void showback(){
  DLL* node = nil->prev;
  while (node!=nil) {
    std::cout << node->val << ' ';
    node = node->prev;
  }
  std::cout << '\n';
};

int main(int argc, char const *argv[]) {
  int n;
  int x;
  string command;

  std::cin >> n;

  init();

  for (size_t i = 0; i < n; i++) {
    std::cin >> command;

    if (command == "insert") {
      std::cin >> x;
      insert(x);
    }else if(command == "delete"){
      std::cin >> x;
      DLL* node = search(x);
      del(node);
    }else if(command == "deleteFirst"){
      delFirst();
    }else if(command == "deleteLast"){
      delLast();
    }
  }

  show();

  return 0;
}
