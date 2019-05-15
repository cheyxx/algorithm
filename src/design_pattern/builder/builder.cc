#include "builder.hh"
#include <iostream>
#include <memory>
using namespace std;

void
product::add(std::string s) {
    items.push_back(s);
}

void 
product::display(){
    for (auto &v : items)
        std::cout << v << std::endl;
}

void direct::construct(std::shared_ptr<builder> builderInstance)
{
    m_builder = builderInstance;
    m_builder->build_wheel("wheel");
    m_builder->build_body("body");
}
