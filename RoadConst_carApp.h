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

#pragma once

#include "veins/modules/application/ieee80211p/DemoBaseApplLayer.h"
#include "roadConstruction_m.h"

namespace veins {

class VEINS_API RoadConst_carApp : public DemoBaseApplLayer {
public:
    void initialize(int stage) override;

protected:
    Coord  Road_constr_pos;
    bool is_there_construction;
    int freeLaneID;
    simtime_t lasttime_m;
    bool Use_CAM;
    bool is_speed_slowdown;
    double distance_edge;
    double last_dsierd_speed;
    simtime_t lastcontrol_time_m;

protected:
    void onWSM(BaseFrame1609_4* wsm) override;
    void slowdownCar(int distance);
    void slowdownCarv1(int distance);
    void slowdownCarv2(int distance);
    void slowdownCarv3(int distance);

    void handleSelfMsg(cMessage* msg) override;
    void handlePositionUpdate(cObject* obj) override;
};

}
