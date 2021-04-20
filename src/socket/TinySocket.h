#if defined(__linux)
    // Do somehitng, hvis den skal køre på linu
    #define NATIVE_SOCKET
    #include "fake_socket.h"
    using namespace tinyclient;
    typedef fake_socket TinySocket;
#elif defined(ESP32)
    #define ESP32_SOCKET
    #include "ESP32Socket.h"
    using namespace tinyclient;
    typedef ESP32Socket TinySocket;
#endif // __linux
