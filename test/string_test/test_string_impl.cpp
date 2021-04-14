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

void test_string_equals_operator_equals(void) {
    TinyString string = "hello";
    TinyString result = "hello";

    TEST_ASSERT_TRUE(string == result);
}

void test_string_equals_operator_not_equals(void) {
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
    TinyString substring = string.substr(0, 5);
    TinyString hello = "hello";

    TEST_ASSERT_TRUE(substring == hello);
}

void test_string_toCharArray_method(void) {
    TinyString string = "hello";

    TEST_ASSERT_EQUAL_STRING(string.toCharArray(), "hello");
}

void test_string_find_method_returns_first_index_of_query(void){
    TinyString string = "hello world";
    TEST_ASSERT_EQUAL_INT(string.find("world"), 6);
}

void test_string_find_method_returns_minusOne_if_not_found(void){
    TinyString string = "hello";
    TEST_ASSERT_EQUAL_INT(string.find("w"), -1);
}

void test_string_find_method_does_not_handle_upper_lower_case(void){
    TinyString string = "Hello World";
    TEST_ASSERT_EQUAL_INT(string.find("world"), -1);
}

void test_string_addition_assignment_operator(void){
    TinyString hello = "hello";
    hello += " ";
    hello += "world";

    TEST_ASSERT_TRUE(hello == "hello world");

}

void test_string_addition_operator(){
    TinyString hello = "hello";
    TinyString res = hello + " " + "world";
    TEST_ASSERT_TRUE(res == "hello world");
}

void test_string_ends_with_method(){
    TinyString hello = "hello world";
    TEST_ASSERT_TRUE(hello.ends_with("world"));
}

void test_TinyString_json_constructor(){
    bourne::json jsonObj = {"Id", "1"};
    TinyString someString = jsonObj;

    TEST_ASSERT(someString == jsonObj.dump().c_str());
}

void runTests(){
    RUN_TEST(test_string_length_method);
    RUN_TEST(test_string_equals_operator_equals);
    RUN_TEST(test_string_equals_operator_not_equals);
    RUN_TEST(test_string_empty_method_empty);
    RUN_TEST(test_string_empty_method_not_empty);
    RUN_TEST(test_string_substr_method);
    RUN_TEST(test_string_toCharArray_method);
    RUN_TEST(test_string_find_method_returns_first_index_of_query);
    RUN_TEST(test_string_find_method_returns_minusOne_if_not_found);
    RUN_TEST(test_string_addition_assignment_operator);
    RUN_TEST(test_string_find_method_does_not_handle_upper_lower_case);
    RUN_TEST(test_string_addition_operator);
    RUN_TEST(test_string_ends_with_method);
    RUN_TEST(test_TinyString_json_constructor);
}

int main(void) {
    UNITY_BEGIN();
    runTests();
    return UNITY_END();
}

void setup()
{
    UNITY_BEGIN();
    runTests();
    UNITY_END();
}

void loop()
{
    
}
