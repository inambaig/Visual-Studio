#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

	struct Node {
		int instructionNumber;
		string operation, baseAddress, location, offset, immediate, rt, rd, rs;
		Node* next;
		Node() {
			instructionNumber = 0;
			operation = "";
			baseAddress = "";
			location = "";
			offset = "";
			immediate = "";
			rt = "";
			rd = "";
			rs = "";
			next = nullptr;
		}
		Node(int in, string op, string ba, string lo, string of, string im, string rtr, string rdr, string rsr, Node* ne) {
			instructionNumber = in;
			operation = op;
			baseAddress = ba;
			location = lo;
			offset = of;
			immediate = im;
			rt = rtr;
			rd = rdr;
			rs = rsr;
			next = ne;
		}
		~Node() {
			free(next);
		}
	};
	ifstream File(argv[1]); // file opening on cmd

	vector<string> instructions; // vector of string type to have the instruction information in it.
	string currentLine; // string variable to save string line from the file
	vector<int> registerValues;
	while (getline(File, currentLine)) { // condition to read the lines from the files untill lines aren't finished
		instructions.push_back(currentLine.substr(0, 32)); // to push readlines pointer to the end of file.
	}

	int currentInstructionNumber = 128; // number for saving current number of instruction per line . 

	string currentLineOrInstruction, opcode, operation, previous_operation, output, decodedOutput = ""; // initialization of decoding the information and saving in through opcode, opcode, operation,  previous ins operation, current ins dissambler output, and the decoded varible for the information about instructions.

	vector<string> decodedInstructions; // decoded instruction later to store in a vector for performing operations later.	vector<int> registerValues; // another vector to store register values

	ofstream disassemblyFile; // write type to write the content on the file
	disassemblyFile.open("disassembly.txt"); // opening of file name dissambly for writing operaation on it.

	Node* root = new Node();
	Node* currentNode = root;

	/*
	first it read the instructions from defined file, decodes the information and then stores it in the instruction into the vector
	then read the register value from defined file and stores them into aanother vector type.
	then at last writes the information to the writable file.
	*/

	for (vector<string>::iterator iter = instructions.begin(); iter != instructions.end(); iter++) { // iterator for the vector

		currentLineOrInstruction = *iter; // secure the current line the variable

		string categoryNumber = currentLineOrInstruction.substr(0, 2); // read the instruction category number.

		if (previous_operation != "BREAK") {

			if (categoryNumber == "00") { // condition to check whether category for instruction is 1 or not?

				opcode = currentLineOrInstruction.substr(2, 4); // read the instruction opcode

				if (opcode == "0000") { // see if it is j instruction

					operation = "J";

					int il = stoi(currentLineOrInstruction.substr(6, 26)); // find out location for jump instruction 
					int decimal = 0; // Initialize decimal number
					int remainder, base = 1; //variable for saving information 
					while (il > 0) { remainder = il % 10; decimal = decimal + (remainder*base); base = base * 2; il = il / 10; } // convertion into decimal format
					string il_naked = to_string(4 * decimal);
					string il_printable = "#" + il_naked;

					decodedOutput = "J " + il_printable;
					output.append(currentLineOrInstruction + "\t" + to_string(currentInstructionNumber) + "\t" + decodedOutput + "\n");

					Node* tempNode = new Node(currentInstructionNumber, "J", "", il_naked, "", "", "", "", "", nullptr);
					if (currentNode != nullptr) {
						while (currentNode->next != nullptr) {
							currentNode = currentNode->next;
						}
					}
					currentNode->next = tempNode;
					currentNode = currentNode->next;

				}
				else if (opcode == "0010") {

					operation = "BEQ";

					int rs = stoi(currentLineOrInstruction.substr(6, 5)); // binary format to save in the register 
					int decimal = 0; // variable to initialize for decimal number
					int remainder, base = 1; // another variable to store mathematical information
					while (rs > 0) { remainder = rs % 10; decimal = decimal + (remainder*base); base = base * 2; rs = rs / 10; } // convertion into decimal format
					string rs_naked = to_string(decimal);
					string rs_printable = "R" + rs_naked; // Full, printable rs register name

					int rt = stoi(currentLineOrInstruction.substr(11, 5)); // save information in binary format to register
					decimal = 0; // Reset decimal number
					base = 1; // Reset base
					while (rt > 0) { remainder = rt % 10; decimal = decimal + (remainder*base); base = base * 2; rt = rt / 10; } // Convert rt to decimal format
					string rt_naked = to_string(decimal);
					string rt_printable = "R" + rt_naked; // Full, printable rt register name

					int of = stoi(currentLineOrInstruction.substr(16, 16)); // read the offset in BFormat
					decimal = 0; // Reset decimal number
					base = 1; // Reset base
					while (of > 0) { remainder = of % 10; decimal = decimal + (remainder*base); base = base * 2; of = of / 10; } // Convert of to decimal format
					string of_naked = to_string(4 * decimal);
					string of_printable = "#" + of_naked; // Printable offset value

					decodedOutput = "BEQ " + rs_printable + ", " + rt_printable + ", " + of_printable;
					output.append(currentLineOrInstruction + "\t" + to_string(currentInstructionNumber) + "\t" + decodedOutput + "\n");

					Node* tempNode = new Node(currentInstructionNumber, "BEQ", "", "", of_naked, "", rt_naked, "", rs_naked, nullptr);
					if (currentNode != nullptr) {
						while (currentNode->next != nullptr) {
							currentNode = currentNode->next;
						}
					}
					currentNode->next = tempNode;
					currentNode = currentNode->next;

				}
				else if (opcode == "0100") {
					operation = "BGTZ";

					int rs = stoi(currentLineOrInstruction.substr(6, 5)); // store info in binary format in register
					int decimal = 0; // initialization of decimal number
					int remainder, base = 1;
					while (rs > 0) { remainder = rs % 10; decimal = decimal + (remainder*base); base = base * 2; rs = rs / 10; } // another conversion into decimal format
					string rs_naked = to_string(decimal);
					string rs_printable = "R" + rs_naked;

					int of = stoi(currentLineOrInstruction.substr(16, 16)); // get info in binary format of ofset
					decimal = 0; // Reset decimal number
					base = 1; // Reset base
					while (of > 0) { remainder = of % 10; decimal = decimal + (remainder*base); base = base * 2; of = of / 10; } // Convert of to decimal format
					string of_naked = to_string(4 * decimal);
					string of_printable = "#" + of_naked; // Printable offset value

					decodedOutput = "BGTZ " + rs_printable + ", " + of_printable;
					output.append(currentLineOrInstruction + "\t" + to_string(currentInstructionNumber) + "\t" + decodedOutput + "\n");

					Node* tempNode = new Node(currentInstructionNumber, "BGTZ", "", "", of_naked, "", "", "", rs_naked, nullptr);
					if (currentNode != nullptr) {
						while (currentNode->next != nullptr) {
							currentNode = currentNode->next;
						}
					}
					currentNode->next = tempNode;
					currentNode = currentNode->next;

				}
				else if (opcode == "0101") { // break operation instruction

					operation = "BREAK";

					decodedOutput = "BREAK";
					output.append(currentLineOrInstruction + "\t" + to_string(currentInstructionNumber) + "\t" + decodedOutput + "\n");

					Node* tempNode = new Node(currentInstructionNumber, "BREAK", "", "", "", "", "", "", "", nullptr);
					if (currentNode != nullptr) {
						while (currentNode->next != nullptr) {
							currentNode = currentNode->next;
						}
					}
					currentNode->next = tempNode;
					currentNode = currentNode->next;

				}
				else if (opcode == "0110") { // SW operation insruction checker

					operation = "SW";

					int br = stoi(currentLineOrInstruction.substr(6, 5)); // read the info in binary format and save it in register
					int decimal = 0; // decimal number store point
					int remainder, base = 1; // Initialize remainder and base
					while (br > 0) { remainder = br % 10; decimal = decimal + (remainder*base); base = base * 2; br = br / 10; } // Convert br to decimal format
					string br_naked = to_string(decimal);
					string br_printable = "R" + br_naked; // Full, printable rs register name

					int rt = stoi(currentLineOrInstruction.substr(11, 5)); // read the info in binary format and save it in register
					decimal = 0; // Reset decimal number
					base = 1; // Reset base
					while (rt > 0) { remainder = rt % 10; decimal = decimal + (remainder*base); base = base * 2; rt = rt / 10; } // Convert rt to decimal format
					string rt_naked = to_string(decimal);
					string rt_printable = "R" + rt_naked; // Full, printable rt register name

					int of = stoi(currentLineOrInstruction.substr(16, 16)); // read the info in binary format and save it in ofset
					decimal = 0; // Reset decimal number
					base = 1; // Reset base
					while (of > 0) { remainder = of % 10; decimal = decimal + (remainder*base); base = base * 2; of = of / 10; } // Convert of to decimal format
					string of_naked = to_string(decimal);
					string of_printable = of_naked; // Printable offset value

					decodedOutput = "SW " + rt_printable + ", " + of_printable + "(" + br_printable + ")";
					output.append(currentLineOrInstruction + "\t" + to_string(currentInstructionNumber) + "\t" + decodedOutput + "\n");

					Node* tempNode = new Node(currentInstructionNumber, "SW", br_naked, "", of_naked, "", rt_naked, "", "", nullptr);
					if (currentNode != nullptr) {
						while (currentNode->next != nullptr) {
							currentNode = currentNode->next;
						}
					}
					currentNode->next = tempNode;
					currentNode = currentNode->next;

				}
				else if (opcode == "0111") { // Lw operation instruction info

					operation = "LW";

					int br = stoi(currentLineOrInstruction.substr(6, 5)); // read the info in binary format and save it in base register
					int decimal = 0; // Initialize decimal number
					int remainder, base = 1; // Initialize remainder and base
					while (br > 0) { remainder = br % 10; decimal = decimal + (remainder*base); base = base * 2; br = br / 10; } // conversion into decimal
					string br_naked = to_string(decimal);
					string br_printable = "R" + br_naked;

					int rt = stoi(currentLineOrInstruction.substr(11, 5)); // read the info in binary format and save it in register
					decimal = 0;
					base = 1;
					while (rt > 0) { remainder = rt % 10; decimal = decimal + (remainder*base); base = base * 2; rt = rt / 10; } // Convert rt to decimal format
					string rt_naked = to_string(decimal);
					string rt_printable = "R" + rt_naked; // Full, printable rt register name

					int of = stoi(currentLineOrInstruction.substr(16, 16)); // read the info in binary format and save it in offset
					decimal = 0; 										base = 1;
					while (of > 0) { remainder = of % 10; decimal = decimal + (remainder*base); base = base * 2; of = of / 10; } // Convert of to decimal format
					string of_naked = to_string(decimal);
					string of_printable = of_naked;

					decodedOutput = "LW " + rt_printable + ", " + of_printable + "(" + br_printable + ")";
					output.append(currentLineOrInstruction + "\t" + to_string(currentInstructionNumber) + "\t" + decodedOutput + "\n");

					Node* tempNode = new Node(currentInstructionNumber, "LW", br_naked, "", of_naked, "", rt_naked, "", "", nullptr);
					if (currentNode != nullptr) {
						while (currentNode->next != nullptr) {
							currentNode = currentNode->next;
						}
					}
					currentNode->next = tempNode;
					currentNode = currentNode->next;

				}

			}
			else if (categoryNumber == "01") { // check if instruction category is 2?

				opcode = currentLineOrInstruction.substr(12, 4); // read the instruction opcide

				if (opcode == "0000") {
					operation = "ADD";
				}
				else if (opcode == "0001") {
					operation = "SUB";
				}
				else if (opcode == "0010") {
					operation = "MUL";
				}
				else if (opcode == "0011") {
					operation = "AND";
				}
				else if (opcode == "0100") {
					operation = "OR";
				}
				else if (opcode == "0101") {
					operation = "XOR";
				}
				else if (opcode == "0110") {
					operation = "NOR";
				}

				int rs = stoi(currentLineOrInstruction.substr(2, 5)); // read the info in binary format and save it in register
				int decimal = 0;
				int remainder, base = 1;
				while (rs > 0) { remainder = rs % 10; decimal = decimal + (remainder*base); base = base * 2; rs = rs / 10; } // Convert rs to decimal format
				string rs_naked = to_string(decimal);
				string rs_printable = "R" + rs_naked;

				int rt = stoi(currentLineOrInstruction.substr(7, 5)); // read the info in binary format and save it in register
				decimal = 0;
				base = 1;
				while (rt > 0) { remainder = rt % 10; decimal = decimal + (remainder*base); base = base * 2; rt = rt / 10; } // Convert rt to decimal format
				string rt_naked = to_string(decimal);
				string rt_printable = "R" + rt_naked;

				int rd = stoi(currentLineOrInstruction.substr(16, 5)); // read the info in binary format and save it in register
				decimal = 0; // Reset decimal number
				base = 1; // Reset base
				while (rd > 0) { remainder = rd % 10; decimal = decimal + (remainder*base); base = base * 2; rd = rd / 10; } // Conversion into decimal format
				string rd_naked = to_string(decimal);
				string rd_printable = "R" + rd_naked;

				decodedOutput = operation + " " + rd_printable + ", " + rs_printable + ", " + rt_printable;
				output.append(currentLineOrInstruction + "\t" + to_string(currentInstructionNumber) + "\t" + decodedOutput + "\n");

				Node* tempNode = new Node(currentInstructionNumber, operation, "", "", "", "", rt_naked, rd_naked, rs_naked, nullptr);
				if (currentNode != nullptr) {
					while (currentNode->next != nullptr) {
						currentNode = currentNode->next;
					}
				}
				currentNode->next = tempNode;
				currentNode = currentNode->next;

			}
			else if (categoryNumber == "10") { // check if the category is "3" or not?

				opcode = currentLineOrInstruction.substr(12, 4); // instruction opcode information return... save it in opcode

				if (opcode == "0000") {
					operation = "ADDI";
				}
				else if (opcode == "0001") {
					operation = "ANDI";
				}
				else if (opcode == "0010") {
					operation = "ORI";
				}
				else if (opcode == "0011") {
					operation = "XORI";
				}

				int rt = stoi(currentLineOrInstruction.substr(7, 5)); // read the info in binary format and save it in register
				//cout << "cat3, rt: " << currentLineOrInstruction.substr(7,5) << ". int form: " << stoi(currentLineOrInstruction.substr(7,5)) << endl;
				int decimal = 0; // Initialize decimal number
				int remainder, base = 1; // Initialize remainder and base
				while (rt > 0) { remainder = rt % 10; decimal = decimal + (remainder*base); base = base * 2; rt = rt / 10; } // Conversion into decimal system
				string rt_naked = to_string(decimal);
				string rt_printable = "R" + rt_naked;

				int rs = stoi(currentLineOrInstruction.substr(2, 5)); // read the info in binary format and save it in register
				//cout << "cat3, rs: " << currentLineOrInstruction.substr(2,5) << endl;
				decimal = 0;
				base = 1;
				while (rs > 0) { remainder = rs % 10; decimal = decimal + (remainder*base); base = base * 2; rs = rs / 10; } // Convert rs to decimal format
				string rs_naked = to_string(decimal);
				string rs_printable = "R" + rs_naked;

				int iv = stoi(currentLineOrInstruction.substr(16, 16)); // get the immediate value of instructio pointer
				//cout << "cat3, iv: " << currentLineOrInstruction.substr(16,16) << endl;
				decimal = 0;
				base = 1;
				while (iv > 0) { remainder = iv % 10; decimal = decimal + (remainder*base); base = base * 2; iv = iv / 10; } // Conversion into decimal system
				string iv_naked = to_string(decimal);
				string iv_printable = "#" + iv_naked; // pint immediate value

				decodedOutput = operation + " " + rt_printable + ", " + rs_printable + ", " + iv_printable;
				output.append(currentLineOrInstruction + "\t" + to_string(currentInstructionNumber) + "\t" + decodedOutput + "\n");

				Node* tempNode = new Node(currentInstructionNumber, operation, "", "", "", iv_naked, rt_naked, "", rs_naked, nullptr);
				if (currentNode != nullptr) {
					while (currentNode->next != nullptr) {
						currentNode = currentNode->next;
					}
				}
				currentNode->next = tempNode;
				currentNode = currentNode->next;

			}

			previous_operation = operation;

		}
		else { // due to the operation gone BREAK, read the value in the register

			signed int registerValue;

			// two's compliment string conversion to decimal

			if (currentLineOrInstruction.substr(0, 1) == "1") { // If the number is negative

				string bvs = currentLineOrInstruction.substr(1, 31); // storing the two's complment conversion to binary number

				string bvs1 = "";

				for (int i = 0; i<bvs.length(); i++)
				{
					if (bvs[i] == '0')
						bvs1 += '1';
					else if (bvs[i] == '1')
						bvs1 += '0';

				}
				bvs = bvs1;
				int bv = stoi(bvs) + 1; // string to binary integer conversion

				int decimal = 0;
				int remainder, base = 1;
				while (bv > 0) { remainder = bv % 10; decimal = decimal + (remainder*base); base = base * 2; bv = bv / 10; } // Convert the binary value to its decimal value
				registerValue = decimal*(-1);

			}
			else { //if the number is positive then

				string bvs = currentLineOrInstruction.substr(1, 31); // store the number's value in binary number

				int bv = stoi(bvs); // bnary string conversion to integer

				int decimal = 0;
				int remainder, base = 1;
				while (bv > 0) { remainder = bv % 10; decimal = decimal + (remainder*base); base = base * 2; bv = bv / 10; } // Convert the binary value to its decimal value

				registerValue = decimal;

			}

			registerValues.push_back(registerValue); // store the register value of the current to register for later access

			output.append(currentLineOrInstruction + "\t" + to_string(currentInstructionNumber) + "\t" + to_string(registerValue) + "\n");

		}

		decodedInstructions.push_back(decodedOutput); // save the decoded instruction to decoder

		currentInstructionNumber = currentInstructionNumber + 4; // Increment the instruction number

	}

	disassemblyFile << output; // Write to the dissasembly.txt file

	ofstream simFile; // A variable to hold the simulation write-to file
	simFile.open("simulation.txt"); // writable file opening

	// get the start of the register value for instruction
	vector<string> decodedInstructionsCopy = decodedInstructions;
	int inNu = 128; // instruction number to start the register value
	string previousInstructionString = "";
	for (vector<string>::iterator iter = decodedInstructions.begin(); iter != decodedInstructions.end() && previousInstructionString != "BREAK"; iter++) {
		previousInstructionString = *iter;
		inNu = inNu + 4;
	}

	vector<int> modRegisterValues; // vector to store register value of instruction

	// filling the values of upper variable with 0's
	for (int i = 0; i <= 31; i++) {
		modRegisterValues.push_back(0);
	}

	// Set the starting node (instruction)
	currentNode = root->next;

	/*
	first iterative read of instruction information
	then get the specified information of operation
	then performing that specified operation
	and then save that operation result
	and at last writes that result to the writable file simulation.txt
	*/
	if (currentNode->next != nullptr) {
		int cycle = 1;
		while (currentNode != nullptr) {

			string currentOperation = currentNode->operation; // curent ins operation

			int currentInstructionNumber = currentNode->instructionNumber; // curr ins number
			string output = "Cycle:" + to_string(cycle) + "\t" + to_string(currentInstructionNumber) + "\t"; // output string

			if (currentOperation == "J") {

				string instructionLocation = currentNode->location;
				int iil = stoi(instructionLocation); // ins location in integer

				Node* startingNode = root;
				while (startingNode->next->instructionNumber != iil) { // Find the jump location
					startingNode = startingNode->next;
				}
				currentNode = startingNode; // setting the location of jump

				output.append("J #" + instructionLocation + "\n\n");

			}
			else if (currentOperation == "BEQ") {

				string offset = currentNode->offset;
				int io = stoi(offset); // integer offset
				string rtReg = currentNode->rt;
				int irt = modRegisterValues[stoi(rtReg)]; // register in integer
				string rsReg = currentNode->rs;
				int irs = modRegisterValues[stoi(rsReg)]; // register in integer

				int nextInstructionNumber = currentNode->instructionNumber + io; // read the next instruction

				if (irt == irs) {
					Node* startingNode = root;
					while (startingNode->next->instructionNumber != nextInstructionNumber) { // found the instruction number at the offset location
						startingNode = startingNode->next;
					}
					currentNode = startingNode->next; // setting the offset location with current node info
				}

				output.append("BEQ R" + rsReg + ", R" + rtReg + ", #" + offset + "\n\n");

			}
			else if (currentOperation == "BGTZ") {

				string offset = currentNode->offset;
				int io = stoi(offset); // integer offset				
				string rsReg = currentNode->rs;
				int irs = modRegisterValues[stoi(rsReg)]; // rs register in integer form

				int nextInstructionNumber = currentNode->instructionNumber + io; // Get the next instruction number (to be used if rs > 0)

				if (irs > 0) {
					Node* startingNode = root;
					while (startingNode->next->instructionNumber != nextInstructionNumber) { // instruction at location of offset
						startingNode = startingNode->next;
					}
					currentNode = startingNode->next; // set the node at location of offset
				}

				output.append("BGTZ R" + rsReg + ", #" + offset + "\n\n");

			}
			else if (currentOperation == "BREAK") {

				output.append("BREAK\n\n");

			}
			else if (currentOperation == "SW") {

				string baseAddress = currentNode->baseAddress;
				int iba = stoi(baseAddress); // base address in integer form
				string offset = currentNode->offset;
				int io = stoi(offset); // integer offset 
				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register 

				// Store the value from the local register specified into the memory register specified
				registerValues[(io - inNu + modRegisterValues[iba]) / 4] = modRegisterValues[irt];

				output.append("SW R" + rtReg + ", " + offset + "(R" + baseAddress + ")\n\n");

			}
			else if (currentOperation == "LW") {

				string baseAddress = currentNode->baseAddress;
				int iba = stoi(baseAddress); // integer base address
				string offset = currentNode->offset;
				int io = stoi(offset); // integer offset
				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register

				// Store the value from the memory register specified into the local register specified
				modRegisterValues[irt] = registerValues[(io - inNu + modRegisterValues[iba]) / 4];

				output.append("LW R" + rtReg + ", " + offset + "(R" + baseAddress + ")\n\n");

			}
			else if (currentOperation == "ADD") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // integer register 
				string rdReg = currentNode->rd;
				int ird = stoi(rdReg); // integer register 

				modRegisterValues[ird] = modRegisterValues[irs] + modRegisterValues[irt]; // rs + rt computation

				output.append("ADD R" + rdReg + ", R" + rsReg + ", R" + rtReg + "\n\n");

			}
			else if (currentOperation == "SUB") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // integer register 
				string rdReg = currentNode->rd;
				int ird = stoi(rdReg); // integer register 

				modRegisterValues[ird] = modRegisterValues[irs] - modRegisterValues[irt]; // rs - rt computation

				output.append("SUB R" + rdReg + ", R" + rsReg + ", R" + rtReg + "\n\n");

			}
			else if (currentOperation == "MUL") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // integer register 
				string rdReg = currentNode->rd;
				int ird = stoi(rdReg); // integer register 

				modRegisterValues[ird] = modRegisterValues[irt] * modRegisterValues[irs]; // rt x rs compuation

				output.append("MUL R" + rdReg + ", R" + rsReg + ", R" + rtReg + "\n\n");

			}
			else if (currentOperation == "AND") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // integer register 
				string rdReg = currentNode->rd;
				int ird = stoi(rdReg); // integer register 

				modRegisterValues[ird] = modRegisterValues[irt] & modRegisterValues[irs]; // bitwise AND of rt and rs computation

				output.append("AND R" + rdReg + ", R" + rsReg + ", R" + rtReg + "\n\n");

			}
			else if (currentOperation == "OR") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // integer register 
				string rdReg = currentNode->rd;
				int ird = stoi(rdReg); // integer register 

				modRegisterValues[ird] = modRegisterValues[irt] | modRegisterValues[irs]; // bitwise OR of rt and rs computation

				output.append("OR R" + rdReg + ", R" + rsReg + ", R" + rtReg + "\n\n");

			}
			else if (currentOperation == "XOR") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // integer register 
				string rdReg = currentNode->rd;
				int ird = stoi(rdReg); // integer register 

				modRegisterValues[ird] = modRegisterValues[irt] ^ modRegisterValues[irs]; // bitwise XOR of rt and rs computation

				output.append("XOR R" + rdReg + ", R" + rsReg + ", R" + rtReg + "\n\n");

			}
			else if (currentOperation == "NOR") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // rt integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // rs integer register 
				string rdReg = currentNode->rd;
				int ird = stoi(rdReg); // rd integer register 

				modRegisterValues[ird] = ~(modRegisterValues[irt] | modRegisterValues[irs]); // bitwise NOR of rt and rs

				output.append("NOR R" + rdReg + ", R" + rsReg + ", R" + rtReg + "\n\n");

			}
			else if (currentOperation == "ADDI") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // rt integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // rs integer register 
				string immediate = currentNode->immediate;
				int io = stoi(immediate); // integer immediate register value

				modRegisterValues[irt] = modRegisterValues[irs] + io;

				output.append("ADDI R" + rtReg + ", R" + rsReg + ", #" + immediate + "\n\n");

			}
			else if (currentOperation == "ANDI") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // integer register 
				string immediate = currentNode->immediate;
				int io = stoi(immediate); // integer immediate value

				modRegisterValues[irt] = modRegisterValues[irs] & io;

				output.append("AND R" + rtReg + ", R" + rsReg + ", #" + immediate + "\n\n");

			}
			else if (currentOperation == "ORI") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // integer register 
				string immediate = currentNode->immediate;
				int io = stoi(immediate); // integer immediate value 

				modRegisterValues[irt] = modRegisterValues[irs] | io;

				output.append("ORI R" + rtReg + ", R" + rsReg + ", #" + immediate + "\n\n");

			}
			else if (currentOperation == "XORI") {

				string rtReg = currentNode->rt;
				int irt = stoi(rtReg); // integer register 
				string rsReg = currentNode->rs;
				int irs = stoi(rsReg); // integer register 
				string immediate = currentNode->immediate;
				int io = stoi(immediate); // integer immediate value

				modRegisterValues[irt] = modRegisterValues[irs] ^ io;

				output.append("XORI R" + rtReg + ", R" + rsReg + ", #" + immediate + "\n\n");

			}

			// Create the "Registers" section
			string registersSection = "Registers\n";
			registersSection.append("R00:\t" + to_string(modRegisterValues[0]) + "\t" + to_string(modRegisterValues[1]) + "\t");
			registersSection.append(to_string(modRegisterValues[2]) + "\t" + to_string(modRegisterValues[3]) + "\t");
			registersSection.append(to_string(modRegisterValues[4]) + "\t" + to_string(modRegisterValues[5]) + "\t");
			registersSection.append(to_string(modRegisterValues[6]) + "\t" + to_string(modRegisterValues[7]) + "\n");
			registersSection.append("R08:\t" + to_string(modRegisterValues[8]) + "\t" + to_string(modRegisterValues[9]) + "\t");
			registersSection.append(to_string(modRegisterValues[10]) + "\t" + to_string(modRegisterValues[11]) + "\t");
			registersSection.append(to_string(modRegisterValues[12]) + "\t" + to_string(modRegisterValues[13]) + "\t");
			registersSection.append(to_string(modRegisterValues[14]) + "\t" + to_string(modRegisterValues[15]) + "\n");
			registersSection.append("R16:\t" + to_string(modRegisterValues[16]) + "\t" + to_string(modRegisterValues[17]) + "\t");
			registersSection.append(to_string(modRegisterValues[18]) + "\t" + to_string(modRegisterValues[19]) + "\t"); \
				registersSection.append(to_string(modRegisterValues[20]) + "\t" + to_string(modRegisterValues[21]) + "\t");
			registersSection.append(to_string(modRegisterValues[22]) + "\t" + to_string(modRegisterValues[23]) + "\n");
			registersSection.append("R24:\t" + to_string(modRegisterValues[24]) + "\t" + to_string(modRegisterValues[25]) + "\t");
			registersSection.append(to_string(modRegisterValues[26]) + "\t" + to_string(modRegisterValues[27]) + "\t"); \
				registersSection.append(to_string(modRegisterValues[28]) + "\t" + to_string(modRegisterValues[29]) + "\t");
			registersSection.append(to_string(modRegisterValues[30]) + "\t" + to_string(modRegisterValues[31]) + "\n\n");

			// Create the "Data" section
			string dataSection = "Data\n";
			dataSection.append(to_string(inNu) + ":\t" + to_string(registerValues[0]) + "\t" + to_string(registerValues[1]) + "\t");
			dataSection.append(to_string(registerValues[2]) + "\t" + to_string(registerValues[3]) + "\t");
			dataSection.append(to_string(registerValues[4]) + "\t" + to_string(registerValues[5]) + "\t");
			dataSection.append(to_string(registerValues[6]) + "\t" + to_string(registerValues[7]) + "\n");
			dataSection.append(to_string(inNu + 32) + ":\t" + to_string(registerValues[8]) + "\t" + to_string(registerValues[9]) + "\t");
			dataSection.append(to_string(registerValues[10]) + "\t" + to_string(registerValues[11]) + "\t");
			dataSection.append(to_string(registerValues[12]) + "\t" + to_string(registerValues[13]) + "\t");
			if (currentOperation == "BREAK") {
				dataSection.append(to_string(registerValues[14]) + "\t" + to_string(registerValues[15]) + "\n");
			}
			else {
				dataSection.append(to_string(registerValues[14]) + "\t" + to_string(registerValues[15]) + "\n\n");
			}

			// Print the output
			simFile << "--------------------\n";
			simFile << output;
			simFile << registersSection;
			simFile << dataSection;

			currentNode = currentNode->next;
			++cycle;
		}
	}

	return 0;
}
