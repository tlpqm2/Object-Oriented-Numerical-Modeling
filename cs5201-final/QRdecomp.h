/**
 * @file MatrixBase.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief QR DECOMPOSITION HEADER containing template QRdecomp algorithm class
 */

#ifndef QRDECOMP_H
#define QRDECOMP_H

#include <stdexcept>

/**
 * @class QRdecomp
 * @brief A functor to decompose a matrix into an orthogonal Q and an upper triangular R which hold the property A = QR
 */

/**
 * @fn QRdecomp(const int size)
 * @brief DEFAULT CONSTRUCTOR is the only constructor for QRdecomp. Initializing m_R allows setting the first k values
 *        in Rk since size-k terms following that are 0.
 * @pre size is >= 0
 * @post m_R has size number of 0 vectors pushed
 */

/**
 * @fn operator()(RectangularMatrix<T>& A)
 * @brief FUNCTION RESOLUTION is the main purpose of QRdecomp class. It performs the algorithm to produce 2 matrices Q
 *        and R.
 * @pre Error is thrown if r(k,k) is 0.  Matrix A is a linearly independent set of Vectors
 * @post m_Q will have size number of Vectors pushed. m_R has k elements in Vector R(k) modified to produce a special
 *           matrix.
 */

/**
 * @fn getQ()
 * @brief M_Q ACCESSOR allows for indirect private member access to the Q matrix
 * @post Returns RectangularMatrix Q
 */

/**
 * @fn getR()
 * @brief M_R ACCESSOR allows for indirect private member access to the R matrix
 * @post Returns RectangularMatrix R
 */

template <class T>
class QRdecomp
{
  private:
    RectangularMatrix<T> m_Q; 
    RectangularMatrix<T> m_R;
  public:
    //Default constructor
    QRdecomp(const int size);
    //QR overloaded function resolution function
    void operator()(RectangularMatrix<T>& A);

    //Accessors for Q and R
    const RectangularMatrix<T> getQ() const;
    const RectangularMatrix<T> getR() const;
};

#include "QRdecomp.hpp"
#endif