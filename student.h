#ifndef __STUDENT__
#define __STUDENT__

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "fixfld.h"
#include "length.h"
#include "delim.h"
using namespace std;

class Student {
public:
	char Identifier[20];
	char Name[20];
	char Address[20];
	char FirstEnroll[20];
	char Credithours[5];

	Student();
	Student(char *_Identifier, char *_Name, char *_Address, char *_FirstEnroll, char *_Credithours);
	void ChangeIdentifier(char *_Identifier);
	void ChangeName(char *_Name);
	void ChangeAddress(char *_Address);
	void ChangeFirstEnroll(char *_FirstEnroll);
	void ChangeCredithours(char *_Credithours);
	void IncreaseHours(int increa);
	void DecreaseHours(int decrea);
	static int InitBuffer(DelimFieldBuffer &);
	static int InitBuffer(LengthFieldBuffer &);
	static int InitBuffer(FixedFieldBuffer &);
	void Clear();
	int Unpack(IOBuffer &);
	int Pack(IOBuffer &) const;
	void Print(ostream &, const char * label = 0) const;
	~Student();
	Student& operator =(const Student& _student);
	friend ostream& operator << (ostream& stream, Student& s);
	friend istream& operator >> (istream& stream, Student& s);
	friend ofstream& operator << (ofstream& stream, Student& s);
	friend ifstream& operator >> (ifstream& stream, Student& s);
};

#endif