//
// Created by ali.zain on 5/21/2022.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "clip.h"
#include "command.h"
#include <doctest/doctest.h>

using namespace std;

string input, result;

TEST_CASE("Executing example commands given in the task") {

    cout << endl;
    cout << "Executing example commands in the task........." << endl;

    sleep(1);

    input = "clip hello 2 1.0 0.0 next none"
            "\nclip world 3 1.0 0.0 previous none"
            "\nticks 10";

    take_input(input);

    parsing_commands();

    result = execute_clips();

    CHECK(result == "hello\nhello\nworld\nworld\nworld\nhello\nhello\nworld\nworld\nworld\n");
    elements.clear();
    clips.clear();
}

TEST_CASE("Executing input clip command with no ticks command")
{
    cout << "Executing input clip command with no ticks command........." << endl;

    sleep(1);

    input = "clip hello 5 1.0 0.0 previous none";

    take_input(input);

    parsing_commands();

    result = execute_clips();

    CHECK(result.empty());
    elements.clear();
    clips.clear();
}

TEST_CASE("Executing input clip command with 0 ticks command")
{
    cout << "Executing input clip command with 0 ticks command........." << endl;

    sleep(1);

    input = "clip hello 5 1.0 0.0 previous none"
            "\nticks 0";

    take_input(input);

    parsing_commands();

    result = execute_clips();

    CHECK(result.empty());
    elements.clear();
    clips.clear();
}

TEST_CASE("Executing single input clip command with 'other' action")
{
    cout << "Executing single input clip command with 'other' action........." << endl;

    sleep(1);

    input = "clip hello 5 1.0 0.0 other none"
            "\nticks 10";

    take_input(input);

    parsing_commands();

    result = execute_clips();

    CHECK(result == "hello\nhello\nhello\nhello\nhello\n");
    elements.clear();
    clips.clear();
}

TEST_CASE("Executing input clip command with more ticks than total ticks")
{
    cout << "Executing input clip command with more ticks than total ticks........." << endl;

    sleep(1);

    input = "clip hello 5 1.0 0.0 other none"
            "\nticks 3";

    take_input(input);

    parsing_commands();

    result.clear();

    result = execute_clips();

    CHECK(result.empty());
    elements.clear();
    clips.clear();
}
