#include "unity.h"
#include <socket/fake_socket.h>
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
    Response rsp = client.del("tinyclient.com");

    const char* content = sock->content.toCharArray();
    TEST_ASSERT_EQUAL_STRING_LEN("DELETE", content, 6);

}

void test_receives_input(){
    Response rsp = client.get("tinyclient.com");

    const char* content = sock->content.toCharArray();
    TEST_ASSERT_EQUAL_STRING_LEN("GET", content, 3);
}


void runTests(){
    RUN_TEST(test_check_type);
    RUN_TEST(test_receives_input);
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
