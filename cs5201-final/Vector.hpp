/**
 * @file Vector.hpp
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The class implementation file for the Vector class
 */

#include <stdexcept>
#include "Vector.h"

template <typename T>
Vector<T>::Vector()
{
  m_size = 0;
  m_data = new T[0];
}

template <typename T>
Vector<T>::Vector(const int size)
{
  m_size = size;
  m_data = new T[m_size];

  for(int i = 0; i < m_size; i++)
  {
    m_data[i] = 0;
  }
}

template <typename T>
Vector<T>::Vector(const Vector<T>& vect)
{
  m_size = vect.m_size;
  m_data = new T[m_size];

  for(int i = 0; i < m_size; i++)
  {
    m_data[i] = vect.m_data[i];
  }
}

template <typename T>
Vector<T>::~Vector()
{
  m_size = 0;
  delete[] m_data;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& vect) : m_data(vect.m_data), m_size(vect.m_size)
{
  vect.m_data = nullptr;
  vect.m_size = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> rhs)
{
  swap(*this, rhs);

  return *this;
}

template <typename T>
T& Vector<T>::operator[](const int i)
{
  if(i < 0 || i >= m_size)
  {
    throw std::out_of_range("Index into Vector is out of range.");
  }
  return m_data[i];
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& rhs)
{
  if(m_size != rhs.m_size)
  {
    throw DimensionError(m_size, rhs.m_size);
  }
  for(int i = 0; i < m_size; i++)
    m_data[i] += rhs.m_data[i];

  return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& rhs)
{
  return *this += -(rhs);
}

template <typename T>
T Vector<T>::operator()(const T x)
{
  T ret = 0;
  for(int i = 0; i < m_size; i++)
  {
    ret += m_data[i]*pow(x, i);
  }
  return ret;
}

template <typename T>
void swap(Vector<T>& lhs, Vector<T>& rhs)
{
  std::swap(lhs.m_size, rhs.m_size);
  std::swap(lhs.m_data, rhs.m_data);
}

template <typename T>
Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs)
{
  Vector<T> v(lhs);
  v += rhs;
  return v;
}

template <typename T>
Vector<T> operator-(const Vector<T>& lhs, const Vector<T>& rhs)
{
  Vector<T> v(lhs);
  v -= rhs;
  return v;
}

template <typename T>
Vector<T> operator-(const Vector<T>& rhs)
{
  Vector<T> v(rhs);

  for(int i = 0; i < v.m_size; i++)
    v.m_data[i] = -rhs.m_data[i];

  return v;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& rhs)
{
  for(int i = 0; i < rhs.m_size; i++)
  {
    os << std::left << std::setw(14) << std::setfill(' ') << rhs.m_data[i] << "\t";
  }

  return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Vector<T>& rhs)
{
  for(int i = 0; i < rhs.m_size; i++)
  {
    is >> rhs.m_data[i];
  }

  return is;
}

template <typename T>
T operator*(const Vector<T>& lhs, const Vector<T>& rhs)
{
  T ret = 0;

  if(lhs.m_size != rhs.m_size)
  {
    throw DimensionError(lhs.m_size, rhs.m_size);
  }

  for(int i = 0; i < lhs.m_size; i++)
  {
    ret += lhs.m_data[i]*rhs.m_data[i];
  }

  return ret;
}

template <typename T>
Vector<T> operator*(const T& lhs, const Vector<T>& rhs)
{
  Vector<T> v(rhs);

  for(int i = 0; i < v.m_size; i++)
  {
    v.m_data[i] = v.m_data[i] * lhs;
  }

  return v;
}

template <typename T>
Vector<T> operator*(const Vector<T>& lhs, const T& rhs)
{
  return rhs*lhs;
}

template <typename T>
T norm(const Vector<T>& vect)
{
  T res = 0;

  for(int i = 0; i < vect.m_size; i++)
  {
    res += pow(vect.m_data[i], 2);
  }

  return sqrt(res);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<Vector<T>>& rhs)
{
  for(int i = 0; i < rhs.size(); i++)
  {
    for(size_t j = 0; j < rhs.size(); j++)
    {
      os << std::left << std::setw(14) << std::setfill(' ') << rhs.at(j).m_data[i];
    }
    os << "\n";
  }

  return os;
}