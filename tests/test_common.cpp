#include "unity.h"

void test_function_should_doBlahAndBlah(void) {
    TEST_ASSERT(true);
}

void test_function_should_doAlsoDoBlah(void) {
    TEST_ASSERT(false);

}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_should_doBlahAndBlah);
    RUN_TEST(test_function_should_doAlsoDoBlah);
    return UNITY_END();
}
