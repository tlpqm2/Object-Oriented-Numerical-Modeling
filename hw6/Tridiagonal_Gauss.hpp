//Programmer  : Tyler Patton
//Assignment  : Assignment 6
//Instructor  : Price
//Course      : CS 5201 Spring 2016
//Due Date    : 4/22/2016
//Description : TRIDIAGONAL GAUSSIAN ELIMINATION IMPLEMENTATION realized through the function resolution operator

//PreCondition  : Type T needs assignment(=), division(/), multiplication(*), addition(+), subtraction(-) defined.
//PostCondition : Source Matrix has augment Vector updated as the solution to Gauss Elimination
//Description   : FUNCTION RESOLUTION is the Gauss Elimination algorithm optimized for a Tridiagonal Matrix
//                Gauss is implemented as a functor for general programming

template <typename T>
void Tridiagonal_Gauss<T>::operator()(Tridiagonal_Matrix<T>& source)
{
  int size = source.getSize();
  T multiplier, tempValue;
  Vector<T> tempRow(size);
  Tridiagonal_Matrix<T> solve(size);

  solve = source;

  //Forward Elimination
  for(int i = 0; i < size - 1; i++)
  {
    multiplier = (-1)*(solve[i][i] / solve[i + 1][i]);
    tempValue = (solve[i + 1][i] * multiplier) + solve[i][i];
    solve.setData(tempValue, 0, i);
    tempValue = (solve[i + 1][i + 1] * multiplier) + solve[i][i + 1];
    solve.setData(tempValue, 1, i + 1);
    if(i < size - 2)
    {
      tempValue = (solve[i + 1][i + 2] * multiplier);
      solve.setData(tempValue, 2, i + 1);
    }
    
    tempValue = solve.getAugment()[i + 1] * multiplier;
    tempValue = tempValue + solve.getAugment()[i];
    solve.setAugment(tempValue, i + 1);
  }

  //Resize Matrix
  for(int i = 0; i < size; i++)
  {
    tempValue = solve[i][i];
    solve.setAugment(solve.getAugment()[i] / tempValue, i);  
  }
  for(int i = 0; i < size - 1; i++)
  {
    tempValue = solve[i][i];
    solve.setData(solve.getDiagonal(2)[i] / tempValue, 2, i);
  }
  for(int i = 0; i < size; i++)
  {
    solve.setData(1, 1, i);
  }
  //Back Substitution
  for(int i = 0; i < size - 1; i++)
  {
    tempValue = solve.getAugment()[size - 1 - i] * solve.getDiagonal(2)[size - 2 - i] * (-1); 
    tempValue += solve.getAugment()[size - 2 - i];
    solve.setAugment(tempValue, size - 2 - i);
  }
  return;
}