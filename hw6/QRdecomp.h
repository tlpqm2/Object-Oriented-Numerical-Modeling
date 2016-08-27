//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : QR DECOMPOSITION HEADER containing template QRdecomp algorithm class

#ifndef QRDECOMP_H
#define QRDECOMP_H

#include <stdexcept>

template <class T>
class QRdecomp
{
  private:
    Dense_Matrix<T> m_Q; 
    Dense_Matrix<T> m_R;
  public:
    //Default constructor
    QRdecomp(const int size);
    //QR overloaded function resolution function
    void operator()(const Dense_Matrix<T>& A);

    //Accessors for Q and R
    const Dense_Matrix<T> getQ() const;
    const Dense_Matrix<T> getR() const;
};

#include "QRdecomp.hpp"
#endif