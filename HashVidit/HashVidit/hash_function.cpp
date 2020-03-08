/* This assignment originated at UC Riverside.*/

#include <string>
#include "hash.h"

using std::string;

// Hash function is got from Paul Larson of Microsoft Research, he has worked a alot 
// in this domain. I have further modified it as per my need, i have used ascii of each letter
// of the word that is being read from the file, assuming the word length will always be 5, then i have summed these
//asciis to to get an integer and then multiplie with 101, which is a prime number as well, so considering the table size, which is 10 in our case
// this is a great hash function as per my anaysis and observation.

int
Hash::hf(string ins) {

	
	return ((((int)ins[0]) + ((int)ins[1]) + ((int)ins[2]) + ((int)ins[3]) + ((int)ins[4]) )* 101) % HASH_TABLE_SIZE;

}