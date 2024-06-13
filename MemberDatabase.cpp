// Member-function definitions for class MemberDatabase.
#include <iostream>
#include <fstream>
#include<string>
using namespace::std;

#include "MemberDatabase.h"

MemberDatabase::MemberDatabase()
{
   loadFromMemberFile();
}

MemberDatabase::~MemberDatabase()
{
   saveToMemberFile();
}

// returns true if userPassword match that of an Account with userIDNumber
bool MemberDatabase::authenticateUser( string userIDNumber, string userPassword )
{
	MemberInfo buffer;
	for (int i = 0; i < members.size(); i++) {
		buffer = members[i];
		if (buffer.getIDNumber() == userIDNumber && buffer.getPassword() == userPassword) {
			return true;
		}
	}
	return false;
}

// returns true if there is an Account containing userIDNumber
bool MemberDatabase::exist(string& userIDNumber)
{
	MemberInfo buffer;
	for (int i = 0; i < members.size(); i++) {
		buffer = members[i];
		if (buffer.getIDNumber() == userIDNumber) {
			return true;
		}
	}
	return false;
}


// add newMember at the end of members
void MemberDatabase::pushBack( MemberInfo &newMember )
{
   members.push_back( newMember );
}

// loads members from the file MemberInfo.dat
void MemberDatabase::loadFromMemberFile()
{
	ifstream myfile;
	myfile.open("MemberInfo.dat", ios::binary);
	if (!myfile) {
		std::cerr << "無法打開文件！" << std::endl;
		return ; 
	}
	MemberInfo buffer;
	while (true) {		// eof return true when is end else is false
		//members[0].setIDNumber(myfile)  frist thought
		if(myfile.eof())
			break;
		myfile.read(reinterpret_cast<char*>(&buffer), sizeof(MemberInfo));
		members.push_back(buffer);
	}
	myfile.close();
}

// stores members into the file MemberInfo.dat
void MemberDatabase::saveToMemberFile()
{
	ofstream outfile;
	char ID[12] = { 0 }, name[8] = { 0 }, password[24] = { 0 };
	outfile.open("MemberInfo.dat", ios::binary);
	if (!outfile) {
		std::cerr << "無法打開文件！" << std::endl;
		return;
	}
	outfile.write(reinterpret_cast<char*> (&members), members.size());
	outfile.close();
}