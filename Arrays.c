#include <stdio.h>
// Function declarations
// Function to traverse array
void traverseArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);    }
    printf("\n");}
// Function to search item in array using binary search
int binarySearch(int array[], int left, int right, int item) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (array[mid] == item) {
            return mid;        }
        if (array[mid] > item) {
            return binarySearch(array, left, mid - 1, item);        }
        return binarySearch(array, mid + 1, right, item);    }
    return -1;}
// Function to insert item in array
void insertItem(int array[], int *size, int item) {
    array[*size] = item;
    (*size)++;}
// Function to delete item in array
void deleteItem(int array[], int *size, int item) {
    int index = binarySearch(array,0,10,item);
    if (index != -1) {
        for (int i = index; i < *size - 1; i++) { 
                       array[i] = array[i + 1];
                             }     
                                (*size)--;  
                                }}
// Function to sort array using bubble sort
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];         
               array[j] = array[j + 1];
                array[j + 1] = temp;            }        }    }}
// Function to sort array using insertion sort
void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
       while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;        }
        array[j + 1] = key;  }}


// Function to sort array using selection sort
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;            }        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;    }}
void print(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);    }
    printf("\n");
}
int main(){
  int array[]={1,2,3,4,5,6,7,8,9,10}; 
  int array1[]={11,2,3,4,55,6,17,8,79,10}; 
  int size=10;
  int item=7;  int left=0;  int right=size-1;  
  traverseArray(array,size);
  int printno2=binarySearch(array,left,right,item);  
  printf("\n%d\n",printno2);
  insertItem(array1,&size,1);  
  print(array1,size);
  deleteItem(array,&size,item);  
  print(array,size-1);
  bubbleSort(array1,size);  
  printf("bubble sort\n");  
  print(array1,size); 
 printf("insertion sort\n");  
 insertionSort(array1,size);  
 print(array1,size);
  printf("selection sort\n");  
  selectionSort(array1,size);  
  print(array1,size);
  return 0;
}