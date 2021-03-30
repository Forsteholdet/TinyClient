#include <string>
#include <fake_socket.h>
#include <http_request.h>
#include "unity.h"

fake_socket *sock;
tinyclient::http_request client(nullptr);

void setUp(){
    sock = new fake_socket;
    client = tinyclient::http_request(sock);
}
void tearDown(){
    delete sock;
}

void test_receives_input(){
    response rsp = client.get("tinyclient.com");

    const char* content = sock->content.toCharArray();
    TEST_ASSERT_EQUAL_STRING_LEN("GET", content, 3);
}


void get_returns_a_response(){
    TinyString url = "tinyclient.com";

    response response = client.get(url);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_receives_input);
    RUN_TEST(get_returns_a_response);

    return UNITY_END();
}