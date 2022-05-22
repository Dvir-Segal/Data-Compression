#include "haar_binary.hpp"
using namespace std;

namespace haar_binary
{
  std::string haar_integer_bin(int *arr, int k2pow)
  {
    std::list<std::pair<int, int>> listofpairs;
    std::list<int> curnums;
    int size = pow(2, k2pow);
    for (size_t i = 0; i < size; i++)
    {
      int cur_num = arr[i];
      curnums.push_back(cur_num);
    }
 
    inner_haar_integer_bin(curnums, k2pow, listofpairs);
    string final_msg = haar_integer_bin_code(listofpairs);
    return final_msg;
  }
  void inner_haar_integer_bin(std::list<int>& curnums, int k2pow, std::list<std::pair<int, int>>&listofpairs)
  {
    std::list<int> znumbers;
    for (std::list<int>::iterator it = curnums.begin(); it != curnums.end(); ++it)
    {
      int first = *it;
      ++it;
      int seconed = *it;
      int modof2 = (first - seconed) % 2;
      int tomatch = (first - seconed) / 2;
      int znum = (first + seconed) / 2;
      znumbers.push_back(znum);
      pair<int, int> pair1;
      pair1.first = modof2;
      pair1.second = tomatch;
      listofpairs.push_back(pair1);
    }
    if (k2pow == 1)
    {
      pair<int, int> pair2;
      pair2.first = -1;
      pair2.second = znumbers.back();
      listofpairs.push_back(pair2);
      return;
    }
    else
    {
      inner_haar_integer_bin(znumbers, k2pow - 1, listofpairs);
    }
  }
  std::string haar_integer_bin_code(std::list<std::pair<int, int>> &listofpairs)
  {
    string code_of_nums = "";
        for (std::list<std::pair<int, int>>::iterator it = listofpairs.begin(); it != listofpairs.end(); ++it)
    {
      int first = (*it).first;
      int seconed = (*it).second;
      if(first!=-1)
      {
        string bin_first = binary_coding(first);
        code_of_nums = bin_first + code_of_nums ;
      }
      string bin_seconed = binary_coding(seconed);
      code_of_nums =  bin_seconed + code_of_nums;
    }
    return code_of_nums;
  }

  std::string haar_new_trasform_bin(int *arr, int k2pow)
  {
    std::list<int> listdifrence;
    std::list<int> curnums;
    int size = pow(2, k2pow);
    for (size_t i = 0; i < size; i++)
    {
      int cur_num = arr[i];
      curnums.push_back(cur_num);
    }

    inner_haar_new_trasform_bin(curnums, k2pow, listdifrence);
    string final_massage = haar_new_trans_bin_code(listdifrence);
    return final_massage;
  }
  void inner_haar_new_trasform_bin(std::list<int>& curnums, int k2pow, std::list<int>& listdifrence)
  {
    std::list<int> znumbers;
    for (std::list<int>::iterator it = curnums.begin(); it != curnums.end(); ++it)
    {
      int first = *it;
      ++it;
      int seconed = *it;
      int dnum =floor((first - seconed) / 2);
      int znum = (first + seconed);
      znumbers.push_back(znum);
      listdifrence.push_back(dnum);
    }
    if (k2pow == 1)
    {
      listdifrence.push_back(znumbers.back());
      return;
    }
    else
    {
      inner_haar_new_trasform_bin(znumbers, k2pow - 1, listdifrence);
    }
  }
    std::string haar_new_trans_bin_code(std::list<int>& listdifrence)
  {
    string code_of_nums = "";
        for (std::list<int>::iterator it = listdifrence.begin(); it != listdifrence.end(); ++it)
    {
      int first = *it;
      string bin_first = binary_coding(first);
        code_of_nums = bin_first +  code_of_nums;
    }
    return code_of_nums;
  }
  string binary_coding(int num)
  {
    if (num == 0)
    {
      return "0";
    }
    string word ="";
    while (num != 1)
    {
      if (num % 2 == 0)
      {
        word = "0" + word;
      }
      else
        {
          word = "1" + word;
        }
        num = num/2;
    }
    word = "1" + word;
    return word;
  }

}