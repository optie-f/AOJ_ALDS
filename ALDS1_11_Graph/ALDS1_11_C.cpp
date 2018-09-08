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
#define N 100

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n, M[N][N], d[N];


void bfs(int s) {
  queue<int> Q;
  Q.push(s);
  REP0(i,n) d[i]=INTINF;
  d[s]=0;
  int u;
  while ( !Q.empty() ) {
    u = Q.front(); Q.pop();
    REP0(v,n){
      if (M[u][v]==0 || d[v]!=INTINF) continue; //disconnected or visited
      d[v] = d[u]+1;
      Q.push(v);
    }
  }
  REP0(i,n){
    std::cout << i+1 << " " << ( (d[i]==INTINF) ? (-1) : d[i] ) << '\n';
  }
}


void input(){
  std::cin >> n;
  int v1, v2, d;
  REP0(i,n) { REP0(j,n) M[i][j]=0; }
  REP0(i,n){
    std::cin >> v1 >> d;
    REP0(j,d){
      std::cin >> v2; M[v1-1][v2-1]=1;
    }
  }
}


int main(int argc, char const *argv[]) {
  cin.tie(0); ios::sync_with_stdio(false);
  input();
  bfs(0);
  return 0;
}
