#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{
    const string inputFile = "data.csv";
    const string outputFile = "result.txt";
    double S;
    int n;
    double* w;
    double* r;

    readData(inputFile, S, n, w, r);

    double portfolioReturn = calculatePortfolioReturn(n, w, r);

    double V = calculateFinalValue(S, portfolioReturn);

    returnDataResults(outputFile, S, n, w, r, portfolioReturn, V);

    cout << "S = " << fixed << setprecision(2) << S << defaultfloat << ", n = " << n << endl;

    cout << "w = [";


    for (int i = 0; i < n; ++i)
    {
        cout << " " << w[i];
    }

    cout << " ]" << endl;

    cout << "r = [";

    for (int i = 0; i < n; ++i)
    {
        cout << " " << r[i];
    }

    cout << " ]" << endl;

    cout << "Rate of return of the portfolio: " << setprecision(4) << portfolioReturn << endl;

    cout << "V: " <<fixed << setprecision(2) << V << defaultfloat << endl;

    delete[] w;
    delete[] r;

    return 0;
}
