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
const int N = 100;
int color[N]; // i's visit status
int M[N][N];
int d[N];  // minimum weight
int p[N]; // i's parent vertex in MST
int n;

#define WHITE 0
#define GRAY 1
#define BLACK 2

struct init{
    init(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
} init;


void prim(){
  int u, minv;

  REP0(i,n){
    color[i] = WHITE;
    d[i] = INTINF;
    p[i] = -1;
  }

  d[0] = 0;

  while (1) {
    minv = INTINF;
    u = -1;
    REP0(i,n){
      if( minv > d[i] && color[i] != BLACK ){
        u = i;
        minv = d[i];  // MSTの隣接辺のうち最小重みを選ぶ
      }
    }
    if ( u==-1 ) break; // 最小重みがなく終了
    color[u] = BLACK; // uをMSTに追加
    REP0(v,n){ // 新たなMSTで, 隣接する頂点の重みと親を更新
      if ( color[v] != BLACK && M[u][v] != INTINF  && d[v] > M[u][v] ) {
        d[v] = M[u][v];
        p[v] = u;
        color[v] = GRAY;
      }
    }
  }

 int sum = 0;
 REP0(i,n){ // MST内で親を持つ頂点について
   if( p[i] != -1 ) sum += M[i][p[i]];
 }
 std::cout << sum << '\n';
}


void input(){
  std::cin >> n;
  int w;
  REP0(i,n) REP0(j,n) {
    std::cin >> w;
    M[i][j] = (w==-1) ? INTINF : w;
  }
}


int main(int argc, char const *argv[]) {
  input();
  prim();
  return 0;
}
