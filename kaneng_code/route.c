#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "route.h"

void initRoute(ROUTE_T* route, int n)
	{
	route->length = n;
	route->lowerBound = INT_MAX;

	route->stopSequence = (int*) calloc(n, sizeof(int));
	}

void freeRoute(ROUTE_T* route)
	{
	free(route->stopSequence);
	free(route);
	}