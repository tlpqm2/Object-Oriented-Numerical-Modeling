//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : TRIDIAGONAL GAUSS ELIMINATION FUNCTOR containing Gaussian algorithm optimized for a Tridiagonal_Matrix

#ifndef TRIDIAGONAL_GAUSS_H
#define TRIDIAGONAL_GAUSS_H

#include <stdexcept>

template<class T>
class Tridiagonal_Gauss
{
    public:
    //Overloaded function resolution operator
    void operator()(Tridiagonal_Matrix<T>& source);
};

#include "Tridiagonal_Gauss.hpp"
#endif
