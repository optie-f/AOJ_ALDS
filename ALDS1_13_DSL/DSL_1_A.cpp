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

struct init{
    init(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
} init;

class DisjointSet {
  public:
    VI rank; // height of tree
    VI p; // parent of each node

    DisjointSet(int size) {
      rank.resize(size, 0);
      p.resize(size, 0);
      REP0(i,size) makeSet(i);
    }

    void makeSet(int x){ // x の単元集合
      p[x] = x;
      rank[x] = 0;
    }

    bool same(int x, int y){
      return findSet(x) == findSet(y);
    }

    void unite(int x, int y){
      link(findSet(x), findSet(y));
    }

    void link(int x, int y){  // root同士であることを前提に, 親の挿げ替え
      if ( rank[x] > rank[y] ) {
        p[y] = x; // set y's parent to x
      }else{
        p[x] = y;
        if (rank[x] == rank[y] ){
          rank[y]++;
        }
      }
    }

    int findSet(int x){ // root's parent is itself
      if ( x != p[x] ){ // recursively get root of tree including x
        p[x] = findSet(p[x]);
      }
      return p[x];
    }
};


int main(int argc, char const *argv[]) {
  int n, q;
  std::cin >> n >> q;
  DisjointSet ds = DisjointSet(n);
  REP0(i,q){
    int com, x, y;
    std::cin >> com >> x >> y;
    if ( com == 0 ) ds.unite(x, y);
    else if( com == 1 ){
      std::cout << ds.same(x, y) << '\n';
    }
  }

  return 0;
}
