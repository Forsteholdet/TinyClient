#include "unity.h"
#include <socket/ESP32Socket.h>
void setUp(){ }

void tearDown(){ }

void test_sends_to_host(){
    ESP32Socket socket(1,1,1,1,5000);

    IPAddress ip(1,1,1,1);
    
    TEST_ASSERT(socket.server_ip == ip);
}

void runTests() {
    RUN_TEST(test_sends_to_host);

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

void loop() { }