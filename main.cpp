#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct DataCollection{
    string course;
    char grade;
    int credits;

    DataCollection(const string& c, char& g, int& cr) : course(c) , grade(g), credits(cr){};
};

vector<DataCollection> DataInputFromUser (){
    bool condition = true;
    vector<DataCollection> courseGrade;
    while(condition) {
        string course;
        char grade;
        int credits;
        cout<< "Please Enter the name of the course with the grade and credit separated with enter, and if you are done please end it with -1" << endl;
        cout <<"Name of Course: " ;
        getline(cin,course);
        if (course == "-1"){ condition = false; cout << endl; break;}

        cout <<"Grade: ";
        cin >> grade;
        if((grade < 'A' || grade > 'F') && (grade < 'a' || grade > 'f')){
            cout << "You put the wrong grade, it should be in the range of A-F! redo!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore();

        cout <<"Credit: ";
        cin >> credits;
        cin.ignore();

        courseGrade.push_back(DataCollection(course, grade, credits));
    }
    return courseGrade;
}
void DisplayData(vector<DataCollection> data){
    for (const auto& datacol : data){
        cout<< "Course:" << datacol.course <<", Grade: "<< datacol.grade << ", Credits: "<< datacol.credits << endl;
    }
}
double CGPAResult (vector<DataCollection> data) {
    map<char, double> gradeValue;
    gradeValue['A'] = 4.0;
    gradeValue['B'] = 3.0;
    gradeValue['C'] = 2.0;
    gradeValue['D'] = 1.0;
    gradeValue['F'] = 0.0;

    int totalCredits = 0;
    double totalgrade =0.0;
    for(const auto& datacol : data){
        totalCredits+= datacol.credits;
        totalgrade += gradeValue[datacol.grade] *datacol.credits;
    }

    return totalgrade/totalCredits;
};

int main() {
    vector<DataCollection> data = DataInputFromUser();
    double finalGrade = CGPAResult(data);
    DisplayData(data);
    cout <<"Your CGPA is " << finalGrade;

    return 0;
}