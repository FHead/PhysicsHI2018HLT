#include <iostream>
#include <fstream>
using namespace std;

#include "TH1.h"
#include "TFile.h"

#include "CommandLine.h"

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   string InputFileName = CL.Get("Input");
   string HistogramName = CL.Get("Hist");
   string OutputFileName = CL.Get("Output");

   TFile File(InputFileName.c_str());

   TH1 *H = (TH1 *)File.Get(HistogramName.c_str());

   if(H == nullptr)
      return -1;

   ofstream out(OutputFileName);

   int N = H->GetNbinsX();
   for(int i = 1; i <= N; i++)
   {
      double XL = H->GetXaxis()->GetBinLowEdge(i);
      double XH = H->GetXaxis()->GetBinUpEdge(i);
      double Y = H->GetBinContent(i);

      out << XL << " " << XH << " " << Y << endl;
   }

   out.close();

   File.Close();

   return 0;
}



