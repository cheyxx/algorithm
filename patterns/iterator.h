/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_ITERATOR_H_
#define PATTERNS_ITERATOR_H_
#include <iostream>
#include <memory>
#include <vector>

class MenuItem {
 public:
  MenuItem(std::string name, std::string description, 
  bool vegetarian, double price);
  std::string getName();
  std::string getDescription();
  double getPrice();
  bool isVegetarian();
private:
  std::string name_;
  std::string description_;
  double price_;
  bool vegetarian_;
};

class Iterator {
public:
  virtual bool hasNext() = 0;
  virtual std::shared_ptr<MenuItem> Next() = 0;
};

class  PanCakeHouseMenu {
public:
typedef std::shared_ptr<MenuItem> menu_ptr;
    void AddItem(std::string name, std::string description, bool vegetarian,double price);
    std::shared_ptr<Iterator> CreateIterator();
private:  
    std::vector<menu_ptr> menu_items_;
};

class PanCakeHouseMenuIterator : public Iterator {
public:
  PanCakeHouseMenuIterator(std::vector<PanCakeHouseMenu::menu_ptr> menus);
  bool hasNext();
  std::shared_ptr<MenuItem> Next();
private: 
  std::vector<PanCakeHouseMenu::menu_ptr> menu_iter_;
  unsigned int position;
};

#endif  //  PATTERNS_ITERATOR_H_
