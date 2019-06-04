#ifndef COMPOSITE_HH_
#define COMPOSITE_HH_
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
  File(std::string name) : _name(name){};
  ~File();
  void display();
  void add(std::shared_ptr<AbstractFile> file){};
};

class Folder : public AbstractFile {
 public:
  typedef std::shared_ptr<AbstractFile> file_ptr;
  Folder(std::string name) : _name(name){};
  void add(file_ptr file);
  ~Folder();
  void display();

 private:
  std::string _name;
  std::vector<file_ptr> _file;
};

#endif