// my_sin.cpp: определяет точку входа для приложения.
//

#include <gtest/gtest.h>
#include "task.h"
using namespace std;
TEST(stack_lib_test, even_number)
{
    vector<int> v = {4,3,2,1};
    vector<int> v_sort = { 1,2,3,4 };
    testspace::Sort(v);
    ASSERT_EQ(v, v_sort);
}
TEST(stack_lib_test, odd_number)
{
    vector<int> v = {4,3,5,2,1};
    vector<int> v_sort = { 1,2,3,4,5 };
    testspace::Sort(v);
    ASSERT_EQ(v, v_sort);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}