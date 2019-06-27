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
}
