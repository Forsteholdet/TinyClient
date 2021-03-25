#include "unity.h"
#include "macro/macro_defs.h"


void setUp(){
}
void tearDown(){
}

void test_string_length_method(void) {
    TinyString str = "test";

    TEST_ASSERT_EQUAL_INT(str.length(), 4);
}

void test_string_equals_implementation_equals(void) {
    TinyString string = "hello";
    TinyString result = "hello";

    TEST_ASSERT_TRUE(string == result);
}

void test_string_equals_implementation_not_equals(void) {
    TinyString string = "hello";
    TinyString result = "world";

    TEST_ASSERT_FALSE(string == result);
}

void test_string_empty_method_empty(void) {
    TinyString string = "";

    TEST_ASSERT_TRUE(string.empty());
}

void test_string_empty_method_not_empty(void) {
    TinyString string = "hello world";

    TEST_ASSERT_FALSE(string.empty());
}

void test_string_substr_method(void) {
    TinyString string = "hello world";
    TinyString hello = string.substr(0, 5);
    TinyString test = "hello";

    TEST_ASSERT_TRUE(hello == test);
}

void test_string_toCharArray_method(void) {
    TinyString string = "hello";

    TEST_ASSERT_EQUAL_STRING(string.toCharArray(), "hello");
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_string_length_method);
    RUN_TEST(test_string_equals_implementation_equals);
    RUN_TEST(test_string_equals_implementation_not_equals);
    RUN_TEST(test_string_empty_method_empty);
    RUN_TEST(test_string_empty_method_not_empty);
    RUN_TEST(test_string_substr_method);
    RUN_TEST(test_string_toCharArray_method);
    return UNITY_END();
}