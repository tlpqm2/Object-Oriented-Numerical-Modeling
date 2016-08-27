//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : MATRIX ABSTRACT BASE CLASS for interfacing common matrix functionality

#ifndef AMATRIX_H
#define AMATRIX_H

#include <cmath>
#include <utility>
#include <stdexcept>
#include "Vector.h"

//Forward declaration of class
template <class T>
class AMatrix;

//THE ABC class matrix class class
template <class T>
class AMatrix
{
  private:
    int m_size;
    Vector<T> m_augment;
  public:
    //Pure virtual overloaded operators
    virtual const Vector<T> operator*(const Vector<T>& rhs) const = 0;
    virtual const Vector<T> operator[](const int index) const = 0;
    virtual void MatrixTest(const Vector<T>& testvector) = 0;
};

#endif