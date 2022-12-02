#include "LcsSeekerPartOne.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: LcsSeekerPartOne.cpp
 *   Assignment number: Project 5
 *
 *   Other comments regarding the file - implements attributes and methods for a program that will read two strings from a file
 *   compute the longest common subsequence, and then reconstruct the subsequence using the "c" array.
 *
 ***************************************************************/


LcsSeekerPartOne::LcsSeekerPartOne()
{
    this->reader.open(FILE_NAME);
    if(reader.is_open())
    {
        getline(this->reader, this->firstString);
        getline(this->reader, this->secondString);
        this->reader.close();
    }
    else
    {
        throw "error opening file";
    }

    this->testTool = new LcsTool(this->firstString, this->secondString);
    
}

void LcsSeekerPartOne::Run()
{
	cout << "---------- PART 1 START ----------" << endl;
    this->testTool->Lcs();
    this->testTool->printLcs();
     cout << "---------- PART 1 COMPLETE ----------" << endl;
}

LcsSeekerPartOne::~LcsSeekerPartOne()
{
    delete this->testTool;
}
