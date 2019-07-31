#include "main_window.h"
#include <QApplication>
#include <QDesktopWidget>

/* Löschen
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <vector>
#include <glob.h>
#include <fstream>

using namespace cv;
using namespace std;

ofstream csv_file;

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

void printProgress(double percentage)
{
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf ("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush (stdout);
}
*/


int main(int argc, char **argv)
{

    QApplication a(argc, argv);
    main_window w;

    w.adjustSize();
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());

    w.show();

    return a.exec();
}
