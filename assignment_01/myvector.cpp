
/*I dont understand how to implement templates. I understand how they work in theory,
as the concept is fairly straightforward, but  the compiler keeps yelling at me that everything
is either not declared or it doesn't like that it is declared as a template and not a member
and I don't know where to put my template declarations because I tried all the variations of
putting them places and it didn't work and google is not being helpful
*/
#include <iostream>
#include "myvector.h"

template <typename Type_any>
myVector<typename Type_any>::myVector(){
  size = 1;
  Type_any* main= new Type_any[size];//need number of values?? how to do without?
}

template <typename Type_any>
void myVector::resize(){
  template <typename Type_any>
  Type_any* temp= new Type_any[size+1];//starts temporary array
  for (int i=0; i<size; i++){
    temp[i]=main[i]; //copies old info from p to q
  }
  //q[size]=a;//adds new value to q //from old code
  size ++;
  //THE SWITCHEROO back to p
  delete[] main;//clears old stuff
  main= new Type_any[size];
  for (int i=0; i<size; i++){
    main[i]=temp[i]; //copies from temporary to regular
  }
  delete[] temp; //clears temporary
}

template <typename Type_any>
int myVector::get_size(){
  return size;
}

template <typename Type_any>
Type_any& myVector::operator[] (int index){
  if (index<size){
    return main[index];
  }
  else if (index==size){
    resize();
    return main[index];
  }
}
