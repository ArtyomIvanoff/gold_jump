/*
The Main file for your project,
all states and sprites declarations must be done in this file
*/
#ifndef ZGBMAIN_H
#define ZGBMAIN_H

#define STATES                                                                 \
  _STATE(StateGame)                                                            \
  STATE_DEF_END

#define SPRITES                                                                \
  _SPRITE_DMG(SpriteHorse, horse)                                            \
  SPRITE_DEF_END

#include "ZGBMain_Init.h"

#endif