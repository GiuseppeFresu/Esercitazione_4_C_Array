#pragma once

#include <iostream>

using namespace std;

void readData(const string& inputFile, double& S, int& n, double*& w, double*& r);

double calculatePortfolioReturn(int n, double* w, double* r);

double calculateFinalValue(double S, double portfolioReturn);

void returnDataResults(const string& outputFile, double S, int n, double* w, double* r, double portfolioReturn, double V);
