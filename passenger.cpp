#ifndef PASSENGER_CPP
#define PASSENGER_CPP

#include "passenger.h"

Passenger::Passenger(int id, Point center, int newAge = 0) {
    pid = id;
    age = newAge;

    tracks.push_back(center);
    trackColor = Scalar(rand() % 255, rand() % 255, rand() % 255);
}

void Passenger::updateCoords(Point newCenter) {
    tracks.push_back(newCenter);

    // If too many tracking points remove older points
    if(tracks.size() > MAX_TRACK_LENGTH)
        tracks.erase(tracks.begin());

    return;
}

#endif
