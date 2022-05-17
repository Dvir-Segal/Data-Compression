#include "haar.hpp"
using namespace std;

namespace haar_algorithm
{
  std::string haar_integer(int *arr, int k2pow)
  {
    std::list<std::pair<int, int>> listofpairs;
    std::list<int> curnums;
    int size = pow(2, k2pow);
    for (size_t i = 0; i < size; i++)
    {
      int cur_num = arr[i];
      curnums.push_back(cur_num);
    }
 
    inner_haar_integer(curnums, k2pow, listofpairs);
    string final_msg = haar_integer_c_delta_code(listofpairs);
    return final_msg;
  }
  void inner_haar_integer(std::list<int>& curnums, int k2pow, std::list<std::pair<int, int>>&listofpairs)
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
      inner_haar_integer(znumbers, k2pow - 1, listofpairs);
    }
  }
  std::string haar_integer_c_delta_code(std::list<std::pair<int, int>> &listofpairs)
  {
    string code_of_nums = "";
        for (std::list<std::pair<int, int>>::iterator it = listofpairs.begin(); it != listofpairs.end(); ++it)
    {
      int first = (*it).first;
      int seconed = (*it).second;
      if(first!=-1)
      {
        cout<<first<<endl;
        string c_delta_first = c_delta_coding(first);
        cout<<c_delta_first<<endl;
        code_of_nums = c_delta_first + code_of_nums ;
      }
      cout<<seconed<<endl;
      string c_delta_seconed = c_delta_coding(seconed);
       cout<<c_delta_seconed<<endl;
      code_of_nums =  c_delta_seconed + code_of_nums;
    }
    return code_of_nums;
  }

  std::string haar_new_trasform(int *arr, int k2pow)
  {
    std::list<int> listdifrence;
    std::list<int> curnums;
    int size = pow(2, k2pow);
    for (size_t i = 0; i < size; i++)
    {
      int cur_num = arr[i];
      curnums.push_back(cur_num);
    }

    inner_haar_new_trasform(curnums, k2pow, listdifrence);
    string final_massage = haar_new_trans_c_delta_code(listdifrence);
    return final_massage;
  }
  void inner_haar_new_trasform(std::list<int>& curnums, int k2pow, std::list<int>& listdifrence)
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
      inner_haar_new_trasform(znumbers, k2pow - 1, listdifrence);
    }
  }
    std::string haar_new_trans_c_delta_code(std::list<int>& listdifrence)
  {
    string code_of_nums = "";
        for (std::list<int>::iterator it = listdifrence.begin(); it != listdifrence.end(); ++it)
    {
      int first = *it;
         cout<<first<<endl;
      string c_delta_first = c_delta_coding(first);
         cout<<c_delta_first<<endl;
        code_of_nums = c_delta_first +  code_of_nums;
    }
    return code_of_nums;
  }
  string unary_coding(int num)
  {
    num = num +1;
    string word;
    for (int i = 1; i < num; i++)
    {
      word.push_back('0');
    }
    word.push_back('1');
    return word;
  }
  string binary_coding(int num)
  {
    if (num == 0)
    {
      return "";
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
    return word;
  }
  string c_gama_coding(int num)
  {
    string c_gama_str,binary_code;
    binary_code =  binary_coding(num);
    c_gama_str = unary_coding(binary_code.size()) + binary_code;
    return c_gama_str;
  }
    string c_delta_coding(int num)
  {
    string c_delta_str,binary_code;
    binary_code =  binary_coding(num+1);
    c_delta_str = c_gama_coding(binary_code.size()+1) +  binary_code;
    return c_delta_str;
  }
}