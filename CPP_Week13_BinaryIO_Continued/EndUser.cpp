#include <string>
#include <iostream>
#include <fstream>

using namespace std;
//Write String Data to a binary file 
//Read the string Data from a binary file 


/*
* Efficiency Tip : since we KNOW the file name does not need to change, AND the data is not going to change,
* We can just pass the EXACT REFERENCE of the data to the function, 
* We also make the passed references a constant so we KNOW it will never change
* 
*/


//Write a string to a Binary (.dat) file 
void writeStringBinary(const string &filePath,const string &data);

//Read a string from a Binary (.dat) File
string readStringBinary(const string &filePath);

int main() {

	string myFullName = "bbbbb bad to the bone \n\n\n bn bn bn n";

	//TODO: writebinary and readBinary

	const string outputfileName = "out.dat";

	string readString = "";

	writeStringBinary(outputfileName, myFullName);

	readString = readStringBinary(outputfileName);

	cout << readString << "THE READ STRING";

	return 0;
}


void writeStringBinary(const string& filePath, const string& data)
{
	//variable that actually stores the proper version of data to send 

	//Joe the Doe isint changing, This statement does NOT change, however the data is
	//going to be changed to be pointing towards something else
	const char* dataPointer = nullptr;

	//size of the string to write 
	int dataSize = 0;

	fstream writeFile(filePath, ios::out | ios::binary);

	//check if stream is valid 
	if (!writeFile) {

		cout << "\nFile " << filePath << " Not Found\n";

		exit(-1);
	}

	//File is Opened

	dataSize = data.size();

	//convert string to char pointer array 
	dataPointer = data.c_str();

	cout << dataPointer << " Data Pointer!" << endl;
	//write data to the file
	writeFile.write(dataPointer, data.size());

	

	writeFile.close();

}


string readStringBinary(const string& filePath)
{


	fstream readFile(filePath, ios::in|ios::binary);

	string temp = "";

	//check if stream is valid 

	if (!readFile) {
		cout << "\nFile " << filePath << " Not Found\n";
		exit(-1);
	}

	//seek the end of the file 
	readFile.seekg(0, ios::end);

	//get the position, which is the size of the file

	int fileSize = readFile.tellg();
	
	
	

	cout << "FILE SIZE: " << fileSize << endl;


	//move the pointer back to the begining
	readFile.seekg(0);

	//loading into a string is just like a Array, it has a set size at declaration
	//when being given a new string or adding to it, you need to resize it.
	//using a declaration
	temp.resize(fileSize);

	readFile.read(&temp[0], fileSize);

	readFile.close();
	

	/*for (int i = 0; i < fileSize; i++) {
		temp = temp + dataRead[i];
	}*/

	return temp;
}

