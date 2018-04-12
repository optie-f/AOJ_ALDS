#include <iostream>
#include <algorithm>
#define INT_MAX 2147483647
//よりスッキリ
int main(void){
  int n;
  int val;

  int max_profit = -INT_MAX;
  int minv;

  std::cin >> n;
  std::cin >> minv;

  for(int i=0; i<n-1; i++){
      std::cin >> val;
      max_profit = std::max(max_profit, val - minv);
      minv = std::min(minv, val);
  }

  std::cout << max_profit << '\n';

  return 0;
}
