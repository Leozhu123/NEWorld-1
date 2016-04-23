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

#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include "Definitions.h"

namespace World
{
chunkid getChunkID(int x, int y, int z);
struct HeightMap
{
    int* array = nullptr;
    int size, size2;
    int originX, originZ;
    void setSize(int s);
    void create();
    void destroy();
    void move(int xd, int zd);
    void moveTo(int x, int z);
    int getHeight(int x, int z);
};
}

#endif
