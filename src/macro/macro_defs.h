
#if defined (__linux)
#include "internals/native_string.h"
    #define PLATFORM "Linux"
    typedef NativeString TinyString;
#elif defined(_WIN32)
#include "internals/native_string.h"
    #define PLATFORM "Windows"
    typedef NativeString TinyString;
#elif defined(ESP32)
#include "internals/esp32_string.h"
    #define PLATFORM "ESP32"
    typedef ESP32String TinyString;
#else
	#define PLATFORM "Others"
#endif

TinyString detect_OS(){
    return PLATFORM;
}