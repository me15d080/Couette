#include <cmath>
double** get_p(double**p, double** old_p, double** diff_p, double**utt, double**vtt, int nx, int ny, double p_err, double maxError, double dx, double dy, double dt, double rho )
{
   

   while (p_err>maxError)
         {

      // Pressure BCs
      for (int  j = 0; j < nx+1; j++)
          {
             p[0][j]=0;
          }
      for (int  j = 0; j < nx+1; j++)
          {
             p[ny][j]=0;
          }

      for (int  i = 0; i < ny+1; i++)
          {
             p[i][0]=0;
          }
      for (int  i = 0; i < ny+1; i++)
          {
             p[i][nx]=0;
          }

      for (int  i = 0; i < ny+1; i++)
          {
           for (int  j = 0; j < nx+1; j++)

               {
                old_p[i][j]=p[i][j];
               }

          }



      for (int  i = 1; i < ny; i++)
          {
           for (int  j = 1; j < nx; j++)

               {


                p[i][j]=((0.5*dy*dy)/(dx*dx+dy*dy))*(p[i][j+1]+p[i][j-1])+
                        ((0.5*dx*dx)/(dx*dx+dy*dy))*(p[i-1][j]+p[i+1][j])-
                        ((0.5*rho*dx*dx*dy*dy)/(dt*dx*dx+dt*dy*dy))*(utt[i][j+1]-utt[i][j])/dx + (vtt[i][j+1]-vtt[i+1][j+1])/dy;

               }

          }
     
     for (int  i = 1; i < ny; i++)
          {
           for (int  j = 1; j < nx; j++)

               {

                diff_p[i][j]=fabs(p[i][j]-old_p[i][j]);
                

               }

          }
 
     p_err=diff_p[1][1];

     for (int  i = 1; i < ny; i++)
          {
           for (int  j = 1; j < nx; j++)

               {

                if(diff_p[i][j] > p_err)
                 {
                  p_err  = diff_p[i][j];
                 }

               }

          }
     

         }

return p;

}


