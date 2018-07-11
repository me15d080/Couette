void clean_zeros(double**M, int row)
{
for (int  i = 0; i < row; i++)
    {
     delete [] M[i];
    }
 delete [] M;
}



