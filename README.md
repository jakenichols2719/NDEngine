iNDev (ND) is a very (very) simple game engine for 2d games, developed in C++ by
James Nichols.


=====FILES=====
When creating files to import into ND, the following constraints should be kept
in mind:
Image: The load script is designed for a 32-bit BMP (RGB and Alpha). I used
  GIMP to create test images, both by hand-drawing and by importing and changing
  the file type. Any size of image should work.
Spritesheet: For sprites of dimensions AxB, a spritesheet should be Ax(B*n) for
  n sprites. This is because the load script reads from the bottom left corner,
  left to right, then up; organizing sprites as a square has some interesting
  results.
Font: Essentially a long spritesheet, but keep in mind that the function to
  print text increments the distance between letters based on their **height**.
  I recommend a 3:4 width to height ratio (ex. 12x16).


=====STRUCTS=====
Sprite:
  Has a width, height, count, and list.
  Represents an indexed sprite, drawn using the drawSprite function described
  below. Each individual sprite in the struct MUST have the same dimensions,
  but entirely distinct sprites can be whatever dimensions you want.

drawSprite(Sprite s, int px_x, int px_y, int idx(=0))
  Draws a sprite with the origin located at the bottom left corner. Agnostic of
  sprite dimensions.

Text:
  Has a count and list.
  Represents an indexed list of strings, drawn using the drawText function.

drawText(Text t, Sprite font, int px_x, int px_y, int idx(=0))
  Draws a string using the given "font".

=====COMPONENTS=====

Prepending a *component* to a function like drawSprite will have two effects:
  -Positioning the resource relative to the bottom-left of that component
  -Checking bounds to ensure that the resource stays in the component.

The components are:
  -Menu
  -Display
  -Image
  -Dialogue

Named as such because that is their expected usage, but you may use them how
you like.


=====BUILDING=====
Building is currently done with CMake. Run as you normally would. The program
should be capable of running with just the generated run.exe and the res folder.