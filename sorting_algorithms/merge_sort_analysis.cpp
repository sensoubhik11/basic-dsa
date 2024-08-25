#include<iostream>

/**
Name : Soubhik Sen
Program : Analysing merge sort
*/
int N = 0;
int COUNT_MERGE_CALLS = 0;
int COUNT_COMPARISONS=0;
int SUM = 0;
int MAX_LEVEL = 0;
int COUNT_LEVEL_COMPARISONS[100]={0};
void print(int[], int);

void merge(int a[], int l, int m, int h, int level) {  
  COUNT_MERGE_CALLS++;
  //finding size of left and right halves
  int n1 = m-l+1;
  int n2 = h-m;
  
  //creating two temporary arrays to store left[l..m] and right[m+1..h] halves
  int left[n1], right[n2];
  for(int i=0; i<n1; i++) left[i] = a[l+i];
  for(int j=0; j<n2; j++) right[j] = a[m+1+j];
  
  std::cout << "\nBefore Merge:\n";
  print(a,N);
  // std::cout << "\nMerging left half a[" << l << ".." << m << "] and right half a[" << m+1 << ".." << h << "]\n\n";
  //now the actual merge will start
  //we will compare the elements of left and right halves
  //and put the minimum of the two in our actual array a[l..h]
  COUNT_COMPARISONS=0;
  int i=0, j=0, k=l;
  while(i<n1 && j<n2) {
    if(left[i] <= right[j]) {
      a[k] = left[i];
      i++;
    }
    else {
      a[k] = right[j];
      j++;
    }
    k++;
    COUNT_COMPARISONS++;
  }
  
  //if some elements are still there in any of left or right half
  while(i<n1) {
    a[k] = left[i];
    k++, i++;
    COUNT_COMPARISONS++;
  }
  while(j<n2) {
    a[k] = right[j];
    k++, j++;
    COUNT_COMPARISONS++;
  }
  
  std::cout << "After Merging:\n";
  print(a,N);
  std::cout << "\nNumber of comparisons made in this merging at level " << level <<": "<< COUNT_COMPARISONS << "\n";
  std::cout << "\n-------------------------------------------------\n";
  
  SUM += COUNT_COMPARISONS;
  MAX_LEVEL = std::max(MAX_LEVEL, level);
  COUNT_LEVEL_COMPARISONS[level] += COUNT_COMPARISONS;
}

void mergeSort(int a[], int low, int high, int level) {
  if(low < high) {
    int mid = low + (high-low)/2;
    mergeSort(a, low, mid, ++level);
    --level;
    mergeSort(a, mid+1, high, ++level);
    merge(a, low, mid, high, level);
  }
}

void print(int a[], int n) {
  for(int i=0; i<n; i++) std::cout << a[i] << " ";
  std::cout << "\n";
}

int main() {

  std::cout << "Enter number of elements: ";
  std::cin >> N;
 
  int a[N];
  for(int i=0; i<N; i++) {
    std::cout << "a[" << i << "]=";
    std::cin>>a[i];
  }

  std::cout << "Unsorted array is:\n";
  print(a, N);
 
 
  std::cout << "Merge Sorting the array...\n";
  std::cout << "\n-------------------------------------------------\n";
  
  mergeSort(a,0,N-1,0);
 
  std::cout << "\nSorted Array is:\n";
  print(a, N);
  
  std::cout << "\nNumber of times merge function was called: " << COUNT_MERGE_CALLS << "\n";
  std::cout << "Number of levels reached in recursion tree: " << MAX_LEVEL << "\n";
  for(int i=1; i<=MAX_LEVEL; i++) {
    std::cout << "Number of comparisons made in level " << i << ": " << COUNT_LEVEL_COMPARISONS[i] << "\n";
  }
  std::cout << "Total no of comparisons made: " << SUM << "\n";
  
  
  return 0;
}
