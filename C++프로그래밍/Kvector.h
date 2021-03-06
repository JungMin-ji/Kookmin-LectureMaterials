#include <iostream>
#ifndef __KVECTOR__
#define __KVECTOR__

template <class T>
class Kvector{
protected:
  T *m;
  int len;
public:
  Kvector(int sz = 0, T value = 0);
  Kvector(const Kvector& v);
  T sum() const{
    T s;
    for(int i=0; i<len; i++) s+=m[i];
    return s;
  }
virtual ~Kvector();
virtual void print() const{std::cout << "Kvector\n"; }
  void clear(){delete[] m; m = NULL; len = 0;}
  int size() const {return len;}
Kvector& operator=(const Kvector& v);
friend bool operator==(const Kvector& v, const Kvector& w);
friend bool operator!=(const Kvector& v, const Kvector& w);
friend Kvector<T> operator+= (const T& t);
int& operator[](int idx){ return m[idx]; }
const int& operator[](int idx) const { return m[idx]; }
friend std::ostream& operator<<(std::ostream& os, const Kvector& v);
};
#include "Kvector.cpp"
#endif
