/*
 * Copyright (c) 2018 Amine Ben Hassouna <amine.benhassouna@gmail.com>
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any
 * person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the
 * Software without restriction, including without
 * limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice
 * shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
 * ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include "plane.h"

bool Ball_load(SDL_Renderer *renderer, Ball *Ball, const char *image1)
{
    // Load plane image
    if(!Image_load(renderer, &Ball->image1, image1))
    {
        return false;
    }



    return true;
}

void Ball_destroy(Ball *Ball)
{
    Image_destroy(&Ball->image1);

}

void Ball_setX(Ball *Ball, int x)
{
    // Plane x coordinate
    Ball->image1.rect.x = x;


}

void Ball_setY(Ball *Ball, int y)
{
    // Plane y coordinate
    Ball->image1.rect.y = y;


}

void Plane1_setCoordinates(Ball *Ball, int x, int y)
{
    Ball_setX(Ball, x);
    Ball_setY(Ball, y);
}

void Ball_moveX(Ball *Ball, int x)
{
    Ball_setX(Ball, Ball->image1.rect.x + x);
}

void Ball_moveY(Ball *Ball, int y)
{
    Ball_setY(Ball, Ball->image1.rect.y + y);
}

void Ball_setDirection(Ball *Ball, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_UP:
        Ball->direction1 &= ~DIRECTION_DOWN;
        Ball->direction1 |= DIRECTION_UP;
        break;

    case SDLK_DOWN:
        Ball->direction1 &= ~DIRECTION_UP;
        Ball->direction1 |= DIRECTION_DOWN;
        break;

    case SDLK_RIGHT:
        Ball->direction1 &= ~DIRECTION_LEFT;
        Ball->direction1 |= DIRECTION_RIGHT;
        break;

    case SDLK_LEFT:
        Ball->direction1 &= ~DIRECTION_RIGHT;
        Ball->direction1 |= DIRECTION_LEFT;
        break;
    }
}

void Ball_unsetDirection(Ball *Ball, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_UP:
        Ball->direction1 &= ~DIRECTION_UP;
        break;

    case SDLK_DOWN:
        Ball->direction1 &= ~DIRECTION_DOWN;
        break;

    case SDLK_RIGHT:
        Ball->direction1 &= ~DIRECTION_RIGHT;
        break;

    case SDLK_LEFT:
        Ball->direction1 &= ~DIRECTION_LEFT;
        break;
    }
}

void Ball_render(SDL_Renderer *renderer, Ball *Ball)
{

    // Render Ball
    Image_render(renderer, &Ball->image1);
}

void Ball_move(Ball *Ball, int screenWidth, int screenHeight, int framerate)
{
    int BallStep = Ball->speed1 / framerate;

    if( (Ball->direction1 & DIRECTION_UP)
            && Ball->image1.rect.y - BallStep >= Ball->margin1)
    {
        Ball_moveY(Ball, -BallStep);
    }
    else if( (Ball->direction1 & DIRECTION_DOWN)
             && Ball->image1.rect.y + Ball->image1.rect.h + BallStep <= screenHeight - Ball->margin1)
    {
        Ball_moveY(Ball, BallStep);
    }

    if( (Ball->direction1 & DIRECTION_RIGHT)
            && Ball->image1.rect.x + Ball->image1.rect.w + BallStep <= screenWidth - Ball->margin1)
    {
        Ball_moveX(Ball, BallStep);
    }
    else if( (Ball->direction1 & DIRECTION_LEFT)
             && Ball->image1.rect.x - BallStep >= Ball->margin1)
    {
        Ball_moveX(Ball, -BallStep);
    }
}
