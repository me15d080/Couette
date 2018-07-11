double** set_y(double**M,int row, int col, double y_max, double dy)
{
  for(int j = 0; j < col; j++)
     {
      for(int i = 0; i < row; i++)
         {
          M[i][j] = y_max - i*dy;        
         }    
     }
     return M;   
}



