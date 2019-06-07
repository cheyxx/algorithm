/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef ADAPTER_HH_
#define ADAPTER_HH_
#include <iostream>
#include <memory>

/*
* spring MVC中的适配器模式
* Spring MVC中的适配器模式主要用于执行目标 Controller 中的请求处理方法。
* 在Spring MVC中，DispatcherServlet 作为用户，HandlerAdapter 作为期望接口，
* 具体的适配器实现类用于对目标类进行适配，Controller 作为需要适配的类。
* 为什么要在 Spring MVC 中使用适配器模式？Spring MVC 中的 Controller 种类众多，
* AbstractHandlerMethodAdapter
* HttpRequestHanderAdapter
* RequestMappingHanderAdapter
* SimpleControllerHanderAdapter
* SimpleServletHandleAdapter
* 不同类型的 Controller
* 通过不同的方法来对请求进行处理。如果不利用适配器模式的话，
* DispatcherServlet 直接获取对应类型的 Controller
*/
class Target {
 public:
  virtual void request() { std::cout << "target" << std::endl; }
};

class Adaptee {
 public:
  void specific_request();
};

class Adapter : public Target {
 public:
  void request();
  void set_adapter(std::shared_ptr<Adaptee> a);

 private:
  std::shared_ptr<Adaptee> _a;
};

#endif  // ADAPTER_HH_
