/**
 * @file MatrixBase.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The MatrixBase interface
 */

#ifndef HW4_MATRIXBASE_H
#define HW4_MATRIXBASE_H

#include "Vector.h"

/**
 * @class MatrixBase
 * @brief The interface that defines common functionality between matrices
 */

/**
 * @fn virtual ~MatrixBase()
 * @brief The interface destructor
 */

/**
 * @fn Vector<T>& operator[](const int i)
 * @brief The index operator for RectangularMatrix classes
 * @pre i must be > 0 and < the number of cols in the RectangularMatrix
 * @post The column vector at index i of the rectangular version of the matrix is returned
 * @param i The column to be accessed, must be > 0 and < cols in the rectangular version of the matrix
 * @return The Vector at index i of the rectangular matrix
 */

/**
 * @fn void transpose()
 * @brief A function to transpose a matrix
 * @post The calling matrix will be transposed
 */

/**
 * @fn int getRows()
 * @brief returns the number of rows in a matrix
 * @post returns the number of rows in a matrix
 * @return the number of rows in a matrix
 */

/**
 * @fn int getCols()
 * @brief returns the number of cols in a matrix
 * @post returns the number of cols in a matrix
 * @return The number of cols in a matrix
 */

/**
 * @fn operator<<(std::ostream& os, const MatrixBase<T>& rhs)
 * @brief outputs a Matrix to ostream os
 * @pre see print
 * @post The matrix will be inserted into os
 * @param os the ostream to print to
 * @param rhs the matrix to print
 * @return A reference to the ostream for chaining
 */

/**
 * @fn operator>>(std::istream& is, MatrixBase<T>& rhs)
 * @brief extracts a matrix from is
 * @pre see read
 * @post matrix contained in is will be extracted into rhs
 * @param is the stream from which to extract
 * @param rhs The matrix to extract to
 * @return A reference to the istream for chaining
 */

/**
 * @fn void print(std::ostream& os) const
 * @brief A function to print the calling RectangularMatrix
 * @pre T must have << defined
 * @post The matrix will be inserted into os
 * @param os The ostream to insert the RectangularMatrix into
 */

/**
 * @fn void read(std::istream& is) const
 * @brief A function to extract the calling RectangularMatrix from is
 * @pre T must have >> defined
 * @post the calling matrix will be the extracted matrix from is
 * @param is The istream to extract the matrix from
 */
template <typename T>
class MatrixBase;
template <typename T>
std::ostream& operator<<(std::ostream& os, const MatrixBase<T>& rhs)
{
  rhs.print(os);
  return os;
}
template <typename T>
std::istream& operator>>(std::istream& is, MatrixBase<T>& rhs)
{
  rhs.read(is);
  return is;
}

template <typename T>
class MatrixBase
{
  public:
    virtual ~MatrixBase() {}

    virtual Vector<T>& operator[](const int i) = 0;
    virtual void transpose() = 0;
    virtual int getRows() const = 0;
    virtual int getCols() const = 0;

    friend std::ostream& operator<< <T>(std::ostream& os, const MatrixBase<T>& rhs);
    friend std::istream& operator>> <T>(std::istream& is, MatrixBase<T>& rhs);

  private:
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
};


#endif //HW4_MATRIXBASE_H
