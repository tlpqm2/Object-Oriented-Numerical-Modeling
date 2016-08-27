/**
 * @file DimensionError.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief The class definition file for the DimensionError class
 */

#ifndef HW3_DIMENSIONERROR_H
#define HW3_DIMENSIONERROR_H

/**
 * @class DimensionError
 * @brief The class which will be thrown if there is a dimension error occurs
 */

/**
 * @fn DimensionError(int d1, int d2)
 * @brief Creates a DimensionError which can be thrown
 * @post A DimensionError is created with dimension 1 d1 and dimension 2 d2
 * @param d1 The first dimension
 * @param d2 The non matching dimension
 */

class DimensionError
{
  public:
    DimensionError(int d1, int d2) : m_dim1(d1), m_dim2(d2) {};

  private:
    int m_dim1, m_dim2;
};


#endif //HW3_DIMENSIONERROR_H
