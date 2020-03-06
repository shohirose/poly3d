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
#ifndef POLY3D_NR_H
#define POLY3D_NR_H

/************************* Function Declarations ****************************/
void d_eigsrt(double d[], double **v, int n);
void d_lubksb(double **a, int n, int *indx, double b[]);
void d_ludcmp(double **a, int n, int *indx, double *d);
void d_jacobi(double **a, int n, double d[], double **v, int *nrot);

#endif  // POLY3D_NR_H
