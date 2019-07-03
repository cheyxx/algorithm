/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/mediator.h"
#include <iostream>
#include <memory>

void
HouseMediator::Send(std::string &message, Person *person)
{
    if(person == renter_)
        landlord_->GetMessage(message);
    else
        renter_->GetMessage(message);
}
