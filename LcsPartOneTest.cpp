#include "LcsSeekerPartOne.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "creating LcsSeekerPartOne object." << endl;
    
    LcsSeekerPartOne testSeeker;

    cout << "object created." << endl;

    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int m = X.length();
    int n = Y.length();

    cout << "The longest common subsequence of " << X << " and " << Y << " is " << testSeeker.Lcs(X, Y, m, n) << " characters long." << endl << endl;

    cout << "OPERATIONS COMPLETE, DEALLOCATING..." << endl;
}