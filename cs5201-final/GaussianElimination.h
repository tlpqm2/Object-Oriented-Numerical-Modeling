/**
 * @file GaussianElimination.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The class definition file for the GaussianElimination class
 */

#ifndef HW5_GAUSSIANELIMINATION_H
#define HW5_GAUSSIANELIMINATION_H

#include "RectangularMatrix.h"
#include "Vector.h"

/**
 * @class GaussianElimination
 * @brief A class containing different methods of gaussian elimination
 */

/**
 * @fn gaussianPartialPivoting(const RectangularMatrix<T>& coeffs, const Vector<T>& solns)
 * @brief An implementation of gaussian elimination with partial pivoting to solve a system of equations
 * @pre coeff is an mxn matrix and solns is an nx1 column vector, an exception will be thrown if this is not the case
 *      The system must have a solution and must have linearly independent equations
 * @post Returns an augmented matrix in reduced row echelon form
 * @param coeffs The coefficients of the linear system of equations, nxm
 * @param solns The solutions to the linear system of equations, mx1
 * @return A matrix containing the solution to the system in reduced row echelon form
 */

template <typename T>
class GaussianElimination
{
  public:
    static Vector<T> gaussianPartialPivoting(const RectangularMatrix<T>& coeffs)
    {
      RectangularMatrix<T> working(coeffs);
      Vector<T> temp;
      int max_row;
      T divisor, max;

      // Reduce to row echelon form
      for(size_t i = 0; i < working.getRows(); i++)
      {
        // Find the max row;
        max_row = static_cast<int>(i);
        max = std::abs(working[i][0]);
        for(size_t j = i + 1; j < working.getRows(); j++)
        {
          if(std::abs(working[j][0] > max))
          {
            max_row = static_cast<int>(j);
            max = std::abs(working[j][0]);
          }
        }

        //Check if a swap is necessary
        if(max_row != i)
        {
          temp = working[i];
          working[i] = working[max_row];
          working[max_row] = temp;
        }

        // Normalize row i
        divisor = working[i][i];
        if(divisor == 0)
        {
          throw std::domain_error("The system either has no solution or has dependent variables.");
        }
        for(size_t j = 0; j < working.getCols(); j++)
        {
          working[i][j] = working[i][j] / divisor;
        }

        for(size_t j = i + 1; j < working.getRows(); j++)
        {
          working[j] -= working[i] * working[j][i];
        }
      }

      // Plug in and solve the matrix
      for(int i = working.getRows() - 2; i >= 0; i--)
      {
        for(int j = i; j >= 0; j--)
          working[j] -= working[j][i+1] * working[i+1];
      }

      return working.getCol(working.getCols()-1);
    }

};


#endif //HW5_GAUSSIANELIMINATION_H
