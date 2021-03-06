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

#ifndef WORLDGEN_H
#define WORLDGEN_H

#include "Definitions.h"
#include "RandGen.h"

class WorldGenerator
{
private:
    double m_perm[256];
    int m_seed;
    double m_NoiseScaleX, m_NoiseScaleZ;
    int m_WaterLevel;
    unique_ptr<RandGen> rng;

    // 禁止无参数创建WorldGenerator实例
    WorldGenerator();

    double Noise(int x, int y);

    double SmoothedNoise(int x, int y);

    double Interpolate(double a, double b, double x)
    {
        return a * (1.0 - x) + b * x;
    }

    double InterpolatedNoise(double x, double y);

    double PerlinNoise2D(double x, double y);

public:
    explicit WorldGenerator(int mapseed);

    int getHeight(int x, int y)
    {
        return (int)PerlinNoise2D(x / m_NoiseScaleX + 0.125 , y / m_NoiseScaleZ + 0.125) >> 2;
    }

    int getWaterLevel()
    {
        return m_WaterLevel;
    }

};

#endif
