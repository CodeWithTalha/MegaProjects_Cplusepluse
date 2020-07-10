#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include<ctime> //for time
#include<fstream>
int drawLine(int n, char symbol);
void rules();
using namespace std; 

struct player
{
	string Name;
	unsigned int amount;
};    

int main()
{	
	string playerName;  
   	unsigned int amount; // hold player's balance amount
   	unsigned int bettingAmount;
    int guess,mode,no;
    int dice; // hold computer generated number
    char choice;
    
    drawLine(60,'_');
    cout<<"\n\n\n\t* * *  \t ******\t *    *   "<<endl;
	cout<<"\t*    * \t *    *\t **   *   "<<endl;
	cout<<"\t*     *\t *    *\t * *  *   "<<endl;
	cout<<"\t*     *\t *    *\t *  * *   "<<endl;
	cout<<"\t*    * \t *    *\t *   **   "<<endl;
	cout<<"\t* * *  \t ******\t *    *   \n"<<endl;
    drawLine(60,'_');    

	cout<<"\n--> Press 1 to Continue:"<<endl;
	cout<<"--> Press 2 for New Game:"<<endl;
	int g;cin>>g;
	

	player p1;
	
	ifstream in("DON.txt");	

		in>>p1.Name;
		in>>p1.amount;
		in.close();	
	
	if(g==1)
	{
		playerName=p1.Name;
		amount=p1.amount;
		goto abc;
		
	}
	else
	
    {
       	
    cout << "\n\nEnter Your Name : ";
    cin>>playerName;
	//getline(cin, playerName);
 
    cout << "\n\nDeposit Money to play the game : $";
    cin >> amount;
    
    
    
abc:
    do
    {
        system("cls");
        rules();
        
xyz:
        cout<<"\n-->Press 1 to Enter Double or Nothing Mode:"<<endl;
        cout<<"-->Press 2 to Enter x10 Mode:(x10 Mode is x10 Harder)"<<endl;
        cin>>mode;
        if(mode==1)
        {
        	mode=2;        
        	no=10;
		}
		else if (mode==2)
		{
			mode=10;		
			no=100;
		}
		else
		{
			cout<<"Please Select The Mode:) "<<endl;
			goto xyz;
		}
		
        cout << "\n\nYour current balance is $ " << amount << "\n";
		
		// Get player's betting amount
        do
        {
        cout <<playerName<<"\tPlay Your bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout<< "Your betting amount is more than your current balance\n"
                <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);
 
		// Get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to "<<no<<":";
            cin >> guess;
            if(guess <= 0 || guess > no)
                cout << "Please check the number!! should be between 1 to "<<no<<"\n"
                <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > no);
        
 		srand(time(0));  // genrates random no each time
        dice = rand()%no + 1; // dice hold the randomly generated integer 
    
        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won $" << bettingAmount * mode;
            amount = amount + bettingAmount * mode;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }
 
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
    drawLine(70,'=');    
    
    cout<<"\n\n-->To Save The Game Progress Press 1::\n-->Or If You Dont Want To Save The Game Press 2::"<<endl;
    int p;
    cin>>p;
    if(p==1)
    {
    	ofstream player("DON.txt");
    	player<<playerName<<endl<<amount<<endl;
    	player.close();
    	cout<<"Game Saved Successfully";
    	
	}	
	
	else
	{
		cout<<"\n\nPress Any To Exit:)";
	}	
	
}
 
    return 0;
}
 
int drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        {
        	cout << symbol;
		}
    //	cout <<endl ;
}
 
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\n\n\t\tBetting Rules"<<endl;
    drawLine(80,'-');
    cout << "\n\t1. Choose one number between \n";
    cout << "\t2. If you win you will get 2 times in DON mode of money you bet\n";
    cout << "\t3. If you win you will get 10 times in x10 mode of money you bet\n";
    cout << "\t4. If you bet on wrong number you will lose your betting amount\n\n";
    cout << "\t5. Save the Game so You dont Lose your Progress\n\n";
    drawLine(80,'-');
}
 
// The End

