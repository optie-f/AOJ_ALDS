#include <iostream>
#include <algorithm>
#include <vector>

long long cnt=0;

int* insertionSort(int* A, int N, int g){
  int tmp;

  for(int i=g; i<N; i++){
    tmp = A[i];
    int j = i-g;
    while (j>=0 && A[j]>tmp) {
      A[j+g]=A[j];
      j = j - g;
      cnt++;
    }
    A[j+g]=tmp;
  }
  return A;
}


void shellSort(int* A, int n){
  std::vector<int> G;
  for (int i = 0; i < n; i = 3*i+1) {
    G.push_back(i);
  }
  int m =  G.size();
  std::cout << m << '\n';
  for (int i = m-1; i >=0; i--) {
    std::cout << G[i];
    if (i!=m-1) {
      std::cout << " ";
    }else{
      std::cout << '\n';
    }
  }
  for (int i = m-1; i >=0; i--) {
    A = insertionSort(A,n,G[i]);
  }

  std::cout << cnt << '\n';

  for (size_t i = 0; i < n; i++) {
    std::cout << A[i] << '\n';
  }
}


int main(void) {
  int n;
  std::cin >> n;
  int* A = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  shellSort(A, n);

  return 0;
}
