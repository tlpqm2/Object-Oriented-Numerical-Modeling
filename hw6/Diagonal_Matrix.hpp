//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : DIAGONAL_MATRIX IMPLEMENTATION containing template Vector class

//PreCondition  : Parameter setSize is >= 0
//PostCondition : Data and Size are initialized for a new Diagonal_Matrix object with a passed size
//Description   : CONSTRUCTOR that takes an integer size as a parameter 
template <typename T>
Diagonal_Matrix<T>::Diagonal_Matrix(const int setSize)
{
  Vector<T> temp(setSize);
  m_diagonal = temp;
  m_size = setSize; 
  m_augment = temp;
}

//PreCondition  : Type T needs and assignment(=) operator defined
//PostCondition : Updates the Matrix, Size and Augment of calling Diagonal_Matrix to the values passed by rhs 
//Description   : COPY CONSTRUCTOR follows copy and swap paradigm
template <typename T>
Diagonal_Matrix<T>::Diagonal_Matrix(const Diagonal_Matrix<T>& rhs)
{
  m_diagonal = rhs.m_diagonal;
  m_size = rhs.m_size;
  m_augment = rhs.m_augment;
  m_diagonal.setSize(rhs.m_size);
}

//PreCondition  : none
//PostCondition : Dynamic Data array is deleted and pointer set to NULL. Size is updated to 0.
//Description   : DESTRUCTOR to be called when a Diagonal_Matrix is removed from memory
template <typename T>
Diagonal_Matrix<T>::~Diagonal_Matrix()
{
  m_size = 0;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs Diagonal_Matrix need matching sizes
//PostCondition : Returns a Diagonal_Matrix copy of the resultant Diagonal_Matrix addition.
//Description   : DIAGONAL_MATRIX ADDITION for adding consecutive terms of 2 Matrices to form a 3rd Diagonal_Matrix
template <typename T>
const Diagonal_Matrix<T> Diagonal_Matrix<T>::operator+(const Diagonal_Matrix<T>& rhs) const
{
  Diagonal_Matrix<T> temp(rhs.m_size);

  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("Size1 error");
  }

  //Use Vector addition for diagonals
  temp.m_diagonal = m_diagonal + rhs.m_diagonal;

  return temp;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs Diagonal_Matrix need matching sizes
//PostCondition : Returns a Diagonal_Matrix copy of the resultant Diagonal_Matrix difference.
//Description   : DIAGONAL_MATRIX DIFFERENCE for subtracting consecutive terms of 2 Matrices 
//                to form a 3rd Diagonal_Matrix
template <typename T>
const Diagonal_Matrix<T> Diagonal_Matrix<T>::operator-(const Diagonal_Matrix<T>& rhs) const
{
  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("Size2 error");
  }

  Diagonal_Matrix<T> temp(rhs.m_size);
  temp = *this + (-rhs);

  return(temp);
}

//PreCondition  : Type T needs integer multiplication(*) and assignment(=) operators defined
//PostCondition : Returns a copy of the calling Diagonal_Matrix negated
//Description   : UNARY MINUS gives the negative of a Diagonal_Matrix, changing the sign of all terms
template <typename T>
const Diagonal_Matrix<T> Diagonal_Matrix<T>::operator-() const
{
  Diagonal_Matrix<T> temp(m_size);

  temp.m_diagonal = m_diagonal * (-1);

  return temp;
}


//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs Diagonal_Matrix need matching sizes
//PostCondition : Returns a Diagonal_Matrix copy of the resultant Diagonal_Matrix multiplication
//Description   : DIAGONAL_MATRIX-DIAGONAL_MATRIX MULTIPLICATION for multiplying two Matrices
//                which creates a Diagonal matrix from the consecutive terms multiplied
template <typename T>
const Diagonal_Matrix<T> Diagonal_Matrix<T>::operator*(const Diagonal_Matrix<T>& rhs) const
{
  Diagonal_Matrix<T> temp(m_size);
  T resultant;

  //Size Check
  if(m_size != rhs.m_size)
  {
    throw std::invalid_argument("Size3 error");
  }

  //Multiply consecutive terms of the diagonals
  for(int i = 0; i < m_size; i++)
  {
    resultant = m_diagonal[i] * rhs.m_diagonal[i];
    temp.m_diagonal.setElement(resultant, i);
  }

  return temp;
}

//PreCondition  : Type T needs multiplication(*) and assignment(=) operators defined
//                Calling object and rhs Vector need matching sizes
//PostCondition : Returns a Vector copy of the resultant Diagonal_Matrix-Vector multiplication.
//Description   : DIAGONAL_MATRIX-VECTOR MULTIPLICATION for multiplying a Vector and a Diagonal_Matrix
template <typename T>
const Vector<T> Diagonal_Matrix<T>::operator*(const Vector<T>& rhs) const
{
  Vector<T> temp(m_size);
  T resultant;

  //Size Check
  if(m_size != rhs.getSize())
  {
    throw std::invalid_argument("Size4 error");
  }

  //Multiply consecutive terms of the diagonal and Vector
  for(int i = 0; i < m_size; i++)
  {
    resultant = m_diagonal[i] * rhs[i];
    temp.setElement(resultant, i);
  }

  return temp;
}

//PreCondition  : Type T needs assignment(=) and multiplication(*) operators defined
//PostCondition : Returns a copy of the resultant Diagonal_Matrix after scalar multiplication
//Description   : DIAGONAL_MATRIX SCALAR MULTIPLICATION multiplies all terms of a Diagonal_Matrix by a given x
template <typename T>
const Diagonal_Matrix<T> Diagonal_Matrix<T>::operator*(const T& x) const
{
  Diagonal_Matrix<T> temp(m_size);

  //Use Vector scalar multiplication to multiply the scalar across the diagonal
  temp.m_diagonal = m_diagonal * x;

  return temp;
}

//PreCondition  : Parameter index is >= 0 and < m_size
//PostCondition : Returns a Vector from calling Diagonal_Matrix at the passed index location
//Description   : BRACKET OPERATOR returns the Vector at row index from calling Diagonal_Matrix
//                and is way more complicated than a bracket operator ever should be
template <typename T>
const Vector<T> Diagonal_Matrix<T>::operator[](const int index) const
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("Bounds error");
  }

  Vector<T> temp(m_size);

  //First row has size - 1 zeroes in the back
  if(index == 0)
  {
    temp.setElement(m_diagonal[0], 0);
    for(int i = 1; i < m_size; i++)
    {
      temp.setElement(0, i);
    }
  }
  //Last row has size - 1 zeroes up front
  else if(index == m_size)
  {
    temp.setElement(m_diagonal[m_size - 1], m_size - 1);
    for(int i = 0; i < m_size - 1; i++)
    {
      temp.setElement(0, i);
    }
  }
  //Every row in between has to be populated on both sides of diagonal with zeroes
  else
  {
    for(int i = 0; i < index; i++)
    {
      //add zeroes up front
      temp.setElement(0, i);
    }

    //put stuff in the places
    temp.setElement(m_diagonal[index], index);

    for(int i = 0; i < m_size - 1 - index; i++)
    {
      //add zeroes in back
      temp.setElement(0, m_size - i);
    }
  }

  return temp;
}

//PreCondition  : Type T has assignment(=) defined
//PostCondition : Returns a constructed Diagonal_Matrix with rhs data and size
//Description   : ASSIGNMENT OPERATOR uses copy and swap idiom for rhs Diagonal_Matrix 
//                to be copied into the calling Diagonal_Matrix
template <typename T>
const Diagonal_Matrix<T>& Diagonal_Matrix<T>::operator=(Diagonal_Matrix<T> rhs)
{
  //SWAP ALL THE DATA
  std::swap(m_diagonal, rhs.m_diagonal);
  std::swap(m_size, rhs.m_size);
  std::swap(m_augment, rhs.m_augment);
  return *this;
}

//PreCondition  : Type T has insertion(<<) operator defined
//PostCondition : Returns the outstream parameter containing the terms of rhs Vector
//Description   : DIAGONAL_MATRIX INSERTION OPERATOR outputs the rows of 
//                the calling Diagonal_Matrix as a square Matrix
//                NOTE: update to call [] operator
template <typename T>
std::ostream& operator<< (std::ostream& out, const Diagonal_Matrix<T>& rhs)
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
  out<<std::endl;

  return out;
}

//PreCondition  : Type T has extraction(>>) and assignment(=) operators defined. Instream has m_size number of data
//PostCondition : Returns the instream parameter and inputs data into rhs Diagonal_Matrix row Vectors
//Description   : EXTRACTION OPERATOR USED FOR A DIFFERENT INPUT FORMAT THAN HW6 REQUIRES
template <typename T>
std::istream& operator>> (std::istream& in, Diagonal_Matrix<T>& rhs)
{
  T temp;
  for(int i = 0; i < rhs.getSize(); i++)
  {
    in>>temp;
    rhs.m_diagonal.setElement(temp, i);
  }

  return in;
}


//PreCondition  : none
//PostCondition : Returns the size of calling Diagonal_Matrix
//Description   : SIZE ACCESSOR allows indirect access to the size of the calling Diagonal_Matrix 
template <typename T>
int Diagonal_Matrix<T>::getSize() const
{
  return m_size;
}

//PreCondition  : none
//PostCondition : Returns augment Vector member
//Description   : AUGMENT ACCESSOR allows indirect access to the Vector augment of the calling Diagonal_Matrix
template <typename T>
Vector<T> Diagonal_Matrix<T>::getAugment() const
{
  return m_augment;
}

//PreCondition  : none
//PostCondition : Returns augment Vector member
//Description   : DIAGONAL ACCESSOR allows indirect access to the diagonal of the calling Diagonal_Matrix
template<typename T>
Vector<T> Diagonal_Matrix<T>::getDiagonal() const
{
  return m_diagonal;
}

//PreCondition  : Type T has assignment(=) operator defined
//                Diagonal is >= 0 and < 3 since there are 3 diagonals
//                Col is >= 0 and < size to fit within the Vector's range
//PostCondition : Updates a row of calling Diagonal_Matrix from passed row parameter
//Description   : DIAGONAL MUTATOR allows the elements of the Diagonal to be set
template <typename T>
void Diagonal_Matrix<T>::setData(const T element, const int col)
{
  //Size Check
  if(col < 0 || col > m_size)
  {
    throw std::invalid_argument("Size5 error");
  }

  m_diagonal[col].setElement(element, col);
  return;
}

//PreCondition  : Type T has assignment(=) operator defined
//                Index is >= 0 and < size.
//PostCondition : Updates a row of calling Diagonal_Matrix from passed row parameter
//Description   : DIAGONAL MUTATOR allows the diagonal to be set
template <typename T>
void Diagonal_Matrix<T>::setDiagonal(const Vector<T> element)
{
  //Size Check
  if(element.getSize() != m_diagonal.getSize())
  {
    throw std::invalid_argument("Size6 error");
  }

  m_diagonal = element;
  return;
}

//PreCondition  : Parameter size is >= 0 and must equal n (number of columns) to maintain square matrices
//PostCondition : Updates the size of calling Diagonal_Matrix from passed size parameter
//Description   : SIZE MUTATOR allows the size of the calling Diagonal_Matrix to be set
template <typename T>
void Diagonal_Matrix<T>::setSize(const int size)
{
  //Size Check
  if(m_size < 0)
  {
    throw std::invalid_argument("Size7 error");
  }
  m_size = size;
  m_diagonal.setSize(size);
  return;
}

//PreCondition  : Parameter index is >= 0 and < size. Type T has assignment(=) operator defined
//PostCondition : Updates an element of the augment vector of the calling Diagonal_Matrix at index parameter location
//Description   : AUGMENT MUTATOR allows for elements of the augment Vector to be set 
template <typename T>
void Diagonal_Matrix<T>::setAugment(const T element, const int index)
{
  //Size Check
  if(index < 0 || index > m_size)
  {
    throw std::invalid_argument("Diagonal4 error");
  }
  m_augment.setElement(element, index);
  return;
}

//PreCondition  : none
//PostCondition : Returns a Diagonal_Matrix copy of the resultant transpose operation
//Description   : TRANSPOSE to convert the rows of a Diagonal_Matrix to the columns... which is the same matrix
template <typename T>
const Diagonal_Matrix<T> Diagonal_Matrix<T>::transpose() const
{ 
  return *this;
}

//PreCondition  : none
//PostCondition : The calling Matrix is assigned from a created Matrix2
//Description   : Tests all the functionality of a particular Matrix class
template <typename T>
void Diagonal_Matrix<T>::MatrixTest(const Vector<T>& testvector)
{
  Diagonal_Matrix<T> matrix2(m_size);
  matrix2 = (*this);
  matrix2.m_diagonal = testvector;

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