#include "utils/median.h"
#include <algorithm>


//resource: https://www.geeksforgeeks.org/cpp/finding-median-of-unsorted-array-in-linear-time-using-c-stl/
// nth_element places the nth element in arr as it would appear in its sorted form

float median(float* arr, int n)
{

    // even or odd check 
    if(n % 2 == 0)
    {
        std::nth_element(arr, arr + n/2, arr + n);
        std::nth_element(arr, arr + (n - 1)/2, arr + n);
        
        return (arr[(n-1)/2] + arr[n/2])/2.0;
    }
    else 
    {
        std::nth_element(arr, arr + n/2, arr + n);
    }
    return arr[n/2];

}