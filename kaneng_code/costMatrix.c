#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataStructure.h"
#include "costMatrix.h"

void initMatrix(COSTMATRIX* matrix, int n)
	{
	int i;

	matrix->data = (int**) calloc(n, sizeof(int*));

	for (i = 0; i < n; i++)
		{
		matrix->data[i] = (int*) calloc(n, sizeof(int));
		}

	matrix->length = n;

	return matrix;
	}
	

void freeMatrix(COSTMATRIX* matrix)
	{
	int i;
	int n = matrix->length;

	if (matrix != NULL)
		{
		for (i = 0; i < n; i++)
			{
			free(matrix->data[i]);
			}
		free(matrix->data);
		}
	}

COSTMATRIX_T genCostMatrix(COSTMATRIX_T timeMatrix, 
						   COSTMATRIX_T distanceMatrix, 
						   int timeWeight, int distanceWeight)
	{
	COSTMATRIX_T newMatrix;
	int bOK = 1;
	int i, j;
	int n;
	int newCost;

	newMatrix.length = -1;

	if (timeMatrix.length != distanceMatrix.length
		bOK = 0;
	if (timeMatrix.length < 1 || distanceMatrix.length < 1)
		bOK = 0;
	if (!bOK)
		return newMatrix;

	initMatrix(&newMatrix, n);
	n = timeMatrix.length;
	for (i = 0; i < n; i++)
		{
		for (j = 0; j < n; j++)
			{
			newCost = timeMatrix.data[i][j]*timeWeight + distanceMatrix.data[i][j]*distanceWeight;
			newMatrix.data[i][j] = newCost;
			}
		}

	return newMatrix;
	}