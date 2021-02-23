#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../includes/constants.h"
#include "../includes/fileio.h"
using namespace std;


bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in) {
	//TODO
}

/*if myfile is open then close it*/
void closeFile(std::fstream& myfile){
	//TODO

/* serializes all content in entries to file outputfilename
 * check out utils for helpful type conversion functions
 * BTW serialize means the process of translating a data structure
 * into a format that can be stored in a file
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in the vector entries
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
}

int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename){
	//TODO
}

