#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "A2DConverter.h"


TEST_CASE("test1-no definition") {
   int sampleArray[] ={900,650,550,740,640};
   int startRangeValue = 2;
   int endRangeValue = 5;
   REQUIRE(getA2DInRangeValue(sampleArray,10,startRangeValue,endRangeValue,5) == 2);
}

TEST_CASE("test2 2 different consecutive readings") {
   int sampleArray[] ={900,650,550,740,640,650,640};
   int startRangeValue = 2;
   int endRangeValue = 5;
   REQUIRE(getA2DInRangeValue(sampleArray,10,startRangeValue,endRangeValue,7) == 4);
}
   
TEST_CASE("test3 - No continuous reading found") {
   int sampleArray[] ={900,650,550,740,630};
   int startRangeValue = 2;
   int endRangeValue = 5;
   REQUIRE(getA2DInRangeValue(sampleArray,10,startRangeValue,endRangeValue,5) == 2);
}

TEST_CASE("test4 - checking if all the sensor values are giving valid current ranges for 12 bit ") {
   int sampleArray[] ={1146,4094, 2045};
   int startRangeValue = 2;
   int endRangeValue = 5;
   REQUIRE(getA2DInRangeValue(sampleArray,12,startRangeValue,endRangeValue,3) == 4);
}

TEST_CASE("test5 - No valid values for 12 bit a2d") {
   int sampleArray[] ={4095};
   int startRangeValue = 2;
   int endRangeValue = 5;
   REQUIRE(getA2DInRangeValue(sampleArray,12,startRangeValue,endRangeValue,1) == 1);
}

TEST_CASE("test5 - No valid values for 10 bit a2d") {
   int sampleArray[] ={1024};
   int startRangeValue = 2;
   int endRangeValue = 5;
   REQUIRE(getA2DInRangeValue(sampleArray,10,startRangeValue,endRangeValue,1) == 1);
}
