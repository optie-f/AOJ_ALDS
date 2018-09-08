#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP0(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define RREP0(i,n) for(int i=n-1; i>=0; --i)
#define RREP1(i,n) for(int i=n; i>=1; --i)

#define SORT(c) sort((c).begin(),(c).end())
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define CLR(a) memset((a), 0 ,sizeof(a))

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INTINF = 2147483647;
const LL LLINF = 9223372036854775807;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int MAX = 100000;
const int NIL = -1;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m,q;
VI G[MAX];
int color[MAX];


void dfs(int r, int c) {
  stack<int> S;
  S.push(r);
  color[r] = c;
  while ( !S.empty() ) {
    int u = S.top(); S.pop();
    REP0( i, G[u].size() ){
      int v = G[u][i];
      if ( color[v] == NIL ) {
        color[v] = c;
        S.push(v);
      }
    }
  }
}


void assignColor(){
  int id=1;
  REP0(i,n) color[i]=NIL;
  REP0(u,n) if (color[u]==NIL) dfs(u, id++);
  //連結成分ごとにdfsしcoloring
}


void input(){
  std::cin >> n >> m;
  int s,t;
  REP0(i,m){
    std::cin >> s >> t;
    G[s].PB(t);
    G[t].PB(s);
  }
}


void output() {
  std::cin >> q; int s,t;
  REP0(i,q){
    std::cin >> s >> t;
    if (color[s]==color[t]) {
      std::cout << "yes" << '\n';
    }else{
      std::cout << "no" << '\n';
    }
  }
}


int main(int argc, char const *argv[]) {
  input();
  assignColor();
  output();
  return 0;
}
