#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Funcs.hpp"

int main() {

        Base    *ptr = NULL;
        Base    *base = NULL;

        while (!ptr) {
                ptr = generate();
        }
        std::cout << "Pointer identify functions:" << std::endl;
        identify(ptr);
        identify(base);

        std::cout << "Reference identify functions:" << std::endl;
        identify(*ptr);
        identify(*base);

        delete ptr;
}
