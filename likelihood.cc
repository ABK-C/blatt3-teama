#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

long double poisson(double mu, int k) 
{
  using namespace std;
  long double P = pow(mu, k) * exp(-mu) / tgamma(k + 1);
  return P;
}

long double prob(std::vector<int> daten, double mu) 
{
  using namespace std;
  long double P = 1;
  for (int k : daten) 
  {
    P *= poisson(mu, k);
  }
  return P;
}

long double prob2(std::vector<int> daten) 
{
  using namespace std;
  long double P = 1;
  for (int k : daten) 
  {
    P *= poisson(k, k);
  }
  return P;
}

int main() 
{
  using namespace std;
  ifstream fin("datensumme.txt");
  ofstream like("likelihood.txt");
  ofstream nll("nll.txt");
  ofstream deltanll("deltanll.txt");

  vector<int> daten(0);
  int n_i;

  for (int i = 0; i < 234; ++i) 
  {
    fin >> n_i;
    daten.push_back(n_i);
  }

  cout << "L(3.11538) = " << prob(daten, 3.11538) << endl;

  for (double i = 0; i <= 6; i += 0.1) 
  {
    like << i << " " << prob(daten, i) << endl;
    nll << i << " " << -2 * log(prob(daten, i)) << endl;
    deltanll << i << " " << -2 * log(prob(daten, i)) + 2 * log(prob(daten, 3.11538)) << endl;
  }

  long double delta = prob(daten, 3.11538) / prob2(daten);

  cout << "-2*ln(\u039B) = " << -2 * log(delta) << endl;
  cout << "z = " << (-2 * log(delta) - 233) / sqrt(2 * 233) << endl;


  fin.close();
  like.close();
  nll.close();
  deltanll.close();
}