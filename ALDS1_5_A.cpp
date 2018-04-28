#include <utility>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int n;
int A[2000];


bool find(int m, int i){
  if (m==0) {
    return true;
  }else if (i>=n || m<0) {
    return false;
  }
  bool res = find(m, i+1) || find(m-A[i], i+1);
  return res;
}


int main(int argc, char const *argv[]) {
  std::cin >> n;
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  int q; std::cin >> q;

  for (size_t i = 0; i < q; i++) {
    int val;
    scanf("%d", &val);
    if (find(val, 0)) {
      std::cout << "yes" << '\n';
    }else{
      std::cout << "no" << '\n';
    }
  }

  return 0;
}
