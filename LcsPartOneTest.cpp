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

    cout << "lcs of strings" << endl;

    cout << testSeeker.GetStringOne() << "\nand\n" << testSeeker.GetStringTwo() << "\nis " << testSeeker.GetLcs() << " characters long." << endl;
    


    cout << "OPERATIONS COMPLETE, DEALLOCATING..." << endl;
}