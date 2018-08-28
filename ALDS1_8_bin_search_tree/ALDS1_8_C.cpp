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
typedef long long ll;
using namespace std;

struct Node{
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;


void insert(int num){
  Node *y = NIL;
  Node *x = root; //start
  Node *z;

  z = (Node *)malloc(sizeof(Node));
  z->key = num;
  z->left = NIL;
  z->right = NIL;

  while ( x!=NIL ) {
    y=x; //おや
    if ( z->key < x->key ) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y==NIL) { //最初
    root = z;
  }else{
    if( z->key < y->key ){  //親より小さければ左につく
      y->left = z;
    }else{
      y->right = z;
    }
  }
}

void find(int num){
  Node *x = root;

  while ( x!=NIL ) {
    if (num < x->key) {
      x=x->left;
    } else if (num > x->key) {
      x=x->right;
    } else {
      std::cout << "yes" << '\n';
      return;
    }
  }
  std::cout << "no" << '\n';
  return;
}

Node *treeMinimum(Node *x){
  while (x->left != NIL) {
    x=x->left;
  }
  return x;
}


Node *treeSuccessor(Node *x){
  if (x->right!=NIL) {
    return treeMinimum(x->right);
  }
  Node *y = x->parent;
  while (y!=NIL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}


void treeDelete(int num){
  Node *y = root;
  while ( y!=NIL ) {
    if (num < y->key) {
      y=y->left;
    } else if (num > y->key) {
      y=y->right;
    } else if(num==y->key){
      break;
    }
  }
    Node *Deletee;
    Node *cldOfDeletee;

    if ( y->left==NIL || y->right==NIL ) Deletee = y;
    else Deletee = treeSuccessor(y);

    if (Deletee->left != NIL) {
      cldOfDeletee = Deletee->left;
    } else {
      cldOfDeletee = Deletee->right;
    }

    if (cldOfDeletee != NIL) {
      cldOfDeletee->parent = Deletee->parent;
    }

    if (Deletee->parent == NIL) {
      root = cldOfDeletee;
    }else{
      if (Deletee==Deletee->parent->left) {
        Deletee->parent->left = cldOfDeletee;
      }else{
        Deletee->parent->right = cldOfDeletee;
      }
    }

    if (Deletee!=y) {
      y->key = Deletee->key;
    }
    free(Deletee);
  

}


void print_in(Node *u){
  if(u==NIL) return;
  print_in(u->left);
  std::cout << " " << u->key;
  print_in(u->right);
}


void print_pre(Node *u){
  if(u==NIL) return;
  std::cout << " " << u->key;
  print_pre(u->left);
  print_pre(u->right);
}


int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int k, num; std::cin >> k;
  string command;
  for (size_t i = 0; i < k; i++) {
    std::cin >> command;
    if (command=="insert") {
      std::cin >> num;
      insert(num);
    } else if (command=="print"){
      print_in(root);
      std::cout << '\n';
      print_pre(root);
      std::cout << '\n';
    } else if (command=="find"){
      std::cin >> num;
      find(num);
    } else if (command=="delete"){
      std::cin >> num;
      treeDelete(num);
    }
  }

  return 0;
}
