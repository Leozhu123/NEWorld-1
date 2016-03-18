#include "stdinclude.h"
#include "Typedefs.h"
#include "Definitions.h"
#include "API.h"
#include "BlockFuncs.h"
#include "Blocks.h"
#include "World.h"

bool GrassBUF(Blocks::BUDDP * args)
{
    long long bx = args->cx;
    long long by = args->cy;
    long long bz = args->cz;
    block b;
    b = World::getblock(bx, by + 1, bz);
    if (b.ID != Blocks::AIR)
    {
        *(args->slf)=block(Blocks::DIRT);
        return true;
    }
    else
    {
        return false;
    }

}

bool WaterBUF(Blocks::BUDDP * args)
{
    if (args->slf->Data81==1)
    {
        long long bx = args->cx;
        long long by = args->cy;
        long long bz = args->cz;
        bool set = false;
        block b;
        const int vec[][] = { { -1, 0, 0 }, { 1, 0, 0 }, { 0, -1, 0 }, { 0, 0, -1 }, { 0, 0, 1 } };
        for (int i = 0; i < 5; i++)
        {
            b = World::getblock(bx + vec[i][0], by + vec[i][1], bz + vec[i][2]);
            if (b.ID == Blocks::AIR || ((b.ID == Blocks::WATER) && (b.Data81 == 0)))
            {
                World::setblock(bx + vec[i][0], by + vec[i][1], bz + vec[i][2], block(Blocks::WATER, 1, 255));
                set = true;
            }
        }
        if (set) return true;
    }
    else if (args->slf->Data81 == 0)
    {
        long long bx = args->cx;
        long long by = args->cy;
        long long bz = args->cz;
        bool set = false, u = false;
        block b = World::getblock(bx, by - 1, bz);
        if (b.ID == Blocks::WATER && b.Data81 == 0)
        {
            int s = b.Data82 + args->slf->Data82;
            if (s < 255)
            {
                World::setblock(bx, by - 1, bz, block(Blocks::WATER, 0, s));
                return true;
            }
            else
            {
                World::setblock(bx, by - 1, bz, block(Blocks::WATER, 0, 255));
                args->slf->Data82 = s - 255;
                u = true;
            }

            const int vec[][] = { { -1, 0, 0 }, { 1, 0, 0 }, { 0, 0, -1 }, { 0, 0, 1 } };
            bool pos[]= { false, false, false, false };
            int total = args->slf->Data82;

            for (int i = 0; i < 4; i++)
            {
                b = World::getblock(bx + vec[i][0], by + vec[i][1], bz + vec[i][2]);
                if (b.ID == Blocks::WATER && b.Data81 == 0 && (b.Data82 < args->slf->Data82 - 2))
                {
                    pos[i] = u = true;
                    total += b.Data82;
                }
            }
            total /= pos[0] + pos[1] + pos[2] + pos[3];
            for (int i = 0; i < 4; i++)
                if (pos[i])
                    World::setblock(bx + vec[i][0], by + vec[i][1], bz + vec[i][2], block(Blocks::WATER, 0, total));
            if (u)
                return u;
        }
    }
    else
    {
        return false;
    }
}
