
/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#include "patterns/decorator.h"
#include <iostream>
#include <memory>
void LoggerCloud::log() { std::cout << "log cloud" << std::endl; }

LoggerCloud::LoggerCloud() {}

LoggerCloud::~LoggerCloud() {}

void LoggerFile::log() { std::cout << "log file" << std::endl; }

LoggerFile::LoggerFile(/* args */) {}

LoggerFile::~LoggerFile() {}

Decorator::Decorator() {}

Decorator::Decorator(std::shared_ptr<Logger> log) { log_ = log; }

Decorator::~Decorator() {}

void Decorator::log() { log_->log(); }

void Extends::log() {
  de_->log();
  functions();
}

void Extends::functions() { std::cout << "log my functions" << std::endl; }

Extends::Extends(std::shared_ptr<Decorator> de) { de_ = de; }

Extends::~Extends() {}

#if 0
std::shared_ptr<Logger> log(std::shared_ptr<LoggerFile>(new LoggerFile));
std::shared_ptr<Decorator> de(std::shared_ptr<Decorator>(new Decorator(log)));
Extends ex(de);
ex.log();
#endif


