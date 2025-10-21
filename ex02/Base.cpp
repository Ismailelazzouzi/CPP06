#include "Base.hpp"

Base *generate(void)
{
    unsigned int number;
    unsigned seed;
    Base *p;

    seed = time(0);
    srand(seed);
    number = (rand() % (3 - 1 + 1)) + 1;
    switch (number)
    {
    case 1:
        return (p = new A);
        break;
    case 2:
        return (p = new B);
    case 3:
        return (p = new C);
    default:
        break;
    }
    return NULL;
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
    {
        std::cout << "A" << std::endl;
        return;
    }
    
    if (dynamic_cast<B *>(p) != NULL)
    {
        std::cout << "B" << std::endl;
        return;
    }
    std::cout << "C" << std::endl;
    return;   
}

void identify(Base &r)
{
    try
    {
        Base &ref = dynamic_cast<A &>(r);
        std::cout << "A" << std::endl;
        (void)ref;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base &ref = dynamic_cast<B &>(r);
        std::cout << "B" << std::endl;
        (void)ref;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base &ref = dynamic_cast<C &>(r);
        std::cout << "C" << std::endl;
        (void)ref;
    }
    catch(const std::exception& e)
    {
    }
}
