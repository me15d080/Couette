double** get_ut(double**ut, double**Ax, double**u, int nx, int ny, double gx, double dt)
{

    for (int j=0;j<nx+2;j++)

    {
         for (int i=0;i<ny+1;i++)

         {
           
          ut[i][j]= u[i][j] -dt* Ax[i][j] + dt*gx;


        }

    }

     return ut;     
}

