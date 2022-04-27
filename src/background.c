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

#include "background.h"
#include "animation.h"
bool Background_load(SDL_Renderer *renderer, Background *background, const char *file)
{
    return Image_load(renderer, &background->image, file);
}

void Background_destroy(Background *background)
{
    Image_destroy(&background->image);
}

void Background_move(Background *background, int framerate, Animation* animation )
{

    int step = background->speed / framerate;


    if( (background->direction & DIRECTION_RIGHT)
           )
    {
        background->image.rect.x -= step;
        if(background->image.rect.x < animation->width - background->image.rect.w ) {
            background->image.rect.x = animation->width - background->image.rect.w;
        }



    }
    else if( (background->direction & DIRECTION_LEFT)
       )
    {
         background->image.rect.x += step;
         if(background->image.rect.x > 0){
             background ->image.rect.x =    0;
         }
    }
    SDL_Rect pixel_position;
    pixel_position.x= animation->Ball.image1.rect.x + animation->Ball.image1.rect.w;
    pixel_position.y= animation->Ball.image1.rect.y + animation->Ball.image1.rect.h;
    pixel_position.w=1;
    pixel_position.h=1;
    int pitch = sizeof(Uint32);

    Uint32 *pixels = malloc(pitch);
        SDL_RenderReadPixels(animation->renderer, &pixel_position, SDL_PIXELFORMAT_RGBA8888, pixels,pitch);
        SDL_PixelFormat*format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
        uint8_t r,g,b;

        SDL_GetRGB(*pixels,format,&r,&g,&b );

        printf("%d (%d,%d,%d)\n",*pixels,r,g,b);
       fflush(stdout);
       if(*pixels ==39287 || *pixels==66303){

       }
       if(*pixels == 396287){
            animation->gameover=true;
        }
       if(*pixels == 66303){
            animation->gameover=true;
        }
       if(*pixels == 16843263){
            animation->gameover=true;
        }

       if(*pixels == 461823){
            animation->gameover=true;
        }
       if(*pixels == -1183164417){
                   animation->gameover=true;
               }
       if(*pixels == 1207959807){
                   animation->gameover=true;
               }
       if(*pixels == -149607937){
                   animation->gameover=true;
       }

                   if(*pixels == 16779519){
                               animation->gameover=true;
                           }
                   if(*pixels == 528127){
                               animation->gameover=true;
                           }
                   if(*pixels == -1824763905){
                               animation->gameover=true;
                           }
                   if(*pixels == 67839){
                               animation->gameover=true;
                           }
                   if(*pixels == 332031){
                               animation->gameover=true;
                           }
                   if(*pixels == -1010580481){
                               animation->gameover=true;
                           }

                   if(*pixels == -1529222657){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1656465665){
                               animation->gameover=true;
                           }
                   if(*pixels ==-266722049 ){
                               animation->gameover=true;
                           }
                   if(*pixels ==255 ){
                               animation->gameover=true;
                           }
                   if(*pixels ==591871 ){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1763907329 ){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1763907329 ){
                               animation->gameover=true;
                           }
                   if(*pixels == 329215 ){
                               animation->gameover=true;
                           }
                   if(*pixels == -1462444545 ){
                               animation->gameover=true;
                           }

                   if(*pixels == -1512774401 ){
                               animation->gameover=true;
                           }

                   if(*pixels == -1010711297 ){
                               animation->gameover=true;
                           }
                   if(*pixels == 100663551 ){
                               animation->gameover=true;
                           }

                   if(*pixels == -1412177921 ){
                               animation->gameover=true;
                           }
                   if(*pixels == -1630081537 ){
                               animation->gameover=true;
                           }

                   if(*pixels == -1646793729  ){
                               animation->gameover=true;
                           }
                   if(*pixels == -1613369857  ){
                               animation->gameover=true;
                           }
                   if(*pixels == 67110143  ){
                               animation->gameover=true;
                           }
                   if(*pixels == 262399  ){
                               animation->gameover=true;
                           }
                   if(*pixels == 16777983  ){
                               animation->gameover=true;
                           }
                   if(*pixels == 327935  ){
                               animation->gameover=true;
                           }
                   if(*pixels == 131327  ){
                               animation->gameover=true;
                           }
                   if(*pixels == -1546526465  ){
                               animation->gameover=true;
                           }
                   if(*pixels == -1027554305  ){
                               animation->gameover=true;
                           }
                   if(*pixels == -977025281  ){
                               animation->gameover=true;
                           }
                   if(*pixels == 134217983  ){
                               animation->gameover=true;
                           }

                   if(*pixels == 255  ){
                               animation->gameover=true;
                           }

                   if(*pixels == -969788673  ){
                               animation->gameover=true;
                           }
                   if(*pixels == -534633217 ){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1797330433 ){
                               animation->gameover=true;
                           }
                   if(*pixels ==100663551 ){
                               animation->gameover=true;
                           }
                   if(*pixels ==-718786817){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1010378753){
                               animation->gameover=true;
                           }
                   if(*pixels ==-551280641){
                               animation->gameover=true;
                           }
                   if(*pixels ==-149414401){
                               animation->gameover=true;
                           }
                   if(*pixels ==-300210945){
                               animation->gameover=true;
                           }
                   if(*pixels ==-316988161){
                               animation->gameover=true;
                           }
                   if(*pixels ==-383900417){
                               animation->gameover=true;
                           }
                   if(*pixels ==-602002689){
                               animation->gameover=true;
                           }
                   if(*pixels ==-350413313){
                               animation->gameover=true;
                           }
                   if(*pixels ==-417454337){
                               animation->gameover=true;
                           }
                   if(*pixels ==-300211457){
                               animation->gameover=true;
                           }
                   if(*pixels ==-316987649){
                               animation->gameover=true;
                           }
                   if(*pixels ==-316987137){
                               animation->gameover=true;
                           }
                   if(*pixels ==-183229697){
                               animation->gameover=true;
                           }
                   if(*pixels ==-669045249){
                               animation->gameover=true;
                           }
                   if(*pixels ==-943603201){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1027356673){
                               animation->gameover=true;
                           }
                   if(*pixels ==167772415){
                               animation->gameover=true;
                           }
                   if(*pixels ==-316859905){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1847660289){
                               animation->gameover=true;
                           }

                   if(*pixels ==-1629888513 ){
                               animation->gameover=true;
                           }
                   if(*pixels ==33620223){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1010580993){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1060846593){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1060846081 ){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1027357185  ){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1027292161  ){
                               animation->gameover=true;
                           }
                   if(*pixels ==67174655){
                               animation->gameover=true;
                           }

                   if(*pixels ==-1010579969){
                               animation->gameover=true;
                           }
                   if(*pixels ==553648383){
                               animation->gameover=true;
                           }
                   if(*pixels ==-1663893505){
                               animation->win=true;
                           }
                   if(*pixels ==961854975){
                               animation->win=true;
                           }
                   if(*pixels ==1078383359){
                               animation->win=true;
                           }
                   if(*pixels ==-303238401){
                               animation->win=true;
                           }
                   if(*pixels ==-303109633){
                               animation->win=true;
                           }
                   if(*pixels ==-774569985){
                               animation->win=true;
                           }
                   if(*pixels ==977913599){
                               animation->win=true;
                           }
                   if(*pixels ==1112254207){
                               animation->win=true;
                           }
                   if(*pixels ==-253039873){
                               animation->win=true;
                           }
                   if(*pixels ==-638060033){
                               animation->win=true;
                           }
                   if(*pixels ==-993868801){
                               animation->gameover=true;
                           }

                   if(*pixels ==1095289599){
                               animation->win=true;
                           }
                   if(*pixels ==1095289599){
                               animation->win=true;
                           }
                   if(*pixels ==-134217729 ){
                               animation->win=true;
                           }
                   if(*pixels ==-235933441 ){
                               animation->win=true;
                           }
                   if(*pixels ==-262145 ){
                               animation->win=true;
                           }
                   if(*pixels ==-269618945 ){
                               animation->win=true;
                           }
                   if(*pixels ==-1793 ){
                               animation->win=true;
                           }
                   if(*pixels ==-198657  ){
                               animation->win=true;
                           }
                   if(*pixels ==-83951617  ){
                               animation->win=true;
                           }

                   if(*pixels ==-1546329345  ){
                               animation->win=true;
                           }

                   if(*pixels ==-1166387457  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1283694849  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==67109119  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==131583  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==328703  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==197375  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-943602689  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1696996609  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1496189953  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1596658433  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-792407809  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-266326273  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-350281473  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-383965441  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-501470721  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-316923137  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-266721537  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-199744769  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-501208065  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-233233665  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-300275457  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1489418497  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1120784897  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==463359  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1278547457  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-367317505  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-38942465  ){
                       animation->gameover=true;
                   }

                   if(*pixels ==-1562974977  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-233295361  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-333438977  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1589818881  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-300211713  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1439218433  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==767  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1194402561  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1656927233  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-233233153  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-350348801  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-366729729  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1925099777  ){
                       animation->gameover=true;
                   }

                   if(*pixels ==-1245060353  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1763907841  ){
                       animation->gameover=true;
                   }

                   if(*pixels ==-1847663361  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1747260417  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1010711809  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==528383  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1663375361  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1646596865  ){
                       animation->gameover=true;
                   }
                   if(*pixels ==-1814173441  ){
                       animation->gameover=true;
                   }

                   if(*pixels ==-16777217 ){
                               animation->win=true;
                           }
                   if(*pixels ==35859199 ){
                               animation->win=true;
                           }
                   if(*pixels ==-1613696769 ){
                               animation->win=true;
                           }

                   if(*pixels ==-1646859777 ){
                               animation->win=true;
                           }
                   if(*pixels ==-1680218369 ){
                               animation->win=true;
                           }
                   if(*pixels ==-1512835585 ){
                               animation->win=true;
                           }
                   if(*pixels ==-1596330753 ){
                               animation->win=true;
                           }
                   if(*pixels ==1061734399 ){
                               animation->win=true;
                           }
                   if(*pixels ==1044894463 ){
                               animation->win=true;
                           }
                   if(*pixels ==1061737983 ){
                               animation->win=true;
                           }
                   if(*pixels ==1061801471 ){
                               animation->win=true;
                           }
                   if(*pixels ==1095219711 ){
                               animation->win=true;
                           }
                   if(*pixels ==1061671167 ){
                               animation->win=true;
                           }
                   if(*pixels ==-1630404609 ){
                               animation->win=true;
                           }
                   if(*pixels ==1078318591 ){
                               animation->win=true;
                           }
                   if(*pixels ==-1848187393 ){
                               animation->win=true;
                           }
                   if(*pixels ==1229825791 ){
                               animation->win=true;
                           }
                   if(*pixels ==1229439743 ){
                               animation->win=true;
                           }
                   if(*pixels ==-117440513 ){
                               animation->win=true;
                           }
                   if(*pixels ==1145626623 ){
                       animation->win=true;
                   }
                   if(*pixels ==-1613627393 ){
                       animation->win=true;
                   }
                   if(*pixels ==-1763844097 ){
                       animation->win=true;
                   }
                   free(pixels);
}
void Background_setDirection(Background *background, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_UP:
        background->direction &= ~DIRECTION_DOWN;
        background->direction |= DIRECTION_UP;
        break;

    case SDLK_DOWN:
        background->direction &= ~DIRECTION_UP;
        background->direction |= DIRECTION_DOWN;
        break;

    case SDLK_d:
        background->direction &= ~DIRECTION_LEFT;
        background->direction |= DIRECTION_RIGHT;
        break;

    case SDLK_q:
        background->direction &= ~DIRECTION_RIGHT;
        background->direction |= DIRECTION_LEFT;
        break;
    }
}


void Background_unsetDirection(Background *background, SDL_Keycode keycode)
{
    switch (keycode)
    {
    case SDLK_UP:
        background->direction &= ~DIRECTION_UP;
        break;

    case SDLK_DOWN:
        background->direction &= ~DIRECTION_DOWN;
        break;

    case SDLK_RIGHT:
        background->direction &= ~DIRECTION_RIGHT;
        break;

    case SDLK_LEFT:
        background->direction &= ~DIRECTION_LEFT;
        break;
    }
}
void Background_render(SDL_Renderer *renderer, Background *background, int width, int height)
{
    // Unused width
    (void) width;

    SDL_Rect crop = background->image.rect;
    crop.x = - background->image.rect.x;
     crop.w = width;


    SDL_Point pos = { 0, 0 };
    Image_renderCrop(renderer, &background->image, &crop, &pos);


}
