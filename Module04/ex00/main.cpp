#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void separator(const std::string& label) {
    std::cout << "\n==== " << label << " ====\n";
}

int main()
{
    separator("Virtual Function Test with Animal*");

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    cat->makeSound();  // Meow!!!
    dog->makeSound();  // Woof!
    meta->makeSound(); // Any animal sound

    delete meta;
    delete dog;
    delete cat;

    separator("WrongAnimal Test (non-virtual)");

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

    wrongCat->makeSound();   // Will call WrongAnimal::makeSound()
    wrongMeta->makeSound();

    delete wrongCat;
    delete wrongMeta;

    separator("Correct Dispatch with WrongCat Object");

    WrongCat actualWrongCat;
    actualWrongCat.makeSound(); // This will call WrongCat::makeSound()

    return 0;
}
