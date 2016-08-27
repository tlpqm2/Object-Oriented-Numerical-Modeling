/**
 * @file RectangularMatrix.hpp
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The class implementation file for the RectangularMatrix class
 */

#include "RectangularMatrix.h"

template <typename T>
void RectangularMatrix<T>::print(std::ostream& os) const
{
  for(size_t i = 0; i < m_rows; i++)
  {
    os << m_data[i] << "\n";
  }
  os << std::endl;
}

template <typename T>
void RectangularMatrix<T>::read(std::istream& is)
{
  for(size_t i = 0; i < m_rows; i++)
  {
    is >> m_data[i];
  }
}

template <typename T>
RectangularMatrix<T>::RectangularMatrix() : m_rows(0), m_cols(0)
{
  m_data = nullptr;
}

template <typename T>
RectangularMatrix<T>::RectangularMatrix(const int size) : m_rows(size), m_cols(size)
{
  if(m_rows < 0 || m_cols < 0)
    throw std::domain_error("RectangularMatrix must be sized greater than 0");

  m_data = new Vector<T>[size];
  for(size_t i = 0; i < size; i++)
  {
    m_data[i] = Vector<T>(size);
  }
}

template <typename T>
RectangularMatrix<T>::RectangularMatrix(const int rows, const int cols) : m_rows(rows), m_cols(cols)
{
  if(m_rows < 0 || m_cols < 0)
    throw std::domain_error("RectangularMatrix must be sized greater than 0");

  m_data = new Vector<T>[rows];
  for(size_t i = 0; i < rows; i++)
  {
    m_data[i] = Vector<T>(cols);
  }
}

template <typename T>
RectangularMatrix<T>::RectangularMatrix(const RectangularMatrix<T>& mat)
{
  // Get the dimensionality
  m_cols = mat.m_cols;
  m_rows = mat.m_rows;

  // Allocate and copy the new matrix
  m_data = new Vector<T>[m_rows];
  for(size_t i = 0; i < m_rows; i++)
  {
    m_data[i] = mat.m_data[i];
  }
}

template <typename T>
RectangularMatrix<T>::RectangularMatrix(RectangularMatrix<T>&& mat) : m_data(mat.m_data), m_rows(mat.m_rows),
                                                                      m_cols(mat.m_cols)
{
  mat.m_data = nullptr;
  mat.m_rows = 0;
  mat.m_cols = 0;
}

template <typename T>
RectangularMatrix<T>::~RectangularMatrix()
{
  m_rows = 0;
  m_cols = 0;
  delete[] m_data;
}

template <typename T>
RectangularMatrix<T>& RectangularMatrix<T>::operator=(RectangularMatrix<T> rhs)
{
  swap(*this, rhs);

  return *this;
}

template <typename T>
Vector<T>& RectangularMatrix<T>::operator[](const int i)
{
  if(i < 0 || i >= m_rows)
    throw std::out_of_range("Index into RectangularMatrix row is out of range.");

  return m_data[i];
}

template <typename T>
RectangularMatrix<T>& RectangularMatrix<T>::operator+=(const RectangularMatrix<T>& rhs)
{
  if(m_rows != rhs.m_rows)
    throw DimensionError(m_rows, rhs.m_rows);
  if(m_cols != rhs.m_cols)
    throw DimensionError(m_cols, rhs.m_cols);

  for(size_t i = 0; i < m_rows; i++)
    m_data[i] += rhs.m_data[i];

  return *this;
}

template <typename T>
RectangularMatrix<T>& RectangularMatrix<T>::operator-=(const RectangularMatrix<T>& rhs)
{
  return *this += -(rhs);
}

template <typename T>
RectangularMatrix<T>& RectangularMatrix<T>::operator*=(const T& rhs)
{
  for(size_t i = 0; i < m_rows; i++)
    m_data[i] = m_data[i] * rhs;

  return *this;
}

template <typename T>
RectangularMatrix<T>& RectangularMatrix<T>::operator*=(const RectangularMatrix<T>& rhs)
{
  RectangularMatrix<T> m(m_rows, rhs.m_cols);

  if(m_cols != rhs.m_rows)
    throw DimensionError(m_cols, rhs.m_rows);

  for(size_t i = 0; i < m.m_rows; i++)
  {
    for(size_t j = 0; j < m.m_cols; j++)
    {
      for(size_t k = 0; k < m_cols; k++)
      {
        m.m_data[i][j] += m_data[i][k] * rhs.m_data[k][j];
      }
    }
  }

  *this = m;

  return *this;
}

template <typename T>
RectangularMatrix<T> RectangularMatrix<T>::augment(const Vector<T>& vect) const
{
  RectangularMatrix<T> m(m_rows, m_cols + 1);
  Vector<T> v(vect);

  if(vect.getDim() != m_rows)
    throw DimensionError(vect.getDim(), m_rows);

  for(size_t i = 0; i < m_rows; i++)
  {
    m[i] = Vector<T>(m_cols + 1);
    for(size_t j = 0; j < m_cols; j++)
    {
      m[i][j] = m_data[i][j];
    }
    m[i][m_cols] = v[i];
  }

  return m;
}

template <typename T>
void RectangularMatrix<T>::transpose()
{
  RectangularMatrix<T> temp(m_cols, m_rows);

  for(size_t i = 0; i < m_rows; i++)
  {
    for(size_t j = 0; j < m_cols; j++)
    {
      temp[j][i] = m_data[i][j];
    }
  }

  *this = temp;
}

template <typename T>
void swap(RectangularMatrix<T>& lhs, RectangularMatrix<T>& rhs)
{
  std::swap(lhs.m_cols, rhs.m_cols);
  std::swap(lhs.m_rows, rhs.m_rows);
  std::swap(lhs.m_data, rhs.m_data);
}

template <typename T>
RectangularMatrix<T> operator-(const RectangularMatrix<T>& mat)
{
  RectangularMatrix<T> m(mat);

  for(size_t i = 0; i < m.m_rows; i++)
    m.m_data[i] = -mat.m_data[i];

  return m;
}

template <typename T>
RectangularMatrix<T> operator+(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs)
{
  RectangularMatrix<T> m(lhs);
  m += rhs;
  return m;
}

template <typename T>
RectangularMatrix<T> operator-(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs)
{
  RectangularMatrix<T> m(lhs);
  m -= rhs;
  return m;
}

template <typename T>
RectangularMatrix<T> operator*(const RectangularMatrix<T>& lhs, const T& rhs)
{
  RectangularMatrix<T> m(lhs);
  m *= rhs;
  return m;
}

template <typename T>
RectangularMatrix<T> operator*(const T& lhs, const RectangularMatrix<T>& rhs)
{
  RectangularMatrix<T> m(rhs);
  m *= lhs;
  return m;
}

template <typename T>
RectangularMatrix<T> operator*(const RectangularMatrix<T>& lhs, const RectangularMatrix<T>& rhs)
{
  RectangularMatrix<T> m(lhs);
  m *= rhs;
  return m;
}

template <typename T>
RectangularMatrix<T> operator*(const RectangularMatrix<T>& lhs, const Vector<T>& rhs)
{
  RectangularMatrix<T> vec(rhs.getDim(), 1);
  Vector<T> v(rhs);

  for(size_t i = 0; i < rhs.getDim(); i++)
    vec.m_data[i][0] = v[i];

  return lhs * vec;
}

template <typename T>
RectangularMatrix<T> operator*(const Vector<T>& lhs, const RectangularMatrix<T>& rhs)
{
  RectangularMatrix<T> vec(1, lhs.getDim());

  vec[0] = lhs;

  return vec * rhs;
}

template <typename T>
void RectangularMatrix<T>::setCol(Vector<T>& data, const int col)
{
  for(int i = 0; i < m_rows; i++)
  {
    m_data[i][col] = data[i];
  }

  return;
}

template <typename T>
Vector<T> RectangularMatrix<T>::getCol(const int col)
{
  Vector<T> temp(m_rows);
  for(int i = 0; i < m_rows; i++)
  {
    temp[i] = m_data[i][col];
  }

  return temp;
}