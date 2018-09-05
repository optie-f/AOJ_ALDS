#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
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

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

static const int N = 100;



int main(int argc, char const *argv[]) {
  cin.tie(0); ios::sync_with_stdio(false);
  int n;
  int p[N+1]; //M_i が p[i-1]行 p[i]列 となる
  int m[N+1][N+1]; //M_i ~ M_jまでをかけあわせたときの最小の掛け算の数
  std::cin >> n;
  REP1(i,n) std::cin >> p[i-1] >> p[i];
  REP1(i,n) m[i][i]=0;

  FOR(l, 2, n){
    REP1(i, n-l+1){
      int j = i+l-1;
      m[i][j] = INTINF;
      FOR(k, i, j-1){
        m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
      }
    }
  }

  std::cout << m[1][n] << '\n';

  return 0;
}
