/**
    passenger
    Purpose: Tracking passengers
    
    @author Mattia Dal Ben
    @version 1.0 26/01/2017

*/

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define MAX_TRACK_LENGTH 40

class Passenger {

  public:

    // Constructor
    Passenger(int id, Point2f center, int age);

    // Selectors
    int getPid() {return pid;};

    Point2f getCenter() {return mc;};
    float getX(){return mc.x;};
    float getY(){return mc.y;};

    int getAge() {return age;};

    vector<Point> getTracks(){return tracks;};
    Scalar getTrackColor(){return trackColor;};

    Point getCurrentPoint(){return tracks[tracks.size()-1];};
    Point getLastPoint(){return tracks[tracks.size()-2];};

    // Methods
    void updateCoords(Point2f newCenter);
    void updateAge(){age++;return;};

  private:
    int pid;    // Passenger ID
    Point2f mc; // Mass center
    int age;    // Passenger age

    vector<Point> tracks;
    Scalar trackColor;

};