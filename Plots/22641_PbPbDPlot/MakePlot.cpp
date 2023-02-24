#include <iostream>
using namespace std;

#include "TGraphAsymmErrors.h"
#include "TCanvas.h"
#include "TH2D.h"
#include "TLegend.h"
#include "TLatex.h"

#include "SetStyle.h"

int main();
void Transcribe(TGraphAsymmErrors &G, int N, double *X, double *Y, double *EYH, double *EYL);

int main()
{
   SetThesisSmallStyle();

   double X[] = {15, 17.5, 20, 25, 30, 35, 40, 45, 55, 60, 65, 70, 80, 90, 100};

   int N60 = 14;
   double Y60[] = {0.001989413,0.02746301,0.002536122,0.00485356,0.015502235,0.007292489,0.007429166,0.022257127,0.066358311,0.941189743,0.928718705,0.930926802,0.968734759,0.987690372};
   double EYL60[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0.01, 0.02, 0.015, 0.015, 0.015};
   double EYH60[] = {0.04, 0, 0, 0, 0, 0, 0, 0, 0, 0.01, 0.02, 0.015, 0.015, 0.015};

   int N40 = 14;
   double Y40[] = {0.060790992,0.044207489,0.019280601,0.038336443,0.044799757,0.036590012,0.921930403,0.924202282,0.928542543,0.945375103,0.926626025,0.928834122,0.987568881,0.977226971};
   double EYL40[] = {0.05, 0, 0, 0, 0, 0, 0, 0, 0.02, 0.01, 0.025, 0.02, 0.01, 0.025};
   double EYH40[] = {0.05, 0, 0, 0, 0, 0, 0, 0, 0.02, 0.01, 0.025, 0.02, 0.01, 0.025};

   int N20 = 6;
   double Y20[] = {0.06079403,0.05257821,0.900298954,0.904706035,0.892335228,0.907141927};
   double EYL20[] = {0, 0.015, 0, 0.015, 0.02, 0.03};
   double EYH20[] = {0, 0.015, 0, 0.015, 0.02, 0.03};

   TGraphAsymmErrors G60, G40, G20;
   Transcribe(G60, N60, X, Y60, EYH60, EYL60);
   Transcribe(G40, N40, X, Y40, EYH40, EYL40);
   Transcribe(G20, N20, X, Y20, EYH20, EYL20);

   G60.SetMarkerStyle(20);
   G40.SetMarkerStyle(20);
   G20.SetMarkerStyle(20);
   G60.SetMarkerSize(2);
   G40.SetMarkerSize(2);
   G20.SetMarkerSize(2);
   G60.SetMarkerColor(kBlue);
   G40.SetMarkerColor(kRed);
   G20.SetMarkerColor(kBlack);
   G60.SetLineColor(kBlue);
   G40.SetLineColor(kRed);
   G20.SetLineColor(kBlack);

   TLegend Legend(0.4, 0.5, 0.7, 0.3);
   Legend.SetTextFont(42);
   Legend.SetTextSize(0.04);
   Legend.SetBorderSize(0);
   Legend.SetFillStyle(0);
   Legend.AddEntry(&G20, "HLT D meson p_{T} #geq 20", "pl");
   Legend.AddEntry(&G40, "HLT D meson p_{T} #geq 40", "pl");
   Legend.AddEntry(&G60, "HLT D meson p_{T} #geq 60", "pl");

   TCanvas Canvas;

   Canvas.SetLeftMargin(0.125);
   Canvas.SetBottomMargin(0.125);
   Canvas.SetRightMargin(0.100);

   TH2D HWorld("HWorld", ";p_{T} (D^{0}) (GeV);HLT Efficiency", 10, 15, 100, 10, 0, 1.5);
   HWorld.SetStats(0);
   HWorld.GetXaxis()->CenterTitle();
   HWorld.GetYaxis()->CenterTitle();

   HWorld.GetXaxis()->SetTitleSize(0.05);
   HWorld.GetYaxis()->SetTitleSize(0.05);
   HWorld.GetXaxis()->SetLabelSize(0.05);
   HWorld.GetYaxis()->SetLabelSize(0.05);

   HWorld.Draw("axis");

   Legend.Draw();

   G20.Draw("p");
   G40.Draw("p");
   G60.Draw("p");

   TLatex Latex;
   Latex.SetTextFont(42);
   Latex.SetTextSize(0.05);
   Latex.SetNDC();

   Latex.SetTextAlign(12);
   Latex.DrawLatex(0.125, 0.925, "#font[62]{CMS} #font[52]{Preliminary}");
   
   Latex.SetTextAlign(32);
   Latex.DrawLatex(0.900, 0.925, "PbPb 5.02 TeV");

   Canvas.SaveAs("DPbPb.pdf");
   Canvas.SaveAs("DPbPb.png");
}

void Transcribe(TGraphAsymmErrors &G, int N, double *X, double *Y, double *EYH, double *EYL)
{
   for(int i = 0; i < N; i++)
   {
      G.SetPoint(i, (X[i] + X[i+1]) / 2, Y[i]);
      G.SetPointError(i, (X[i+1] - X[i]) / 2, (X[i+1] - X[i]) / 2, EYL[i], EYH[i]);
   }
}


