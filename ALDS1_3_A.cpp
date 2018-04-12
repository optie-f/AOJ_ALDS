#include <iostream>
#include <algorithm>
#include <string>


class Stack {
private:
  int container[100];
  int num;

public:
  Stack(){ num=0; };
  void show() {
    for (int i = 0; i < num; i++) {
      std::cout << container[i] << ' ';
    }
    std::cout  << '\n';
};
  void push(int val){ container[num++]=val; };
  int pop(){ num--; return container[num]; };

};



int main(void){
  std::string s;
  int a,b;
  Stack stack = Stack();

  while(std::cin >> s){
    if(s=="+"){
      b = stack.pop();
      a = stack.pop();
      stack.push(a + b);
    } else if (s=="-") {
      b = stack.pop();
      a = stack.pop();
      stack.push(a - b);
    } else if (s=="*") {
      b = stack.pop();
      a = stack.pop();
      stack.push(a * b);
    } else {
      int val = std::stoi(s);
      stack.push( val );
    }
//    stack.show();
  }


  std::cout << stack.pop() << '\n';

  return 0;
}
