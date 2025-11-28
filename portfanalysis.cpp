#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Asset{
    std::string name;
    std::vector <float> returns;
    Asset(string n, vector<float> r){
        name=n;
        returns=r;
    }
}
