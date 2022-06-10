//
// Created by ali.zain on 5/20/2022.
//

#ifndef PROGRAMMING_TASK_1_CLIP_H
#define PROGRAMMING_TASK_1_CLIP_H

#include "common.h"

using namespace std;

//  Types of commands which can be utilized
enum class TYPE {
    ticks,
    clip
};

//  Pre-defined actions for clips
enum class FOLLOW_ACTIONS {
    none,
    any,
    other,
    next,
    previous
};

//  Lambda for checking action and converting it to FOLLOW_ACTION type
auto check_action = [](const string &action) {
    if (action == "none") {
        return FOLLOW_ACTIONS::none;
    } else if (action == "any") {
        return FOLLOW_ACTIONS::any;
    } else if (action == "other") {
        return FOLLOW_ACTIONS::other;
    } else if (action == "next") {
        return FOLLOW_ACTIONS::next;
    } else if (action == "previous") {
        return FOLLOW_ACTIONS::previous;
    } else {
        exit(127);
    }
};

//  Struct for storing clip
struct CLIP {

//  Overloading == operator for comparison and making finding possible in list of clips
    bool operator==(const CLIP &other) const {
        return (this->name == other.name);
    }

//  String container for storing the name
    string name;

//  Unsigned int container for storing ticks of clip
    unsigned int ticks = 0;

//  Float containers for storing chance1 and chance2
    float chance1 = 0;
    float chance2 = 0;

//  Custom follow action containers for storing action1 and action2
    FOLLOW_ACTIONS action1 = FOLLOW_ACTIONS::none;
    FOLLOW_ACTIONS action2 = FOLLOW_ACTIONS::none;
};

//  List container for storing clips
list<CLIP> clips;

//  Generating random distribution objects for any and other actions
std::uniform_int_distribution<unsigned int> dist_any_other(0, clips.size());

#endif //PROGRAMMING_TASK_1_CLIP_H
