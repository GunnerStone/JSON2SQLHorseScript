// HorseGeneratingScript.cpp 
// Gunner Stone 
// Febuary 4 2020
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

vector<string> generateData(const string filename);
string removeSpaces(string str);

int main()
{
	///Define names of files
	const string JSONHorseData = "horseData.json";
	const string SQLHorseData = "sqlHorseData.txt";

	cout << "==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==\n";
	cout << "= Initializing Horse JSON->SQL Script =\n";
	cout << "==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==\n";
	
	///Read JSON File & passback every line to vector myLines
	cout << "Reading JSON\n";

	auto startTime = high_resolution_clock::now();
	vector<string> myLines = generateData(JSONHorseData);
	auto stopTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myLines.size() << " lines from filename: \""<< JSONHorseData << "\" in "<<(duration.count()/ 1000000.0) << " seconds\n";

	cout << "==-=-=-=-=-=-=-=-=-=-=-==\n";
	cout << "=   Converting to SQL   =\n";
	cout << "==-=-=-=-=-=-=-=-=-=-=-==\n";
	startTime = high_resolution_clock::now();

	//output filestream that will contain generated json horse data
	ofstream myfile;
	myfile.open(SQLHorseData);


	///List of JSON Parameters
	vector<string> param;
	param.push_back("ID");
	param.push_back("color");
	param.push_back("Position");
	param.push_back("Mane_Color");
	param.push_back("LFMarking");
	param.push_back("RFMarking");
	param.push_back("LHMarking");
	param.push_back("RHMarking");
	param.push_back("FaceString");

					
	//Body of SQL
	for (int i = 0; i < myLines.size(); i++)
	{
		string myLine = myLines.at(i);

		if (myLine.find("\""+ param.at(0) +"\":") != string::npos) {
			
			myLine = removeSpaces(myLine);
			// Find position of ':' using find() 
			int spos = myLine.find(":");
			int subLength = myLine.find(",")-spos;
			string myOutput = myLine.substr(spos+1, subLength-1)+",";
			cout << myOutput;
			myfile << myOutput;

		}
		else if (myLine.find("\"" + param.at(1) + "\":") != string::npos) {
			myLine = removeSpaces(myLine);
			// Find position of ':' using find() 
			int spos = myLine.find(":");
			int subLength = myLine.find(",") - spos;
			string myOutput = myLine.substr(spos + 1, subLength - 1) + ",";
			cout << myOutput;
			myfile << myOutput;
		}
		else if (myLine.find("\"" + param.at(2) + "\":") != string::npos) {
			myLine = removeSpaces(myLine);
			// Find position of ':' using find() 
			int spos = myLine.find(":");
			int subLength = myLine.find(",") - spos;
			string myOutput = myLine.substr(spos + 1, subLength - 1) + ",";
			cout << myOutput;
			myfile << myOutput;
		}
		else if (myLine.find("\"" + param.at(3) + "\":") != string::npos) {
			myLine = removeSpaces(myLine);
			// Find position of ':' using find() 
			int spos = myLine.find(":");
			int subLength = myLine.find(",") - spos;
			string myOutput = myLine.substr(spos + 1, subLength - 1) + ",";
			cout << myOutput;
			myfile << myOutput;
		}
		else if (myLine.find("\"" + param.at(4) + "\":") != string::npos) {
			myLine = removeSpaces(myLine);
			// Find position of ':' using find() 
			int spos = myLine.find(":");
			int subLength = myLine.find(",") - spos;
			string myOutput = myLine.substr(spos + 1, subLength - 1) + ",";
			cout << myOutput;
			myfile << myOutput;
		}
		else if (myLine.find("\"" + param.at(5) + "\":") != string::npos) {
			myLine = removeSpaces(myLine);
			// Find position of ':' using find() 
			int spos = myLine.find(":");
			int subLength = myLine.find(",") - spos;
			string myOutput = myLine.substr(spos + 1, subLength - 1) + ",";
			cout << myOutput;
			myfile << myOutput;
		}
		else if (myLine.find("\"" + param.at(6) + "\":") != string::npos) {
			myLine = removeSpaces(myLine);
			// Find position of ':' using find() 
			int spos = myLine.find(":");
			int subLength = myLine.find(",") - spos;
			string myOutput = myLine.substr(spos + 1, subLength - 1) + ",";
			cout << myOutput;
			myfile << myOutput;
		}
		else if (myLine.find("\"" + param.at(7) + "\":") != string::npos) {
			myLine = removeSpaces(myLine);
			// Find position of ':' using find() 
			int spos = myLine.find(":");
			int subLength = myLine.find(",") - spos;
			string myOutput = myLine.substr(spos + 1, subLength - 1) + ",";
			cout << myOutput;
			myfile << myOutput;
		}
		else if (myLine.find("\"" + param.at(8) + "\":") != string::npos) {
			myLine = removeSpaces(myLine);
			// Find position of ':' using find() 
			int spos = myLine.find(":");
			int subLength = myLine.find("\n") - spos-1;
			string myOutput = myLine.substr(spos + 1, subLength - 1) + "\n";
			replace(myOutput.begin(), myOutput.end(), ',', '-'); // replace all ',' to '-'
			cout << myOutput;
			myfile << myOutput;
		}
	}
	myfile.close();

	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	///Display feedback to user
	cout << "Successfully Generated SQL Horses into filename: \"" << SQLHorseData << "\" in " << (duration.count() / 1000000.0) << " seconds\n";
	system("pause");
}


/************************************************
* Given a valid filename, this function 
* will parse each line as a string and return all
* parsed strings back as a vector<string>
*************************************************/
vector<string> generateData(const string filename)
{
	//vector to store string data
	vector<string> dataList;

	//input filestream that contains random names
	ifstream myFile;
	myFile.open(filename);

	//add names to vector
	string tempName;
	while (myFile.good())
	{
		getline(myFile, tempName);
		dataList.push_back(tempName);
	}

	return dataList;
}

// Function to remove all spaces from a given string 
string removeSpaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	str.erase(remove(str.begin(), str.end(), '"'), str.end());
	return str;
}