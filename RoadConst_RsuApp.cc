//
// Copyright (C) 2016 David Eckhoff <david.eckhoff@fau.de>
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

#include "RoadConst_RsuApp.h"

#include <stdio.h>
#include <string.h>
#include <omnetpp.h>


using namespace veins;

Define_Module(veins::RoadConst_RsuApp);

RoadConst_RsuApp::~RoadConst_RsuApp()
{
    cancelAndDelete(sendBeacon);
    cancelAndDelete(R_Cons_message);
}

void RoadConst_RsuApp::initialize(int stage) {
    DemoBaseApplLayer::initialize(stage);
    findHost()->getDisplayString().setTagArg("i", 1, "red");

    EV_INFO<<"RoadConst_RsuApp::initialize"<<stage;
    if (stage == 0) {
        double pos_x = par("Reconstruction_pos_x").doubleValue();
        double pos_y = par("Reconstruction_pos_y").doubleValue();
        double lane = par("FreeLaneID").intValue();
        int ttl = par("TTL").intValue();
        use_RSU = par("use_RSU").boolValue();

        R_Cons_message = new roadConstruction();
        R_Cons_message->setDemoData("RSU_Road_construction_message");
        R_Cons_message->setPosx(pos_x);
        R_Cons_message->setPosy(pos_y);
        R_Cons_message->setFreeLaneID(lane);
        R_Cons_message->setTtl(ttl);

        //beaconing
        RSUbeaconInterval = par("RSUbeaconInterval");
        sendBeacon = new cMessage("start_BeaconEvt",10);
        EV_INFO<<"RoadConst_RsuApp::initialize x"<<R_Cons_message->getPosx()<<" y: "<<R_Cons_message->getPosy()<<beaconInterval;

        scheduleAt(simTime()+RSUbeaconInterval, sendBeacon);

    }
}

void RoadConst_RsuApp::handleSelfMsg(cMessage *msg) {
    if (msg->getKind() == 10 && use_RSU) {
        R_Cons_message->setTimestamp(simTime());
        populateWSM(R_Cons_message);
        sendDown(R_Cons_message->dup());
        EV << "sending a beacon: working zone at position: "<< R_Cons_message->getPosx()<< "m \n";
        scheduleAt(simTime()+RSUbeaconInterval, sendBeacon);

    }

}

