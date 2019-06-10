
/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef PATTERNS_DECORATOR_H_
#define PATTERNS_DECORATOR_H_
#include <iostream>
#include <memory>

class Logger {
 public:
  virtual void log() = 0;
};

class LoggerCloud : public Logger {
 private:
 public:
  LoggerCloud();
  ~LoggerCloud();
  void log();
};

class LoggerFile : public Logger {
 private:
 public:
  LoggerFile();
  ~LoggerFile();
  void log();
};

class Decorator : public Logger {
 private:
  std::shared_ptr<Logger> log_;

 public:
  Decorator();
  explicit Decorator(std::shared_ptr<Logger> log);
  void log();
  ~Decorator();
};

class Extends : public Decorator {
 private:
    std::shared_ptr<Decorator> de_;
 public:
    explicit Extends(std::shared_ptr<Decorator> de);
    ~Extends();
    void log();
    void functions();
};

#endif  //  PATTERNS_DECORATOR_H_
