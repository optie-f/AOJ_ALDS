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

int V, E;
VI G[MAX];
bool visited[MAX];
int prenum[MAX], parent[MAX], lowest[MAX], timer;

struct init{
    init(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
} init;


void input(){
  std::cin >> V >> E;
  REP0( i, E ){
    int s, t;
    std::cin >> s >> t;
    G[s].PB(t);
    G[t].PB(s);
  }
}


void dfs( int current, int prev ) {
  // ノード current を訪問直後
  prenum[current] = lowest[current] = timer;
  timer++;

  visited[current] = true;

  int next;

  REP0( i, G[current].size() ){ // currentに接続する頂点集合G[current]について,
    next = G[current][i]; // i番目を next とおき,
    if ( !visited[next] ) { // nextがdfs未訪問ならば
      parent[next] = current;
      dfs( next, current );
      // next の探索が完了した直後の処理
      lowest[current] = min( lowest[current], lowest[next] );
    } else if ( next != prev ) { // nextがdfsで訪問済みならば,
      //すなわちcurrent->next がback-edgeの場合,
      lowest[current] = min( lowest[current], prenum[next] );
    }
  }

}


void art_points() {
  REP0( i, V ) visited[i] = false;
  timer = 1;
  dfs( 0, -1 ); // 0:root

  set<int> ap;
  int np = 0;
  for (int i = 1; i < V; i++) {
    int p = parent[i];
    if ( p == 0 ) np++; // np:rootの子の数
    else if ( prenum[p] <= lowest[i] ) ap.insert(p);
    // prenum[p] : 頂点 i の親 p のdfs訪問順
    // lowest[i] :  min( i のdfs訪問順, dfs外の枝で接続する頂点の訪問順, dfs木における i の子すべてのlowest )
    // すなわち, dfsでの訪問が, dfs外の枝も含めた訪問順より速いかどうか？
  }
  if ( np > 1 ) ap.insert(0);

  for ( set<int>::iterator it = ap.begin(); it != ap.end(); it++ ) {
    std::cout << *it << '\n';
  }
}


int main(int argc, char const *argv[]) {
  input();
  art_points();
  return 0;
}
