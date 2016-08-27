/**
 * @file MatrixBase.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief QR DECOMPOSITION HEADER containing template QRsolver algorithm class
 */

#ifndef QRSOLVER_H
#define QRSOLVER_H

#include <stdexcept>

/**
 * @class QRSolver
 * @brief A class containing functions to solve systems of equations using QR decomposition
 */

/**
 * @fn solve(const RectangularMatrix<T>& A)
 * @brief A method to solve an augmented matrix of linear equations
 * @pre The matrix A must be augmented
 * @post The solution vector will be returned
 * @param A an augmented rectangular matrix
 * @return A solution vector to the augmented matrix A
 */

template <class T>
class QRsolver
{
  public:
    //QRsolver overloaded function resolution function
    static Vector<T> solve(const RectangularMatrix<T>& A);
    
};

#include "QRsolver.hpp"
#endif