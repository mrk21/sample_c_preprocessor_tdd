#include <iostream>
#include <string>
#include <map>
#include "preprocessor.hpp"

STRINGIFIABLE_ENUM(shop_category,
    food,
    electronics,
    hobby
)

int main() {
    std::cout << shop_category::food << std::endl; // food
    std::cout << shop_category::electronics << std::endl; // electronics
    std::cout << shop_category::hobby << std::endl; // hobby
    return 0;
}
