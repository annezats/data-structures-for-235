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


int array1[]= {33,8,25,51,47,9,13,11};//doesnt work with lowest value sometimes?
//7,13,22,51,76,1
int SIZE = 8;

void siftup(int array1[], int n);

void printarray(int array1[]){
  std::cout<< "array1: [";
  for (int n=0; n<SIZE; n++){
    std::cout<<array1[n]<<",";
  }
  std::cout << "]"<< std::endl;
}

void makeheap (int array1[], int size){ //to make this insert, first insert each number but dont need cause already have array
  for (int n=1; n<size; n++){
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
    //std::cout<< n;
    n = (n-1)/2; //move index up to parentindex
    mynode = array1[n];
    parent = array1[(n-1)/2];
    //printarray (array1);
  }
}

void removemin(int array1[], int size){
  int root = array1[0]; int n=0;
  int last = array1[size-1];
  array1[size-1]= root;
  array1[0] = last;
  //make smaller array
  //printarray(array1);
  makeheap(array1, size-1);
  //find smallest righest child and siftup()
    //stick root into end
    //OR just switch root with last value and do makeheap?
    /*while ( (2*n+2) < size){
      array1[n] = rightchild; //stick myvalue into parentnode
      array1[2*n+2] = root; //stick parentvalue into mynode
      std::cout<< n;
      n = 2*n+2; //move index up to parentindex
      rightchild = array1[n];
      root = array1[2*n+2];
      printarray (array1);*
    }*/
    //array1[SIZE-1]=0; //this command removes the min that is now the last value in the heap
    //return root;
}

void heapsort(int array1[]){
  for (int size = SIZE; size >0; size --){
   removemin(array1, size);
  }
}

int main(){
  printarray(array1);
  makeheap(array1, SIZE);
  std::cout<< std::endl<< "made into heap: ";
  printarray(array1);

  heapsort(array1);
  std::cout<< std::endl<< "sorted the heap: ";
  printarray(array1);
  return 0;
}
