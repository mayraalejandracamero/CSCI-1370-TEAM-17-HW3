//****************************************************************************** //
//  Team # 17             CSCI/CMPE 1370          Spring2020              Homework # 3 
// Mayra Alejandra Camero 
// Alexander Camacho 
// this program allows mathematical operations to be made on rational number 
// 1. displayed a void function to show our options (menu)
// 2. gets the values from the user (get rational)
// 3. reduces the values by finding the greatest common factoe and the absolute value (function reduce)
// 4. adding the rational fractions by a + c = (a * d) + (c * b) b d (b * d) (add rational)
// 5. subtracts the raional fractions by a - c = (a * d) - (c * b) b d (b * d) (subtract rational)
// 6. (display rational)
// 7. void functions for add and subtract and display 
// 7. main function --> switch cases for upper case and lower case options plus showMenu()
// //******************************************************************************



//-------------------------------------MENU--------------------------------------//
#include <iostream>
// #include hw3functions.h --> ????
using namespace std;



int gcd(int a, int m) // gcd --> greatest common denominator  
{
if (a == 0)
return m;
return gcd(m % a, a);
}
void showMenu(){
   system("cls"); // system("cls") --> use to clear the screen
cout<<   "\n_______________________________________________________________________________\n"
<<"Rational numbers calculator\n"
<<"(A)ddition\n"
<<"(S)ubtraction\n"
<<"(Q)uit\n"
<<"Enter your option:_\n"
<<"_______________________________________________________________________________\n";
}
//----------------------------------------------------------------------------------//






//--------------------------------Get Rational -----------------------------------//
//GetRational(int num, int den);
// This function shows the prompt Please enter a fraction (n/d): , gets the values 
// from the keyboard and returns them to the caller. Since the division operator (/) 
// is read in along with the numbers the function must read and discard it
// This function must reject a denominator equal to zero

void GetRational(int &num,int &den){
   char c;
   while(1){
   cout<<"\nPlease enter a fraction (n/d) ";
   cin>>num>>c>>den;
   if(den == 0)
   cout<<"\nDenominator must not be 0";
   else break;}
}
//--------------------------------------------------------------------------------//






//--------------------------------Function Reduce-----------------------------------//
// reduce(int num, int den)
// num and den are provided by the caller
// num and den are reduced according to the algorithm explained below and returned to the caller

void reduce(int &num,int &den){
   int gcf = gcd(num,den); // gfc --> greatest common factor 
   num /= gcf;
   den /= gcf;
}
//--------------------------------------------------------------------------------//





//--------------------------------Add Rational -----------------------------------//
//AddRational(int anum, int aden, int num1, int den1, int num2, int den2); 
// num1, den1, num2, and den2 are provided by the caller
// anum and aden are calculated using the formula shown above and returned to the 
// caller after they are reduced. To reduce the fraction this function must call the function reduce(anum, aden)

void AddRational(int &anum,int &aden,int num1,int den1,int num2,int den2){
   anum=(num1*den2)+(num2*den1);
   aden=(den1*den2);
   reduce(anum,aden);
}
//--------------------------------------------------------------------------------//




//----------------------------Subtract Rational -----------------------------------//
//SubtractRational(int anum, int aden, int num1, int den1, int num2, int den2); 
// num1, den1, num2, and den2 are provided by the caller
// anum and aden are calculated using the formula shown above and returned to the 
// caller after they are reduced. To reduce the fraction this function must call the function reduce(anum, aden)
void SubtractRational(int &anum,int &aden,int num1,int den1,int num2,int den2){
   anum=(num1*den2)-(num2*den1);
   aden=(den1*den2);
   reduce(anum,aden);
}
//--------------------------------------------------------------------------------//




//----------------------------Display Rational -----------------------------------//
// DisplayRational(int num, int den);
// num and den are provided by the caller.
// The numbers are shown in the form num/den unless den is equal to 1, in this case only the numerator should be displayed.

void DisplayRational(int anum,int aden){
   cout<<endl<<"The result is: "<<anum;
   if(aden != 1)
   cout<<" / "<<aden<<endl;
}
//--------------------------------------------------------------------------------//





void add(){
int num1,den1,num2,den2,anum,aden;
char status='N';
do{ status='N';
   system("cls");
GetRational(num1,den1);
GetRational(num2,den2);
AddRational(anum,aden,num1,den1,num2,den2);

DisplayRational(anum,aden);
cout<<"\nDo you want to do more additions?(Y/N)\n";
cin>>status;
}while(status=='Y' || status == 'y');
  
}

void subtract(){
int num1,den1,num2,den2,anum,aden;
char status='N';
do{ status ='N';
   system("cls");
GetRational(num1,den1);
GetRational(num2,den2);
SubtractRational(anum,aden,num1,den1,num2,den2);

DisplayRational(anum,aden);
cout<<"\nDo you want to do more substracions?(Y/N)\n";
cin>>status;
}while(status=='Y' || status == 'y');

  
}

int main() {
  
   char state;
do{ state = 'Q';  
   system("cls");
   showMenu();
   cin>>state;
  
   switch(state){  // rather the user puts uppercase or lowercase the program will pick it up
   case 'Q':
   case 'q':break;
  
   case 'A':
   case 'a': add();
   break;
   case 'S':
   case 's': subtract();
   break;
   default: break;
      
   }
  
}while((state != 'Q') && (state != 'q'));  
  
   return 0;
}