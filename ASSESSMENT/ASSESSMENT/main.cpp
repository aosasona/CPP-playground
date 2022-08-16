//
//  ASSESSMENT - POULTRY MANAGEMENT CLI APPLICATION IN C++
//
//  Created by Ayodeji Osasona on 18/03/2022.
//

#include <iostream>
#include <fstream>

using namespace std;

//LOOP COUNTER
bool loopCounter = true;

//All sales variables at 0
int smallEggs, mediumEggs, bigEggs, smallChicken, mediumChicken, bigChicken = 0;

//All sales PLACEHOLDER variables at 0
int smallEggsP, mediumEggsP, bigEggsP, smallChickenP, mediumChickenP, bigChickenP = 0;


//All stocks variables at 0
int smallEggsStock, mediumEggsStock, bigEggsStock, smallChickenStock, mediumChickenStock, bigChickenStock = 0;

//Program's password
string password = "Ayodeji";

//Action selectors
int firstSelection, secondSelection, thirdSelection;


//Functions declaration
void addStocks(), viewStocks();
void addSales(), viewSales();
void saveFile();

int main() {
    
    string userPassword; //user-defined password
    
    cout<<"===============| Poultry Services Stock Management System |=============== \n\n";
    
    //Ask for the user's password
    do{
        cout<<"---> Enter your password <--- \n";
        cout<<"======> ";
        cin>>userPassword;
    }
    while(userPassword != password);
    
    cout<<"\n Hello! What do you want to do today? \n";
    
    //Make the application run continuously
    
    do{
        //Ask what the user wants to manage
        
        
        cout<<"(Enter any number corresponding to the section you want to manage, enter 0 to exit the program) \n\n";
        cout<<"\t 1 ---- Stocks \n";
        cout<<"\t 2 ---- Sales \n";
        do{
            //Repeat the question of the user chooses the wrong option
            cout<<"======> ";
            cin>>firstSelection;
        }
        while(firstSelection >= 3);
        
        if(firstSelection == 1){
            //If the user chooses stocks
            cout<<"\n Choose an action below \n";
            cout<<"\t 1 ---- Add New Record \n";
            cout<<"\t 2 ---- View Stocks \n";
        }
        else if (firstSelection == 0){
            exit(0);
        }
        else{
            //If the user chooses sales
            cout<<"\n Choose an action below \n";
            cout<<"\t 1 ---- Sell An Item \n";
            cout<<"\t 2 ---- View Sales \n";
            
        }
        
        //Get the second selection/action
        do{
        cout<<"======> ";
        cin>>secondSelection;
        }
        while(secondSelection >= 3);
        
        if(firstSelection == 1 && secondSelection == 1){
            
            //If user selects "Add new record" for Stocks
            addStocks();
            
            
        }
        else if (firstSelection == 1 && secondSelection == 2){
            //If user selects "View Stocks"
            viewStocks();
           
        }
        else if(firstSelection == 2 && secondSelection == 1){
            
            //If user selects "Add new record" for Sales
            addSales();
            
        }
        else if (secondSelection == 0){
            exit(0);
        }
        else {
            //If the useer chooses "View Sales"
            viewSales();
        }
    }
    while(loopCounter == true);
    
    return 0;
}


/*
 @Type - FUNCTION
 @Purpose - View Stocks
 */
void viewStocks() {
    cout<<"\n\n============| Current Stocks |============";
    cout<<"\n-----------------------------------------";
    cout<<"\n\t\t | Small Eggs \t\t | \t"<<smallEggsStock;
    cout<<"\n\t\t | Medium Eggs \t\t | \t"<<mediumEggsStock;
    cout<<"\n\t\t | Big Eggs \t\t | \t"<<bigEggsStock;
    cout<<"\n-----------------------------------------\n";
    cout<<"\t\t | Small Chicken \t | \t"<<smallChickenStock;
    cout<<"\n\t\t | Medium Chicken \t | \t"<<mediumChickenStock;
    cout<<"\n\t\t | Big Chicken \t\t | \t"<<bigChickenStock;
    cout<<"\n-----------------------------------------\n\n";
    
}


/*
 @Type - FUNCTION
 @Purpose - Add Stocks
 */
void addStocks() {
    cout<<"Enter the amount of stocks you want to add for: \n";
    //For Eggs
    cout<<"=================================================== \n EGGS \n===================================================";
    cout<<"\n\t Small =====> ";
    cin>>smallEggsStock;
    cout<<"\n\t Medium ====> ";
    cin>>mediumEggsStock;
    cout<<"\n\t Big ====> ";
    cin>>bigEggsStock;
    
    //For Chicken
    cout<<"=================================================== \n CHICKEN \n===================================================";
    cout<<"\n\t Small =====> ";
    cin>>smallChickenStock;
    cout<<"\n\t Medium ====> ";
    cin>>mediumChickenStock;
    cout<<"\n\t Big ====> ";
    cin>>bigChickenStock;
    
    cout<<"\n=================================================== \n";
    cout<<"\t All stocks have been recorded";
    cout<<"\n=================================================== \n";
    
    saveFile();
    
}


/*
 @Type - FUNCTION
 @Purpose - View Sales
 */
void viewSales() {
    cout<<"\n\n============| Current Sales |============";
    cout<<"\n-----------------------------------------";
    cout<<"\n\t\t | Small Eggs \t\t | \t"<<smallEggs;
    cout<<"\n\t\t | Medium Eggs \t\t | \t"<<mediumEggs;
    cout<<"\n\t\t | Big Eggs \t\t | \t"<<bigEggs;
    cout<<"\n-----------------------------------------\n";
    cout<<"\t\t | Small Chicken \t | \t"<<smallChicken;
    cout<<"\n\t\t | Medium Chicken \t | \t"<<mediumChicken;
    cout<<"\n\t\t | Big Chicken \t\t | \t"<<bigChicken;
    cout<<"\n-----------------------------------------\n\n";
}


/*
 @Type - FUNCTION
 @Purpose - Add Sales
 */
void addSales() {
    /* @todo - Add prompt when stock is empty for each category */
    
    cout<<"Enter the amount of stocks you want to add for: \n";
    //For Eggs
    cout<<"=================================================== \n EGGS \n===================================================";
    
    cout<<"\n\t Small =====> ";
    cin>>smallEggsP;
    if(smallEggsP > smallEggsStock){
        cout<<"Chief, you're low on stock for small eggs!";
    } else {
        smallEggs = smallEggsP;
        smallEggsStock = smallEggsStock - smallEggsP;
    }
    
    cout<<"\n\t Medium ====> ";
    cin>>mediumEggsP;
    if(mediumEggsP > mediumEggsStock){
        cout<<"Chief, you're low on stock for medium eggs!";
    } else {
        mediumEggs = mediumEggsP;
        mediumEggsStock =  mediumEggsStock - mediumEggsP;
    }
    
    cout<<"\n\t Big ====> ";
    cin>>bigEggsP;
    if(bigEggsP > bigEggsStock){
        cout<<"Chief, you're low on stock for big eggs!";
    } else {
        bigEggs = bigEggsP;
        bigEggsStock = bigEggsStock - bigEggsP;
    }
    
    //For Chicken
    cout<<"\n=================================================== \n CHICKEN \n===================================================";
    
    cout<<"\n\t Small =====> ";
    cin>>smallChickenP;
    if(smallChickenP > smallChickenStock){
        cout<<"Not enough small chicken!";
    }
    else {
        smallChicken = smallChickenP;
        smallChickenStock = smallChickenStock - smallChickenP;
    }
    
    cout<<"\n\t Medium ====> ";
    cin>>mediumChickenP;
    if(mediumChickenP > mediumChickenStock){
        cout<<"Not enough medium chicken!";
    }
    else {
        mediumChicken = mediumChickenP;
        mediumChickenStock = mediumChickenStock - mediumChickenP;
    }
    
    cout<<"\n\t Big ====> ";
    cin>>bigChickenP;
    if(bigChickenP > bigChickenStock){
        cout<<"Not enough big chicken!";
    }
    else {
        bigChicken = bigChickenP;
        bigChickenStock = bigChickenStock - bigChickenP;
    }
    
    cout<<"\n=================================================== \n";
    cout<<"\t All stocks have been recorded";
    cout<<"\n=================================================== \n";
    
    /* =================== SALES RECORD  =================== */
    //Append to chicken sales
    fstream chickenSaleFile;
    
    chickenSaleFile.open("SMS-Sales-10032022.txt", ios::app);
    
    if(!chickenSaleFile){
        cout<<"File not created!";
    } else {
        chickenSaleFile<<"==============================\n SALES \n==============================\n"<<"Small Chicken -> "<<smallChicken<<"\nMedium Chicken -> "<<mediumChicken<<"\nBig Chicken -> "<<bigChicken<<"\n"<<"Small Eggs -> "<<smallEggs<<"\nMedium Eggs -> "<<mediumEggs<<"\nBig Eggs -> "<<bigEggs<<"\n"<<endl;
        chickenSaleFile.close();
    }
    
    saveFile();

}


/*
 @Type - FUNCTION
 @Purpose - Save Files
 */
void saveFile() {
    //Write to the chicken files
    fstream chickenFile;
    
    chickenFile.open("SMS-Chicken-10032022.txt", ios::out);
    
    if(!chickenFile){
        cout<<"File not created!";
    } else {
        chickenFile<<"Small Chicken -> "<<smallChickenStock<<"\nMedium Chicken -> "<<mediumChickenStock<<"\nBig Chicken -> "<<bigChickenStock<<endl;
        chickenFile.close();
    }
    
    //Write to the egg files
    fstream eggFile;
    
    eggFile.open("SMS-Eggs-10032022.txt", ios::out);
    
    if(!eggFile){
        cout<<"File not created!";
    } else {
        cout<<"File created successfully! \n";
        eggFile<<"Small Eggs -> "<<smallEggsStock<<"\nMedium Eggs -> "<<mediumEggsStock<<"\nBig Eggs -> "<<bigEggsStock<<endl;
        eggFile.close();
    }
    
    
}
