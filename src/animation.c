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
#include "animation.h"


bool Animation_start(SDL_Renderer *renderer, int width, int height)
{
    Animation animation = {0};
    animation.renderer  = renderer;
    animation.width     = width;
    animation.height    = height;
    animation.gameover =false;
    animation.win =false;
    // Loat animation assets
    if(!Animation_load(&animation))
        return false;


    // Initialize framerate manager : 30 FPS
    FPSmanager fpsmanager;
    SDL_initFramerate(&fpsmanager);
    SDL_setFramerate(&fpsmanager, 60);

    // Initialize start frame
    int frame = SDL_getFramecount(&fpsmanager);


    // Event loop exit flag
    bool quit = false;

    // Event loop
    while(!quit && !animation.gameover && !animation.win)
    {
        SDL_Event e;

        // Get available event
        while(SDL_PollEvent(&e))
        {
            // Handle animation events
            quit = Animation_handleEvent(&animation, &e);
        }

        // Each new frame
        int currentFrame = SDL_getFramecount(&fpsmanager);
        if(currentFrame != frame)
        {
            // Update animation frame
            Animation_update(&animation, SDL_getFramerate(&fpsmanager));

            currentFrame = frame;
        }

        // Render animation
        Animation_render(&animation);

        // Update screen
        SDL_RenderPresent(renderer);

        // Delay
        SDL_framerateDelay(&fpsmanager);
    }

    Animation_destroy(&animation);

    return true;
}
void Animation_text_gameover(Animation *animation){
    SDL_Color textColor           = { 0x00, 0x00, 0x00, 0xFF };
    SDL_Color textBackgroundColor = { 0xFF, 0xFF, 0xFF, 0xFF };



    SDL_Surface *textSurface = TTF_RenderText_Shaded(animation->font, "Game Over", textColor, textBackgroundColor);
    if(!textSurface) {
        printf("Unable to render text surface!\n"
               "SDL2_ttf Error: %s\n", TTF_GetError());
    } else {
        // Create texture from surface pixels
        animation->text = SDL_CreateTextureFromSurface(animation->renderer, textSurface);
        if(!animation->text) {
            printf("Unable to create texture from rendered text!\n"
                   "SDL2 Error: %s\n", SDL_GetError());

        }

        // Get text dimensions
        animation->textRect.w = textSurface->w;
        animation->textRect.h = textSurface->h;

        SDL_FreeSurface(textSurface);
    }
     SDL_RenderCopy(animation->renderer, animation->text, NULL, &animation->textRect);
    animation->textRect.x=0;
    animation->textRect.y=100;



}
void Animation_text_play(Animation *animation){
    SDL_Color textColor           = { 0x00, 0x00, 0x00, 0xFF };
    SDL_Color textBackgroundColor = { 0xFF, 0xFF, 0xFF, 0xFF };



    SDL_Surface *textSurface = TTF_RenderText_Shaded(animation->font, "push  d to move the screen", textColor, textBackgroundColor);
    if(!textSurface) {
        printf("Unable to render text surface!\n"
               "SDL2_ttf Error: %s\n", TTF_GetError());
    } else {
        // Create texture from surface pixels
        animation->text = SDL_CreateTextureFromSurface(animation->renderer, textSurface);
        if(!animation->text) {
            printf("Unable to create texture from rendered text!\n"
                   "SDL2 Error: %s\n", SDL_GetError());

        }

        // Get text dimensions
        animation->textRect.w = textSurface->w;
        animation->textRect.h = textSurface->h;

        SDL_FreeSurface(textSurface);
    }
     SDL_RenderCopy(animation->renderer, animation->text, NULL, &animation->textRect);
    animation->textRect.x=0;
    animation->textRect.y=100;



}

void Animation_text_win(Animation *animation){
    SDL_Color textColor           = { 0x00, 0x00, 0x00, 0xFF };
    SDL_Color textBackgroundColor = { 0xFF, 0xFF, 0xFF, 0xFF };



    SDL_Surface *textSurface = TTF_RenderText_Shaded(animation->font, "You WIN", textColor, textBackgroundColor);
    if(!textSurface) {
        printf("Unable to render text surface!\n"
               "SDL2_ttf Error: %s\n", TTF_GetError());
    } else {
        // Create texture from surface pixels
        animation->text = SDL_CreateTextureFromSurface(animation->renderer, textSurface);
        if(!animation->text) {
            printf("Unable to create texture from rendered text!\n"
                   "SDL2 Error: %s\n", SDL_GetError());

        }

        // Get text dimensions
        animation->textRect.w = textSurface->w;
        animation->textRect.h = textSurface->h;

        SDL_FreeSurface(textSurface);
    }
     SDL_RenderCopy(animation->renderer, animation->text, NULL, &animation->textRect);
    animation->textRect.x=0;
    animation->textRect.y=100;



}
bool Animation_load(Animation *animation)
{
    // Load the ocean image
    if(!Background_load(animation->renderer, &animation->background, OCEAN_IMG))
        return false;
    animation->background.image.rect.x=0;
    animation->background.image.rect.y=0;
    // Background move direction
    animation->background.direction = DIRECTION_STOP;

    // Background speed in pixel/second
    animation->background.speed = OCEAN_SPEED;

    if(!Ball_load(animation->renderer, &animation->Ball, PLANE_IMG))
    {
        Background_destroy(&animation->background);
        return false;
    }

    animation->Ball.margin1 = PLANE_MARGIN;


    // Set Ball initial position
  Ball_setX(&animation->Ball, 10); // Horiz. center
    Ball_setY(&animation->Ball, animation->height - animation->Ball.image1.rect.h - 90);

    // Plane move direction
    animation->Ball.direction1 = DIRECTION_STOP;

    // Plane move speed in pixel/second
    animation->Ball.speed1 = PLANE_SPEED;

        animation->font=TTF_OpenFont(FONT_PATH, 40);
        if(!animation->font) {
            printf("Unable to load font: '%s'!\n"
                   "SDL2_ttf Error: %s\n", FONT_PATH, TTF_GetError());
            return 0;
        }



    return true;
}

void Animation_destroy(Animation *animation)
{
    Ball_destroy(&animation->Ball);

    Background_destroy(&animation->background);
}


bool Animation_handleEvent(Animation *animation, SDL_Event *e)
{
    bool quit = false;

    // User requests quit
    if(e->type == SDL_QUIT)
    {
        quit = true;
    }
    else if(e->type == SDL_KEYDOWN)
    {
        switch (e->key.keysym.sym)
        {
        case SDLK_ESCAPE:
            quit = true;
            break;

        case SDLK_UP:
        case SDLK_DOWN:
        case SDLK_RIGHT:
        case SDLK_LEFT:
            Ball_setDirection(&animation->Ball, e->key.keysym.sym);
break;
        case SDLK_d:
        case SDLK_q:
            Background_setDirection(&animation->background, e->key.keysym.sym);

            break;
        case SDLK_z:
        case SDLK_s:
            Ball_unsetDirection(&animation->Ball, e->key.keysym.sym);
        break;
        case SDLK_w:
         case SDLK_p:
             Background_unsetDirection(&animation->background, e->key.keysym.sym);
            break;
        }
    }
    else if(e->type == SDL_KEYUP)
    {
        switch (e->key.keysym.sym)
        {
        case SDLK_UP:
        case SDLK_DOWN:
        case SDLK_RIGHT:
        case SDLK_LEFT:
           Ball_unsetDirection(&animation->Ball, e->key.keysym.sym);

            break;
        case SDLK_z:
        case SDLK_s:
        case SDLK_d:
        case SDLK_q:
            Ball_unsetDirection(&animation->Ball, e->key.keysym.sym);

            break;
        }
    }

    return quit;
}

void Animation_update(Animation *animation, int framerate)
{
    // Move ocean
    Background_move(&animation->background, framerate, animation);

    // Move plane
    Ball_move(&animation->Ball, animation->width, animation->height, framerate);

}

void Animation_render(Animation *animation)
{
    // Render ocean
   Background_render(animation->renderer, &animation->background, animation->width, animation->height);

    // Render plane
    Ball_render(animation->renderer, &animation->Ball);
    if(animation->gameover){
        Animation_text_gameover(animation);
    }

    if(animation->win){
        Animation_text_win(animation);
    }

}
