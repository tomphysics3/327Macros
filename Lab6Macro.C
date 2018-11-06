//Macro for Lab 6 Report

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
  //c1->Divide(2,1);

  //Part B

  //List the data points for first set of data (Varying V1-V2)
  int n = 6;
  double V1V2[]  = {-0.58,-0.455,-0.21,0.38,0.62,0.68}; //Volts
  double Vout1[]  = {6.11,4.85,2.21,-3.50,-6.19,-6.76}; //Volts
  double Vout1err[] = {0.05,0.05,0.05,0.05,0.05,0.05}; //Volts

  //List the data points for second set of data (Varying V1)
  double V1[]  = {-0.572,-0.2126,-0.0005,0.192,0.542,0.713}; //Volts
  double Vout2[]  = {5.87,2.183,0.0023,-1.972,-5.56,-7.31}; //Volts
  double Vout2err[] = {0.01,0.01,0.0001,0.01,0.01,0.01}; //Volts

  //List the data points for third set of data (frequncy dependance)
  int m = 16;
  double f[]  = {1,10,50,100,150,200,250,300,350,400,500,600,700,800,900,1000}; //kHz
  double Voutpkpk[]  = {10.2,10.2,5.96,3.16,2.12,1.64,1.40,1.16,1.00,0.92,0.84,0.72,0.68,0.60,0.56,0.52}; //Volts
  //double Vout3err[] = {0.01,0.01,0.0001,0.01,0.01,0.01}; //Volts

  //Part C

  //List the data points for first set of data (Gain as function of input)
  int j = 4;
  double Vin[]  = {0.25,0.5,0.75,1.0}; //Volts
  double G[]  = {-11.6,-11.6,-11.3,-11.05}; //Gain->unitless

  //List the data points for second set of data (frequency dependance)
  int i = 7;
  double f1[]  = {1,5,10,50,100,500,1000}; //kHz
  double Vout3[]  = {-5.8,-5.8,-5.8,-3.5,-1.85,-0.55,-0.4}; //Volts



  //Make the graphs+Set Plot Properties
  //c1->cd(1);
  TGraph *gr1 = new TGraph(n,V1V2,Vout1);

  gr1->SetTitle("Plot of Vout (V) vs. (V1-V2);(V1-V2) (V);Vout (V)");
  gr1->SetMarkerColor(4);
  gr1->SetMarkerStyle(21);
  auto axisx = gr1->GetXaxis();
  axisx->SetLimits(-1.,1.);
  auto axisy = gr1->GetYaxis();
  axisy->SetLimits(-8.,8.);
  //gr1->Draw("AP");
  // TF1 *fa1 = new TF1("fa1","5*977/(sqrt(pow((6.283185*0.001*x/((39.4784176*0.001*0.0000001*x*x)-1)),2)+954529))",0,1000000);
  //fa1->Draw("same");

  // c1->cd(2);
  //TGraph *gr2 = new TGraphErrors(n,lf,phi,lfer,phier);
  TGraph *gr2 = new TGraph(n,V1,Vout2);

  gr2->SetTitle("Plot of Vout vs. V1;V1 (V);Vout (V)");
  gr2->SetMarkerColor(4);
  gr2->SetMarkerStyle(21);
  auto axis1x = gr2->GetXaxis();
  axis1x->SetLimits(-1.,1.);
  auto axis1y = gr2->GetYaxis();
  axis1y->SetLimits(-8.,8.);
  //  gr2->Draw("AP");
  //TF1 *fa2 = new TF1("fa2","5*98.5/(sqrt(pow((6.283185*0.001*x/((39.4784176*0.001*0.0000001*x*x)-1)),2)+(98.5*98.5)))",0,1000000);
  // fa2->Draw("same");

  //c1->cd(3);
  TGraph *gr3 = new TGraph(m,f,Voutpkpk);

  gr3->SetTitle("Plot Vout pk to pk vs. Frequency;Frequency (kHz);Voutpkpk (V)");
  gr3->SetMarkerColor(1);
  gr3->SetMarkerStyle(21);
  auto axis2x = gr3->GetXaxis();
  axis2x->SetLimits(0.,1000.);
  auto axis2y = gr3->GetYaxis();
  axis2y->SetLimits(0.,12.);
  // gr3->Draw("AP");
  //TF1 *fa3 = new TF1("fa3","5*98.5/sqrt(pow(((39.4784176*0.001*0.0000001*x*x)-1)/(6.283185*0.0000001*x),2)+(98.5*98.5))",-1,1000000);
  //fa3->Draw("same");

 /* TLegend *leg = new TLegend(0.8,0.2,0.65,0.45,NULL,"brNDC");
  leg->SetBorderSize(1); leg->SetTextSize(0.035); leg->SetLineColor(0); leg->SetLineStyle(1); leg->SetLineWidth(2); leg->SetFillColor(0); leg->SetFillStyle(1001);
  leg->AddEntry(gr2," Voltage divider circuit","pl");
  leg->AddEntry(gr3," Transistor circuit","pl");
  // leg->Draw();*/

  //c1->cd(1);
  TGraph *gr4 = new TGraph(j,Vin,G);

  gr4->SetTitle("Plot of the Gain vs. V1;V1 (V);Gain");
  gr4->SetMarkerColor(4);
  gr4->SetMarkerStyle(21);
  auto axis3x = gr4->GetXaxis();
  axis3x->SetLimits(0.,1.);
  auto axis3y = gr4->GetYaxis();
  axis3y->SetLimits(-20.,0.);
  //gr4->Draw("AP");
  // TF1 *fa4 = new TF1("fa4","100*(exp(-.05048*x))",0,80);
  // fa4->Draw();

  //c1->cd(2);
  TGraph *gr5 = new TGraph(i,f1,Vout3);

  gr5->SetTitle("Plot of Vout amplitude vs. Input Frequency;frequency (kHz);Vout amplitude (V)");
  gr5->SetMarkerColor(4);
  gr5->SetMarkerStyle(21);
  auto axis4x = gr5->GetXaxis();
  axis4x->SetLimits(0.,1000.);
  auto axis4y = gr5->GetYaxis();
  axis4y->SetLimits(-7.,0.);
  gr5->Draw("AP");

  

} //End Macro
