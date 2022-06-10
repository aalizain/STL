//adjacent_find finds first two adjacent matching elements and returns the address to first matching value

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    std::array<int, 5> arr{1, 1, 3, 3, 5};
    int *ptr = adjacent_find(arr.begin(), arr.end());
    cout << "Matching elements: " << *ptr++ << " ";
    cout << *ptr;
}
