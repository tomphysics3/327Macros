//Macro for Lab1 Report

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


{
  //New Canvases
  TCanvas * c1 = new TCanvas("c1", "Plot1", 3600, 3600);
  // TCanvas * c2 = new TCanvas("c2", "Plot2", 3600, 3600);
  // TCanvas * c3 = new TCanvas("c3", "Plot3", 3600, 3600);

  //List the data points for R1=100k and find the desired quantites
  int n = 7;
  double R2[]  = {1.000,10.00,100.0,990,9970,100300,1024000}; //Ohms
  double logR2[]  = {log (1),log (10),log (100),log (990),log (9970),log (100300),log (1024000)};
  //cout << logR2[1] << endl;
  double Vin[]  = {11.98,11.98,11.98,11.98,11.97,11.86,10.88}; //Volts
  double Vout[]  = {(0.0001),(0.0012),(0.0119),(0.1178),1.088,6.01,10.92}; //Volts
  double r[] = {(Vout[0]/R2[0]), (Vout[1]/R2[1], (Vout[2]/R2[2])), (Vout[3]/R2[3]), (Vout[4]/R2[4]), (Vout[5]/R2[5]), (Vout[6]/R2[6])};
   cout << r[6] << endl;

  //List the data points for R1=100 and find the desired quantites
  int m = 5;
  double r2[]  = {100.0,990,9970,100300,1024000}; //Ohms
  double logr2[]  = {log (100),log (990),log (9970),log (100300),log (1024000)};
  //cout << logR2[1] << endl;
  double Vin2[]  = {12.10,12.10,12.09,11.98,10.90}; //Volts
  double Vout2[]  = {(1.96),(10.94),11.97,12.09,12.10}; //Volts

  //List the data points for LED
  int j = 5;
  double Vled[]  = {2.591, 1.966, 1.831, 1.753, 1.660}; //Volts
  double I[]  = {21.10, 4.17, 0.45, 0.0482, 0.0051}; //milli-Amps

//Calculate the desired quantites
  /* double results[7];
  std::transform (Vout, Vout+7, R2, results, std::divides<double>());
  for (int i=0; i<7; i++){
    // double x[] = {results[i]};
    // cout << results[i] << endl;
    // double r[] = {results[1],results[2],results[3],results[4],results[5],results[6],results[7]};
    double r[] = {(Vout[1]/R2[2], (Vout[2]/R2[2])), (Vout[3]/R2[3]), (Vout[4]/R2[4]), (Vout[5]/R2[5]), (Vout[6]/R2[6]), (Vout[7]/R2[7])};
    cout << r[i] << endl;
    
    TGraph *gr1 = new TGraph(n, r, logR2);

    gr1->SetTitle("Plot");
    gr1->SetMarkerColor(4);
    gr1->SetMarkerStyle(21);
    //gr1->Draw("AP");
    
    } //end for loop*/

  //Make the graphs+Set Plot Properties
  //c1->cd(1);
  TGraph *gr1 = new TGraph(n,logR2,r);

  gr1->SetTitle("Vout/R2 vs. log(R2);log(R2);Vout/R2 (Volt/Ohms)");
  gr1->SetMarkerColor(4);
  gr1->SetMarkerStyle(21);
  // gr1->SetXTitle("log(R2)");
  // gr1->SetYTitle("Vout/R2 (Volt/Ohms)");
  auto axisx = gr1->GetXaxis();
  axisx->SetLimits(-5.,20.);
  auto axisy = gr1->GetYaxis();
  axisy->SetLimits(-10.,10.);
  // gr1->Draw("AP");
  TF1 *fa1 = new TF1("fa1","(12.10*x)/(x+100000)",-5,20);
  // fa1->Draw("same");

  //c2->cd(1);
  TGraph *gr2 = new TGraph(m,logR2,Vout2);

  gr2->SetTitle("Vout vs. log(R2);log(R2);Vout (Volts)");
  gr2->SetMarkerColor(4);
  gr2->SetMarkerStyle(21);
  //gr2->SetXTitle("log(R2)");
  // gr2->SetYTitle("Vout (Volts)");
  auto axis1x = gr2->GetXaxis();
  axis1x->SetLimits(-2.,15.);
  auto axis1y = gr2->GetYaxis();
  axis1y->SetLimits(-2.,15.);
  gr2->Draw("AP");
  TF1 *fa2 = new TF1("fa2","(12.10*x)/(x+100)",0,15);
  //fa2->Draw("same");

  //c3->cd(1);
  TGraph *gr3 = new TGraph(j,I,Vled);

  gr3->SetTitle("V(LED) vs. I;Current I (milli-Amps);V(LED) (Volts)");
  gr3->SetMarkerColor(4);
  gr3->SetMarkerStyle(21);
  //gr3->SetXTitle("I (milliAmps)");
  //gr3->SetYTitle("V(LED) (Volts)");
  auto axis2x = gr3->GetXaxis();
  axis2x->SetLimits(-5.,30.);
  auto axis2y = gr3->GetYaxis();
  axis2y->SetLimits(-5.,10.);
  gr3->Draw("AP");

  /* c1->cd(4);
  TF1 *fa1 = new TF1("fa1","(12.10*x)/(x+100)",0,100);
  fa1->Draw();*/

  

}
