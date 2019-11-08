#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <typeinfo>
#include <windows.h>
#include <thread>
#include "pch.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
void insert_multiply(int* mas1, int* mas2, size_t size) 
{
  int mul = 1;
  int count_zero = 0;

  for (size_t i = 0; i < size; ++i)
  {
    if (!mas1[i])
    {
      ++count_zero;
    }
  }

  if (count_zero >= 2)
  {
    //all next actions are mindless, because in results  give zero
    memset(mas2, 0, size * sizeof(int));
    cout << "Input array contain too many zeros" << endl;
    return;
  }

  for (size_t i = 0; i < size; ++i)
  {
    if (mas1[i])
    {
      mul *= mas1[i];
    }
  }
  
  cout << "Myultiply of input array : " << mul << endl;

  if (!count_zero)
  {
    for (size_t i = 0; i < size; ++i)
    {
      mas2[i] = mul / mas1[i];
    }
  }
  else
  {
    memset(mas2, 0, size * sizeof(int));

    for (size_t i = 0; i < size; ++i)
    {
      if (!mas1[i])
      {
        mas2[i] = mul;
        //return;
      }
    }
  }

  cout << "Output array: ";
  for (size_t i = 0; i < size; ++i)
  {
    cout << mas2[i] << " ";
  }
  cout << endl;
}


int main(int, char*[])
{
  constexpr size_t size = 6;
  int mas1[size] = { 1, 2, 3, 4, 5, 6 };
  int mas2[size] = { 1, 2, 3, 0, 5, 6 };
  int mas3[size] = { 1, 2, 0, 0, 5, 6 };
  int mas4[size] = { 1, 2, 3, 0, 0, 0 };
  int result[size] = { 0 };

  insert_multiply(mas1, result, size);
  insert_multiply(mas2, result, size);
  insert_multiply(mas3, result, size);
  insert_multiply(mas4, result, size);

}