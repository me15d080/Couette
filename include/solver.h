#ifndef MAKE_ZEROS_H
#define MAKE_ZEROS_H
double** make_zeros(int, int);
#endif

#ifndef SET_X_H
#define SET_X_H
double** set_x(double**, int , int , double , double );
#endif


#ifndef SET_Y_H
#define SET_Y_H
double** set_y(double**, int , int , double , double );
#endif


#ifndef SYMMETRY_U_H
#define SYMMETRY_U_H
double** symmetry_u(double**, int, int );
#endif

#ifndef SYMMETRY_V_H
#define SYMMETRY_V_H
double** symmetry_v(double**, int, int );
#endif

#ifndef GET_AX_H
#define GET_AX_H
double** get_ax(double**, double**, double**, int , int , double , double );
#endif

#ifndef GET_AY_H
#define GET_AY_H
double** get_ay(double**, double**, double**, int , int , double , double );
#endif

#ifndef GET_UT_H
#define GET_UT_H
double** get_ut(double**, double**, double**, int , int , double, double);
#endif

#ifndef GET_VT_H
#define GET_VT_H
double** get_vt(double**, double**, double**, int , int , double, double);
#endif

#ifndef GET_DX_H
#define GET_DX_H
double** get_dx(double**, double**, int , int , double , double);
#endif

#ifndef GET_DY_H
#define GET_DY_H
double** get_dy(double**, double**, int , int , double , double);
#endif

#ifndef GET_UTT_H
#define GET_UTT_H
double** get_utt(double**, double**, double**, int , int , double , double , double);
#endif

#ifndef GET_VTT_H
#define GET_VTT_H
double** get_vtt(double**, double**, double**, int , int , double , double , double);
#endif

#ifndef GET_P_H
#define GET_P_H
#include <cmath>
double** get_p(double**, double**, double**, double**, double**, int , int , double , double , double , double, double, double );
#endif

#ifndef CORRECT_U_H
#define CORRECT_U_H
double** correct_u(double**,double**, double**, int , int , double );
#endif

#ifndef CORRECT_V_H
#define CORRECT_V_H
double** correct_v(double**,double**, double**, int , int , double );
#endif

#ifndef GET_CONT_ERROR_H
#define GET_CONT_ERROR_H
#include <cmath>
double get_cont_error(double**,double**, double**, int , int , double , double ,double );
#endif


#ifndef PRINT_ARRAY_H
#define PRINT_ARRAY_H
#include <iostream>
using namespace std;
void print_array(double**, int, int);
#endif

#ifndef WRITE_DATA_H
#define WRITE_DATA_H
# include<iostream>
# include<iomanip>
# include<fstream>
# include<cstdio>
# include<stdlib.h>
using namespace std;
void write_data(int , 
                double** , int , int , char const*, 
                double** , int , int , char const*, 
                double** , int , int , char const* );
#endif


#ifndef CLEAN_ZEROS_H
#define CLEAN_ZEROS_H
void clean_zeros(double**, int);
#endif


