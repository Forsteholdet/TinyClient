#include <iostream>
#if defined (__linux)
    #define PLATFORM "Linux"
    typedef std::string TCstring;
#elif defined(_WIN32)
    #define PLATFORM "Windows"
    typedef std::string TCstring;
#elif defined(ESP32)
    #define PLATFORM "ESP32"
    include <string>
    typedef string TCstring;
#else
	#define PLATFORM "Others"
#endif

void detect_OS(){
    std::cout << "\nOS is: " << PLATFORM;
}