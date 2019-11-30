#define ABSTRACTSTRUCTS_H
#ifdef ABSTRACTSTRUCTS_H

struct APotrubniPrvek;
struct IPotrubi {
	virtual ~IPotrubi() { }
	virtual const APotrubniPrvek* DejPrvek(int x, int y) const = 0;
	virtual bool JePotrubiOk() const = 0;
};
struct APotrubniPrvek {
	virtual ~APotrubniPrvek() { }
	virtual bool JeKorektneZapojen(const IPotrubi* potrubi) const = 0;
	int _x;
	int _y;
};

#endif // ABSTRACTSTRUCTS_H
