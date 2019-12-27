
#ifdef SIMPLEDBLIBRARY_EXPORTS
#define DLL_SPEC __declspec(dllexport)
#else
#define DLL_SPEC __declspec(dllimport)
#endif

#include <string>
#include <functional>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
// Typ datového pole
enum struct FieldType {
	Integer,
	Double,
	String,
	Field
};
class DLL_SPEC Object {
public:
	Object() {}
	virtual ~Object() {}
	// Gettery a settery podle typu
	// Jejich funkce je definována jen v pøípadì, e aktuální objekt je odpovídajícího typu
	// Automatické konverze v základním API nejsou vyadovány
	virtual std::string getString() const { return""; }
	virtual void setString(std::string value) {}
	virtual int getInt() const { return 0; }
	virtual void setInt(int value) {}
	virtual double getDouble() const { return 0; }
	virtual void setDouble(double value) {}
	// Vrací true, pokud aktuální objekt pøedstavuje danı typ
	virtual bool isType(FieldType type) const { return false; }
};

class DLL_SPEC IntObject : public Object {
private:
	int value;
public:
	IntObject() : value(0) {}
	IntObject(int v) : value(v) {}
	int getInt() const { return value; }
	void setInt(int value) { this->value = value; }
	bool isType(FieldType type) const { return type == FieldType::Integer; }
};
class DLL_SPEC DoubleObject : public Object {
private:
	double value;
public:
	DoubleObject() : value(0.0) {}
	DoubleObject(double v) : value(v) {}
	double getDouble() const { return value; }
	void setDouble(double value) { this->value = value; }
	bool isType(FieldType type) const { return type == FieldType::Double; }
};
class DLL_SPEC StringObject : public Object {
private:
	std::string value;
public:
	StringObject() : value("") {}
	StringObject(std::string v) : value(v) {}
	std::string getString() const { return value; }
	void setString(std::string value) { this->value = value; }
	bool isType(FieldType type) const { return type == FieldType::String; }
};
// Objekt popisující sloupeèek „field“
class DLL_SPEC FieldObject : public Object {
private:
	std::string name;
	FieldType type;
public:
	FieldObject() {}
	FieldObject(std::string name, FieldType type) :name(name), type(type) {}
	//virtual bool isType(FieldType type) const override = 0;
	// Název sloupeèku
	std::string getName() const { return name; }
	// Typ sloupeèku
	FieldType getType() const { return type; }
};

// --------------------------------------------------------
// Rozhraní definující podmínku – pouze pro bonusové metody
class DLL_SPEC Condition {
	virtual ~Condition() { }
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------
// Rozhraní iterátoru (select)
class DLL_SPEC Iterator {
public:
	//virtual ~Iterator();
	// Posun na další øádek (vrací true, pokud je iterátor platnı; logika podle Java Iterator)
	virtual bool moveNext() = 0;
	// Vrací pole Object* obsahující data øádku
	virtual Object** getRow() = 0;
	// Vrací interní rowId aktuálního øádku
	virtual int getRowId() = 0;
	// Uzavøe iterátor (dealokuje pamìové prostøedky)
	virtual void close() = 0;
};
/*class DLL_SPEC SelectIterator : Iterator {
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
};*/
// Tabulka
class DLL_SPEC Table {
private:
	std::string databaseName;
	std::string name;
	int rowCount;
	FieldObject** fields;
	Object*** table;
	int fieldCount;
public:
	
	Table(std::string name, int fieldsCount, FieldObject** fields, std::string databaseName);
	Table(std::string name, std::string databaseName);
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
class DLL_SPEC Db {
private:
	std::string name;
	std::string tablesNames[100];
	//Table** tables;
	Table* openedTable;
	int tablesCount;
public:
	Db(std::string nameI, std::string* tablesNamesI, int tablesCountI);
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
