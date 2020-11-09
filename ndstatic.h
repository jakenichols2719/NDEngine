//static classes that are used for interacting with components of the screen
#include "ndstruct.h"

class Display {
private:
public:
  static int o_x, o_y;
  static void drawSpriteDisplay(Sprite s, int px_x, int px_y, int idx=0);
};