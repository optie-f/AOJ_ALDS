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

int binarySearch(int key, const std::vector<int> &S){
  int L = 0;
  int R = S.size();
  int mid;
  while (L < R) {
    mid = (L+R)/2;
    if (S[mid]==key) {
      return 1;
    }
    if (key > S[mid]) {
      L = mid + 1;
    }else if (key < S[mid]) {
      R = mid;
    }
  }
  return 0;
}


int main(int argc, char const *argv[]) {
  int n; std::cin >> n;
  int val;
  std::vector<int> S; S.reserve(100000);

  for (size_t i = 0; i < n; i++) {
    std::cin >> val;
    S.push_back(val);
    }

  int num=0;


  int q; std::cin >> q;
  int key;
  for (size_t i = 0; i < q; i++) {
    std::cin >> key;
    if (binarySearch(key, S)) num++;
  }


  std::cout << num << '\n';

  return 0;
}
