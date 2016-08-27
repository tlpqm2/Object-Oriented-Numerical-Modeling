//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : QR DECOMPOSITION IMPLEMENTATION .hpp containing template QRdecomp functions

//PreCondition  : size is >= 0
//PostCondition : m_R has size number of 0 vectors pushed
//Description   : DEFAULT CONSTRUCTOR is the only constructor for QRdecomp. Initializing m_R allows
//                setting the first k values in Rk since size-k terms following that are 0.
template <typename T>
QRdecomp<T>::QRdecomp(const int size)
{
  Dense_Matrix<T> temp(size);
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      temp.setData(0, i, j);
    }
  }
  m_R = temp;
  m_Q = temp;
}

//PreCondition  : Error is thrown if r(k,k) is 0. 
//                Matrix A is a linearly independent set of Vectors              
//PostCondition : m_Q will have size number of Vectors pushed. m_R has k elements in Vector R(k) 
//                modified to produce a special matrix.
//Description   : FUNCTION RESOLUTION is the main purpose of QRdecomp class. It performs the algorithm 
//                to produce 2 matrices Q and R.
template <typename T>
void QRdecomp<T>::operator()(const Dense_Matrix<T>& A) 
{
  int size = A.getSize();
  int loopK = 1;
  int loopI = 0;
  T tempTerm = 0;
  Vector<T> tempVector(size);
  Vector<T> reset(size);
  for(int i = 0; i < size; i++)
  {
    reset.setElement(0, i);
  }

  //check for nonempty matrix
  if(size != 0)
  {
    T norm = A.getCol(0).twoNorm();

    //get R1
    m_R.setData(norm, 0, 0);

    if(norm == 0)
    {
      throw std::domain_error("Don't divide by 0");
    }
    //get Q1
    tempVector = (1/(norm)) * A.getCol(0);
    m_Q.setCol(tempVector, 0);

    //Iterate
    for(int i = 0; i < size - 1; i++)
    {
      //Horizontal iteration
      for(int k = loopK; k < size; k++)
      {
        tempTerm = A.getCol(k) * m_Q.getCol(loopI);
        m_R.setData(tempTerm, loopI, k);
      }
      tempVector = reset;

      //Find r(n,n)
      for(int j = 0; j < loopK; j++)
      {
        tempVector = tempVector + m_R[j][loopK] * m_Q.getCol(j);
      }
      tempVector = A.getCol(loopK) - tempVector;
      m_R.setData(tempVector.twoNorm(), loopK, loopK);

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

//PreCondition  : none
//PostCondition : Returns Dense_Matrix Q
//Description   : M_Q ACCESSOR allows for indirect private member access to the Q matrix
template <typename T>
const Dense_Matrix<T> QRdecomp<T>::getQ() const
{
  //check Q has been set
  return m_Q;
}

//PreCondition  : none
//PostCondition : Returns Dense_Matrix R 
//Description   : M_R ACCESSOR allows for indirect private member access to the R matrix
template <typename T>
const Dense_Matrix<T> QRdecomp<T>::getR() const
{
  //check r has been set
  return m_R;
}