double** make_zeros(int row, int col)
{
 double** M = 0;
 M = new double*[row];

 for (int i = 0; i < row; i++)
    {
      M[i] = new double[col];

      for (int j = 0; j < col; j++)
      {                  
        M[i][j] =0;
      }
    }

  return M;
 }



