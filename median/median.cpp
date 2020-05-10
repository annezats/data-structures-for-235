/*     */

#include <iostream>


int array1[]= {33,8,25,51,47,9,13,11};//doesnt work with lowest value sometimes?
//7,13,22,51,76,1
int SIZE = 8;

void printarray(int array1[], std::string name){
  std::cout<< name << ": [";
  for (int n=0; n<SIZE; n++){
    std::cout<<array1[n]<<",";
  }
  std::cout << "]"<< std::endl;
}

void printDUBarray(double array1[], std::string name){
  std::cout<< name << ": [";
  for (int n=0; n<SIZE; n++){
    std::cout<<array1[n]<<",";
  }
  std::cout << "]"<< std::endl;
}

void siftupmin(int array1[], int n){//for min heap
  int parent = array1[(n-1)/2];
  int mynode = array1[n];
  while (n>=0 && mynode < parent){//if child is smaller than parent
    array1[(n-1)/2] = mynode; //stick myvalue into parentnode
    array1[n] = parent; //stick parentvalue into mynode    //std::cout<< n;
    n = (n-1)/2; //move index up to parentindex
    mynode = array1[n];
    parent = array1[(n-1)/2];
  }
}

void siftupmax(int array1[], int n){//for min heap
  int parent = array1[(n-1)/2];
  int mynode = array1[n];
  while (n>=0 && mynode > parent){//if child is smaller than parent
    array1[(n-1)/2] = mynode; //stick myvalue into parentnode
    array1[n] = parent; //stick parentvalue into mynode    //std::cout<< n;
    n = (n-1)/2; //move index up to parentindex
    mynode = array1[n];
    parent = array1[(n-1)/2];
  }
}

void insertmin(int array1[], int & size, int data){ //to make this insert, first insert each number but dont need cause already have array
  array1[size]= data;//adds data to end of array
  siftupmin(array1, size);//sifts it up
  size ++;
}

void insertmax(int array1[], int & size, int data){ //to make this insert, first insert each number but dont need cause already have array
  array1[size]= data;//adds data to end of array
  siftupmax(array1, size);//sifts it up
  size ++;
}

int removemin(int array1[], int &size){
  size = size-1;
  int root = array1[0];
  int last = array1[size];//sticks last value into last
  array1[size]= 0; //empties out last place
  array1[0] = last; //sticks last into root
  for (int n=1; n<size; n++){
    siftupmin(array1, n); //sifts up to fix heap
  }
  return root;
}

int removemax(int array1[], int &size){
  size = size-1;
  int root = array1[0];
  int last = array1[size];//sticks last value into last
  array1[size]= 0; //empties out last place
  array1[0] = last; //sticks last into root
  for (int n=1; n<size; n++){
    siftupmax(array1, n); //sifts up to fix heap
  }
  return root;
}

int main(){
  int minheap[(SIZE/2)+1]; int maxheap[(SIZE/2)+1];
  int minheapsize = 0; int maxheapsize = 0; int medianarraysize =0;
  double medianarray[SIZE]; int number= 0;
  for (int i=0; i<SIZE; i++){
    // grab number from array1
    number = array1[i];
    //stick it either into minarray or maxarray
    //update sizes of arrays
    if (number< maxheap[0]){
      insertmax(maxheap, maxheapsize, number);
    }
    else insertmin(minheap, minheapsize, number);
    //find median and stick it into medianarray
    int c = minheapsize - maxheapsize;
    switch(c){
      case 0: //equal heaps
        medianarray[medianarraysize] = ((double)minheap[0]+maxheap[0])/2;
        medianarraysize ++; break;
      case 1: //minheap is bigger
        medianarray[medianarraysize] = minheap[0];
        medianarraysize ++; break;
      case -1: //maxheap is bigger
        medianarray[medianarraysize] = maxheap[0];
        medianarraysize ++; break;
      case 2: //minheap is two bigger, have to removemin and insert to maxheap
        number = removemin(minheap, minheapsize);
        insertmax(maxheap, maxheapsize, number);
        medianarray[medianarraysize] = ((double)minheap[0]+maxheap[0])/2;
        medianarraysize ++; break;
      case -2://maxheap is two bigger
        number = removemax(maxheap, maxheapsize);
        insertmin(minheap, minheapsize, number);
        medianarray[medianarraysize] = ((double)minheap[0]+maxheap[0])/2;
        medianarraysize ++; break;
    }
  }
  printarray(array1, "array1");
  printarray(maxheap, "maxheap");
  printarray(minheap, "minheap");
  printDUBarray(medianarray, "median array");
  return 0;
}
