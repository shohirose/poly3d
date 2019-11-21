/*==================================================
SET TABSTOPS AT EVERY FOUR SPACES FOR PROPER DISPLAY
====================================================*/

/****************************************************************************
* FILE: safetan.h
* DATE: June, 1993
* BY:	Andrew L. Thomas
*
* Header file for safetan.c
*****************************************************************************/
#ifndef POLY3D_SAFETAN_H
#define POLY3D_SAFETAN_H

/******************************** Constants *********************************/
#define SAFE_ATAN_LIMIT	1e+20			/* max y/x for atan, atan2			*/
#define SAFE_TAN_LIMIT	1e-11			/* closest a in tan(a) is allowed	*/
										/*   to N*PI/2, N = +/- 1,2,3,...	*/


/****************************** Type Definitions ****************************/
typedef double safetan_t;


/************************* ANSI Function declarations ***********************/
safetan_t	safe_atan(double y, double x);
safetan_t	safe_atan2(double y, double x);
safetan_t	safe_tan(double alpha);

#endif // POLY3D_SAFETAN_H