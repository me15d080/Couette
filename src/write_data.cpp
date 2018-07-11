# include<iostream>
# include<iomanip>
# include<fstream>
# include<cstdio>
# include<stdlib.h>
using namespace std;
void write_data(int iteration, 
                double** M1, int row1, int col1, char const* ch1,
                double** M2, int row2, int col2, char const* ch2,
                double** M3, int row3, int col3, char const* ch3)
{

// Create a folder

 //double t = iteration*dt;
 char command[50];
 sprintf(command,"mkdir /home/vikas/Desktop/Couette_flow/output/%d",iteration);
 system (command);

// Create files

 char fname1[50];
 //sprintf(fname, "%s_%d.txt",ch ,iteration);
 sprintf(fname1, "/home/vikas/Desktop/Couette_flow/output/%d/%s",iteration,ch1);
 ofstream fout1;
 fout1.open(fname1);

 for(int i = 0; i < row1; i++)
    {
     for(int j = 0; j < col1; j++)
         {
          fout1.precision(18); 
          fout1 << M1[i][j]; 
          fout1 << "\n";      
         }
       
    }

fout1.close();

/*------------------------------*/

 char fname2[50];
 sprintf(fname2, "/home/vikas/Desktop/Couette_flow/output/%d/%s",iteration,ch2);
 ofstream fout2;
 fout2.open(fname2);

 for(int i = 0; i < row2; i++)
    {
     for(int j = 0; j < col2; j++)
         {
          fout2.precision(18); 
          fout2 << M2[i][j]; 
          fout2 << "\n";      
         }
       
    }

fout2.close();

/*------------------------------*/

 char fname3[50];
 sprintf(fname3, "/home/vikas/Desktop/Couette_flow/output/%d/%s",iteration,ch3);
 ofstream fout3;
 fout3.open(fname3);

 for(int i = 0; i < row3; i++)
    {
     for(int j = 0; j < col3; j++)
         {
          fout3.precision(18); 
          fout3 << M3[i][j]; 
          fout3 << "\n";      
         }
       
    }

fout3.close();
}
