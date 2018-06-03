#include <utility>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MAX 100005
#define NIL -1
typedef long long ll;
using namespace std;

struct TreeNode { int parent, left_child, right_sibling; };
TreeNode T[MAX];
int n, D[MAX];


void initTree(){
  for (size_t i = 0; i < n; i++) {
    T[i].parent = T[i].left_child = T[i].right_sibling = NIL;
  }
}


void makeTree(){
  int id, deg, child_id, child;
  for (size_t i = 0; i < n; i++) {  //各idの子
    std::cin >> id >> deg;
    for (size_t j = 0; j < deg; j++) {
      std::cin >> child_id;
      if (j==0) T[id].left_child = child_id;  //初回はこれ,
      else T[child].right_sibling = child_id;  //2回目以降
      child = child_id;  //これで一番上の兄弟からたどる
      T[child].parent = id;
    }
  }
}


void recDepth(int id, int depth){
  D[id]=depth;
  if (T[id].right_sibling != NIL) {
    recDepth(T[id].right_sibling, depth);
  }
  if (T[id].left_child != NIL) {
    recDepth(T[id].left_child, depth+1);
  }
}

void printTreeNode(int id){
  printf("node %d: parent = %d, depth = %d, ",
                                  id, T[id].parent, D[id]);

  if (T[id].parent==NIL) {
    std::cout << "root, [";
  }else if(T[id].left_child==NIL){
    std::cout << "leaf, [";
  }else{
    std::cout << "internal node, [";
  }
  int leaf =  T[id].left_child;

  while (leaf!=NIL) {
    std::cout << leaf;
    leaf = T[leaf].right_sibling;
    if (leaf!=NIL) std::cout << ", ";
  }

  std::cout << "]" << '\n';
}


int main(int argc, char const *argv[]) {
  int root=0;
  cin >> n;

  initTree();
  makeTree();

  for (size_t i = 0; i < n; i++) {
    if (T[i].parent==NIL) root=i;
  }

  recDepth(root, 0);

  for (size_t i = 0; i < n; i++) {
    printTreeNode(i);
  }

  return 0;
}
