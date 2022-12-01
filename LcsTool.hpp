#ifndef LCSTOOL_HPP
#define LCSTOOL_HPP
#include <iostream>
#include <string>
#include <bits/stdc++.h>

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: LcsTool.hpp
 *   Assignment number: Project 5
 *
 *   Other comments regarding the file - defines attributes and methods for a program that will read two strings from a file
 *   compute the longest common subsequence, and then reconstruct the subsequence using the "c" array.
 *
 ***************************************************************/
using std::cout;
using std::endl;
using std::max;
using std::string;

class LcsTool
{
    private:
    string firstString;
    string secondString;
    int m;  // length of first string
    int n; // length of second string
    int** lcsTable; //integer matrix for lcs algorithm
    char lcs;   //character array for storing the longest common subsequence.

    public:
    LcsTool(string xString, string yString);
    void Lcs();
    void printLcs();
    int GetLcs();
    string GetStringOne();
    string GetStringTwo();
    ~LcsTool();
};

#endif