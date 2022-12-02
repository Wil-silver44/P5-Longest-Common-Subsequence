#ifndef LCSSEEKERPARTTWO_HPP
#define LCSSEEKERPARTTWO_HPP
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
 *   Other comments regarding the file - defines attributes and methods for a program that will read multiple strings from a file
 *   calculate measures of similarity among an arbitrary number of character strings in a file.
 *
 ***************************************************************/

using std::cout;
using std::endl;
using std::ifstream;
using std::max;
using std::min;
using std::string;
using std::getline;

class LcsSeekerPartTwo
{
    private:
    const string FILE_NAME = "multiStrings.txt";
    ifstream reader;
    string* list;
    int numStrings;
    char** simTable; //Similarity table.
    char compareStrings(string xString, string yString);

    public:
    LcsSeekerPartTwo();
    void Run();
    void printSimTable();
    ~LcsSeekerPartTwo();

};

#endif
