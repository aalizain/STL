//any_of returns true when a condition is present for at least one element in the given range

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    std::array<int, 5> arr{0, 1, 1, 5, 5};
    if(any_of(arr.begin(), arr.end(), [](int x){return x % 2 ? false : true;}))
    {
        cout << "At least one element is even";
    }
    else
    {
        cout << "No element is even";
    }
}
