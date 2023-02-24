#include "A2DConverter.h"

bool getActualChargeOrDischargeCurrentVaule_10A2D(int*sensorData,int * currentInAmps)
{
    float currentValue = 0.0;
    int CurrentRoundedValue = 0;
    
    if((*sensorData < 1024)&&(*sensorData >=0))
    {
        currentValue = ((30  * (*sensorData)) / 1023);
        CurrentRoundedValue = round(currentValue);
        *currentInAmps = abs(CurrentRoundedValue - 15);
        
        return 1;
    }
    else
    {
        return 0;
    }
}

bool  getActualCurrentvalue_12A2D(int*sensorData,int * currentInAmps)
{
    float currentvalue = 0.0;
    float currentvalue1 = 0.0;
    if((*sensorData < 4095) &&(*sensorData >=0))
    {
        currentvalue = (10  * (*sensorData ));
        currentvalue1 = (currentvalue / 4094);
        *currentInAmps = round(currentvalue1);
        
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int ConvertToCurrentRange(int bitInput ,int*sensorData)
{
    
    bool isvalueInRange = 0;
    int currentValue = 0;

    if(bitInput == 10)
    {
        isvalueInRange =getActualChargeOrDischargeCurrentVaule_10A2D(sensorData,&currentValue);      
    }
    else 
    {
        //(bitInput == 12)
        isvalueInRange = getActualCurrentvalue_12A2D(sensorData,&currentValue);
    }

    if( isvalueInRange == 1)
    {
        return currentValue;
    }
    else
    {
        return -1;
    }
}
int getA2DInRangeValue(int* sensorData,int inputBit ,int startRange, int endRange,int noOfValues)
{
   
    int currentValue[noOfValues] ={0};
    int noOfValueInRequestedRange= 0;
    
    
    for(int i = 0; i< noOfValues ; i++)
    {
        currentValue[i] = ConvertToCurrentRange(inputBit ,&sensorData[i]);
    }
    
    noOfValueInRequestedRange = getNoOfRValuesInRange(currentValue,startRange ,endRange);
    return noOfValueInRequestedRange;
}
