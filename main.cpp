//Реализовать сортировку и оценить её сложность.
//Сортировка подсчётом

#include <iostream>
#include <ctime>
#include <chrono>
#include "timer.hpp"

using namespace std;
using namespace chrono_literals;

void CountSort(int* arr, int n, int a) 
{
    int* counts = new int[a];

    for (int i = 0; i < a; i++) 
    { 
        counts[i] = 0;
    }

    for (int i = 0; i < n; i++) 
    { 
        counts[arr[i]]++;
    }

    int k = 0;

    for (int i = 0; i < a; i++)
    { 
        if (counts[i] != 0) 
        {
            while (counts[i] != 0) 
            {
                arr[k] = i;
                k++;
                counts[i]--;
            }
        }
    }
    delete[] counts;
}

void PrintArray(int* arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void RandomElements(int* arr, int n, int a) 
{
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % a;
    }
}

int main()
{
    srand(time(0));

    int a = 100000;
    int n = 100000;
    int* arr = new int[n];

    RandomElements(arr, n, a);

    yc::Timer timer;
    CountSort(arr, n, a);
    cout << timer.elapsed() << endl;

    cout << endl;
    delete[] arr;

    return 0;
    
    // сложность О(n)
}