//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : LOWERTRIANGULAR MATRIX HEADER containing template LowerTriangular_Matrix class.
#ifndef LOWERTRIANGULAR_MATRIX_H
#define LOWERTRIANGULAR_MATRIX_H

#include <cmath>
#include <utility>
#include <stdexcept>
#include "AMatrix.h"
#include "Vector.h"
//#include "UpperTriangular_Matrix.h"

//Forward declaration of classes
template <class T>
class LowerTriangular_Matrix;
template <class T>
class UpperTriangular_Matrix;

//Forward declaration of templated friend functions
//Documentation for the following 2 friend functions
//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs Vector need matching sizes for Matrix-Vector multiplication.
//PostCondition : Returns a copy of the resultant multiplication.
//Description   : MATRIX-VECTOR AND MATRIX-SCALAR MULTIPLICATION implemented as friend functions to allow for
//                natural use of operators. i.e. 4*Matrix and Matrix*4 will both work; the same goes for Vectors.
template <typename T>
LowerTriangular_Matrix<T> operator* (const T& x, const LowerTriangular_Matrix<T>& rhs);

template <typename T>
LowerTriangular_Matrix<T> operator* (const Vector<T>& x, const LowerTriangular_Matrix<T>& rhs);

template <typename T>
std::ostream& operator<< (std::ostream& out, const LowerTriangular_Matrix<T>& rhs);

template <typename T>
std::istream& operator>> (std::istream& in, LowerTriangular_Matrix<T>& rhs);

//THE other class
template <class T>
class LowerTriangular_Matrix: public AMatrix<T>
{
  private:
    Vector<T>* m_matrix;
    int m_size;
    Vector<T> m_augment;
  public:
    //Constructors and destructor
    LowerTriangular_Matrix(const int setSize);
    LowerTriangular_Matrix(const LowerTriangular_Matrix<T>& rhs);
    LowerTriangular_Matrix(LowerTriangular_Matrix<T>&& rhs): m_matrix(std::move(rhs.m_matrix))
                                                            ,m_size(rhs.m_size)
                                                            ,m_augment(std::move(rhs.m_augment)) 
                                                       {rhs.m_matrix = nullptr; rhs.m_size = 0;};
    ~LowerTriangular_Matrix();

    //Overloaded operators
    const LowerTriangular_Matrix<T> operator+(const LowerTriangular_Matrix<T>& rhs) const;
    const LowerTriangular_Matrix<T> operator-(const LowerTriangular_Matrix<T>& rhs) const;
    const LowerTriangular_Matrix<T> operator-() const;
    const LowerTriangular_Matrix<T> operator*(const LowerTriangular_Matrix<T>& rhs) const;
    const LowerTriangular_Matrix<T> operator*(const T& x) const;
    const LowerTriangular_Matrix<T>& operator=(LowerTriangular_Matrix<T> rhs);

    virtual const Vector<T> operator*(const Vector<T>& rhs) const;
    virtual const Vector<T> operator[](const int index) const;
    virtual void MatrixTest(const Vector<T>& testvector);

    //Friend functions
    friend LowerTriangular_Matrix<T> operator* (const T& x, const LowerTriangular_Matrix<T>& rhs) {return rhs * x;};
    friend LowerTriangular_Matrix<T> operator* (const Vector<T>& x, const LowerTriangular_Matrix<T>& rhs) {return rhs * x;};
    friend std::ostream& operator<< <T>(std::ostream& out, const LowerTriangular_Matrix<T>& rhs);
    friend std::istream& operator>> <T>(std::istream& in, LowerTriangular_Matrix<T>& rhs);

    //Accessors and mutators
    int getSize() const;
    Vector<T> getAugment() const;
    void setData(const T element, const int row, const int col);
    void setRow(const Vector<T> row, const int index);
    void setSize(const int size);
    void setAugment(const T element, const int index);

    //Transpose
    const UpperTriangular_Matrix<T> transpose() const;
};

#include "LowerTriangular_Matrix.hpp"
#endif