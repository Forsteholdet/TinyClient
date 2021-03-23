#include <string>
#include "unity.h"

void test_fun(void) {
    std::string lol = "lol";
    const char *gay = lol.c_str();

    TEST_ASSERT_EQUAL_STRING_LEN(gay, "lol", 3);

}
void setUp(){
}
void tearDown(){
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_fun);

    return UNITY_END();
}