#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main(void){
  std::string s;
  int a,b;
  stack<int> S;

  while(std::cin >> s){
    if(s=="+"){
      b = S.top(); S.pop();
      a = S.top(); S.pop();
      S.push(a + b);
    } else if (s=="-") {
      b = S.top(); S.pop();
      a = S.top(); S.pop();
      S.push(a - b);
    } else if (s=="*") {
      b = S.top(); S.pop();
      a = S.top(); S.pop();
      S.push(a * b);
    } else {
      int val = std::stoi(s);
      S.push( val );
    }
  }


  std::cout << S.top() << '\n';

  return 0;
}
