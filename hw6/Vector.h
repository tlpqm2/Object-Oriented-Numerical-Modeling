//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : VECTOR HEADER containing template Vector class

#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <utility>
#include <stdexcept>

//Forward declaration of class
template <class T>
class Vector;

//Forward declaration of templated friend functions

//PreCondition  : Type T needs assignment(=) and multiplication(*) operators defined
//PostCondition : Returns a copy of the resultant Vector after scalar multiplication
//Description   : SCALAR MULTIPLICATION implemented as a friend function to allow for x*Vector and Vector*x
template <typename T>
Vector<T> operator* (const T& x, const Vector<T>& rhs);

template <typename T>
std::ostream& operator<< (std::ostream& out, const Vector<T>& rhs);

template <typename T>
std::istream& operator>> (std::istream& in, const Vector<T>& rhs);

//Global constant for a default size of a Vector
const int DEFAULT_SIZE = 20;

//THE class
template <class T>
class Vector
{
  private:
    T* m_data;
    int m_size;

  public:
    //Constructors and destructor
    Vector();
    Vector(const int setSize);
    Vector(const Vector<T>& rhs);
    Vector(Vector<T> && rhs): m_data(std::move(rhs.m_data)), m_size(rhs.m_size){rhs.m_data = nullptr; rhs.m_size = 0;};
    ~Vector();

    //Overloaded operators
    const Vector<T> operator+ (const Vector<T>& rhs) const;
    const Vector<T> operator- (const Vector<T>& rhs) const;
    const Vector<T> operator- () const;
    const T operator* (const Vector<T>& rhs) const;
    const Vector<T> operator* (const T& x) const;
    const T& operator[] (const int index) const;
    const Vector<T>& operator= (Vector<T> rhs);

    //Friend functions
    friend Vector<T> operator* (const T& x, const Vector<T>& rhs) {return rhs * x;};
    friend std::ostream& operator<< <T>(std::ostream& out, const Vector<T>& rhs);
    friend std::istream& operator>> <T>(std::istream& in, const Vector<T>& rhs);
    
    //Accessor and mutator functions
    int getSize() const;
    void setSize(const int size);
    void setElement(const T element, const int index);

    //2-Norm
    const T twoNorm() const;
};

#include "Vector.hpp"
#endif