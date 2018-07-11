double** get_dy(double**Dy, double**vt, int nx, int ny, double dx, double dy)
{

   for (int j=1;j<nx+2;j++)

    {
         for (int i=1;i<ny+1;i++)

         {
           Dy[i][j]=(1/(dx*dy))*  ( (vt[i][j+1]-vt[i][j] ) *( dy/dx)  +   //flux through right face
                                    (vt[i][j]  -vt[i][j-1])*(-dy/dx)  +   //flux through left face
                                    (vt[i-1][j]-vt[i][j]  )*( dx/dy)  +   //flux through top face
                                    (vt[i][j]  -vt[i+1][j])*(-dx/dy)   ); //flux through bottom face

         }

    }

     return Dy;     
}

