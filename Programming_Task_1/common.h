//
// Created by ali.zain on 5/20/2022.
//

#ifndef PROGRAMMING_TASK_1_COMMON_H
#define PROGRAMMING_TASK_1_COMMON_H

#include <random>
#include <queue>
#include <deque>
#include <list>

using namespace std;

//  Int for keeping record of total number of ticks given in overall ticks commands
int total_num_of_ticks = 0;

//  Deque container for storing independent elements from the command
deque<string> elements;

//  Queue container for storing all the commands given as input
queue<string> commands;

//  Random device object for random number generation
random_device rd;

//  String containers for storing current command and data inserted as input command
string current, data_ = " ";

//  Geneartor object for generating random numbers
mt19937 gen(rd());

#endif //PROGRAMMING_TASK_1_COMMON_H
