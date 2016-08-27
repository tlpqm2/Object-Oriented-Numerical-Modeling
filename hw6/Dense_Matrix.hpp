//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : DENSE_MATRIX IMPLEMENTATION for declerations of Dense_Matrix functions

//PreCondition  : none
//PostCondition : Data and Size are initialized for a new Dense_Matrix object with a passed size
//Description   : CONSTRUCTOR that takes an integer size as a parameter 
template <typename T>
Dense_Matrix<T>::Dense_Matrix()
{
  m_matrix = new Vector<T>[DEFAULT_SIZE];
  m_size = DEFAULT_SIZE;

  Vector<T> temp(DEFAULT_SIZE);
  m_augment = temp;
}

//PreCondition  : Parameter size is >= 0
//PostCondition : Data and Size are initialized for a new Dense_Matrix object with a passed size
//Description   : CONSTRUCTOR that takes an integer size as a parameter 
template <typename T>
Dense_Matrix<T>::Dense_Matrix(const int setSize)
{
  //Size Check
  if(setSize < 0)
  {
    throw std::invalid_argument("size error");
  }
  m_matrix = new Vector<T>[setSize];
  m_size = setSize;

  Vector<T> temp(setSize);
  for(int i = 0; i < m_size; i++)
  {
    m_matrix[i] = temp;
  }

  m_augment = temp;
}

//PreCondition  : None 
//PostCondition : Updates the Data and Size of calling Dense_Matrix to the values passed by rhs Dense_Matrix
//Description   : COPY CONSTRUCTOR follows copy and swap paradigm
template <typename T>
Dense_Matrix<T>::Dense_Matrix(const Dense_Matrix<T>& rhs)
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
//Description   : DESTRUCTOR to be called when a Dense_Matrix is removed from memory
template <typename T>
Dense_Matrix<T>::~Dense_Matrix()
{
  delete[] m_matrix;
  m_matrix = nullptr;
  m_size = 0;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs Dense_Matrix need matching sizes
//PostCondition : Returns a Dense_Matrix copy of the resultant Dense_Matrix addition.
//Description   : Dense_MATRIX ADDITION for adding consecutive terms of 2 Matrices to form a 3rd Dense_Matrix
template <typename T>
const Dense_Matrix<T> Dense_Matrix<T>::operator+(const Dense_Matrix<T>& rhs) const
{
  Dense_Matrix<T> temp(m_size);

  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("1matching size error");
  }

  //Use Vector addition for corresponding columns in this and rhs
  for(int i = 0; i < m_size; i++)
  {
    temp.m_matrix[i] = m_matrix[i] + rhs.m_matrix[i];
  }

  return temp;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs Dense_Matrix need matching sizes (thrown by assignment(+) operator)
//PostCondition : Returns a Dense_Matrix copy of the resultant Dense_Matrix difference.
//Description   : DENSE_MATRIX DIFFERENCE for subtracting consecutive terms of 2 Matrices to form a 3rd Dense_Matrix
template <typename T>
const Dense_Matrix<T> Dense_Matrix<T>::operator-(const Dense_Matrix<T>& rhs) const
{
  Dense_Matrix<T> temp(m_size);
  temp = *this + (-rhs);

  return(temp);
}

//PreCondition  : Type T needs integer multiplication(*) and assignment(=) operators defined
//PostCondition : Returns a copy of the calling Dense_Matrix negated
//Description   : UNARY MINUS gives the negative of a Dense_Matrix, changing the sign of all terms
template <typename T>
const Dense_Matrix<T> Dense_Matrix<T>::operator-() const
{
  Dense_Matrix<T> temp(m_size);

  for(int i = 0; i < m_size; i++)
  {
    temp.m_matrix[i] = m_matrix[i] * (-1);
  }

  return temp;
}


//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs Dense_Matrix need matching sizes
//PostCondition : Returns a Dense_Matrix copy of the resultant Dense_Matrix-Dense_Matrix multiplication.
//Description   : Dense_MATRIX-Dense_MATRIX MULTIPLICATION for multiplying two Matrices to form a 3rd Dense_Matrix
template <typename T>
const Dense_Matrix<T> Dense_Matrix<T>::operator*(const Dense_Matrix<T>& rhs) const
{
  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("2matching size error");
  }
  Dense_Matrix<T> temp(m_size);
  Vector<T> column(m_size);

  for(int i = 0; i < m_size; i++)
  {
    for(int j = 0; j < m_size; j++)
    {
      column.setElement(rhs.m_matrix[j][i], j);
    }
    for(int j = 0; j < m_size; j++)
    {
      temp.m_matrix[j].setElement(column * m_matrix[j], i);
    }
  }

  return temp;
}

//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs Vector need matching sizes
//PostCondition : Returns a Vector copy of the resultant Dense_Matrix-Vector multiplication.
//Description   : Dense_MATRIX-VECTOR MULTIPLICATION for multiplying a Vector and a Dense_Matrix to form a Vector
template <typename T>
const Vector<T> Dense_Matrix<T>::operator*(const Vector<T>& rhs) const
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
    result = m_matrix[i] * rhs;
    temp.setElement(result,i);
  }

  return temp;
}

//PreCondition  : Type T needs assignment(=) and multiplication(*) operators defined
//PostCondition : Returns a copy of the resultant Dense_Matrix after scalar multiplication
//Description   : Dense_MATRIX SCALAR MULTIPLICATION multiplies all terms of a Dense_Matrix by a given T
template <typename T>
const Dense_Matrix<T> Dense_Matrix<T>::operator*(const T& x) const
{
  Dense_Matrix<T> temp(m_size);

  //Use Vector-scalar multiplication for each Vector in this
  for(int i = 0; i < m_size; i++)
  {
    temp.m_matrix[i] = m_matrix[i] * x;
  }

  return temp;
}

//PreCondition  : Parameter index is >= 0 and < m_size
//PostCondition : Returns a Vector from calling Dense_Matrix at the passed index location
//Description   : BRACKET OPERATOR returns the Vector at row index from calling Dense_Matrix
template <typename T>
const Vector<T> Dense_Matrix<T>::operator[](const int index) const
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("size error");
  }

  return m_matrix[index];
}

//PreCondition  : Type T has assignment(=) defined
//PostCondition : Returns a constructed Dense_Matrix with rhs data and size
//Description   : ASSIGNMENT OPERATOR uses copy and swap idiom for rhs Dense_Matrix 
//                to be copied into the calling Dense_Matrix
template <typename T>
const Dense_Matrix<T>& Dense_Matrix<T>::operator=(Dense_Matrix<T> rhs)
{
  std::swap(m_matrix, rhs.m_matrix);
  std::swap(m_size, rhs.m_size);
  std::swap(m_augment, rhs.m_augment);

  return *this;
}

//PreCondition  : Type T has insertion(<<) operator defined
//PostCondition : Returns the outstream parameter containing the terms of rhs Vector
//Description   : Dense_MATRIX INSERTION OPERATOR outputs the rows of calling Dense_Matrix
template <typename T>
std::ostream& operator<< (std::ostream& out, const Dense_Matrix<T>& rhs)
{
  std::setprecision(6);
  for(int i = 0; i < rhs.m_size; i++)
  {
    for(int j = 0; j < rhs.m_size; j++)
    {
      out<<std::setw(20)<<std::fixed<<std::setprecision(8)<<rhs[i][j];
    }
    out<<std::endl;      
  }

  return out;
}
/*
//PreCondition  : Type T has extraction(>>) and assignment(=) operators defined. 
//PostCondition : Returns the instream parameter and inputs data into rhs Dense_Matrix row Vectors
//Description   : EXTRACTION OPERATOR for creating an augmented Vandermonde Dense_Matrix 
//                to be solved with Gauss Elimination
template <typename T>
std::istream& operator>> (std::istream& in, Dense_Matrix<T>& rhs)
{
  T x,y;
  T temp;
  for(int i = 0; i < rhs.m_size; i++)
  {
    in>>x>>y;
    for(int j = 0; j < rhs.m_size; j++)
    {
      temp = x;
      temp = pow(temp,j);
      rhs.m_matrix[i].setElement(temp,j);
    }
    rhs.m_augment.setElement(y, i);
  }
  
  return in;
}
*/

//PreCondition  : Type T has extraction(>>) and assignment(=) operators defined. 
//PostCondition : Returns the instream parameter and inputs data into rhs Dense_Matrix row Vectors
//Description   : EXTRACTION OPERATOR to fill the Matrix data from file
template <typename T>
std::istream& operator>> (std::istream& in, Dense_Matrix<T>& rhs)
{
  T data;
  Vector<T> temp(rhs.m_size);
  for(int i = 0; i < rhs.m_size; i++)
  {
    for(int j = 0; j < rhs.m_size; j++)
    {
      in >> data;
      temp.setElement(data, j);
    }
    rhs.m_matrix[i] = temp;
  }

  return in;
}
//PreCondition  : Type T has extraction(>>) and assignment(=) operators defined. Instream has m_size number of data
//PostCondition : Returns the instream parameter and inputs data into rhs Dense_Matrix row Vectors
//Description   : EXTRACTION OPERATOR for inputting a square matrix
template <typename T>
std::istream& operator>> (std::istream& in, const Dense_Matrix<T>& rhs)
{
  T temp;
  for(int i = 0; i < rhs.m_size; i++)
  {
    for(int j = 0; j < rhs.m_size; j++)
    {
      in>>temp;
      rhs.m_matrix[i].setElement(temp, j);
    }
  }
  return in;
}

//PreCondition  : none
//PostCondition : Returns the size of calling Dense_Matrix
//Description   : SIZE ACCESSOR allows indirect access to the size of the calling Dense_Matrix 
template <typename T>
int Dense_Matrix<T>::getSize() const
{
  return m_size;
}

//PreCondition  : none
//PostCondition : Returns augment Vector member
//Description   : AUGMENT ACCESSOR allows indirect access to the augment of the calling Dense_Matrix
template <typename T>
Vector<T> Dense_Matrix<T>::getAugment() const
{
  return m_augment;
}

//PreCondition  : none
//PostCondition : Returns main diagonal Vector 
//Description   : DIAGONAL ACCESSOR allows indirect access to the main diagonal of the calling Dense_Matrix
template <typename T>
Vector<T> Dense_Matrix<T>::getDiagonal() const
{
  Vector<T> diagonal(m_size);
  for(int i = 0; i < m_size; i++)
  {
    diagonal.setElement(m_matrix[i][i], i);
  }

  return diagonal;
}

//PreCondition  : none
//PostCondition : Returns augment Vector member
//Description   : COLUMN ACCESSOR allows indirect access to the columns of the calling Dense_Matrix
template <typename T>
Vector<T> Dense_Matrix<T>::getCol(const int col) const
{
  Vector<T> temp(m_size);
  for(int i = 0; i < m_size; i++)
  {
    temp.setElement(m_matrix[i][col], i);
  }

  return temp;
}

//PreCondition  : Type T has assignment(=) operator defined
//                Index is >= 0 and < size. 
//PostCondition : Updates a data of calling Dense_Matrix from passed data parameter
//Description   : DATA MUTATOR allows the data of a Matrix to be set
template <typename T>
void Dense_Matrix<T>::setData(const T element, const int row, const int col)
{
  m_matrix[row].setElement(element, col);

  return;
}

//PreCondition  : Type T has assignment(=) operator defined
//                Index is >= 0 and < size. 
//PostCondition : Updates a row of calling Dense_Matrix from passed row parameter
//Description   : ROW MUTATOR allows the row of a Matrix to be set
template <typename T>
void Dense_Matrix<T>::setRow(const Vector<T> row, const int index)
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("size error");
  }

  m_matrix[index] = row;

  return;
}

//PreCondition  : Type T has assignment(=) operator defined
//                Index is >= 0 and < size. 
//PostCondition : Updates a row of calling Dense_Matrix from passed row parameter
//Description   : COL MUTATOR allows the column of a Matrix to be set
template <typename T>
void Dense_Matrix<T>::setCol(const Vector<T> col, const int index)
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("size error");
  }

  for(int i = 0; i < m_size; i++)
  {
    m_matrix[i].setElement(col[i], index);
  }

  return;
}

//PreCondition  : Parameter size is >= 0 and must equal n (number of columns) to maintain square matrices
//PostCondition : Updates the size of calling Dense_Matrix from passed size parameter
//Description   : SIZE MUTATOR allows the size of the calling Dense_Matrix to be set
template <typename T>
void Dense_Matrix<T>::setSize(const int size)
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
//PostCondition : Updates an element of the augment vector of the calling Dense_Matrix at index parameter location
//Description   : AUGMENT MUTATOR allows for elements of the augment Vector to be set 
template <typename T>
void Dense_Matrix<T>::setAugment(const T element, const int index)
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
//PostCondition : Returns a Dense_Matrix copy of the resultant transpose operation
//Description   : TRANSPOSE to convert the rows of a Dense_Matrix to the columns
template <typename T>
const Dense_Matrix<T> Dense_Matrix<T>::transpose() const
{
  Dense_Matrix<T> temp(m_size);

  for(int i = 0; i < m_size; i++)
  {
    for(int j = 0; j < m_size; j++)
    {
      temp.m_matrix[j].setElement(m_matrix[i][j], i);
    }
  }

  return temp;
}

//PreCondition  : none
//PostCondition : The calling Matrix is assigned from a created Matrix2
//Description   : Tests all the functionality of a particular Matrix class
template <typename T>
void Dense_Matrix<T>::MatrixTest(const Vector<T>& testvector)
{
  Dense_Matrix<T> matrix2(m_size);
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

