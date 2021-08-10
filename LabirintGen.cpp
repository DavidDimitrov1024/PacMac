#include "LabirintGen.h"

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int w, h;
char maze[1000][1000];

int randomNumGen(int range){
    int num = rand() % range;  
    return num;
}

bool isItWall(int y, int x){
    if(x >= w || x < 0){
        return true;
    }
    if(y >= h || y < 0){
        return true;
    }
    return false;
}

int nbCnt(int y, int x){
    int neighboursCnt = 0;

    if(!isItWall(y, x - 1)){
        if(maze[y][x - 1] != '#'){
            neighboursCnt++;
        } 
    }
    if(!isItWall(y, x + 1)){
        if(maze[y][x + 1] != '#'){
            neighboursCnt++;
        }
    }
    if(!isItWall(y - 1, x)){
        if(maze[y - 1][x] != '#'){
            neighboursCnt++;
        }
    }
    if(!isItWall(y + 1, x)){
        if(maze[y + 1][x] != '#'){
            neighboursCnt++;
        }
    }
     
    return neighboursCnt; 
}

bool isItValid(int y, int x){
    if(y >= h || y < 0 || x >= w || x < 0){
        return false;
    }
    if(nbCnt(y, x) >= 2){
        return false;
    }
    return true;
}

void dfs(int y, int x){
    if(x >= w || x < 0 || y >= h || y < 0) return;
    if(maze[y][x] != '#') return;
    if(!isItValid(y, x)){
        return;
    }
    maze[y][x] = '.';

    int direction = randomNumGen(3) - 1;
    dfs(y + direction, x + !direction);
    dfs(y - direction, x - !direction);
    dfs(y - !direction, x - direction);
    dfs(y + !direction, x + direction);
}

void mazeGen(int _h, int _w){
    srand(time(NULL));
    h = _h; w = _w / 2;
    for(int i = 0;i < h;++i){
        for(int x = 0;x < w;++x){
            maze[i][x] = '#';
        }
    } 
    dfs(0, 0);
    for (int i = 0; i < h; ++i)
    {
        for (int j = w - 1, k = w ; k < w * 2; ++k, --j)
        {
            //cout<<i<<" "<<j<<" "<<k<<endl;
            maze[i][k] = maze[i][j];
            cout<<maze[i][k];
        }
        std::cout<<'\n';
    }
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w * 2; ++j)
        {
            //cout<<i<<" "<<j<<" "<<k<<endl;
            cout<<maze[i][j];
        }
        std::cout<<'\n';
    }
}
