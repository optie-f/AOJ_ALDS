#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[]) {
  int n, key, cnt=0;
  std::cin >> n;

  std::vector<int> S; S.reserve(10001);

  for (size_t i = 0; i < n; i++) {
    std::cin >> S[i];
  }

  int q;  std::cin >> q;

  for (size_t i = 0; i < q; i++) {
    std::cin >> key;
    for (size_t j = 0; j < n; j++) {
      if (key==S[j]) {
        cnt++;
        break;
      }
    }
  }

  std::cout << cnt << '\n';

  return 0;
}
