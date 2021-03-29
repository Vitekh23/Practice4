#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/md5.h> // MD5
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>
using namespace std;
int main()
{
	using CryptoPP::MD5;
	ifstream fs;
	string str;
	string strs="";
	string file = "../file.txt";
	fs.open(file);
	while (!fs.eof()) {
		getline(fs, str);
		strs = strs+str;
	}
	cout << strs;
	string hesh;
	CryptoPP::Weak1::MD5 hashmd4;
	CryptoPP::StringSource(strs, true, new CryptoPP::HashFilter(hashmd4,new CryptoPP::HexEncoder(new CryptoPP::StringSink(hesh))));
	cout << endl<<hesh;
}
