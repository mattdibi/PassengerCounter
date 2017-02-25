#include "passenger.h"

Passenger::Passenger(int id, Point2f center, int age=0)
{
    pid = id;
    mc = center;
    age = age;

    tracks.push_back(Point(center.x,center.y));
    trackColor = Scalar(rand() % 255, rand() % 255, rand() % 255);
}

void Passenger::updateCoords(Point2f newCenter)
{
    mc = newCenter;

    tracks.push_back(Point(newCenter.x,newCenter.y));

    // If too many tracking points remove older points
    if(tracks.size() > MAX_TRACK_LENGTH)
    {
        tracks.erase(tracks.begin());
    }

    // Reset age
    // If the object is being tracked it means its active we don't want it to disappear
    age = 0;

    return;
}
