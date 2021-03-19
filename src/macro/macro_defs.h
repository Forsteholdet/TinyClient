#include <iostream>
#if defined __linux
    #define PLATFORM "Linux"
#else
	#define PLATFORM "Others"
#endif

void detect_OS(){
    std::cout << "OS is: " << PLATFORM;
}