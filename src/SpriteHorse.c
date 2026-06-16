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
#include <stdbool.h>

// first element of each array: the number of frames in this animation
// other elements: chosen tiles from horse.gbr file
// tiles 0-2: horse runs with a rider
// tiles 3-5: horse runs alone
const UINT8 anim_run_with_rider[] = {6, 0, 0, 1, 0, 0, 2};

const UINT8 anim_run_alone[] = {6, 3, 3, 4, 3, 3, 5};

bool is_rider_jumped = false;

void START(void) {}

void printPlayerPosition() {
  // for debug with Emulcious - run via VS Code launches (Debug)!
  DPrintf("x:%d y:%d \n  ", THIS->x, THIS->y);
}

void UPDATE(void) {
  UINT8 step = 1;

  // hold A button to speed up
  if (KEY_PRESSED(J_A)) {
    step = step << 1;
  }

  /*
   delta_time (from ZGB) is used for optimization:
  a) Will be 0 when the frame rate is ~60fps
  b) Will be 1 otherwise
  See
  https://zalods.blogspot.com/2016/07/game-boy-development-tips-and-tricks-ii.html
  */
  if (KEY_PRESSED(J_LEFT)) {
    is_rider_jumped = true;
    TranslateSprite(THIS, -step << delta_time, 0);
    SetSpriteAnim(THIS, anim_run_alone, 10 * step);
    printPlayerPosition();
  } else if (KEY_PRESSED(J_RIGHT)) {
    is_rider_jumped = true;
    TranslateSprite(THIS, step << delta_time, 0);
    SetSpriteAnim(THIS, anim_run_alone, 10 * step);
    printPlayerPosition();
  } else if (keys == 0) {
    if (is_rider_jumped) {
      SetSpriteAnim(THIS, anim_run_alone, 10);
      return;
    }

     SetSpriteAnim(THIS, anim_run_with_rider, 10);
  }
}

void DESTROY(void) {}