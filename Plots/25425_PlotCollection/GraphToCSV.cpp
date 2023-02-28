#include <iostream>
#include <fstream>
using namespace std;

#include "TGraphAsymmErrors.h"
#include "TFile.h"

#include "CommandLine.h"

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   string InputFileName = CL.Get("Input");
   string GraphName = CL.Get("Graph");
   string OutputFileName = CL.Get("Output");

   TFile File(InputFileName.c_str());

   TGraphAsymmErrors *G = (TGraphAsymmErrors *)File.Get(GraphName.c_str());

   if(G == nullptr)
      return -1;

   ofstream out(OutputFileName);

   int N = G->GetN();
   for(int i = 0; i < N; i++)
   {
      double X = G->GetPointX(i);
      double Y = G->GetPointY(i);
      double EXL = G->GetErrorXlow(i);
      double EXH = G->GetErrorXhigh(i);
      double EYL = G->GetErrorYlow(i);
      double EYH = G->GetErrorYhigh(i);

      out << X << " " << Y << " " << EXL << " " << EXH << " " << EYL << " " << EYH << endl;
   }

   out.close();

   File.Close();

   return 0;
}



