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

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int CalcLCS(string X, string Y){
  int c[1001][1001];
  int m = SZ(X);
  int n = SZ(Y);
  int mlen=0;
  X = ' ' + X;
  Y = ' ' + Y;

  REP1(i,m) c[i][0]=0;

  REP1(j,n) c[0][j]=0;
  
  REP1(i,m){
    REP1(j,n){
      if (X[i]==Y[j]) {
        c[i][j] = c[i-1][j-1] + 1;
      } else {
        c[i][j] = max(c[i-1][j], c[i][j-1]);
      }
      mlen=max(mlen, c[i][j]);
    }
  }
  return mlen;
}


int main(int argc, char const *argv[]) {
  int q; std::cin >> q;
  string X,Y;

  REP0(i,q){
    std::cin >> X >> Y;
    std::cout << CalcLCS(X,Y) << '\n';
  }

  return 0;
}
