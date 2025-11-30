/*This is a file for basic Portfolio Analysis in C++
Includes classes for Storing Asset and Portfolio Data
Includes RiskEngine for calculating important risk metrics(i.e., historical VaR, Sharpe's ratio, volatility)
Completed on November 29, 2025
© MK 2025
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <string>
#include <climits>

using namespace std;

struct Asset{
    std::string name;
    std::vector <double> returns;
    double weight;
    
    Asset (std::string& n, vector<double>& r, double w):name(n), returns(r), weight(w) {}
};

class Portfolio{
    std::vector<Asset> positions;
    std::vector<double> portfolioReturns;

    public:
        Portfolio(vector<Asset> position){
            positions=position;
            if(!allSameSize(positions))
                trimToMin(positions);

            int time=positions[0].returns.size();
            for(int t=0; t<time; t++){
                double total=0.0;
                for(Asset d:positions)
                    total+=d.weight*d.returns[t];
                portfolioReturns.push_back(total);
            }
        }

        bool allSameSize(vector<Asset>& p){
            bool sameA=true
            int size=p.at(i).returns.size()
            for(int i=0; i<p.size(); i++){
                if(p.at(i).returns.size()!=size)
                    return false;
            }
            return true;
        }

        int findMinLength(vector<Asset>& p){
            int ml=INT_MAX
            for(int i=0; i<p.size(); i++){
                if(p.at(i).returns.size()<ml)
                    ml=p.at(i).returns.size();
            }
            return ml;
        }

        public void trimToMin(vector <Asset>& p){
            int min=findMinLength(p);
            for(int i=0; i<p.size(); i++){
                if(p.at(i).returns.size()>min)
                    p.at(i).returns.resize(min);
            }
        }

         void addPosition(string name, double weight){
                std::vector<double> temp;
                positions.push_back(Asset(name, temp, weight));
                portfolioReturns.push_back(0.0);
            }

    
          void setReturnsForAsset(string ticker, vector<double> assetReturns){
                for(int i=0; i<positions.size(); i++){
                    if(positions.at(i).name==ticker){
                        positions.at(i).returns.insert(positions.at(i).returns.end(), assetReturns.begin(), assetReturns.end());
                        break;
                     }
                 }
            }
         vector<double> getPortfolioReturns(){
                return portfolioReturns;
        }
};

class RiskEngine{
    
    std::vector<double>pfReturns;
    
    public:
        RiskEngine(vector<double>& pf){
            pfReturns=pf;
        }

        double meanReturn(){
            double total=0;
            for(double d:pfReturns)
                total+=d;
            return total/pfReturns.size();
        }

        double volatility(){
            double m=this->meanReturn();
            double sum=0;
            for(double d:pfReturns)
                sum+=(d-m)*(d-m);
            double var=sum/(pfReturns.size()-1);
            return sqrt(var);
        }

        double calcSharpeRatio(double riskFreeRate){
            return (this.meanReturn()-riskFreeRate/this.volatility());
        }

        double maxDrawdown(){
            double val=1.0;
            double tempMax=1.0;
            double mdd=0.0;
            for(double r:pfReturns){
                thisVal=val*(1+r)
                tempMax=max(thisVal,tempMax);
                dd=(thisVal-tempMax)/tempMax;
                mdd=min(dd,mdd);
                val=thisVal;
            }
            return mdd;
        }    

        double hVaR(double cfLevel){
            vector<double> temp=pfReturns;
            std::sort(temp.begin(), temp.end(), std::greater<double>());
            indLevel=1.0-cfLevel;
            return 1.0-(temp.at(std::floor(temp.size()*indLevel)));
        }


};
