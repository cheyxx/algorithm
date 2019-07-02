/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#include "patterns/iterator.h"
#include <iostream>
#include <memory>
#include <vector>

std::string
MenuItem::getName() {
  return name_;
}

double
MenuItem::getPrice(){
  return price_;
}

std::string
MenuItem::getDescription() {
  return description_;
}

bool
MenuItem::isVegetarian() {
  return vegetarian_;
} 

MenuItem::MenuItem(std::string name, std::string description, 
  bool vegetarian, double price) {
  name_ = name;
  description_ = description;
  price_ = price;
  vegetarian_ = vegetarian;
}

PanCakeHouseMenuIterator::PanCakeHouseMenuIterator(std::vector<PanCakeHouseMenu::menu_ptr> menu_iter) {
  menu_iter_ = menu_iter;
  position = 0;
}
std::shared_ptr<MenuItem>
PanCakeHouseMenuIterator::Next() {
  PanCakeHouseMenu::menu_ptr ptr = menu_iter_[position];
  position++;
  return ptr;
}

bool
PanCakeHouseMenuIterator::hasNext() {
  if (position >= menu_iter_.size() || menu_iter_[position] == nullptr) {
    return false;
  }
  else {
    return true;
  }
}

std::shared_ptr<Iterator>
PanCakeHouseMenu::CreateIterator () {
  return std::shared_ptr<PanCakeHouseMenuIterator>(new PanCakeHouseMenuIterator(menu_items_));
}

void 
PanCakeHouseMenu::AddItem(std::string name, std::string description, bool vegetarian, double price) 
{
  std::shared_ptr<MenuItem> item = std::shared_ptr<MenuItem>(new MenuItem(name, description, vegetarian, price));
  menu_items_.push_back(item);
}