//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "RoadConst_carApp.h"
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

using namespace veins;

Define_Module(veins::RoadConst_carApp);

void RoadConst_carApp::initialize(int stage) {
    veins::DemoBaseApplLayer::initialize(stage);
    WATCH(Use_CAM);
    if (stage == 0) {
        lasttime_m = simTime();
        lastcontrol_time_m = simTime();
        is_speed_slowdown = false;
        distance_edge = -1;
        is_there_construction = false;
        Road_constr_pos = Coord(-1, -1, 0.0);
        freeLaneID = -1;
        double Percentage = par("CAM_pecent").doubleValue();
        Use_CAM = par("Use_CAM").boolValue();

        if (Percentage >= 0.0 && Percentage <= 1 && Use_CAM) {
            if (bernoulli(Percentage) == 1) {
                Use_CAM = true;
                traciVehicle->setColor(TraCIColor(200, 100, 10, 255));
                findHost()->getDisplayString().setTagArg("i", 1, "yellow");

            } else {
                Use_CAM = false;
                findHost()->getDisplayString().setTagArg("i", 1, "white");
            }
        }

    }
}

void RoadConst_carApp::onWSM(BaseFrame1609_4 *frame) {
    EV << "RoadConst_carApp::onWSM car:" << getParentModule()->getIndex()
              << is_there_construction << Use_CAM;
    if (roadConstruction *message = dynamic_cast<roadConstruction*>(frame)) {
        EV << "onWSM Rx message dynamic_cast " << message->getDemoData();

        if (message->getTimestamp() > lasttime_m) {
            lasttime_m = message->getTimestamp();
            is_there_construction = true;
            EV << "onWSM Rx message " << message->getDemoData() << "d:"
                      << traci->getDistance(curPosition,
                              Coord(message->getPosx(), message->getPosy(),
                                      0.0), true);
            Road_constr_pos = Coord(message->getPosx(), message->getPosy(),
                    0.0);
            freeLaneID = message->getFreeLaneID();
            if (message->getTtl() > 0 && Use_CAM) {
                scheduleAt(simTime() + uniform(0, 0.3), message->dup());
            }

        }
    }
}
void RoadConst_carApp::handleSelfMsg(cMessage *msg) {
    EV << "RoadConst_carApp::handleSelfMsg Car" << getParentModule()->getIndex()
              << msg->isSelfMessage() << is_there_construction << Use_CAM;

    if (roadConstruction *message = dynamic_cast<roadConstruction*>(msg)) //beacon
    {

        EV << "handleSelfMsg Tx message beaconing Car"
                  << getParentModule()->getIndex() << " send_beacon "
                  << message->getPosx() << "," << message->getTimestamp()
                  << ">\n";
        message->setTtl(message->getTtl() - 1);
        populateWSM(message);
        sendDown(message->dup());
        delete (message);

    }

}

void RoadConst_carApp::handlePositionUpdate(cObject *obj) {
    curPosition = mobility->getPositionAt(simTime());
    EV << "carApp::PositionUpdate Id:" << getParentModule()->getIndex() << ","
              << is_there_construction;

    if (is_there_construction) {

        int distance = traci->getDistance(curPosition, Road_constr_pos, true);
        EV << "RoadConst_RsuApp Updatespeed dist:" << distance << " x:"
                  << Road_constr_pos.x << " y: " << Road_constr_pos.x;
        if ((lastcontrol_time_m+0.5) < simTime() && distance > 0) {
            lastcontrol_time_m = simTime();
            is_speed_slowdown = false;
        }
        double speed = mobility->getSpeed();
        EV << "RsuApp::pos dist" << distance << " speed: " << speed;
        if (distance < 0) {
            {
                findHost()->getDisplayString().setTagArg("i", 1, "blue");
                traciVehicle->setColor(TraCIColor(0, 0, 255, 255));
            }
            traciVehicle->setSpeed(-1);
            traciVehicle->setMinGap(1.5);

            is_there_construction = false;
            is_speed_slowdown = false;
            distance_edge = -1;
            Road_constr_pos = Coord(-1.0, -1.0, 0.0);
            freeLaneID = -1;

        } else if (is_speed_slowdown != true || distance_edge > distance) {
            findHost()->getDisplayString().setTagArg("i", 1, "green");

            slowdownCarv2(distance);

        }
    }

}


void RoadConst_carApp::slowdownCarv2(int distance) {
    //prepare some parameters
    is_speed_slowdown = true;
    distance_edge = -1;
    //get minGap and speed and neighbor
    traciVehicle->setColor(TraCIColor(50, 255, 50, 255));
    double slow_down_distance = 300;
    double gap = traciVehicle->getMinGap();
    double speed = traciVehicle->getSpeed();
    std::vector<TraCICommandInterface::Vehicle::neighbor> neighbor =
            traciVehicle->getNeighbors(1, 0, 0);
    if(!neighbor.empty() && freeLaneID == traciVehicle->getLaneIndex() && gap<10 ){
        traciVehicle->setMinGap(3);
    }else if( neighbor.empty() && freeLaneID == traciVehicle->getLaneIndex()) {
        traciVehicle->setMinGap(1.5);

    }
    if (freeLaneID != traciVehicle->getLaneIndex() && distance < 200) {

          traciVehicle->slowDown(0.5, distance /(speed+0.2));
    }

    if (freeLaneID != traciVehicle->getLaneIndex()) {
        //change lane to free lane
        traciVehicle->changeLane(freeLaneID, 5.0);
        traciVehicle->setColor(TraCIColor(50, 50, 50, 255));
        findHost()->getDisplayString().setTagArg("i", 1, "black");
    }


}
void RoadConst_carApp::slowdownCarv3(int distance) {
    //prepare some parameters
    is_speed_slowdown = true;
    distance_edge = -1;
    //get minGap and speed and neighbor
    if (freeLaneID == traciVehicle->getLaneIndex() ) {

        traciVehicle->setColor(TraCIColor(50, 255, 50, 255));
    }
    if (freeLaneID != traciVehicle->getLaneIndex() && distance < 200) {

        traciVehicle->slowDown(0.5, distance / 18.0);
    }

    if (freeLaneID != traciVehicle->getLaneIndex()&& distance < 1900-uniform(0,std::abs(distance-400))) {
        //change lane to free lane
        traciVehicle->changeLane(freeLaneID, 5.0);
        traciVehicle->setColor(TraCIColor(10, 10, 10, 255));
        findHost()->getDisplayString().setTagArg("i", 1, "black");
    }


}




