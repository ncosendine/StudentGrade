//Program by Nathan Cosendine
//Nov. 2021
//This Program takes the average grades from a users txt file and outputs the final number and letter grade.

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
string inFileName;
string  outFilename;
ifstream inFile;
ofstream outFile;
    // read input filename
cout<<"Enter the input filename: ";
cin>>inFileName;
inFile.open(inFileName); // open input file

// check if input file opened successfully
if(inFile.fail())
{
cout<<"Unable to open input file: "<<inFileName<<"."<<endl;
return 1;
}

// read output filename
cout<<"Enter the output filename: ";
cin>>outFilename;
outFile.open(outFilename); // create and open output file

// check if output file opened successfully
if(outFile.fail())
{
cout<<"Unable to open output file: "<<outFilename<<"."<<endl;
return 1;
}

string firstName;
string lastName;
int numHwGrades;
double percentage_hwGrade;
int numProgramGrades;
double percentage_programGrade;
int numExamGrades;
double grade;
double percentage_examGrade;
double hwTotal;
double programTotal;
double examTotal;
double finalGrade;
char letterGrade;
string comment;

// loop to read till the end of input file
while(!inFile.eof())
{
// reset total grades for homework, program and examTotal to 0
hwTotal = programTotal = examTotal = 0;

// read first name and last name and number of homework grades
inFile>>firstName>>lastName>>numHwGrades;

// loop to homework grades and calculate total homework grades
for(int i=0;i<numHwGrades;i++)
{
inFile>>grade;
hwTotal += grade;
}

// read the homework percent and number of program grades
inFile>>percentage_hwGrade>>numProgramGrades;

// loop to program grades and calculate total program grades
for(int i=0;i<numProgramGrades;i++)
{
inFile>>grade;
programTotal += grade;
}

// read the program percent and number of exam_grades
inFile>>percentage_programGrade>>numExamGrades;

// loop to _exam grades and calculate examTotal grades
for(int i=0;i<numExamGrades;i++)
{
inFile>>grade;
examTotal += grade;
}

inFile>>percentage_examGrade; // read the examPercent

// calculate the average grade
finalGrade = (((hwTotal/(100*numHwGrades))*percentage_hwGrade) + ((programTotal/(100*numProgramGrades))*percentage_programGrade) + ((examTotal/(numExamGrades*100))*percentage_examGrade))*100;

// based on average grade determine letter grade and comment
if(finalGrade >= 90){
letterGrade = 'A';
comment = "Top of the class!";
}
else if(finalGrade >= 80){
letterGrade = 'B';
comment = "IMHO You Passed";
}
else if(finalGrade >= 70){
letterGrade = 'C';
comment = "Average";
}
else if(finalGrade >= 60){
letterGrade = 'D';
comment = "Passed by the skin of your teeth";
}
else{
letterGrade = 'F';
comment = "Better luck next year :(";
}

// output the result to console and output file
cout<<firstName<<" "<<lastName<<" Total Points (numerical grade): "<<finalGrade<<" Letter Grade: "<<letterGrade<<" "<<comment<<endl;
outFile<<firstName<<" "<<lastName<<" Total Points (numerical grade): "<<finalGrade<<" Letter Grade: "<<letterGrade<<" "<<comment<<endl;
}

cout<<endl;
// close the input and output files
inFile.close();
outFile.close();


return 0;
}
