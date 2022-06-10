/// \Clamp
/// clamp is used for checking that whether a value is lower than lower bound, upper than upper bound or between them
/// In case of lower than lower bound, the lower value is returned
/// In case of upper than upper bound, the upper value is returned
/// In case of the value existing between the lower and upper bounds, the value itself is returned

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int x = 4;
    auto value = clamp(x, 0, 5);
    switch (value) {
        case 4:
            cout << "The value is between the range" << endl;
            break;

        case 0:
            cout << "The value is lower than the lower bound" << endl;
            break;

        case 5:
            cout << "The value is upper than the upper bound" << endl;
            break;

        default:
            cout << "The value is undefined" << endl;
            break;
    }
}
