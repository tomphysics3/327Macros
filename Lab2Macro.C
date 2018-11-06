//Macro for Lab2 Report

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <TH1F.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TTree.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TFile.h>
#include <TStyle.h>
#include <TStopwatch.h>
#include <TRandom3.h>
#include <TChain.h>
#include <TProfile.h>
#include <TStopwatch.h>
#include <TCut.h>
#include <cstdlib>
#include <cmath>
#include "TLegend.h"
#include "TLatex.h"
#include "TMath.h"
#include "TLine.h"
#include "TFormula.h"


{
  //New Canvases
  TCanvas * c1 = new TCanvas("c1", "Plots", 3600, 3600);
  c1->Divide(3,1);

  //List the data points for first part (measuring phase)
  int n = 8;
  double f[]  = {100,300,1000,3000,10000,30000,100000,1000000}; //Hz
  double lf[] = {log(100),log(300),log(1000),log(3000),log(10000),log(30000),log(100000),log(1000000)};
  double lfer[] = {0,0,0,0,0,0,0,0};
  double Vin[]  = {50,50,50,50,50,50,50,50}; //Volts
  double Vout[]  = {1.28,3.65,11.5,16.6,35.6,44.4,45.1,47.5}; //Volts
  //double VoutVin[] = {(Vout[0]/Vin[0]), (Vout[1]/Vin[1], (Vout[2]/Vin[2])), (Vout[3]/Vin[3]), (Vout[4]/Vin[4]), (Vout[5]/Vin[5]), (Vout[6]/Vin[6])};
  double phi[] = {1.57,1.52,1.40,1.32,0.627,0.189,0.125,0.094};
  double phier[] = {0.13,0.21,0.13,0.23,0.327,0.099,0.065,0.037};
  double logVoutVin[] = {log(1.28/50),log(3.65/50),log(11.5/50),log(16.6/50),log(35.6/50),log(44.4/50),log(45.1/50),log(47.5/50)};

  //List the data points for square/triangle waves
  int m = 8;
  int j = 12;
  double Voutsq[]  = {80.4,60.0,40.0,20.0,10.0,3.5,1.0,0.1}; //Volts
  double tsq[]  = {0,5.0,15.0,27.0,40.0,50.0,75.0,100.0}; //microseconds
  double Vouttri[]  = {21.2,18.4,15.2,12.4,10.4,9.6,7.2,5.2,4.8,2.0,2.8,1.2}; //Volts
  double Vintri[]  = {102,100,98,96,94,92,90,86,78,74,70,62}; //Volts
  double ttri[] = {0,4,8,12,16,20,24,32,40,48,56,64}; //microseconds

  //Make the graphs+Set Plot Properties
  //c1->cd(1);
  TGraph *gr1 = new TGraph(n,lf,logVoutVin);

  gr1->SetTitle("Plot of log(Vout/Vin) vs. log(f);log(f);log(Vout/Vin)");
  gr1->SetMarkerColor(4);
  gr1->SetMarkerStyle(21);
  auto axisx = gr1->GetXaxis();
  axisx->SetLimits(4.,15.);
  auto axisy = gr1->GetYaxis();
  axisy->SetLimits(-5.,1.);
  //gr1->Draw("AP");
  TF1 *fa1 = new TF1("fa1","log((19810)/sqrt(392436100+(1/(0.0000000000000000394784176*exp(2*x)))))",4,15);
  // fa1->Draw("same");

  //c1->cd(2);
  TGraph *gr2 = new TGraphErrors(n,lf,phi,lfer,phier);

  gr2->SetTitle("Plot of phase difference vs. log(f);log(f);Phase Difference(#phi)");
  gr2->SetMarkerColor(4);
  gr2->SetMarkerStyle(21);
  auto axis1x = gr2->GetXaxis();
  axis1x->SetLimits(3.,15.);
  auto axis1y = gr2->GetYaxis();
  axis1y->SetLimits(-1.,13.);
  // gr2->Draw("AP");
  TF1 *fa2 = new TF1("fa2","atan(1/(0.0001244699*exp(x)))",1,15);
  //TF1 *fa2 = new TF1("fa2","atan(x)",-1,1);
  //fa2->Draw("same");

  //c1->cd(3);
  TGraph *gr3 = new TGraph(m,tsq,Voutsq);

  gr3->SetTitle("Exponential Decay of V(t);time (#mus);Vout (Volts)");
  gr3->SetMarkerColor(4);
  gr3->SetMarkerStyle(21);
  auto axis2x = gr3->GetXaxis();
  axis2x->SetLimits(0.,100.);
  auto axis2y = gr3->GetYaxis();
  axis2y->SetLimits(0.,100.);
  gr3->Draw("AP");
  TF1 *fa3 = new TF1("fa3","80*(exp(-x/19.81))",0,100);
  fa3->Draw("same");

  // c1->cd(2);
  /* TGraph *gr4 = new TGraph(j,ttri,Vouttri);

  gr4->SetTitle("Exponential Decay 2;time(${mu}$s);Vout (Volts)");
  gr4->SetMarkerColor(4);
  gr4->SetMarkerStyle(21);
  auto axis3x = gr4->GetXaxis();
  axis3x->SetLimits(-5.,80.);
  auto axis3y = gr4->GetYaxis();
  axis3y->SetLimits(-5.,30.);
  gr4->Draw("AP");
  gr5->SetTitle("Exponential Decay 2;time(${mu}$s);Vout (Volts)");
  gr5->SetMarkerColor(6);
  gr5->SetMarkerStyle(20);
  gr5->Draw("same");*/
  // TF1 *fa4 = new TF1("fa4","100*(exp(-.05048*x))",0,80);
  // fa4->Draw();

  

} //End Macro
