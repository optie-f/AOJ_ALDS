#include <iostream>
#include <algorithm>

void printArray(int* A, int N){
  for (int i = 0; i < N; i++) {
    std::cout << A[i];
    if (i!=N-1) {
      std::cout << " ";
    }
  }
  std::cout <<'\n';
}


void selectionSort(int* A, int n){
  int min_j;
  for (int i = 0; i < n; i++) {
    min_j = i;
    for (int j = i; j < n; j++) {
      if (A[j] < A[min_j]) {
        min_j = j;
      }
    }
    std::swap(A[min_j], A[j]);
  }
  printArray(A,n);
}


int main() {
  int n;
  std::cin >> n;
  int* A = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }
  return 0;
}
