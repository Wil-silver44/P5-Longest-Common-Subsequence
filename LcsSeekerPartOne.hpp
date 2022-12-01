#ifndef LCSSEEKERPARTONE_HPP
#define LCSSEEKERPARTONE_HPP
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
    int Lcs(string xString, string yString, int m, int n);
    void RevLCSMat(int c, string X, string Y, int i, int j);
    void printLcs();
    ~LcsSeekerPartOne();
};

#endif