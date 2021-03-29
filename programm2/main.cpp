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
#include "cryptopp/aes.h"
#include "cryptopp/des.h"
#include "cryptopp/modes.h"
#include "cryptopp/cbcmac.h"
#include <locale>
using namespace std;
void encrypt() {
    setlocale(LC_ALL, "Russia");
    ifstream fs;
    ofstream fs2;
    ifstream fs3;
    string str;
    string strs = "";
    string file;
    cout << "Введите имя файла, откуда считать текст:";
    cin >> file;
    fs.open(file);
    char ch;
    while (fs.get(ch)) {
        strs.push_back(ch);
    }
    byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
    memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);
    string plaintext = strs;
    string ciphertext;
    cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
    cout << plaintext;
    cout << std::endl << std::endl;
    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);
    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length());
    stfEncryptor.MessageEnd();
    cout << "Cipher Text (" << ciphertext.size() << " bytes)" << endl;
    for (int i = 0; i < ciphertext.size(); i++) {
        cout << std::hex << (0xFF & static_cast<byte>(ciphertext[i]));
    }
    cout << "\nВыберете файл куда записать: ";
    string imp, file2;
    cin >> file2;
    fs2.open(file2);
    for (int i = 0; i < ciphertext.size(); i++) {
        fs2 << ciphertext[i];
    }
}
void decrypt() {
    setlocale(LC_ALL, "Russia");
    ifstream fs;
    ofstream fs2;
    ifstream fs3;
    string str;
    string strs = "";
    string file;
    cout << "Введите имя файла, откуда считать текст:";
    cin >> file;
    fs.open(file);
    char ch;
    while (fs.get(ch)) {
        strs.push_back(ch);
    }
	byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
    memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);
    string plaintext = strs;
    string decryptedtext;
    cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
    cout << plaintext;
    cout << std::endl << std::endl;
    string imp, file2;
    cout << "Выберете файл куда записать: ";
    cin >> file2;
    fs2.open(file2);
    fs3.open(file2);
    std::cout << std::endl << std::endl;
    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.size());
    stfDecryptor.MessageEnd();
    cout << decryptedtext << endl;
    fs2 << decryptedtext;
}
void decrypt2() {
    setlocale(LC_ALL, "Russia");
    ifstream fs;
    ofstream fs2;
    ifstream fs3;
    string str;
    string strs = "";
    string file;
    cout << "Введите имя файла, откуда считать текст:";
    cin >> file;
    fs.open(file);
    char ch;
    while (fs.get(ch)) {
        strs.push_back(ch);
    }
    byte key[CryptoPP::DES::DEFAULT_KEYLENGTH], iv[CryptoPP::DES::BLOCKSIZE];
    memset(key, 0x00, CryptoPP::DES::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::DES::BLOCKSIZE);
    string plaintext = strs;
    string decryptedtext;
    cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
    cout << plaintext;
    cout << std::endl << std::endl;
    string imp, file2;
    cout << "Выберете файл куда записать: ";
    cin >> file2;
    fs2.open(file2);
    fs3.open(file2);
    std::cout << std::endl << std::endl;
    CryptoPP::DES::Decryption aesDecryption(key, CryptoPP::DES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.size());
    stfDecryptor.MessageEnd();
    cout << decryptedtext << endl;
    fs2 << decryptedtext;
}
void encrypt2() {
    setlocale(LC_ALL, "Russia");
    ifstream fs;
    ofstream fs2;
    ifstream fs3;
    string str;
    string strs = "";
    string file;
    cout << "Введите имя файла, откуда считать текст:";
    cin >> file;
    fs.open(file);
    char ch;
    while (fs.get(ch)) {
        strs.push_back(ch);
    }
    byte key[CryptoPP::DES::DEFAULT_KEYLENGTH], iv[CryptoPP::DES::BLOCKSIZE];
    memset(key, 0x00, CryptoPP::DES::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::DES::BLOCKSIZE);
    string plaintext = strs;
    string ciphertext;
    cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
    cout << plaintext;
    cout << std::endl << std::endl;
    CryptoPP::DES::Encryption aesEncryption(key, CryptoPP::DES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);
    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length());
    stfEncryptor.MessageEnd();
    cout << "Cipher Text (" << ciphertext.size() << " bytes)" << endl;
    for (int i = 0; i < ciphertext.size(); i++) {
        cout << std::hex << (0xFF & static_cast<byte>(ciphertext[i]));
    }
    cout << "\nВыберете файл куда записать: ";
    string imp, file2;
    cin >> file2;
    fs2.open(file2);
    for (int i = 0; i < ciphertext.size(); i++) {
        fs2 << ciphertext[i];
    }
}
int main()
{
    setlocale(LC_ALL, "Russia");
    ifstream fs;
    ofstream fs2;
    ifstream fs3;
    string str;
    string strs = "";
    string file, str9;
    string t;
    int k;
    do {
        cout << "\nВедите режим AES или DES или 10 чтобы выйти: ";
        cin >> t;
        if (t == "AES") {
            do {
                cout << "\nВедите 1, если шифровать или 2, если расшифровать или 0, чтобы вести другой режим:";
                cin >> k;
                if (k == 1) {
                    encrypt();
                }
                else  if (k == 2) {
                    decrypt();
                }
            } while (k != 0);
        }
        if (t == "DES") {
            do {
                cout << "\nВедите 1, если шифровать или 2, если расшифровать или 0, чтобы вести другой режим:";
                cin >> k;
                if (k == 1) {
                    encrypt2();
                }
                else  if (k == 2) {
                    decrypt2();
                }
            } while (t != "");
        }
    } while (t !="10");
    return 0;
}





/*#include <string>
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
*/
