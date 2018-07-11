double** get_dx(double**Dx, double**ut, int nx, int ny, double dx, double dy)
{
    for (int j=1;j<nx+1;j++)

    {
         for (int i=1;i<ny;i++)

         {
          Dx[i][j]=(1/(dx*dy))*  ( (ut[i][j+1]-ut[i][j]  )*( dy/dx)  +     //  flux through right face
                                   (ut[i][j]  -ut[i][j-1])*(-dy/dx)  +     //  flux through left face
                                   (ut[i-1][j]-ut[i][j]  )*( dx/dy)  +     //  flux through top face
                                   (ut[i][j]  -ut[i+1][j])*(-dx/dy)   );   //  flux through bottom face         
 
          
         }

    }

     return Dx;     
}

