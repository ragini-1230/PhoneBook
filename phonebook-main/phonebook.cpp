#include<iostream>
#include<windows.h>
using namespace std;

void start();
int menu();
int k=0; 

int main()
{
    start();
    string name[100], no[100];
    int check;
    int Total_contacts=0;
    check=menu();
    do{
        //Add Contact
        if(check==1){
            cout<<"\t\t\t\t\t\tName : ";
            cin>>name[k]; 
            cout<<"\t\t\t\t\t\tPhone No. :";
            cin>>no[k];
            k++;
            Total_contacts++;
        }

        //Display Contact
        else if(check==2){
            int check2=0;
            for(int i=0;i<k;i++){
                if(name[i]!="\0")
                cout<<"\t\t\t\t\t\tName :"<<name[i]<<"          Phone :"<<no[i]<<endl;
                check2++;
            }
            if(check2==0){
                cout<<"\t\t\t\t\t\tYour Contact list is empty";
            }
        }

        //Search by Number
        else if(check==3){
            string temp;
            cout<<"\t\t\t\t\t\tNumber : ";
            cin>>temp;
            int check2=0;

            for(int i=0;i<k;i++){
                if(no[i]==temp){
                    cout<<"\t\t\t\t\t\tNumber is found\n";
                    cout<<"\t\t\t\t\t\tName :"<<name[i]<<"          Phone :"<<no[i]<<endl;
                    check2++;
                }
            }
            if(check2==0){
                cout<<"\t\t\t\t\t\t This Name is Not Found in your contact list\n";
            }
        }

        //Search by Name
        else if(check==4){
            string temp;
            cout<<"\t\t\t\t\t\tName : ";
            cin>>temp;
            int check2=0;

            for(int i=0;i<k;i++){
                if(name[i]==temp){
                    cout<<"\t\t\t\t\t\tName is found\n";
                    cout<<"\t\t\t\t\t\tName :"<<name[i]<<"          Phone :"<<no[i]<<endl;
                    check2++;
                }
            }
            if(check2==0){
                cout<<"\t\t\t\t\t\t This Name is Not Found in your contact list\n";
            }
        }

        //Update
        else if(check==5){
            string temp, temp2, temp3;
            cout<<"\t\t\t\t\t\tName : ";
            cin>>temp;
            int check2=0;

            for(int i=0;i<k;i++){
                if(name[i]==temp){
                    cout<<"\t\t\t\t\t\tNew Name : ";
                    cin>>temp2;
                    cout<<"\t\t\t\t\t\tNew Number : ";
                    cin>>temp3;
                    name[i]=temp2;
                    no[i]=temp3;
                    cout<<"\t\t\t\t\t\tName :"<<name[i]<<"          Phone :"<<no[i]<<endl;
                    check2++;
                    cout<<"\t\t\t\t\t\tUpdated Successfully ";

                }
            }
            if(check2==0){
                cout<<"\t\t\t\t\t\t This Name is Not Found in your contact list\n";
            }
        }

        //Delete
        else if(check==6){
            string temp;
            cout<<"\t\t\t\t\t\tFor Delete Enter Name : ";
            cin>>temp;
            int check2=0;

            for(int i=0;i<k;i++){
                if(name[i]==temp){
                    cout<<"\t\t\t\t\t\tDeleted Successfully\n";
                    cout<<"\t\t\t\t\t\tName :"<<name[i]<<"          Phone :"<<no[i]<<endl;
                    name[i]='\0';
                    no[i]='\0';
                    check2++;
                    Total_contacts--;

                }
            }
            if(check2==0){
                cout<<"\t\t\t\t\t\t This Name is Not Found in your contact list\n";
            }
        }

        //Delete All 
        else if(check==7){
            cout<<"\t\t\t\t\t\tAll Deleted Successfully\n";
            for(int i=0;i<k;i++){
                name[i]="\0";
                no[i]="\0";
            }
            k=0;
            Total_contacts=0;
        }   

        //Number of Contacts
        else if(check==8){
            cout<<"\t\t\t\t\t\tTotal Number of Contact list are : "<<Total_contacts<<endl;
        } 
        check=menu();
    }while(check!=9);
    return 0;
}

int menu(){
    cout<<"\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t--------------------------------------\n";
    cout<<"\t\t\t\t\t\t--------------------------------------\n";
    cout<<"\t\t\t\t\t\t|        PHONE BOOK APPLICATION      |\n";
    cout<<"\t\t\t\t\t\t--------------------------------------\n";
    cout<<"\t\t\t\t\t\t|                                    |\n";
    cout<<"\t\t\t\t\t\t|        [1] Add Contacts            |\n";
    cout<<"\t\t\t\t\t\t|        [2] Display All Contacts    |\n";
    cout<<"\t\t\t\t\t\t|        [3] Search by Number        |\n";
    cout<<"\t\t\t\t\t\t|        [4] Search by Name          |\n";
    cout<<"\t\t\t\t\t\t|        [5] Update                  |\n";
    cout<<"\t\t\t\t\t\t|        [6] Delete                  |\n";
    cout<<"\t\t\t\t\t\t|        [7] Delete All              |\n";
    cout<<"\t\t\t\t\t\t|        [8] Number of Contacts      |\n";
    cout<<"\t\t\t\t\t\t|                                    |\n";
    cout<<"\t\t\t\t\t\t--------------------------------------\n";
    cout<<"\t\t\t\t\t\t|                                    |\n";
    cout<<"\t\t\t\t\t\t--------------------------------------\n";    
    cout<<"\t\t\t\t\t\t|              [9] Exit              |\n";
    cout<<"\t\t\t\t\t\t--------------------------------------\n";  
    int a;
    cout<<"Enter your choice"<<endl;
    cin>>a;  
    system("cls");
    return a;
}


void start(){
    system("Color 0B");
    cout<<"\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t-------------------------------------\n";
    cout<<"\t\t\t\t\t\t-------------------------------------\n";
    cout<<"\t\t\t\t\t\t      PHONE BOOK APPLICATION\n";
    cout<<"\t\t\t\t\t\t-------------------------------------\n";
    cout<<"\t\t\t\t\tLoading ";
    char x=219;
    for(int i=0;i<35; i++)
    {
        cout<<x;
        if(i<10)
        Sleep(300);
        if(i>=10 && i<20)
        Sleep(150);
        if(i>=10);
        Sleep(25);
    }
    system("cls");
}