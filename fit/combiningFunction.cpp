/**
 * @file   combiningFunction.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Thu May 11 15:17:03 2017
 * 
 * @brief  Example for fitting signal/background.
 * 
 */

#include "TH1D.h"
#include "TMath.h"
#include "TF1.h"
#include "TLegend.h"
#include "TCanvas.h"

/// quadratic background function
/** 
 * background
 * 
 * @param x 
 * @param par 
 * 
 * @return 
 */
double background(double *x, double *par)
{
  return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
}

/** 
 * lorentzian peak function
 * 
 * @param x 
 * @param par 
 * 
 * @return 
 */
double lorentzianPeak(double *x, double *par)
{
    return (0.5*par[0]*par[1]/TMath::Pi()) /
    TMath::Max( 1.e-10,(x[0]-par[2])*(x[0]-par[2])
   + .25*par[1]*par[1]);
}

/** 
 * fit function
 * 
 * @param x 
 * @param par 
 * 
 * @return 
 */
double fitFunction(double *x, double *par)
{
  return background(x, par) + lorentzianPeak(x, &par[3]);
}

int combiningFunction()
{
 //Bevington Exercise by Peter Malzacher, modified by Rene Brun
   const int nBins = 60;
   Double_t data[nBins] = { 6, 1,10,12, 6,13,23,22,15,21,
                           23,26,36,25,27,35,40,44,66,81,
                           75,57,48,45,46,41,35,36,53,32,
                           40,37,38,31,36,44,42,37,32,32,
                           43,44,35,33,33,39,29,41,32,44,
                           26,39,29,35,32,21,21,15,25,15};
   TCanvas *c1 = new TCanvas("c1","Fitting Demo",10,10,700,500);
   c1->SetFillColor(33);
   c1->SetFrameFillColor(41);
   c1->SetGrid();

   TH1F *histo = new TH1F("histo", "Lorentzian Peak on Quadratic Background", 60, 0, 3);
   histo->SetMarkerStyle(21);
   histo->SetMarkerSize(0.8);
   histo->SetStats(0);

   for(int i=0; i < nBins;  i++)
     {
       histo->SetBinContent(i+1, data[i]);
     }

   // create a TF1 with the range from 0 to 3 and 6 parameters
   TF1 *fitFcn = new TF1("fitFcn", fitFunction, 0, 3, 6);
   fitFcn->SetNpx(500);
   fitFcn->SetLineWidth(4);
   fitFcn->SetLineColor(kMagenta);

   // first try without starting values for the parameters
   // This defaults to 1 for each param.
   // this results in an ok fit for the polynomial function
   // however the non-linear part (lorenzian) does not
   // respond well.
   fitFcn->SetParameters(1,1,1,1,1,1);
   histo->Fit("fitFcn","0");

   fitFcn->SetParameter(4,0.2); // width
   fitFcn->SetParameter(5,1);   // peak

   histo->Fit("fitFcn","V+","ep");

      // improve the picture:
   TF1 *backFcn = new TF1("backFcn",background,0,3,3);
   backFcn->SetLineColor(kRed);
   TF1 *signalFcn = new TF1("signalFcn",lorentzianPeak,0,3,3);
   signalFcn->SetLineColor(kBlue);
   signalFcn->SetNpx(500);
   Double_t par[6];

   // writes the fit results into the par array
   fitFcn->GetParameters(par);

   backFcn->SetParameters(par);
   backFcn->Draw("same");

   signalFcn->SetParameters(&par[3]);
   signalFcn->Draw("same");

   // draw the legend
   TLegend *legend=new TLegend(0.6,0.65,0.88,0.85);
   legend->SetTextFont(72);
   legend->SetTextSize(0.04);
   legend->AddEntry(histo,"Data","lpe");
   legend->AddEntry(backFcn,"Background fit","l");
   legend->AddEntry(signalFcn,"Signal fit","l");
   legend->AddEntry(fitFcn,"Global Fit","l");
   legend->Draw();


   /// was added by xiaohai
   TF1 *xiaohaiFit = histo->GetFunction("fitFcn");
   double chi2 = xiaohaiFit->GetChisquare();
   double p0 = xiaohaiFit->GetParameter(0);
   double e0 = xiaohaiFit->GetParError(0);
   double p1 = xiaohaiFit->GetParameter(1);
   double e1 = xiaohaiFit->GetParError(1);
   double p2 = xiaohaiFit->GetParameter(2);
   double e2 = xiaohaiFit->GetParError(2);
   double p3 = xiaohaiFit->GetParameter(3);
   double e3 = xiaohaiFit->GetParError(3);
   double p4 = xiaohaiFit->GetParameter(4);
   double e4 = xiaohaiFit->GetParError(4);
   double p5 = xiaohaiFit->GetParameter(5);      
   double e5 = xiaohaiFit->GetParError(5);
   cout << "\033[31m" << "chi2 = " << chi2 << endl;
   cout << "parameters 0 is = " << p0 << "       " << "error is = " << e0 << endl;
   cout << "parameters 1 is = " << p1 << "       " << "error is = " << e1 << endl;
   cout << "parameters 2 is = " << p2 << "       " << "error is = " << e2 << endl;
   cout << "parameters 3 is = " << p3 << "       " << "error is = " << e3 << endl;
   cout << "parameters 4 is = " << p4 << "       " << "error is = " << e4 << endl;
   cout << "parameters 5 is = " << p5 << "       " << "error is = " << e5 << "\033[0m" << endl;   
   return 0;
}
