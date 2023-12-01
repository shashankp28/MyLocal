#include <cstdlib>
#include <iostream>
#include <chrono>
#include "matfunc.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{
  int N;

  if(argc!=2)
  {
    cout<<"Enter Valid Command Line Arguments !";
    return 1;
  }
  else
  {
    if(!isNumber(argv[1]))
    {
      cout<<"Enter Only Positive Integer!";
      return 1;
    }
    else
    {
      N = atoi(argv[1]);
      if(N<=0)
      {
        cout<<"Enter compatible value for N";
        return 1;
      }
    }
  }

  double **A = generate_matrix(N, 0);
  double **B = generate_matrix(N, 0);
  double **C = generate_matrix(N, 1);

  double *A_colmaj = to_major(A, N, 0);
  double *B_rowmaj = to_major(B, N, 1);
  double *C_rowmaj = to_major(C, N, 1);



  // Use ijk loop for matrix multiplication
  // B, C: Row-Major ; A: Col-Major
  auto start = high_resolution_clock::now();
  for(int k=0; k<N; k++)
  {
    for(int i=0; i<N; i++)
    {
      for(int j=0; j<N; j++)
      {
        C_rowmaj[(i*N) + j] = C_rowmaj[(i*N) + j] + A_colmaj[(k*N) + i] * B_rowmaj[(k*N) + j];
      }
    }
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  C = to_2D(C_rowmaj, N, 1);

  validate(A, B, C, N);
  cout << "Time for Matrix Multiplication: "
         << (double) duration.count()/1000000 << " seconds" << endl;

}