typedef struct{
	double minX;
	double minY;
	double maxX;
	double maxY;
} Rectangle;

typedef struct{
	double originX;
	double originY;
	double radius;	
} Circle;

typedef struct{
	double minY;
	double maxY;
	double pt1X;
	double pt2X;
} Triangle;

typedef union{
	Rectangle r;
	Circle c;
	Triangle t;
} ShapeUnion;

struct Shape;

typedef struct{
	double (*GetArea)(struct Shape*);
	void (*GetBoundingBox)(struct Shape*, double *);
} FunctionTable;

typedef enum{
	rectangle,
	circle,
	triangle
} ShapeType;

struct Shape{
	ShapeUnion sUnion;
	ShapeType sType;
	FunctionTable ft;
};
