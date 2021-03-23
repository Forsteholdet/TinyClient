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



int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_check_type);
    return UNITY_END();
}
