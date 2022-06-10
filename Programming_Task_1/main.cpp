/// \FollowMe Follow Me is the project for implementation of clip and ticks commands
/// \n \Conditions
///    -- Assumption is made that all the input would be syntactically correct according to the task requirements
/// \n -- However, if the input command is not correct, the program will exit with error code 127
/// \n \Note
///         Error code 127 represents that the command is not correct

//  Header files
#include "clip.h"
#include "command.h"

using namespace std;

int main() {

//    Calling function for taking input. If the string is empty it will take input from standard input
    take_input("");

//    Calling function for parsing commands
    parsing_commands();

//    Calling function for executing clips and printing the returned string
    cout << execute_clips();

    return 0;
}
