//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : LOWERTRIANGULAR_MATRIX IMPLEMENTATION for declerations of LowerTriangular_Matrix functions

//PreCondition  : Parameter size is >= 0
//PostCondition : Data and Size are initialized for a new LowerTriangular_Matrix object with a passed size
//Description   : CONSTRUCTOR that takes an integer size as a parameter 
template <typename T>
LowerTriangular_Matrix<T>::LowerTriangular_Matrix(const int setSize)
{
  //Size Check
  if(setSize < 0)
  {
    throw std::invalid_argument("size error");
  }
  m_matrix = new Vector<T>[setSize];
  m_size = setSize;

  //Create "triangle" storage
  for(int i = 0; i < setSize; i++)
  {
    Vector<T> temp(i + 1);
    m_matrix[i] = temp;
  }

  Vector<T> temp(setSize);
  m_augment = temp;
}

//PreCondition  : None 
//PostCondition : Updates the Data and Size of calling LowerTriangular_Matrix to the values passed by rhs LowerTriangular_Matrix
//Description   : COPY CONSTRUCTOR follows copy and swap paradigm
template <typename T>
LowerTriangular_Matrix<T>::LowerTriangular_Matrix(const LowerTriangular_Matrix<T>& rhs)
{
  m_size = rhs.m_size;
  m_matrix = new Vector<T>[m_size];
  m_augment = rhs.m_augment;
  m_augment.setSize(m_size);
  for(int i = 0; i < m_size; i++)
  {
    m_matrix[i] = rhs.m_matrix[i];
  }
}

//PreCondition  : none
//PostCondition : Dynamic Data array is deleted and pointer set to NULL. Size is updated to 0.
//Description   : DESTRUCTOR to be called when a LowerTriangular_Matrix is removed from memory
template <typename T>
LowerTriangular_Matrix<T>::~LowerTriangular_Matrix()
{
  delete[] m_matrix;
  m_matrix = nullptr;
  m_size = 0;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs LowerTriangular_Matrix need matching sizes
//PostCondition : Returns a LowerTriangular_Matrix copy of the resultant LowerTriangular_Matrix addition.
//Description   : LOWERTRIANGULAR_MATRIX ADDITION for adding consecutive terms of 2 Matrices 
//                to form a 3rd LowerTriangular_Matrix
template <typename T>
const LowerTriangular_Matrix<T> LowerTriangular_Matrix<T>::operator+(const LowerTriangular_Matrix<T>& rhs) const
{
  LowerTriangular_Matrix<T> temp(m_size);

  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("1matching size error");
  }

  //Use Vector addition for corresponding rows in this and rhs
  for(int i = 0; i < m_size; i++)
  {
    temp.m_matrix[i] = m_matrix[i] + rhs.m_matrix[i];
  }

  return temp;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs LowerTriangular_Matrix need matching sizes (thrown by assignment(+) operator)
//PostCondition : Returns a LowerTriangular_Matrix copy of the resultant LowerTriangular_Matrix difference.
//Description   : LOWERTRIANGULAR_MATRIX DIFFERENCE for subtracting consecutive terms of 
//                2 Matrices to form a 3rd LowerTriangular_Matrix
template <typename T>
const LowerTriangular_Matrix<T> LowerTriangular_Matrix<T>::operator-(const LowerTriangular_Matrix<T>& rhs) const
{
  LowerTriangular_Matrix<T> temp(m_size);
  temp = *this + (-rhs);

  return(temp);
}

//PreCondition  : Type T needs integer multiplication(*) and assignment(=) operators defined
//PostCondition : Returns a copy of the calling LowerTriangular_Matrix negated
//Description   : UNARY MINUS gives the negative of a LowerTriangular_Matrix, changing the sign of all terms
template <typename T>
const LowerTriangular_Matrix<T> LowerTriangular_Matrix<T>::operator-() const
{
  LowerTriangular_Matrix<T> temp(m_size);

  for(int i = 0; i < m_size; i++)
  {
    temp.m_matrix[i] = m_matrix[i] * (-1);
  }

  return temp;
}


//PreCondition  : Type T needs multiplication(*), addition(+) and assignment(=) operators defined
//                Calling object and rhs LowerTriangular_Matrix need matching sizes
//PostCondition : Returns a LowerTriangular_Matrix copy of the resultant 
//                LowerTriangular_Matrix-LowerTriangular_Matrix multiplication.
//Description   : LOWERTRIANGULAR_MATRIX-LOWERTRIANGULAR_MATRIX MULTIPLICATION for multiplying 
//                two Matrices to form a 3rd LowerTriangular_Matrix
template <typename T>
const LowerTriangular_Matrix<T> LowerTriangular_Matrix<T>::operator*(const LowerTriangular_Matrix<T>& rhs) const
{
  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("2matching size error");
  }
  LowerTriangular_Matrix<T> temp(m_size);
  Vector<T> tempVector(m_size);
  T result = 0;

  for(int i = 0; i < m_size; i++)
  {
    for(int j = 0; j < m_size; j++)
    {
      tempVector.setElement(rhs[j][i], j);
    }
    for(int j = 0; j < m_size; j++)
    {
      for(int k = 0; k < j + 1; k++)
      {
        result += m_matrix[j][k] * tempVector[k];
      }
      temp.m_matrix[j].setElement(result, i);
      result = 0;
    } 
  }

  return temp;
}

//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs Vector need matching sizes
//PostCondition : Returns a Vector copy of the resultant LowerTriangular_Matrix-Vector multiplication.
//Description   : LOWERTRIANGULAR_MATRIX-VECTOR MULTIPLICATION for multiplying a Vector 
//                and a LowerTriangular_Matrix to form a Vector
template <typename T>
const Vector<T> LowerTriangular_Matrix<T>::operator*(const Vector<T>& rhs) const
{
  //Size Check
  if(m_size != rhs.getSize())
  {
    throw std::invalid_argument("3matching size error");
  }

  Vector<T> temp(m_size);
  T result = 0;
  for(int i = 0; i < m_size; i++)
  {
    for(int j = 0; j < i + 1; j++)
    {
      result += m_matrix[i][j] * rhs[j];
    }
    temp.setElement(result, i);
    result = 0;
  }

  return temp;
}

//PreCondition  : Type T needs assignment(=) and multiplication(*) operators defined
//PostCondition : Returns a copy of the resultant LowerTriangular_Matrix after scalar multiplication
//Description   : LOWERTRIANGULAR_MATRIX SCALAR MULTIPLICATION multiplies all terms 
//                of a LowerTriangular_Matrix by a given T
template <typename T>
const LowerTriangular_Matrix<T> LowerTriangular_Matrix<T>::operator*(const T& x) const
{
  LowerTriangular_Matrix<T> temp(m_size);

  //Use Vector-scalar multiplication for each Vector in this
  for(int i = 0; i < m_size; i++)
  {
    temp.m_matrix[i] = m_matrix[i] * x;
  }

  return temp;
}

//PreCondition  : Parameter index is >= 0 and < m_size
//PostCondition : Returns a Vector from calling LowerTriangular_Matrix at the passed index location
//Description   : BRACKET OPERATOR returns the Vector at row index from calling LowerTriangular_Matrix
template <typename T>
const Vector<T> LowerTriangular_Matrix<T>::operator[](const int index) const
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("size error");
  }

  Vector<T> temp(m_size);
  //Check for last row
  if(index == (m_size - 1))
  {
    temp = m_matrix[m_size - 1];
  }
  else
  {
    //Set values
    for(int i = 0; i < index + 1; i++)
    {
      temp.setElement(m_matrix[index][i], i);
    }
    //Set zeroes
    for(int i = index + 1; i < m_size; i++)
    {
      temp.setElement(0, i);
    }
  }

  return temp;
}

//PreCondition  : Type T has assignment(=) defined
//PostCondition : Returns a constructed LowerTriangular_Matrix with rhs data and size
//Description   : ASSIGNMENT OPERATOR uses copy and swap idiom for rhs LowerTriangular_Matrix be copied 
//                into the calling LowerTriangular_Matrix
template <typename T>
const LowerTriangular_Matrix<T>& LowerTriangular_Matrix<T>::operator=(LowerTriangular_Matrix<T> rhs)
{
  std::swap(m_matrix, rhs.m_matrix);
  std::swap(m_size, rhs.m_size);
  std::swap(m_augment, rhs.m_augment);

  return *this;
}

//PreCondition  : Type T has insertion(<<) operator defined
//PostCondition : Returns the outstream parameter containing the terms of rhs Vector
//Description   : LOWERTRIANGULAR _MATRIX INSERTION OPERATOR outputs the rows of calling LowerTriangular_Matrix
template <typename T>
std::ostream& operator<< (std::ostream& out, const LowerTriangular_Matrix<T>& rhs)
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
//PostCondition : Returns the instream parameter and inputs data into rhs LowerTriangular_Matrix row Vectors
//Description   : EXTRACTION OPERATOR USED FOR A DIFFERENT INPUT FORMAT THAN HW6 REQUIRES
template <typename T>
std::istream& operator>> (std::istream& in, LowerTriangular_Matrix<T>& rhs)
{
  T temp;
  for(int i = 0; i < rhs.m_size; i++)
  {
    for(int j = 0; j < i + 1; j++)
    {
      in>>temp;
      rhs.m_matrix[i].setElement(temp, j);
    }
  }
  return in;
}

//PreCondition  : none
//PostCondition : Returns the size of calling LowerTriangular_Matrix
//Description   : SIZE ACCESSOR allows indirect access to the size of the calling LowerTriangular_Matrix 
template <typename T>
int LowerTriangular_Matrix<T>::getSize() const
{
  return m_size;
}

//PreCondition  : none
//PostCondition : Returns augment Vector member
//Description   : AUGMENT ACCESSOR allows indirect access to the augment of the calling LowerTriangular_Matrix
template <typename T>
Vector<T> LowerTriangular_Matrix<T>::getAugment() const
{
  return m_augment;
}

//PreCondition  : Type T has assignment(=) operator defined
//                Index is >= 0 and < size. 
//PostCondition : Updates a data of calling LowerTriangular_Matrix from passed row parameter
//Description   : DATA MUTATOR allows indirect access to set data of calling Matrix
template <typename T>
void LowerTriangular_Matrix<T>::setData(const T element, const int row, const int col)
{
  m_matrix[row].setElement(element, col);
  return;
}

//PreCondition  : Type T has assignment(=) operator defined
//                Index is >= 0 and < size. 
//PostCondition : Updates a row of calling LowerTriangular_Matrix from passed row parameter
//Description   : ROW MUTATOR allows the row of a Matrix to be set, but does not require the 0's to be included
template <typename T>
void LowerTriangular_Matrix<T>::setRow(const Vector<T> row, const int index)
{
  //Size Check
  if(index != (row.getSize() + 1))
  {
    throw std::invalid_argument("99size error");
  }

  m_matrix[index] = row;

  return;
}

//PreCondition  : Parameter size is >= 0 and must equal n (number of columns) to maintain square matrices
//PostCondition : Updates the size of calling LowerTriangular_Matrix from passed size parameter
//Description   : SIZE MUTATOR allows the size of the calling LowerTriangular_Matrix to be set
template <typename T>
void LowerTriangular_Matrix<T>::setSize(const int size)
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
//                LowerTriangular_Matrix at index parameter location
//Description   : AUGMENT MUTATOR allows for elements of the augment Vector to be set 
template <typename T>
void LowerTriangular_Matrix<T>::setAugment(const T element, const int index)
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
//PostCondition : Returns a LowerTriangular_Matrix copy of the resultant transpose operation
//Description   : TRANSPOSE to convert the rows of a LowerTriangular_Matrix to the columns
//                which creates an UpperTriangular_Matrix
template <typename T>
const UpperTriangular_Matrix<T> LowerTriangular_Matrix<T>::transpose() const
{
  UpperTriangular_Matrix<T> temp(m_size);

  for(int i = 0; i < m_size; i++)
  {
    Vector<T> tempVector(m_size - i);
    for(int j = i; j < m_size; j++)
    {
      tempVector.setElement(m_matrix[j][i], j);
    }
    temp.setRow(tempVector, i);
  }
  return temp;
}

//PreCondition  : none
//PostCondition : The calling Matrix is assigned from a created Matrix2
//Description   : Tests all the functionality of a particular Matrix class
template <typename T>
void LowerTriangular_Matrix<T>::MatrixTest(const Vector<T>& testvector)
{
  LowerTriangular_Matrix<T> matrix2(m_size);
  matrix2 = (*this);
  matrix2.m_matrix[m_size - 1] = testvector;

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
