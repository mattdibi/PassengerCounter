#include "passenger.h"

Passenger::Passenger(int id, Point2f center, int age=0)
{
    pid = id;
    mc = center;
    age = age;

    tracks.push_back(Point(center.x,center.y));
}

void Passenger::updateCoords(Point2f newCenter)
{
    mc = newCenter;

    tracks.push_back(Point(newCenter.x,newCenter.y));
}