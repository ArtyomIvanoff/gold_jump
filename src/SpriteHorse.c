/*
 this is the code of the Game Boy Sprite (player.mbr) that you see on the
 screen. It has all the required methods
*/
#include "Banks/SetAutoBank.h"

#include "Keys.h"
#include "Print.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

// first element of each array: the number of frames in this animation
// other elements: chosen tiles from horse.gbr file
const UINT8 anim_walk[] = {6, 0, 0, 1, 0, 0, 2};

void START(void) {}

void printPlayerPosition() {
  // for debug with Emulcious - run via VS Code launches (Debug)!
  DPrintf("x:%d y:%d \n  ", THIS->x, THIS->y);
}

void UPDATE(void) {
  UINT8 i;
  Sprite *spr;
  UINT8 step = 1;

  // hold A button to speed up
  if (KEY_PRESSED(J_A)) {
    step = step << 1;
  }

  /*
   delta_time (from ZGB ) is used for optimization:
  a) Will be 0 when the frame rate is ~60fps
  b) Will be 1 otherwise
  See
  https://zalods.blogspot.com/2016/07/game-boy-development-tips-and-tricks-ii.html
  */
  if (KEY_PRESSED(J_LEFT)) {
    TranslateSprite(THIS, -step << delta_time, 0);
    SetSpriteAnim(THIS, anim_walk, 10);
    printPlayerPosition();
  } else if (KEY_PRESSED(J_RIGHT)) {
    TranslateSprite(THIS, step << delta_time, 0);
    SetSpriteAnim(THIS, anim_walk, 10);
    printPlayerPosition();
  } else if (keys == 0) {
    SetSpriteAnim(THIS, anim_walk, 10);
  }
}

void DESTROY(void) {}