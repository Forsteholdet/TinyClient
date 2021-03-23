#include "unity.h"
#include "macro/macro_defs.h"


void setUp(){
}
void tearDown(){
}

void test_string_length_method(void) {
    TCstring str = "test";

    TEST_ASSERT_EQUAL_INT(str.length(), 4);
}

void test_string_equals_implementation_equals(void) {
    TCstring string = "hello";
    TCstring result = "hello";

    TEST_ASSERT_TRUE(string == result);
}

void test_string_equals_implementation_not_equals(void) {
    TCstring string = "hello";
    TCstring result = "world";

    TEST_ASSERT_FALSE(string == result);
}

void test_string_empty_method_empty(void) {
    TCstring string = "";

    TEST_ASSERT_TRUE(string.empty());
}

void test_string_empty_method_not_empty(void) {
    TCstring string = "hello world";

    TEST_ASSERT_FALSE(string.empty());
}

void test_string_substr_method(void) {
    TCstring string = "hello world";
    TCstring hello = string.substr(0,5);

    TEST_ASSERT_EQUAL_STRING(hello.str.c_str(), "hello");
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_string_length_method);
    RUN_TEST(test_string_equals_implementation_equals);
    RUN_TEST(test_string_equals_implementation_not_equals);
    RUN_TEST(test_string_empty_method_empty);
    RUN_TEST(test_string_empty_method_not_empty);
    RUN_TEST(test_string_substr_method);
    return UNITY_END();
}