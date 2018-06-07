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


void bubbleSort(int* A, int n){
  int flag=1;
  int cnt=0;
  int sorted_i=0;
  while (flag) {
    flag=0;
    for (int i = n-1; i > sorted_i; i--) {
      if(A[i-1] > A[i]){
        std::swap(A[i-1], A[i]);
        cnt++;
        flag=1;
      }
    }
    sorted_i++;
  }
  printArray(A,n);
  std::cout << cnt << '\n';
}


int main() {
  int n;
  std::cin >> n;
  int* A = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }
  bubbleSort(A,n);
  return 0;
}
