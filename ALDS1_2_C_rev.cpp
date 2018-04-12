#include <iostream>
#include <algorithm>

//構造体を使ってみる
struct Card{ char suit, value; };

void printArray(struct Card A[], int N){
  for (int i = 0; i < N; i++) {
    std::cout << A[i].suit << A[i].value;
    if (i!=N-1) {
      std::cout << " ";
    }
  }
  std::cout <<'\n';
}


struct Card* bubbleSort(struct Card A[], int n){
  int flag=1;
  int cnt=0;
  int sorted_i=0;
  while (flag) {
    flag=0;
    for (int i = n-1; i > sorted_i; i--) {
      if(A[i-1].value > A[i].value){
        std::swap(A[i-1], A[i]);
        cnt++;
        flag=1;
      }
    }
    sorted_i++;
  }
  return A;
}


struct Card* selectionSort(struct Card A[], int n){
  int min_j;
  int cnt=0;
  for (int i = 0; i < n; i++) {
    min_j = i;
    for (int j = i; j < n; j++) {
      if (A[j].value < A[min_j].value) {
        min_j = j;
      }
    }
    if(i!=min_j){
      std::swap(A[min_j], A[i]);
      cnt++;
    }
  }
  return A;
}

bool isStable(struct Card A[], struct Card B[], int n){
  for (int i = 0; i < n; i++) {
    if (A[i].suit != B[i].suit) {
      return false;
    }
  }
  return true;
}

int main(void){
  int n;
  std::cin >> n;
  Card* A = new Card[n];
  Card* B = new Card[n];

  for (int i = 0; i < n; i++) {
    std::cin >> A[i].suit >> A[i].value;
    B[i] = A[i];
  }

  A = bubbleSort(A,n);
  printArray(A,n);
  std::cout << "Stable" << '\n';

  B = selectionSort(B,n);
  printArray(B,n);


  if(isStable(A,B,n)){
    std::cout << "Stable" << '\n';
  }else{
    std::cout << "Not stable" << '\n';
  }


  return 0;
}
