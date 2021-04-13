#include "unity.h"
#include <fake_socket.h>
#include <http_request.h>

fake_socket *sock;
tinyclient::http_request client(nullptr);

void setUp(){
    sock = new fake_socket;
    client = tinyclient::http_request(sock);

}
void tearDown(){
    delete sock;
}

void test_check_type(){
    response rsp = client.del("tinyclient.com");

    const char* content = sock->content.toCharArray();
    TEST_ASSERT_EQUAL_STRING_LEN("DELETE", content, 6);

}

void test_receives_input(){
    response rsp = client.get("tinyclient.com");

    const char* content = sock->content.toCharArray();
    TEST_ASSERT_EQUAL_STRING_LEN("GET", content, 3);
}


void run_all_test(){
    RUN_TEST(test_check_type);
    RUN_TEST(test_receives_input);
}

int main(void) {
    UNITY_BEGIN();
    run_all_test();
    return UNITY_END();
}

void setup()
{
    UNITY_BEGIN();
    run_all_test();
    UNITY_END();
}

void loop()
{
    
}
