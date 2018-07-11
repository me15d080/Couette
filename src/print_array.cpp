#include <iostream>
using namespace std;
void print_array(double**M, int row, int col)
{
  for(int i = 0; i < row; i++)
     {
      for(int j = 0; j < col; j++)
         {
                  cout<< " "<<M[i][j];
         }
      cout<<endl;    
     }
          
}



