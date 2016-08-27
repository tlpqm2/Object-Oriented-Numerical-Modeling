/**
 * @file TriangularMatrix.hpp
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The class implementation file for the TriangularMatrix class
 */

#include "TriangularMatrix.h"

template <typename T>
void TriangularMatrix<T>::print(std::ostream& os) const
{
  for(size_t i = 0; i < m_dim; i++)
  {
    os << vectorizeRow(i) << "\n";
  }
  os << std::endl;
}

template <typename T>
void TriangularMatrix<T>::read(std::istream& is)
{
  for(size_t i = 0; i < m_dim; i++)
  {
    is >> m_data[i];
  }
}


template <typename T>
TriangularMatrix<T>::TriangularMatrix() : m_dim(0)
{
  m_data = new Vector<T>[0];
}

template <typename T>
TriangularMatrix<T>::TriangularMatrix(const int size) : m_dim(size)
{
  m_data = new Vector<T>[size];

  for(int i = 0; i < m_dim; i++)
  {
    m_data[i] = Vector<T>(m_dim - i);
  }
}

template <typename T>
TriangularMatrix<T>::TriangularMatrix(const TriangularMatrix<T>& mat) : m_dim(mat.m_dim)
{
  m_data = new Vector<T>[m_dim];

  for(size_t i = 0; i < m_dim; i++)
  {
    m_data[i] = mat.m_data[i];
  }
}

template <typename T>
TriangularMatrix<T>::TriangularMatrix(TriangularMatrix<T>&& mat) : m_data(mat.m_data), m_dim(mat.m_dim)
{
  mat.m_data = nullptr;
  mat.m_dim = 0;
}

template <typename T>
TriangularMatrix<T>::~TriangularMatrix()
{
  m_dim = 0;
  delete[] m_data;
}

template <typename T>
TriangularMatrix<T>& TriangularMatrix<T>::operator=(TriangularMatrix<T> rhs)
{
  swap(*this, rhs);

  return *this;
}

template <typename T>
Vector<T>& TriangularMatrix<T>::operator[](const int i)
{
  if(i < 0 || i >= m_dim)
    std::out_of_range("Index into TriangularMatrix is out of range.");

  return m_data[i];
}

template <typename T>
Vector<T> TriangularMatrix<T>::vectorizeRow(const int i) const
{
  Vector<T> v(m_dim);

  if(i < 0 || i >= m_dim)
    throw std::out_of_range("Index into TriangularMatrix row is out of range.");

  for(size_t j = 0; j < m_dim - i; j++)
  {
    v[j + i] = m_data[i][j];
  }

  return v;
}

template <typename T>
TriangularMatrix<T>& TriangularMatrix<T>::operator+=(const TriangularMatrix<T>& rhs)
{
  if(m_dim != rhs.m_dim)
    throw DimensionError(m_dim, rhs.m_dim);

  for(size_t i = 0; i < m_dim; i++)
  {
    m_data[i] += rhs.m_data[i];
  }

  return *this;
}

template <typename T>
TriangularMatrix<T>& TriangularMatrix<T>::operator-=(const TriangularMatrix<T>& rhs)
{
  return *this += -rhs;
}

template <typename T>
TriangularMatrix<T>& TriangularMatrix<T>::operator*=(const T& rhs)
{
  for(size_t i = 0; i < m_dim; i++)
  {
    m_data[i] = m_data[i] * rhs;
  }

  return *this;
}

template <typename T>
void TriangularMatrix<T>::transpose()
{ }

template <typename T>
RectangularMatrix<T> TriangularMatrix<T>::squarify() const
{
  RectangularMatrix<T> ret(m_dim);
  for(size_t i = 0; i < m_dim; i++)
  {
    ret[i] = vectorizeRow(i);
  }

  return ret;
}

template <typename T>
void swap(TriangularMatrix<T>& lhs, TriangularMatrix<T>& rhs)
{
  std::swap(lhs.m_dim, rhs.m_dim);
  std::swap(lhs.m_data, rhs.m_data);
}

template <typename T>
TriangularMatrix<T> operator-(const TriangularMatrix<T>& mat)
{
  TriangularMatrix<T> ret(mat);

  for(size_t i = 0; i < mat.m_dim; i++)
  {
    ret.m_data[i] = -mat.m_data[i];
  }

  return ret;
}

template <typename T>
TriangularMatrix<T> operator+(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs)
{
  TriangularMatrix<T> m(lhs);
  m += rhs;
  return m;
}

template <typename T>
TriangularMatrix<T> operator-(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs)
{
  TriangularMatrix<T> m(lhs);
  m -= rhs;
  return m;
}

template <typename T>
TriangularMatrix<T> operator*(const TriangularMatrix<T>& lhs, const T& rhs)
{
  TriangularMatrix<T> ret(lhs);
  ret *= rhs;
  return ret;
}

template <typename T>
TriangularMatrix<T> operator*(const T& lhs, const TriangularMatrix<T>& rhs)
{
  TriangularMatrix<T> ret(rhs);
  ret *= lhs;
  return ret;
}

template <typename T>
RectangularMatrix<T> operator*(const TriangularMatrix<T>& lhs, const TriangularMatrix<T>& rhs)
{
  RectangularMatrix<T> ret(rhs.m_dim);

  if(lhs.m_dim != rhs.m_dim)
    throw DimensionError(lhs.m_dim, rhs.m_dim);

  for(size_t i = 0; i < lhs.m_dim; i++)
  {
    for(size_t j = i; j < lhs.m_dim; j++)
    {
      for(size_t k = i; k < lhs.m_dim; k++)
      {
        ret[i][j] += lhs.vectorizeRow(i)[k] * rhs.vectorizeRow(k)[j];
      }
    }
  }

  return ret;
}