// Ernest Majdalani, ID: 40021641
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

const char * output_file = "reverse.dat"; //Naming output file

int main(int argc, char *argv[]) {
	//Check the number of parameters

	if (argc < 2) {  
		cout << "Error: cannot find path" << endl; 
		exit(1);
	}

	ifstream in(argv[1]); // reads "in" the next parameter
	
	// if fails to open "in" file
	if (!in) {
		cout << "Input file cannot be opened " << argv[1] << endl;
		exit(1);
	}

	ofstream out(output_file);
	// if fails to open "out" file
	if (!out) {
		cout << "Input file cannot be opened " << output_file << endl;
		exit(1);
	}

	string dType; // Data Type
	size_t dSize; // Data size

	//Starts to read from file
	while (!in.eof()) {
		in >> dType >> dSize; // Takes in Data type and Data size
		out << left << setw(5) << dType << '\t' << dSize << '\t';

		// if the file reads a data type of "int" will read in the numbers and reverse them
		if (dType == "int") {

			int * iPtr = new int[dSize];
			for (size_t i = 0; i < dSize; ++i)
				in >> iPtr[i];
			for (size_t i = 0; i < dSize; ++i)
				out << iPtr[dSize - i - 1] << " ";
			delete [] iPtr;
		}

		// Same applies here for floating point data type
		else if (dType == "float") {

			float * fPtr = new float[dSize];
			for (size_t i = 0; i < dSize; ++i)
				in >> fPtr[i];
			for (size_t i = 0; i < dSize; ++i)
				out << fPtr[dSize - i - 1] << " ";
			delete [] fPtr;

		}

		// Same applies here for character data type
		else if (dType == "char") {
			char * cPtr = new char[dSize];
			for (size_t i = 0; i < dSize; ++i)
				in >> cPtr[i];
			for (size_t i = 0; i < dSize; ++i)
				out << cPtr[dSize - i - 1] << " ";
			delete [] cPtr;
		}

		else {
			cout << "Error: " << dType << " cannot support record type" << endl;
			exit(1);
		}

		out << endl;
	}

	in.close();
	out.close();
	
	return 0;

}
