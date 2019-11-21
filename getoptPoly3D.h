/*================================================== 
SET TABSTOPS AT EVERY FOUR SPACES FOR PROPER DISPLAY
====================================================*/

/***************************************************************************** 
* FILE: getoptPoly3D.c
* DATE: June, 1993 
* BY:   Andrew L. Thomas 
*
* Header file for getopt.c
*****************************************************************************/

#ifndef POLY3D_GETOPTPOLY3D_H
#define POLY3D_GETOPTPOLY3D_H

/***************************** Includes/Defines ******************************/

#define FILE_ARG 0
#define FLAG 1
#define FLAG_AND_FILE 2
#define NO_MORE_ARGS -1
#define NO_SUCH_ARG -2


/********************************* Structures ********************************/
struct arg_rec {
	char flag_name;
	char arg_type;
	struct arg_rec *next_rec;
	char *file_arg;
};


/******************************* External Variables **************************/
extern char *getopt_arg_E;


/****************************** Function Declarations ************************/
int getoptPoly3D(char *arg_string, int argc, char *argv[]);

#endif // POLY3D_GETOPTPOLY3D_H