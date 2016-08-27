/**
 * @file LowerTriangularMatrix.hpp
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The class implementation file for the LowerTriangularMatrix class
 */

#include "LowerTriangularMatrix.h"

template <typename T>
LowerTriangularMatrix<T>::LowerTriangularMatrix() : TriangularMatrix<T>()
{ }

template <typename T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(const int size) : TriangularMatrix<T>(size)
{ }

template <typename T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(const LowerTriangularMatrix<T>& mat) : TriangularMatrix<T>(mat)
{ }

template <typename T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(LowerTriangularMatrix<T>&& mat) : TriangularMatrix<T>(mat)
{ }

template <typename T>
LowerTriangularMatrix<T>::~LowerTriangularMatrix()
{ }

template <typename T>
Vector<T> LowerTriangularMatrix<T>::vectorizeRow(const int i) const
{
  Vector<T> v(TriangularMatrix<T>::m_dim);

  if(i < 0 || i >= TriangularMatrix<T>::m_dim)
    throw std::out_of_range("Index into TriangularMatrix row is out of range.");

  for(size_t j = 0; j < i + 1; j++)
  {
    v[j] = TriangularMatrix<T>::m_data[TriangularMatrix<T>::m_dim - i - 1][j];
  }

  return v;
}

template <typename T>
LowerTriangularMatrix<T>& LowerTriangularMatrix<T>::operator+=(const LowerTriangularMatrix<T>& rhs)
{
  TriangularMatrix<T>::operator+=(rhs);
  return *this;
}

template <typename T>
LowerTriangularMatrix<T>& LowerTriangularMatrix<T>::operator-=(const LowerTriangularMatrix<T>& rhs)
{
  TriangularMatrix<T>::operator-=(rhs);
  return *this;
}

template <typename T>
LowerTriangularMatrix<T>& LowerTriangularMatrix<T>::operator*=(const T& rhs)
{
  TriangularMatrix<T>::operator*=(rhs);
  return *this;
}

template <typename T>
LowerTriangularMatrix<T> operator-(const LowerTriangularMatrix<T>& mat)
{
  LowerTriangularMatrix<T> ret(mat);

  for(size_t i = 0; i < mat.m_dim; i++)
  {
    ret.m_data[i] = -mat.m_data[i];
  }

  return ret;
}

template <typename T>
LowerTriangularMatrix<T> operator+(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs)
{
  LowerTriangularMatrix<T> m(lhs);
  m += rhs;
  return m;
}

template <typename T>
LowerTriangularMatrix<T> operator-(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs)
{
  LowerTriangularMatrix<T> m(lhs);
  m -= rhs;
  return m;
}
template <typename T>
LowerTriangularMatrix<T> operator*(const LowerTriangularMatrix<T>& lhs, const T& rhs)
{
  LowerTriangularMatrix<T> ret(lhs);
  ret *= rhs;
  return ret;
}

template <typename T>
LowerTriangularMatrix<T> operator*(const T& lhs, const LowerTriangularMatrix<T>& rhs)
{
  LowerTriangularMatrix<T> ret(rhs);
  ret *= lhs;
  return ret;
}

template <typename T>
RectangularMatrix<T> operator*(const LowerTriangularMatrix<T>& lhs, const LowerTriangularMatrix<T>& rhs)
{
  RectangularMatrix<T> ret(rhs.m_dim);

  if(lhs.m_dim != rhs.m_dim)
    throw DimensionError(lhs.m_dim, rhs.m_dim);

  for(size_t i = 0; i < lhs.m_dim; i++)
  {
    for(size_t j = 0; j < i + 1; j++)
    {
      for(size_t k = 0; k < i + 1; k++)
      {
        ret[i][j] += lhs.vectorizeRow(i)[k] * rhs.vectorizeRow(k)[j];
      }
    }
  }

  return ret;
}