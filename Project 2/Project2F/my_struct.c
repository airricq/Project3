#include <prototypes.h>

//Initializations
void InitializeRectangle(Rectangle *thisRect, double minX, double maxX, double minY,double maxY){
	thisRect->minX = minX;
	thisRect->maxX = maxX;
	thisRect->minY = minY;
	thisRect->maxY = maxY;
}

void InitializeCircle(Circle *thisCirc, double radius, double origin, double originY){
	thisCirc->originX = origin;
	thisCirc->originY = originY;
	thisCirc->radius = radius;
}

void InitializeTriangle(Triangle *thisTri, double pt1X, double pt2X, double minY, double maxY){
	thisTri->minY = minY;
	thisTri->maxY = maxY;
	thisTri->pt1X = pt1X;
	thisTri->pt2X = pt2X;
}


//Area Functions
double GetCircleArea(Circle *thisCirc){
	return 3.14159 * thisCirc->radius * thisCirc->radius;
}


double GetRectangleArea(Rectangle *thisRect){
	return (thisRect->maxX - thisRect-> minX) * (thisRect->maxY - thisRect-> minY);
}

double GetTriangleArea(Triangle *thisTri){
	return (thisTri->pt2X - thisTri->pt1X) * (thisTri->maxY - thisTri->minY) / 2;
}


//Bounding box functions

void GetCircleBoundingBox(Circle *thisCirc, double *bbox){
	bbox[0] = thisCirc->originX - thisCirc->radius;
	bbox[1] = thisCirc->originX + thisCirc->radius;
	bbox[2] = thisCirc->originY - thisCirc->radius;
	bbox[3] = thisCirc->originY + thisCirc->radius;
}

void GetRectangleBoundingBox(Rectangle *thisRect, double *bbox){
	bbox[0] = thisRect->minX;
	bbox[1] = thisRect->maxX;
	bbox[2] = thisRect->minY;
	bbox[3] = thisRect->maxY;
}

void GetTriangleBoundingBox(Triangle *thisTri, double *bbox){
	bbox[0] = thisTri->pt1X;
	bbox[1] = thisTri->pt2X;
	bbox[2] = thisTri->minY;
	bbox[3] = thisTri->maxY;
}
