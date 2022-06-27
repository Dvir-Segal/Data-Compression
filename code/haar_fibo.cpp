#include "haar_fibo.hpp"
using namespace std;

namespace haar_fibo
{
  std::string haar_integer_fibo(int *arr, int k2pow)
  {
    std::list<std::pair<int, int>> listofpairs;
    std::list<int> curnums;
    int size = pow(2, k2pow);
    for (size_t i = 0; i < size; i++)
    {
      int cur_num = arr[i];
      curnums.push_back(cur_num);
    }
 
    inner_haar_integer_fibo(curnums, k2pow, listofpairs);
    string final_msg = haar_integer_fibo_code(listofpairs);
    return final_msg;
  }
  void inner_haar_integer_fibo(std::list<int>& curnums, int k2pow, std::list<std::pair<int, int>>&listofpairs)
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
      inner_haar_integer_fibo(znumbers, k2pow - 1, listofpairs);
    }
  }
  std::string haar_integer_fibo_code(std::list<std::pair<int, int>> &listofpairs)
  {
    string code_of_nums = "";
        for (std::list<std::pair<int, int>>::iterator it = listofpairs.begin(); it != listofpairs.end(); ++it)
    {
      int first = (*it).first;
      int seconed = (*it).second;
      if(first!=-1)
      {
        string c_delta_first = fibo_coding(first);
        code_of_nums = c_delta_first + code_of_nums ;
      }
      string c_delta_seconed = fibo_coding(seconed);
      code_of_nums =  c_delta_seconed + code_of_nums;
    }
    return code_of_nums;
  }

  std::string haar_new_trasform_fibo(int *arr, int k2pow)
  {
    std::list<int> listdifrence;
    std::list<int> curnums;
    int size = pow(2, k2pow);
    for (size_t i = 0; i < size; i++)
    {
      int cur_num = arr[i];
      curnums.push_back(cur_num);
    }

    inner_haar_new_trasform_fibo(curnums, k2pow, listdifrence);
    string final_massage = haar_new_trans_fibo_code(listdifrence);
    return final_massage;
  }
  void inner_haar_new_trasform_fibo(std::list<int>& curnums, int k2pow, std::list<int>& listdifrence)
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
      inner_haar_new_trasform_fibo(znumbers, k2pow - 1, listdifrence);
    }
  }
    std::string haar_new_trans_fibo_code(std::list<int>& listdifrence)
  {
    string code_of_nums = "";
        for (std::list<int>::iterator it = listdifrence.begin(); it != listdifrence.end(); ++it)
    {
      int first = *it;
      string c_delta_first = fibo_coding(first);
        code_of_nums = c_delta_first +  code_of_nums;
    }
    return code_of_nums;
  }


  string fibo_coding(int num)
  {
    if (num == 0)
    {
      return "11";
    }
    num = num+1;
    int size = 0;
    list<int> one_location;
    string word ="";
    while(num!=0)
    {
        int counter = 1;
        int fib_num1 = 1;
        int fib_num2 = 1;
    while (fib_num2 < num )
    {
      int temp_num = fib_num1;
      fib_num1 = fib_num2;
      fib_num2 = fib_num1 + temp_num;
      counter++;
    }
     if(num == fib_num2)
     {
       num = num-fib_num2;
     }
     else{
       num = num-fib_num1;  
       counter = counter -1;
     }
    one_location.push_back(counter);
     if(size == 0)
     {
         size = counter;
     }
    }
    int cur_location = one_location.front();
    one_location.pop_front();
    int i=0;
    for ( i=size; i > 0; i=i-1)
    {
        if(i==cur_location)
        {
            word = word + "1";
            if(!one_location.empty())
            {cur_location = one_location.front();
            one_location.pop_front();}
            else{
                cur_location = -1;
            }
        }
        else{
          word = word + "0";
        }
    }
   string rev_word ="";
   for (int index = 0, len = word.length(); (index < len); index++) {
      rev_word =  rev_word +  word[len-1-index];
   }
   rev_word  = rev_word +"1";
    return rev_word;
  }
}