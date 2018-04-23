#include <utility>
#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define nil 0


class hashTable{
private:
  int size;
  std::vector<long> v;
public:
  hashTable(long size_){size=size_; v.reserve(size_); v.resize(size_,0); };
  long h1(long x){ return x%size; };
  long h2(long x){ return 1 + x%(size-1); };
  long hash(long x, long i){ return (h1(x) + i*h2(x)) % size; };
  long str2long(string s);
  void insert(string s);
  bool search(string s);
  void prlongv();
};

void hashTable::insert(string s){
  long key = str2long(s);
  long i=0;
  while (1) {
    long j=hash(key, i);
    if (v[j]==0) {
      v[j]=key;
      break;
    }else{
      i++;
    }
  }
}

bool hashTable::search(string s){
  long key = str2long(s);
  long i=0;
  while (1) {
    long j=hash(key, i);
    if (v[j]==key) {
      return true;
    }else if (v[j]==0 || i>=size) {
      return false;
    }else{i++;}
    }
  }


long hashTable::str2long(string s){
  long val=0;
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i]=='A') val+= 1 * pow(10,i);
    else if (s[i]=='C') val+= 2 * pow(10,i);
    else if (s[i]=='G') val+= 3 * pow(10,i);
    else if (s[i]=='T') val+= 4 * pow(10,i);
    else val+= 5 * pow(10,i);
  }
  return val;
}

void hashTable::prlongv(){
  for (size_t i = 0; i < size; i++) {
    std::cout << i << ":"  << v[i] << ", ";
  }
  std::cout  << '\n';
}

int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; std::cin >> n;
  string s;
  hashTable h = hashTable(1000000);
  for (size_t i = 0; i < n; i++) {
    std::cin >> s;
    if (s=="insert") {
      std::cin >> s;
      h.insert(s);
    }else if (s=="find") {
      std::cin >> s;
      if (h.search(s)) {
        std::cout << "yes" << '\n';
      }else{
        std::cout << "no" << '\n';
      }
    }
  }

  return 0;
}
