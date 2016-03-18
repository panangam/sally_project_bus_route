#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "dataStructures.h"
#include "priorityQueue.h"
#include "costMatrix.h"
#include "route.h"

#define EARTHCIRC 40075

ROUTE_T* genRoute(COSTMATRIX_T timeMatrix, 
				 COSTMATRIX_T distanceMatrix, 
			   	 int timeWeight, int distanceWeight)
	{
	int n;
	COSTMATRIX_T costMatrix;
	int i;
	ROUTE_T* tempRoute;
	int bestCost = INT_MAX;
	ROUTE_T* bestRoute = NULL;

	newMatrix = genCostMatrix(timeMatrix, distanceMatrix, timeWeight, distanceWeight);

	for (i = 0; i < n; i++)
		{
		tempRoute = (ROUTE_T*) calloc(1, sizeof(ROUTE_T));
		initRoute(tempRoute, 1);
		tempRoute->stopSequence[0] = i;
		tempRoute->lowerBound = calcLowerBound(tempRoute, costMatrix);

		pqPush(tempRoute, calcPriority(tempRoute)); /* TODO: implement this function */
		}

	while (pqNotEmpty())
		{
		ROUTE_T* poppedRoute;
		ROUTE_T* routeToPush;
		int j;

		poppedRoute = (ROUTE_T*) pqPop();

		if (poppedRoute->lowerBound < bestCost) /* finish this loop! */
			{
			if (poppedRoute->length < n) /* not a finish route yet */
				{
				for (j = 0; j < n; j++)
					{
					if (stopNotExist(route, i)) /* TODO: implement */
						{
						routeToPush = (ROUTE_T*) calloc(1, sizeof(ROUTE_T));
						initRoute(routeToPush, poppedRoute->length+1);
						memcpy(routeToPush->stopSequence, poppedRoute->stopSequence, sizeof(int)*poppedRoute->length);
						routeToPush->stopSequence[routeToPush->length] = i;
						routeToPush->lowestCost = calcLowerBound(routeToPush, costMatrix);

						pqPush(routeToPush, calcPriority(routeToPush, costMatrix));
						}
					}
				}
			else /* this is a complete route */
				{
				int cost;

				cost = calcCost(poppedRoute, costMatrixt) /* TODO: implement */
				if (cost < bestCost)
					{
					bestRoute = poppedRoute;
					}
				}
		freeRoute(poppedRoute);
		}

	return bestRoute;
	}

int calcPriority(ROUTE_T* route)
	{
	int priority;

	priority = route->length*EARTHCIRC + route->lowerBound;
	return priority;
	}


int calcLowerBound(ROUTE_T route, COSTMATRIX_T costMatrix)
	{
	print("calcLowerBound\n");
	return 0;
	}