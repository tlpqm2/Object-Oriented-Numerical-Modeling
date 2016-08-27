//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : DENSE-GAUSSIAN ELIMINATION FUNCTOR containing Gaussian algorithm with partial pivoting

#ifndef DENSE_GAUSS_H
#define DENSE_GAUSS_H

#include <stdexcept>

template<class T>
class Dense_Gauss
{
    public:
    //Overloaded function resolution operator
    void operator()(Dense_Matrix<T>& source);
};

#include "Dense_Gauss.hpp"
#endif
