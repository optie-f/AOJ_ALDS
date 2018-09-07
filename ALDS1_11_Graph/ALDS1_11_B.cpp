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
#define N 100

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

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int M[N][N];
int n, tt, d[N], f[N];
int color[N]; //-1:unvisited, 0:visited, 1:finished
int nt[N];

#define WHITE 0
#define GRAY 1
#define BLACK 2


int next(int u){
  FOR(v, nt[u], n){
    nt[u]=v+1;
    if (M[u][v]) return v; // where v is first next_to_u
  }
  return -1;
}


void dfs_visit(int r){
  REP0(i,n) nt[i]=0;

  stack<int> S;
  S.push(r);
  color[r] = GRAY;
  d[r] = ++tt;

  while (!S.empty()) {
    int u=S.top();
    int v=next(u);
    if (v!=-1) {
      if (color[v]==WHITE) {
        color[v]=GRAY;
        d[v]=++tt;
        S.push(v);  //次のループで取り出されるu
      }
    }else{ //隣接未探索なし
      S.pop();
      color[u]=BLACK;
      f[u]=++tt;
    }
  }

}


void dfs(){
  REP0(i,n){
    color[i]=WHITE;
    nt[i]=0;
  }
  tt=0;
  REP0(i,n) if (color[i]==WHITE) dfs_visit(i);
  REP0(i,n) std::cout << i+1 << " " << d[i] << " " << f[i] << '\n';
}


void input(int n){
  int v1, v2, d;
  REP0(i,n) { REP0(j,n) M[i][j]=0; }
  REP0(i,n){
    std::cin >> v1 >> d;
    color[v1-1]=-1;
    REP0(j,d){
      std::cin >> v2; M[v1-1][v2-1]=1;
    }
  }
}


int main(int argc, char const *argv[]) {
  cin.tie(0); ios::sync_with_stdio(false);
  std::cin >> n;
  input(n);
  dfs();
  return 0;
}
