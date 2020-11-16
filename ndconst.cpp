#include "ndconst.h"

const int WIN_W = 1920;
const int WIN_H = 1080;
const float WIN_S = 1.0;

/*
 * Primitive function definitions
*/
//draw sprite s[idx] at origin px_x, px_y
void drawSprite(Sprite s, int px_x, int px_y, int idx) {
  if(idx >= s.ct) return; //return if idx is too high
  idx = s.ct-(idx+1); //invert index
  int offset = idx*(s.w*s.h);
  //set position
  glRasterPos2i(px_x*WIN_S, px_y*WIN_S);
  //draw sprite
  glDrawPixels(s.w, s.h, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, s.list+offset);
}

//draw text d[idx] with font at origin px_x, px_y
void drawText(Text d, Sprite font, int px_x, int px_y, int idx) {
  if(idx >= d.ct) return; //return if idx is too high
  std::string line = d.list[idx];
  for(int n=0; n<line.length(); n++) {
    //base calculation is from ' ' = 0 (ascii 32)
    int letter_idx = std::toupper(line[n])-32; //calculate letter_idx from string
    if(letter_idx == 0) {
      px_x += font.h; //increment x by font HEIGHT
      continue;
    }
    drawSprite(font, px_x, px_y, letter_idx);
    px_x += font.h; //incrememnt x by font HEIGHT/2 for decent-looking spaces.
  }
}

//draw string d with font at origin px_x, px_y
void drawText(std::string d, Sprite font, int px_x, int px_y) {
  for(int n=0; n<d.length(); n++) {
    //base calculation is from ' ' = 0 (ascii 32)
    int letter_idx = std::toupper(d[n])-32; //calculate letter_idx from string
    if(letter_idx == 0) {
      px_x += font.h; //increment x by font HEIGHT
      continue;
    }
    drawSprite(font, px_x, px_y, letter_idx);
    px_x += font.h; //incrememnt x by font HEIGHT for decent-looking spacing.
  }
}

/*
 * Individually defining origin, dimension of components,
 * as well as functions to draw at their positions
*/
const int O_DISP_X=256, O_DISP_Y=256, D_DISP_W=1664, D_DISP_H=768;
void Display_drawSprite(Sprite x, int px_x, int px_y, int idx) {
  drawSprite(x, px_x+O_DISP_X, px_y+O_DISP_Y, idx);
}
void Display_drawText(Text d, Sprite font, int px_x, int px_y, int idx) {
  int end_px = px_x + d.list[0].length()*font.h;
  int start_diff = (O_DISP_X-px_x)/font.h; if(start_diff<0) start_diff=0;
  int end_diff   = (D_DISP_W-end_px)/font.h; if(end_diff>0) end_diff=0;
  int start_c = start_diff;
  int end_c = d.list[idx].length()+end_diff;
  std::string line = d.list[idx].substr(start_c, end_c);
  drawText(line, font, px_x+O_DISP_X, px_y+O_DISP_Y);
}
void Display_drawText(std::string d, Sprite font, int px_x, int px_y) {
  int end_px = px_x + d.length()*font.h;
  int start_diff = (0-px_x)/font.h; if(start_diff<0) start_diff=0;
  int end_diff   = (D_DISP_W-end_px)/font.h; if(end_diff>0) end_diff=0;
  int start_c = start_diff;
  int end_c = d.length()+end_diff;
  std::string line = d.substr(start_c, end_c);
  drawText(line, font, px_x+O_DISP_X+start_diff*font.h, px_y+O_DISP_Y);
}

const int O_DIA_X=256, O_DIA_Y=0, D_DIA_W=1664, D_DIA_H=256;
void Dialog_drawSprite(Sprite x, int px_x, int px_y, int idx) {
  drawSprite(x, px_x+O_DIA_X, px_y+O_DIA_Y, idx);
}
void Dialog_drawText(Text d, Sprite font, int px_x, int px_y, int idx) {
  drawText(d, font, px_x+O_DIA_X, px_y+O_DIA_Y, idx);
}
void Dialog_drawText(std::string d, Sprite font, int px_x, int px_y) {
  int end_px = px_x + d.length()*font.h;
  int start_diff = (O_DIA_X-px_x)/font.h; if(start_diff<0) start_diff=0;
  int end_diff   = (D_DIA_W-end_px)/font.h; if(end_diff>0) end_diff=0;
  int start_c = start_diff;
  int end_c = d.length()+end_diff;
  std::string line = d.substr(start_c, end_c);
  drawText(line, font, px_x+O_DIA_X, px_y+O_DIA_Y);
}

const int O_MEN_X=0, O_MEN_Y=256, D_MEN_W=256, D_MEN_H=768;
void Menu_drawSprite(Sprite x, int px_x, int px_y, int idx) {
  drawSprite(x, px_x+O_MEN_X, px_y+O_MEN_Y, idx);
}
void Menu_drawText(Text d, Sprite font, int px_x, int px_y, int idx) {
  drawText(d, font, px_x+O_MEN_X, px_y+O_MEN_Y, idx);
}
void Menu_drawText(std::string d, Sprite font, int px_x, int px_y) {
  int end_px = px_x + d.length()*font.h;
  int start_diff = (O_MEN_X-px_x)/font.h; if(start_diff<0) start_diff=0;
  int end_diff   = (D_MEN_W-end_px)/font.h; if(end_diff>0) end_diff=0;
  int start_c = start_diff;
  int end_c = d.length()+end_diff;
  std::string line = d.substr(start_c, end_c);
  drawText(line, font, px_x+O_MEN_X, px_y+O_MEN_Y);
}

const int O_IMG_X=0, O_IMG_Y=0, D_IMG_W=256, D_IMG_H=256;
void Image_drawSprite(Sprite x, int px_x, int px_y, int idx) {
  drawSprite(x, px_x+O_IMG_X, px_y+O_IMG_Y, idx);
}
void Image_drawText(Text d, Sprite font, int px_x, int px_y, int idx) {
  drawText(d, font, px_x+O_IMG_X, px_y+O_IMG_Y, idx);
}
void Image_drawText(std::string d, Sprite font, int px_x, int px_y) {
  int end_px = px_x + d.length()*font.h;
  int start_diff = (O_IMG_X-px_x)/font.h; if(start_diff<0) start_diff=0;
  int end_diff   = (D_IMG_W-end_px)/font.h; if(end_diff>0) end_diff=0;
  int start_c = start_diff;
  int end_c = d.length()+end_diff;
  std::string line = d.substr(start_c, end_c);
  drawText(line, font, px_x+O_IMG_X, px_y+O_IMG_Y);
}

const int O_BAR_X=0, O_BAR_Y=1024, D_BAR_W=1920, D_BAR_H=56;
void Bar_drawSprite(Sprite x, int px_x, int px_y, int idx) {
  drawSprite(x, px_x+O_BAR_X, px_y+O_BAR_Y, idx);
}
void Bar_drawText(Text d, Sprite font, int px_x, int px_y, int idx) {
  drawText(d, font, px_x+O_BAR_X, px_y+O_BAR_Y, idx);
}
void Bar_drawText(std::string d, Sprite font, int px_x, int px_y) {
  int end_px = px_x + d.length()*font.h;
  int start_diff = (O_BAR_X-px_x)/font.h; if(start_diff<0) start_diff=0;
  int end_diff   = (D_BAR_W-end_px)/font.h; if(end_diff>0) end_diff=0;
  int start_c = start_diff;
  int end_c = d.length()+end_diff;
  std::string line = d.substr(start_c, end_c);
  drawText(line, font, px_x+O_BAR_X, px_y+O_BAR_Y);
}
