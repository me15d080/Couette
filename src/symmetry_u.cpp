double** symmetry_u(double**u, int nx, int ny)
{     
for (int  i = 0; i < ny+1; i++)//Left
    {
     u[i][0]=u[i][1];
    }
      
      
for (int  i = 0; i < ny+1; i++)//Right
    {
     u[i][nx+1]=u[i][nx];
    }
return u;
}     
