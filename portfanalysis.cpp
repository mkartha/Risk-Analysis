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
    public Asset (std::string& n, vector<double>& r, double& w:name(n), returns(r), weight(w) {}
};

class Portfolio{
    std::vector<Asset> positions;
    std::vector<double> portfolioReturns;

    public:
        Portfolio(vector<Asset> position){
            positions=position;
            if(!allSameSize(position&)
                trimToMin(position&);

            int time=positions[0].returns.size();
            for(int t=0; t<time; t++){
                total=0;
                for(Asset d:positions)
                    total+=d.weight*d.returns[t];
                portfolioReturns.push_back(total)
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
