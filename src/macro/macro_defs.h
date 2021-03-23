#include <iostream>
#include "internals/TCstring.h"

#if defined (__linux)
    #define PLATFORM "Linux"
    typedef TCstringLinux TCstring;
#elif defined(_WIN32)
    #define PLATFORM "Windows"
    typedef TCstringLinux TCstring;
#elif defined(ESP32)
    #define PLATFORM "ESP32"
    typedef TCstringEsp32 TCstring;
#else
	#define PLATFORM "Others"
#endif

void detect_OS(){
    std::cout << "\nOS is: " << PLATFORM;
}