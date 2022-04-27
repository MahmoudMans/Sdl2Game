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


#ifndef PLANE_H
#define PLANE_H

#include "utils.h"
#include "image.h"

struct Ball
{
    // Ball
    Image image1;



    // Direction
    Direction direction1;

    // Speed in pixel/second
    int speed1;

    // Margin
    int margin1;
};
typedef struct Ball Ball;


bool Ball_load(SDL_Renderer *renderer, Ball *Ball, const char *image1);
void Ball_destroy(Ball *Ball);

void Ball_setX(Ball *Ball, int x);
void Ball_setY(Ball *Ball, int y);
void Ball_setCoordinates(Ball *Ball, int x, int y);

void Ball_moveX(Ball *Ball, int x);
void Ball_moveY(Ball *Ball, int y);

void Ball_move(Ball *Ball, int screenWidth,int screenHeight, int framerate);

void Ball_setDirection(Ball *Ball, SDL_Keycode keycode);
void Ball_unsetDirection(Ball *Ball, SDL_Keycode keycode);

void Ball_render(SDL_Renderer *renderer, Ball *plane1);





#endif // PLANE_H
