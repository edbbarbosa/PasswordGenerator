#include "passwordgenerator.h"

PasswordGenerator::PasswordGenerator(int size) {
    this->size = size;

}

std::string PasswordGenerator::password(){
    const std::string characters =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()_+-=[]{}|;:,.<>?";

    std::string password;
    password.reserve(size);

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    for(int i = 0; i < size; ++i)
        password += characters[distribution(gen)];

    return password;
}
