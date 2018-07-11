double** get_ax(double**Ax, double**u, double**v, int nx, int ny, double dx, double dy)
{

 for (int j=1;j<nx+1;j++)

     {
      for (int i=1;i<ny;i++)

          {
           Ax[i][j]=(1/(dx*dy))*( ( (0.5*(u[i][j]+u[i][j+1])) * ( 0.5*(u[i][j]  +u[i][j+1])  *dy) )+   // Flux through right face
                                  ( (0.5*(u[i][j]+u[i][j-1])) * (-0.5*(u[i][j]  +u[i][j-1])  *dy) )+   // Flux through left face
                                  ( (0.5*(u[i][j]+u[i-1][j])) * ( 0.5*(v[i][j]  +v[i][j+1])  *dx) )+   // Flux through top face
                                  ( (0.5*(u[i][j]+u[i+1][j])) * (-0.5*(v[i+1][j]+v[i+1][j+1])*dx) )  );// Flux through bottom face



          }

     }

     return Ax;     
}

