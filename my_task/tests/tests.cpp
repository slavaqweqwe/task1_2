
#include <gtest/gtest.h>
#include "task.h"

#include <random>
#include <chrono>
#include <algorithm>
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
TEST(stack_lib_test, one_zero)
{
    vector<int> v = { 1,0,1,0,-1,0,1 };
    vector<int> v_sort = { -1,0,0,0,1,1,1 };
    testspace::Sort(v);
    ASSERT_EQ(v, v_sort);
}
TEST(stack_lib_test, random)
{
    static std::mt19937_64 gen{
    static_cast<unsigned long long>(
                std::chrono::system_clock::now().time_since_epoch().count()) };
    int A = -20, B = 20;
    std::uniform_int_distribution<int> dis(A, B);

    vector<int> v = { dis(gen),dis(gen),dis(gen),dis(gen),dis(gen),dis(gen),dis(gen),dis(gen),dis(gen),dis(gen) };
    vector<int> v_sort = v;
    sort(v_sort.begin(), v_sort.end());
    testspace::Sort(v);
    ASSERT_EQ(v, v_sort);
}
TEST(stack_lib_test, sort)
{
    vector<int> v = { -1,0,1,2,3,3,4 };
    vector<int> v_sort = { -1,0,1,2,3,3,4 };
    testspace::Sort(v);
    ASSERT_EQ(v, v_sort);
}
TEST(stack_lib_test, all_neg1)
{

    vector<int> v = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
    vector<int> v_sort = v;
    sort(v_sort.begin(), v_sort.end());
    testspace::Sort(v);
    ASSERT_EQ(v, v_sort);
}
TEST(stack_lib_test, all_0)
{

    vector<int> v = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    vector<int> v_sort = v;
    sort(v_sort.begin(), v_sort.end());
    testspace::Sort(v);
    ASSERT_EQ(v, v_sort);
}
TEST(stack_lib_test, all_1)
{

    vector<int> v = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    vector<int> v_sort = v;
    sort(v_sort.begin(), v_sort.end());
    testspace::Sort(v);
    ASSERT_EQ(v, v_sort);
}
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}