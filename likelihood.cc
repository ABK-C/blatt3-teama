#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) 
{
  using namespace std;
  double P = pow(mu, k) * exp(-mu) / tgamma(k + 1);
  return P;
}

double prob(std::vector<int> daten, double mu) 
{
  using namespace std;
  long double P = 1;
  for(int k : daten) 
  { 
    P *= poisson(mu , k);
  }
   return P;
}

int main() 
{
    using namespace std;
    ifstream fin("datensumme.txt");

    vector<int> daten(0);


    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i);
    }
    fin.close();
    cout <<  prob(daten , 3.11538 )<< endl;
}