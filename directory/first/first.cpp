int first()
{
  TFile *file = new TFile("file.root", "RECREATE");
  TDirectoryFile *myfile = new TDirectoryFile("myfile", "myfile");
  myfile->cd();
  TH1D *gauss = new TH1D("gauss", "gauss", 100, -5, 5);
  gauss->FillRandom("gaus", 10000);
  myfile->Write();

  file->cd();
  TDirectoryFile *myfile1 = new TDirectoryFile("myfile1", "myfile1");
  myfile1->cd();
  TH1D *gauss2 = new TH1D("gauss2", "gauss2", 100, -5, 5);
  gauss2->FillRandom("gaus", 100000);
  gauss2->Write();
  
  // file->Write();
  return 0;
}
