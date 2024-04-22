#include "Utils.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void readData(const string& inputFile, double& S, int& n, double*& w, double*& r)
{
    // Open File
    ifstream file;
    file.open(inputFile);

    if (file.fail())
    {
        cerr << "File open failed." << endl;
        exit(1);
    }

    // Read data from input file
    string line;

    // Read the initial investment S
    getline(file, line, ';');
    file >> S;

    // Read the number of assets n
    getline(file, line, ';');
    file >> n;

    // Read weights and returns from the file
    getline(file, line); // Skip "w;r" line
    file >> line;

    w = new double[n];
    r = new double[n];

    for (int i = 0; i < n; ++i)
    {
        getline(file, line, ';');
        istringstream convertW(line);
        convertW >> w[i];

        getline(file,line);
        istringstream convertR(line);
        convertR >> r[i];
    }

    // Close File
    file.close();
}

double calculatePortfolioReturn(int n, double* w, double* r)
{
    double portfolioReturn = 0.0;

    for (int i = 0; i < n; ++i)
    {
        portfolioReturn += w[i] * r[i];
    }

    return portfolioReturn;
}

double calculateFinalValue(double S, double portfolioReturn)
{
    return S * (1 + portfolioReturn);
}

void returnDataResults(const string& outputFile, double S, int n, double* w, double* r, double portfolioReturn, double V)
{
    ofstream file(outputFile);

    if (!file)
    {
       cerr << "Unable to create output file." << endl;
       exit(1);
    }

    file << "S = " << fixed << setprecision(2) << S << defaultfloat << ", n = " << n << endl;

    file << "w = [";

    for (int i = 0; i < n; ++i)
    {
        file << " " << w[i];
    }

    file << " ]" << endl;

    file << "r = [";

    for (int i = 0; i < n; ++i)
    {
        file << " " << r[i];
    }

    file << " ]" << endl;

    file << "Rate of return of the portfolio: " << setprecision(4) << portfolioReturn << endl;

    file << "V: " << fixed << setprecision(2) << V << defaultfloat << endl;

    file.close();
}
