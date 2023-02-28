#include <iostream>
#include <fstream>
using namespace std;

#include "TFile.h"
#include "TGraphAsymmErrors.h"

#include "CommandLine.h"

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   string Input = CL.Get("Input");
   string Output = CL.Get("Output");
   string Name = CL.Get("Name");

   TFile OutputFile(Output.c_str(), "RECREATE");
   
   TGraphAsymmErrors G;
   G.SetNameTitle(Name.c_str(), Name.c_str());

   ifstream in(Input);

   while(in)
   {
      double x = -10000, y, exl, exh, eyl, eyh;

      in >> x >> y >> exl >> exh >> eyl >> eyh;

      if(x < -9999)
         continue;

      int N = G.GetN();
      G.SetPoint(N, x, y);
      G.SetPointError(N, exl, exh, eyl, eyh);
   }

   in.close();

   G.SetMarkerStyle(20);
   G.Write();

   OutputFile.Close();

   return 0;
}



