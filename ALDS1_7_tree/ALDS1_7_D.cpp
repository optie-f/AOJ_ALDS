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
typedef long long ll;
using namespace std;

int n,pos;
std::vector<int> pre, in, post;

void rec(int l, int r) {
  if (l>=r) return;
  int root = pre[pos++];
  int m = distance(in.begin(), find(in.begin(),in.end(), root));
  rec(l,m);
  rec(m+1,r);
  post.push_back(root);
}

void solve(){
  pos=0;
  rec(0, pre.size());
  for (size_t i = 0; i < n; i++) {
    if (i) std::cout << " ";
    std::cout << post[i];
  }
  std::cout << '\n';
}

void input(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int k;
  std::cin >> n;
  for (size_t i = 0; i < n; i++) {
    std::cin >> k;
    pre.push_back(k);
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> k;
    in.push_back(k);
  }
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
