/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef PATTERNS_COMPOSITE_H_
#define PATTERNS_COMPOSITE_H_
#include <string>
#include <iostream>
#include <memory>
#include <vector>
class Folder;
class AbstractFile {
 public:
  virtual void display() = 0;
  virtual void add(std::shared_ptr<AbstractFile> file) = 0;
};

class File : public AbstractFile {
 private:
  std::string _name;
  /* data */
 public:
  explicit File(std::string name);
  ~File();
  void display();
  void add(std::shared_ptr<AbstractFile> file);
};

class Folder : public AbstractFile {
 public:
  typedef std::shared_ptr<AbstractFile> file_ptr;
  explicit Folder(std::string name);
  void add(file_ptr file);
  ~Folder();
  void display();

 private:
  std::string _name;
  std::vector<file_ptr> _file;
};

#endif  //  PATTERNS_COMPOSITE_H_
