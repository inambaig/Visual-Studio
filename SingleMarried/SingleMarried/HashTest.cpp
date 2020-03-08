#include <iostream> //iostrem
#include <string>   //string
#include <vector>   //vector
#include "GeneralHashFunctions.h"
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	/*const std::string key = "abcdefghijklmnopqrstuvwxyz1234567890";
	std::cout << "General Purpose Hash Function Algorithms Test" << std::endl;
	std::cout << "By Arash Partow - 2002        " << std::endl;
	std::cout << "Key: " << key << std::endl;
	std::cout << " 1. RS-Hash Function Value:   " << RSHash(key) << std::endl;
	std::cout << " 2. JS-Hash Function Value:   " << JSHash(key) << std::endl;
	std::cout << " 3. PJW-Hash Function Value: " << PJWHash(key) << std::endl;
	std::cout << " 4. ELF-Hash Function Value: " << ELFHash(key) << std::endl;
	std::cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << std::endl;
	std::cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << std::endl;
	std::cout << " 7. DJB-Hash Function Value: " << DJBHash(key) << std::endl;
	std::cout << " 8. DEK-Hash Function Value: " << DEKHash(key) << std::endl;
	std::cout << " 9. FNV-Hash Function Value: " << FNVHash(key) << std::endl;
	std::cout << "10. BP-Hash Function Value:   " << BPHash(key) << std::endl;
	std::cout << "11. AP-Hash Function Value:   " << APHash(key) << std::endl;*/

	// I am using 2 hash functions

	// 1.  RS-Hash Function
	// 2.  JS-Hash Function

	std::cout << "Enter size of bloom : ";
	int size = 0;
	std::cin >> size;
	bool *bloom = new bool[size];
	std::string key = "";
	std::cout << "Keep on entering values and Enter -1 to stop entering values ";
	do
	{
		std::cin >> key;
		int rsHash = RSHash(key)%size;
		int jsHash = JSHash(key)%size;
		bloom[rsHash] = 1;
		bloom[jsHash] = 1;
	} while (key != "-1");
	
	std::cout << "Keep on searching values and Enter -1 to stop searching values ";
	do
	{
		std::cin >> key;
		int rsHash = RSHash(key) % size;
		int jsHash = JSHash(key) % size;
		if (bloom[rsHash] == 1 && bloom[jsHash] == 1)
			cout << "may be";
		else
			cout << "not exists";
	} while (key != "-1");


	ifstream in("randomInput.txt");
	int sizee;
	in >> sizee;
	bool *hashTable = new bool[sizee*5];
	for (int i = 0; i < sizee; i++)
	{
		in >> key;	
		int rsHash = RSHash(key) % size;
		int jsHash = JSHash(key) % size;
		hashTable[PJWHash(key) % size] = 1;
		hashTable[RSHash(key) % size] = 1;
		hashTable[JSHash(key) % size] = 1;

		hashTable[ELFHash(key) % size] = 1;
		hashTable[BKDRHash(key) % size] = 1;
		hashTable[SDBMHash(key) % size] = 1;

		hashTable[DJBHash(key) % size] = 1;
		hashTable[DEKHash(key) % size] = 1;
		hashTable[FNVHash(key) % size] = 1;
	}

	system("pause");
	return 1;
}
