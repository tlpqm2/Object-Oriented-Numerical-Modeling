/**
 * @file MatrixBase.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The PDESolver header containing template PDEsolver algorithm class
 */

#ifndef PDESOLVER_H
#define PDESOLVER_H

#include <stdexcept>
#include <cmath>
#include <chrono>
#include "RectangularMatrix.h"

/**
 * @class PDESolver
 * @brief The functor for solving a specific PDE (the Dirichlet problem using the Poisson equation)
 */

/**
 * @fn operator()(const int n)
 * @brief Solves the Dirichlet problem for the Poisson equation with n subdivisions
 * @pre a forcing function, boundary function and solver function must all be passed in as template arguments.
 *      The boundary function should be piecewise and return different equations based on which boundary it is on.
 * @post Return a vector of solutions based on the forcing function.  The vector will be the interior points which use
 *       1/n divisions
 * @param n is the number of same size partitions
 * @return A vector of solutions based on the forcing function and Poisson's equation
 */

template <class T, T T_forcing(T, T), T T_boundary(T, T), Vector<T> T_solver(const RectangularMatrix<T>&)>
class PDEsolver
{
  public:
    //PDEsolver overloaded function resolution operator
    Vector<T> operator()(const int n);
};

#include "PDEsolver.hpp"
#endif