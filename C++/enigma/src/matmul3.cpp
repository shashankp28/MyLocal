#include <cstdlib>
#include <iostream>
#include <chrono>
#include "matfunc.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{
  int N, nb;
  if(argc!=3)
  {
    cout<<"Enter Valid Command Line Arguments !";
    return 1;
  }
  else
  {
    if(!isNumber(argv[1]) or !isNumber(argv[2]))
    {
      cout<<"Enter Only Positive Integers !";
      return 1;
    }
    else
    {
      N = atoi(argv[1]);
      nb = atoi(argv[2]);
      if(N<=0 or nb<=0 or N<nb or N%nb!=0)
      {
        cout<<"Enter compatible values for N and nb";
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
  for(int i=0; i<nb; i++)
  {
    for (int k=0; k<N; k++)
    {
      for(int i_a=0; i_a<N/nb; i_a++)
      {
        for(int j_b=0; j_b<N; j_b++)
        {
          int blocked_index_row = i*(N/nb)*N + i_a*N + j_b;
          int blocked_index_col = i_a + k*N + i*(N/nb);
          C_rowmaj[blocked_index_row] = C_rowmaj[blocked_index_row] + A_colmaj[blocked_index_col] * B_rowmaj[(k*N) + j_b];
        }
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