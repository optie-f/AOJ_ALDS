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

class Node{
public:
  int location;
  int p, l, r;
  Node() {}
};


class Point {
public:
  int id, x, y;
  Point() {}
  Point(int id, int x, int y): id(id), x(x), y(y) {}
  bool operator < (const Point &p) const {
    return id < p.id;
  }
  void print(){
    printf("%d\n", id);
  }
};

static const int MAX = 1000000;
static const int NIL = -1;

int N;
Point P[MAX];
Node T[MAX];
int np;

bool lessX(const Point &p1, const Point&p2) {return p1.x < p2.x; }
bool lessY(const Point &p1, const Point&p2) {return p1.y < p2.y; }


void input() {
  scanf("%d", &N);
  int x, y;
  REP0(i,N){
    scanf("%d %d", &x, &y);
    P[i] = Point(i, x, y);
    T[i].l = T[i].r = T[i].p = NIL;
  }
}


int makeKDTree(int l, int r, int depth){
  if( !(l<r) ) return NIL;
  int mid = (l+r)/2;
  int t = np++;

  if( depth%2==0 ){
    sort(P+l, P+r, lessX);
  }else{
    sort(P+l, P+r, lessY);
  }

  T[t].location = mid;
  T[t].l = makeKDTree(l, mid, depth+1);
  T[t].r = makeKDTree(mid+1, r, depth+1);

  return t; // index of bintree node
}


void find(int v, int sx, int tx, int sy, int ty, int depth, std::vector<Point> &ans){
  int x = P[T[v].location].x;
  int y = P[T[v].location].y;

  if (sx <= x && x <= tx && sy <= y && y <= ty) {
    ans.push_back(P[T[v].location]);
  }

  if (depth%2==0) {
    if (T[v].l != NIL) {
      if(sx <= x) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
    }
    if (T[v].r != NIL) {
      if(x <= tx) find(T[v].r, sx, tx, sy, ty, depth+1, ans);
    }
  }else{
    if (T[v].l != NIL) {
      if(sy <= y) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
    }
    if (T[v].r != NIL) {
      if(y <= ty) find(T[v].r, sx, tx, sy, ty, depth+1, ans);
    }

  }
}


void solve(){
  np = 0;
  int root = makeKDTree(0, N, 0);

  int q;
  scanf("%d", &q);
  int sx, tx, sy, ty;
  std::vector<Point> ans;
  int s;

  REP0(i,q){
    scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    ans.clear();
    find(root, sx, tx, sy, ty, 0, ans);
    SORT(ans);
    s = ans.size();
    REP0(j, s){
      ans[j].print();
    }
    printf("\n");
  }
}


int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
