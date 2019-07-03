/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/template_method.h"
#include <iostream>
#include <memory>
#include <vector>
namespace temp {
void 
Man::CombHair() {
    std::cout << "man comb hair!" << std::endl;
}

void 
Woman::CombHair() {
    std::cout << "woman comb hair!" << std::endl;
}
}