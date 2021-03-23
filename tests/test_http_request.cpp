#include "unity.h"
#include "t_socket.h"
#include <fake_socket.h>
#include "http_request.h"

fake_socket *sock;
tinyclient::http_request client(nullptr);

void setUp(){
    sock = new fake_socket;
}
void tearDown(){
    delete sock;
}


void test_fun(void) {
    std::string lol = "lol";
    const char *gay = lol.c_str();

    TEST_ASSERT_EQUAL_STRING_LEN(gay, "lol", 3);

}

void test_request_string_have_method(void) {
    client = tinyclient::http_request(sock);

    client.get("tinyclient.com");
    std::string content = sock->content;

    const char *content_char = content.c_str();

    TEST_ASSERT_EQUAL_STRING_LEN("GET", content_char, 3);
}

void find_address_only_have_baseurl (){
    std::string baseurl = "tinyclient.com";
    client.request(baseurl);

    TEST_ASSERT(client.host_address == baseurl);
}

void find_host_address_with_url_and_uri(){
    std::string baseurl = "tinyclient.com";

    client.request(baseurl + "/users");
    TEST_ASSERT(client.host_address == baseurl);
}

void if_no_uri_make_it_empty(){
    std::string baseurl = "tinyclient.com";

    client.request(baseurl);
    TEST_ASSERT(client.uri.empty());
}

void make_a_request_with_uri_and_host(){
    client.get("tinyclient.com/users?page=lol");

    auto full_request = client.type() + " /users?page=lol HTTP/1.1\r\n"
                                        "Host: tinyclient.com\r\n";


    TEST_ASSERT(sock->content == full_request);
}

void request_standard_accept_is_application_slash_json(){
    client.request("tinyclient.com");

    TEST_ASSERT(client.accept == constants::JSON);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_fun);
    RUN_TEST(test_request_string_have_method);
    RUN_TEST(find_address_only_have_baseurl);
    RUN_TEST(find_host_address_with_url_and_uri);
    RUN_TEST(if_no_uri_make_it_empty);
    RUN_TEST(make_a_request_with_uri_and_host);
    RUN_TEST(request_standard_accept_is_application_slash_json);
    return UNITY_END();
}
