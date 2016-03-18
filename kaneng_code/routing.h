#ifndef ROUTING_H_INCLUDED
#define ROUTING_H_INCLUDED

#include "dataStructure.h"

ROUTE_T genRoute(COSTMATRIX_T costMatrix);

int calcLowerBound(ROUTE_T route, COSTMATRIX_T costMatrix);

#endif