//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : DENSE_GAUSSIAN ELIMINATION IMPLEMENTATION realized through the function resolution operator

//PreCondition  : Type T needs assignment(=), division(/), multiplication(*), addition(+), subtraction(-) defined.
//PostCondition : Source Matrix has augment Vector updated as the solution to Gauss Elimination
//Description   : FUNCTION RESOLUTION is the Gauss Elimination algorithm with partial pivoting.
//                Gauss is implemented as a functor for general programming

template <typename T>
void Dense_Gauss<T>::operator()(Dense_Matrix<T>& source)
{
  T multiplier, augment;
  int size = source.getSize() - 1;
  Vector<T> temp(size + 1);
  Dense_Matrix<T> solution(size + 1), pivotMatrix(size + 1);
  
  solution = source;
  pivotMatrix = source;

  //Forward substitution
  for(int i = 0; i < size; i++)
  {
    //Partial Pivoting implementation
    for(int j = 0; j < size - i - 1; j++)
    {
      if(solution.getRow(i + j)[i + j] < solution.getRow(j + i + 1)[i + j])
      {
        temp = solution.getRow(i + j);
        augment = source.getAugment()[i + j];
        solution.setRow(solution.getRow(i + j + 1), i + j);
        solution.setRow(temp, i + j + 1);
        source.setAugment(source.getAugment()[i + j + 1], i + j);
        source.setAugment(augment, i + j + 1);
      }       
    }
    
    for(int j = 0; j < size - i; j++)
    {
      multiplier = (-1)*(solution.getRow(i)[i] / solution.getRow(j + i + 1)[i]);
      temp = solution.getRow(j + i + 1);
      temp = temp * multiplier;
      temp = temp + solution.getRow(i);
      solution.setRow(temp,j + i + 1);

      augment = source.getAugment()[i + j + 1];
      augment = augment * multiplier;
      augment = augment + source.getAugment()[i];
      source.setAugment(augment, j + i + 1);      
    }
  }

  //Resize Matrix
  for(int i = 0; i < size + 1; i++)
  {
    multiplier = (1) / solution.getRow(i)[i];
    temp = solution.getRow(i);
    temp = temp * multiplier;
    source.setAugment(source.getAugment()[i]*multiplier, i);
    solution.setRow(temp,i);
  }
  //Back substitution
  for(int i = 0; i < size; i++)
  {
    augment = source.getAugment()[size - i - 1];
    for(int j = 0; j < i + 1; j++)
    {
      augment= augment - source.getAugment()[size - j] * solution.getRow(size - i - 1)[size - j];
    }
    source.setAugment(augment, size - i - 1);
  }   
  return;
}
