//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : DIAGONAL MATRIX HEADER containing template Diagonal_Matrix class.
#ifndef DIAGONAL_MATRIX_H
#define DIAGONAL_MATRIX_H

#include <cmath>
#include <utility>
#include <stdexcept>
#include "AMatrix.h"
#include "Vector.h"

//Forward declaration of class
template <class T>
class Diagonal_Matrix;

//Forward declaration of templated friend functions
//Documentation for the following 2 friend functions
//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs Vector need matching sizes for Matrix-Vector multiplication.
//PostCondition : Returns a copy of the resultant multiplication.
//Description   : MATRIX-VECTOR AND MATRIX-SCALAR MULTIPLICATION implemented as friend functions to allow for
//                natural use of operators. i.e. 4*Matrix and Matrix*4 will both work; the same goes for Vectors.
template <typename T>
Diagonal_Matrix<T> operator* (const T& x, const Diagonal_Matrix<T>& rhs);

template <typename T>
Diagonal_Matrix<T> operator* (const Vector<T>& x, const Diagonal_Matrix<T>& rhs);

template <typename T>
std::ostream& operator<< (std::ostream& out, const Diagonal_Matrix<T>& rhs);

template <typename T>
std::istream& operator>> (std::istream& in, Diagonal_Matrix<T>& rhs);

//THE other class
template <class T>
class Diagonal_Matrix: public AMatrix<T>
{
  private:
    Vector<T> m_diagonal;
    int m_size;
    Vector<T> m_augment;
  public:
    //Constructors and destructor
    Diagonal_Matrix(const int setSize);
    Diagonal_Matrix(const Diagonal_Matrix<T>& rhs);
    Diagonal_Matrix(Diagonal_Matrix<T>&& rhs): m_diagonal(std::move(rhs.m_diagonal))
                                              ,m_size(rhs.m_size)
                                              ,m_augment(std::move(rhs.m_augment)) 
                                              {rhs.m_size = 0;};
    ~Diagonal_Matrix();

    //Overloaded operators
    const Diagonal_Matrix<T> operator+(const Diagonal_Matrix<T>& rhs) const;
    const Diagonal_Matrix<T> operator-(const Diagonal_Matrix<T>& rhs) const;
    const Diagonal_Matrix<T> operator-() const;
    const Diagonal_Matrix<T> operator*(const Diagonal_Matrix<T>& rhs) const;
    const Diagonal_Matrix<T> operator*(const T& x) const;
    const Diagonal_Matrix<T>& operator=(Diagonal_Matrix<T> rhs);

    virtual const Vector<T> operator*(const Vector<T>& rhs) const;
    virtual const Vector<T> operator[](const int index) const;
    virtual void MatrixTest(const Vector<T>& testvector);

    //Friend functions
    friend Diagonal_Matrix<T> operator* (const T& x, const Diagonal_Matrix<T>& rhs) {return rhs * x;};
    friend Diagonal_Matrix<T> operator* (const Vector<T>& x, const Diagonal_Matrix<T>& rhs) {return rhs * x;};
    friend std::ostream& operator<< <T>(std::ostream& out, const Diagonal_Matrix<T>& rhs);
    friend std::istream& operator>> <T>(std::istream& in, Diagonal_Matrix<T>& rhs);

    //Accessors and mutators
    int getSize() const;
    Vector<T> getDiagonal() const;
    Vector<T> getAugment() const;
    void setData(const T element, const int col);
    void setDiagonal(const Vector<T> element);
    void setSize(const int size);
    void setAugment(const T element, const int index);

    //Transpose
    const Diagonal_Matrix<T> transpose() const;
};

#include "Diagonal_Matrix.hpp"
#endif