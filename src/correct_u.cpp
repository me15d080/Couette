double** correct_u(double**u,double**utt, double**p, int nx, int ny, double dx)
{

     for (int j=1;j<nx+1;j++)
         {
          for (int i=1; i<ny;i++)
             {
               u[i][j]=utt[i][j]-(p[i][j]-p[i][j-1])/dx;
 
             }
         }

     return u;     
}

