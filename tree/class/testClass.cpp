/**
 * @file   class.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Sat Jun  3 11:25:30 2017
 * 
 * @brief  class for root branch.
 */

int testClass()
{
  class testBranch
{
public:
  // testBranch() = default;
  testBranch(){}
  double X;
  double Y;
  double Z;
};

  TFile *file = new TFile("file.root", "RECREATE");
  TTree *tree = new TTree("test", "a test branch");
  testBranch *mybranch = new testBranch();
  mybranch->X = 2;
  mybranch->Y = 3;
  mybranch->Z = 4;
  tree->Branch("haha", "testBranch", &mybranch);
  tree->Fill();
  tree->Write();
  return 0;
}
