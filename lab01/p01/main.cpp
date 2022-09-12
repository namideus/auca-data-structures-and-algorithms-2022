#include <iostream>

int main(int argc, char **argv)
{
#ifdef AUCA_DEBUG
    std::cout << "author: Yiman Altynbek uulu\n"; 
#endif
    std::cout << "Hello, C++ " << __cplusplus << "!\n"; 
}