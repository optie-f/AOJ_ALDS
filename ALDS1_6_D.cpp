#include <utility>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MAX 1000
#define VMAX 10000
typedef long long ll;
using namespace std;

int n, A[MAX], s;
int B[MAX], T[VMAX+1];

int solve(){
  int ans=0;

  bool V[MAX];
  for (size_t i = 0; i < n; i++) {
    B[i]=A[i];
    V[i]=false;
  }
  sort(B, B+n);

  for (size_t i = 0; i < n; i++) T[B[i]]=i;
  for (size_t i = 0; i < n; i++) {
    if (V[i]) continue;
    int cur = i;
    int S = 0;
    int m = VMAX;
    int A_n = 0;
    while (1) {
      V[cur] = true;
      A_n++;
      int v = A[cur];
      m = min(m, v);
      S += v;
      cur = T[v];
      if (V[cur]) break;
    }
    ans += min(S + (A_n-2) * m, S + m + (A_n + 1)*s );
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  std::cin >> n;
  s = VMAX;

  for (size_t i = 0; i < n; i++) {
    std::cin >> A[i];
    s = min(s, A[i]);
  }
  int cost = solve();

  std::cout << cost << '\n';

  return 0;
}
