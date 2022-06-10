//
// Created by ali.zain on 5/25/2022.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    vector<string> words;
    unordered_map<char, int> characters;
    string str = "Hello my name is aahad";
    stringstream ss(str);
    string item;
    char delim = ' ';

    while (getline (ss, item, delim)) {
        words.push_back(item);
    }

    int highest = 0;
    string most_occ;

    for(auto i : words)
    {
        for(auto j : i)
        {
            if(characters.contains(j))
            {
                ++characters.find(j)->second;
            }
            else
            {
                characters.insert({j, 1});
            }
        }

        auto highest_ = max_element(characters.begin(), characters.end(), [](const auto &x, const auto &y) {
            return x.second < y.second;
        });

        if(highest_->second > highest)
        {
            highest = highest_->second;
            most_occ = i;
        }

        characters.clear();
    }

    cout << "String: " << most_occ << endl;
    cout << "Most number of repeated characters: " << highest << endl;
}
