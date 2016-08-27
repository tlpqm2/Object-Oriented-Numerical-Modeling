//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : VECTOR IMPLEMENTATION containing template Vector class

//PreCondition  : Default size >= 0 (please don't change my default <3)
//PostCondition : Data and Size are initialized for a new Vector object
//Description   : DEFAULT CONSTRUCTOR to replace the given default constructor
template <typename T>
Vector<T>::Vector()
{
	m_data = new T[DEFAULT_SIZE];
  m_size = DEFAULT_SIZE;
}

//PreCondition  : Parameter size is >= 0
//PostCondition : Data and Size are initialized for a new Vector object with a passed size
//Description   : CONSTRUCTOR that takes an integer size as a parameter 
template <typename T>
Vector<T>::Vector(const int setSize)
{
  m_data = new T[setSize];
  m_size = setSize;
}

//PreCondition  : Calling Vector and rhs must have matching template types 
//PostCondition : Updates the Data and Size of calling Vector to the values passed by rhs Vector
//Description   : COPY CONSTRUCTOR follows copy and swap paradigm
template <typename T>
Vector<T>::Vector(const Vector<T>& rhs)
{
  m_size = rhs.m_size;
  m_data = new T[m_size];

  for(int i = 0; i < m_size; i++)
  {
    m_data[i] = rhs.m_data[i];
  }
}

//PreCondition  : none
//PostCondition : Dynamic Data array is deleted and pointer set to NULL. Size is updated to 0.
//Description   : DESTRUCTOR to be called when a Vector is removed from memory
template <typename T>
Vector<T>::~Vector()
{
  delete[] m_data;
  m_data = NULL;
  m_size = 0;
}

//PreCondition  : Type T needs addition(+) and assignment(=) operators defined
//                Calling object and rhs Vector need matching sizes
//PostCondition : Returns a copy of the resultant Vector addition.
//Description   : VECTOR ADDITION for adding consecutive terms of 2 Vector to form a 3rd Vector
template <typename T>
const Vector<T> Vector<T>::operator+ (const Vector<T>& rhs) const
{
  Vector<T> temp(m_size);

  for(int i = 0; i < m_size; i++)
  {
    temp.m_data[i] = m_data[i] + rhs.m_data[i];
  }

  return temp;
}

//PreCondition  : Type T needs addition(+), assignment(=) and unary minus(-) operators defined
//                Calling object and rhs Vector need matching sizes
//PostCondition : Returns a copy of the resultant Vector difference
//Description   : VECTOR DIFFERENCE for taking the difference of 
//                consecutive terms of 2 Vectors to form a 3rd Vector
template <typename T>
const Vector<T> Vector<T>::operator- (const Vector<T>& rhs) const
{
  Vector<T> temp(m_size);
  temp = (*this + (-rhs));
  return temp;
}

//PreCondition  : Type T needs integer multiplication(*) and assignment(=) operators defined
//PostCondition : Returns a copy of the calling Vector negated
//Description   : UNARY MINUS gives the negative of a Vector, changing the sign of all terms
template <typename T>
const Vector<T> Vector<T>::operator- () const
{
  Vector<T> temp(m_size);

  for(int i = 0; i < m_size; i++)
  {
    temp.m_data[i] = (m_data[i])*(-1);
  }
  return temp;
}

//PreCondition  : Type T needs addition(+), assignment(=) and multiplication(*) operators defined
//                Calling object and rhs Vector need matching sizes
//PostCondition : Returns the resultant Real from the dot product
//Description   : DOT PRODUCT sums consecutive terms of 2 Vectors after multiplying to produce a Real
template <typename T>
const T Vector<T>::operator* (const Vector<T>& rhs) const 
{
  T sum = 0;

  for(int i = 0; i < rhs.m_size; i++)
  {
    sum += m_data[i]*rhs.m_data[i];
  }

  return sum;
}

//PreCondition  : Type T needs assignment(=) and multiplication(*) operators defined
//PostCondition : Returns a copy of the resultant Vector after scalar multiplication
//Description   : SCALAR MULTIPLICATION multiplies all terms of a vector by a given T
template <typename T>
const Vector<T> Vector<T>::operator* (const T& x) const
{
  Vector<T> temp(m_size);

  for(int i = 0; i < m_size; i++)
  {
    temp.m_data[i] = (x) * (m_data[i]);
  }
  return temp;
}

//PreCondition  : Parameter index is >= 0 and < m_size
//PostCondition : Returns a Real element from calling Vector at the passed index location
//Description   : BRACKET OPERATOR returns the element of a Vector at a given index 
template <typename T>
const T& Vector<T>::operator[] (const int index) const
{
  return m_data[index];
}

//PreCondition  : Type T has assignment(=) defined
//PostCondition : Returns a constructed Vector with rhs data and size
//Description   : ASSIGNMENT OPERATOR uses std::swap per copy and swap idiom
template <typename T>
const Vector<T>& Vector<T>::operator= (Vector<T> rhs)
{
  std::swap(m_data, rhs.m_data);
  std::swap(m_size, rhs.m_size);
  return *this;
}

//PreCondition  : Type T has insertion(<<) operator defined
//PostCondition : Returns the outstream parameter containing the terms of rhs Vector
//Description   : VECTOR INSERTION OPERATOR outputs the terms of a Vector as a row
template <typename T>
std::ostream& operator<< (std::ostream& out, const Vector<T>& rhs)
{
  for(int i = 0; i < rhs.m_size; i++)
  {
    out<<std::setw(12)<<std::fixed<<std::setprecision(8)<<rhs[i];
  }
  return out;
}

//PreCondition  : Type T has extraction(>>) operator defined. Instream has m_size number of data
//PostCondition : Returns the instream parameter and inputs data into rhs Vector data
//Description   : VECTOR EXTRACTION OPERATOR takes m_size number of terms from file into a Vector
template <typename T>
std::istream& operator>> (std::istream& in, const Vector<T>& rhs)
{
  for(int i = 0; i < rhs.m_size; i++)
  {
    in>>rhs.m_data[i];
  }
  return in;
}

//PreCondition  : none
//PostCondition : Returns the size of calling Vector
//Description   : SIZE ACCESSOR allows indirect access to the size of the calling Vector
template <typename T>
int Vector<T>:: getSize() const
{
  return m_size;
}

//PreCondition  : Parameter size is >= 0 and isn't contained in a 
//                Matrix(std::vector<Vector<T>) where m(rows) != size. Size must = the number of elements in Vector.
//PostCondition : Updates the size of calling Vector from passed size parameter
//Description   : SIZE MUTATOR allows the size of a Vector to be set
template <typename T>
void Vector<T>::setSize(const int size)
{
  m_size = size;
  return;
}

//PreCondition  : Parameter index is >= 0 and < size. Type T has assignment(=) operator defined
//PostCondition : Updates an element of calling Vector at index parameter location
//Description   : DATA MUTATOR allows for elements of a Vector to be set
template <typename T>
void Vector<T>::setElement(const T element, const int index)
{
  m_data[index] = element;
  return;
}

//PreCondition  : Type T needs addition(+), assignment(=) and multiplication(*) operators defined. 
//                Type T needs square root operation defined.
//PostCondition : Returns a Real from 2-norm of a Vector
//Description   : VECTOR NORM gives the 2-norm of a Vector which is the 
//                square root of the sum of squares of all terms in the Vector
template <typename T>
const T Vector<T>:: twoNorm() const
{
  T norm = 0;
  T temp = (*this) * (*this);
  norm = sqrt(temp);
  return norm;
}
