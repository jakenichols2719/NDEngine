ND is a very (very) simple game engine for 2d games, developed in C++ by
James Nichols.

Here is an explanation of the structs and their helpers.

Sprite:
Has a width, height, count, and list.
Represents an indexed sprite, drawn using the drawSprite function described
below. Each individual sprite in the struct MUST have the same dimensions,
but entirely distinct sprites can be whatever dimensions you want.

drawSprite(Sprite s, int px_x, int px_y, int idx(=0))
Draws a sprite with the origin located at the bottom left corner. Agnostic of
sprite dimensions.

Using Spritesheets:
Because of the way image loading works, spritesheets are 32x(32*n) for n images,
with Sprite 0 at the bottom.