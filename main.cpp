// lab 8
//Nahiyan Bhuiyan's functions
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <array>

#include "imagehelpers.h"

//TASK A
//  inverts the original colors. As a result, white shades become blacks
// and vice versa.
void invert(int o[MAX_H][MAX_W], int height, int width){
  for(int i = 0; i < height; i++)
  {
    for(int pix = 0; pix < width; pix++)
    {
      o[i][pix] = 255 - o[i][pix];
      // changes the pixels
    }
  }
}
//-----------------------------------------------------------------//
//TASK B
// inverts the colors only in the right half of the picture.
//
void invertRightHalf(int o[MAX_H][MAX_W], int height, int width){
  for(int i = 0; i < height; i++)
  {
    for(int pix = width/2; pix < width; pix++)
    {
      o[i][pix] = 255 - o[i][pix];
      // width/2 shows half pixels changed
    }
  }
}
//----------------------------------------------------------------//
//TASK C
//  program places a white box in the middl eof the pic.
// The dimensions of the box should be 50% by 50% of the original picture’s width and height.
void whiteBox(int o[MAX_H][MAX_W], int height, int width){
  int newH = .5 * height;
  int newW = .5 * width;
  int start = (height-newH)/2;
  int wstart = (width-newW)/2;

  for(int i = start; i < newH + start; i++)
  {
    for(int pix = wstart; pix < newW + wstart; pix++)
    {
      o[i][pix] = 255;
    }
  }

}
//-----------------------------------------------------------------------//
//TASK D
// outlines the pick in a frame exactly one pixel thick.


void frame(int o[MAX_H][MAX_W], int height, int width){
  int newH = .5 * height;
  int newW = .5 * width;
  int start = (height - newH)/2;
  int wstart = (width - newW)/2;

  for(int i = wstart; i <= newW + wstart; i++)
  {
    o[start][i] = 255;
  }

  for(int i = start+1; i< newH + start; i++)
  {
    o[i][wstart] = 255;
    o[i][newW + wstart] = 255;
  }

  for(int i = wstart; i <= newW + wstart; i++){
    o[newH + start][i] = 255;
  }
}
//----------------------------------------------------------------//
//TASK E
// this function scale the original picture to 200% of its size.
void scale(int k[MAX_H*2][MAX_W*2], int o[MAX_H][MAX_W], int height, int width){

  for(int i = 0; i < height * 2; i += 2)
  // times 2 for scale bigger
  {
    for(int pix = 0; pix < width*2; pix +=2)
    {
      k[i][pix] = o[i][pix];
      k[i][pix+1] = o[i][pix];
      k[i+1][pix] = o[i][pix];
      k[i+1][pix+1] = o[i][pix];
    }
  }

}
//---------------------------------------------//
//TASK F
// the function will pixelate the picture.
void pixelate(int o[MAX_H][MAX_W], int height, int width){
  int mean;
  for(int i = 0; i < MAX_H; i += 2)
  {
      for(int pix = 0; pix < MAX_W; pix += 2){
        mean = (o[i][pix] + o[i][pix+1] + o[i+1][pix] + o[i+1][pix+1]) / 4;
        o[i][pix] = mean;
        o[i][pix+1] = mean;
        o[i+1][pix] = mean;
        o[i+1][pix+1] = mean;
      }
  }
}

int main() {

  int img[MAX_H][MAX_W];
  int height, width;

  readImage("inImage.pgm",img, height, width);
  int out[MAX_H][MAX_W];

  for(int row = 0; row < height; row++)
  {
    for(int column = 0; column < width; column++)
    {
      out[row][column] = img[row][column];
    }
  }
  invert(out, height, width);
  writeImage("Task_A.pgm",out, height, width);

  for(int row = 0; row < height; row++)
  {
    for(int column = 0; column < width; column++)
    {
      out[row][column] = img[row][column];
    }
  }
  invertRightHalf(out, height, width);
  writeImage("Task_B.pgm",out, height, width);

  for(int row = 0; row < height; row++)
  {
    for(int column = 0; column < width; column++)
    {
      out[row][column] = img[row][column];
    }
  }
  whiteBox(out, height, width);
  writeImage("Task_C.pgm",out, height, width);

  for(int row = 0; row < height; row++)
  {
    for(int column = 0; column < width; column++)
    {
      out[row][column] = img[row][column];
    }
  }
  frame(out, height, width);
  writeImage("Task_D.pgm",out, height, width);

  int t = 0;
  for(int row = 0; row < height; row++)
  {
    for(int column = 0; column < width; column++)
    {
      out[row][column] = img[row][column];
    }
  }
  int k[MAX_H*2][MAX_W*2];
  scale(k, img, height, width);
  writeImageBigger("Task_E.pgm",k, height, width);

  for(int row = 0; row < height; row++)
  {
    for(int column = 0; column < width; column++)
    {
      out[row][column] = img[row][column];
    }
  }
  pixelate(out, height, width);
  writeImage("Task_F.pgm",out, height, width);

  std::cout<<"Task_A.pgm, Task_B.pgm, Task_C.pgm, Task_D.pgm, Task_E.pgm, Task_F.pgm are ready"<<std::endl;
  return 0;
}
