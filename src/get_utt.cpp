double** get_utt(double**utt, double**Dx, double**ut, int nx, int ny, double rho, double mu, double dt)
{

    for (int j=0;j<nx+2;j++)

    {
         for (int i=0;i<ny+1;i++)

         {
           
          utt[i][j]= ut[i][j] +(dt/rho)*mu* Dx[i][j];

        }

    }

     return utt;     
}

