#ifndef LCSSEEKERPARTONE_HPP
#define LCSSEEKERPARTONE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "LcsTool.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: LcsSeekerPartOne.hpp
 *   Assignment number: Project 5
 *
 *   Other comments regarding the file - defines attributes and methods for a program that will read two strings from a file
 *   compute the longest common subsequence, and then reconstruct the subsequence using the "c" array.
 *
 ***************************************************************/

using std::ifstream;
using std::string;

class LcsSeekerPartOne
{
    private:
    const string FILE_NAME = "twoStrings.txt";
    ifstream reader;
    LcsTool* testTool;
    string firstString;
    string secondString;

    public:
    LcsSeekerPartOne();
    void Run();
    ~LcsSeekerPartOne();
};

#endif