/*==================================================
SET TABSTOPS AT EVERY FOUR SPACES FOR PROPER DISPLAY
====================================================*/

/****************************************************************************
* FILE: matrix.c
* DATE: June, 1993
* BY:   Andrew L. Thomas
*
* This file contains several functions for manipulating 3-component vectors
* and 3x3 matrices (1st and 2nd rank tensors).  The variable type assumed
* for vector and matrix components is set in the file matrix.h
*****************************************************************************/


/****************************** Includes/Defines ****************************/
#include	<math.h>
#include	"matrix.h"
#include	"nr.h"
#include	"nrutil.h"


/*************************** Function: matrix_mult ***************************
* Multiplies the 3x3 matrices a and b to obtain matrix c (i.e. c = ab).
*****************************************************************************/
void        matrix_mult(matrix_t a, matrix_t b, matrix_t c)
{
	int i,j,k;
	matrix_t a_copy;
	matrix_t b_copy;

	copy_matrix(a,a_copy);
	copy_matrix(b,b_copy);

	for (i=0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			c[i][j] = 0.;
			for (k=0; k < 3; k++) {
				c[i][j] += a_copy[i][k] * b_copy[k][j];
			}
		}
	}
}

/************************* Function: rotate_vector **************************
* Rotates the vector x to a new coord system using the rotation matrix a
*****************************************************************************/
void        rotate_vector(int inverse_rot, matrix_t a, vector_t x)
{
	matrix_t	a_copy;

	copy_matrix(a,a_copy);
	if (inverse_rot) {
		transpose_matrix(a_copy);
	}
	matrix_vector_mult(a_copy,x,x);
}


/************************ Function: matrix_vector_mult ***********************
* Multiplies the 3x3 matrices a and b to obtrain matrix c
*****************************************************************************/
void        matrix_vector_mult(matrix_t a, vector_t b, vector_t c)
{
	int		i, j;
	vector_t	tmp_b;

	copy_vector(b,tmp_b);
	for (i=0; i < 3; i++) {
		c[i] = 0.;
		for (j=0; j < 3; j++) {
			c[i] += a[i][j] * tmp_b[j];
		}
	}
}


/************************* Function: rotate_tensor **************************
* Rotates the tensor s to a new coord system using the rotation matrix a
*****************************************************************************/
void        rotate_tensor(int inverse_rot, matrix_t a, matrix_t s)
{
	matrix_t	a_copy;
	matrix_t	a_copy_trans;
	matrix_t	temp;

	copy_matrix(a,a_copy);
	if (inverse_rot) {
		transpose_matrix(a_copy);
	}
	copy_matrix(a_copy,a_copy_trans);
	transpose_matrix(a_copy_trans);

	matrix_mult(s,a_copy_trans,temp);
	matrix_mult(a_copy,temp,s);

}


/*************************** Function: dot_product ***************************
* Calculates the dot product of the vectors v1 and v2
*****************************************************************************/
component_t dot_product(vector_t v1, vector_t v2)
{
	return(v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2]);
}


/************************** Function: cross_product **************************
* Computes the cross product of vector1 and vector2, returning the result in
* vector3
*****************************************************************************/
void        cross_product(vector_t v1, vector_t v2, vector_t v3)
{
	int i, j, k;

	for (i=0; i < 3; i++) {
		j = i + 1;
		k = j + 1;
		if (j > 2)
			j -= 3;
		if (k > 2)
			k -= 3;
		v3[i] = v1[j]*v2[k] - v1[k]*v2[j];
	}
}


/*********************** Function: vector_magnitude **************************
* Calculates the magnitude of the vector v.
******************************************************************************/
component_t vector_magnitude(vector_t v)
{
	component_t mag;

	mag = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);

	return(mag);
}


/*********************** Function: subtract_vectors **************************
* Subtracts the vectors v2 and v1 to obtain v3
*****************************************************************************/
void        subtract_vectors(vector_t v1, vector_t v2, vector_t v3)
{

	int		i;

	for (i=0; i < 3; i++) {
		v3[i] = v1[i] - v2[i];
	}
}



/******************* Function: transform_position_vector *********************
* Transforms the position vector x to a new coordinate system with the given
* origin using the coordinate rotation matrix a.
******************************************************************************/
void        transform_position_vector(int inverse_trans, vector_t origin, matrix_t a,vector_t x)
{
/*
	if (inverse_trans) {
		rotate_vector(INVERSE_ROT,a,x);
		subtract_vectors(x,origin,x);
	}
	else {
		rotate_vector(FORWARD_ROT,a,x);
		add_vectors(x,origin,x);
	}
*/
	if (inverse_trans) {
		rotate_vector(INVERSE_ROT,a,x);
		add_vectors(x,origin,x);
	} else {
		subtract_vectors(x,origin,x);
		rotate_vector(FORWARD_ROT,a,x);
	}


}


/*************************** Function: transpose_matrix **********************
* Transposes the 3x3 matrix a.
*****************************************************************************/
void        transpose_matrix(matrix_t a)
{
	int i, j;
	matrix_t	a_copy;

	copy_matrix(a,a_copy);
	for (i=0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			a[i][j] = a_copy[j][i];
		}
	}
}


/************************ Function: initialize_matrix ***********************
* Initializes the matrix m using the given value.
****************************************************************************/
void        initialize_matrix(matrix_t m, component_t value)
{
	int		i, j;

	for (i=0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			m[i][j] = value;
		}
	}
}


/************************** Function: initialize_vector *********************
* Initializes the vector v using the given value
****************************************************************************/
void        initialize_vector(vector_t v, component_t value)
{
	int		i;

	for (i=0; i < 3; i++) {
		v[i] = value;
	}
}


/**************************** Function: add_matrices ************************
* Adds the 3x3 matrices m1 and m2 to obtain m3.
****************************************************************************/
void        add_matrices(matrix_t m1, matrix_t m2, matrix_t m3)
{
	int		i, j;

	for (i=0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			m3[i][j] = m1[i][j] + m2[i][j];
		}
	}
}


/*********************** Function: subtract_matrices ************************
* Subtracts the 3x3 matrices m1 and m2 to obtain m3
****************************************************************************/
void        subtract_matrices(matrix_t m1, matrix_t m2, matrix_t m3)
{
	int		i, j;

	for (i=0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			m3[i][j] = m1[i][j] - m2[i][j];
		}
	}
}
	

/************************* Function: add_vectors ****************************
* Adds the vectors v1 and v2 to obtain v3
*****************************************************************************/
void        add_vectors(vector_t v1, vector_t v2, vector_t v3)
{

	int		i;

	for (i=0; i < 3; i++) {
		v3[i] = v1[i] + v2[i];
	}
}


/************************** Function: copy_vector ***************************
* Copies the vector v to v_copy
****************************************************************************/
void        copy_vector(vector_t v, vector_t v_copy)
{
	int		i;

	for (i=0; i < 3; i++) {
		v_copy[i] = v[i];
	}
}


/************************** Function: copy_matrix ***************************
* Copies the matrix m to m_copy.
****************************************************************************/
void        copy_matrix(matrix_t m, matrix_t m_copy)
{
	int		i, j;

	for (i=0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			m_copy[i][j] = m[i][j];
		}
	}
}


/*********************** Function: scalar_vector_mult ***********************
* Multiplies the vector v1 by the scalar s to obtain the vector v2.
****************************************************************************/
void        scalar_vector_mult(component_t s, vector_t v1, vector_t v2)
{
	int		i;

	for (i=0; i < 3; i++) {
		v2[i] = s * v1[i];
	}
}


/*********************** Function: scalar_matrix_mult ***********************
* Multiplies the 3x3 matrix m1 by the scalar s to obtain the 3x3 matrix m2.
****************************************************************************/
void        scalar_matrix_mult(component_t s, matrix_t m1, matrix_t m2)
{
	int		i, j;

	for (i=0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			m2[i][j] = s * m1[i][j];
		}
	}
}


/*********************** Function: normalize_vector ************************
* Normalizes the vector v.
****************************************************************************/
void        normalize_vector(vector_t v)
{
	scalar_vector_mult(1/vector_magnitude(v),v,v);
}


/**************************** Function: cauchy ******************************
* Calculates the traction vector traction_v on a plane with unit normal vector
* normal_v due to the stress tensor stress.
*****************************************************************************/
void        cauchy(matrix_t stress, vector_t normal_v, vector_t traction_v)
{
	int		i,j;

	initialize_vector(traction_v,0.0);
	for (i=0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			traction_v[i] += stress[j][i] * normal_v[j];
		}
	}
}


/************************** Function: principal ******************************
* Calculates the magnitudes, prin, and directions, traj, of principal
* strains/stresses given the stress/strain tensor, str.
*
* Uses functions d_jacobi and d_eigsrt adapted by permission from the book:
*
*		Numerical Recipes in C: The Art of Scientific Computing, 2nd Ed.
*		Press, W.H., Teukolsky, S.A., Vetterling, W.T. & Flannery, B.P.
*		1992, Cambridge University Press, Cambridge, 994 p.
*****************************************************************************/
void        principal(matrix_t str, vector_t prin, matrix_t traj)
{
	double	**nr_str;
	double	*nr_prin;
	double	**nr_traj;
	int		nrot;
	int		i, j;

	nr_str    = dmatrix(1,3,1,3);
	nr_prin   = dvector(1,3);
	nr_traj   = dmatrix(1,3,1,3);

	for (i=0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			nr_str[i+1][j+1] = str[i][j];
		}
	}

	d_jacobi(nr_str,3,nr_prin,nr_traj,&nrot);
	d_eigsrt(nr_prin,nr_traj,3);

	for (i=0; i < 3; i++) {
		prin[i] = nr_prin[i+1];
		for (j=0; j < 3; j++) {
			traj[i][j] = nr_traj[j+1][i+1];
		}
	}

	free_dmatrix(nr_str,1,3,1,3);
	free_dvector(nr_prin,1,3);
	free_dmatrix(nr_traj,1,3,1,3);
}



/************************** Function: distance *********************
* return distance from point v to point w
****************************************************************************/
float distance(vector_t v, vector_t w)
{
   int i;
   float d = 0;

   for (i=0; i < 3; i++)
		d += (v[i] - w[i])*(v[i] - w[i]);
	
   return sqrt(d);
}
