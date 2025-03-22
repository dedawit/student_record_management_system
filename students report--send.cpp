#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>


using namespace std;

// the class that stores data
class student
{
int id;
char name[50];
float eng, math, phy, chem, bio, civ,it,hpe,td,amh;
float average;
char grade[3];

public:
    void check();
    void calculate();
    void get_data();
    void get_identity();
    void showdata();
    int idf();


}; //class ends here
//------------------------------------------------------------------------------------------------------
void student::get_identity(){
    cout<<"\nEnter student's ID: ";

cin>>id; cin.ignore();
cout<<"\n\nEnter student's name: ";
cin.getline(name,50);
get_data();}
//------------------------------------------------------------------------------------------------------


void student::get_data(){

cout<<"\nAll marks should be out of 100";
cout<<"\nEnter marks in English: ";
cin>>eng;
cout<<"\nEnter marks in Mathematics:  ";
cin>>math;
cout<<"\nEnter marks in Physics:  ";
cin>>phy;
cout<<"\nEnter marks in Chemistry:  ";
cin>>chem;
cout<<"\nEnter marks in Biology:  ";
cin>>bio;
cout<<"\nEnter marks in Civics and ethical education:  ";
cin>>civ;
cout<<"\nEnter marks in Technical drawing:  ";
cin>>td;
cout<<"\nEnter marks in Health and physical education:  ";
cin>>hpe;
cout<<"\nEnter marks in Information technology:  ";
cin>>it;
cout<<"\nEnter marks in Amharic:  ";
cin>>amh;
check();
system("cls");
calculate();}
//------------------------------------------------------------------------------------------------------

//check validity of marks
void student::check (){
if(eng<0||eng>100||
   math<0||math>100||
   phy<0||phy>100||
   civ<0||civ>100||
   chem<0||chem>100||
   bio<0||bio>100||
   td<0||td>100||
   amh<0||amh>100||
   it<0||it>100||
   hpe<0||hpe>100)
   { system("cls");
    cout<<"\n \t !!!!!!!!!!! You have entered one or more INCORRECT mark!!!!!!!!!!!!!\
    \n \t \t Please enter the marks again.\n";

    get_data();
}}
   //-------------------------------------------------------------------------------------------------------

//perform calculations
   void student::calculate(){

average=(eng+math+phy+chem+bio+civ+it+hpe+td+amh)/10.0;
if(average>=90&&average<=100)
strcpy(grade,"A+");
else if(average>=85&&average<90)
strcpy(grade,"A");
else if(average>=80&&average<85)
 strcpy(grade,"A-");
else if(average>=75&&average<80)
 strcpy(grade,"B+");
 else if(average>=70&&average<75)
 strcpy(grade,"B");
 else if(average>=65&&average<70)
 strcpy(grade,"B-");
 else if(average>=60&&average<65)
 strcpy(grade,"C+");
 else if(average>=50&&average<60)
 strcpy(grade,"C");
 else if(average>=45&&average<50)
 strcpy(grade,"C-");
 else if(average>=40&&average<45)
 strcpy(grade,"D");
 else if(average>=30&&average<40)
 strcpy(grade,"Fx");
 else if(average>=0&&average<30)
 strcpy(grade,"F");
}
//---------------------------------------------------------------------------------------------------

//show the students information

void student::showdata()
{
    cout.setf(ios::fixed);
cout<<"\nStudent's ID: "<<id<<endl;
cout<<"\nName of student : "<<name<<endl;
cout<<"\nEnglish : "<<eng<<endl;
cout<<"\nMathematics : "<<math<<endl;
cout<<"\nPhysics : "<<phy<<endl;
cout<<"\nChemistry : "<<chem<<endl;
cout<<"\nBiology:"<<bio<<endl;
cout<<"\nCivics and ethical education :"<<civ<<endl;
cout<<"\nTechnical drawing:"<<td<<endl;
cout<<"\nInformation technology:"<<it<<endl;
cout<<"\nHealth and physical education:"<<hpe<<endl;
cout<<"\nAmharic:"<<amh<<endl<<endl;

cout<<"*******************************************";
cout<<"\n*\tAverage mark of the student: "<<average<<"*"<<endl;
cout<<"\n*\tGrade of student :"<<grade<<"             *";
cout<<"\n*******************************************";
}
//------------------------------------------------------------------------------------------------------
int student::idf()
{
return id;
}
//-------------------------------------------------------------------------------------------------------
//function declaration
void enter_student_mark(char filename[],int num);//enter marks of new student
void display_sp(char filename[],int stud);//display particular record
void display_all(char filename[]); // display all records
void delete_student(char filename[],int stud);//delete particular record
void change_student(char filename[],int stud);//edit particular record
//-------------------------------------------------------------------------------------------------------
fstream file;
student stud[60];
char name[50];
int id, i;

char filename[35];


//***************************MAIN********************************
int main()
{
    system("color 24");
int choice;
cout<<setprecision(2);
do
{
  int num;

system("cls");
cout<<"\n\n\n\tMENU";
cout<<"\n*****************************************\n";
cout<<"\n\n\t1.Create students record";
cout<<"\n\n\t2. Search student record";
cout<<"\n\n\t3. Display all students records ";
cout<<"\n\n\t4.Delete student record";
cout<<"\n\n\t5.Modify student record";
cout<<"\n\n\t6.Exit";
cout<<"\n\n\What is your Choice (1/2/3/4/5/6)?\n ";
cin>>choice;
system("cls");


switch(choice)
{
case 1:
    cout<<"Please enter the name of the file:\n";
cin.ignore();
cin.getline(filename,35);
    cout<<"\nHow many students mark do you want to enter?\n";
    cin>>num;
    enter_student_mark(filename,num);
     break;
case 2:
    cout<<"Please enter the name of the file:\n";
cin.ignore();
cin.getline(filename,35);
    cout<<"\n\n\tEnter The student ID:\n ";
cin>>id;
display_sp(filename,id);
break;
case 3:
    cout<<"Please enter the name of the file:\n";
cin.ignore();
cin.getline(filename,35);
     display_all(filename);
     break;
case 4:
    cout<<"Please enter the name of the file:\n";
cin.ignore();
cin.getline(filename,35);
     cout<<"\n\n\tEnter The student ID:\n ";
cin>>id;
delete_student(filename,id);
break;
case 5:
    cout<<"Please enter the name of the file:\n";
cin.ignore();
cin.getline(filename,35);
     cout<<"\n\n\tEnter The student ID:\n ";
cin>>id;
change_student(filename,id);
break;
case 6:
     cout<<"Exiting, Thank you!";
     exit(0);
}
}while(choice!=6);
return 0;
}


//-----------------------------------------------------------------------------
//write student details to file
void enter_student_mark(char filename[],int num)
{

file.open(filename,ios::binary|ios::app);
if(file.is_open()){
cout<<"\nPlease enter students information accordingly:\n";
cin.ignore();
for(i=0;i<num;i++){
        cout<<"\nPlease enter information of student "<<i+1<<endl;
stud[i].get_identity();}
file.write((char*)stud, num*sizeof(student));
file.close();
     cout<<"\n\nStudent record Has Been Created.\n ";
cin.ignore();
cin.get();}
else{
    cout<<"\nError in opening the file.\n";
    cin.ignore();
cin.get();
}

}
//----------------------------------------------------------------------
// read file records
void display_all(char filename[])
{

file.open(filename,ios::in|ios::binary);

if(file.is_open())
{i=0;
    cout<<"\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
while(file.read((char*)&stud[i], sizeof(student)))
{
    cout<<"The information of student "<<i+1<<" is :\n";
stud[i].showdata();
cout<<"\n\n====================================\n";
i++;}
file.close();

cin.get();

}
else
{
cout<<"File could not be opened !!\n Press any Key to get menu";

cin.get();
}

}
//-------------------------------------------------------
//read specific record based on ID
void display_sp(char filename[],int id)
{


file.open(filename,ios::binary|ios::in);
if(file.is_open())
{
  bool flag=false;
while(file.read((char*)&stud[i], sizeof(student)))
{

if(stud[i].idf()==id)
{
    cout<<"\n The record of the student with id "<<stud[i].idf()<<" is:\n";
  stud[i].showdata();
flag=true;
}
}
file.close();
if(flag==false)
cout<<"\n\nrecord does not exist";
cin.ignore();

cin.get();
}
else
{
cout<<"File could not be opened...\n Press any Key to get menu";
cin.ignore();
cin.get();

}

}

//--------------------------------------------------------------
// modify record for specified ID
void change_student(char filename[],int id)
{
bool found=false;
file.open(filename,ios::binary|ios::in|ios::out);
if(file.is_open())
{while(!file.eof() && found==false)
{
file.read((char*)&stud[i], sizeof(student));
if(stud[i].idf()==id)
{
    cout<<"\nThe record of the student you want to update is :\n";
stud[i].showdata();


cout<<"\nEnter new details of the student:"<<endl;
stud[i].get_identity();
    int pos=(-1)*sizeof(student);
    file.seekp(pos,ios::cur);
    file.write((char*)&stud[i], sizeof(student));
    cout<<"\n\n\t Record Updated";
    found=true;
}
}
file.close();
if(found==false)
cout<<"\n\n Record Not Found ";
cin.ignore();
cin.get();}
else
{
cout<<"File could not be opened.\n Press any Key to get menu...";
cin.ignore();
cin.get();

}

}
//---------------------------------------------------------------------------------
//delete record with particular ID
void delete_student(char filename[],int id)
{

file.open(filename,ios::binary|ios::in);
if(file.is_open())
{
ofstream file2;
file2.open("Temp.dat",ios::out);

while(file.read((char*)&stud[i], sizeof(student)))
{
if(stud[i].idf()!=id)
{
file2.write((char*)&stud[i], sizeof(student));
}
}
file2.close();
file.close();
remove(filename);
rename("Temp.dat",filename);
cout<<"\n\n\tRecord Deleted ..";
cin.ignore();
cin.get();
}

else{

cout<<"File could not be opened... \nPress any Key to exit...";
cin.ignore();
cin.get();
}

}

