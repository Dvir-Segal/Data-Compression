#pragma once
#include <string> // string
#include <iostream>
#include <list>
#include <math.h> 
#include <cmath>
namespace haar_decode
{
    void haar_integer_decode(std::string code);
    void haar_new_trasform_decode(std::string code);
    std::list<int>& haar_integer_get_numbers(std::list<int> & numbers);
    std::list<int>& haar_new_trasform_get_numbers(std::list<int> numbers);
    std::list<int>& haar_integer_get_numbers_inner(std::list<int> & numbers,std::list<int>& cur_numbers, int index ,int size_k, int max);
    std::list<int>& haar_new_trasform_get_numbers_inner(std::list<int> & numbers,std::list<int>& cur_numbers, int index ,int size_k, int max);
    void binary_to_numbers(std::string code, std::list<int>& numbers);
    int binary_decode(std::string code, int index,int c_del_size);
    int find_k_size(int size_numbers);
    void print_list(std::list<int>& numbers);
} 