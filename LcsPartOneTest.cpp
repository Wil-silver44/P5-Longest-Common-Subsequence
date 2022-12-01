#include "LcsSeekerPartOne.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "creating LcsSeekerPartOne object." << endl;
    
    LcsSeekerPartOne testSeeker;

    cout << "object created." << endl;

    cout << "finding lcs..." << endl;

    testSeeker.Lcs();

    cout << "lcs found." << endl;

    cout << "printing lcs." << endl;

    testSeeker.printLcs();

    cout << "OPERATIONS COMPLETE, DEALLOCATING..." << endl;
}