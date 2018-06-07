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


int* insertionSort(int* A, int N){
  int tmp;

  for(int i=1; i<N; i++){
    tmp = A[i];
    int j = i-1;
    while (j>=0 && A[j]>tmp) {
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=tmp;
    printArray(A, N);
  }
  return A;
}


int main(){
  int n;
  std::cin >> n;
  int* A = new int[n];

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  printArray(A, N);
  A = insertionSort(A, n);

  return 0;

}
