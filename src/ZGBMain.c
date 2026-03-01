/*
This containts the default method (GetTileReplacement) for replacing tiles
when adding them to the map,
and the initial state that should be launched
*/
#include "ZGBMain.h"
#include "Math.h"

UINT8 next_state = StateGame;

/*
This function is called for any tile that is placed in the background.

1) It receives a UINT8* pointing to the tile that will be placed
2) It must return an Sprite_Type or 255 to spawn nothing.
3) It must assign on tile the tile index that should go in the background
(usually the same that was passed on tile_ptr except when spawning an enemy)

This default function will spawn and enemy of type 0 when the tile is 255,
and enemy of type 1 when the tile is 254,
and enemy of type 2 when the tile is 253... and so on.
In our case: as "enemy" is declared in ZGBMain.h as second (index == 1),
then every place of 254th tile (= 255 - 1) of map.gbm will be replaced with sprite from "enemy.gbr"
 */
UINT8 GetTileReplacement(UINT8 *tile_ptr, UINT8 *tile) {
  if (current_state == StateGame) {
    uint8_t from_tile_ind = 255 - (uint16_t)*tile_ptr;
    if (from_tile_ind < N_SPRITE_TYPES) {
      *tile = 0;
      return from_tile_ind;
    }

    *tile = *tile_ptr;
  }

  return 255u;
}