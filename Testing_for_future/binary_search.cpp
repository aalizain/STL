/// \binary_search
/// \Conditions
/// \n Range must be sorted in ascending order
/// \n There should be the direct access to the middle element in any sublist

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    std::array<int, 5> arr{1, 1, 4, 5, 5};
    if(binary_search(arr.begin(), arr.end(), 4))
    {
        cout << "4 is present";
    }
    else
    {
        cout << "4 is not present";
    }
}
