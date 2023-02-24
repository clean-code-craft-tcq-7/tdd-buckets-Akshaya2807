#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "CheckRange.h"

int getA2DInRangeValue(int* sensorData,int inputBit ,int startRange, int endRange,int noOfValues);
int ConvertToCurrentRange(int bitInput ,int*sensorData);
bool  getActualCurrentvalue_12A2D(int*sensorData,int * currentInAmps);
bool getActualChargeOrDischargeCurrentVaule_10A2D(int*sensorData,int * currentInAmps);
