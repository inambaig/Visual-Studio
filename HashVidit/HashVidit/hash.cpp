#include "hash.h"

Hash::Hash()
{
	collisions = 0;
	runningAvgListLength = 0;
	countElements = 0;
	longestList = 0;
	longestListIndex = 0;
	nonemptylistcount = 0;
}
void Hash::remove(string key)
{
	int hash = hf(key);

	for (int i = 0; i < hashTable[hash].size(); i++)
	{
		auto currentElement = std::next(hashTable[hash].begin(), i);
		if (key == *currentElement)
		{
			hashTable[hash].remove(key);
			countElements--;
			if (hashTable[hash].size() == 0)
			{
				nonemptylistcount--;
			}
			runningAvgListLength = (double)countElements / nonemptylistcount;
		}

	}
}
void Hash::print()
{
	for (int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		cout << i << ":\t";
		for (int j = 0; j < hashTable[i].size(); j++)
		{
			 
			auto currentElement = std::next(hashTable[i].begin(), j);
			cout << *currentElement << ", ";
		}
		cout << endl;
	}
	
}

void Hash::processFile(string filename)
{
	ifstream in(filename);
	int hash;
	string word = "";
	while (in >> word)
	{
		 
		hash = hf(word);
		if (hashTable[hash].size() == 0)
		{
			nonemptylistcount++;
		}
		hashTable[hash].push_back(word);
		countElements++;
		if (hashTable[hash].size() > longestList)
		{
			longestList = hashTable[hash].size();
			longestListIndex = hash;
		}


		if (hashTable[hash].size() != 1)
			collisions++;
		
		runningAvgListLength = ((double)countElements / nonemptylistcount);
	}
	
}
bool Hash::search(string word)
{
	int hash = hf(word);

	for (int i = 0; i < hashTable[hash].size(); i++)
	{
		auto currentElement = std::next(hashTable[hash].begin(), i);
		if (word == *currentElement)
			return true;
	}
	return false;
}
void Hash::output(string filename)
{
	ofstream out(filename);
	for (int i = 0; i < HASH_TABLE_SIZE; i++)
	{
		out << i << ":\t";

		for (int j = 0; j < hashTable[i].size(); j++)
		{
			auto currentElement = std::next(hashTable[i].begin(), j);
			out << *currentElement << ", ";
		}
		out << endl;
	}

 

}
void Hash::printStats()
{
	cout << "Total Collisions = " << collisions << endl;
	cout << "Longest List Ever = " << longestList << endl;
	cout << "Average List Length Over Time = " << runningAvgListLength << endl;
	cout << "Load Factor = " <<(double)countElements/HASH_TABLE_SIZE<< endl;
}