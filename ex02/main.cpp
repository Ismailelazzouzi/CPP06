#include "Base.hpp"

int main()
{
    Base *mysteryPointer = generate();
    identify(mysteryPointer);
    identify(*mysteryPointer);
    delete mysteryPointer;
}