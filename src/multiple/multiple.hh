#ifndef MULTIPLE_HH_
#define MULTIPLE_HH_
#include <iostream>
#include <vector>
class multiple {
public:
    multiple();
    void cin();
    void algorithm();
    void display();
    void execute();
private:
    std::string _multiplier;
    std::string _multiplicand;
    std::vector<unsigned int> _result;

};

#endif