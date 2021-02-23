#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../includes/constants.h"
#include "../includes/utilities.h"

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in){
	myfile.open(myFileName, mode);
	return myfile.is_open();

}

/*if myfile is open then close it*/
void closeFile(std::fstream& myfile){
	if (myfile.is_open())
		myfile.close();
}

/* serializes all content in entries to file outputfilename
 * check out utils for helpful type conversion functions
 * BTW serialize means the process of translating a data structure
 * into a format that can be stored in a file
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in the vector entries
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */

int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename){
	std::ofstream outfile;
	outfile.open(outputfilename);

	//if cannot open outputfilename
	if (!outfile.is_open()){
		return constants::FAIL_FILE_DID_NOT_OPEN;
	}

	//if there are 0 entries in the vector entries
	if (entries.size()==0){
		return constants::FAIL_NO_ARRAY_DATA;
	}

	//serialize all content in entries to file outputfilename
	for (unsigned int i=0; i<entries.size(); i++){
		outfile<<entries[i].word<<" "<<entries[i].number_occurences<<std::endl;
	}

	//if all data is written and outputfilename closes okay
	return constants::SUCCESS;
}

