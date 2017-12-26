/********************************************************/
/*                 Created  by  xiaohai                 */
/*                 Telphone : 18501781924               */
/*            E-mail : jinxiaohai@sinap.ac.cn           */
/*            E-mail : xiaohaijin@outlook.com           */
/*   Address : Shanghai Institute of Applied Physics    */
/********************************************************/
//root
#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ class PlotFile;
#pragma link C++ class Exception;
#pragma link C++ class Track<double>+;
#pragma link C++ class Event<double>+;

#endif
#ifndef __CINT__
#include "TH3D.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TTree.h"
#include "TNtuple.h"
#include "TRandom.h"
#include "TMath.h"
#include "TSystem.h"
#include "TUnixSystem.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TROOT.h"
#include "TFile.h"
#include "TChain.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TGaxis.h"
#include "TPaveStats.h"
#include "TObject.h"
#include "TClonesArray.h"
#include "TRefArray.h"
#include "TRef.h"
#include "TBits.h"
#endif

//c++
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <fstream>
#include <sstream>
#include "Particle.h"

using namespace std;
using namespace xiaohai;

int main(int argc, char *argv[])
{
  Event<double> *evt = new Event<double>;
  ifstream input("/home/xiaohai/Github/ampt/comment/ana/ampt.dat");
  input >> *evt;
  try{
    cout << evt->GetTrack(-1) << endl;
  }
  catch(Exception e){
    cout << e.What() << endl;
  }
  return 0;
}
