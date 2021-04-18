#include<iostream>
#include<vector>

using namespace std;

int arr[3][3];
string player1, player2;
int k,n;
vector <int> c ;

int display();
void print();
int input1(int);
int input2(int);
int check_row();
int check_column();
int check_leftdiagonal();
int check_rightdiagonal();
int check();

int main(){
    
    cout << "Enter player name 1 : ";
    cin >> player1 ;

    cout << "Enter player name 2 : ";
    cin >> player2;

    cout<< "\n\n\t\tTIC TAC TOE\n\n";
   // print();
   for( int i = 0 ; i < 9 ; i = i+2){
        print();
        input1(i);
        display();
        if(i+1 < 9 ){
            print();
            input2(i+1);
            display();
        }
    }

    printf("WELL DONE ! THIS MATCH BECOME DRAW....\n");
    return 0;
}
  

void print(){
    cout<<"\nTYPE THE NUMBER\n";
    for( int i = 0 ; i < 8*6 ; i++ )    cout<<"-";
    cout << "\n|\t1\t|\t2\t|\t3\t|\n";
    for( int i = 0 ; i < 8*6 ; i++ )    cout<<"-";
    cout << "\n|\t4\t|\t5\t|\t6\t|\n";
    for( int i = 0 ; i < 8*6 ; i++ )    cout<<"-";
    cout << "\n|\t7\t|\t8\t|\t9\t|\n";
    for( int i = 0 ; i < 8*6 ; i++ )    cout<<"-";

    return;
}

int input1(int index){
    cout<< "\n\n";
      
    cout << player1 <<", Enter the number between 1-9 : ";
    cin >> n;
    if(n<=0 || n>9){
        printf("Wrong numbers type between 1-9\n");
        input1(index);
    }
    int size = c.size();
    if(c.empty()){
        c.push_back(n);
    }
    else{
        for(int i = 0 ; i < size; i++){
        if( c[i] == n){
            cout<<"OOPS !!! the given number was already existed\n";
            input1(index);
        }
        }
    }
    c.push_back(n);
    switch (n)
    {
    case 1:
        arr[0][0] = 1;
        break;
    
    case 2:
         arr[0][1] = 1;
         break;

    case 3:
        arr[0][2] = 1;
        break;
    
    case 4:
        arr[1][0] = 1;
        break;

    case 5:
        arr[1][1] = 1;
        break;

    case 6:
        arr[1][2] = 1;
        break;
    
    case 7:
        arr[2][0] = 1;
        break;

    case 8:
        arr[2][1] = 1;
        break;

    case 9:
        arr[2][2] = 1;
        break;
    }
    check();
   // display();

    return 0;
}

int input2(int index){
    
    cout<<"\n";
    cout << player2 <<", Enter the number between 1-9 : ";
    cin >> n;
    if(n<=0 || n>9){
        printf("Wrong numbers type between 1-9\n");
        input1(index);
    }
    int size = c.size();
    if(c.empty()){
        c.push_back(n);
    }
    else{
        for(int i = 0 ; i < size; i++){
        if( c[i] == n){
            cout<<"OOPS !!! the given number was already existed\n";
            input2(index);
        }
        }
    }
    c.push_back(n);
    switch (n)
    {
    case 1:
        arr[0][0] = 2;
        break;
    
    case 2:
         arr[0][1] = 2;
         break;

    case 3:
        arr[0][2] = 2;
        break;
    
    case 4:
        arr[1][0] = 2;
        break;

    case 5:
        arr[1][1] = 2;
        break;

    case 6:
        arr[1][2] = 2;
        break;
    
    case 7:
        arr[2][0] = 2;
        break;

    case 8:
        arr[2][1] = 2;
        break;

    case 9:
        arr[2][2] = 2;
        break;
    }

    check();
    //display();

    return 0;
}

int display(){
    cout<<"\n\n";
    for(int k = 0 ; k < 8*6 ; k++)  cout<<"-";
    cout<<"\n";
    for( int i = 0 ; i < 3 ; i++ ){
        for (int j = 0 ; j < 3 ; j++){
            if(arr[i][j] == 1){
                cout<<"|\tX\t|";
                }
            else if(arr[i][j] == 2){
                cout<<"|\tO\t|";
            }
            else{
                cout<<"|\t \t|";
            }
        }
        cout<<"\n";
        for(int k = 0 ; k < 8*6 ; k++)  cout<<"-";
        cout<<"\n";

    }
    return 0;
}

int check_row(){
    for( int i = 0 ; i < 3 ; i++){
        if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] ){
            k = arr[i][0];
            if(k == 1){
                cout<< player1 << " has won the match by rows!!!";
                exit(0);
            }
            else if(k == 2){
                cout<< player2 << " has won the match by rows!!!";
                exit(0);
            }
        }
    }
    return 0;
}

int check_column(){
    for( int i = 0 ; i < 3 ; i++){
        if(arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] ){
            k = arr[0][i];
            if(k == 1){
                cout<< player1 << " has won the match by column!!!";
                exit(0);
            }
            else if(k == 2){
                cout<< player2 << " has won the match by column!!!";
                exit(0);
            }
        }
    }
    return 0;
}

int check_leftdiagonal(){
    if(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]){
        k = arr[0][0];
        if(k == 1){
            cout<< player1 << " has won the match by left diagonal!!!";
            exit(0);
        }
        else if(k == 2){
            cout<< player2 << " has won the match by left diagonal!!!";
            exit(0);
        }
    }
    return 0;
}

int check_rightdiagonal(){
    if(arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]){
        k = arr[0][2];
        if(k == 1){
            cout<< player1 << " has won the match by right diagonal!!!";
            exit(0);
        }
        else if(k == 2){
            cout<< player2 << " has won the match  by right diagonal!!!";
            exit(0);
        }
    }

    return 0;
}

int check(){
    check_row();
    check_column();
    check_leftdiagonal();
    check_rightdiagonal();

    return 0;
}

