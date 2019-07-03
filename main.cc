/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>  // std::cin, std::cout
#include <iterator>  // std::istream_iterator
#include <memory>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
#include "patterns/Singleton.h"
#include "patterns/adapter.h"
#include "patterns/decorator.h"
#include "patterns/bridge.h"
#include "patterns/builder.h"
#include "patterns/composite.h"
#include "patterns/factory.h"
#include "patterns/filter.h"
#include "algorithms/kmp.h"
#include "algorithms/multiple.h"
#include "patterns/observer.h"
#include "algorithms/pid.h"
#include "patterns/single_factory.h"
#include "patterns/strategy.h"
#include "patterns/abstract_factory.h"
#include "patterns/facade.h"
#include "algorithms/reverse_polish_notation.h"
#include "patterns/flyweight.h"
#include "patterns/proxy.h"
#include "patterns/chain_of_responsibility.h"
#include "patterns/command.h"
#include "patterns/state.h"
#include "patterns/null.h"
#include "patterns/iterator.h"
#include "patterns/mediator.h"
#include "patterns/memento.h"
#include "patterns/visitor.h"
#include "patterns/template_method.h"
#if 0
目录：（点击进入相应页面）
概述、六大原则
一、创建模式
0、简单工厂模式
1.工厂方法模式（Factory Method）
2、抽象工厂模式
3、单例模式（Singleton）
4、建造者模式（Builder）
5、原型模式（Prototype）
二、结构模式（7种）
6、适配器模式
7、装饰模式（Decorator）
8、代理模式（Proxy）
9、外观模式（Facade）
10、桥接模式（Bridge）
11、组合模式（Composite）
12、享元模式（Flyweight）
三、关系模式（11种）
13、策略模式（strategy）
14、模板方法模式（Template Method）
15、观察者模式（Observer）
16、迭代子模式（Iterator）
17、责任链模式（Chain of Responsibility）
18、命令模式（Command）
19、备忘录模式（Memento)
20、状态模式（State）
21、访问者模式（Visitor）
22、中介者模式（Mediator）
23、解释器模式（Interpreter）
#endif
int main() {
    //  外观模式（Facade）
    Facade f;
    f.operation();
    //  享元模式（Flyweight）
    FlyWeightFactory fly;
    UnsharedConcreteFlyWeight w;
    w.SetInfo("FIRST");
    std::shared_ptr<AbstractFlyWeight> abs = fly.GetFlyWeight(w);
    abs->operation();
    abs = fly.GetFlyWeight(w);
    abs->operation();
    // 代理模式（Proxy）
    std::shared_ptr<AbsObject> abs_obj = std::shared_ptr<Object>(new Object);
    abs_obj->RxTxMessage();
    Proxy p(abs_obj);
    p.RxTxMessage();
    // 责任链模式（Chain of Responsibility）
    Chain::Consumer c("Van");
    std::shared_ptr<Chain::AbstractChain> car = std::shared_ptr<Chain::Car>(new Chain::Car);
    std::shared_ptr<Chain::AbstractChain> van = std::shared_ptr<Chain::Van>(new Chain::Van);
    car->SetNext(van);
    car->Product(c);
    // 命令模式（Command）
    std::shared_ptr<cmd::Receiver> receiver = std::shared_ptr<cmd::Receiver>(new cmd::Receiver);
    std::shared_ptr<cmd::Command> command = std::shared_ptr<cmd::ConcreteCommand>(new cmd::ConcreteCommand(receiver) );
    cmd::Invoker inv;
    inv.SetCommand(command);
    inv.RunCommand();
    // Null模式（Null）
    CustomerFactory factory;
    std::shared_ptr<AbstractCustomer> customer = factory.GetCustomer("tom");
    std::string tom = customer->GetName();
    std::cout << "Null " << customer->isNull() << " name " << tom << std::endl;
    customer = factory.GetCustomer("joy");
    std::string joy = customer->GetName();
    std::cout << "Null " << customer->isNull() << " name " << joy << std::endl;

    //  迭代子模式（Iterator）
    PanCakeHouseMenu pancake;
    pancake.AddItem("Blueberry pancakes", "pancakes", true, 3.49);
    pancake.AddItem("pancakes", "cakes", true, 2.56);
    std::shared_ptr<Iterator> iter = pancake.CreateIterator();
    while(iter->hasNext()) {
        std::shared_ptr<MenuItem> menuitem = iter->Next();
        std::cout << menuitem->getName() << std::endl;
    }
    // 状态模式（State）
    std::shared_ptr<Context> context  = std::shared_ptr<Context>(new Context(3));

    context->InsertQuarter();
    context->TurnCrank();
    context->Dispense();
    context->EjectQuarter();
    context->Dispense();
    context->InsertQuarter();
    context->InsertQuarter();
    context->TurnCrank();
    context->Dispense();
    
    std::cout << "count " << context->GetCount() << std::endl;
    context->InsertQuarter();
    context->EjectQuarter();
    context->TurnCrank();
    context->Dispense();
    std::cout << "count " << context->GetCount() << std::endl;
    context->InsertQuarter();
    context->TurnCrank();
    context->Dispense();
    std::cout << "count " << context->GetCount() << std::endl;
    context->InsertQuarter();
    
    //  中介者模式（Mediator）
    Mediator *mediator = new HouseMediator();
    Person *person1 = new Renter();
    Person *person2 = new Landlord();
    mediator->SetRenter(person1);
    mediator->SetLandlord(person2);
    person1->SetMediator(mediator);
    person2->SetMediator(mediator);
    std::string rent_str = "I want to rent a house \n";
    std::string out_str = "I want to rent out a house \n";
    person1->SendMessage(rent_str);
    person2->SendMessage(out_str);
    
    // 备忘录模式（Memento)
    Originator* original_ptr = new Originator("role", 100);
    std::cout<< "orginal state: "<< std::endl;
    original_ptr->Show();
    CareTaker* caretaker_ptr = new CareTaker();
    caretaker_ptr->AddMemento(original_ptr->SaveState());
    original_ptr->SetVitality(50);
    std::cout<< "fight state: "<< std::endl;
    original_ptr->Show();
    original_ptr->RecoverState(caretaker_ptr->GetMemento(0));
    std::cout<< "file state: "<< std::endl;
    original_ptr->Show();
    
    //  访问者模式（Visitor）
    AccountBook *accountBook_ptr = new AccountBook();
    accountBook_ptr->addBill(new IncomeBill(10000, "sale entertainment"));
    accountBook_ptr->addBill(new IncomeBill(12000, "sale advertisement"));
    accountBook_ptr->addBill(new ConsumeBill(1000, "salary"));
    accountBook_ptr->addBill(new ConsumeBill(2000, "materials"));
    AccountBookViewer *boss = new Boss();
    AccountBookViewer *cpa = new CPA();
    accountBook_ptr->show(cpa);
    accountBook_ptr->show(boss);
    Boss * b = dynamic_cast<Boss *> (boss);
    b->getTotalIncome();
    b->getTotalConsume();

    std::shared_ptr<temp::Person> person  = std::shared_ptr<temp::Man>(new temp::Man());
    person->Activity();
    person = std::shared_ptr<temp::Woman>(new temp::Woman());
    person->Activity();
    
}
