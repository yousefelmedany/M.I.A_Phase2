#include <bits/stdc++.h>
#include <unistd.h>
#include <windows.h>
#define co(a) cout<<a<<endl
#define ci(a) cin>>a
#define M 1000000000
#define ll long long
using namespace std;

bool arr[100000]={0};


// Task class representing new tasks
class Task{
    int id;  //id of the task
    string description; //description of the task;
    bool completed;  // check if completed or not

public:
//constructor
Task(int id,string desc,bool completed){
    this->id=id;
    this->description=desc;
    this->completed=completed;
}
//getters and setters
int getid(){
    return this->id;
}
string getdescription(){
    return this->description;
}
bool getcompleteness(){
    return this->completed;
}
void setcompleteness(){
    this->completed=true;
}
void changedescription(string s){
    this->description=s;
}
};

//this is our system class. By using it, we can add new task, delete a task, mark some task, and view all tasks in the system
class System{
    vector<Task> Tasks; //the list of our tasks

public:
HANDLE col =  GetStdHandle(STD_OUTPUT_HANDLE);

//this function operates our system.
void Run(){
    string x;
    this->mainmenu();
    co("Select an Option");
    getline(cin,x);
    if(!x.compare("1")){ //checking the option after taking it from the user.
         this->addTask();       
    }else if(!x.compare("2")){
        this->markTask();
    }else if(!x.compare("3")){
        if(this->Tasks.size()==0){system("cls");co("No Tasks in the System!");sleep(3);}
        else{
            system("cls");
            this->viewtasks();
            string x;
            SetConsoleTextAttribute(col,1);
            co("Enter -1 to Exit, anything else to return to main menu: ");
            SetConsoleTextAttribute(col,15);
            getline(cin,x);
            if(!x.compare("-1")){
                this->Exit();
                return;
            }
            }
    }else if(!x.compare("4")){
        this->removeTask();
    }else if(!x.compare("5")){
        this->Exit();
        return;
    }else{
        system("cls");
        co("Please Enter a valid option!");
        sleep(3);
    }
    system("cls");
    this->Run(); //reloadig the system.
}
//the main menu we can choose from.
void mainmenu(){
    SetConsoleTextAttribute(col,4);
    co("Minions Task Manager");
    SetConsoleTextAttribute(col,1);
    co("1.Add Task");
    co("2.Mark Task");
    co("3.View Tasks");
    co("4.Remove Task");
    co("5.Exit\n");
    SetConsoleTextAttribute(col,7);
}
//if we need to add a new task, we use this method.
void addTask(){
    system("cls");
    string description;
    SetConsoleTextAttribute(col,1);
    co("Enter Task Description");
    SetConsoleTextAttribute(col,15);
    getline(cin,description); //taking the description of the new task and then check its validity.
    if(count(description.begin(), description.end(), ' ')==description.size() || description.size()==0){
        system("cls");
        co("Please Enter a Description!");
        sleep(3);
        this->addTask();
        return;
    }
    int id=0,i; //assigning a unique id for the new task.
    while(arr[id]==1){
        id++;
    }
    arr[id]=1;
    Task task(id+1,description,false);
    for(i=0;i<this->Tasks.size();i++){
        if(this->Tasks[i].getid()>task.getid()){
            break;
        }
    }

    this->Tasks.insert(this->Tasks.begin()+i,task);
    SetConsoleTextAttribute(col,2);
    co("Task Added Successfully!");
    SetConsoleTextAttribute(col,7);
    sleep(3);
}
//if we want to remove one of our tasks, we use this method.
void removeTask(){
    system("cls");
    if(this->Tasks.size()==0){co("No Tasks in the System!");sleep(3);return;}else{this->viewtasks();}
    string id;
    co("Enter ID to delete: "); //taking id of the task to be deleted and then check its validity.
    getline(cin,id);
    bool check=false;
    for(int i=0;i<this->Tasks.size();i++){
        if(!id.compare(to_string(this->Tasks[i].getid()))){
            arr[this->Tasks[i].getid()-1]=0;
            this->Tasks.erase(this->Tasks.begin()+i);
            check=true;
            break;
        }
    }
    SetConsoleTextAttribute(col,2);
    if(check){
        co("Task Deleted Successfully!");
        SetConsoleTextAttribute(col,7);
        sleep(3);
    }else{
        system("cls");
        co("Please Enter a Valid ID!");
        sleep(3);
        this->removeTask();
    }
   
}
//if we want to mark a task as completed, we use this method. 
void markTask(){
    system("cls");
    if(this->Tasks.size()==0){co("No Tasks in the System!");sleep(3);return;}else{this->viewtasks();}
    string id;
    SetConsoleTextAttribute(col,1);
    co("Enter ID to complete: "); //taking the id of the task to be marked then check its validity.
    SetConsoleTextAttribute(col,15);
    getline(cin,id);
    bool check=false;int i;
    for(i=0;i<this->Tasks.size();i++){
        if(!id.compare(to_string(this->Tasks[i].getid()))){
            check=true;
            break;
        }
    }
    SetConsoleTextAttribute(col,2);
    if(check){
        if(this->Tasks[i].getcompleteness()){
            co("Task is already completed!");

        }else{
            this->Tasks[i].setcompleteness();
            co("Task completed Successfully!");
        }
        SetConsoleTextAttribute(col,7);
        sleep(3);
    }else{
        system("cls");
        co("Please Enter a Valid ID!");
        sleep(3);
        this->markTask();
    }
}
//if we want to view all the available tasks, we use this method
void viewtasks(){
SetConsoleTextAttribute(col,4);
cout<<setfill(' ')<<left<<setw(6)<<"ID"<<setfill(' ')<<setw(80)<<"Description"<<setfill(' ')<<left<<setw(15)<<"Is Completed?\n";
cout<<endl;
SetConsoleTextAttribute(col,15);

for(auto elem:this->Tasks){
cout<<setfill(' ')<<left<<setw(6)<<elem.getid()<<setfill(' ')<<setw(80)<<elem.getdescription();

if(elem.getcompleteness()){
    cout<<setfill(' ')<<left<<setw(3)<<"YES"<<endl;}
else{
    cout<<setfill(' ')<<left<<setw(3)<<"NO"<<endl;}

}
cout<<endl;

}
//if we want to exit from our system, we call this method.
void Exit(){
    system("cls");
    SetConsoleTextAttribute(col,4);
    co("Thanks For Using Our System!");
    SetConsoleTextAttribute(col,15);
    sleep(4);
}
};

int main(){

System s;
s.Run();
}

