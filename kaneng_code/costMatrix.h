#ifndef COST_MATRIX_H_INCLUDED
#define COST_MATRIX_H_INCLUDED

typedef struct _costmatrix
	{
	int length;
	int** data;
	} COSTMATRIX_T;

COSTMATRIX* allocMatrix(int n);

void freeMatrix(COSTMATRIX* matrix);

COSTMATRIX_T genCostMatrix(COSTMATRIX_T timeMatrix, COSTMATRIX_T distanceMatrix, int timeWeight, int distanceWeight);

#endif /* COST_MATRIX_H_INCLUDED */