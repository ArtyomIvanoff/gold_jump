/*
the current State that makes a basic initialization:
1) creates a sprite of type SPRITE_PLAYER and sets it as the scroll camera
2) Initializes the scroll (this will center the camera on the sprite set as
camera and fill the background) and adds collision with background tiles (see
map.gbm)
*/
#include "Banks/SetAutoBank.h"
#include "Scroll.h"
#include "SpriteManager.h"
#include "ZGBMain.h"

/*
Collision-able tiles are declared as an array of UINT8 ended with 0.
So the tile with index 1 (= top/bottom edges), = 2 (left/right edges) from tiles.gbr is collidable.
Pay attention to player.gbr.meta: it allows to remove space between player
sprite and background tiles: "-px 2 -py 0 -pw 12 -ph 16"
*/
UINT8 collision_tiles[] = {1, 2, 0};

IMPORT_MAP(map);

void START(void) {
  // spawn the horse below the screen center
  UINT16 initial_horse_x = SCREEN_WIDTH/2;
  UINT16 initial_horse_y = SCREEN_HEIGHT * 0.85;
  scroll_target = SpriteManagerAdd(SpriteHorse, initial_horse_x, initial_horse_y);
  InitScroll(BANK(map), &map, collision_tiles, 0);
}

void UPDATE(void) {}
