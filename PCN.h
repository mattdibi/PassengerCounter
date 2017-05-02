/**
    PCN (Passenger CouNter)
    Purpose: Creating a computer vision system that counts passengers entering/exiting a door in a transportation environment
             using background subtraction.

    @author Mattia Dal Ben
    @version 1.0 21/03/2017

*/

#ifndef PCN_H
#define PCN_H

// #define ReliaGate

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include <X11/Xlib.h>
#include <opencv2/opencv.hpp>

#include "passenger.cpp"

using namespace std;
using namespace cv;
using namespace std::chrono;

// Camera settings
#define IMAGEWIDTH   640
#define IMAGEHEIGHT  480
#define FRAMERATE     30

// Constants
#define MAXRGBVAL 255
#define NODATA 0

#define RED   Scalar(0,0,255)
#define BLUE  Scalar(255,0,0)
#define GREEN Scalar(0,255,0)
#define WHITE Scalar(255,255,255)
#define BLACK Scalar(0,0,0)

// Calibration starting values
#define BACKGROUN_SUB_THRESHOLD 50
#define LEARNINGRATE 10
#define THRESHOLD 100
#define ERODE_AMOUNT 3
#define DILATE_AMOUNT 6
#define BLUR_KSIZE 10           // [matrix size]
#define AREA_MIN 10000          // [pixels^2]: This depends on the camera distance from the passengers
#define X_NEAR 40              // [pixels]
#define Y_NEAR 90              // [pixels]
#define MAX_PASSENGER_AGE 2     // [seconds]

#define MAX_1PASS_AREA 30000    // [pixels^2]
#define MAX_2PASS_AREA 60000    // [pixels^2]

class PCN {

  public:

    // Constructor
    PCN(int device);
    ~PCN() { thread_.join(); }

    // Selectors
    string getThreadID(){return threadID;};

    int getCountIn(){return cnt_in;};
    int getCountOut(){return cnt_out;};

    // Setters
    void setCalibration(bool value) {calibrationOn = value; return;};
    void setDisplayColor(bool value) {displayColor = value; return;};
    void setDisplayBacksub(bool value) {displayBacksub = value; return;};
    void setDisplayDenoise(bool value) {displayDenoise = value; return;};
    void setSaveVideo(bool value) {saveVideo = value; return;};

    // Methods
    void start();
    void count();
    void resetCounters(){cnt_in = 0; cnt_out = 0; return;};
    void stop(){halt = true;};

    void toggleCalibration();
    void toggleDisplayColor();
    void toggleDisplayBacksub();
    void toggleDisplayDenoise();

  private:
    VideoCapture cap;
    Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor

    std::thread thread_;
    string threadID;

    bool halt = false;

    // Passenger counters
    int cnt_in  = 0;
    int cnt_out = 0;

    // Passengers tracker
    int pid = 0;
    vector<Passenger> passengers;

    // Options
    bool calibrationOn = false;
    bool displayColor = false;
    bool displayBacksub = false;
    bool displayDenoise = false;
    bool saveVideo = false;
};

#endif
