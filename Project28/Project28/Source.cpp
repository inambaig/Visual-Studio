#include <string>
#include <fstream>

using namespace std;

int dAndE(int x){

	ifstream readPassword;
	readPassword.open("password.txt");
	int length = 0;
	if (readPassword.good()){
		string password;
		getline(readPassword, password);
		length = lseek(x, 0, SEEK_END);
		
		return 0;
	}
	else{
		printf("Error: no password file found, Using the defaults\n");
		length = lseek(x, 0, SEEK_END);
	}

	unsigned char* buffer;
	buffer = (unsigned char*)calloc(length, sizeof(char));
	pread(x, buffer, length, 0);
	string word(reinterpret_cast<char*>(buffer), length);
	char const* charArr = word.c_str();
	RC4_KEY key;
	int lenthData = word.size();
	unsigned char *buffer = (unsigned char*)malloc(lenthData + 1);
	memset(buffer, 0, lenthData + 1);

	RC4_set_key(&key, KEY_LENGTH, (const unsigned char*)KEY);
	RC4(&key, lenthData, (const unsigned char*)charArr, buffer);

	string ret((char*)buffer, lenthData);
	const char *bufferOutput = ret.c_str();
	pwrite(x, bufferOutput, ret.length(), 0);
	ftruncate(x, ret.length());
	return 0;
}