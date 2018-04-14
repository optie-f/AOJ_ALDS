#include <iostream>
#include <algorithm>
#include <queue>

int main(int argc, char const *argv[]) {
  int n;
  int q;
  int cumtime=0;
  int t;
  string name;
  queue<pair<string, int>> Q;
  std::cin >> n >> q;

  for (size_t i = 0; i < n; i++) {
    std::cin >> name;
    std::cin >> t;
    Q.push(make_pair(name,t));
  }

  pair<string, int> cur;

  while (!Q.empty()) {
    cur = Q.front(); Q.pop();
    t = min(cur.second, q);
    cur.second -= t;
    cumtime += t;
    if (cur.second>0) {
      Q.push(cur);
    }else{
      std::cout << cur.first << " " << cumtime << '\n';
    }
  }

  return 0;
}
