# include<cmath>
double get_cont_error(double**div_vel,double**u, double**v, int nx, int ny, double dx, double dy,double continuity_error)
{

     for (int j=1;j<nx;j++)
         {
          for (int i=1; i<ny;i++)
             {

               div_vel[i][j]=fabs((u[i][j]-u[i][j-1])/dx +  (v[i-1][j]-v[i][j])/dy);

 
             }
         }


     
     continuity_error=div_vel[1][1];

     for (int j=1;j<nx;j++)
         {
          for (int i=1; i<ny;i++)
             {

               if(div_vel[i][j] > continuity_error)
                 {
                  continuity_error  = div_vel[i][j];
                 }

 
             }
         }


     return continuity_error;     
}

