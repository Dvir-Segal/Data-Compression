#pragma once
#include <string> // string
#include <iostream>
#include <list>
#include <math.h> 
#include <cmath>
namespace haar_fibo
{
    std::string haar_integer_fibo(int *arr,int k2pow);
    void inner_haar_integer_fibo(std::list<int>&curnums, int k2pow,std::list<std::pair<int,int>> &listofpairs);
    std::string haar_new_trasform_fibo(int *arr,int k2pow);
    void inner_haar_new_trasform_fibo(std::list<int>& curnums, int k2pow, std::list<int>& listdifrence);
    std::string haar_new_trans_fibo_code(std::list<int>& listdifrence);
    std::string haar_integer_fibo_code(std::list<std::pair<int, int>>& listofpairs);
    std::string fibo_coding(int num);
}