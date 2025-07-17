#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        std::ifstream file(argv[1]);
        std::string s;
        std::getline(file, s);
        std::cout << s1.find(s2);

        // std::cout << "Read String: " << s << "\n";
    }
    // std::ofstream file("testFile");
    // file << "GGIIIII" << "\n";
    return(0);
}