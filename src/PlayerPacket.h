/*
 * NEWorld: An free game with similar rules to Minecraft.
 * Copyright (C) 2016 NEWorld Team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PLAYERPACKET_H
#define PLAYERPACKET_H

enum PlayerPackets
{
    PLAYER_PACKET_SEND,
    PLAYER_PACKET_REQ
};

struct PlayerPacket
{
    double x, y, z;
    double lookupdown, heading;
    char name[32];
    int onlineID;
    int skinID;
};

#endif
