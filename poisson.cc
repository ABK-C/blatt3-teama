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

int main() 
{
   using namespace std;

   ifstream fin("datensumme.txt");
   ofstream fout("hist.txt");
   ofstream fout2("histpoi.txt");


   vector<int> zaehler(11);

    int n_i;
    
    for(int i = 0 ; i < 234 ; ++i) 
    {
      fin >> n_i;
      zaehler[n_i] += 1; 
    }


    for (int j = 0; j < zaehler.size(); ++j) 
    {
     fout << j << " : " << zaehler[j] << endl;
     fout2 << j << " : " << zaehler[j] << " : " << poisson(3.11538, j) * 234 << endl;
    }

    fin.close();
    fout.close();
    fout2.close(); 
}