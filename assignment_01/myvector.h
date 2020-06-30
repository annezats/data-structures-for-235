#include <iostream>

template <typename Type_any>
class myVector{
public:
  myVector();
  void resize();
  int get_size();
  Type_any& operator[] (int index);

private:
  int size;
  Type_any* main; //my pointer to my main array
  Type_any* temp;
};

template <typename Type_any>
myVector<typename Type_any>::myVector();

template <typename Type_any>
void myVector::resize();

template <typename Type_any>
int myVector::get_size();

template <typename Type_any>
Type_any& myVector::operator[] (int index);
