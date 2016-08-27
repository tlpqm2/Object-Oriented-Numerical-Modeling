/**
 * @file Vector.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The class definition file for the Vector class
 */

#ifndef HW3_VECTOR_H
#define HW3_VECTOR_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include "DimensionError.h"

/**
 * @class Vector
 * @brief A Vector class which will store an n dimensional vector
 */

/**
 * @fn Vector()
 * @brief The default constructor for the Vector class
 * @post Creates an empty Vector with m_size=0 and no data
 */

/**
 * @fn Vector(const int size)
 * @brief A constructor to create an empty vector of dimensionality size
 * @post An empty Vector of dimensionality size is initialized
 */

/**
 * @fn Vector(const Vector<T>& vect)
 * @brief The copy constructor for the Vector class
 * @pre T must have the = operator defined
 * @post A deep copy of the Vector vect will be created
 * @param vect The Vector to be copied
 */

/**
 * @fn Vector(Vector<T>&& vect)
 * @brief The move constructor for the Vector class
 * @param vect an rvalue which will be moved to the newly created Vect
 * @post A new Vector is created which uses the data from vect instead of creating a copy, vect's data is set to nullptr
 */

/**
 * @fn ~Vector()
 * @brief The destructor for the Vector class
 * @post All allocated memory used by the Vector class will be freed
 */

/**
 * @fn operator=(Vector<T> rhs)
 * @brief The assignment operator for the Vector class which will copy the rhs into the calling object
 * @post The calling object will be an identical copy of rhs
 * @param rhs The Vector which should be copied into the calling object
 * @return A reference to the calling object which will be identical to rhs
 */

/**
 * @fn operator[](const int i)
 * @brief An operator to access the data held in the Vector class by element
 * @pre 0 < i < m_size it will throw an error if this is not true
 * @post Return a reference to the data contained at index i in the Vector
 * @param i The location to be indexed
 * @return A reference to the data contained at index i in the Vector
 */

/**
 * @fn operator+=(const Vector<T>& rhs)
 * @brief The addition assignment operator will add rhs to the calling object and return a reference to the calling
 *        object
 * @pre T must have the += operator defined
 * @post A reference to the calling object is returned which has been modified by adding rhs to the calling object, will
 *       throw a DimensionError if the vectors are of different sizes
 * @param rhs The Vector to be added to the calling object
 * @return A reference to the calling object which is the result of addition between the calling object and rhs
 */

/**
 * @fn operator-=(const Vector<T>& rhs)
 * @brief The subtraction assignment operator will subtract rhs from the calling object and return a reference to the
 *        calling object, refer to operator+= for error throwing
 * @pre T must have the += operator defined and the unary - operator defined
 * @post A reference to the calling object is returned which has been modified by subtracting rhs from the calling
 *       object
 * @param rhs The Vector to be subtracted from the calling object
 * @return A reference to the calling object which is the result of subtraction of rhs from the calling object
 */

/**
 * @fn getDim()
 * @brief Returns the dimensionality of the vector
 * @post Returns the dimensionality of the vector
 * @return the dimensionality of the vector
 */

/**
 * @fn swap(Vector<T>& lhs, Vector<T>& rhs)
 * @brief swaps the member variables of lhs with rhs
 * @post lhs will be rhs and rhs will be lhs
 * @param lhs a vector to be swapped
 * @param rhs a vector to be swapped
 * @post lhs and rhs will have their member variables swapped
 */

/**
 * @fn operator+(const Vector<T>& lhs, const Vector<T>& rhs)
 * @brief Adds two Vectors together
 * @pre The Vectors must be the same length
 * @post A Vector will be returned that is the addition of lhs and rhs
 * @param lhs An n dimensional Vector
 * @param rhs An n dimensional Vector
 * @return A Vector that is the result of addition between lhs and rhs
 */

/**
 * @fn operator-(const Vector<T>& lhs, const Vector<T>& rhs)
 * @brief Subtract two Vectors
 * @pre The Vectors must be the same length and the -= operator must be defined for T
 * @post The result of subtracting two vectors
 * @param lhs An n dimensional Vector
 * @param rhs An n dimensional Vector
 * @return A Vector that is the result of subtraction between lhs and rhs
 */

/**
 * @fn operator-(const Vector<T>& rhs)
 * @brief The unary - operator will negate all terms of the Vector
 * @pre The unary - operator must be defined for the type T
 * @post All terms of the vector will be negated
 * @param rhs The Vector to be negated
 * @return A vector which is the result of negating each term in rhs
 */

/**
 * @fn operator<<(std::ostream os, const Vector<T>& rhs)
 * @brief The insertion operator for the Vector class, it will print a Vector to an ostream
 * @pre The type T has operator<< defined
 * @post return a reference to an ostream which contains the Vector element
 * @param os The ostream which the vector will be output to
 * @param rhs The vector to add to the ostream os
 * @return A reference to an ostream which contains the Vector rhs
 */

/**
 * @fn operator>>(std::istream& is, Vector<T>& rhs)
 * @brief The extraction operator for the Vector class, it will take an istream and insert the contents into rhs
 * @pre The type T must have operator>> defined, rhs must also have m_size set BEFORE using the operator
 * @post Return a reference to the istream and also extract the information from is and insert it into rhs
 * @param is The istream from which to extract
 * @param rhs The Vector to insert into
 * @return A reference to the istream which allows for chaining
 */

/**
 * @fn operator*(const Vector<T>& lhs, const Vector<T>& rhs)
 * @brief The dot product of two vectors
 * @pre The * operator and the + operator must be defined for type T, the two vectors must be of the same dimensionality
 *      T also needs to have an assignment operator defined which takes an int as the assignment
 * @post Performs the dot product between the two vectors and returns the result
 * @param lhs A vector to perform the dot product with
 * @param rhs A vector to perform the dot product with
 * @return The result of the dot product between lhs and rhs
 */

/**
 * @fn operator*(const T& lhs, const Vector<T>& rhs)
 * @brief Multiplies the vector rhs by the scalar lhs
 * @pre The type T must have an operator* which takes two T's as arguments
 * @post The Vector rhs will be multiplied by the scalar lhs and the result will be returned
 * @param lhs A scalar to multiply the vector by
 * @param rhs The vector to multiply by a scalar
 * @return The result of the scalar multiplication
 */

/**
 * @fn Vector<T> operator*(const Vector<T>& lhs, const T& rhs)
 * @brief Multiplies the vector lhs by the scalar rhs)
 * @pre The type T must have an operator* which takes two T's as arguments
 * @post The Vector lhs will be multiplied by the scalar rhs and the result will be returned
 * @param lhs A vector to multiply by a scalar
 * @param rhs A scalar to multiply the vector by
 * @return The result of the scalar multiplication
 */

/**
 * @fn norm(const Vector<T>& vect)
 * @brief Finds the 2 norm of a vector (magnitude)
 * @pre T must be a numeric type which can be used in pow and sqrt and can be assigned the value 0, T must also have
 *      a += operator
 * @post The 2 norm of the vector will be calculated and returned as a double (this is due to sqrt)
 * @param vect The vector for which the 2 norm is calculated
 * @return The 2 norm of vect (double)
 */

/**
 * @fn operator<<(std::ostream& os, const std::vector<Vector<T>>& rhs)
 * @brief insert the set of column vectors contained in rhs into os and return a reference to os
 * @pre Type T must have operator<< defined
 * @post Insert the set of column vectors contained in rhs into os
 * @param os The ostream to insert the Vectors into
 * @param rhs The set of Vectors to be inserted into the ostream os
 * @return A reference to the os which contains the formatted output for the set of Vectors rhs
 */

/**
 * @fn operator()(const T x)
 * @brief Evaluates a vector at x using the index as a power for x and the value in the vector as a coeff
 * @post returns the evaluation of the vector
 * @return The evaluation of the vector
 */

/* ~~~~~ Forward Declarations ~~~~~ */
template <typename T>
class Vector;

template <typename T>
void swap(Vector<T>& lhs, Vector<T>& rhs);
template <typename T>
Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs);
template <typename T>
Vector<T> operator-(const Vector<T>& lhs, const Vector<T>& rhs);
template <typename T>
Vector<T> operator-(const Vector<T>& rhs);
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& rhs);
template <typename T>
std::istream& operator>>(std::istream& is, Vector<T>& rhs);
template <typename T>
T operator*(const Vector<T>& lhs, const Vector<T>& rhs);
template <typename T>
Vector<T> operator*(const T& lhs, const Vector<T>& rhs);
template <typename T>
Vector<T> operator*(const Vector<T>& lhs, const T& rhs);
template <typename T>
T norm(const Vector<T>& vect);
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<Vector<T>>& rhs);

template <typename T>
class Vector
{
  private:
    T* m_data;
    int m_size;

  public:
    /* ~~~~~ Constructors ~~~~~ */
    Vector();
    Vector(const int size);
    Vector(const Vector<T>& vect);
    Vector(Vector<T>&& vect);
    ~Vector();

    /* ~~~~~ Member Functions ~~~~~ */
    Vector<T>& operator=(Vector<T> rhs);
    T& operator[](const int i);
    Vector<T>& operator+=(const Vector<T>& rhs);
    Vector<T>& operator-=(const Vector<T>& rhs);
    T operator()(const T x);
    int getDim() const {return m_size;};

    /* ~~~~~ Friend Functions ~~~~~ */
    friend void swap <T>(Vector<T>& lhs, Vector<T>& rhs);
    friend Vector<T> operator+ <T>(const Vector<T>& lhs, const Vector<T>& rhs);
    friend Vector<T> operator- <T>(const Vector<T>& lhs, const Vector<T>& rhs);
    friend Vector<T> operator- <T>(const Vector<T>& rhs);
    friend std::ostream& operator<< <T>(std::ostream& os, const Vector<T>& rhs);
    friend std::istream& operator>> <T>(std::istream& is, Vector<T>& rhs);
    friend T operator* <T>(const Vector<T>& lhs, const Vector<T>& rhs);
    friend Vector<T> operator* <T>(const T& lhs, const Vector<T>& rhs);
    friend Vector<T> operator* <T>(const Vector<T>& lhs, const T& rhs);
    friend T norm <T>(const Vector<T>& vect);
    friend std::ostream& operator<< <T>(std::ostream& os, const std::vector<Vector<T>>& rhs);
};

#include "Vector.hpp"

#endif //HW3_VECTOR_H
