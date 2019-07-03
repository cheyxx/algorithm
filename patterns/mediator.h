/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_MEDIATOR_H_
#define PATTERNS_MEDIATOR_H_
#include <iostream>
#include <memory>
#include <vector>
#include <string>


class Mediator;
class Person
{
public:
    virtual void SetMediator(Mediator *mediator){}
    virtual void SendMessage(std::string &message){}
    virtual void GetMessage(std::string &message){}
protected:
    Mediator *mediator_; 
};


class Mediator
{
public:
    virtual void Send(std::string &message, Person *person) = 0;
    virtual void SetRenter(Person *renter) = 0;
    virtual void SetLandlord(Person *landlord) = 0;
    
};


class Renter:public Person
{
public:
    void SetMediator(Mediator *mediator){mediator_ = mediator;}
    void SendMessage(std::string &message){ mediator_->Send(message,this);}
    void GetMessage(std::string &message){std::cout<<"Receiver the msg from the landlord："<<message;}
};


class Landlord:public Person
{
public:
    void SetMediator(Mediator *mediator){mediator_ = mediator;}
    void SendMessage(std::string &message){ mediator_->Send(message,this);}
    void GetMessage(std::string &message){std::cout<<"Receiver the msg from the renter: "<<message;}
};

class HouseMediator: public Mediator
{
public:
    HouseMediator():renter_(nullptr),landlord_(nullptr){std::cout << "" << std::endl;}
    void SetRenter(Person *renter){renter_ = renter;}
    void SetLandlord(Person *landlord){landlord_ = landlord;}
    void Send(std::string &message, Person *person);
    ~HouseMediator() {}
private:
    Person *renter_;
    Person *landlord_;
};

#endif
