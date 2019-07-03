/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/visitor.h"
#include <iostream>
#include <memory>
#include <vector>

void ConsumeBill::Accept(AccountBookViewer *viewer) { viewer->view(*this);}
void IncomeBill::Accept(AccountBookViewer *viewer) { viewer->view(*this);}