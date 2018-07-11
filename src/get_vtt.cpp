double** get_vtt(double**vtt, double**Dy, double**vt, int nx, int ny, double rho, double mu, double dt)
{

    for (int j=0;j<nx+3;j++)

    {
         for (int i=0;i<ny+2;i++)

         {
           
           vtt[i][j]= vt[i][j] +(dt/rho)*mu* Dy[i][j];
         }

    }

     return vtt;     
}

