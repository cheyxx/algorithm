/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/
#ifndef PATTERNS_STRING_H_
#define PATTERNS_STRING_H_

#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class String
{
public:
    static std::string trimLeft(const std::string& str, const std::string& token = " ")
    {
        std::string t = str;
        t.erase(0, t.find_first_not_of(token));
        return t;
    }

    static std::string trimRight(const std::string& str, const std::string& token = " ")
    {
        std::string t = str;
        t.erase(t.find_last_not_of(token) + 1);
        return t;
    }

    static std::string trim(const std::string& str, const std::string& token = " ")
    {
        std::string t = str;
        t.erase(0, t.find_first_not_of(token));
        t.erase(t.find_last_not_of(token) + 1);
        return t;
    }

    static std::string toLower(const std::string& str)
    {
        std::string t = str;
        std::transform(t.begin(), t.end(), t.begin(), tolower);
        return t;
    }

    static std::string toUpper(const std::string& str)
    {
        std::string t = str;
        std::transform(t.begin(), t.end(), t.begin(), toupper);
        return t;
    }

    static bool startsWith(const std::string& str, const std::string& substr)
    {
        return str.find(substr) == 0;
    }

    static bool endsWith(const std::string& str, const std::string& substr)
    {
        return str.rfind(substr) == (str.length() - substr.length());
    }

    static bool equalsIgnoreCase(const std::string& str1, const std::string& str2) 
    {
        return toLower(str1) == toLower(str2);
    }

    static std::vector<std::string> split(const std::string& str, const std::string& delimiter)
    {
        char* save = nullptr;
        char* token = strtok_r(const_cast<char*>(str.c_str()), delimiter.c_str(), &save);
        std::vector<std::string> result;
        while (token != nullptr)
        {
            result.emplace_back(token);
            token = strtok_r(nullptr, delimiter.c_str(), &save);
        }
        return result;
    }
};

#if 0
总结一下string
标准C++库字符串类std::string的用法 
#include<iostream> 
std::string s1; 
std::string s3(s2); 
std::string s2(“this is a string”); 
begin 得到指向字符串开头的Iterator 
end 得到指向字符串结尾的Iterator 
rbegin 得到指向反向字符串开头的Iterator 
rend 得到指向反向字符串结尾的Iterator 
size 得到字符串的大小 
length() 和size函数功能相同 
max_size 字符串可能的最大大小 
capacity 在不重新分配内存的情况下，字符串可能的大小 
empty 判断是否为空 
operator[] 取第几个元素，相当于数组 
c_str 取得C风格的const char* 字符串 
data 取得字符串内容地址 
operator= 赋值操作符 
reserve 预留空间 
swap 交换函数 
insert 插入字符 
append 追加字符 
push_back 追加字符 
erase 删除字符串 
clear 清空字符容器中所有内容 
resize 重新分配空间 
assign 和赋值操作符一样 
replace 替代 
copy 字符串到空间 
find 查找,返回基于0的索引号 
rfind 反向查找 
find_first_of 查找包含子串中的任何字符，返回第一个位置 
find_first_not_of 查找不包含子串中的任何字符，返回第一个位置 
find_last_of 查找包含子串中的任何字符，返回最后一个位置 
find_last_not_of 查找不包含子串中的任何字符，返回最后一个位置 
substr(n1,len) 得到字符串从n1开始的长度为len的子串 
比较字符串(支持所有的关系运算符) 
compare 比较字符串 
operator+ 字符串链接 
operator+= += 操作符 
operator== 判断是否相等 
operator!= 判断是否不等于 
operator< 判断是否小于 
operator>> 从输入流中读入字符串 
operator<< 字符串写入输出流 
getline 从输入流中读入
#endif
#endif  //  PATTERNS_STRING_H_