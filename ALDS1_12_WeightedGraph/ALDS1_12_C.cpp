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
const int MAX = 10000;

int n;
std::vector<PII> adj[MAX];

struct init{
    init(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
} init;


void dijkstra(){
  priority_queue<PII> PQ;  // <cost, vertex> のPQ
  int color[MAX];
  int d[MAX];  // d[i] : mincost from s to i
  REP0(i,n){
    d[i] = INTINF;
    color[i] = WHITE;
  }
  d[0] = 0;
  PQ.push(MP(0,0));
  color[0] = GRAY;
  while ( !PQ.empty() ) {
    PII f = PQ.top(); PQ.pop(); //最小となる頂点と重み
    int u = f.second;
    color[u] = BLACK;

    if( d[u] < f.first * -1 ) continue;

    REP0( j, adj[u].size() ){ // uに隣接する頂点をみていく
      int v = adj[u][j].first;
      if ( color[v] == BLACK ) continue;
      if ( d[v] > d[u] + adj[u][j].second ){ // does it renew shortest path to v
        d[v] = d[u] + adj[u][j].second;
        PQ.push(MP(d[v]*-1, v));
        color[v] = GRAY;
      }
    }
  }

  REP0(i,n){
    std::cout << i << " " << (d[i] == INTINF ? -1 : d[i]) << '\n';
  }
}


void input(){
  int u,k,v,c;
  std::cin >> n;
  REP0(i,n){
    std::cin >> u >> k;
    REP0(j,k){
      std::cin >> v >> c;
      adj[u].PB(MP(v,c));
    }
  }
}


int main(int argc, char const *argv[]) {
  input();
  dijkstra();
  return 0;
}
