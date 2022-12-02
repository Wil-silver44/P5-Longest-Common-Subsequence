#ifndef LCSSIMULATION_HPP
#define LCSSIMULATION_HPP
#include <string>
#include "LcsSeekerPartOne.hpp"
#include "LcsSeekerPartTwo.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: LcsSimulation.hpp
 *   Assignment number: Project 5
 *
 *   Other comments regarding the file - defines attributes and methods for a program that runs the LcsSeeker parts 
 *   and displays their information.
 *
 ***************************************************************/

using std::string;

class LcsSimulation
{
    private:
    LcsSeekerPartOne lcsTestOne;
    LcsSeekerPartTwo lcsTestTwo;


    public:
    void RunPOne();
    void RunPTwo();

};

#endif
