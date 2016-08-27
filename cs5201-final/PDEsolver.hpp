/**
 * @file MatrixBase.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The PDESolver implementation file containing template PDEsolver algorithm class
 */

#include "PDEsolver.h"

template <class T, T T_forcing(T, T), T T_boundary(T, T), Vector<T> T_solver(const RectangularMatrix<T>&)>
Vector<T> PDEsolver<T, T_forcing, T_boundary, T_solver>::operator()(const int n)
{
  //Produce Matrices A and Vector b and g
  int size = pow(n-1, 2);
  Vector<T> solved;

  /* Generate A */
  RectangularMatrix<T> A(size);

  // The top and bottom vectors are going to be -1/4
  for(size_t i = 0; i < size - (n-1); i++)
  {
    // TODO: This should probaly be a constant but I have no idea what to call it
    A[i][n-1+i] = -.25;
    A[n-1+i][i] = -.25;
  }

  // Fill in the offcenter diagonals
  for(size_t i = 0; i < size - 1; i++)
  {
    if((i+1) % (n-1) != 0)
    {
      A[i][i+1] = -.25;
      A[i+1][i] = -.25;
    }
  }

  // Fill in the center diagonal
  for(size_t i = 0; i < size; i++)
  {
    A[i][i] = 1;
  }

  /* Generate b */
  Vector<T> b(size);
  int runner = 0;
  for(int i = 0; i < n-1; i++)
  {
    for(int j = 0; j < n-1; j++)
    {
      if(i == 0)
      {
        b[runner] = T_boundary((j+1.0)/n, 0);
      }
      else if(i == n-2)
      {
        b[runner] = T_boundary((j+1.0)/n, 1);
      }

      if(j == 0)
      {
        b[runner] += T_boundary(0, (i+1.0)/n);
      }
      else if(j == n-2)
      {
        b[runner] += T_boundary(1, (i+1.0)/n);
      }
      runner++;
    }
  }

  /* Generate g */
  int fastrunner = 0;
  Vector<T> g(size);
  for(int i = 0; i < n-1; i++)
  {
    T second = ((i+1.0)/n);
    for(int j = 0; j < n-1; j++)
    {
      T first = ((j+1.0)/n);
      g[fastrunner] = T_forcing(first, second);
      fastrunner++;
    }
  }

  //Run T_solver
  Vector<T> x(size);
  T h = 1.0/n;
  b = (1.0/4) * b;
  g = g * ((h * h) / 4);
  b = b - g;

  solved = T_solver(A.augment(b));

  return solved;
}