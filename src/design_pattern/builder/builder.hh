#ifndef BUILD_HH_
#define BUILD_HH_
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class builder {
public:
    virtual void build_wheel(std::string a_wheel) = 0;
    virtual void build_body(std::string a_body) = 0;
};

class product
{
public:
    product(){};
    void add(std::string s);
    void display();

private:
    std::vector<std::string> items;
};

class concrete_builder : public builder
{
public:
    concrete_builder(std::shared_ptr<product> instance) {m_product = instance;}
    void build_wheel(std::string a_wheel) { m_product->add(a_wheel);}
    void build_body(std::string a_body){ m_product->add(a_body);}
    std::shared_ptr<product> get_product() {return m_product;}

private:    
    std::shared_ptr<product> m_product; 
};


class direct {
public:
    direct(){};
    void construct(std::shared_ptr<builder> builderInstance);

private:
    std::shared_ptr<builder> m_builder;
};
#endif 
