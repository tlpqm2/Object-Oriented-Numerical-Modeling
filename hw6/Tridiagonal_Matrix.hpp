//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : TRIDIAGONAL_MATRIX IMPLEMENTATION containing template Vector class

//PreCondition  : Parameter setSize is >= 0
//PostCondition : Data and Size are initialized for a new Tridiagonal_Matrix object with a passed size
//Description   : CONSTRUCTOR that takes an integer size as a parameter 
template <typename T>
Tridiagonal_Matrix<T>::Tridiagonal_Matrix(const int setSize)
{
  Vector<T> temp1(setSize);
  Vector<T> temp2(setSize-1);
  m_matrix = new Vector<T>[3];
  m_size = setSize;
  //sub diagonal
  m_matrix[0] = temp2;
  //main diagonal
  m_matrix[1] = temp1;
  //super diagonal
  m_matrix[2] = temp2; 
  m_augment = temp1;
}

//PreCondition  : Type T needs and assignment(=) operator defined
//PostCondition : Updates the Matrix, Size and Augment of calling Tridiagonal_Matrix to the values passed by rhs 
//Description   : COPY CONSTRUCTOR follows copy and swap paradigm
template <typename T>
Tridiagonal_Matrix<T>::Tridiagonal_Matrix(const Tridiagonal_Matrix<T>& rhs)
{
  m_size = rhs.m_size;
  m_matrix = new Vector<T>[3];
  m_augment = rhs.m_augment;
  m_matrix[0] = rhs.m_matrix[0];
  m_matrix[1] = rhs.m_matrix[1];
  m_matrix[2] = rhs.m_matrix[2];

  m_matrix[0].setSize(rhs.m_size-1);
  m_matrix[1].setSize(rhs.m_size);
  m_matrix[2].setSize(rhs.m_size-1);
}

//PreCondition  : none
//PostCondition : Dynamic Data array is deleted and pointer set to NULL. Size is updated to 0.
//Description   : DESTRUCTOR to be called when a Tridiagonal_Matrix is removed from memory
template <typename T>
Tridiagonal_Matrix<T>::~Tridiagonal_Matrix()
{
  delete[] m_matrix;
  m_matrix = nullptr;
  m_size = 0;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs Tridiagonal_Matrix need matching sizes
//PostCondition : Returns a Tridiagonal_Matrix copy of the resultant Tridiagonal_Matrix addition.
//Description   : Tridiagonal_MATRIX ADDITION for adding consecutive terms of 2 Matrices 
//                to form a 3rd Tridiagonal_Matrix
template <typename T>
const Tridiagonal_Matrix<T> Tridiagonal_Matrix<T>::operator+(const Tridiagonal_Matrix<T>& rhs) const
{
  Tridiagonal_Matrix<T> temp(rhs.m_size);

  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("Size1 error");
  }

  //Use Vector addition for corresponding diagonals in this and rhs
  for(int i = 0; i < 3; i++)
  {
    temp.m_matrix[i] = m_matrix[i] + rhs.m_matrix[i];
  }
  return temp;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs Tridiagonal_Matrix need matching sizes
//PostCondition : Returns a Tridiagonal_Matrix copy of the resultant Tridiagonal_Matrix difference.
//Description   : Tridiagonal_MATRIX DIFFERENCE for subtracting consecutive terms of 2 Matrices 
//                to form a 3rd Tridiagonal_Matrix
template <typename T>
const Tridiagonal_Matrix<T> Tridiagonal_Matrix<T>::operator-(const Tridiagonal_Matrix<T>& rhs) const
{
  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("Size2 error");
  }

  Tridiagonal_Matrix<T> temp(rhs.m_size);
  temp = *this + (-rhs);

  return(temp);
}

//PreCondition  : Type T needs integer multiplication(*) and assignment(=) operators defined
//PostCondition : Returns a copy of the calling Tridiagonal_Matrix negated
//Description   : UNARY MINUS gives the negative of a Tridiagonal_Matrix, changing the sign of all terms
template <typename T>
const Tridiagonal_Matrix<T> Tridiagonal_Matrix<T>::operator-() const
{
  Tridiagonal_Matrix<T> temp(m_size);

  for(int i = 0; i < 3; i++)
  {
    temp.m_matrix[i] = m_matrix[i] * (-1);
  }

  return temp;
}


//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs Tridiagonal_Matrix need matching sizes
//PostCondition : Returns a Dense_Matrix copy of the resultant Tridiagonal_Matrix multiplication
//Description   : Tridiagonal_MATRIX-Tridiagonal_MATRIX MULTIPLICATION for multiplying two Matrices
//                which creates a Pentadiagonal_Matrix (sadly it's only a Dense_Matrix here)
template <typename T>
const Dense_Matrix<T> Tridiagonal_Matrix<T>::operator*(const Tridiagonal_Matrix<T>& rhs) const
{
  Dense_Matrix<T> temp(m_size);
  Dense_Matrix<T> temprhs(m_size);

  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("Size3 error");
  }
  for(int i = 0; i < m_size; i++)
  {
    temp.setRow((*this)[i], i);
    temprhs.setRow(rhs[i], i);
  }
  temp = temp * temprhs;

  return temp;
}

//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs Vector need matching sizes
//PostCondition : Returns a Vector copy of the resultant Tridiagonal_Matrix-Vector multiplication.
//Description   : Tridiagonal_MATRIX-VECTOR MULTIPLICATION for multiplying a Vector and a Tridiagonal_Matrix
template <typename T>
const Vector<T> Tridiagonal_Matrix<T>::operator*(const Vector<T>& rhs) const
{
  Vector<T> temp(m_size);
  T resultant;

  //Size Check
  if(m_size != rhs.getSize())
  {
    throw std::invalid_argument("Size4 error");
  }

  //Set first elements
  resultant = (m_matrix[1][0] * rhs[0]) + (m_matrix[2][0] * rhs[1]);
  temp.setElement(resultant, 0);
  resultant = (m_matrix[0][m_size - 2] * rhs[m_size - 1]) + (m_matrix[1][m_size - 1] * rhs[m_size - 1]);
  temp.setElement(resultant, m_size - 1);

  //Set the rest with a nice loop
  for(int i = 0; i < m_size - 2; i++)
  {
    resultant = (m_matrix[0][i] * rhs[i]) + (m_matrix[1][i + 1] * rhs[i + 1]) + (m_matrix[2][i + 1] * rhs[i + 2]);
    temp.setElement(resultant, i + 1);
  }
  return temp;
}

//PreCondition  : Type T needs assignment(=) and multiplication(*) operators defined
//PostCondition : Returns a copy of the resultant Tridiagonal_Matrix after scalar multiplication
//Description   : Tridiagonal_MATRIX SCALAR MULTIPLICATION multiplies all terms of a Tridiagonal_Matrix by a given x
template <typename T>
const Tridiagonal_Matrix<T> Tridiagonal_Matrix<T>::operator*(const T& x) const
{
  Tridiagonal_Matrix<T> temp(m_size);

  //Use Vector-scalar multiplication for each Vector in this
  for(int i = 0; i < 3; i++)
  {
    temp.m_matrix[i] = m_matrix[i] * x;
  }
  return temp;
}

//PreCondition  : Parameter index is >= 0 and < m_size
//PostCondition : Returns a Vector from calling Tridiagonal_Matrix at the passed index location
//Description   : BRACKET OPERATOR returns the Vector at row index from calling Tridiagonal_Matrix
//                and is way more complicated than a bracket operator ever should be
template <typename T>
const Vector<T> Tridiagonal_Matrix<T>::operator[](const int index) const
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("Bounds error");
  }

  Vector<T> temp(m_size);
  //First row has size - 2 zeroes in the back
  if(index == 0)
  {
    temp.setElement(m_matrix[1][0], 0);
    temp.setElement(m_matrix[2][0], 1);
    for(int i = 0; i < m_size - 2; i++)
    {
      temp.setElement(0,i + 2);
    }
  }
  //Last row has size - 2 zeroes up front
  else if(index == m_size)
  {
    temp.setElement(m_matrix[0][m_size - 1], m_size - 1);
    temp.setElement(m_matrix[1][m_size], m_size);
    for(int i = 0; i < m_size - 2; i++)
    {
      temp.setElement(0, i);
    }
  }
  //Every row in between has to be populated on both sides of bands with zeroes
  else if(index > 0 && index < m_size)
  {
    for(int i = 0; i < index - 1; i++)
    {
      //add zeroes up front
      temp.setElement(0, i);
    }

    //put stuff in the places
    temp.setElement(m_matrix[0][index - 1], index - 1);
    temp.setElement(m_matrix[1][index], index);
    temp.setElement(m_matrix[2][index], index + 1);

    for(int i = 0; i < m_size - 2 - index; i++)
    {
      //add zeroes in back
      temp.setElement(0, m_size - i);
    }
  }

  return temp;
}

//PreCondition  : Type T has assignment(=) defined
//PostCondition : Returns a constructed Tridiagonal_Matrix with rhs data and size
//Description   : ASSIGNMENT OPERATOR uses copy and swap idiom for rhs Tridiagonal_Matrix  
//                to be copied into the calling Tridiagonal_Matrix
template <typename T>
const Tridiagonal_Matrix<T>& Tridiagonal_Matrix<T>::operator=(Tridiagonal_Matrix<T> rhs)
{
  //SWAP ALL THE DATA
  std::swap(m_matrix, rhs.m_matrix);
  std::swap(m_size, rhs.m_size);
  std::swap(m_augment, rhs.m_augment);
  return *this;
}

//PreCondition  : Type T has insertion(<<) operator defined
//PostCondition : Returns the outstream parameter containing the terms of rhs Vector
//Description   : TRIDIAGONAL_MATRIX INSERTION OPERATOR outputs the rows of 
//                the calling Tridiagonal_Matrix as a square Matrix
//                NOTE: update to call [] operator
template <typename T>
std::ostream& operator<< (std::ostream& out, const Tridiagonal_Matrix<T>& rhs)
{
  std::setprecision(6);
  //Output first row of values
  out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<rhs.m_matrix[1][0];
  out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<rhs.m_matrix[2][0];
  for(int i = 0; i < rhs.m_size - 2; i++)
  {
    out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<"0";
  }
  out<<std::endl;

  for(int i = 0; i < rhs.m_size - 2; i++)
  {
    for(int j = 0; j < i; j++)
    {
      //add zeroes up front
      out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<"0";
    }

    out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<rhs.m_matrix[0][i];
    out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<rhs.m_matrix[1][i + 1];
    out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<rhs.m_matrix[2][i + 1];

    for(int j = 0; j < rhs.m_size - i - 3; j++)
    {
      //add zeroes in back
      out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<"0";
    }    
    out<<std::endl;  
  }

  //Output last row of values
  for(int i = 0; i < rhs.m_size - 2; i++)
  {
    out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<"0";
  }
  out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<rhs.m_matrix[0][rhs.m_size - 2];
  out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<rhs.m_matrix[1][rhs.m_size - 1];
  out<<std::endl;
  return out;
}

//PreCondition  : Type T has extraction(>>) and assignment(=) operators defined. 
//PostCondition : Returns the instream parameter and inputs data into rhs Tridiagonal_Matrix row Vectors
//Description   : EXTRACTION OPERATOR for creating an augmented Tridiagonal_Matrix to be used to create a cubic spline
template <typename T>
std::istream& operator>> (std::istream& in, Tridiagonal_Matrix<T>& rhs)
{
  T x,y;
  T dummyValue;
  Vector<T> temp(rhs.m_size);
  Vector<T> aVector(rhs.m_size);

  //Set first and last row of rhs
  rhs.m_matrix[1].setElement(1, 0);
  rhs.m_matrix[2].setElement(0, 0);
  rhs.m_matrix[0].setElement(0, rhs.m_size - 2);
  rhs.m_matrix[1].setElement(1, rhs.m_size - 1);

  //Set first and last values of the B vector (augment) as 0
  rhs.m_augment.setElement(0, 0);
  rhs.m_augment.setElement(0, rhs.m_size - 1);

  //Extract data points and function values from instream
  for(int i = 0; i < rhs.m_size; i++)
  {
    in>>x>>y;
    temp.setElement(x, i);
    aVector.setElement(y, i);
  }

  //Convert x values to h values
  for(int i = 0; i < rhs.m_size; i++)
  {
    dummyValue = temp[i + 1] - temp[i];
    temp.setElement(dummyValue, i);
  }

  //A Matrix:
  //Set values of super and sub diagonal with h values
  //Set values of main diagonal with 2(hj + hj+1)
  for(int i = 0; i < rhs.m_size - 2; i++)
  {
    rhs.m_matrix[0].setElement(temp[i], i);
    rhs.m_matrix[2].setElement(temp[i + 1], i + 1);
    dummyValue = 2*(temp[i] + temp[i + 1]);
    rhs.m_matrix[1].setElement(dummyValue, i + 1);
  }

  //B Vector:
  //Set values of augment with (3/hj+1)(aj+2 - aj+1) - (3/hj)(aj+1 - aj)
  for(int i = 0; i < rhs.m_size - 2; i++)
  {
    dummyValue = (3 / temp[i + 1]) * (aVector[i + 2] - aVector[i + 1]) - (3 / temp[i]) * (aVector[i + 1] - aVector[i]);
    rhs.m_augment.setElement(dummyValue, i + 1);
  }

  return in;
}
/*
//PreCondition  : Type T has extraction(>>) and assignment(=) operators defined. Instream has m_size number of data
//PostCondition : Returns the instream parameter and inputs data into rhs Tridiagonal_Matrix row Vectors
//Description   : EXTRACTION OPERATOR USED FOR A DIFFERENT INPUT FORMAT THAN HW5 REQUIRES
template <typename T>
std::istream& operator>> (std::istream& in, Tridiagonal_Matrix<T>& rhs)
{
  T temp;
  Vector<T> tempvector1(rhs.m_size);
  Vector<T> tempvector02(rhs.m_size - 1);
  //Sub diagonal
  for(int i = 0; i < rhs.m_size - 1; i++)
  {
    in>>temp;
    tempvector02.setElement(temp, i);
  }
  rhs.setRow(tempvector02, 0);

  //Main diagonal
  for(int i = 0; i < rhs.m_size; i++)
  {
    in>>temp;
    tempvector1.setElement(temp, i);
  }
  rhs.setRow(tempvector1, 1);

  //Super diagonal
  for(int i = 0; i < rhs.m_size - 1; i++)
  {
    in>>temp;
    tempvector02.setElement(temp, i);
  }
  rhs.setRow(tempvector02, 2);

  return in;
}
*/
//PreCondition  : none
//PostCondition : Returns the size of calling Tridiagonal_Matrix
//Description   : SIZE ACCESSOR allows indirect access to the size of the calling Tridiagonal_Matrix 
template <typename T>
int Tridiagonal_Matrix<T>::getSize() const
{
  return m_size;
}

//PreCondition  : none
//PostCondition : Returns augment Vector member
//Description   : AUGMENT ACCESSOR allows indirect access to the Vector augment of the calling Tridiagonal_Matrix
template <typename T>
Vector<T> Tridiagonal_Matrix<T>::getAugment() const
{
  return m_augment;
}

//PreCondition  : none
//PostCondition : Returns augment Vector member
//Description   : DIAGONAL ACCESSOR allows indirect access to the sub main or super diagonal 
//                of the calling Tridiagonal_Matrix
template <typename T>
Vector<T> Tridiagonal_Matrix<T>::getDiagonal(const int diagonal) const
{
  //Size Check
  if(diagonal < 0 || diagonal > 2)
  {
    throw std::invalid_argument("Diagonal1 error");
  }
  return m_matrix[diagonal];
}

//PreCondition  : Type T has assignment(=) operator defined
//                Diagonal is >= 0 and < 3 since there are 3 diagonals
//                Col is >= 0 and < size to fit within the Vector's range
//PostCondition : Updates a row of calling Tridiagonal_Matrix from passed row parameter
//Description   : ROW MUTATOR allows the rows of a Vector to be set
template <typename T>
void Tridiagonal_Matrix<T>::setData(const T element, const int diagonal, const int col)
{
  //Size Check
  if(diagonal < 0 || diagonal > 2)
  {
    throw std::invalid_argument("Diagonal error2");
  }
  if(col < 0 || col > m_size)
  {
    throw std::invalid_argument("Size5 error");
  }

  m_matrix[diagonal].setElement(element, col);
  return;
}

//PreCondition  : Type T has assignment(=) operator defined
//                Index is >= 0 and < size.
//PostCondition : Updates a row of calling Tridiagonal_Matrix from passed row parameter
//Description   : ROW MUTATOR allows the rows of a Vector to be set
template <typename T>
void Tridiagonal_Matrix<T>::setDiagonal(const Vector<T> element, const int diagonal)
{
  //Diagonal Check
  if(diagonal < 0 || diagonal > 2)
  {
    throw std::invalid_argument("Diagonal3 error");
  }
  //Size Check
  if(element.getSize() != m_matrix[diagonal].getSize())
  {
    throw std::invalid_argument("Size6 error");
  }

  m_matrix[diagonal] = element;
  return;
}

//PreCondition  : Parameter size is >= 0 and must equal n (number of columns) to maintain square matrices
//PostCondition : Updates the size of calling Tridiagonal_Matrix from passed size parameter
//Description   : SIZE MUTATOR allows the size of the calling Tridiagonal_Matrix to be set
template <typename T>
void Tridiagonal_Matrix<T>::setSize(const int size)
{
  //Size Check
  if(m_size < 0)
  {
    throw std::invalid_argument("Size7 error");
  }
  m_size = size;
  m_matrix[0].setSize(size - 1);
  m_matrix[1].setSize(size);
  m_matrix[2].setSize(size - 1);
  return;
}

//PreCondition  : Parameter index is >= 0 and < size. Type T has assignment(=) operator defined
//PostCondition : Updates an element of the augment vector of the calling Tridiagonal_Matrix at 
//                index parameter location
//Description   : AUGMENT MUTATOR allows for elements of the augment Vector to be set 
template <typename T>
void Tridiagonal_Matrix<T>::setAugment(const T element, const int index)
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("Diagonal4 error");
  }
  m_augment.setElement(element, index);
  return;
}

//PreCondition  : Type T has assignment(=) defined
//PostCondition : Returns a Tridiagonal_Matrix copy of the resultant transpose operation
//Description   : TRANSPOSE to convert the rows of a Tridiagonal_Matrix to the columns
template <typename T>
const Tridiagonal_Matrix<T> Tridiagonal_Matrix<T>::transpose() const
{
  Tridiagonal_Matrix<T> temp(m_size);

  temp.m_matrix[0] = m_matrix[2];
  temp.m_matrix[1] = m_matrix[1];
  temp.m_matrix[2] = m_matrix[0];

  return temp;
}

//PreCondition  : none
//PostCondition : The calling Matrix is assigned from a created Matrix2
//Description   : Tests all the functionality of a particular Matrix class
template <typename T>
void Tridiagonal_Matrix<T>::MatrixTest(const Vector<T>& testvector)
{
  Tridiagonal_Matrix<T> matrix2(m_size);
  matrix2 = (*this);
  matrix2.m_matrix[1] = testvector;

  std::cout<<"Output test: Matrix1"<<std::endl;
  std::cout<<(*this)<<std::endl;
  std::cout<<"Output test: Matrix2"<<std::endl;
  std::cout<<matrix2<<std::endl;
  /*
  std::cout<<"Addition test: Matrix1 + Matrix2"<<std::endl;
  std::cout<<(*this) + matrix2<<std::endl;
  std::cout<<"Subtraction test: Matrix1 - Matrix2"<<std::endl;
  std::cout<<(*this) - matrix2<<std::endl;
  std::cout<<"Unary- test: -Matrix1"<<std::endl;
  std::cout<<-(*this)<<std::endl;
  */
  std::cout<<"Matrix* test: Matrix1 * Matrix2"<<std::endl;
  std::cout<<(*this) * matrix2<<std::endl;
  /*
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
  */
  return;
}