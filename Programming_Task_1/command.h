//
// Created by ali.zain on 5/20/2022.
//

#ifndef PROGRAMMING_TASK_1_COMMAND_H
#define PROGRAMMING_TASK_1_COMMAND_H

#include <string>
#include <iostream>
#include "clip.h"

using namespace std;

//    Booleans for checking that whether "other" and "none" actions has been called or not
bool other_called = false, none_called = false;

//  Function for taking all commands from standard input or "input" string passed in the function
//  If the "input" string variable is empty, then the function will take input from standard input
void take_input(const string& input)
{
    if(input.empty()) {
        while (!data_.empty()) {
            getline(cin, data_);
            if (!data_.empty()) {
                commands.push(data_);
            }
        }
    }
    else
    {

//        String variable single_command for storing single command
        string single_command;
        auto current_pos = 0;
        do
        {
            string remaining = input.substr(current_pos, input.size());
            single_command = remaining.substr(0, remaining.find('\n'));
            commands.push(single_command);
            current_pos += single_command.length() + 1;
            if(current_pos > input.size())
            {
                break;
            }
        }while(!single_command.empty());
    }
}

//  Lambda for checking the type of the input command
auto type_check = [](const string &t_or_c) {
    if (t_or_c == "clip") {
        return TYPE::clip;
    } else if (t_or_c == "ticks") {
        return TYPE::ticks;
    } else {
        exit(127);
    }
};

//  Function for parsing a single command
void parsing_single_command(unsigned long pos, string remaining)
{
    while (pos <= remaining.length()) {
        if (pos < remaining.length()) {
            pos = remaining.find(' ');
            remaining = pos < current.length() ? remaining.substr(pos + 1) : remaining;
            auto temp = remaining.find(' ');
            auto element = remaining.substr(0, temp);
            if (!element.empty()) {
                elements.push_back(element);
            }
        } else {
            break;
        }
    }
}

//  Function for storing command
void storing_command(TYPE type, CLIP clip)
{

//    Checking that whether the command is "ticks" or "clip" and storing it in elements queue
    if (type == TYPE::ticks) {
        total_num_of_ticks += stoul(elements.back());
        elements.pop_back();
        unsigned int count_ = count(current.begin(), current.end(), ' ');
        if ((count_ > 1 && (total_num_of_ticks * 2) != count_) || count_ != 1) {
            exit(127);
        }
    } else {
        clip.name = elements.front();
        elements.pop_front();
        clip.ticks = stoul(elements.front());
        elements.pop_front();
        clip.chance1 = stof(elements.front());
        elements.pop_front();
        clip.chance2 = stof(elements.front());
        elements.pop_front();

        clip.action1 = check_action(elements.front());
        elements.pop_front();
        clip.action2 = check_action(elements.front());
        elements.pop_front();

        auto iterator = find(clips.begin(), clips.end(), clip);

//        If the current clip exists in the clip collection, then modify it. Otherwise, just push it in the collection
        if (iterator != clips.end()) {
            *iterator = clip;
        } else {
            clips.push_back(clip);
        }
    }
}

//  Function for parsing different commands taken from standard input
void parsing_commands()
{
    while (!commands.empty()) {
        current = commands.front();
        auto pos = current.find(' ');
        string tick_or_clip = current.substr(0, pos);

        TYPE type = type_check(tick_or_clip);

        string remaining = current;
        CLIP clip;

        parsing_single_command(pos, remaining);

        storing_command(type, clip);

        commands.pop();
    }
}

//    Lambda for performing specific actions on iterator according to the given input action
auto perform_action = [](FOLLOW_ACTIONS action, list<CLIP>::iterator &iterator_) {

//        Variable for keeping record of the random number for "any" and "other" actions
    unsigned int adding = 0;

//        Switch case for "action" variable to perform several actions
    switch (action) {

        case FOLLOW_ACTIONS::previous:

//                Decrementing the iterator
            --iterator_;

//                Checking if the iterator has reached the end then decrement one more time
            if(iterator_ == clips.end())
            {
                --iterator_;
            }
            break;

        case FOLLOW_ACTIONS::next:

//                Incrementing the iterator
            ++iterator_;

//                Checking if the iterator has reached the end then increment one more time
            if(iterator_ == clips.end())
            {
                ++iterator_;
            }
            break;

        case FOLLOW_ACTIONS::any:

//                Random number generated and stored in "adding" variable
            adding = dist_any_other(gen);

//                Advancing the iterator by value stored in "adding" variable
            advance(iterator_, adding);
            break;

        case FOLLOW_ACTIONS::other:

//                Random number generated and stored in "adding" variable
            adding = dist_any_other(gen);

//                Notifying "other" action is performed by assigning true to "other_called" variable
            other_called = true;

//                Advancing the iterator by value stored in "adding" variable
            advance(iterator_, adding);
            break;

        case FOLLOW_ACTIONS::none:

//                Notifying "none" action is performed by assigning true to "none_called" variable
            none_called = true;
            break;

        default:

//                Program will exit with error code 127
            exit(127);
    }
};

//  Function for executing clips and returning the result in a string
string execute_clips()
{
//    String for storing the result
    string result;

    //    Clip container for current clip
    CLIP current_clip;

//    Checking if the clip is inserted or not and performing actions with respect to the given commands
    if (!clips.empty()) {

//        Assigning the first element of clips collection to "current_clip" variable
        current_clip = clips.front();

//        Assigning the first iterator of clips collection to "iterator" variable
        auto iterator = clips.begin();

//        Storing the number of ticks of the current clip command
        unsigned int num_of_clip_ticks = current_clip.ticks;

//        Loop executing until the number of ticks of the current clip command
        while (total_num_of_ticks > 0) {

//            Boolean for identifying if a clip has ticks or not
            bool clip_has_ticks = false;

//            Assigning the current clip the value to which the iterator is pointing
            current_clip = *iterator;

//            Number of ticks is updated according to the current clip command ticks
            num_of_clip_ticks = current_clip.ticks;

//            Number of ticks of current clip command is being subtracted from total number of ticks
            total_num_of_ticks -= num_of_clip_ticks;

//            While loop will execute when the number of ticks of current clip command is greater than zero
//            and total number of ticks is greater than or equal to 0
            while (num_of_clip_ticks > 0 && total_num_of_ticks >= 0) {

//                Assigning true to "clip_has_ticks" variable
//                This is necessary to avoid double decrement in "total_num_of_ticks" variable whose check is placed in the code
                clip_has_ticks = true;

//                Checking the specific conditions for "other" action
//                because in case of only one input clip command the "other" action should not allow the current clip to perform any action
//                After that the result is stored in "result" string
                if(!(other_called && clips.size() == 1) && (!none_called)) {
                    result += current_clip.name;
                    result += '\n';
                }

//                Decrementing "num_of_ticks" variable which has current clip's number of ticks
                --num_of_clip_ticks;
            }

//            Assigning false to "other_called" to avoid any unexpected behavior
            other_called = false;

//            Assigning false to "none_called" to avoid any unexpected behavior
            none_called = false;

//            Assigning "low" variable the lower value of chance from current clip
            float low = current_clip.chance1 < current_clip.chance2 ? current_clip.chance1 : current_clip.chance2;

//            Assigning "high" variable the higher value of chance from current clip
            float high = current_clip.chance2 < current_clip.chance1 ? current_clip.chance1 : current_clip.chance2;

//            Creating a distribution range between 1 and higher value of chance of current clip for random values
            std::uniform_real_distribution<float> dist(1, high);

//            Generating random value and checking that is it lower than the "low" variable value which is lower value of chance of the current clip
//            In this way, I have constructed the logic for implementing the chances of the current clip
//            Further explanation can be found in the readme file
            if (dist(gen) <= low) {

//                Checking that whether the "low" variable corresponds to chance1 or chance2
//                This is necessary in order to perform action1 or action2
                if (low == current_clip.chance1) {
                    perform_action(current_clip.action1, iterator);
                } else {
                    perform_action(current_clip.action2, iterator);
                }

//              If the generated random value is higher than "low" variable then it is considered as higher chance
            } else {

//                Checking that whether the "high" variable corresponds to chance1 or chance2
//                This is necessary in order to perform action1 or action2
                if (high == current_clip.chance1) {
                    perform_action(current_clip.action1, iterator);
                } else {
                    perform_action(current_clip.action2, iterator);
                }
            }

//            If there are no clips found in the clip command the simply just decrement the "total_num_of_ticks"
            if(!clip_has_ticks)
            {
                --total_num_of_ticks;
            }
        }
    }

//    Returning the result
//    This was necessary for result displaying and unittest verification
    return result;
}

#endif //PROGRAMMING_TASK_1_COMMAND_H
