//Macro for Lab 4 Report

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
  //c1->Divide(3,1);

  //List the data points for first set of data (Diodes)
  int n = 8;
  double Vin[]  = {0.5,1,1.5,2,2.5,3,3.5,4}; //Volts (Vpp=2Vin)
  double Vout[]  = {0.124,0.580,1.08,1.54,2.04,2.52,3.00,3.48}; //Volts
  double Vouterr[] = {0.004,0.02,0.04,0.04,0.04,0.04,0.04,0.04};

  //List the data points for second set of data (Voltage divider + transistor)
  //Simple voltage divider
  int m = 2;
  double Vout1[]  = {0,3.018}; //Volts
  double I1[]  = {0,5.40}; //mA

  //Voltage divider with a transistor
  double Vout2[]  = {0,2.131}; //Volts
  double I2[]  = {0,3.72}; //mA

  //Simple current source circuit
  int j = 6;
  double RL[]  = {509,985,1964,2943,3928,4915}; //Ohms
  double I3[]  = {7.41,5.75,3.47,2.47,1.91,1.56}; //mA


  //Make the graphs+Set Plot Properties
  //c1->cd(1);
  TGraph *gr1 = new TGraph(n,Vin,Vout);

  gr1->SetTitle("Plot of Vout vs. Vin for a Half Wave Rectifier;Vin (V);Vout (V)");
  gr1->SetMarkerColor(4);
  gr1->SetMarkerStyle(21);
  auto axisx = gr1->GetXaxis();
  axisx->SetLimits(0.,5.);
  auto axisy = gr1->GetYaxis();
  axisy->SetLimits(0.,4.);
  // gr1->Draw("AP");
  // TF1 *fa1 = new TF1("fa1","5*977/(sqrt(pow((6.283185*0.001*x/((39.4784176*0.001*0.0000001*x*x)-1)),2)+954529))",0,1000000);
  //fa1->Draw("same");

  //c1->cd(2);
  //TGraph *gr2 = new TGraphErrors(n,lf,phi,lfer,phier);
  TGraph *gr2 = new TGraph(m,I1,Vout1);

  gr2->SetTitle("Plot of Vout vs. I;I (mA);Vout (V)");
  gr2->SetMarkerColor(4);
  gr2->SetMarkerStyle(21);
  auto axis1x = gr2->GetXaxis();
  axis1x->SetLimits(0.,6.);
  auto axis1y = gr2->GetYaxis();
  axis1y->SetLimits(0.,4.);
  // gr2->Draw("");
  //TF1 *fa2 = new TF1("fa2","5*98.5/(sqrt(pow((6.283185*0.001*x/((39.4784176*0.001*0.0000001*x*x)-1)),2)+(98.5*98.5)))",0,1000000);
  // fa2->Draw("same");

  //c1->cd(3);
  TGraph *gr3 = new TGraph(m,I2,Vout2);

  gr3->SetTitle("Plot of Vout vs. I;I (mA);Vout (V)");
  gr3->SetMarkerColor(1);
  gr3->SetMarkerStyle(21);
  auto axis2x = gr3->GetXaxis();
  axis2x->SetLimits(0.,6.);
  auto axis2y = gr3->GetYaxis();
  axis2y->SetLimits(0.,4.);
  // gr3->Draw("LP");
  //TF1 *fa3 = new TF1("fa3","5*98.5/sqrt(pow(((39.4784176*0.001*0.0000001*x*x)-1)/(6.283185*0.0000001*x),2)+(98.5*98.5))",-1,1000000);
  //fa3->Draw("same");

  TLegend *leg = new TLegend(0.8,0.2,0.65,0.45,NULL,"brNDC");
  leg->SetBorderSize(1); leg->SetTextSize(0.035); leg->SetLineColor(0); leg->SetLineStyle(1); leg->SetLineWidth(2); leg->SetFillColor(0); leg->SetFillStyle(1001);
  leg->AddEntry(gr2," Voltage divider circuit","pl");
  leg->AddEntry(gr3," Transistor circuit","pl");
  // leg->Draw();

  // c1->cd(3);
  TGraph *gr4 = new TGraph(j,RL,I3);

  gr4->SetTitle("Plot of IL vs RL for the Current Source Transistor Circuit;RL (#Omega);IL (mA)");
  gr4->SetMarkerColor(4);
  gr4->SetMarkerStyle(21);
  auto axis3x = gr4->GetXaxis();
  axis3x->SetLimits(0.,5000.);
  auto axis3y = gr4->GetYaxis();
  axis3y->SetLimits(0.,8.);
  gr4->Draw("AP");
  // TF1 *fa4 = new TF1("fa4","100*(exp(-.05048*x))",0,80);
  // fa4->Draw();

  

} //End Macro
