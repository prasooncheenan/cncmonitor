#include "paramchecker.h"
#include <gtest/gtest.h>
 
/*TEST(VitalsTest, BPM) { 
    ASSERT_EQ(true, vitalsAreOk(100, 100, 50));
}*/
 

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
