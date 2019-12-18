#include <string>
#include <functional>
// Typ datového pole
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
	// Jejich funkce je definována jen v pøípadì, e aktuální objekt je odpovídajícího typu
	// Automatické konverze v základním API nejsou vyadovány
	virtual std::string getString() const;
	virtual void setString(std::string value);
	virtual int getInt() const;
	virtual void setInt(int value);
	virtual double getDouble() const;
	virtual void setDouble(double value);
	// Vrací true, pokud aktuální objekt pøedstavuje danı typ
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
// Objekt popisující sloupeèek „field“
class FieldObject : public Object {
private:
	std::string name;
	FieldType type;
public:
	FieldObject() {}
	FieldObject(std::string name, FieldType type) :name(name), type(type) {}
	virtual bool isType(FieldType type) const override;
	// Název sloupeèku
	std::string getName() const { return name; }
	// Typ sloupeèku
	FieldType getType() const { return type; }
};

// --------------------------------------------------------
// Rozhraní definující podmínku – pouze pro bonusové metody
class Condition {
	virtual ~Condition() { }
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------
// Rozhraní iterátoru (select)
class Iterator {
public:
	virtual ~Iterator();
	// Posun na další øádek (vrací true, pokud je iterátor platnı; logika podle Java Iterator)
	virtual bool moveNext() = 0;
	// Vrací pole Object* obsahující data øádku
	virtual Object** getRow() = 0;
	// Vrací interní rowId aktuálního øádku
	virtual int getRowId() = 0;
	// Uzavøe iterátor (dealokuje pamìové prostøedky)
	virtual void close() = 0;
};
class SelectIterator : Iterator {
	int currentRow;
	int rowCount;
	Object*** rows;
	SelectIterator(int rowCountI, Object*** rowsI);
	// Posun na další øádek (vrací true, pokud je iterátor platnı; logika podle Java Iterator)
	bool moveNext();
	// Vrací pole Object* obsahující data øádku
	Object** getRow();
	// Vrací interní rowId aktuálního øádku
	int getRowId();
	// Uzavøe iterátor (dealokuje pamìové prostøedky)
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
	// Vloení nového øádku do tabulky (pole Object* (pro jednotlivé hodnoty sloupeèkù))
	void insert(Object** row);
	// Smazání vyrabného øádku z tabulky
	void remove(int rowid);
	// Select – vytvoøí iterátor k procházení tabulky
	Iterator* select();
	// Commit – pøenese zmìny z pamìti do datovıch souborù
	void commit();
	// Uzavøe tabulku (dealokuje pamìové prostøedky)
	void close();
	// Vrací poèet øádkù v tabulce
	int getRowCount() const;
	// Vrací pole FieldObject* popisující sloupeèky tabulky
	FieldObject** getFields() const;
	// Vrací poèet sloupeèkù
	int getFieldCount() const;
	// ============== Bonusové metody: ================
	// Select s podmínkou
	Iterator* select(Condition* condition) { throw 0; }
	// Nalezení rowId s podmínkou
	int findRowId(Condition* condition) { throw 0; }
	// Update – aktualizuje øádky vyhovující podmínce, aktualizaci provádí funkce „callback“
	// callback na vstupu obdrí data øádku a vrací data
	void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }
};
// Databáze
class Db {
private:
	std::string name;
	Table** tables;
	int tablesCount;
public:
	
	// Otevøe databázi
	static Db* open(std::string database);
	// Uzavøe databázi (dealokuje pamìové prostøedky)
	void close();
	// Vytvoøí novou tabulku
	Table* createTable(std::string name, int fieldsCount, FieldObject** fields);
	// Otevøe existující tabulku
	Table* openTable(std::string name);
	// Otevøe tabulku (pokud neexistuje, vytvoøí automaticky novou)
	Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);
	// Alokuje objekt „int“
	static Object* Int(int value);
	// Alokuje objekt „double“
	static Object* Double(double value);
	// Alokuje objekt „string“
	static Object* String(std::string value);
	// Alokuje objekt „field“
	static FieldObject* Field(std::string name, FieldType type);
};
// Polymorfní datovı objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhraní vyhovuje základním typùm int, double, string; pro typ „field“ je rozhraní rozšíøeno
