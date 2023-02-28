#include <iostream>
#include <fstream>
using namespace std;

#include "TFile.h"
#include "TH1D.h"

#include "CommandLine.h"

int main(int argc, char *argv[])
{
   CommandLine CL(argc, argv);

   string Input = CL.Get("Input");
   string Output = CL.Get("Output");
   string Name = CL.Get("Name");

   TFile OutputFile(Output.c_str(), "RECREATE");

   int N = 0;
   double X[10000] = {0};
   double Y[10000] = {0};

   ifstream in(Input);

   double xl, xr, y;
   while(in)
   {
      xl = -1;
      in >> xl >> xr >> y;

      if(xl < 0)
         continue;

      X[N] = xl;
      X[N+1] = xr;
      Y[N] = y;
      N = N + 1;
   }

   in.close();

   TH1D H(Name.c_str(), Name.c_str(), N, X);
   for(int i = 1; i <= N; i++)
      H.SetBinContent(i, Y[i-1]);
   H.Write();

   OutputFile.Close();

   return 0;
}



