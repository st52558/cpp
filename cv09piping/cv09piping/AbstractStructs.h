#define PIPETYPES_H
#ifdef PIPETYPES_H

struct APipeElement;
struct IPiping {
	virtual ~IPiping() { }
	virtual const APipeElement* GiveElement(int x, int y) const = 0;
	virtual bool IsPipingOk() const = 0;
};
struct APipeElement {
	virtual ~APipeElement() { }
	virtual bool IsCorrectlyInvolved(const IPiping* potrubi) const = 0;
	int _x;
	int _y;
};

#endif // ABSTRACTSTRUCTS_H
