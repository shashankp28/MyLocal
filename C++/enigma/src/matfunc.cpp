#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

double doubleRand() {
  return 10 * (float) rand()/RAND_MAX;
}

bool isNumber(char number[])
{
    int i = 0;
    if (number[0] == '-')
        return false;
    for (; number[i] != 0; i++)
    {
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}

bool compare(double a, double b)
{
    return (abs(a - b) < 1e-6);
}

void validate(double **A, double **B, double **C, int N)
{
  bool is_ok = true;
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      for(int k=0; k<N; k++)
      {
        C[i][j] = C[i][j] - A[i][k]*B[k][j];
      }
    }
  }
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      is_ok = is_ok && compare(C[i][j], 0);
    }
  }
  if(is_ok)
  {
    cout<<"Matrix Multiplication is Verified !!"<<endl;
  }
  else
  {
    cout<<"Error, Some of the Outputs are not verified !!"<<endl;
  }
}

double **generate_matrix(int N, int to_zero)
{
  double **M;
  M = new double*[N];
  for(int i=0; i<N; i++)
  {
    M[i] = new double[N];
  }
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      M[i][j] = (1-to_zero)*doubleRand();
    }
  }
  return M;
}

double *to_major(double **M, int N, bool to_row)
{
  int no_elements = pow(N, 2)+0.5;
  double *M_major = new double[no_elements];
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      int index = to_row*(i*N + j) + (1-to_row)*(j*N + i);
      M_major[index] = M[i][j];
    }
  }
  return M_major;
}

double **to_2D(double *M_maj, int N, bool to_row)
{
  double **M;
  M = new double*[N];
  for(int i=0; i<N; i++)
  {
    M[i] = new double[N];
  }
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      int index = to_row*(i*N + j) + (1-to_row)*(j*N + i);
      M[i][j] = M_maj[index];
    }
  }
  return M;
}
