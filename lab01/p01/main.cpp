#include <iostream>
#include <fstream>

int main()
{
    std::ofstream out("hello17.txt");
    std::streambuf *coutbuf = std::cout.rdbuf();    // save old buffer
    std::cout.rdbuf(out.rdbuf());                   // redirect std::cout to hello11.txt

    std::cout << "Hello, C++ " << __cplusplus << "!\n";

    std::cout.rdbuf(coutbuf);                       // reset to standard to output again
}