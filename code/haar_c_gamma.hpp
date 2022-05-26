#pragma once
#include <string> // string
#include <iostream>
#include <list>
#include <math.h> 
#include <cmath>
namespace haar_c_gamma
{
    std::string haar_integer_c_gamma(int *arr,int k2pow);
    void inner_haar_integer_c_gamma(std::list<int>&curnums, int k2pow,std::list<std::pair<int,int>> &listofpairs);
    std::string haar_new_trasform_c_gamma(int *arr,int k2pow);
    void inner_haar_new_trasform_c_gamma(std::list<int>& curnums, int k2pow, std::list<int>& listdifrence);
    std::string haar_new_trans_c_gamma_code(std::list<int>& listdifrence);
    std::string haar_integer_c_gamma_code(std::list<std::pair<int, int>>& listofpairs);
    std::string unary_coding(int num);
    std::string binary_coding(int num);
    std::string c_gamma_coding(int num);
}