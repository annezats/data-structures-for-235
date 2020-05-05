/* Basically, you are to implement a heapsort.
Start with an array of random values.
Convert it into a heap as outlined in class. To review,
  start with a[1] and sift up then a[2] etc until you're done.
Repeatedly remove-min and recreate the heap until sorted.
When you do the removemin, rather than truly removing the root element
  and replacing it with the lowest rightest leaf you swap the root
  with that value and decrease your heap size by one. This results in
  you sorting the array in place. */

#include <iostream>

int array1[]= {33,8,9,51,47,25};//doesnt work with lowest value sometimes?
//7,13,22,51,76,1
int SIZE = 6;

void siftup(int array1[], int n);

void makeheap (int array1[]){ //to make this insert, first insert each number but dont need cause already have array
  for (int n=1; n<SIZE; n++){
    siftup(array1, n);
  }
}

void siftup(int array1[], int n){
  int parent = array1[(n-1)/2];
  int mynode = array1[n];
  //if (mynode > parent) return 0;
  while (n>=0 && mynode < parent){//if child is smaller than parent
    array1[(n-1)/2] = mynode; //stick myvalue into parentnode
    array1[n] = parent; //stick parentvalue into mynode
    n = (n-1)/2; //move index up to parentindex
    mynode = parent;
    parent = array1[(n-1)/2];
  }
}

void removemin(int array1[], int size){
  int root = array1[0]; int n=0;
  int rightchild = array1[(2*n+2)];
  while ( (2*n+2) < size){
    array1[n] = rightchild; //stick myvalue into parentnode
    array1[2*n+2] = root; //stick parentvalue into mynode
    n = 2*n+2; //move index up to parentindex
    rightchild = root;
    root = array1[2*n+2];
  }
  //array1[SIZE-1]=0; //this command removes the min that is now the last value in the heap
  //return root;
}

void heapsort(int array1[]){
  int size = SIZE;
  for (int n=0; n< SIZE; n++){
   removemin(array1, size);
   size--;
  }
}

int main(){
  for (int n=0; n<SIZE; n++){
    std::cout<<array1[n]<<",";
  }
  makeheap(array1);
  std::cout<< std::endl<< "made into heap: ";
  for (int n=0; n<SIZE; n++){
    std::cout<<array1[n]<<",";
  }
  heapsort(array1);
  std::cout<< std::endl<< "sorted the heap: ";
  for (int n=0; n<SIZE; n++){
    std::cout<<array1[n]<<",";
  }
  return 0;
}
