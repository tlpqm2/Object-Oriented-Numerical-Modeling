/**
 * @file MatrixBase.h
 * @author Matthew Anderson <mia2n4@mst.edu>
 *         Tyler Patton <tlpqm2@mst.edu>
 *         Class: CS5201 Spring 2016
 * @brief QR DECOMPOSITION HEADER containing template QRsolver algorithm class
 */

template <typename T>
Vector<T> QRsolver<T>::solve(const RectangularMatrix<T>& A)
{
  int size = A.getRows();
  Vector<T> solution(size);
  Vector<T> b(size);
  RectangularMatrix<T> working(A);

  b = working.getCol(size);
  Vector<T> d(size);

  //QRdecomp A
  QRdecomp<T> qr(size);
  qr(working);
  RectangularMatrix<T> dummyQ = qr.getQ();
  RectangularMatrix<T> dummyR = qr.getR();

  dummyQ.transpose();
  //Compute: d = Qt * b
  //         Back sub for Rx = d
  d = (dummyQ * b).getCol(0);

  dummyR = dummyR.augment(d);

  //Rescale R for Back Sub
  for(int i = 0; i < dummyR.getRows(); i++)
  {
    dummyR[i] = (1.0 / dummyR[i][i]) * dummyR[i];
  }

  //Back Sub
  for(int i = dummyR.getRows() - 2; i >= 0; i--)
  {
    for(int j = i; j >= 0; j--)
    {
      dummyR[j] -= dummyR[j][i+1] * dummyR[i+1];
    }
  }
  solution = dummyR.getCol(size);

  return solution;
}