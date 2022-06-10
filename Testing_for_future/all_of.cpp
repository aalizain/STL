//all_of returns true when a specific condition is met for all the elements of the given range

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    std::array<int, 5> arr{0, 2, 2, 4, 4};
    if(all_of(arr.begin(), arr.end(), [](int x){return x % 2 ? false : true;}))
    {
        cout << "All elements are even";
    }
    else
    {
        cout << "All elements are not even";
    }
}
