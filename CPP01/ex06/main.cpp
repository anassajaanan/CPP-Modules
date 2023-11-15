
#include "Harl.hpp"
#include <iostream>



int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <log_level>" << std::endl;
        return 1;
    }

    std::string logLevel = argv[1];
    Harl harl;
    harl.complain(logLevel);

    return 0;
}