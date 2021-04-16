#include "unity.h"
#include "socket/t_socket.h"
#include <socket/fake_socket.h>
#include "http_request.h"
#include "macro/macro_defs.h"

fake_socket *sock;
tinyclient::http_request client(nullptr);

void setUp(){
    sock = new fake_socket;
    client = tinyclient::http_request(sock);

}
void tearDown(){
    delete sock;
}

void test_request_string_have_method(void) {
    client.get("tinyclient.com");
    TinyString content = sock->content;

    const char *content_char = content.toCharArray();

    TEST_ASSERT_EQUAL_STRING_LEN("GET", content_char, 3);
}

void find_address_only_have_baseurl (){
    TinyString baseurl = "tinyclient.com";
    client.request(baseurl);

    TEST_ASSERT(client.host_address == baseurl);
}

void find_host_address_with_url_and_uri(){
    TinyString baseurl = "tinyclient.com";

    client.request(baseurl + "/users");
    TEST_ASSERT(client.host_address == baseurl);
}

void if_no_uri_make_it_empty(){
    TinyString baseurl = "tinyclient.com";

    client.request(baseurl);
    TEST_ASSERT(client.uri.empty());
}

void make_a_request_with_uri_and_host(){
    client.get("tinyclient.com/users?page=lol");

    TinyString full_request ="GET /users?page=lol HTTP/1.1\r\nHost: tinyclient.com\r\n";
    // Expected 'GET /users?page=lol HTTP/1.1\r\nHost: tinyclient.com\r\n'
    // Was      'GET /users?page=lo HTTP/1.1\r\nHost: tinyclient.com\r\n' 
    TEST_ASSERT_EQUAL_STRING(full_request.toCharArray(), sock->content.toCharArray());
}

void request_standard_accept_is_application_slash_json(){
    client.request("tinyclient.com");

    TEST_ASSERT(client.accept == constants::JSON);
}

void runTests(){
    RUN_TEST(test_request_string_have_method);
    RUN_TEST(find_address_only_have_baseurl);
    RUN_TEST(find_host_address_with_url_and_uri);
    RUN_TEST(if_no_uri_make_it_empty);
    RUN_TEST(make_a_request_with_uri_and_host);
    RUN_TEST(request_standard_accept_is_application_slash_json);
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
