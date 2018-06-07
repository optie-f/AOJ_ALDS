#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//番兵により比較回数の削減
int isin_Lsearch(std::vector<int> A, int n, int key){
  int i=0;
  A.push_back(key);
  while (A[i] != key) i++;
  return i != n;
}

int main(int argc, char const *argv[]) {
  int n, tmp, key, cnt=0;
  std::cin >> n;

  std::vector<int> S; S.reserve(10001);

  for (size_t i = 0; i < n; i++) {
    std::cin >> tmp;
    S.push_back(tmp);
  }

  int q;  std::cin >> q;

  for (size_t i = 0; i < q; i++) {
    std::cin >> key;
    if( isin_Lsearch(S, n, key) ) cnt++;
  }

  std::cout << cnt << '\n';

  return 0;
}
