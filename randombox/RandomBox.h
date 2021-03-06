#ifndef __RandomBox_h
#define __RandomBox_h

// gets 1D array of random boxes with output tuples: x,y,z,lx,ly,lz
int* getRandomBoxes(int* minL, int* maxL, int* distance, int numBox);

// convert input x,y,z coordinates (0 indexed) to a linear index (0 indexed)
int getIndexFromXYZ(const int* dim, const int* boxVertice);

//calculates average integral based on target coordinates and random
//boxes
// generate an array of integral corresponding to target coordinates
// and random boxes, returns continuous 1D array of rows of m x n input data
// for CT: m = number of target coordinates,n = number of random boxes
// for MRI: m = number of target coordinates,n = (number of random boxes)/2
// targetCoord = array of input coordinates (x,y,z)'s
// numTargetCoord = number of coordinate sets
// randomBoxes = array of random boxes (ox,oy,oz,lx,ly,lz)'s
// numRandomBoxes = number of random boxes
// data = pointer to image data having template dataType
// dim = size of image (SizeX,SizeY,SizeZ)
// isMRI = true if MRI, false if CT
template< class dataType>
double* getRandomBoxIntegral(const int* targetCoord, const int numTargetCoord, const int* randomBoxes, const int numRandomBoxes, const dataType * data, const int* dim, bool isMRI);

#include "RandomBox.hxx"

#endif
