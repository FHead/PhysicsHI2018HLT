#!/bin/bash

# HM L1 plot
./Execute \
	--label "Tower count > 115 and 120","Tower count > 145 and 150" \
	--file Combined.root \
	--curve pPb8TeV_HM_L1_115120_O,pPb8TeV_HM_L1_145150_O \
   --hline 1 --vline 185,250 \
   --xtitle "N_{trk}^{offline}" --ytitle "L1 Trigger Efficiency" --xmin 0 --xmax 400 --ymin 0.0 --ymax 1.05 \
   --system "pPb 8.16 TeV" --qualifier "Preliminary" \
	--legendx 0.50 --legendy 0.05 --output Plots/pPb8TeV_HM_L1.pdf

# HM HLT plot
./Execute \
	--label "N_{ch}^{online} > 120","N_{ch}^{online} > 150","N_{ch}^{online} > 185","N_{ch}^{online} > 250","N_{ch}^{online} > 280" \
	--file Combined.root \
	--curve pPb8TeV_HM_HLT_120_O,pPb8TeV_HM_HLT_150_O,pPb8TeV_HM_HLT_185_O,pPb8TeV_HM_HLT_250_O,pPb8TeV_HM_HLT_280_O \
   --hline 1 --vline 120,150,185,250,280 \
   --xtitle "N_{trk}^{offline}" --ytitle "High-Level Trigger Efficiency" --xmin 0 --xmax 400 --ymin 0.0 --ymax 1.05 \
   --system "pPb 8.16 TeV" --qualifier "Preliminary" \
	--legendx 0.025 --legendy 0.55 --output Plots/pPb8TeV_HM_HLT.pdf

# PAL3Mu12 efficiency
./Execute \
   --label "MC Powheg","Data" \
   --file Combined.root \
   --curve pPb8TeV_L3Mu_L1HLT_12_PT_MC_O,pPb8TeV_L3Mu_L1HLT_12_PT_Data_O \
   --xtitle "p_{T}^{#mu} (GeV/c)" --ytitle "Muon efficiency" --xmin 0 --xmax 200 --ymin 0.85 --ymax 1.00 \
   --system "pPb 8.16 TeV" --qualifier "Preliminary" \
   --ratio true --rtitle "Data/MC" --rmin 0.9 --rmax 1.09 --rfile Combined.root --rcurve pPb8TeV_L3Mu_L1HLT_12_PT_Ratio_O \
   --legendx 0.6 --legendy 0.1 --output Plots/pPb8TeV_L3Mu12.pdf \
   --text 0.08,0.12,"|#eta^{#mu}| < 2.4&comma; p_{T}^{#mu} > 15 GeV/c",0.08,0.20,"HLT_PAL3Mu12 Efficiency"

# PbPb L1DoubleMu0 efficiency
./Execute \
   --label "MC Pythia","Data" \
   --file Combined.root \
   --curve PbPb5TeV_DoubleMu_L1HLT_0_PT_MC_O,PbPb5TeV_DoubleMu_L1HLT_0_PT_Data_O \
   --xtitle "p_{T}^{#mu} (GeV/c)" --ytitle "Muon efficiency" --xmin 0 --xmax 30 --ymin 0.45 --ymax 1.00 \
   --system "PbPb 5.02 TeV" --qualifier "Preliminary" \
   --ratio true --rtitle "Data/MC" --rmin 0.5 --rmax 1.45 --rfile Combined.root --rcurve PbPb5TeV_DoubleMu_L1HLT_0_PT_Ratio_O \
   --legendx 0.6 --legendy 0.1 --output Plots/PbPb5TeV_L1DoubleMu0.pdf \
   --text 0.5,0.42,"|#eta^{#mu}| < 2.4&comma; p_{T}^{#mu} > 1.8 GeV/c",0.5,0.50,"HLT_HIL1DoubleMu0 Efficiency"

# MB efficiency
./Execute \
	--label "40-50%","50-60%","60-70%","70-80%","80-100%" \
	--file Combined.root \
	--curve PbPb5TeV_MB_L1HLT_4050_O,PbPb5TeV_MB_L1HLT_5060_O,PbPb5TeV_MB_L1HLT_6070_O,PbPb5TeV_MB_L1HLT_7080_O,PbPb5TeV_MB_L1HLT_80100_O \
   --hline 1 --vline 15 \
   --xtitle "HF threshold (ADC)" --ytitle "Efficiency" --xmin 0 --xmax 40 --ymin 0.0 --ymax 1.2 \
   --system "PbPb 5.02 TeV" --qualifier "Preliminary" \
   --text 0.05,0.91,"HLT_ZeroBias_SinglePixelTrack_AND",0.05,0.43,"Centrality" \
   --box 15,0,16,1.2 \
	--legendx 0.04 --legendy 0.04 --output Plots/PbPb5TeV_MB.pdf

# D0 pp efficiency
./Execute \
   --label "HLT D meson p_{T} #geq 8","HLT D meson p_{T} #geq 15","HLT D meson p_{T} #geq 20" \
   --file Combined.root \
   --curve pp5TeV_D_HLT_8,pp5TeV_D_HLT_15,pp5TeV_D_HLT_20 \
   --hline 1 \
   --xtitle "p_{T} (D^{0}) (GeV)" --ytitle "HLT Efficiency" --xmin 0 --xmax 50 --ymin 0 --ymax 1.05 \
   --system "pp 5.02 TeV" --qualifier "Preliminary" \
   --legendx 0.55 --legendy 0.15 --output Plots/pp5TeV_D0.pdf

# D0 PbPb efficiency
./Execute \
   --label "HLT D meson p_{T} #geq 20","HLT D meson p_{T} #geq 40","HLT D meson p_{T} #geq 60" \
   --file Combined.root \
   --curve PbPb5TeV_D_HLT_20,PbPb5TeV_D_HLT_40,PbPb5TeV_D_HLT_60 \
   --hline 1 \
   --xtitle "p_{T} (D^{0}) (GeV)" --ytitle "HLT Efficiency" --xmin 10 --xmax 100 --ymin 0 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier "Preliminary" \
   --legendx 0.15 --legendy 0.35 --output Plots/PbPb5TeV_D0.pdf

# Photon
./Execute \
   --label "HLT SinglePhoton 40","HLT SinglePhoton 50","HLT SinglePhoton 60" \
   --file Combined.root \
   --curve PbPb5TeV_Photon_HLT_40_O,PbPb5TeV_Photon_HLT_50_O,PbPb5TeV_Photon_HLT_60_O \
   --hline 1 \
   --xtitle "p_{T}^{#gamma} (GeV)" --ytitle "L1+HLT Efficiency" --xmin 20 --xmax 110 --ymin 0 --ymax 1 \
   --system "PbPb 5.02 TeV" --qualifier "Preliminary" \
   --text 0.55,0.4,"|#eta_{#gamma}| < 1.44" \
   --legendx 0.55 --legendy 0.1 --output Plots/PbPb5TeV_Photon.pdf

# Electron barrel
./Execute \
   --label "MC Pythia + Hydjet (0.9636^{+0.000}_{-0.000})","Data (0.9652^{+0.012}_{-0.013})" \
   --file Combined.root \
   --curve PbPb5TeV_Electron_L1HLT_20_MCBarrel,PbPb5TeV_Electron_L1HLT_20_DataBarrel \
   --xtitle "p_{T}^{e} [GeV/c]" --ytitle "Single electron efficiency" --xmin 15 --xmax 150 --ymin 0.8 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier "Preliminary" \
   --ratio true --rtitle "Scale factor" --rmin 0.91 --rmax 1.09 --rfile Combined.root --rcurve PbPb5TeV_Electron_L1HLT_20_RatioBarrel \
   --legendx 0.4 --legendy 0.1 --output Plots/PbPb5TeV_ElectronBarrel.pdf \
   --text 0.4,0.42,"|#eta^{#mu}| #in [0.0&comma; 1.4]&comma; p_{T}^{e} > 20.0 GeV/c",0.5,0.50,"L1+HLT Efficiency"

# Electron endcap
./Execute \
   --label "MC Pythia + Hydjet (0.9668^{+0.000}_{-0.000})","Data (0.9592^{+0.018}_{-0.024})" \
   --file Combined.root \
   --curve PbPb5TeV_Electron_L1HLT_20_MCEndcap,PbPb5TeV_Electron_L1HLT_20_DataEndcap \
   --xtitle "p_{T}^{e} [GeV/c]" --ytitle "Single electron efficiency" --xmin 15 --xmax 150 --ymin 0.8 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier "Preliminary" \
   --ratio true --rtitle "Scale factor" --rmin 0.91 --rmax 1.09 --rfile Combined.root --rcurve PbPb5TeV_Electron_L1HLT_20_RatioEndcap \
   --legendx 0.4 --legendy 0.1 --output Plots/PbPb5TeV_ElectronEndcap.pdf \
   --text 0.4,0.42,"|#eta^{#mu}| #in [1.6&comma; 2.0]&comma; p_{T}^{e} > 20.0 GeV/c",0.5,0.50,"L1+HLT Efficiency"

# Jet
./Execute \
   --label "HLT SingleJet 40","HLT SingleJet 60","HLT SingleJet 80","HLT SingleJet 100" \
   --file Combined.root \
   --curve PbPb5TeV_Jet_HLT_40,PbPb5TeV_Jet_HLT_60,PbPb5TeV_Jet_HLT_80,PbPb5TeV_Jet_HLT_100 \
   --hline 1 \
   --xtitle "p_{T}^{jet} (GeV)" --ytitle "L1+HLT Efficiency" --xmin 25 --xmax 180 --ymin 0 --ymax 1.19 \
   --system "PbPb 5.02 TeV" --qualifier "Preliminary" \
   --text 0.55,0.45,"|#eta_{jet}| < 2.0",0.55,0.52,"anti-k_{t} R = 0.4" \
   --legendx 0.55 --legendy 0.1 --output Plots/PbPb5TeV_Jet.pdf

# L1EG barrel
./Execute \
   --label "MC Starlight (0.9781^{+0.002}_{-0.002})","Data (0.9790^{+0.004}_{-0.004})" \
   --file Combined.root \
   --curve PbPb5TeV_EG_L1_2_MCBarrel,PbPb5TeV_EG_L1_2_DataBarrel \
   --xtitle "SC E_{T} [GeV/c]" --ytitle "Single electron efficiency" --xmin 0 --xmax 20 --ymin 0 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier "Preliminary" \
   --ratio true --rtitle "Data / MC" --rmin 0.5 --rmax 1.6 --rfile Combined.root --rcurve PbPb5TeV_EG_L1_2_RatioBarrel \
   --legendx 0.4 --legendy 0.1 --output Plots/PbPb5TeV_L1EGBarrel.pdf \
   --text 0.4,0.42,"|#eta^{#mu}| #in [0.0&comma; 1.5]&comma; SC E_{T} > 2.0 GeV/c",0.48,0.50,"L1 EG2 trigger Efficiency"

# L1EG endcap 
./Execute \
   --label "MC Starlight (0.9248^{+0.007}_{-0.008})","Data (0.8763^{+0.018}_{-0.019})" \
   --file Combined.root \
   --curve PbPb5TeV_EG_L1_2_MCEndcap,PbPb5TeV_EG_L1_2_DataEndcap \
   --xtitle "SC E_{T} [GeV/c]" --ytitle "Single electron efficiency" --xmin 0 --xmax 20 --ymin 0 --ymax 1.05 \
   --system "PbPb 5.02 TeV" --qualifier "Preliminary" \
   --ratio true --rtitle "Data / MC" --rmin 0.5 --rmax 1.6 --rfile Combined.root --rcurve PbPb5TeV_EG_L1_2_RatioEndcap \
   --legendx 0.4 --legendy 0.1 --output Plots/PbPb5TeV_L1EGEndcap.pdf \
   --text 0.4,0.42,"|#eta^{#mu}| #in [1.5&comma; 2.4]&comma; SC E_{T} > 2.0 GeV/c",0.48,0.50,"L1 EG2 trigger Efficiency"

