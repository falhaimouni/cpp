#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    dog->makeSound(); // should say "Woof!!!"
    cat->makeSound(); // should say "Meow!!!"

    delete dog;
    delete cat;

    return 0;
}
