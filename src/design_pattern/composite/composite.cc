#include "composite.hh"
#include <iostream>
#include <vector>
void File::display() { std::cout << "file name: " << _name << std::endl; }

File::~File() {}

void Folder::add(Folder::file_ptr file) { _file.push_back(file); }

void Folder::display() {
  std::cout << "folder name: " << _name << std::endl;
  for (const auto &v : _file) {
    v->display();
  }
}

Folder::~Folder() {}