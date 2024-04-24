#include<iostream>
#include<vector>
#include<map>
using namespace std;

void take_operand(int &num1,int &num2){
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    
}

void conver_to_unary(int num,string &unaryNum){
    for(int i=0;i<num;i++){
        unaryNum+="1";
    }
}

void setTape(vector<string> &tape,string unaryNum1,string unaryNum2){
    int i=1;
    for(int j=0;j<unaryNum1.size();j++){
        tape[i]=unaryNum1[j];
        i++;
    }
    tape[i]="*";

    i++;
    for(int j=0;j<unaryNum2.size();j++){
        tape[i]=unaryNum2[j];
        i++;
    }

    tape[i]="=";

   
}

void printTape(vector<string> tape){
    for(int i=0;i<tape.size();i++){
        cout<<tape[i];
    }
    cout<<endl;
}

void printUnary(string unaryNum){
    cout<<unaryNum<<endl;
}

void Multiplication_TM(vector<string> &tape,vector<string> &pointer,map<vector<string>,vector<string>> TMstateRecord){
    string nextState="s1";
    int pl=1;
    int counter=1;
    int choice;
    bool pauser=true;
    cout<<"Lets start the Turing Machine"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
      

     while(true){
        if(nextState=="s8"){
            break;
        }

        string currentState=nextState;
        string tapeSymbol=tape[pl];
        vector<string> key={currentState,tapeSymbol};
        vector<string> value=TMstateRecord[key];
        nextState=value[0];
        tape[pl]=value[1];
        string move=value[2];

       

        pointer[pl]="|";
        cout<<"Step: "<<counter<<endl;
        cout<<"The current state is: "<<currentState<<endl;
        cout<<"The tape symbol is: "<<tapeSymbol<<endl;
        cout<<"The next state is: "<<nextState<<endl;
        cout<<"The write symbol is: "<<value[1]<<endl;
        cout<<"The move is: "<<move<<endl;
        printTape(pointer);
        printTape(tape);
        cout<<"--------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<endl;
        counter++;

        pointer[pl]=" ";
         if(move=="R"){
            pl++;
        }else if(move=="L"){
            pl--;
        }

        
       

        if(pauser){
            cout<<"1=>next Step"<<"   ";
            cout<<"{any}-{1}=>run till end"<<endl;
            cin>>choice;
            if(choice!=1){
                pauser=false;
            }
        }


     }
}

int main(){
   //The value to be multiplied
   int num1,num2;
   take_operand(num1,num2);

   //Declaring tape for the Turing Machine
   vector<string> tape(100,"_");
   vector<string> pointer(100," ");
  

   //Converting the numbers to unary
   string unaryNum1="";
   string unaryNum2="";
   conver_to_unary(num1,unaryNum1);
   conver_to_unary(num2,unaryNum2);

   //Printing the unary numbers
   cout<<"The unary number 1 "<<endl;
   printUnary(unaryNum1);
   cout<<"The unary number 2"<<endl;
   printUnary(unaryNum2);

    //Setting the tape
    setTape(tape,unaryNum1,unaryNum2);

    

    //The state of the Turing Machine
    //  Sate+tape_symbol->new_state+write_symbol+move

    map<vector<string>,vector<string>> TMstateRecord;

    TMstateRecord[{"s1","1"}]={"s2","X","R"};
    TMstateRecord[{"s1","*"}]={"s8","*","R"};
    TMstateRecord[{"s1","0"}]={"s7","0","R"};

    TMstateRecord[{"s2","1"}]={"s2","1","R"};
    TMstateRecord[{"s2","*"}]={"s3","*","R"};

    TMstateRecord[{"s3","1"}]={"s4","Y","R"};
    TMstateRecord[{"s3","0"}]={"s7","0","R"};
    TMstateRecord[{"s3","="}]={"s6","=","L"};

    TMstateRecord[{"s4","1"}]={"s4","1","R"};
    TMstateRecord[{"s4","="}]={"s4","=","R"};
    TMstateRecord[{"s4","_"}]={"s5","1","L"};

    TMstateRecord[{"s5","1"}]={"s5","1","L"};
    TMstateRecord[{"s5","="}]={"s5","=","L"};
    TMstateRecord[{"s5","Y"}]={"s3","Y","R"};

    TMstateRecord[{"s6","1"}]={"s6","1","L"};
    TMstateRecord[{"s6","Y"}]={"s6","1","L"};
    TMstateRecord[{"s6","X"}]={"s1","X","R"};
    TMstateRecord[{"s6","*"}]={"s6","*","L"};

    TMstateRecord[{"s7","1"}]={"s7","1","R"};
    TMstateRecord[{"s7","*"}]={"s7","*","R"};
    TMstateRecord[{"s7","0"}]={"s7","0","R"};
    TMstateRecord[{"s7","="}]={"s7","=","R"};
    TMstateRecord[{"s7","_"}]={"s1","0","R"};


    

    //The Turing Machine
    Multiplication_TM(tape,pointer,TMstateRecord);

    
    return 0;
}