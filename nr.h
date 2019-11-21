/*==================================================
SET TABSTOPS AT EVERY FOUR SPACES FOR PROPER DISPLAY
====================================================*/

/****************************************************************************
* FILE: nr.h
* DATE: June, 1993
* BY:   Andrew L. Thomas
*
* Header file for nr.c
*****************************************************************************/
#ifndef _NR_H_
#define _NR_H_


/************************* Function Declarations ****************************/
void	d_eigsrt(double d[], double **v, int n);
void	d_lubksb(double **a, int n, int *indx, double b[]);
void	d_ludcmp(double **a, int n, int *indx, double *d);
void	d_jacobi(double **a, int n, double d[], double **v, int *nrot);

#endif /* _NR_H_ */
