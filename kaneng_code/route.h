#ifndef ROUTE_H_INCLUDED
#define ROUTE_H_INCLUDED

typedef struct _route
	{
	int length;
	int* stopSequence;
	double lowerBound;
	} ROUTE_T;

void initRoute(ROUTE_T* route, int n);

void freeRoute(ROUTE_T* route)

#endif