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

void test_receives_input(){
    response rsp = client.post("tinyclient.com");

    const char* content = sock->content.toCharArray();
    TEST_ASSERT_EQUAL_STRING_LEN("POST", content, 4);

}

void test_accept_body_with_post_request(){

    bourne::json body = {"Id","1"};

    response rsp = client.post("tinyclient.com", body);

    TEST_ASSERT(body == client.body());
}

void test_socket_receives_body_in_the_end_of_request(){
    bourne::json body = {"Id","1"};
    response rsp = client.post("tinyclient.com", body);

    auto content = sock->content;
    TinyString res = body.dump();

    TEST_ASSERT(content.ends_with(res));
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_receives_input);
    RUN_TEST(test_accept_body_with_post_request);
    RUN_TEST(test_socket_receives_body_in_the_end_of_request);
    return UNITY_END();
}
