/*==================================================
SET TABSTOPS AT EVERY FOUR SPACES FOR PROPER DISPLAY
====================================================*/

/*****************************************************************************
* FILE: infcoeff.h
* DATE: June, 1993
* BY:   Andrew L. Thomas
*
* Header file for infcoeff.c
*****************************************************************************/
#ifndef POLY3D_INFCOEFF_H
#define POLY3D_INFCOEFF_H

/********************************* Constants ********************************/
#define COMNINOU_TINY 1.0e-14

/******************************* Function Declarations **********************/
void	comninou_displ_ics(double y[3], double a, double beta,
		double pr, int half_space, double displ_ic[3][3]);
void	comninou_strain_ics(double y[3], double a, double beta,
		double pr, int half_space, double strain_ic[3][3][3]);

#endif // POLY3D_INFCOEFF_H