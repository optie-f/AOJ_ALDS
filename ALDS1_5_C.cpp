#include <utility>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;

void koch(pair<double,double> left,
          pair<double,double> right, int n){
  if(n==0){
    std::cout << left.first << ' ' << left.second << '\n';
    return;
  }

  double x1, y1, x2, y2, x3, y3;
  x1 = left.first*2/3 + right.first*1/3;
  y1 = left.second*2/3 + right.second*1/3;
  pair<double,double> s = make_pair(x1, y1);

  x2 = left.first*1/3 + right.first*2/3;
  y2 = left.second*1/3 + right.second*2/3;
  pair<double,double> t = make_pair(x2, y2);

  double theta = atan2((y2-y1),(x2-x1));
  theta += M_PI/3;
  double r = sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
  x3 = r*cos(theta) + x1;
  y3 = r*sin(theta) + y1;
  pair<double,double> u = make_pair(x3, y3);

  koch(left, s, n-1);
  koch(s, u, n-1);
  koch(u, t, n-1);
  koch(t, right, n-1);
}


int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; std::cin >> n;

  pair<double,double> left = make_pair(0,0);
  pair<double,double> right = make_pair(100,0);

  koch(left, right, n);
  std::cout << right.first << ' ' << right.second << '\n';

  return 0;
}
