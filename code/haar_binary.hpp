#pragma once
#include <string> // string
#include <iostream>
#include <list>
#include <math.h> 
#include <cmath>
namespace haar_binary
{
    std::string haar_integer_bin(int *arr,int k2pow);
    void inner_haar_integer_bin(std::list<int>&curnums, int k2pow,std::list<std::pair<int,int>> &listofpairs);
    std::string haar_new_trasform(int *arr,int k2pow);
    void inner_haar_new_trasform(std::list<int>& curnums, int k2pow, std::list<int>& listdifrence);
    std::string haar_new_trans_c_delta_code(std::list<int>& listdifrence);
    std::string haar_integer_c_delta_code(std::list<std::pair<int, int>>& listofpairs);
    std::string unary_coding(int num);
    std::string binary_coding(int num);
    std::string c_gama_coding(int num);
    std::string c_delta_coding(int num);
}