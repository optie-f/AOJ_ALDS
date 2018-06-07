#include <iostream>
#include <algorithm>

void printArray(std::string A[], int N){
  for (int i = 0; i < N; i++) {
    std::cout << A[i];
    if (i!=N-1) {
      std::cout << " ";
    }
  }
  std::cout <<'\n';
}


std::string* bubbleSort(std::string A[], int n){
  int flag=1;
  int cnt=0;
  int sorted_i=0;
  while (flag) {
    flag=0;
    for (int i = n-1; i > sorted_i; i--) {
      if(A[i-1][1] > A[i][1]){
        std::swap(A[i-1], A[i]);
        cnt++;
        flag=1;
      }
    }
    sorted_i++;
  }
  return A;
}


std::string* selectionSort(std::string A[], int n){
  int min_j;
  int cnt=0;
  for (int i = 0; i < n; i++) {
    min_j = i;
    for (int j = i; j < n; j++) {
      if (A[j][1] < A[min_j][1]) {
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


int main(void){
  int n;
  std::cin >> n;

  std::string* A = new std::string[n];
  std::string* B = new std::string[n];
  std::string* C = new std::string[n];

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
    B[i] = A[i];
    C[i] = A[i];
  }

  B = bubbleSort(B,n);
  printArray(B,n);
  std::cout << "Stable" << '\n';

  C = selectionSort(C,n);
  printArray(C,n);

  for (int i = 0; i < n; i++) {
    if(B[i]!=C[i]){
      std::cout << "Not stable" << '\n';
      return 0;
    }
  }
  std::cout << "Stable" << '\n';

  return 0;
}
