# DPA
Digital Plant Analyzer


works with QT creator 4.0.2 and QT 5.7.0
you can download it here:
https://download.qt.io/archive/qt/5.7/5.7.0/

installation details see below.

Ubuntu (tested for 16.04 and 18.04):

go to your download folder:

$ chmod +x qt-opensource-linux-x64-5.7.0.run 

$ ./qt-opensource-linux-x64-5.7.0.run

follow the instructions of the installation guide

download sourcecode and datasets (best to your homefolder):

$ git clone https://github.com/hohenheimdr/DPA.git

open project file of DPA at
 DPA/DPA/DPA.pro
click "yes" in the pop up

change Build directory if needed under Projects ->Build directory

build and run the project by clicking the "run" button

if neccessary install dependencies: 
OpenCV - https://opencv.org/


Windows (not tested until now):
install qt 5.7.0 on your system
https://download.qt.io/archive/qt/5.7/5.7.0/
install visual studio with c/c++ support
msvc2013 compiler
https://www.microsoft.com/en-us/download/details.aspx?id=40760

download sourcecode and run project

if you use the code in research, please consider citing the following paper:

Robust index-based semantic plant/background segmentation for RGB-images
D Riehle, D Reiser, HW Griepentrog - Computers and Electronics in Agriculture, 2020

https://scholar.google.com/citations?view_op=view_citation&hl=de&user=KdxvfVsAAAAJ&citation_for_view=KdxvfVsAAAAJ:8k81kl-MbHgC





