#include <utility>
#include <cstdio>
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
typedef long long ll;
using namespace std;
#define MAX 27
#define NIL -1


struct Node {int parent, left, right; };
Node node[MAX];
int D[MAX];
int H[MAX];
int n;

void initNode(){
  for (size_t i = 0; i < n; i++) {
    node[i].parent = node[i].left = node[i].right = NIL;
    H[i]=0;
  }
}


void inputNode(){
  int id, l, r;
  for (size_t i = 0; i < n; i++) {
    std::cin >> id >> l >> r;
    node[id].left = l;
    node[id].right = r;
    if (l!=NIL) node[l].parent=id;
    if (r!=NIL) node[r].parent=id;
    }
}

void recDepth(int id, int depth){
    D[id]=depth;
    if (node[id].left!=NIL) {
      recDepth(node[id].left, depth+1);
    }
    if(node[id].right!=NIL) {
      recDepth(node[id].right, depth+1);
    }

}

void recHeight(int id, int idrec, int height){
  H[id] = max(H[id], height);
  if (node[idrec].left!=NIL) {
    recHeight(id, node[idrec].left, height+1);
  }
  if(node[idrec].right!=NIL) {
    recHeight(id, node[idrec].right, height+1);
  }
}



void printNode(int id) {
  int parent = node[id].parent;
  int sibiling = NIL;
  int depth = D[id];

  if (parent!=NIL && node[parent].left!=NIL && node[parent].right!=NIL) {
    if (node[parent].left==id) {
      sibiling = node[parent].right;
    }else{
      sibiling = node[parent].left;
    }
  }


  int degree = 0;
  degree += (node[id].left!=NIL) + (node[id].right!=NIL);

  recHeight(id,id,0);
  int height = H[id];

  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",id,parent,sibiling,degree,depth,height);

  if (parent==NIL) {
    std::cout << "root" << '\n';
  }else if(degree!=0){
    std::cout << "internal node" << '\n';
  }else{
    std::cout << "leaf" << '\n';
  }
}


int main(int argc, char const *argv[]) {
  std::cin >> n;
  initNode();
  inputNode();
  int root;
  for (size_t i = 0; i < n; i++) {
    if (node[i].parent==NIL) {
      root=i;
    }
  }
  recDepth(root, 0);
  for (size_t i = 0; i < n; i++) {
    printNode(i);
  }
  return 0;
}
