#ifndef LCSSEEKERPARTONE_HPP
#define LCSSEEKERPARTONE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: LcsSeeker.hpp
 *   Assignment number: Project 4
 *
 *   Other comments regarding the file - defines attributes and methods for a program that will read two strings from a file
 *   compute the longest common subsequence, and then reconstruct the subsequence using the "c" array.
 *
 ***************************************************************/
using std::cout;
using std::endl;
using std::ifstream;
using std::max;
using std::string;
using std::getline;

class LcsSeekerPartOne
{
    private:
    const string FILE_NAME = "twoStrings.txt";
    ifstream reader;
    string firstString;
    string secondString;
    int m;  // length of first string
    int n; // length of second string
    int** lcsTable;
    char lcs;

    public:
    LcsSeekerPartOne();
    void Lcs();
    void printLcs();
    int GetLcs();
    string GetStringOne();
    string GetStringTwo();
    ~LcsSeekerPartOne();
};

#endif