/**
    passenger
    Purpose: Tracking passengers
    
    @author Mattia Dal Ben
    @version 1.0 26/01/2017

*/

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define MAX_TRACK_DIM 50

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

    // Methods
    void updateCoords(Point2f newCenter);

  private:
    int pid;    // Passenger ID
    Point2f mc; // Mass center
    int age;    // Passenger age

    vector<Point> tracks;
    Scalar trackColor;

};