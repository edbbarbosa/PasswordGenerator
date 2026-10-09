#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H
#include <string>
#include <random>
#include <algorithm>

class PasswordGenerator
{
    int size;
public:
    PasswordGenerator(int size);
    std::string password();
};

#endif // PASSWORDGENERATOR_H
