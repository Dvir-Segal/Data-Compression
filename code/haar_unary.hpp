#pragma once
#include <string> // string
#include <iostream>
#include <list>
#include <math.h> 
#include <cmath>
namespace haar_unary
{
    std::string haar_integer_unary(int *arr,int k2pow);
    void inner_haar_integer_unary(std::list<int>&curnums, int k2pow,std::list<std::pair<int,int>> &listofpairs);
    std::string haar_new_trasform_unary(int *arr,int k2pow);
    void inner_haar_new_trasform_unary(std::list<int>& curnums, int k2pow, std::list<int>& listdifrence);
    std::string haar_new_trans_unary_code(std::list<int>& listdifrence);
    std::string haar_integer_unary_code(std::list<std::pair<int, int>>& listofpairs);
    std::string unary_coding(int num);
}