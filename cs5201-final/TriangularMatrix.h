/**
 * @file TriangularMatrix.hpp
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The class declaration file for the Triangular Matrix class
 */

#ifndef HW6_TRIANGULARMATRIX_H
#define HW6_TRIANGULARMATRIX_H

#include "MatrixBase.h"
#include "RectangularMatrix.h"

/**
 * @class TriangularMatrix
 * @brief  A class which will contain a set of vectors which will contain an upper triangular matrix
 */

/**
 * @fn void print(std::ostream& os) const
 * @brief The print function for the TriangularMatrix class, it will print a TriangularMatrix to the ostream
 * @pre The type T has operator<< defined
 * @post return a reference to an ostream which contains the TriangularMatrix
 * @param os The ostream which the TriangularMatrix will be output to
 */

/**
 * @fn void read(std::istream& is) const
 * @brief The read function for the TriangularMatrix class it will take an istream and insert the contents into the
 *        calling object
 * @pre The type T must have operator>> defined, calling object must also have m_rows set BEFORE using the operator
 * @post Returns a reference to the istream and also extracts the information from is and inserts it into rhs
 * @param is The istream from which to extract
 */


/**
 * @fn TriangularMatrix()
 * @brief The default constructor for the TriangularMatrix class, will allocate an empty matrix
 * @post An empty TriangularMatrix will be allocated with no data
 */

/**
 * @fn TriangularMatrix(const int size)
 * @brief Creates a square matrix with a dimensionality of size
 * @pre size must be positive
 * @post A square matrix of dimensionality size will be allocated, if size is negative an exception will be thrown
 * @param size The dimensionality of the matrix to be created
 */

/**
 * @fn TriangularMatrix(const TriangularMatrix<T>& mat)
 * @brief The copy constructor for the TriangularMatrix class
 * @pre operator= must be defined for type T (T = T)
 * @post A new matrix will be created which is a copy of mat
 * @param mat The matrix to be copied
 */

/**
 * @fn TriangularMatrix(TriangularMatrix<T>&& mat)
 * @brief The move constructor for the TriangularMatrix class
 * @param mat an rvalue which will be moved to the newly created TriangularMatrix
 * @post A new TriangularMatrix is created which uses data from mat instead of creating a copy
 */

/**
 * @fn TriangularMatrixgularMatrix()
 * @brief The destructor for the TriangularMatrix class
 * @post The TriangularMatrix will be allocated and destructed
 */

/**
 * @fn operator=(TriangularMatrix<T> rhs)
 * @brief The assignment operator for the TriangularMatrix class which will copy rhs into the calling object
 * @post The calling object will be an identical copy of rhs
 * @param rhs The TriangularMatrix which should be copied into the calling object
 * @return A reference to the calling object which will be identical to rhs
 */

/**
 * @fn operator[](cost int i)
 * @brief The subscript operator to access the data held in the TriangularMatrix class by element
 * @pre 0 < i < m_rows, if this is not true an IndexError will be thrown
 * @post Return a reference to the data contained at index i in the TriangularMatrix
 * @param i The location to be indexed (IndexError thrown if not 0 < i < m_rows
 * @return A reference to the data contained at index i in the TriangularMatrix
 */

/**
 * @fn operator+=(const TriangularMatrix<T>& rhs)
 * @brief The addition assignment operator will add rhs to the calling object and return a reference to the calling
 *        object
 * @pre T must have the += operator defined (T += T)
 * @post A reference to the calling object is returned which has been modified by adding rhs to the calling object, will
 *       throw a Dimension error if the two matrices cannot be added (different sizes)
 * @param rhs The TriangularMatrix to be added to the calling object
 * @return A reference to the calling object which is the result of addition between the calling object and rhs
 */

/**
 * @fn TriangularMatrix<T>& operator-=(const TriangularMatrix<T>& rhs)
 * @brief The subtraction assignment operator will subtract rhs from the calling object and return a reference to the
 *        calling object, refer to operator+= for error throwing
 * @pre T must have the += operator defined and the unary - operator defined (-T and T+=T)
 * @post A reference to the calling object is returned which has been modified by subtracting rhs from the calling
 *       object
 * @param rhs The TriangularMatrix to be subtracted from the calling object
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
 * @post An augmented TriangularMatrix will be returned which is the calling object augmented with vect
 * @param vect A vector to augment the matrix by, must have as many elements as there are rows in the calling object
 * @return The calling object augmented by vect
 */

/**
 * @fn transpose()
 * @brief Transposes the TriangularMatrix
 * @post The calling object is transposed
 */

/**
 * @fn squarify() const
 * @brief converts tridiaganal to rectangular
 * @post returns the rectangular version of the Triangular
 * @return The rectangular version of the Triangular
 */

/**
 * @fn swap(TriangularMatrix<T>& lhs, TriangularMatrix<T>& rhs)
 * @brief swaps the member variables of lhs and rhs
 * @post lhs will be rhs and rhs will be lhs
 * @param lhs a TriangularMatrix to be swapped with rhs
 * @param rhs a TriangularMatrix to be swapped with lhs
 * @post lhs and rhs will have their member variables swapped
 */

/**
 * @fn operator-(const TriangularMatrix<T>& mat)
 * @brief The unary - operator will negate all terms of the TriangularMatrix
 * @pre The unary - operator must be defined for type T (-T)
 * @post All terms of the TriangularMatrix will be negated
 * @param rhs The TriangularMatrix to be negated
 * @return A TriangularMatrix which is the result of negating each term in rhs
 */

/**
 * @fn operator+(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs)
 * @brief Adds two Matrices together
 * @pre The Matrices must be the same dimensionality, for error throwing and T requirements refer to +=
 * @post A TriangularMatrix will be returned that is the result of addition between rhs and lhs
 * @param lhs An nxm matrix
 * @param rhs An nxm matrix
 * @return A TriangularMatrix that is the result of addition between lhs and rhs
 */

/**
 * @fn operator-(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs)
 * @brief Subtract rhs from lhs
 * @pre The Matrices must be the same dimensionality, for error throwing and T requirements refer to -=
 * @post A TriangularMatrix will be returned that is the result of lhs - rhs
 * @param lhs An nxm matrix
 * @param rhs An nxm matrix
 * @return A TriangularMatrix that is the result of subtraction of rhs from lhs
 */

/**
 * @fn operator*(const TriangularMatrix<T>& lhs, const T& rhs)
 * @brief The scalar multiplication between rhs and TriangularMatrix lhs
 * @pre The * operator must be defined for type T (T * T)
 * @post A TriangularMatrix which is the result of lhs*rhs will be returned
 * @param lhs The TriangularMatrix to multiply by a scalar
 * @param rhs The scalar to multiply lhs by
 * @return A TriangularMatrix which is the result of scalar multiplication between rhs and lhs
 */

/**
 * @fn operator*(const T& lhs, const TriangularMatrix<T>& rhs)
 * @brief The scalar multiplication between lhs and TriangularMatrix rhs
 * @pre The * operator must be defined for type T (T * T)
 * @post A TriangularMatrix which is the result of lhs*rhs will be returned
 * @param lhs The scalar to multiply rhs by
 * @param rhs The TriangularMatrix to multiply by a scalar
 * @return A TriangularMatrix which is the result of scalar multiplication between rhs and lhs
 */

/**
 * @fn operator*(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs)
 * @brief The matrix multiplication between lhs and rhs
 * @pre refer the the preconditions of *=
 * @post A RectangularMatrix which is the result of lhs*rhs will be returned
 * @param lhs An nxn matrix
 * @param rhs An nxn matrix
 * @return A RectangularMatrix which is the result of matrix multiplication between rhs and lhs
 */

/**
 * @fn operator*(const TriangularMatrix<T>& lhs, const Vector<T>& rhs)
 * @brief Multiplies TriangularMatrix rhs by the column Vector<T>& lhs
 * @pre The RectangularMatrix lhs must be nxn and the vector rhs must be nx1 or an exception will be thrown
 * @post The result of TriangularMatrix lhs multiplied by column vector lhs
 * @param lhs An nxm Triangular matrix
 * @param rhs An mx1 column vector
 * @return A RectangularMatrix which is the result of multiplying a matrix lhs by a column vector rhs
 */

/**
 * @fn operator*(const Vector<T>& lhs, const TriangularMatrix<T>& rhs)
 * @brief Multiplies TriangularMatrix lhs by the row Vector<T>& rhs
 * @pre The TriangularMatrix rhs must be nxn and the vector lhs must be 1xn or an exception will be thrown
 * @post The result of TriangularMatrix lhs multiplied by column vector lhs
 * @param lhs A 1xn row vector
 * @param rhs An nxn Triangular matrix
 * @return A RectangularMatrix which is the result of multiplying a matrix rhs by a row vector lhs
 */

/* ~~~~~ Forward Declarations ~~~~~ */
template <typename T>
class TriangularMatrix;

template <typename T>
void swap(TriangularMatrix<T>& lhs, TriangularMatrix<T>& rhs);
template <typename T>
TriangularMatrix<T> operator-(const TriangularMatrix<T>& mat);
template <typename T>
TriangularMatrix<T> operator+(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs);
template <typename T>
TriangularMatrix<T> operator-(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs);
template <typename T>
TriangularMatrix<T> operator*(const TriangularMatrix<T>& lhs, const T& rhs);
template <typename T>
TriangularMatrix<T> operator*(const T& lhs, const TriangularMatrix<T>& rhs);
template <typename T>
RectangularMatrix<T> operator*(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs);

template <typename T>
class TriangularMatrix : public MatrixBase<T>
{
  protected:
    int m_dim;
    Vector<T>* m_data;

    virtual void print(std::ostream& os) const;
    virtual void read(std::istream& is);

  public:
    /* ~~~~~ Constructors ~~~~~ */
    TriangularMatrix();
    TriangularMatrix(const int size);
    TriangularMatrix(const TriangularMatrix<T>& mat);
    TriangularMatrix(TriangularMatrix<T>&& mat);
    ~TriangularMatrix();

    /* ~~~~~ Member Functions ~~~~~ */
    TriangularMatrix<T>& operator=(TriangularMatrix<T> rhs);
    virtual Vector<T>& operator[](const int i);
    virtual Vector<T> vectorizeRow(const int i) const;
    virtual TriangularMatrix<T>& operator+=(const TriangularMatrix<T>& rhs);
    virtual TriangularMatrix<T>& operator-=(const TriangularMatrix<T>& rhs);
    virtual TriangularMatrix<T>& operator*=(const T& rhs);
    virtual void transpose();
    virtual int getRows() const {return m_dim;}
    virtual int getCols() const {return m_dim;}
    RectangularMatrix<T> squarify() const;

    friend void swap <T>(TriangularMatrix<T>& lhs, TriangularMatrix<T>& rhs);
    friend TriangularMatrix<T> operator- <T>(const TriangularMatrix<T>& mat);
    friend TriangularMatrix<T> operator+ <T>(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs);
    friend TriangularMatrix<T> operator- <T>(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs);
    friend TriangularMatrix<T> operator* <T>(const TriangularMatrix<T>& lhs, const T& rhs);
    friend TriangularMatrix<T> operator* <T>(const T& lhs, const TriangularMatrix<T>& rhs);
    friend RectangularMatrix<T> operator* <T>(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs);
};

#include "TriangularMatrix.hpp"

#endif //HW6_TRIANGULARMATRIX_H
