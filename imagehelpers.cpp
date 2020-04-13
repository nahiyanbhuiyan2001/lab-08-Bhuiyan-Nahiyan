/*
  Author: Nahiyan Bhuiyan

  Description:
    The program reads a PGM image from the file "inImage.pgm",
    and outputs a modified image to "outImage.pgm"
*/


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imagehelpers.h"
using namespace std;
// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width) {
  char c;
  int x;
  ifstream instr;
  instr.open(filename);

  // read the header P2
  instr >> c;
assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int column = 0; column < width; column++)
			instr >> image[row][column];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions

void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width) {
  ofstream ostr;
  ostr.open(filename);
  if (ostr.fail())
  {
    cout << "Unable to write file\n";
    exit(1);
  };

  // print the header
  ostr << "P2" << endl;
// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++)
   {
		for (int col = 0; col < width; col++)
    {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

void writeImageBigger(std::string filename, int image[MAX_H*2][MAX_W*2], int height, int width) {
  ofstream ostr;
  ostr.open(filename);
  if (ostr.fail())
  {
    cout << "Unable to write file\n";
    exit(1);
  };

  // prints the header
  ostr << "P2" << endl;
// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++)
  {
		for (int column = 0; column < width; column++)
    {
			assert(image[row][column] < 256);
			assert(image[row][column] >= 0);
			ostr << image[row][column] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}
