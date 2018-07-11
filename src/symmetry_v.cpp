double** symmetry_v(double**v, int nx, int ny)
{
 for (int  i = 0; i < ny+2; i++)//Left
          {
             v[i][0]=v[i][1];
          }

 for (int  i = 0; i < ny+2; i++)//Right
          {
             v[i][nx+2]=v[i][nx+1];
          }

 return v;
}

