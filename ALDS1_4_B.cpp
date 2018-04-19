#include <utility>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[]) {
  int n, val, tmp;
  int len=0;
  std::cin >> n;
  std::vector<int> S; S.reserve(100000);


  for (size_t i = 0; i < n; i++) {
    std::cin >> val;
    if (i==0 || val != tmp) {
      len++;
      S[len]=val;
      tmp=val;
    }
  }

  int num=0;

  int q; std::cin >> q;
  for (size_t i = 0; i < q; i++) {
    std::cin >> val;
    int lower=0;
    int upper=len;
    int mid = upper/2;
    while (1) {
      if (val==S[mid] || val==S[mid+1] || val==S[mid-1]) {
        num++;
        break;
      }
      if(S[0] <= val && val <= S[mid-1]){
        upper = mid;
        mid = (mid + lower)/2;
      }else if (S[mid+1] <= val && val <= S[upper]) {
        lower = mid;
        mid = (mid + upper)/2;
      }else{
        break;
      }
    }

  }
  std::cout << num << '\n';

  return 0;
}
