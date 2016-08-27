/**
 * @file Matrix.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The class definition file for the RectangularMatrix class
 */

#ifndef HW5_RECTANGULARMATRIX_H
#define HW5_RECTANGULARMATRIX_H

#include <utility>
#include <iostream>
#include <stdexcept>
#include "MatrixBase.h"


/**
 * @class RectangularMatrix
 * @brief  A class which will contain a set of Vectors and will act as a mathematical matrix
 */

/**
 * @fn void print(std::ostream& os) const
 * @brief The print function for the RectangularMatrix class, it will print a RectangularMatrix to the ostream
 * @pre The type T has operator<< defined
 * @post return a reference to an ostream which contains the RectangularMatrix
 * @param os The ostream which the RectangularMatrix will be output to
 */

/**
 * @fn void read(std::istream& is) const
 * @brief The read function for the RectangularMatrix class it will take an istream and insert the contents into the
 *        calling object
 * @pre The type T must have operator>> defined, calling object must also have m_rows set BEFORE using the operator
 * @post Returns a reference to the istream and also extracts the information from is and inserts it into rhs
 * @param is The istream from which to extract
 */


/**
 * @fn RectangularMatrix()
 * @brief The default constructor for the RectangularMatrix class, will allocate an empty matrix
 * @post An empty RectangularMatrix will be allocated with no data
 */

/**
 * @fn RectangularMatrix(const int size)
 * @brief Creates a square matrix with a dimensionality of size
 * @pre size must be positive
 * @post A square matrix of dimensionality size will be allocated, if size is negative an exception will be thrown
 * @param size The dimensionality of the matrix to be created
 */

/**
 * @fn RectangularMatrix(const int rows, const int cols)
 * @brief Create a rectangular RectangularMatrix with rows rows and cols cols
 * @pre rows and cols must both be positive
 * @post A rectangular matrix with rows rows and cols cols will be allocated, if either rows or cols is negative an
 *       exception will be thrown
 * @param rows The number of rows in the rectangular matrix, must be positive
 * @param cols The number of cols in the rectangular matrix, must be positive
 */

/**
 * @fn RectangularMatrix(const RectangularMatrix<T>& mat)
 * @brief The copy constructor for the RectangularMatrix class
 * @pre operator= must be defined for type T (T = T)
 * @post A new matrix will be created which is a copy of mat
 * @param mat The matrix to be copied
 */

/**
 * @fn RectangularMatrix(RectangularMatrix<T>&& mat)
 * @brief The move constructor for the RectangularMatrix class
 * @param mat an rvalue which will be moved to the newly created RectangularMatrix
 * @post A new RectangularMatrix is created which uses data from mat instead of creating a copy
 */

/**
 * @fn RectangularMatrixgularMatrix()
 * @brief The destructor for the RectangularMatrix class
 * @post The RectangularMatrix will be allocated and destructed
 */

/**
 * @fn operator=(RectangularMatrix<T> rhs)
 * @brief The assignment operator for the RectangularMatrix class which will copy rhs into the calling object
 * @post The calling object will be an identical copy of rhs
 * @param rhs The RectangularMatrix which should be copied into the calling object
 * @return A reference to the calling object which will be identical to rhs
 */

/**
 * @fn operator[](cost int i)
 * @brief The subscript operator to access the data held in the RectangularMatrix class by element
 * @pre 0 < i < m_rows, if this is not true an IndexError will be thrown
 * @post Return a reference to the data contained at index i in the RectangularMatrix
 * @param i The location to be indexed (IndexError thrown if not 0 < i < m_rows
 * @return A reference to the data contained at index i in the RectangularMatrix
 */

/**
 * @fn operator+=(const RectangularMatrix<T>& rhs)
 * @brief The addition assignment operator will add rhs to the calling object and return a reference to the calling
 *        object
 * @pre T must have the += operator defined (T += T)
 * @post A reference to the calling object is returned which has been modified by adding rhs to the calling object, will
 *       throw a Dimension error if the two matrices cannot be added (different sizes)
 * @param rhs The RectangularMatrix to be added to the calling object
 * @return A reference to the calling object which is the result of addition between the calling object and rhs
 */

/**
 * @fn RectangularMatrix<T>& operator-=(const RectangularMatrix<T>& rhs)
 * @brief The subtraction assignment operator will subtract rhs from the calling object and return a reference to the
 *        calling object, refer to operator+= for error throwing
 * @pre T must have the += operator defined and the unary - operator defined (-T and T+=T)
 * @post A reference to the calling object is returned which has been modified by subtracting rhs from the calling
 *       object
 * @param rhs The RectangularMatrix to be subtracted from the calling object
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
 * @fn operator*=(const RectangularMatrix<T>& rhs)
 * @brief The multiplication assignment operator will multiply rhs and the calling object using RectangularMatrix multiplication
 * @pre if the calling object is an nxm matrix then rhs must be an mxp matrix, T must have * and + defined (T*T and T+T)
 * @post The calling object will be multiplied by rhs using matrix multiplication, an exception will be thrown if the
 *       dimensions do not adhere to the preconditions
 * @param rhs The matrix to multiply the calling object by
 * @return A reference to the calling object after matrix multiplication
 */

/**
 * @fn augment(const Vector<T>& vect) const
 * @brief A function to augment a matrix with a solution vector
 * @pre vect must have as many elements as there are rows in the calling object, an exception will be thrown if this is
 *      not the case
 * @post An augmented RectangularMatrix will be returned which is the calling object augmented with vect
 * @param vect A vector to augment the matrix by, must have as many elements as there are rows in the calling object
 * @return The calling object augmented by vect
 */

/**
 * @fn transpose()
 * @brief Transposes the RectangularMatrix
 * @post The calling object is transposed
 */

/**
 * @fn getRow(const int i)
 * @brief Returns a reference to a row in the matrix
 * @pre i must be > 0 and < m_rows or an error will be thrown
 * @post The vector at row i will be returned as a reference
 * @param i The index of the row vector to return
 * @return A reference to the row vector
 */

/**
 * @fn swap(RectangularMatrix<T>& lhs, RectangularMatrix<T>& rhs)
 * @brief swaps the member variables of lhs and rhs
 * @post lhs will be rhs and rhs will be lhs
 * @param lhs a RectangularMatrix to be swapped with rhs
 * @param rhs a RectangularMatrix to be swapped with lhs
 * @post lhs and rhs will have their member variables swapped
 */

/**
 * @fn operator-(const RectangularMatrix<T>& mat)
 * @brief The unary - operator will negate all terms of the RectangularMatrix
 * @pre The unary - operator must be defined for type T (-T)
 * @post All terms of the RectangularMatrix will be negated
 * @param rhs The RectangularMatrix to be negated
 * @return A RectangularMatrix which is the result of negating each term in rhs
 */

/**
 * @fn operator+(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs)
 * @brief Adds two Matrices together
 * @pre The Matrices must be the same dimensionality, for error throwing and T requirements refer to +=
 * @post A RectangularMatrix will be returned that is the result of addition between rhs and lhs
 * @param lhs An nxm matrix
 * @param rhs An nxm matrix
 * @return A RectangularMatrix that is the result of addition between lhs and rhs
 */

/**
 * @fn operator-(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs)
 * @brief Subtract rhs from lhs
 * @pre The Matrices must be the same dimensionality, for error throwing and T requirements refer to -=
 * @post A RectangularMatrix will be returned that is the result of lhs - rhs
 * @param lhs An nxm matrix
 * @param rhs An nxm matrix
 * @return A RectangularMatrix that is the result of subtraction of rhs from lhs
 */

/**
 * @fn operator*(const RectangularMatrix<T>& lhs, const T& rhs)
 * @brief The scalar multiplication between rhs and RectangularMatrix lhs
 * @pre The * operator must be defined for type T (T * T)
 * @post A RectangularMatrix which is the result of lhs*rhs will be returned
 * @param lhs The RectangularMatrix to multiply by a scalar
 * @param rhs The scalar to multiply lhs by
 * @return A RectangularMatrix which is the result of scalar multiplication between rhs and lhs
 */

/**
 * @fn operator*(const T& lhs, const RectangularMatrix<T>& rhs)
 * @brief The scalar multiplication between lhs and RectangularMatrix rhs
 * @pre The * operator must be defined for type T (T * T)
 * @post A RectangularMatrix which is the result of lhs*rhs will be returned
 * @param lhs The scalar to multiply rhs by
 * @param rhs The RectangularMatrix to multiply by a scalar
 * @return A RectangularMatrix which is the result of scalar multiplication between rhs and lhs
 */

/**
 * @fn operator*(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs)
 * @brief The matrix multiplication between lhs and rhs
 * @pre refer the the preconditions of *=
 * @post A RectangularMatrix which is the result of lhs*rhs will be returned
 * @param lhs An mxn matrix
 * @param rhs An nxp matrix
 * @return A RectangularMatrix which is the result of matrix multiplication between rhs and lhs
 */

/**
 * @fn operator*(const RectangularMatrix<T>& lhs, const Vector<T>& rhs)
 * @brief Multiplies RectangularMatrix rhs by the column Vector<T>& lhs
 * @pre The RectangularMatrix lhs must be nxm and the vector rhs must be mx1 or an exception will be thrown
 * @post The result of RectangularMatrix lhs multiplied by column vector lhs
 * @param lhs An nxm matrix
 * @param rhs An mx1 column vector
 * @return A RectangularMatrix which is the result of multiplying a matrix lhs by a column vector rhs
 */

/**
 * @fn operator*(const Vector<T>& lhs, const RectangularMatrix<T>& rhs)
 * @brief Multiplies RectangularMatrix lhs by the row Vector<T>& rhs
 * @pre The RectangularMatrix rhs must be mxn and the vector lhs must be 1xm or an exception will be thrown
 * @post The result of RectangularMatrix lhs multiplied by column vector lhs
 * @param lhs A 1xm row vector
 * @param rhs An mxn column vector
 * @return A RectangularMatrix which is the result of multiplying a matrix rhs by a row vector lhs
 */

/* ~~~~~ Forward Declarations ~~~~~ */
template <typename T>
class RectangularMatrix;

template <typename T>
void swap(RectangularMatrix<T>& lhs, RectangularMatrix<T>& rhs);
template <typename T>
RectangularMatrix<T> operator-(const RectangularMatrix<T>& mat);
template <typename T>
RectangularMatrix<T> operator+(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs);
template <typename T>
RectangularMatrix<T> operator-(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs);
template <typename T>
RectangularMatrix<T> operator*(const RectangularMatrix<T>& lhs, const T& rhs);
template <typename T>
RectangularMatrix<T> operator*(const T& lhs, const RectangularMatrix<T>& rhs);
template <typename T>
RectangularMatrix<T> operator*(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs);
template <typename T>
RectangularMatrix<T> operator*(const RectangularMatrix<T>& lhs, const Vector<T>& rhs);
template <typename T>
RectangularMatrix<T> operator*(const Vector<T>& lhs, const RectangularMatrix<T>& rhs);


template <typename T>
class RectangularMatrix : public MatrixBase<T>
{
  private:
    Vector<T>* m_data;
    int m_rows, m_cols;

    virtual void print(std::ostream& os) const;
    virtual void read(std::istream& is);

  public:
    /* ~~~~~ Constructors ~~~~~ */
    RectangularMatrix();
    RectangularMatrix(const int size);
    RectangularMatrix(const int rows, const int cols);
    RectangularMatrix(const RectangularMatrix<T>& mat);
    RectangularMatrix(RectangularMatrix<T>&& mat);
    ~RectangularMatrix();

    /* ~~~~~ Member Functions ~~~~~ */
    RectangularMatrix<T>& operator=(RectangularMatrix<T> rhs);
    virtual Vector<T>& operator[](const int i);
    RectangularMatrix<T>& operator+=(const RectangularMatrix<T>& rhs);
    RectangularMatrix<T>& operator-=(const RectangularMatrix<T>& rhs);
    RectangularMatrix<T>& operator*=(const T& rhs);
    RectangularMatrix<T>& operator*=(const RectangularMatrix<T>& rhs);
    RectangularMatrix<T> augment(const Vector<T>& vect) const;
    virtual void transpose();
    virtual int getRows() const {return m_rows;}
    virtual int getCols() const {return m_cols;}

    /** ~~~~~ Friend Functions ~~~~~ */
    friend void swap <T>(RectangularMatrix<T>& lhs, RectangularMatrix<T>& rhs);
    friend RectangularMatrix<T> operator- <T>(const RectangularMatrix<T>& mat);
    friend RectangularMatrix<T> operator+ <T>(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs);
    friend RectangularMatrix<T> operator- <T>(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs);
    friend RectangularMatrix<T> operator* <T>(const RectangularMatrix<T>& lhs, const T& rhs);
    friend RectangularMatrix<T> operator* <T>(const T& lhs, const RectangularMatrix<T>& rhs);
    friend RectangularMatrix<T> operator* <T>(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs);
    friend RectangularMatrix<T> operator* <T>(const RectangularMatrix<T>& lhs, const Vector<T>& rhs);
    friend RectangularMatrix<T> operator* <T>(const Vector<T>& lhs, const RectangularMatrix<T>& rhs);

    void setCol(Vector<T>& data, const int col);
    Vector<T> getCol(const int col);
};

#include "RectangularMatrix.hpp"


#endif //HW5_RECTANGULARMATRIX_H
