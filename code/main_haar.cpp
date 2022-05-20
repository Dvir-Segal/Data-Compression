
#include "haar.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
#define SIZE 2
#define K_SIZE 1
#define LOOP 1000
#define NUM_LIM 10000

void get_rand_numbers(int cur_numbers[])
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < SIZE; i++)
    {
        cur_numbers[i] = ((rand() % NUM_LIM) + 1);
    }
}

void run_rand(int score[])
{
    for (int i = 0; i < LOOP; i++)
    {
        int cur_numbers[SIZE];
        get_rand_numbers(cur_numbers);
        int n = sizeof(cur_numbers) / sizeof(cur_numbers[0]);
        /*Here we take two parameters, the beginning of the
        array and the length n upto which we want the array to
         be sorted*/
        sort(cur_numbers, cur_numbers + n ,greater<int>());
        string haar_in_ans = haar_algorithm::haar_integer(cur_numbers, K_SIZE);
        string haar_trn_ans = haar_algorithm::haar_new_trasform(cur_numbers, K_SIZE);
        score[3] = score[3] + haar_in_ans.size();
        score[4] = score[4] + haar_trn_ans.size();
        if (haar_in_ans.size() < haar_trn_ans.size())
        {
            score[0] = score[0] + 1;
        }
        else if (haar_in_ans.size() > haar_trn_ans.size())
        {
            score[1] = score[1] + 1;
        }
        else
        {
            score[2] = score[2] + 1;
        }
    }
}
int main()
{
    int score[5] = {0, 0, 0, 0, 0};
    run_rand(score);
    ofstream myfile;
    std::string file_name , content;
    file_name = to_string(SIZE) +  "_arg_" ; 
    myfile.open (file_name);
    content = to_string(score[0]) + "," + to_string(score[1]) + "," + to_string(score[2]) + "," + to_string(score[3]) + "," + to_string(score[4]) ;
     //exception handling
  try {
    //open file for writing
    ofstream fw(file_name, std::ofstream::out);
    //check if file was successfully opened for writing
    if (fw.is_open())
    {
      //store array contents to text file
        fw << content << "\n";
      fw.close();
    }
    else cout << "Problem with opening file";
  }
  catch (const char* msg) {
    cerr << msg << endl;
  }
    return 0;
}