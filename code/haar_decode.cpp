#include "haar_decode.hpp"
using namespace std;

namespace haar_decode
{
 void haar_integer_decode(std::string code)
 {
     std::list<int> numbers;
    binary_to_numbers(code,numbers); 
    std::list<int> original_numbers =haar_integer_get_numbers(numbers);
    printf("finish");
    

 }
 void haar_new_trasform_decode(std::string code)
 {
     std::list<int> numbers;
     binary_to_numbers(code,numbers);
     std::list<int> original_numbers;
     printf("finish");
 }
  std::list<int>& haar_integer_get_numbers(std::list<int> & numbers)
 {
    std::list<int> cur_numbers ;
    cur_numbers.push_back(numbers.front());
    int num_count = (numbers.size()-1)/2;
    int max = find_k_size(num_count);
    int i =1,size_k=0;
    return haar_integer_get_numbers_inner(numbers,cur_numbers,i,size_k,max);
  
 }
  std::list<int>& haar_integer_get_numbers_inner(std::list<int> & numbers,std::list<int>& cur_numbers, int index ,int size_k, int max)
 {
     if (size_k== max)
     {
         return cur_numbers;
     }
     std::list<int> cur_numbers2 ;
     int diff,cur_num,num1,num2;
     list<int>::iterator it = numbers.begin();
     advance(it, index);
     list<int>::iterator it2 = cur_numbers.begin();
     advance(it2, 0);
 for (size_t i = 0; i < pow(2,size_k); i++)
 {
    diff = *it;
    it++;
    cur_num = *it;
    it++;
    num1 = *it2 + diff + cur_num;
    num2 = *it2 - cur_num;
    cur_numbers2.push_back(num1);
    cur_numbers2.push_back(num2);
    it2++;
 }
 index = index + pow(2,size_k)*2;
return haar_integer_get_numbers_inner(numbers,cur_numbers2,index,size_k+1,max);
 
 }
  std::list<int>& haar_new_trasform_get_numbers(std::list<int> numbers)
 {
 std::list<int> cur_numbers ;
    cur_numbers.push_back(numbers.front());
    int num_count = (numbers.size()-1);
    int max = find_k_size(num_count);
    int i =1,size_k=0;
    return haar_new_trasform_get_numbers_inner(numbers,cur_numbers,i,size_k,max);
 }
   std::list<int>& haar_new_trasform_get_numbers_inner(std::list<int> & numbers,std::list<int>& cur_numbers, int index ,int size_k, int max)
 {
     if (size_k== max)
     {
         return cur_numbers;
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
    num1 = ceil(*it2/2)  + cur_num;
    num2 = *it2/2 - cur_num;
    cur_numbers2.push_back(num1);
    cur_numbers2.push_back(num2);
    it2++;
 }
 index = index + pow(2,size_k);
return haar_new_trasform_get_numbers_inner(numbers,cur_numbers2,index,size_k+1,max);
 
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
  for (size_t i = c_del_size-1; i >= 0; i--)
  {
      if(code[index] == '1')
      {
          num += pow(2,i);
      }
      index++;
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
    // Access the object through iterator
    // int num = it*;
    
    //Print the contents
    // std::cout << num << "," << std::endl;
}
 }
}