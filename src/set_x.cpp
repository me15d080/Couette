double** set_x(double**M,int row, int col, double x_min, double dx)
{

  for(int i = 0; i < row; i++)
     {
      for(int j = 0; j < col; j++)
         {
          M[i][j] = x_min + j*dx;        
         }    
     }
     return M;     
}



