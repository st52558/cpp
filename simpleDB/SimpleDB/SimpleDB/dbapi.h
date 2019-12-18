#include <string>
#include <functional>
// Typ datov�ho pole
enum struct FieldType {
	Integer,
	Double,
	String,
	Field
};
class Object {
public:
	Object();
	virtual ~Object();
	// Gettery a settery podle typu
	// Jejich funkce je definov�na jen v p��pad�, �e aktu�ln� objekt je odpov�daj�c�ho typu
	// Automatick� konverze v z�kladn�m API nejsou vy�adov�ny
	virtual std::string getString() const;
	virtual void setString(std::string value);
	virtual int getInt() const;
	virtual void setInt(int value);
	virtual double getDouble() const;
	virtual void setDouble(double value);
	// Vrac� true, pokud aktu�ln� objekt p�edstavuje dan� typ
	virtual bool isType(FieldType type) const;
};

class IntObject : public Object {
private:
	int value;
public:
	IntObject() : value(0) {}
	IntObject(int v) : value(v) {}

};
class DoubleObject : public Object {
private:
	double value;
public:
	DoubleObject() : value(0.0) {}
	DoubleObject(double v) : value(v) {}

};
class StringObject : public Object {
private:
	std::string value;
public:
	StringObject() : value("") {}
	StringObject(std::string v) : value(v) {}

};
// Objekt popisuj�c� sloupe�ek �field�
class FieldObject : public Object {
private:
	std::string name;
	FieldType type;
public:
	FieldObject() {}
	FieldObject(std::string name, FieldType type) :name(name), type(type) {}
	virtual bool isType(FieldType type) const override;
	// N�zev sloupe�ku
	std::string getName() const { return name; }
	// Typ sloupe�ku
	FieldType getType() const { return type; }
};

// --------------------------------------------------------
// Rozhran� definuj�c� podm�nku � pouze pro bonusov� metody
class Condition {
	virtual ~Condition() { }
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------
// Rozhran� iter�toru (select)
class Iterator {
public:
	virtual ~Iterator();
	// Posun na dal�� ��dek (vrac� true, pokud je iter�tor platn�; logika podle Java Iterator)
	virtual bool moveNext() = 0;
	// Vrac� pole Object* obsahuj�c� data ��dku
	virtual Object** getRow() = 0;
	// Vrac� intern� rowId aktu�ln�ho ��dku
	virtual int getRowId() = 0;
	// Uzav�e iter�tor (dealokuje pam�ov� prost�edky)
	virtual void close() = 0;
};
class SelectIterator : Iterator {
	int currentRow;
	int rowCount;
	Object*** rows;
	SelectIterator(int rowCountI, Object*** rowsI);
	// Posun na dal�� ��dek (vrac� true, pokud je iter�tor platn�; logika podle Java Iterator)
	bool moveNext();
	// Vrac� pole Object* obsahuj�c� data ��dku
	Object** getRow();
	// Vrac� intern� rowId aktu�ln�ho ��dku
	int getRowId();
	// Uzav�e iter�tor (dealokuje pam�ov� prost�edky)
	void close();
};
// Tabulka
class Table {
private:
	FieldObject** fields;
	Object*** table;
	int fieldCount;
public:
	std::string name;
	int rowCount;
	Table(std::string name, int fieldsCount, FieldObject** fields);
	// Vlo�en� nov�ho ��dku do tabulky (pole Object* (pro jednotliv� hodnoty sloupe�k�))
	void insert(Object** row);
	// Smaz�n� vyrabn�ho ��dku z tabulky
	void remove(int rowid);
	// Select � vytvo�� iter�tor k proch�zen� tabulky
	Iterator* select();
	// Commit � p�enese zm�ny z pam�ti do datov�ch soubor�
	void commit();
	// Uzav�e tabulku (dealokuje pam�ov� prost�edky)
	void close();
	// Vrac� po�et ��dk� v tabulce
	int getRowCount() const;
	// Vrac� pole FieldObject* popisuj�c� sloupe�ky tabulky
	FieldObject** getFields() const;
	// Vrac� po�et sloupe�k�
	int getFieldCount() const;
	// ============== Bonusov� metody: ================
	// Select s podm�nkou
	Iterator* select(Condition* condition) { throw 0; }
	// Nalezen� rowId s podm�nkou
	int findRowId(Condition* condition) { throw 0; }
	// Update � aktualizuje ��dky vyhovuj�c� podm�nce, aktualizaci prov�d� funkce �callback�
	// callback na vstupu obdr�� data ��dku a vrac� data
	void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }
};
// Datab�ze
class Db {
private:
	std::string name;
	Table** tables;
	int tablesCount;
public:
	
	// Otev�e datab�zi
	static Db* open(std::string database);
	// Uzav�e datab�zi (dealokuje pam�ov� prost�edky)
	void close();
	// Vytvo�� novou tabulku
	Table* createTable(std::string name, int fieldsCount, FieldObject** fields);
	// Otev�e existuj�c� tabulku
	Table* openTable(std::string name);
	// Otev�e tabulku (pokud neexistuje, vytvo�� automaticky novou)
	Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);
	// Alokuje objekt �int�
	static Object* Int(int value);
	// Alokuje objekt �double�
	static Object* Double(double value);
	// Alokuje objekt �string�
	static Object* String(std::string value);
	// Alokuje objekt �field�
	static FieldObject* Field(std::string name, FieldType type);
};
// Polymorfn� datov� objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhran� vyhovuje z�kladn�m typ�m int, double, string; pro typ �field� je rozhran� roz���eno
