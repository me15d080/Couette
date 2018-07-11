double** get_ay(double**Ay, double**u, double**v, int nx, int ny, double dx, double dy)
{

    for (int j=1;j<nx+2;j++)

    {
         for (int i=1;i<ny+1;i++)

         {
           Ay[i][j]=(1/(dx*dy))*( ( (0.5*(v[i][j]+v[i][j+1])) * ( 0.5*(u[i-1][j]   +u[i][j]  )  *dy) )+   // Flux through right face
                                  ( (0.5*(v[i][j]+v[i][j-1])) * (-0.5*(u[i-1][j-1] +u[i][j-1])  *dy) )+   //Flux through left face
                                  ( (0.5*(v[i][j]+v[i-1][j])) * ( 0.5*(v[i][j]     +v[i-1][j]  )*dx) )+   // Flux through top face
                                  ( (0.5*(v[i][j]+v[i+1][j])) * (-0.5*(v[i][j]     +v[i+1][j]  )*dx) )  );//Flux through bottom face

         }

    }

     return Ay;     
}

