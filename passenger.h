/**
    passenger
    Purpose: Tracking passengers
    
    @author Mattia Dal Ben
    @version 1.0 26/01/2017

*/

#ifndef PASSENGER_H
#define PASSENGER_H

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define MAX_TRACK_LENGTH 40

class Passenger {

  public:

    // Constructor
    Passenger(int id, Point center, int newAge);

    // Selectors
    int getPid() {return pid;};
    int getAge() {return age;};

    vector<Point> getTracks(){return tracks;};
    Scalar getTrackColor(){return trackColor;};

    Point getCurrentPoint(){return tracks[tracks.size()-1];};
    Point getLastPoint(){return tracks[tracks.size()-2];};

    // Methods
    void updateCoords(Point newCenter);
    void updateAge(){age++;return;};

  private:
    int pid;    // Passenger ID
    int age;    // Passenger age

    vector<Point> tracks;
    Scalar trackColor;

};

#endif
