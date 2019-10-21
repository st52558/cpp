#ifndef OBJECT_H
#define OBJECT_H
struct Object
{
private:
	int id;
	double x;
	double y;

public:
	Object(int id);
	virtual ~Object();
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	int getId() const;
};

#endif

