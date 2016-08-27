//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : SYMMETRICDENSE_MATRIX IMPLEMENTATION for declerations of SymmetricDense_Matrix functions

//PreCondition  : Parameter size is >= 0
//PostCondition : Data and Size are initialized for a new SymmetricDense_Matrix object with a passed size
//Description   : CONSTRUCTOR that takes an integer size as a parameter 
template <typename T>
SymmetricDense_Matrix<T>::SymmetricDense_Matrix(const int setSize)
{
  //Size Check
  if(setSize < 0)
  {
    throw std::invalid_argument("size error");
  }
  m_matrix = new Vector<T>[setSize];
  m_size = setSize;

  //Create "triangle" storage so that symmetric values are stored once
  for(int i = 0; i < setSize; i++)
  {
    Vector<T> temp(setSize - i);
    m_matrix[i] = temp;
  }

  Vector<T> temp(setSize);
  m_augment = temp;
}

//PreCondition  : None 
//PostCondition : Updates the Data and Size of calling SymmetricDense_Matrix 
//                to the values passed by rhs SymmetricDense_Matrix
//Description   : COPY CONSTRUCTOR follows copy and swap paradigm
template <typename T>
SymmetricDense_Matrix<T>::SymmetricDense_Matrix(const SymmetricDense_Matrix<T>& rhs)
{
  m_size = rhs.m_size;
  m_matrix = new Vector<T>[m_size];
  m_augment = rhs.m_augment;
  for(int i = 0; i < m_size; i++)
  {
    m_matrix[i] = rhs.m_matrix[i];
  }
}

//PreCondition  : none
//PostCondition : Dynamic Data array is deleted and pointer set to NULL. Size is updated to 0.
//Description   : DESTRUCTOR to be called when a SymmetricDense_Matrix is removed from memory
template <typename T>
SymmetricDense_Matrix<T>::~SymmetricDense_Matrix()
{
  delete[] m_matrix;
  m_matrix = nullptr;
  m_size = 0;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs SymmetricDense_Matrix need matching sizes
//PostCondition : Returns a SymmetricDense_Matrix copy of the resultant SymmetricDense_Matrix addition.
//Description   : SYMMETRICDENSE_MATRIX ADDITION for adding consecutive terms of 
//                2 Matrices to form a 3rd SymmetricDense_Matrix
template <typename T>
const SymmetricDense_Matrix<T> SymmetricDense_Matrix<T>::operator+(const SymmetricDense_Matrix<T>& rhs) const
{
  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("1matching size error");
  }

  SymmetricDense_Matrix<T> temp(m_size);

  //Use Vector addition for corresponding columns in this and rhs
  for(int i = 0; i < m_size; i++)
  {
    temp.m_matrix[i] = m_matrix[i] + rhs.m_matrix[i];
  }

  return temp;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs SymmetricDense_Matrix need matching sizes (thrown by assignment(+) operator)
//PostCondition : Returns a SymmetricDense_Matrix copy of the resultant SymmetricDense_Matrix difference.
//Description   : SYMMETRICDENSE_MATRIX DIFFERENCE for subtracting consecutive terms of 
//                2 Matrices to form a 3rd SymmetricDense_Matrix
template <typename T>
const SymmetricDense_Matrix<T> SymmetricDense_Matrix<T>::operator-(const SymmetricDense_Matrix<T>& rhs) const
{
  SymmetricDense_Matrix<T> temp(m_size);
  temp = *this + (-rhs);

  return(temp);
}

//PreCondition  : Type T needs integer multiplication(*) and assignment(=) operators defined
//PostCondition : Returns a copy of the calling SymmetricDense_Matrix negated
//Description   : UNARY MINUS gives the negative of a SymmetricDense_Matrix, changing the sign of all terms
template <typename T>
const SymmetricDense_Matrix<T> SymmetricDense_Matrix<T>::operator-() const
{
  SymmetricDense_Matrix<T> temp(m_size);

  for(int i = 0; i < m_size; i++)
  {
    temp.m_matrix[i] = m_matrix[i] * (-1);
  }

  return temp;
}


//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs SymmetricDense_Matrix need matching sizes
//PostCondition : Returns a SymmetricDense_Matrix copy of the resultant 
//                SymmetricDense_Matrix-SymmetricDense_Matrix multiplication.
//Description   : SYMMETRICDENSE_MATRIX-SYMMETRICDENSE_MATRIX MULTIPLICATION for 
//                multiplying two Matrices to form a 3rd SymmetricDense_Matrix
template <typename T>
const Dense_Matrix<T> SymmetricDense_Matrix<T>::operator*(const SymmetricDense_Matrix<T>& rhs) const
{
  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("2matching size error");
  }
  Dense_Matrix<T> temp(m_size);
  Dense_Matrix<T> tempRhs(m_size);

  //Create Dense Matrices for 2 matrices to be multiplied and use Dense Matrix multiplication
  for(int i = 0; i < m_size; i++)
  {
    temp.setRow((*this)[i], i);
    tempRhs.setRow(rhs[i], i);
  }
  temp = temp * tempRhs;

  return temp;
}

//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs Vector need matching sizes
//PostCondition : Returns a Vector copy of the resultant SymmetricDense_Matrix-Vector multiplication.
//Description   : SYMMETRICDENSE_MATRIX-VECTOR MULTIPLICATION for multiplying a Vector 
//                and a SymmetricDense_Matrix to form a Vector
template <typename T>
const Vector<T> SymmetricDense_Matrix<T>::operator*(const Vector<T>& rhs) const
{
  //Size Check
  if(m_size != rhs.getSize())
  {
    throw std::invalid_argument("3matching size error");
  }

  Vector<T> temp(m_size);
  T result;

  for(int i = 0; i < m_size; i++)
  {
    result = (*this)[i] * rhs;
    temp.setElement(result, i);
  }

  return temp;
}

//PreCondition  : Type T needs assignment(=) and multiplication(*) operators defined
//PostCondition : Returns a copy of the resultant SymmetricDense_Matrix after scalar multiplication
//Description   : SYMMETRICDENSE_MATRIX SCALAR MULTIPLICATION multiplies all terms of a 
//                SymmetricDense_Matrix by a given T
template <typename T>
const SymmetricDense_Matrix<T> SymmetricDense_Matrix<T>::operator*(const T& x) const
{
  SymmetricDense_Matrix<T> temp(m_size);

  //Use Vector-scalar multiplication for each Vector in the calling matrix
  for(int i = 0; i < m_size; i++)
  {
    temp.m_matrix[i] = m_matrix[i] * x;
  }

  return temp;
}

//PreCondition  : Parameter index is >= 0 and < m_size
//PostCondition : Returns a Vector from calling SymmetricDense_Matrix at the passed index location
//Description   : BRACKET OPERATOR returns the Vector at row index from calling SymmetricDense_Matrix
//                which is the full row not just the stored half of the SymmetricDense_Matrix
template <typename T>
const Vector<T> SymmetricDense_Matrix<T>::operator[](const int index) const
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("size error");
  }
  Vector<T> temp(m_size);
  T value;

  //Check for first row
  if(index == 0)
  {
    temp = m_matrix[0];
  }
  //If not first row we must add symmetric data that we do not store
  else
  {
    //Put Symmetric data into temp
    for(int i = 0; i < index; i++)
    {
      value = m_matrix[i][index - i];
      temp.setElement(value, i);
    }

    //Put stored data into temp
    for(int i = 0; i < m_size - index; i++)
    {
      value = m_matrix[index][i];
      temp.setElement(value, index + i);
    }
  }

  return temp;
}

//PreCondition  : Type T has assignment(=) defined
//PostCondition : Returns a constructed SymmetricDense_Matrix with rhs data and size
//Description   : ASSIGNMENT OPERATOR uses copy and swap idiom for rhs 
//                SymmetricDense_Matrix be copied into the calling SymmetricDense_Matrix
template <typename T>
const SymmetricDense_Matrix<T>& SymmetricDense_Matrix<T>::operator=(SymmetricDense_Matrix<T> rhs)
{
  std::swap(m_matrix, rhs.m_matrix);
  std::swap(m_size, rhs.m_size);
  std::swap(m_augment, rhs.m_augment);

  return *this;
}

//PreCondition  : Type T has insertion(<<) operator defined
//PostCondition : Returns the outstream parameter containing the terms of rhs Vector
//Description   : SYMMETRICDENSE_MATRIX INSERTION OPERATOR outputs the rows of calling SymmetricDense_Matrix
template <typename T>
std::ostream& operator<< (std::ostream& out, const SymmetricDense_Matrix<T>& rhs)
{
  std::setprecision(6);
  for(int i = 0; i < rhs.m_size; i++)
  {
    for(int j = 0; j < rhs.m_size; j++)
    {
      out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<rhs[i][j];
    }
    out<<std::endl;      
  }

  return out;
}


//PreCondition  : Type T has extraction(>>) and assignment(=) operators defined. Instream has m_size number of data
//PostCondition : Returns the instream parameter and inputs data into rhs SymmetricDense_Matrix row Vectors
//Description   : EXTRACTION OPERATOR USED FOR A DIFFERENT INPUT FORMAT THAN HW6 REQUIRES
template <typename T>
std::istream& operator>> (std::istream& in, SymmetricDense_Matrix<T>& rhs)
{
  T temp;
  for(int i = 0; i < rhs.m_size; i++)
  {
    for(int j = 0; j < rhs.m_size - i; j++)
    {
      in>>temp;
      rhs.m_matrix[i].setElement(temp, j);
    }
  }
  return in;
}

//PreCondition  : none
//PostCondition : Returns the size of calling SymmetricDense_Matrix
//Description   : SIZE ACCESSOR allows indirect access to the size of the calling SymmetricDense_Matrix 
template <typename T>
int SymmetricDense_Matrix<T>::getSize() const
{
  return m_size;
}

//PreCondition  : none
//PostCondition : Returns augment Vector member
//Description   : AUGMENT ACCESSOR allows indirect access to the augment of the calling SymmetricDense_Matrix
template <typename T>
Vector<T> SymmetricDense_Matrix<T>::getAugment() const
{
  return m_augment;
}
/*

*****IF NEEDED LATER WILL UPDATE TO CHECK THAT SYMMETRY IS MAINTAINED*****

//PreCondition  : Type T has assignment(=) operator defined
//                Index is >= 0 and < size. 
//PostCondition : Updates a row of calling SymmetricDense_Matrix from passed row parameter
//Description   : ROW MUTATOR allows the row of a Matrix to be set
template <typename T>
void SymmetricDense_Matrix<T>::setRow(const Vector<T> row, const int index)
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("size error");
  }

  m_matrix[index] = row;
  return;
}
*/
//PreCondition  : Parameter size is >= 0 and must equal n (number of columns) to maintain square matrices
//PostCondition : Updates the size of calling SymmetricDense_Matrix from passed size parameter
//Description   : SIZE MUTATOR allows the size of the calling SymmetricDense_Matrix to be set
template <typename T>
void SymmetricDense_Matrix<T>::setSize(const int size)
{
  //Size Check
  if(size < 0)
  {
    throw std::invalid_argument("size error");
  }
  m_size = size;

  return;
}

//PreCondition  : Type T has assignment(=) operator defined 
//                Parameter index is >= 0 and < size. 
//PostCondition : Updates an element of the augment vector of the calling 
//                SymmetricDense_Matrix at index parameter location
//Description   : AUGMENT MUTATOR allows for elements of the augment Vector to be set 
template <typename T>
void SymmetricDense_Matrix<T>::setAugment(const T element, const int index)
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("size error");
  }
  m_augment.setElement(element, index);

  return;
}

//PreCondition  : Type T has assignment(=) defined
//PostCondition : Returns a SymmetricDense_Matrix copy of the resultant transpose operation
//Description   : TRANSPOSE to convert the rows of a SymmetricDense_Matrix to the columns... which is the smae matrix
template <typename T>
const SymmetricDense_Matrix<T> SymmetricDense_Matrix<T>::transpose() const
{
  return *this;
}

//PreCondition  : none
//PostCondition : The calling Matrix is assigned from a created Matrix2
//Description   : Tests all the functionality of a particular Matrix class
template <typename T>
void SymmetricDense_Matrix<T>::MatrixTest(const Vector<T>& testvector)
{
  SymmetricDense_Matrix<T> matrix2(m_size);
  matrix2 = (*this);
  matrix2.m_matrix[0] = testvector;

  std::cout<<"Output test: Matrix1"<<std::endl;
  std::cout<<(*this)<<std::endl;
  std::cout<<"Output test: Matrix2"<<std::endl;
  std::cout<<matrix2<<std::endl;
  std::cout<<"Addition test: Matrix1 + Matrix2"<<std::endl;
  std::cout<<(*this) + matrix2<<std::endl;
  std::cout<<"Subtraction test: Matrix1 - Matrix2"<<std::endl;
  std::cout<<(*this) - matrix2<<std::endl;
  std::cout<<"Unary- test: -Matrix1"<<std::endl;
  std::cout<<-(*this)<<std::endl;
  std::cout<<"Matrix* test: Matrix1 * Matrix2"<<std::endl;
  std::cout<<(*this) * matrix2<<std::endl;
  std::cout<<"Scalar* test1: 4 * Matrix1"<<std::endl;
  std::cout<<4 * (*this)<<std::endl;
  std::cout<<"Scalar* test2: Matrix1 * 4"<<std::endl;
  std::cout<<(*this) * 4<<std::endl;
  std::cout<<"Vector* test: Matrix1 * testvector"<<std::endl;
  std::cout<<(*this) * testvector<<std::endl;
  std::cout<<"Bracket test: Matrix1[1]"<<std::endl;
  std::cout<<(*this)[1]<<std::endl;
  std::cout<<"Assignment test: Matrix1 = Matrix2"<<std::endl;
  (*this) = matrix2;
  std::cout<<(*this)<<std::endl;
  return;
}