
#include "haar.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <bits/stdc++.h>
using namespace std;
#define SIZE 8
#define K_SIZE 3
#define LOOP 100
#define NUM_LIM 10000

void get_rand_numbers(int cur_numbers [])
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
       for(int i = 0 ; i<SIZE ; i++)
    {
      cur_numbers[i] = ((rand() % NUM_LIM) + 1);
    }
    int n = sizeof(cur_numbers) / sizeof(cur_numbers[0]);
  
    /*Here we take two parameters, the beginning of the
    array and the length n upto which we want the array to
    be sorted*/
    sort(cur_numbers, cur_numbers + n);
    for (int j = 0; j < n; ++j)
        {std::cout << cur_numbers[j] << ",";}
    std::cout  << std::endl;
}

void run_rand(int score [])
{
    for(int i = 0 ; i<LOOP ; i++)
    {
       int cur_numbers[SIZE];
       get_rand_numbers(cur_numbers);
       string haar_in_ans = haar_algorithm::haar_integer(cur_numbers,K_SIZE);
       string haar_trn_ans = haar_algorithm::haar_new_trasform(cur_numbers,K_SIZE);
       score[3] = score[3] + haar_in_ans.size();
       score[4] = score[4] + haar_trn_ans.size();
       if(haar_in_ans.size()>haar_trn_ans.size())
       {
           score[0] = score[0] +1;
       }
       else if(haar_in_ans.size()<haar_trn_ans.size())
       {
           score[1] = score[1] +1;
       }
       else{
           score[2] = score[2] +1;
       }
    }
}
int main() {
	int score [5] = { 0,0,0,0,0 };
    run_rand(score);
    
    return 0;
}