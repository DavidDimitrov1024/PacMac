#ifndef LABIRINTGEN_H
#define LABIRINTGEN_H

#pragma once

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

extern int w, h;
extern char maze[1000][1000];

int randomNumGen(int range);

bool isItWall(int y, int x);

int nbCnt(int y, int x);

bool isItValid(int y, int x);

void dfs(int y, int x);

void mazeGen(int h, int w);

#endif //LABIRINTGEN_H