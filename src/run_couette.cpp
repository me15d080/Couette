/*************************************************/
/*             COUETTE FLOW                      */    
/*************************************************/

#include "solver.h"
#include <iomanip>
#include <cmath> 
#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
  char const* ch1="u"; char const* ch2="v"; char const* ch3="p"; 
  double      Lx, Ly, gx, gy, rho, mu, dx, dy, dt, tmax, maxError, t, p_err, continuity_error;
  int         nx, ny, iteration, nstep;
/*--Read user input--------------*/

  ifstream input_file;
  input_file.open("/home/vikas/Desktop/Couette_flow/input/user_input");

  input_file >> Lx;  
  input_file >> Ly;
  input_file >> gx;
  input_file >> gy;
  input_file >> rho;
  input_file >> mu;

  input_file >> nx;
  input_file >> ny;
  input_file >> dt;
  input_file >> nstep;
  input_file >> maxError;  
  input_file >> p_err;
               
  input_file.close();
/*-------------------------------*/
  dx=Lx/nx;
  dy=Ly/ny;  
  tmax=nstep*dt;
  
/*--Pre-Allocate Arrays--*/
  double** p       = make_zeros (ny+1, nx+1);
  double** xp      = make_zeros (ny+1, nx+1);
  double** yp      = make_zeros (ny+1, nx+1);
  double** old_p   = make_zeros (ny+1, nx+1);
  double** div_vel = make_zeros (ny+1, nx+1);
  double** diff_p  = make_zeros (ny+1, nx+1);

  double** u       = make_zeros (ny+1, nx+2);
  double** xu      = make_zeros (ny+1, nx+2);
  double** yu      = make_zeros (ny+1, nx+2);
  double** ut      = make_zeros (ny+1, nx+2);
  double** utt     = make_zeros (ny+1, nx+2);
  double** Ax      = make_zeros (ny+1, nx+2);
  double** Dx      = make_zeros (ny+1, nx+2);
  

  double** v       = make_zeros (ny+2, nx+3);
  double** xv      = make_zeros (ny+2, nx+3);
  double** yv      = make_zeros (ny+2, nx+3);
  double** vt      = make_zeros (ny+2, nx+3);
  double** vtt     = make_zeros (ny+2, nx+3);
  double** Ay      = make_zeros (ny+2, nx+3);
  double** Dy      = make_zeros (ny+2, nx+3);

/*-- Set the Grid--*/
  xp = set_x (xp, ny+1, nx+1, 0  , dx);                  //print_array(xp, ny+1, nx+1);
  yp = set_y (yp, ny+1, nx+1, Ly , dy);                  //print_array(yp, ny+1, nx+1);
  xu = set_x (xu, ny+1, nx+2, -0.5*dx, dx);
  yu = set_y (yu, ny+1, nx+2, Ly , dy);
  xv = set_x (xv, ny+2, nx+3, -dx, dx);
  yv = set_y (yv, ny+2, nx+3, Ly+0.5*dy,dy);

/*--Initial Conditions--*/
for (int  j = 0; j < nx+2; j++)
{
  u[0][j]=1; // also serves as top BC
}

/*--START TIME LOOP--*/

  t=0;
  iteration=1;
  while (t<tmax)

{
/*-----Symmetry BCs----*/
  u = symmetry_u(u, nx, ny);
  v = symmetry_v(v, nx, ny);   
  
/*-- Advection step--*/
  Ax = get_ax(Ax, u, v, nx, ny, dx, dy);
  Ay = get_ay(Ay, u, v, nx, ny, dx, dy);
  ut = get_ut(ut, Ax, u, nx, ny, gx, dt);
  vt = get_vt(vt, Ay, v, nx, ny, gy, dt);

/*-- Diffusion step--*/
  Dx = get_dx(Dx, ut, nx, ny, dx, dy);
  Dy = get_dy(Dy, vt, nx, ny, dx, dy);
  utt = get_utt(utt, Dx, ut, nx, ny, rho, mu, dt);
  vtt = get_vtt(vtt, Dy, vt, nx, ny, rho, mu, dt);

/*-- Pressure  step--*/
  p = get_p(p, old_p, diff_p, utt, vtt, nx, ny, p_err, maxError, dx, dy, dt, rho);

/*-- Velocity correction step--*/
  u = correct_u(u, utt, p, nx, ny, dx);
  v = correct_v(v, vtt, p, nx, ny, dy);

/*-- Check incompressibility --*/
  continuity_error = get_cont_error(div_vel, u, v, nx, ny, dx, dy,continuity_error);

/*-- Write the data file--*/
  write_data(iteration,u, ny+1, nx+2, ch1,v, ny+2, nx+3, ch2, p, ny+1, nx+1, ch3);

/*-- Screen Output---*/

//     cout<< setw(3)<< iteration <<"  "<<setw(4) << continuity_error << endl;

/*-- Increment ---*/
  t = t + dt;
  iteration=iteration+1;

}


/*-- Clean-up Arrays--*/

  clean_zeros (p, ny+1);
  clean_zeros (xp, ny+1);
  clean_zeros (yp, ny+1);
  clean_zeros (old_p,ny+1);
  clean_zeros (diff_p,ny+1);
  clean_zeros (div_vel,ny+1);

  clean_zeros (u, ny+1);
  clean_zeros (xu, ny+1);
  clean_zeros (yu, ny+1);
  clean_zeros (ut, ny+1);
  clean_zeros (utt, ny+1);
  clean_zeros (Ax, ny+1);
  clean_zeros (Dx, ny+1);

  clean_zeros (v, ny+2);
  clean_zeros (xv, ny+2);
  clean_zeros (yv, ny+2);
  clean_zeros (vt, ny+2);
  clean_zeros (vtt, ny+2);
  clean_zeros (Ay, ny+2);
  clean_zeros (Dy, ny+2);

return 0;
}
