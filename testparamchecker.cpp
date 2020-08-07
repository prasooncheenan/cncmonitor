#include "paramchecker.h"
#include <gtest/gtest.h>
 

TEST(CNCParameterTest,TemperatureOK)
{
   ASSERT_EQ("",CheckLimits(0,20));
}

TEST(CNCParameterTest,TemperatureNOTOK)
{
   ASSERT_NE("",CheckLimits(0,40));
}

TEST(CNCParameterTest,VarianceOK)
{
   ASSERT_EQ("",CheckLimits(1,0.02));
}

TEST(CNCParameterTest,VarianceNOTOK)
{
   ASSERT_NE("",CheckLimits(1,0.06));
}

TEST(CNCParameterTest,TotalTimeOK)
{
   ASSERT_EQ("",CheckLimits(2,350));
}

TEST(CNCParameterTest,TotalTimeNOTOK)
{
   ASSERT_NE("",CheckLimits(2,370));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
