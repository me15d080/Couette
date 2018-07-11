double** correct_v(double**v,double**vtt, double**p, int nx, int ny, double dy)
{

     for (int j=1;j<nx+2;j++)
         {
          for (int i=1; i<ny+1;i++)
             {

                v[i][j]= vtt[i][j]-(p[i-1][j-1]-p[i][j-1])/dy;
 
             }
         }

     return v;     
}

