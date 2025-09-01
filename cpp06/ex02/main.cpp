#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Funcs.hpp"

int main() {

        Base    *ptr = NULL;
        Base    *base = NULL;

        while (!ptr) {
                ptr = generate();
                std::cout << "I tried" << std::endl;
        }
        identify(ptr);
        identify(base);

        identify(*ptr);
        identify(*base);

        delete ptr;
}
