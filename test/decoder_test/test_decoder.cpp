#include <string>
#include <socket/fake_socket.h>
#include <http_request.h>
#include "unity.h"
#include "decoder/decoder.h"
#include "response/response.h"


TinyString header = "Request URL: https://fake.com/ Request Method: GET Status Code 200";
TinyString body = "{'test', 'body'}";
    

Package package(header, body);
Decoder decoder;

void setUp(){

}
void tearDown(){

}

void test_decoder_finds_satusCode(){
    
    Response rsp = decoder.decode(package);

    int statusCode = decoder.getStatusCode();

    TEST_ASSERT(200 == statusCode);
}

void test_decoder_finds_body_as_tinystring(){
    Response rsp = decoder.decode(package);

    TinyString stringBody = decoder.getStringBody();
    TinyString expected = "default";

    TEST_ASSERT(expected == stringBody);
}

void test_decoder_decodes_stringbody_to_jsonbody(){
    Response rsp = decoder.decode(package);

    bourne::json jsonBody = decoder.getJsonBody();

    bourne::json expected = "{'default', 'body'}";
    
    TEST_ASSERT(expected == jsonBody);
}

void runTests(){
    RUN_TEST(test_decoder_finds_satusCode);
    RUN_TEST(test_decoder_finds_body_as_tinystring);
    RUN_TEST(test_decoder_decodes_stringbody_to_jsonbody);
}


int main(void) {
    UNITY_BEGIN();
    runTests();
    return UNITY_END();
}

void setup() {
    UNITY_BEGIN();
    runTests();
    UNITY_END();
}

void loop() {
    
}
