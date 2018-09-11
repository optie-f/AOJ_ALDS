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
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INTINF = 2147483647;
const LL LLINF = 9223372036854775807;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
const int MAX = 100;
int n, M[MAX][MAX];
int d[MAX], color[MAX];

struct init{
    init(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
} init;


void dijkstra(){
  int minv;

  REP0(i,n){
    d[i] = INTINF;
    color[i] = WHITE;
  }

  d[0] = 0;
  color[0] = GRAY;

  while (1) {
    minv = INTINF;
    int u = -1;
    // 未確定頂点のうち最も近いもの := u を選んで確定
    REP0(i,n){
      if ( minv > d[i] && color[i] != BLACK ){
        u = i;
        minv = d[i];
      }
    }
    if ( u == -1 ) break;
    color[u] = BLACK;
    // uから到達可能な未確定頂点を選んで最短距離を更新していく
    REP0(v,n){
      if ( color[v] != BLACK && M[u][v] != INTINF) {
        if ( d[v] > d[u] + M[u][v] ) {
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
        }
      }
    }
  }
}



void input() {
  std::cin >> n;
  REP0(i,n) REP0(j,n) M[i][j] = INTINF;

  int u, k, v, c;
  REP0(i,n){
    std::cin >> u >> k;
    REP0(j,k){
      std::cin >> v >> c;
      M[u][v] = c;
    }
  }
}


void output(){
  REP0(i,n){
    std::cout << i << " " << ( d[i] == INTINF ? -1 : d[i] ) << '\n';
  }
}


int main(int argc, char const *argv[]) {
  input();
  dijkstra();
  output();
  return 0;
}
