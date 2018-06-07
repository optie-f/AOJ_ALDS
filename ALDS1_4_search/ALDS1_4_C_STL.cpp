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

int A[1000000], n;

int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cin >> n;
  for (size_t i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  int q,k, sum=0;
  std::cin >> q;

  for (size_t i = 0; i < q; i++) {
    std::cin >> k;
    if (*lower_bound(A, A+n, k)==k) sum++;
  }

  std::cout << sum << '\n';

  return 0;
}
