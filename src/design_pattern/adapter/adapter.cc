#include<iostream>
#include<memory>
#include "adapter.hh"

void
Adapter::request() {
    _a->specific_request();
}

void
Adapter::set_adapter(std::shared_ptr<Adaptee> a) {
    _a = a;
}

void
Adaptee::specific_request() {
    std::cout << "specific request" << std::endl;
} 