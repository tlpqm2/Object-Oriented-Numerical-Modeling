/**
 * @file LowerTriangularMatrix.hpp
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The class definition file for the LowerTriangularMatrix class
 */

#ifndef HW6_LOWERTRIANGULARMATRIX_H
#define HW6_LOWERTRIANGULARMATRIX_H

#include "TriangularMatrix.h"

/**
 * @class TriangularMatrix
 * @brief  A class which will contain a set of vectors which will contain a lower triangular matrix
 */

/**
 * @fn LowerTriangularMatrix()
 * @brief The default constructor for the LowerTriangularMatrix class, will allocate an empty matrix
 * @post An empty LowerTriangularMatrix will be allocated with no data
 */

/**
 * @fn LowerTriangularMatrix(const int size)
 * @brief Creates a square matrix with a dimensionality of size
 * @pre size must be positive
 * @post A square matrix of dimensionality size will be allocated, if size is negative an exception will be thrown
 * @param size The dimensionality of the matrix to be created
 */

/**
 * @fn LowerTriangularMatrix(const LowerTriangularMatrix<T>& mat)
 * @brief The copy constructor for the LowerTriangularMatrix class
 * @pre operator= must be defined for type T (T = T)
 * @post A new matrix will be created which is a copy of mat
 * @param mat The matrix to be copied
 */

/**
 * @fn LowerTriangularMatrix(LowerTriangularMatrix<T>&& mat)
 * @brief The move constructor for the LowerTriangularMatrix class
 * @param mat an rvalue which will be moved to the newly created LowerTriangularMatrix
 * @post A new LowerTriangularMatrix is created which uses data from mat instead of creating a copy
 */

/**
 * @fn operator=(LowerTriangularMatrix<T> rhs)
 * @brief The assignment operator for the LowerTriangularMatrix class which will copy rhs into the calling object
 * @post The calling object will be an identical copy of rhs
 * @param rhs The LowerTriangularMatrix which should be copied into the calling object
 * @return A reference to the calling object which will be identical to rhs
 */

/**
 * @fn operator+=(const LowerTriangularMatrix<T>& rhs)
 * @brief The addition assignment operator will add rhs to the calling object and return a reference to the calling
 *        object
 * @pre T must have the += operator defined (T += T)
 * @post A reference to the calling object is returned which has been modified by adding rhs to the calling object, will
 *       throw a Dimension error if the two matrices cannot be added (different sizes)
 * @param rhs The LowerTriangularMatrix to be added to the calling object
 * @return A reference to the calling object which is the result of addition between the calling object and rhs
 */

/**
 * @fn LowerTriangularMatrix<T>& operator-=(const LowerTriangularMatrix<T>& rhs)
 * @brief The subtraction assignment operator will subtract rhs from the calling object and return a reference to the
 *        calling object, refer to operator+= for error throwing
 * @pre T must have the += operator defined and the unary - operator defined (-T and T+=T)
 * @post A reference to the calling object is returned which has been modified by subtracting rhs from the calling
 *       object
 * @param rhs The LowerTriangularMatrix to be subtracted from the calling object
 * @return A reference to the calling object which is the result of subtraction of rhs from the calling object
 */

/**
 * @fn operator*=(const T& rhs)
 * @brief The multiplication assignment operator will multiply rhs and the calling object using scalar multiplication
 * @pre T must have the * operator defined (T * T)
 * @post A reference to the calling object will be returned which is the result of scalar multiplication between the
 *       calling object and rhs
 * @param rhs The object to multiply the calling object by
 * @return A reference to the calling object which is the result of scalar multiplication of rhs and the calling object
 */

/**
 * @fn augment(const Vector<T>& vect) const
 * @brief A function to augment a matrix with a solution vector
 * @pre vect must have as many elements as there are rows in the calling object, an exception will be thrown if this is
 *      not the case
 * @post An augmented LowerTriangularMatrix will be returned which is the calling object augmented with vect
 * @param vect A vector to augment the matrix by, must have as many elements as there are rows in the calling object
 * @return The calling object augmented by vect
 */

/**
 * @fn operator-(const LowerTriangularMatrix<T>& mat)
 * @brief The unary - operator will negate all terms of the LowerTriangularMatrix
 * @pre The unary - operator must be defined for type T (-T)
 * @post All terms of the LowerTriangularMatrix will be negated
 * @param rhs The LowerTriangularMatrix to be negated
 * @return A LowerTriangularMatrix which is the result of negating each term in rhs
 */

/**
 * @fn operator+(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs)
 * @brief Adds two Matrices together
 * @pre The Matrices must be the same dimensionality, for error throwing and T requirements refer to +=
 * @post A LowerTriangularMatrix will be returned that is the result of addition between rhs and lhs
 * @param lhs An nxm matrix
 * @param rhs An nxm matrix
 * @return A LowerTriangularMatrix that is the result of addition between lhs and rhs
 */

/**
 * @fn operator-(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs)
 * @brief Subtract rhs from lhs
 * @pre The Matrices must be the same dimensionality, for error throwing and T requirements refer to -=
 * @post A LowerTriangularMatrix will be returned that is the result of lhs - rhs
 * @param lhs An nxm matrix
 * @param rhs An nxm matrix
 * @return A LowerTriangularMatrix that is the result of subtraction of rhs from lhs
 */

/**
 * @fn operator*(const LowerTriangularMatrix<T>& lhs, const T& rhs)
 * @brief The scalar multiplication between rhs and LowerTriangularMatrix lhs
 * @pre The * operator must be defined for type T (T * T)
 * @post A LowerTriangularMatrix which is the result of lhs*rhs will be returned
 * @param lhs The LowerTriangularMatrix to multiply by a scalar
 * @param rhs The scalar to multiply lhs by
 * @return A LowerTriangularMatrix which is the result of scalar multiplication between rhs and lhs
 */

/**
 * @fn operator*(const T& lhs, const LowerTriangularMatrix<T>& rhs)
 * @brief The scalar multiplication between lhs and LowerTriangularMatrix rhs
 * @pre The * operator must be defined for type T (T * T)
 * @post A LowerTriangularMatrix which is the result of lhs*rhs will be returned
 * @param lhs The scalar to multiply rhs by
 * @param rhs The LowerTriangularMatrix to multiply by a scalar
 * @return A LowerTriangularMatrix which is the result of scalar multiplication between rhs and lhs
 */

/**
 * @fn operator*(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs)
 * @brief The matrix multiplication between lhs and rhs
 * @pre refer the the preconditions of *=
 * @post A RectangularMatrix which is the result of lhs*rhs will be returned
 * @param lhs An nxn matrix
 * @param rhs An nxn matrix
 * @return A RectangularMatrix which is the result of matrix multiplication between rhs and lhs
 */

/* ~~~~~ Forward Declarations ~~~~~ */
template <typename T>
class LowerTriangularMatrix;

template <typename T>
LowerTriangularMatrix<T> operator-(const LowerTriangularMatrix<T>& mat);
template <typename T>
LowerTriangularMatrix<T> operator+(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);
template <typename T>
LowerTriangularMatrix<T> operator-(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);
template <typename T>
LowerTriangularMatrix<T> operator*(const LowerTriangularMatrix<T>& lhs, const T& rhs);
template <typename T>
LowerTriangularMatrix<T> operator*(const T& lhs, const LowerTriangularMatrix<T>& rhs);
template <typename T>
RectangularMatrix<T> operator*(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);

template <typename T>
class LowerTriangularMatrix : public TriangularMatrix<T>
{
  public:
    /* ~~~~~ Constructors ~~~~~ */
    LowerTriangularMatrix();
    LowerTriangularMatrix(const int size);
    LowerTriangularMatrix(const LowerTriangularMatrix<T>& mat);
    LowerTriangularMatrix(LowerTriangularMatrix<T>&& mat);
    ~LowerTriangularMatrix();

    /* ~~~~~ Member Functions ~~~~~ */
    virtual Vector<T> vectorizeRow(const int i) const;
    virtual LowerTriangularMatrix<T>& operator+=(const LowerTriangularMatrix<T>& rhs);
    virtual LowerTriangularMatrix<T>& operator-=(const LowerTriangularMatrix<T>& rhs);
    virtual LowerTriangularMatrix<T>& operator*=(const T& rhs);

    /* ~~~~~ Friend Functions ~~~~~ */
    friend LowerTriangularMatrix<T> operator- <T>(const LowerTriangularMatrix<T>& mat);
    friend LowerTriangularMatrix<T> operator+ <T>(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);
    friend LowerTriangularMatrix<T> operator- <T>(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);
    friend LowerTriangularMatrix<T> operator* <T>(const LowerTriangularMatrix<T>& lhs, const T& rhs);
    friend LowerTriangularMatrix<T> operator* <T>(const T& lhs, const LowerTriangularMatrix<T>& rhs);
    friend RectangularMatrix<T> operator* <T>(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs);
};

#include "LowerTriangularMatrix.hpp"

#endif //HW6_LOWERTRIANGULARMATRIX_H
