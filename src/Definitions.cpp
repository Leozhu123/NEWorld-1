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

#include "Definitions.h"

float FOVyNormal = 60.0f;       //视野角度
float mousemove = 0.2f;         //鼠标灵敏度
int ViewDistance = 8;           //视野距离
int CloudWidth = 10;            //云的宽度
int selectPrecision = 32;       //选择方块的精度
int selectDistance = 8;         //选择方块的距离
float walkspeed = 0.15f;        //前进速度
float runspeed = 0.3f;          //跑步速度
int MaxAirJumps = 3 - 1;        //空中N段连跳
bool SmoothLighting = true;     //平滑光照
bool NiceGrass = true;          //草地材质连接
bool MergeFace = false;         //合并面渲染
bool GUIScreenBlur = false;     //GUI背景模糊(非常慢）
int linelength = 10;            //跟F3的准星有关
int linedist = 30;              //跟F3的准星有关
bool ppistretch = false;        //试验功能，默认关闭
float skycolorR = 0.7f, skycolorG = 1.0f, skycolorB = 1.0f;         //天空颜色
float FOVyRunning = 8.0f;
float FOVyExt;
double stretch = 1.0f;          //ppi缩放比例（供gui绘制使用）
int Multisample = 0;            //多重采样抗锯齿
bool vsync = false;             //垂直同步
int gametime = 0;                //游戏时间 0~2592000

int windowwidth = 852;     //窗口宽度
int windowheight = 480;    //窗口宽度
bool gamebegin, gameexit, bagOpened;

//多人游戏
bool multiplayer = false;
string serverip;
unsigned short port = 30001;

TextureID BlockTextures, BlockTextures3D;
TextureID tex_select, tex_unselect, tex_title, tex_mainmenu[6];
TextureID DestroyImage[11];
TextureID DefaultSkin;

//线程
mutex_t Mutex;
thread_t updateThread;
double lastupdate, updateTimer;
double lastframe;
bool updateThreadRun, updateThreadPaused;

bool shouldGetScreenshot;
bool shouldGetThumbnail;
bool FirstUpdateThisFrame;
bool FirstFrameThisUpdate;
double SpeedupAnimTimer;
double TouchdownAnimTimer;
double screenshotAnimTimer;
double bagAnimTimer;
double bagAnimDuration = 0.5;

//OpenGL
int gl_version_major, gl_version_minor, gl_version_rev;
//GLFW
GLFWwindow* MainWindow;
GLFWcursor* MouseCursor;

//鼠标输入数据
double mx, my, mxl, myl;
int mw, mb, mbp, mbl, mwl;
double mxdelta, mydelta;
//键盘输入数据
string inputstr;

