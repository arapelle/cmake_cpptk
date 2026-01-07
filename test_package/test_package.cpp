#include <cmake_cpptk/cmake_cpptk.hpp>
#include <cmake_cpptk/version.hpp>

#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "TESTING " << argv[0] << " " << cmake_cpptk::version.str() << std::endl;
    cmake_cpptk::cmake cmake("");
    cmake_cpptk::ctest ctest("");
    std::cout << "TEST PACKAGE SUCCESS " << std::endl;
    return EXIT_SUCCESS;
}
