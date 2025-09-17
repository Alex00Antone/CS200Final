#include "Regression.h"
#include "DataCleaner.h"
#include <iomanip>
using namespace std;

// creates Regression object with a pointer pDataframe member to datacleaning object file member.
Regression::Regression(vector <vector <string>> &dataFrame){
    _dataFrame = dataFrame;
}

//creates regression model utilizing least squares method
void Regression::generateEquation(){
    double b_0;
    double b_1;
    double sumX = 0 , sumY = 0, sumXY = 0, sumXSq = 0; 
    double x;
    double y;
    
    for (unsigned int i = 0; i<_dataFrame.size(); i++){
        
        x = stod(_dataFrame.at(i).at(_predictor));

        y = stod(_dataFrame.at(i).at(_explanatory));
        sumX+= x;
        sumY+= y;
        sumXY += x*y;
        sumXSq += x*x;

    }
    
    b_1 = (_dataFrame.size()*sumXY-(sumX*sumY))/(_dataFrame.size()*sumXSq-(sumX*sumX));
    b_0 = (sumY-(b_1*sumX))/(_dataFrame.size());


    _equation.push_back(to_string(b_0));
    _equation.push_back(to_string(b_1));

}

//returns equation
vector<string> const Regression::getEquation(){
    return _equation;
}
    
//generates a summary of the model, with Sum of squares model vs sum of squares total, t-test statistics, p-statistics, etc.
void Regression::createSummary(){
    double sumSqMod  = 0;
    double y;
    double yMean = 0;
    double sumSqTotal = 0;
    double y_i;
    double b_0 = stod(_equation.at(0));
    double b_1 = stod(_equation.at(1));

    for (unsigned int i = 0; i<_dataFrame.size(); i++){
        
        y= stod(_dataFrame.at(i).at(_explanatory));
        yMean += y;
        
        
    }
    

    yMean /=_dataFrame.size();
    for (unsigned int i = 0; i<_dataFrame.size(); i++){
        y_i =b_1*stod(_dataFrame.at(i).at(_predictor))+b_0;
        y= stod(_dataFrame.at(i).at(_explanatory));
        sumSqTotal+= (y-yMean)*(y-yMean);
        sumSqMod += (y_i-yMean)*(y_i-yMean);
    } 
   

    double rSq = sumSqMod/sumSqTotal;
    
    double dfError = (_dataFrame.size()-2);
    double dfMod = 1;
    double meanSqError = (sumSqTotal-sumSqMod)/dfError;
    
    double meanSqModel = (sumSqMod)/dfMod;
    double fStat = meanSqModel/meanSqError;
    double tStat = sqrt(fStat);


    //normal distribution approximation of a t-distribution, for small samples use a t-distribution CDF
    double pValue = 2 * (1 - ( 0.5 * (1 + erf(tStat / sqrt(2.0)))));

    //location 0
    _summary.push_back(to_string(sumSqMod));
    //location 1
    _summary.push_back(to_string(sumSqTotal));
    //location 2
    _summary.push_back(to_string(rSq));
    //location 3
    _summary.push_back(to_string(meanSqError));
    //location 4
    _summary.push_back(to_string(tStat));
    //location 5
    _summary.push_back(to_string(pValue));





    cout<<"Sum of Squares model: "<<sumSqMod<<endl;
    cout<<"Sum of Squares Total: "<<sumSqTotal<<endl;
    cout<<"R squared: "<<rSq<<endl;
    cout<<"mean Squared Error: "<<meanSqError<<endl;
    cout<<"t Statistic: "<<tStat<<endl;
    cout<<"p value: "<<pValue<<endl;




}


//sets predictor and explanatory variables
void Regression::setPredictorExplanatoryvars(int predictor1, int explanatory1){
    _predictor = predictor1;
    _explanatory = explanatory1;
}