int npeaks = 30;
double fpeaks(double *x, double *par)
{
  double result = par[0] + par[1]*x[0];
  for (int p = 0; p != npeaks; ++p)
    {
      double norm = par[3*p+2];
      double mean = par[3*p+3];
      double sigma = par[3*p+4];
      result += norm*TMath::Gaus(x[0], mean, sigma);
    }
  return result;
}


int peaks(int np=10)
{
  npeaks = TMath::Abs(np);
  TH1D *h = new TH1D("h", "test", 500, 0, 1000);
  /// generate n peaks at random
  double par[3000];
  par[0] = 0.8;
  par[1] = -0.6/1000;
  for (int p = 0; p<npeaks; ++p)
    {
      par[3*p+2] = 1;
      par[3*p+3] = 10+gRandom->Rndm()*980;
      par[3*p+4] = 3+2*gRandom->Rndm();
    }
  TF1 *f = new TF1("f", fpeaks, 0, 1000, 2+3*npeaks);
  f->SetNpx(1000);
  f->SetParameters(par);
  TCanvas *c1 = new TCanvas("c1", "c1", 10, 10, 1000, 900);
  c1->Divide(1, 2);
  c1->cd(1);
  h->FillRandom("f", 20000);
  h->Draw();
  TH1D *h2 = (TH1D*)h->Clone("h2");

  /// Use TSpectrum to find the peak candidates
  /// the argument is maximum of peaks.
  TSpectrum *s = new TSpectrum(2*npeaks);
  int nfound = s->Search(h, 2, "", 0.10);
  cout << "Found" << nfound << "candidate peaks to fit." << endl;

  /// estimate background using TSpectrum::Background
  // TH1D *hb = s->Backgound(h, 20, "same");
  // if (hb)
  //   {
  //     c1->Update();
  //   }
  // if (np < 0)
  //   {
  //     return 0;
  //   }
 int numpeak = s->GetNPeaks();
 cout << numpeak << endl;

 s->Print();
 
 // double xposition[numpeak], yposition[numpeak];
 // for (int i = 0; i != numpeak; ++i)
 //   {
 //     cout << "(" << *(s->GetPositionX()+i) << ", " << *(s->GetPositionY()+i) << ")" << endl;
 //   }
 

  /// e
  return 0;
}
