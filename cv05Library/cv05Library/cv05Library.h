#ifndef CV05LIBRARY_H
#define CV05LIBRARY_H

#ifdef CV05LIBRARY_EXPORTS
#define	CV05LIBRARY_DYNAMIC_LIBRARY __declspec(dllexport)
#else
#define CV05LIBRARY_DYNAMIC_LIBRARY __declspec(dllimport)
#endif // CV05LIBRARYEXPORT

class CV05LIBRARY_DYNAMIC_LIBRARY MyLibrary
{
public:
	void sayHello() const;
	void sayBye() const;
};


#endif // !CV05LIBRARY_H
