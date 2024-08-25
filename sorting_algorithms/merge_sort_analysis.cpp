#include<iostream>

/**
Name : Soubhik Sen
Roll : 24MA4108
Algorithm Class Date: Aug 23, 2024
Assignment : Implement and demonstrate merge sort
*/
int n = 0;
int COUNT_MERGE_CALLS = 0;
int COUNT_COMPARISONS[1000];
void print(int[], int);

void merge(int a[], int l, int m, int h) {  
  //finding size of left and right halves
  int n1 = m-l+1;
  int n2 = h-m;
  
  //creating two temporary arrays to store left[l..m] and right[m+1..h] halves
  int left[n1], right[n2];
  for(int i=0; i<n1; i++) left[i] = a[l+i];
  for(int j=0; j<n1; j++) right[j] = a[m+1+j];
  
  std::cout << "\nBefore Merge:\n";
  print(a,n);
  //now the actual merge will start
  //we will compare the elements of left and right halves
  //and put the minimum of the two in our actual array a[l..h]
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
    COUNT_COMPARISONS[COUNT_MERGE_CALLS]++;
  }
  
  //if some elements are still there in any of left or right half
  while(i<n1) {
    a[k] = left[i];
    k++, i++;
    COUNT_COMPARISONS[COUNT_MERGE_CALLS]++;
  }
  while(j<n2) {
    a[k] = right[j];
    k++, j++;
    COUNT_COMPARISONS[COUNT_MERGE_CALLS]++;
  }
  
  std::cout << "After Merge:\n";
  print(a,n);
  std::cout << "Number of comparisons made in this merging: " << COUNT_COMPARISONS[COUNT_MERGE_CALLS] << "\n";
  
  COUNT_MERGE_CALLS++;
}

void mergeSort(int a[], int low, int high) {
  if(low < high) {
    int mid = low + (high-low)/2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
  }
}

void print(int a[], int n) {
  for(int i=0; i<n; i++) std::cout << a[i] << " ";
  std::cout << "\n";
}

int main() {

  std::cout << "Enter number of elements: ";
  std::cin >> n;
 
  int a[n];
  for(int i=0; i<n; i++) {
    std::cout << "a[" << i << "]=";
    std::cin>>a[i];
  }

  std::cout << "Unsorted array is:\n";
  print(a, n);
 
 
  std::cout << "Merge Sorting the array...\n\n";
  mergeSort(a,0,n-1);
 
  std::cout << "\nSorted Array is:\n";
  print(a, n);
  
  std::cout << "\nNumber of times merge function was called: " << COUNT_MERGE_CALLS << "\n";
  
  int sum = 0;
  for(int i=0; i<COUNT_MERGE_CALLS; i++) {
    sum += COUNT_COMPARISONS[i];
    std::cout << "No of insertions(comparisons) made in original array in merge " << i+1 << ": " << COUNT_COMPARISONS[i] << "\n";
  }
  std::cout << "Total no of comparisons made: " << sum << "\n";
  return 0;
}
