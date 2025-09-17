#ifndef REGRESSION_H

#define REGRESSION_H 

#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Regression
{

public:
    // creates Regression object with a pointer pDataframe member to datacleaning object file member.
    Regression(vector <vector <string>> &dataFrame);

    
    //creates regression model utilizing least squares method
    void generateEquation();

    //returns equation
    vector<string> const getEquation();
    
    //generates a summary of the model, with Sum of squares model vs sum of squares total, t-test statistics, p-statistics, etc.
    void createSummary(); 

    //sets predictor and explanatory variables
    void setPredictorExplanatoryvars(int predictor, int explanatory);
    
    


private:
vector<string> _equation;
    double _mean;
    vector <vector <string>> _dataFrame;
    vector <string> _summary;
    
    int _predictor;
    int _explanatory;
    
};


#endif