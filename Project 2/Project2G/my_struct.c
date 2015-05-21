#include <prototypes.h>

//Initializations
void InitializeRectangle(struct Shape *thisShape, double minX, double maxX, double minY,double maxY){
	thisShape->sType = rectangle;
	thisShape->sUnion.r.minX = minX;
	thisShape->sUnion.r.maxX = maxX;
	thisShape->sUnion.r.minY = minY;
	thisShape->sUnion.r.maxY = maxY;
	
	thisShape->ft.GetArea = GetRectangleArea;
	thisShape->ft.GetBoundingBox = GetRectangleBoundingBox;

}

void InitializeCircle(struct Shape *thisShape, double radius, double origin, double originY){
	
	thisShape->sType = circle;
	thisShape->sUnion.c.originX = origin;
	thisShape->sUnion.c.originY = originY;
	thisShape->sUnion.c.radius = radius;

	thisShape->ft.GetArea = GetCircleArea;
	thisShape->ft.GetBoundingBox = GetCircleBoundingBox;
}

void InitializeTriangle(struct Shape *thisShape, double pt1X, double pt2X, double minY, double maxY){
	
	thisShape->sType = triangle;
	thisShape->sUnion.t.minY = minY;
	thisShape->sUnion.t.maxY = maxY;
	thisShape->sUnion.t.pt1X = pt1X;
	thisShape->sUnion.t.pt2X = pt2X;

	thisShape->ft.GetArea = GetTriangleArea;
	thisShape->ft.GetBoundingBox = GetTriangleBoundingBox;
}


//Area Functions
double GetCircleArea(struct Shape *thisShape){
	return 3.14159 * thisShape->sUnion.c.radius * thisShape->sUnion.c.radius;
}


double GetRectangleArea(struct Shape *thisShape){
	return (thisShape->sUnion.r.maxX - thisShape->sUnion.r.minX) *
		   (thisShape->sUnion.r.maxY - thisShape->sUnion.r.minY);
}

double GetTriangleArea(struct Shape *thisShape){
	return (thisShape->sUnion.t.pt2X - thisShape->sUnion.t.pt1X) *
		   (thisShape->sUnion.t.maxY - thisShape->sUnion.t.minY) /2;
}


//Bounding box functions

void GetCircleBoundingBox(struct Shape *thisShape, double *bbox){
	bbox[0] = thisShape->sUnion.c.originX - thisShape->sUnion.c.radius;
	bbox[1] = thisShape->sUnion.c.originX + thisShape->sUnion.c.radius;
	bbox[2] = thisShape->sUnion.c.originY - thisShape->sUnion.c.radius;
	bbox[3] = thisShape->sUnion.c.originY + thisShape->sUnion.c.radius;
}

void GetRectangleBoundingBox(struct Shape *thisShape, double *bbox){
	bbox[0] = thisShape->sUnion.r.minX;
	bbox[1] = thisShape->sUnion.r.maxX;
	bbox[2] = thisShape->sUnion.r.minY;
	bbox[3] = thisShape->sUnion.r.maxY;
}

void GetTriangleBoundingBox(struct Shape *thisShape, double *bbox){
	bbox[0] = thisShape->sUnion.t.pt1X;
	bbox[1] = thisShape->sUnion.t.pt2X;
	bbox[2] = thisShape->sUnion.t.minY;
	bbox[3] = thisShape->sUnion.t.maxY;
}
