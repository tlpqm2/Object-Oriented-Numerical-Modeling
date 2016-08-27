/**
 * @file MatrixBase.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief QR DECOMPOSITION IMPLEMENTATION .hpp containing template QRdecomp functions
 */

template <typename T>
QRdecomp<T>::QRdecomp(const int size)
{
  RectangularMatrix<T> temp(size);
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      temp[i][j];
    }
  }
  m_R = temp;
  m_Q = temp;
}

template <typename T>
void QRdecomp<T>::operator()(RectangularMatrix<T>& A) 
{
  int size = A.getRows();
  int loopK = 1;
  int loopI = 0;
  T tempTerm = 0;
  Vector<T> tempVector(size);
  Vector<T> temp2(size);
  Vector<T> reset(size);
  for(int i = 0; i < size; i++)
  {
    reset[i] = 0;
  }

  //check for nonempty matrix
  if(size != 0)
  {
    temp2 = A.getCol(0);
    T tempnorm = norm(temp2);

    //get R1
    m_R[0][0] = tempnorm;

    if(tempnorm == 0)
    {
      throw std::domain_error("Don't divide by 0");
    }
    //get Q1
    tempVector = A.getCol(0);
    tempVector = tempVector * (1/(tempnorm));
    m_Q.setCol(tempVector, 0);

    //Iterate
    for(int i = 0; i < size - 1; i++)
    {
      //Horizontal iteration
      for(int k = loopK; k < size; k++)
      {
        tempTerm = A.getCol(k) * m_Q.getCol(loopI);
        m_R[loopI][k] = tempTerm;
      }
      tempVector = reset;

      //Find r(n,n)
      for(int j = 0; j < loopK; j++)
      {
        tempVector = tempVector + m_R[j][loopK] * m_Q.getCol(j);
      }
      tempVector = A.getCol(loopK) - tempVector;
      m_R[loopK][loopK] = norm(tempVector);

      if((m_R[loopK][loopK]) == 0)
      {
        throw std::domain_error("Don't divide by 0");
      }

      //Find Q(n)
      tempVector = tempVector * (1/m_R[loopK][loopK]);
      m_Q.setCol(tempVector, i + 1);
      loopI++;
      loopK++;
    }
  }
  
  return; 
}

template <typename T>
const RectangularMatrix<T> QRdecomp<T>::getQ() const
{
  //check Q has been set
  return m_Q;
}

template <typename T>
const RectangularMatrix<T> QRdecomp<T>::getR() const
{
  //check r has been set
  return m_R;
}