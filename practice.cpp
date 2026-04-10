#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student{
    string name;
    int score;
};

class StudentManager{
    private:
    vector<Student> students;

    public:
    //生徒追加
    void add_student(){
        Student input;
        cout << "情報を入力(name score):";
        cin >> input.name >> input.score;

        students.push_back(input);

        sort(students.begin(), students.end(), [](const Student& a, const Student& b){
            if(a.score != b.score){
                return a.score > b.score;
            }
            return a.name < b.name;
        });
        
        return;
    }

    //生徒一覧
    void view_students(){
        
    }
};

int main(){

}