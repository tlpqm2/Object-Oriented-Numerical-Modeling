/**
 * @file driver.cpp
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The driver file for the final project.  The driver numerically approximates the Dirchlet problem on the
 *        Poisson distribution
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include "RectangularMatrix.h"
#include "GaussianElimination.h"
#include "TriangularMatrix.h"
#include "LowerTriangularMatrix.h"
#include "QRdecomp.h"
#include "PDEsolver.h"
#include "QRsolver.h"


// Forcing function and boundary function definition
template <typename T>
T forcing(T x, T y)
{
  if(x <= 0 || x >= 1 || y <= 0 || y >= 1)
    throw std::out_of_range("Either x or y is out of range and is undefined in the forcing function");
  return -2*(pow(x, 2) + pow(y, 2));
}

template <typename T>
T boundary(T x, T y)
{
  T res = 0;
  if(y == 0)
  {
    res = 1 - pow(x, 2);
  }
  else if(y == 1)
  {
    res = 2*(1-pow(x, 2));
  }
  else if(x == 0)
  {
    res = 1 + pow(y, 2);
  }
  else if(x == 1)
  {
    res = 0;
  }
  return res;
}

int main(int argc, char** argv)
{
  PDEsolver<double, forcing<double>, boundary<double>, GaussianElimination<double>::gaussianPartialPivoting> p;
  PDEsolver<double, forcing<double>, boundary<double>, QRsolver<double>::solve> p2;
  int partitions;
  std::chrono::steady_clock::time_point begin, end;
  Vector<double> soln;

  if(argc < 2)
  {
    std::cerr << "Too few arguments!" << std::endl;
    std::cerr << "Usage is: ./driver <n>" << std::endl;
    exit(0);
  }
  partitions = atoi(argv[1]);

  /* Gaussian */
  // Solve and time
  begin = std::chrono::steady_clock::now();
  soln = p(partitions);
  end = std::chrono::steady_clock::now();
  std::cout << "Time(us) to solve using gaussian: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;

  // Output the solution vector
  std::cout << "Solutions for Gaussian method: " << std::endl;
  for(size_t i = 0; i < partitions - 1; i++)
  {
    for(size_t j = 0; j < partitions - 1; j++)
    {
      std::cout << std::fixed << std::setprecision(3) << "u(" << (i + 1.0) / partitions << ", "
      << (j + 1.0) / partitions << ") = ";
      std::cout << std::fixed << std::setprecision(8) << soln[i * (partitions - 1) + j] << std::endl;
    }
  }
  std::cout << std::endl;

  /* QR */
  // Solve and time
  begin = std::chrono::steady_clock::now();
  soln = p2(partitions);
  end = std::chrono::steady_clock::now();
  std::cout << "Time(us) to solve using QR: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;

  // Output the solution vector
  std::cout << "Solutions for QR method: " << std::endl;
  for(size_t i = 0; i < partitions - 1; i++)
  {
    for(size_t j = 0; j < partitions - 1; j++)
    {
      std::cout << std::fixed << std::setprecision(3) << "u(" << (i + 1.0) / partitions << ", "
      << (j + 1.0) / partitions << ") = ";
      std::cout << std::fixed << std::setprecision(8) << soln[i * (partitions - 1) + j] << std::endl;
    }
  }

  return 0;
}