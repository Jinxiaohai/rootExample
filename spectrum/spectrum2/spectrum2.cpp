int npeaks = 6;
double fitfunction(double *x, double *par)
{
  double result = 0.;
  for (int p = 0; p != npeaks; ++p)
    {
      double norm = par[5*p];
      double mean1 = par[5*p+1];
      double sigma1 = par[5*p+2];
      double mean2 = par[5*p+3];
      double sigma2 = par[5*p+4];
      result += norm*TMath::Gaus(x[0], mean1, sigma1)*TMath::Gaus(x[1], mean2, sigma2);
    }
  return result;
}


int spectrum2()
{
  double par[1000];
  for (int p = 0; p != npeaks; ++p)
    {
      par[5*p] = gRandom->Uniform(0.4, 1);
      par[5*p+1] = gRandom->Uniform(0, 200);
      par[5*p+2] = gRandom->Uniform(1, 5);
      par[5*p+3] = gRandom->Uniform(0, 200);
      par[5*p+4] = gRandom->Uniform(1, 5);
    }
  TF2 *f2 = new TF2("f2", fitfunction, 0, 200, 0, 200, 5*npeaks);
  f2->SetParameters(par);
  TH2D *testhis = new TH2D("testhis", "testhis", 200, 0, 200, 200, 0, 200);
  testhis->FillRandom("f2", 200000);

  TSpectrum2 *s2 = new TSpectrum2(6);
  s2->Search(testhis, 2, "same", 0.1);
  s2->Print();
  testhis->SetTitle("");
  return 0;
}
