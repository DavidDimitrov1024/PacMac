#pragma once

#include <iostream>
#include <conio.h>

enum direction {sit, up, down, left, right};

class chovek
{
    direction dir = direction::sit;
    int y;
    int x;
    char c;
    int field_height, field_width;
public:
    chovek()
    {

    }
    chovek(int y, int x, char c)
    {
        this -> y = y;
        this -> x = x;
        this -> c = c;
    }
    int get_y()
    {
        return this -> y;
    }
    int get_x()
    {
        return this -> x;
    }
    direction get_dir()
    {
        return this -> dir;
    }
    char get_c()
    {
        return this -> c;
    }
    void set_height(int height)
    {
        this -> field_height = height;
    }
    void set_width(int width)
    {
        this -> field_width = width;
    }
    void set_c(char c)
    {
        this -> c = c;
    }
    void set_y(int y)
    {
        this -> y = y;
    }
    void set_x(int x)
    {
        this -> x = x;
    }
    void set_dir(direction dir)
    {
        this -> dir = dir;
    }

    // proverqva dali geroq mozhe da se dvizhi v opredelena posoka
    bool legal_move(direction a)
    {
        switch (a)
        {
            case up:
                return this -> y - 1 > 0;
            case down:
                return this -> y + 1 < field_height;
            case left:
                return this -> x - 1 > 0;
            case right:
                return this -> x + 1 < field_width;
        }
        return true;
    }

    // shte se izpolzva v while kogato pechatame terena (shte proverqvame postoqnno
    // za promqna v posokata ot potrebitelq
    void make_move_geroi()
    {
        if (!kbhit()) return ;
        char next_move = getch();
        switch (next_move)
        {
            case 'w':
                dir = up;
                break;
            case 's':
                dir = down;
                break;
            case 'r':
                dir = right;
                break;
            case 'l':
                dir = left;
                break;
        }
    }

    // vikai tazi funkciq kogato promenqsh posokata
    void move(bool is_geroi)
    {
        if (is_geroi) make_move_geroi(); 
        switch (this -> dir)
        {
            case up:
                if (legal_move(up))
                    this -> y--;
                break;
            case down:
                if (legal_move(down))
                    this -> y++;
                break;
            case left:
                if (legal_move(left))
                    this -> x--;
                break;
            case right:
                if (legal_move(right))
                    this -> x++;
                break;
        }
    }
};

