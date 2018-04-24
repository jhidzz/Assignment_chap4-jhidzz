#include "Student.h"

Student::Student()   //Default constructor
{
	Clear();
}
void Student::Clear()
{
	// set each field to an empty string
	Identifier[0] = NULL;
	Name[0] = NULL;
	Address[0] = NULL;
	FirstEnroll[0] = NULL;
	Credithours[0] = NULL;
}

Student::Student(char *_Identifier, char *_Name, char *_Address, char *_FirstEnroll, char *_Credithours)   //constructor
{
	strcpy_s(Identifier, _Identifier);
	strcpy_s(Name, _Name);
	strcpy_s(Address, _Address);
	strcpy_s(FirstEnroll, _FirstEnroll);
	strcpy_s(Credithours, _Credithours);
}
int Student::Pack(IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	Buffer.Clear();
	numBytes = Buffer.Pack(Identifier);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(Name);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(Address);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(FirstEnroll);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(Credithours);
	if (numBytes == -1) return FALSE;
	return TRUE;
}
int Student::Unpack(IOBuffer & Buffer)
{
	Clear();
	int numBytes;
	numBytes = Buffer.Unpack(Identifier);
	if (numBytes == -1) return FALSE;
	Identifier[numBytes] = 0;
	numBytes = Buffer.Unpack(Name);
	if (numBytes == -1) return FALSE;
	Name[numBytes] = 0;
	numBytes = Buffer.Unpack(Address);
	if (numBytes == -1) return FALSE;
	Address[numBytes] = 0;
	numBytes = Buffer.Unpack(FirstEnroll);
	if (numBytes == -1) return FALSE;
	FirstEnroll[numBytes] = 0;
	numBytes = Buffer.Unpack(Credithours);
	if (numBytes == -1) return FALSE;
	Credithours[numBytes] = 0;
	return TRUE;
}
int Student::InitBuffer(FixedFieldBuffer & Buffer)
// initialize a FixedFieldBuffer to be used for Persons
{
	int result;
	result = Buffer.AddField(19); // LastName [11];
	result = result && Buffer.AddField(19); // FirstName [11];
	result = result && Buffer.AddField(19); // Address [16];
	result = result && Buffer.AddField(19); // City [16];
	result = result && Buffer.AddField(4);  // State [3];
	return result;
}
int Student::InitBuffer(DelimFieldBuffer & Buffer)
// initialize a DelimFieldBuffer to be used for Persons
{
	return TRUE;
}

int Student::InitBuffer(LengthFieldBuffer & Buffer)
// initialize a LengthFieldBuffer to be used for Persons
{
	return TRUE;
}
void Student::Print(ostream & stream, const char * label) const
{
	if (label == 0) stream << "Person:";
	else stream << label;
	stream << "\n\t Identifier '" << Identifier << "'\n"
		<< "\tName '" << Name << "'\n"
		<< "\tAddress '" << Address << "'\n"
		<< "\tFirstEnroll '" << FirstEnroll << "'\n"
		<< "\tCreditHours '" << Credithours << "'\n"
		<<"'\n" << flush;
}
void Student::ChangeIdentifier(char *_Identifier)
{
	strcpy_s(Identifier, _Identifier);
}
void Student::ChangeName(char *_Name)
{
	strcpy_s(Name, _Name);
}
void Student::ChangeAddress(char *_Address)
{
	strcpy_s(Address, _Address);
}
void Student::ChangeFirstEnroll(char *_FirstEnroll)
{
	strcpy_s(FirstEnroll, _FirstEnroll);
}
void Student::ChangeCredithours(char *_Credithours)
{
	strcpy_s(Credithours, _Credithours);
}
void Student::IncreaseHours(int increa)  //학점을 증가하기 위해서 사용 (Increament value)
{
	int itemp = 0;
	char *ctemp = Credithours;
	itemp = atoi(ctemp);
	itemp = itemp + increa;
	_itoa(itemp, ctemp, 10);
	strcpy_s(Credithours, ctemp);
}
void Student::DecreaseHours(int decrea)  //학점을 감소하기 위해서 사용 (decreament value)
{
	int itemp = 0;
	char *ctemp = Credithours;
	itemp = atoi(ctemp);
	if (itemp - decrea > 0)
		itemp = itemp - decrea;
	_itoa(itemp, ctemp, 10);
	strcpy_s(Credithours, ctemp);
}
Student::~Student()
{

}
Student& Student::operator =(const Student& _student) //assignment
{
	strcpy_s(Identifier, _student.Identifier);
	strcpy_s(Name, _student.Name);
	strcpy_s(Address, _student.Address);
	strcpy_s(FirstEnroll, _student.FirstEnroll);
	strcpy_s(Credithours, _student.Credithours);
	return *this;
}

ostream& operator << (ostream & stream, Student & s)//operator override
{
	stream << s.Identifier << endl;
	stream << s.Name << endl;
	stream << s.Address << endl;
	stream << s.FirstEnroll << endl;
	stream << s.Credithours << endl;
	return stream;
}

istream & operator >> (istream & stream, Student & s)//operator override
{
	cout << "Input Student Identifier: "; stream >> s.Identifier;
	cout << "Input Student Name: "; stream >> s.Name;
	cout << "Input Student Address: "; stream >> s.Address;
	cout << "Input Student FirstEnrollment: "; stream >> s.FirstEnroll;
	cout << "Input Student Credithours: "; stream >> s.Credithours;
	return stream;
}
ofstream& operator << (ofstream& stream, Student& s) // file에 쓸 때 딜리미터를 포함하여 각 value를 구분하게 하는 operator
{
	stream << s.Identifier << "|";
	stream << s.Name << "|";
	stream << s.Address << "|";
	stream << s.FirstEnroll << "|";
	stream << s.Credithours << "|";
	return stream;
}
ifstream& operator >> (ifstream& stream, Student& s) //file에서 읽어 올때, 딜리미터를 기준으로 각 value를 읽어오게하는 operator 
{
	stream.getline(s.Identifier, 20, '|');
	stream.getline(s.Name, 20, '|');
	stream.getline(s.Address, 20, '|');
	stream.getline(s.FirstEnroll, 20, '|');
	stream.getline(s.Credithours, 5, '|');
	return stream;
}
