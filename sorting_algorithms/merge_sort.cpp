#include<iostream>

/**
Name : Soubhik Sen
Roll : 24MA4108
Algorithm Class Date: Aug 23, 2024
Assignment : Implement and demonstrate merge sort
*/

void merge(int a[], int l, int m, int h) {
  //finding size of left and right halves
  int n1 = m-l+1;
  int n2 = h-m;
  
  //creating two temporary arrays to store left[l..m] and right[m+1..h] halves
  int left[n1], right[n2];
  for(int i=0; i<n1; i++) left[i] = a[l+i];
  for(int j=0; j<n1; j++) right[j] = a[m+1+j];
  
  //now the actual merge will start
  //we will compare the elements of left and right halves
  //and put the min of the two in our actual array a[l..h]
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
  }
  
  //if some elements are still there in any of left or right half
  while(i<n1) {
    a[k] = left[i];
    k++, i++;
  }
  while(j<n2) {
    a[k] = right[j];
    k++, j++;
  }
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
  int n;
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
 
  std::cout << "Sorted Array is:\n";
  print(a, n);
 
  return 0;
}
