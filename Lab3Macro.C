//Macro for Lab 3 Report

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
  // c1->Divide(2,1);

  //List the data points for first resistor (R=1 kOhm)
  int n = 28;
  double f1[]  = {100,1000,10000,15800,15850,15915.49432,16000,16100,16200,16300,16400,16500,16600,16700,16800,16900,17000,17200,17400,17600,18000,18200,18600,19600,20000,21000,100000,1000000}; //Hz
  double Vout1[]  = {4.6,4.6,4.55,4.04,4.02,4.0,4.0,3.96,3.94,3.92,3.92,3.90,3.90,3.88,3.88,3.84,3.76,3.76,3.74,3.70,3.76,3.78,3.80,3.85,3.88,3.90,4.9,4.9}; //Volts

  //List the data points for second resistor (R=100 Ohm)
  int m = 19;
  double f2[]  = {100,1000,10000,15000,15800,15850,15915.49432,16000,16500,17000,17200,17500,17700,18000,18500,18700,19000,100000,1000000}; //Hz
  double Vout2[]  = {2.96,2.98,2.60,1.35,1.12,1.10,1.08,1.07,0.98,0.92,0.86,0.90,0.92,0.94,1.02,1.07,1.12,2.98,2.98}; //Volts

   //List the data points for series circuit (R=100 Ohm)
  int j = 15;
  double f3[]  = {100,1000,10000,15000,15800,15900,15915.49432,16000,16100,16500,17000,17500,18000,100000,1000000}; //Hz
  double Vout3[]  = {0.043,0.332,2.6,2.96,2.98,2.98,3,3.02,3.0,3.0,2.96,2.95,2.94,0.98,0.070}; //Volts

  //Make the graphs+Set Plot Properties
  //c1->cd(1);
  TGraph *gr1 = new TGraph(n,f1,Vout1);

  gr1->SetTitle("Plot of frequency vs. Vout for R=1 k#Omega;frequency(Hz);Vout(V)");
  gr1->SetMarkerColor(4);
  gr1->SetMarkerStyle(21);
  auto axisx = gr1->GetXaxis();
  axisx->SetLimits(0.,1000000.);
  auto axisy = gr1->GetYaxis();
  axisy->SetLimits(2.,6.);
  //gr1->Draw("AP");
  TF1 *fa1 = new TF1("fa1","5*977/(sqrt(pow((6.283185*0.001*x/((39.4784176*0.001*0.0000001*x*x)-1)),2)+954529))",0,1000000);
  //fa1->Draw("same");

  //c1->cd(2);
  //TGraph *gr2 = new TGraphErrors(n,lf,phi,lfer,phier);
  TGraph *gr2 = new TGraph(m,f2,Vout2);

  gr2->SetTitle("Plot of frequency vs. Vout for R=100 #Omega;frequency(Hz);Vout(V)");
  gr2->SetMarkerColor(4);
  gr2->SetMarkerStyle(21);
  auto axis1x = gr2->GetXaxis();
  axis1x->SetLimits(0.,1000000.);
  auto axis1y = gr2->GetYaxis();
  axis1y->SetLimits(0.,5.);
  // gr2->Draw("AP");
  TF1 *fa2 = new TF1("fa2","5*98.5/(sqrt(pow((6.283185*0.001*x/((39.4784176*0.001*0.0000001*x*x)-1)),2)+(98.5*98.5)))",0,1000000);
  // fa2->Draw("same");

  //c1->cd(3);
  TGraph *gr3 = new TGraph(j,f3,Vout3);

  gr3->SetTitle("Plot of frequency vs. Vout for the series circuit;frequency(Hz);Vout(V)");
  gr3->SetMarkerColor(4);
  gr3->SetMarkerStyle(21);
  auto axis2x = gr3->GetXaxis();
  axis2x->SetLimits(0.,1000000.);
  auto axis2y = gr3->GetYaxis();
  axis2y->SetLimits(0.,5.);
  gr3->Draw("AP");
  TF1 *fa3 = new TF1("fa3","5*98.5/sqrt(pow(((39.4784176*0.001*0.0000001*x*x)-1)/(6.283185*0.0000001*x),2)+(98.5*98.5))",-1,1000000);
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
