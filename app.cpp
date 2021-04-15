#include<iostream>
#include <iomanip>
#include<stack>
#include<fstream>
#include<vector>
#include <ctime>
#include<string>
using namespace std;



void del(int n);
 int calls(string filename);
 vector<string> timer();
 void help();
 void ls();





 int calls(string filename){
    int pk=0;
    string s;
fstream r(filename);
r.seekg (0, ios::end);
unsigned int length = r.tellg();
if (length==0)
{
   
    r.close();
    return 0;
}
else{
 
 r.seekg (0, ios::beg);
while (getline (r,s)) {
 
  pk++;
  
}

// Close the file
r.close();
return pk;
}

}

vector<string> timer(){
    vector<string>Months {"Jan" ,"Feb", "Mar", "Apr", "May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    
    time_t my_time = time(NULL);
   
    string ok= ctime(&my_time);
   //13-4-2021
      

    vector <string> tokens;
      
    
    stringstream check1(ok);
      
    string intermediate;
      
   
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
    int i;
    for( i=0;i<Months.size();i++){
        if(Months[i]==tokens[1]){
            break;
        }
    }
    string cat= tokens[4];
string cat2;
for(int i=0;i<cat.size();i++){
    if(cat[i]=='\n'){
        continue;
    }
    cat2+=cat[i];
}
    int y=i+1;
    string stri = to_string(y);
      vector<string>l1;
      l1.push_back(tokens[2]);
      l1.push_back(stri);
      l1.push_back(cat2);
  return l1;
}




void help(){
const char separator= ' ';
const int nameWidth= 40;
 
cout<<"Usage :-"<<endl;
cout<<" $ ./todo add \"todo item\""<< setw(31)<<"#Add a new todo"<<endl;
cout<<" $ ./todo ls"<< setw(50) << setfill(separator) <<"#Show remaining todos"<<endl;
cout<<" $ ./todo del NUMBER"<<setw(35) << setfill(separator) <<"#Delete a todo"<<endl;
cout<<" $ ./todo done NUMBER "<<setw(36) << setfill(separator) <<"#Complete a  todo"<<endl;
cout<<" $ ./todo help"<<  setw(38) << setfill(separator) <<"#Show usage"<<endl;
cout<<" $ ./todo report "<<setw(35) << setfill(separator) <<"#Statistics"<<endl;
}


void ls(){
string s;

stack<string> list;

ifstream r("todo.txt");
r.seekg (0, ios::end);
unsigned int length = r.tellg();
if (length==0)
{
   
    r.close();
    cout<<"file is empty"<<endl;
}
else{
r.seekg (0, ios::beg);

while (getline (r,s)) {
 
   list.push(s);
 
 
}
r.close();
}
while (!list.empty())
{
    /* code */
    cout<<"["<<list.size()<<"]  "<<list.top()<<endl;
    
    list.pop();
    
}

  
}


void add(string a2){
    vector<string> l1;
    string temp;
    ifstream read;
    int found=0;
    read.open("todo.txt");
    while(read){
        getline(read,temp);
        l1.push_back(temp);
    }
    read.close();
    bool check=false;//task not present
    int i=0;
    for(i;i<l1.size();i++){
        if(a2==l1[i]){
            check=true;//task already present
            found=i;
        }
    }
    
    if(check==false){
        ofstream write;
        write.open("todo.txt",ios::app);
        
        write<<a2<<endl;
        cout<<"Added todo: "<<a2<<endl;
        write.close();
       


        
    }
    else{
        //refresh it 
        found+=1;//i starts with 0
        del(found);
        ofstream write;
        write.open("todo.txt",ios::app);
        
        write<<a2<<endl;
        cout<<"Added todo: "<<a2<<endl;
        write.close();
       


    }
    
    }




void del(int n){
      int present_line= calls("todo.txt");
    if((n>present_line) || (n<1)){
        cout<<"#"<<n<<"doesn't exist";
    }else{
string s;
int line=0;
ifstream r;
r.open("todo.txt");
ofstream w;
w.open("sam.txt",ofstream::out);
while(getline(r,s)){
 line=line+1;
 if(line==n){
  continue;
 }
w<<s<<endl;
}


w.close();
r.close();
remove("todo.txt");
rename("sam.txt","todo.txt");
cout<<"Deleted todo #"<<n;
    }

   

}


string del1(int n){
    int present_line= calls("todo.txt");
    if((n>present_line) || (n<1)){
        string ex="exit";
        return ex;
    }
    else{
string s1,s;
int line=0;
ifstream r;
r.open("todo.txt");
ofstream w;
w.open("sam.txt",ofstream::out);
while(getline(r,s)){
 line=line+1;
 if(line==n){
     s1=s;
  continue;
 }
w<<s<<endl;
}

 w.close();
 r.close();
 remove("todo.txt");
 rename("sam.txt","todo.txt");
 return s1;
    }
 }

void done(int n){

  
vector<string> op;
op=timer();

string combine="x "+op[2]+"-"+op[1]+"-"+op[0]+"  ";
    
  

    string ok=del1(n);
    if(ok=="exit"){
       cout<<"#"<<n<<"doesn't exist"<<endl;
    }
    else{
    ofstream write;
      
        write.open("done.txt",ios::app);
      
       write<<combine;
   
        write<<ok<<endl;
        cout<<"Marked todo #"<<n<<" as done."<<endl;
       
        write.close();
    }
    
   

}


void report(){
int ok=calls("todo.txt");
vector<string> op;
op=timer();

string combine=op[0]+"/"+op[1]+"/"+op[2]+":";
cout<<combine<<"\tpending: "<<ok;
int ok1=calls("done.txt");
cout<<"\tcompleted: "<<ok1;

}
int main(int argc,char* argv[]){
    string a1,a2;
    if(argc>1)
    a1=argv[1];
    if((argc==1) || (a1=="help")){
        help();


    }
    else if(a1=="ls"){
        ls();
    }
    else if(a1=="add"){
        if(argc==2){
            cout<<"ERROR.... missing todo string! Nothing added"<<endl; 
        }
        else{
        a2=argv[2];
        add(a2);
        }

    }
    else if(a1=="del"){
        if(argc==2){
            cout<<"ERROR.... missing todo number! Nothing deleted"<<endl;
        }
        else{
        a2=argv[2];
        int num=stoi(a2);
        if(num>0){
        del(num);
        }
        else{
           cout<<"ERROR  #0 doesn't exist"<<endl; 
        }

    }}
    else if(a1=="done"){
        if(argc==2){
            cout<<"ERROR.... missing todo number! Nothing marked completed"<<endl;
        }
        else{
        a2=argv[2];
        int num=stoi(a2);
        if(num>0){
            done(num); 
            }
        else{
            cout<<"ERROR  #0 doesn't exist"<<endl;
            }
        }
         
    }
    else if(a1=="report"){
        report();
    }
}