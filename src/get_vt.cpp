double** get_vt(double**vt, double**Ay, double**v, int nx, int ny, double gy, double dt)

{
    for (int j=0;j<nx+3;j++)

    {
         for (int i=0;i<ny+2;i++)

         {
           
           vt[i][j]= v[i][j] -dt* Ay[i][j] + dt*gy;
         }

    }

     return vt;     
}

