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
 *   Other comments regarding the file - defines attributes and methods 
 *
 ***************************************************************/

using std::ifstream;
using std::max;
using std::string;

class LcsSeekerPartOne
{
    private:
    ifstream reader;
    string firstString;
    string secondString;
    char lcs;

    public:
    LcsSeekerPartOne();
    int Lcs(string xString, string yString, int m, int n);
    void RevLCSMat(int c, string X, string Y, int i, int j);
    void printLcs();

};

#endif