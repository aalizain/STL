/// \copy
/// copying values from input iterators and pasting them on the output iterators in forward direction

/// \copy_n
/// copying specific number of elements

/// \copy_if
/// copying if the specific condition is met
/// All the previous three arguments are similar to copy, but the fourth argument if of a function pointer or lambda which returns a boolean
/// If the boolean is true, then the value is copied. Otherwise, the value is not copied.

/// \copy_backward
/// copies elements backwards from the input ending iterator and finishes at the input starting iterator and pastes the elements in the destination container in forward direction
/// So the overall presentation in the destination is in reverse order as found in source container

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> vec1 = {1, 2, 3, 4, 5, 6};

//    if the vector does not have space for six elements then a segmentation fault will be generated
//    i.e. instead of vector<int> vec2(6), if there is written vector<int> vec2
    vector<int> vec2(6);

    copy(vec1.begin(), vec1.end(), vec2.begin());

    for(auto i : vec2)
    {
        cout << i << endl;
    }
}
