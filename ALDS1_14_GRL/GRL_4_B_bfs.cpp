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
const int MAX = 100000;

VI G[MAX]; // G[i] には iから到達可能な頂点が入る
list<int> out;
bool V[MAX];
int N, E;
int indeg[MAX]; // 入次数=到達に必要な仕事(ノード)の数

struct init{
    init(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
} init;


void input(){
  int s,t;
  std::cin >> N >> E;

  REP0(i,N) V[i] = false;

  REP0(i,E){
    std::cin >> s >> t;
    G[s].PB(t);
  }

}


void bfs( int s ) {
  queue<int> Q;
  Q.push(s);
  V[s] = true;

  while ( !Q.empty() ) {
    int u = Q.front(); Q.pop();
    out.PB(u);
    REP0( i, G[u].size() ){ // u に到達したら
      int v = G[u][i]; // uから到達可能な頂点の入次数を下げる
      indeg[v]--;
      if ( indeg[v]==0 && !V[v] ) {
        V[v] = true;
        Q.push(v);
      }
    }
  }

}


void tsort(){
  REP0( i, N ) indeg[i] = 0;

  REP0( u, N ){
    REP0( i, G[u].size() ){ // 各点から到達可能な頂点を列挙することで入次数をカウント
      int v = G[u][i];
      indeg[v]++;
    }
  }

  REP0( u, N ){
    if ( indeg[u]==0 && !V[u] ) bfs(u);
  }

}


void output(){
  for ( list<int>::iterator it = out.begin(); it != out.end(); it++ ) {
    std::cout << *it << '\n';
  }
}


int main(int argc, char const *argv[]) {
  input();
  tsort();
  output();
  return 0;
}
