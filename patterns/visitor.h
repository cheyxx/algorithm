/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_VISITOR_H_
#define PATTERNS_VISITOR_H_
#include <iostream>
#include <memory>
#include <vector>

class AccountBookViewer;

class Bill {
 public:
  virtual void  Accept(AccountBookViewer *view) = 0;
};

class ConsumeBill : public Bill{
public: 
   ConsumeBill(double amount, std::string item) {
        amount_ = amount;
        item_ = item;
    }
    void Accept(AccountBookViewer *viewer);
    double getAmount() { return amount_;}
    std::string getItem() { return item_;}
private:
    double amount_;
    std::string item_;

};

class IncomeBill  : public Bill{
public: 
   IncomeBill(double amount, std::string item) {
        amount_ = amount;
        item_ = item;
    }
    void Accept(AccountBookViewer *viewer);
    double getAmount() { return amount_;}
    std::string getItem() { return item_;}
private:
    double amount_;
    std::string item_;

};


class AccountBookViewer {
public:
    virtual void view(ConsumeBill & bill) = 0;
    virtual void view(IncomeBill & bill)  = 0;
    
};


class Boss : public AccountBookViewer{
private:    
     double totalIncome_;
    double totalConsume_;
    
public: 
     Boss() {totalIncome_ = 0; totalConsume_ = 0;}
     void view(ConsumeBill & bill) {  totalConsume_ += bill.getAmount();}
     void view(IncomeBill & bill) { totalIncome_ += bill.getAmount();}
     double getTotalIncome() {
        std::cout << "boss totalIncome " << totalIncome_ << std::endl;
        return totalIncome_;
    }
     double getTotalConsume() {
        std::cout << "boss totalConsume " << totalConsume_ << std::endl;
        return totalConsume_;
    }
};

class CPA : public AccountBookViewer{
public:
    void view(ConsumeBill & bill) {
        if (bill.getItem().compare("salary")) {
            std::cout << "CPA totalIncome " << bill.getAmount() << std::endl;
        }
    }
    void view(IncomeBill & bill) {
        std::cout << "CPA totalConsume " << bill.getAmount() << std::endl;
    }
};

class AccountBook {
private:
 std::vector<Bill *> billList_;
public:
    void addBill(Bill *bill){
        billList_.push_back(bill);
    }
    void show(AccountBookViewer *viewer){
        for (auto bill : billList_) {
            bill->Accept(viewer);
        }
    }
};

#endif  //  #define PATTERNS_VISITOR_H_


