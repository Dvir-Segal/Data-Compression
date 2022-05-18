#include "haar_decode.hpp"
using namespace std;

namespace haar_decode
{
 void haar_integer_decode(std::list<int>& final_numbers ,std::string code)
 {
     std::list<int> numbers;
    binary_to_numbers(code,numbers); 
    print_list(numbers);
    haar_integer_get_numbers(final_numbers,numbers);
  
 }
 void haar_new_trasform_decode(std::list<int>& final_numbers,std::string code)
 {
    std::list<int> numbers;
    binary_to_numbers(code,numbers);
    print_list(numbers);
    haar_new_trasform_get_numbers(final_numbers,numbers);
  
     
 }
  void haar_integer_get_numbers(std::list<int>& final_numbers ,std::list<int> & numbers)
 {
    std::list<int> cur_numbers ;
    int first = numbers.front();
    cur_numbers.push_back(first);
    int num_count = (numbers.size()-1)/2;
    int max = find_k_size(num_count);
    int i =1,size_k=0;
    haar_integer_get_numbers_inner(final_numbers,numbers,cur_numbers,i,size_k,max);

 }
  void haar_integer_get_numbers_inner(std::list<int>& final_numbers ,std::list<int> & numbers,std::list<int>& cur_numbers1, int index ,int size_k, int max)
 {
     
     if (size_k== max)
     {
        for (auto itr = cur_numbers1.begin(); itr != cur_numbers1.end(); itr++)
        {
             final_numbers.push_front(*itr);
        }
        return;
     }
     std::list<int> cur_numbers2 ;
     int diff,cur_num,num1,num2,cur_bignum;
     list<int>::iterator it = numbers.begin();
     advance(it, index);
     list<int>::iterator it2 = cur_numbers1.begin();
     advance(it2, 0);
 for (size_t i = 0; i < pow(2,size_k); i++)
 {
    diff = *it;
    it++;
    cur_num = *it;
    it++;
    cur_bignum = *it2;
    num1 = cur_bignum + diff + cur_num;
    num2 = cur_bignum -diff;
    cur_numbers2.push_back(num2);
    cur_numbers2.push_back(num1);
    it2++;
 }
 index = index + pow(2,size_k)*2;
 haar_integer_get_numbers_inner(final_numbers,numbers,cur_numbers2,index,size_k+1,max);
 
 }
  void haar_new_trasform_get_numbers(std::list<int>& final_numbers,std::list<int> numbers)
 {
 std::list<int> cur_numbers ;
    cur_numbers.push_back(numbers.front());
    int num_count = (numbers.size()-1);
    int max = find_k_size(num_count);
    int i =1,size_k=0;
    haar_new_trasform_get_numbers_inner(final_numbers,numbers,cur_numbers,i,size_k,max);
 }
void haar_new_trasform_get_numbers_inner(std::list<int>& final_numbers,std::list<int> & numbers,std::list<int>& cur_numbers, int index ,int size_k, int max)
 {
     if (size_k== max)
     {
            for (auto itr = cur_numbers.begin(); itr != cur_numbers.end(); itr++)
        {
             final_numbers.push_front(*itr);
        }
        return;
     }
     std::list<int> cur_numbers2 ;
     int cur_num,num1,num2;
     list<int>::iterator it = numbers.begin();
     advance(it, index);
     list<int>::iterator it2 = cur_numbers.begin();
     advance(it2, 0);
 for (size_t i = 0; i < pow(2,size_k); i++)
 {
    cur_num = *it;
    it++;
    int big_num = *it2;
    num1 = ceil((double(big_num))/2)  + cur_num;
    num2 = big_num/2 - cur_num;
    cur_numbers2.push_back(num2);
    cur_numbers2.push_back(num1);
    it2++;
 }
 index = index + pow(2,size_k);
 haar_new_trasform_get_numbers_inner(final_numbers, numbers,cur_numbers2,index,size_k+1,max);
 
 }
 void binary_to_numbers(std::string code, std::list<int>& numbers)
 {
    int code_size = code.length();
    int unary_size = 0;
    for (size_t i = 0; i <code_size; i++)
    {
        if (code[i]=='0')
        {
           unary_size++;
        }
        else
        {
          if(unary_size == 0)
          {
              numbers.push_back(0);
          }
          else
          {
          i++;
          int binary_size = binary_decode(code,i,unary_size)-1;
          i+=unary_size;
          unary_size = 0;
          int cur_num = binary_decode(code,i,binary_size)-1;
          numbers.push_back(cur_num);
          i+=binary_size-1;
          }
        } 
    } 
 }
 int binary_decode(std::string code, int index,int c_del_size)
 {
  int num = pow(2,c_del_size);
  int j =c_del_size-1;
  while ( j>=0)
  {
      if(code[index] == '1')
      {
          num += pow(2,j);
      }
      index++;
      j=j-1;
  }
  return num;
 }
  int find_k_size(int size_numbers)
 {
  int sum = 0;
  int i = 0;
  while (sum != size_numbers)
  {
     sum+=pow(2,i);
     i++;
  }
  return i;
  
 }
 void print_list(std::list<int>& numbers)
 {
     std::list<int>::iterator it;
     for (it = numbers.begin(); it != numbers.end(); it++)
   {
    int num  = *it;
    std::cout << num << "," ;
   }
   std::cout  << std::endl;
 }
}