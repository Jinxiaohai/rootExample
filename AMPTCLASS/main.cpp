#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <random>
#include "Particle.h"

using namespace std;
using namespace xiaohai;

int main(int argc, char *argv[])
{
  
  Event<double> *evt = new Event<double>;
  ifstream input("/home/xiaohai/Github/ampt/comment/ana/ampt.dat");
  input >> *evt;
  cout << *evt;
  return 0;
}
