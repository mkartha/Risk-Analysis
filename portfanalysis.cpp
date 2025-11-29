#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <string>

using namespace std;

struct Asset{
    std::string name;
    std::vector <double> returns;
    double weight;
    public Asset (std::string& n, vector<double>& r, double& w:name(n), returns(r), weight(w) {}
};

class Portfolio{
    std::vector<Asset> positions;
    std::vector<double> portfolioReturns;

    public:
        Portfolio(vector<Asset> position){
            positions=position;
            bool sameA=true;
            size=positions.at(0).returns.size();
            for(int i=0; i<positions.size(); i++){
                if(positions.at(i).returns.size()!=size){
                    sameA=false;
                }
            }
            f5
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
