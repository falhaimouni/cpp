#include "easyfind.hpp"


int main() {
    try {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found: " << *it << std::endl;

        it = easyfind(v, 50);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<int> l;
        l.push_back(5);
        l.push_back(15);
        l.push_back(25);

        std::list<int>::iterator it = easyfind(l, 15);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}