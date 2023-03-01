#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#include "TH1D.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TFile.h"
#include "TGaxis.h"
#include "TPad.h"
#include "TBox.h"

#include "RootUtilities.h"
#include "CustomAssert.h"
#include "CommandLine.h"
#include "SetStyle.h"

int main(int argc, char *argv[]);
void SetPad(TPad &P);
void SetAxis(TGaxis &A);
string FindBase(string FileName);

int main(int argc, char *argv[])
{
   SilenceRoot();

   vector<int> DefaultColors = GetCVDColors6();
   int DefaultMarkers[6] = {20, 20, 20, 20, 20, 20};

   CommandLine CL(argc, argv);

   vector<string> Labels       = CL.GetStringVector("label");
   vector<string> FileNames    = CL.GetStringVector("file");
   vector<string> Curves       = CL.GetStringVector("curve");
   bool HistogramMode          = CL.GetBool("histogram", false);
   string OutputFileName       = CL.Get("output");
   string XTitle               = CL.Get("xtitle", "");
   string YTitle               = CL.Get("ytitle", "");
   double XMin                 = CL.GetDouble("xmin");
   double XMax                 = CL.GetDouble("xmax");
   double YMin                 = CL.GetDouble("ymin", 0.0);
   double YMax                 = CL.GetDouble("ymax", 1.1);
   bool DoRatio                = CL.GetBool("ratio", false);
   string RTitle               = DoRatio ? CL.Get("rtitle") : "";
   vector<string> RFileNames   = DoRatio ? CL.GetStringVector("rfile") : vector<string>();
   vector<string> RCurves      = DoRatio ? CL.GetStringVector("rcurve") : vector<string>();
   double RMin                 = DoRatio ? CL.GetDouble("rmin") : 0;
   double RMax                 = DoRatio ? CL.GetDouble("rmax") : 1;
   vector<int> Colors          = CL.GetIntVector("color", DefaultColors);
   vector<int> Markers         = CL.GetIntVector("marker", vector<int>(DefaultMarkers, DefaultMarkers + 6));
   vector<double> HLines       = CL.GetDoubleVector("hline", vector<double>());
   vector<double> VLines       = CL.GetDoubleVector("vline", vector<double>());
   vector<double> Boxes        = CL.GetDoubleVector("box", vector<double>());
   vector<string> Texts        = CL.GetStringVector("text", vector<string>());
   bool Grid                   = CL.GetBool("grid", false);
   bool LogX                   = CL.GetBool("logx", false);
   bool LogY                   = CL.GetBool("logy", false);
   double LegendX              = CL.GetDouble("legendx", 0.35);
   double LegendY              = CL.GetDouble("legendy", 0.20);
   int ReBin                   = CL.GetInt("rebin", 1);
   bool DoLegend               = CL.GetBool("legend", true);
   bool DoWatermark            = CL.GetBool("watermark", true);
   string Qualifier            = CL.Get("qualifier", "");
   string System               = CL.Get("system", "");

   if(HistogramMode == true && DoRatio == true)
   {
      cout << "Note: histogram mode is true, setting ratio to false" << endl;
      DoRatio = false;
   }

   string OutputBase = FindBase(OutputFileName);

   for(int i = 0; i < (int)Colors.size(); i++)
   {
      if(Colors[i] == -1)   Colors[i] = DefaultColors[0];
      if(Colors[i] == -2)   Colors[i] = DefaultColors[1];
      if(Colors[i] == -3)   Colors[i] = DefaultColors[2];
      if(Colors[i] == -4)   Colors[i] = DefaultColors[3];
      if(Colors[i] == -5)   Colors[i] = DefaultColors[4];
      if(Colors[i] == -6)   Colors[i] = DefaultColors[5];
   }

   int N = FileNames.size();
   if(N == 1 && Curves.size() > 1)
   {
      N = Curves.size();
      FileNames.insert(FileNames.end(), N - FileNames.size(), FileNames[0]);
   }

   Assert(N == Labels.size(),       "Number of files != number of labels");
   Assert(N == Curves.size(),       "Number of files != number of curves");
   Assert(N <= Colors.size(),       "Please specify line colors");

   int NR = RFileNames.size();
   if(DoRatio == true)
      Assert(RFileNames.size() == RCurves.size(), "Number of ratio files != number of ratio curves");
   else
      NR = 0;

   if(N > Markers.size())
      Markers.insert(Markers.end(), N - Markers.size(), 20);

   vector<TGraphAsymmErrors> Graphs(N);
   vector<TH2D> Histograms(N);
   for(int i = 0; i < N; i++)
   {
      TFile File(FileNames[i].c_str());
      if(HistogramMode == false)
         Graphs[i] = *(TGraphAsymmErrors *)File.Get(Curves[i].c_str());
      else
         Histograms[i] = *(TH2D *)File.Get(Curves[i].c_str());
      File.Close();
   }
   
   vector<TGraphAsymmErrors> RGraphs(NR);
   for(int i = 0; i < NR; i++)
   {
      TFile File(RFileNames[i].c_str());
      RGraphs[i] = *(TGraphAsymmErrors *)File.Get(RCurves[i].c_str());
      File.Close();
   }

   double CanvasW      = 1024;
   double CanvasH      = 768;
   double LeftMargin   = 0.125;
   double RightMargin  = 0.10;
   double TopMargin    = 0.10;
   double BottomMargin = 0.125;
   double RHeight      = 0.20;
   if(DoRatio == false)
      RHeight = 0;

   TCanvas Canvas("Canvas", "", CanvasW, CanvasH);
   // Canvas.SetLeftMargin(LeftMargin);
   // Canvas.SetRightMargin(RightMargin);
   // Canvas.SetTopMargin(TopMargin);
   // Canvas.SetBottomMargin(BottomMargin);

   double PadX0 = LeftMargin;
   double PadX1 = 1 - RightMargin;
   double PadY0 = BottomMargin;
   double PadY1 = 1 - TopMargin;
   double PadYM = (PadY1 - PadY0) * RHeight + PadY0;   // if ratio, cut in middle

   TPad MainPad("MainPad", "", PadX0, PadYM, PadX1, PadY1);
   SetPad(MainPad);

   TPad RatioPad("RatioPad", "", PadX0, PadY0, PadX1, PadYM);
   if(DoRatio == true)
      SetPad(RatioPad);

   TGaxis XAxis(PadX0, PadY0, PadX1, PadY0, XMin, XMax, 510, (LogX ? "G" : ""));
   TGaxis YAxis(PadX0, PadYM, PadX0, PadY1, YMin, YMax, 510, (LogY ? "G" : ""));
   TGaxis RAxis(PadX0, PadY0, PadX0, PadYM, RMin, RMax, 503, "");

   SetAxis(XAxis);
   SetAxis(YAxis);
   if(DoRatio)
      SetAxis(RAxis);

   MainPad.cd();
   MainPad.SetGridx(Grid);
   MainPad.SetGridy(Grid);
   MainPad.SetLogx(LogX);
   MainPad.SetLogy(LogY);

   TH2D HWorld("HWorld", "", 100, XMin, XMax, 100, YMin, YMax);
   HWorld.SetStats(0);
   HWorld.Draw();

   TGraph GHLine;
   GHLine.SetLineStyle(kDashed);
   for(int i = 0; i < (int)HLines.size(); i++)
   {
      if(i % 2 == 0)
      {
         GHLine.SetPoint(i * 2 + 0, XMin - 1, HLines[i]);
         GHLine.SetPoint(i * 2 + 1, XMax + 1, HLines[i]);
      }
      else
      {
         GHLine.SetPoint(i * 2 + 0, XMax + 1, HLines[i]);
         GHLine.SetPoint(i * 2 + 1, XMin - 1, HLines[i]);
      }
   }
   GHLine.Draw("l");

   TGraph GVLine;
   GVLine.SetLineStyle(kDashed);
   for(int i = 0; i < (int)VLines.size(); i++)
   {
      if(i % 2 == 0)
      {
         GVLine.SetPoint(i * 2 + 0, VLines[i], YMin - 1);
         GVLine.SetPoint(i * 2 + 1, VLines[i], YMax + 1);
      }                                               
      else                                            
      {                                               
         GVLine.SetPoint(i * 2 + 0, VLines[i], YMax + 1);
         GVLine.SetPoint(i * 2 + 1, VLines[i], YMin - 1);
      }
   }
   GVLine.Draw("l");

   TBox Box;
   Box.SetFillStyle(1);
   Box.SetFillColor(kBlue);
   Box.SetLineWidth(0);
   cout << Boxes.size() << endl;
   for(int i = 0; i + 4 <= (int)Boxes.size(); i = i + 4)
   {
      cout << Boxes[i+0] << " " << Boxes[i+1] << " " << Boxes[i+2] << " " << Boxes[i+3] << endl;
      Box.DrawBox((Boxes[i] - XMin) / (XMax - XMin), (Boxes[i+1] - YMin) / (YMax - YMin),
         (Boxes[i+2] - XMin) / (XMax - XMin), (Boxes[i+3] - YMin) / (YMax - YMin));
      Box.DrawBox(Boxes[i], Boxes[i+1], Boxes[i+2], Boxes[i+3]);
   }

   for(int i = 0; i < N; i++)
   {
      if(HistogramMode == false)
      {
         Graphs[i].SetMarkerColor(Colors[i]);
         Graphs[i].SetMarkerStyle(Markers[i]);
         Graphs[i].SetMarkerSize(1.5 - i * 0.04);
         Graphs[i].SetLineColor(Colors[i]);
         Graphs[i].SetLineWidth(2);
         if(Graphs[i].GetN() > 0)
            Graphs[i].Draw("p");
      }
      else
      {
         Histograms[i].SetLineColor(Colors[i]);
         Histograms[i].SetLineWidth(2);
         Histograms[i].SetFillColorAlpha(Colors[i], 0.25);
         Histograms[i].Draw("same");
      }
   }

   int LegendCount = 0;
   for(int i = 0; i < N; i++)
      if(Labels[i] != "NONE")
         LegendCount = LegendCount + 1;
   TLegend Legend(LegendX, LegendY, LegendX + 0.3, LegendY + 0.06 * LegendCount / (PadY1 - PadYM));
   Legend.SetTextFont(42);
   Legend.SetTextSize(0.035 / (PadY1 - PadYM));
   Legend.SetBorderSize(0);
   Legend.SetFillStyle(0);
   for(int i = 0; i < N; i++)
   {
      if(Labels[i] != "NONE")
      {
         if(HistogramMode == false)
            Legend.AddEntry(&Graphs[i], Labels[i].c_str(), "pl");
         else
            Legend.AddEntry(&Histograms[i], Labels[i].c_str(), "F");
      }
   }
   if(DoLegend == true)
      Legend.Draw();

   if(Texts.size() > 0)
   {
      TLatex Latex;
      Latex.SetNDC();
      Latex.SetTextFont(42);
      Latex.SetTextSize(0.035 / (PadY1 - PadYM));
      Latex.SetTextAlign(11);

      for(int i = 0; i + 3 <= (int)Texts.size(); i = i + 3)
      {
         double x = atof(Texts[i+0].c_str());
         double y = atof(Texts[i+1].c_str());
         while(Texts[i+2].find("&comma;") != string::npos)
            Texts[i+2].replace(Texts[i+2].find("&comma;"), 7, ",");
         Latex.DrawLatex(x, y, Texts[i+2].c_str());
      }
   }

   TH2D HWorldR("HWorld", "", 100, XMin, XMax, 100, RMin, RMax);
   HWorldR.SetStats(0);
   HWorldR.GetYaxis()->SetNdivisions(503);
   
   if(DoRatio == true)
   {
      RatioPad.cd();
      RatioPad.SetLogx(LogX);
      HWorldR.Draw();

      for(int i = 0; i < NR; i++)
      {
         RGraphs[i].SetMarkerStyle(Markers[i]);
         RGraphs[i].SetMarkerSize(1.5 - i * 0.04);
         RGraphs[i].SetLineWidth(2);
         RGraphs[i].SetMarkerColor(kBlack);
         RGraphs[i].SetLineColor(kBlack);
         // RGraphs[i].SetMarkerColor(Colors[i]);
         // RGraphs[i].SetLineColor(Colors[i]);
         if(RGraphs[i].GetN() > 0)
            RGraphs[i].Draw("p");
      }
   }

   Canvas.cd();

   TLatex Latex;
   Latex.SetNDC();

   Latex.SetTextFont(42);
   Latex.SetTextSize(0.03);
   Latex.SetTextAlign(11);
   Latex.DrawLatex(LeftMargin, 1 - TopMargin + 0.01, ("#scale[1.5]{CMS} #font[52]{" + Qualifier + "}").c_str());

   Latex.SetTextSize(0.035);
   Latex.SetTextAlign(31);
   Latex.DrawLatex(1 - RightMargin, 1 - TopMargin + 0.01, System.c_str());

   Latex.SetTextAlign(22);
   Latex.SetTextAngle(0);
   Latex.DrawLatex((PadX0 + PadX1) / 2, PadY0 / 2, XTitle.c_str());
   
   Latex.SetTextAlign(22);
   Latex.SetTextAngle(90);
   Latex.DrawLatex(PadX0 / 2, (PadYM + PadY1) / 2, YTitle.c_str());

   if(DoRatio == true)
   {
      Latex.SetTextAlign(22);
      Latex.SetTextAngle(90);
      Latex.DrawLatex(PadX0 / 2, (PadY0 + PadYM) / 2, RTitle.c_str());
   }

   if(DoWatermark == true)
   {
      TLatex Latex;
      Latex.SetNDC();
      Latex.SetTextFont(42);
      Latex.SetTextSize(0.025);
      Latex.SetTextColor(19);
      Latex.SetTextAlign(11);
      Latex.DrawLatex(0.02, 0.02, OutputBase.c_str());
   }

   Canvas.SaveAs((OutputBase + ".pdf").c_str());
   Canvas.SaveAs((OutputBase + ".png").c_str());
   Canvas.SaveAs((OutputBase + ".eps").c_str());
   Canvas.SaveAs((OutputBase + ".C").c_str());

   return 0;
}

void SetPad(TPad &P)
{
   P.SetLeftMargin(0);
   P.SetTopMargin(0);
   P.SetRightMargin(0);
   P.SetBottomMargin(0);
   P.SetTickx();
   P.SetTicky();
   P.Draw();
}

void SetAxis(TGaxis &A)
{
   A.SetLabelFont(42);
   A.SetLabelSize(0.035);
   A.SetTitleFont(42);
   A.SetTitleSize(0.035);
   A.SetMaxDigits(6);
   // A.SetMoreLogLabels();
   // A.SetNoExponent();
   A.Draw();
}

string FindBase(string FileName)
{
   if(FileName.find('.') == string::npos)
      return FileName;

   FileName.erase(FileName.begin() + FileName.find('.'), FileName.end());
   return FileName;
}

