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

#include "WorldGen.h"
#include "Definitions.h"

WorldGenerator::WorldGenerator(int mapseed)
{
    rng = unique_ptr<RandGen>(new MersenneRandGen);
    m_seed = mapseed;
    for (int i = 0; i < 256; i++)
        m_perm[i] = rng->get_double_ranged(0.0, 256.0);
    m_NoiseScaleX = m_NoiseScaleZ = 64;
    m_WaterLevel = 30;
}

double WorldGenerator::Noise(int x, int y)
{
    long long xx = x + y * 13258953287;
    xx = (xx >> 13) ^ xx;
    return ((xx*(xx*xx * 15731 + 789221) + 1376312589) & 0x7fffffff) / 16777216.0;
}

double WorldGenerator::SmoothedNoise(int x, int y)
{
    double corners, sides, center;
    corners = (Noise(x - 1, y - 1) + Noise(x + 1, y - 1) + Noise(x - 1, y + 1) + Noise(x + 1, y + 1)) / 8.0;
    sides = (Noise(x - 1, y) + Noise(x + 1, y) + Noise(x, y - 1) + Noise(x, y + 1)) / 4.0;
    center = Noise(x, y);
    return corners + sides + center;
}

double WorldGenerator::InterpolatedNoise(double x, double y)
{
    int int_X, int_Y;
    double fractional_X, fractional_Y, v1, v2, v3, v4, i1, i2;
    int_X = (int)floor(x);
    fractional_X = x - int_X;
    int_Y = (int)floor(y);
    fractional_Y = y - int_Y;
    v1 = Noise(int_X, int_Y);
    v2 = Noise(int_X + 1, int_Y);
    v3 = Noise(int_X, int_Y + 1);
    v4 = Noise(int_X + 1, int_Y + 1);
    i1 = Interpolate(v1, v2, fractional_X);
    i2 = Interpolate(v3, v4, fractional_X);
    return Interpolate(i1, i2, fractional_Y);
}

double WorldGenerator::PerlinNoise2D(double x, double y)
{
    double total = 0.0, frequency = 1.0, amplitude = 1.0;
    for (int i = 0; i <= 4; i++)
    {
        total += InterpolatedNoise(x * frequency, y * frequency) * amplitude;
        frequency *= 2.0;
        amplitude /= 2.0;
    }
    return total;
}

