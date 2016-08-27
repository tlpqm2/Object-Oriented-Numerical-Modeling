//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : DRIVER to run the specified output for HOMEWORK 5 as well as a series of tests
//              for the Tridiagonal Matrix implementation.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Vector.h"
#include "AMatrix.h"
#include "Dense_Matrix.h"
#include "Tridiagonal_Matrix.h"
#include "Diagonal_Matrix.h"
#include "LowerTriangular_Matrix.h"
#include "UpperTriangular_Matrix.h"
#include "SymmetricDense_Matrix.h"
#include "Dense_Gauss.h"
#include "Tridiagonal_Gauss.h"
#include "QRdecomp.h"

float TOLERANCE = .0000001;

template<typename T>
T f(T x);

template<typename T>
T p(Vector<T> poly, T x);

int main(int argc, char** argv)
{
  if(argc == 2)
  {
    std::fstream in;
    in.open("TestMatrices.txt");

    Dense_Matrix<float> test(3);
    QRdecomp<float> qr(3);

    in >> test;

    std::cout << "Test output: " << std::endl;
    std::cout << test << std::endl;
    qr(test);
    std::cout << "Q output: " << std::endl;
    std::cout << qr.getQ() << std::endl;
    std::cout << "R output: " << std::endl;
    std::cout << qr.getR() << std::endl;
    in.close();
  }
   /* Vector<int> testvector(4);
    Tridiagonal_Matrix<int> tritest(4);
    Diagonal_Matrix<int> diagonaltest(4);
    SymmetricDense_Matrix<int> symmetricdensetest(4);
    UpperTriangular_Matrix<int> uppertriangulartest(4);
    LowerTriangular_Matrix<int> lowertriangulartest(4);

    in >> testvector >> diagonaltest >> symmetricdensetest >> uppertriangulartest >> lowertriangulartest;
    in.close();
    tritest.setDiagonal(uppertriangulartest.getRow(1), 0);
    tritest.setDiagonal(testvector, 1);
    tritest.setDiagonal(uppertriangulartest.getRow(1), 2);

    //FUNCTIONALITY TESTS
    std::cout << "TRIDIAGONAL_MATRIX tests: " << std::endl;
    tritest.MatrixTest(testvector);
    std::cout << "DIAGONAL_MATRIX tests: " << std::endl;
    diagonaltest.MatrixTest(testvector);
    std::cout << "SYMMETRICDENSE_MATRIX tests: " << std::endl;
    symmetricdensetest.MatrixTest(testvector);
    std::cout << "UPPERTRIANGULAR_MATRIX tests: " << std::endl;
    uppertriangulartest.MatrixTest(testvector);
    std::cout << "LOWERTRIANGULAR_MATRIX tests: " << std::endl;
    lowertriangulartest.MatrixTest(testvector);

    in.open(argv[1]);
    int size;

    for(int i = 0; i < 2; i++)
    {
      in >> size;
      int counter = 1;
      Vector<float> diagonal(size);
      Dense_Matrix<float> currentA(size);
      Dense_Matrix<float> previousA(size);
      in >> currentA;
      
      //Iterate until convergence
      //Diagonals of current and previous Matrix iterations converge to the zero vector when normed
      while((currentA.getDiagonal() - previousA.getDiagonal()).twoNorm() > TOLERANCE || counter == 1)
      {
        QRdecomp<float> myQR(size);
        myQR(currentA);
        previousA = currentA;
        currentA = myQR.getR() * myQR.getQ();
        counter++;
        if(counter == 5)
        {
          std::cout << "=== Iteration 5 - Matrix " << i + 1 << " ==="<<std::endl;
          std::cout << currentA << std::endl;
        }
        else if(counter == 10)
        {
          std::cout << "=== Iteration 10 - Matrix " << i + 1 << " ==="<<std::endl;
          std::cout << currentA << std::endl;
        }
      }
      std::cout << "=== Final Iteration "<<counter<<" - Matrix " << i + 1 << " ==="<<std::endl;
      std::cout << currentA << std::endl;
      std::cout << "=== Reason - Matrix " << i + 1 << " ==="<<std::endl;
      std::cout << "Two norm of (currentA main diagonal - previousA main diagonal) < error tolerance: " << std::endl;
      std::cout << "The main Diagonal (Eigenvalues) converges to a particular set of values"<<std::endl;
      std::cout << "Absolute error = "; 
      std::cout << (currentA.getDiagonal() - previousA.getDiagonal()).twoNorm() << std::endl;
      std::cout << "Tolerance = " << TOLERANCE << std::endl<<std::endl;  
      std::cout << "=== Eigenvalues - Matrix " << i + 1 << " ==="<<std::endl;
      std::cout << currentA.getDiagonal() << std::endl; 
    }
    in.close();
    std::cout << "===" << std::endl;
  } 
  */
  return 0;
}
