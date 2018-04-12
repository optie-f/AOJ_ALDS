#include <iostream>
#define INT_MAX 2147483647

int main(void){
  int n;
  std::cin >> n;
  int val[n];

  int min=INT_MAX;
  int max=0;
  int profit=-INT_MAX;

  for(int i=0; i<n; i++){
      std::cin >> val[i];
      if (val[i] < min){ //底値割
        if(i>0 && profit < val[i]-min){
          profit = val[i]-min;
        }
        min = val[i];
      }else if (profit < val[i]-min){
        profit = val[i]-min;
      }
  }
  std::cout << profit << '\n';
  return 0;
}
