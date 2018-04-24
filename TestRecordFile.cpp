#include <fstream>
#include <iomanip>
#include <cstring>
#include "iobuffer.h"
#include "fixfld.h"
#include "length.h"
#include "person.h"
#include "buffile.h"
#include "recfile.h"
#include "stdafx.h"
#include "student.h"
#include "course.h"
#include "courseregistration.h"

Student S[3];
Course C[3];
CourseRegistration CR[3];

template <class IOB, class stude>
void testBuffer(IOB & Buff,const char * myfile, stude st )
{
	//Person person;
	int result; int recaddr1, recaddr2;
	stude s;
	// Test writing
	RecordFile<stude> TestOut(Buff);
	result = TestOut.Create(myfile, ios::in | ios::out);
	cout << "create file " << result << endl;
	if (!result)
	{
		cout << "Unable to create file " << myfile << endl; return;
	}
	recaddr1 = TestOut.Write(st);
	cout << "write at " << recaddr1 << endl;
	TestOut.Close();

	RecordFile<stude> TestIn(Buff);
	TestIn.Open(myfile, ios::in);
	s.Unpack(Buff);
	TestIn.Read(s, recaddr1);

	s.Print(cout, "First record:");
	result = TestIn.Read(s, recaddr1);
	if (result == -1) cout << "Read past end of file! Error." << endl;
	else cout << "Read past end of file failed! Correct." << endl;
}

void InitStudent()
{
	cout << "Initializing 3 Student" << endl;
	strcpy_s(S[0].Identifier, "201324461");
	strcpy_s(S[0].Name, "Seo");
	strcpy_s(S[0].Address, "123 Maple");
	strcpy_s(S[0].DateEnroll, "2018-04-23");
	strcpy_s(S[0].NumberCredit, "2");
	S[0].Print(cout);
	strcpy_s(S[1].Identifier, "201324452");
	strcpy_s(S[1].Name, "dsag");
	strcpy_s(S[1].Address, "1255 TUPLE");
	strcpy_s(S[1].DateEnroll, "2010-02-05");
	strcpy_s(S[1].NumberCredit, "2");
	S[1].Print(cout);
	strcpy_s(S[2].Identifier, "201324643");
	strcpy_s(S[2].Name, "dag");
	strcpy_s(S[2].Address, "555 dgd");
	strcpy_s(S[2].DateEnroll, "2016-08-02");
	strcpy_s(S[2].NumberCredit, "3");
	S[2].Print(cout);
}

void InitCourse()
{
	cout << "Initializing 3 Student" << endl;
	strcpy_s(C[0].courseIdent , "201324461");
	strcpy_s(C[0].courseName, "MATH");
	strcpy_s(C[0].courseGrade, "A");
	strcpy_s(C[0].courseHours, "3");
	strcpy_s(C[0].teacher, "HONG");
	strcpy_s(C[0].classroom, "201");
	C[0].Print(cout);
	strcpy_s(C[1].courseIdent, "201324461");
	strcpy_s(C[1].courseName, "MaTH");
	strcpy_s(C[1].courseGrade, "A");
	strcpy_s(C[1].courseHours, "3");
	strcpy_s(C[1].teacher, "Seo");
	strcpy_s(C[1].classroom, "201");
	C[1].Print(cout);
	strcpy_s(C[2].courseIdent, "201324461");
	strcpy_s(C[2].courseName, "Korean");
	strcpy_s(C[2].courseGrade, "A");
	strcpy_s(C[2].courseHours, "1");
	strcpy_s(C[2].teacher, "hoon");
	strcpy_s(C[2].classroom, "201");
	C[2].Print(cout);
}

void InitCourseRegistration()
{
	cout << "Initializing 3 CR" << endl;
	strcpy_s(CR[0].courseIdent, "2135412");
	strcpy_s(CR[0].studentIdent, "201324461");
	strcpy_s(CR[0].NumberCredit, "2");
	strcpy_s(CR[0].courseGrade, "A");
	CR[0].Print(cout);
	strcpy_s(CR[1].courseIdent, "621651");
	strcpy_s(CR[1].studentIdent, "201324461");
	strcpy_s(CR[1].NumberCredit, "4");
	strcpy_s(CR[1].courseGrade, "A");
	CR[1].Print(cout);
	strcpy_s(CR[2].courseIdent, "565451");
	strcpy_s(CR[2].studentIdent, "201324461");
	strcpy_s(CR[2].NumberCredit, "4");
	strcpy_s(CR[2].courseGrade, "A");
	CR[2].Print(cout);

}

void StestFixedField()
{
	cout << "Testing Fixed Field Buffer" << endl;
	FixedFieldBuffer Buff(6);
	Student::InitBuffer(Buff);
	testBuffer(Buff, "fixfile.dat",S[0]);
}

void StestLength()
{
	cout << "\nTesting LengthTextBuffer" << endl;
	LengthFieldBuffer Buff;
	Student::InitBuffer(Buff);
	testBuffer(Buff, "lenfile.dat",S[1]);
}

void StestDelim()
{
	cout << "\nTesting DelimTextBuffer" << endl;
	DelimFieldBuffer::SetDefaultDelim('|');
	DelimFieldBuffer Buff;
	Student::InitBuffer(Buff);
	testBuffer(Buff, "delfile.dat",S[2]);
}
void CtestFixedField()
{
	cout << "Testing Fixed Field Buffer" << endl;
	FixedFieldBuffer Buff(7);
	Course::InitBuffer(Buff);
	testBuffer(Buff, "fixfileCO.dat", C[0]);
}

void CtestLength()
{
	cout << "\nTesting LengthTextBuffer" << endl;
	LengthFieldBuffer Buff;
	Course::InitBuffer(Buff);
	testBuffer(Buff, "lenfileCO.dat", C[1]);
}

void CtestDelim()
{
	cout << "\nTesting DelimTextBuffer" << endl;
	DelimFieldBuffer::SetDefaultDelim('|');
	DelimFieldBuffer Buff;
	Course::InitBuffer(Buff);
	testBuffer(Buff, "delfileCO.dat", C[2]);
}
void CRtestFixedField()
{
	cout << "Testing Fixed Field Buffer" << endl;
	FixedFieldBuffer Buff(4);
	Course::InitBuffer(Buff);
	testBuffer(Buff, "fixfileCOreg.dat", CR[0]);
}

void CRtestLength()
{
	cout << "\nTesting LengthTextBuffer" << endl;
	LengthFieldBuffer Buff;
	Course::InitBuffer(Buff);
	testBuffer(Buff, "lenfileCOreg.dat", CR[1]);
}

void CRtestDelim()
{
	cout << "\nTesting DelimTextBuffer" << endl;
	DelimFieldBuffer::SetDefaultDelim('|');
	DelimFieldBuffer Buff;
	Course::InitBuffer(Buff);
	testBuffer(Buff, "delfileCOreg.dat", CR[2]);
}
int main(int argc, char ** argv)
{
	InitStudent();
	StestFixedField();
	StestLength();
	StestDelim();
	InitCourse();
	CtestFixedField();
	CtestLength();
	CtestDelim();
	InitCourseRegistration();
	CRtestFixedField();
	CRtestLength();
	CRtestDelim();
}
