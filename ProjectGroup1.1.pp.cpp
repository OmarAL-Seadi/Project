// Omar Aqeel AL-Saedi      Ali Hamad         Fawaz Altahini           Ayman hassan alalmai         Abdulelah Ahmed Alzahrani
//    2220004560           2220005429          2220003471                   2220003287                    2220004084
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>            // no use
#include<ctime>             //printing time
#include<bits/stdc++.h>     // toupper input for string
using namespace std;




//------------------------------------------------------------------------struct start-----------------------------------------------------------------------------


struct Update{
string updatedProduct;
string updatedCompany;
string updatedPrice;                                                           
string updatedSells;
string updatedQuantity;	
};
struct lists{
string Product;
string Company;
string Price;                                                                 

string Sells;
string Quantity;
};


//--------------------------------------------------------------------------struct end----------------------------------------------------------------------------
                              
                              
                              
                                                       
//-----------------------------------------------------------------------fun Headers start------------------------------------------------------------------------


void saveed1 (lists data[],int numberOfItems);             // update input text file  fun

void load(lists data[],int &numberOfItems,int size);       // input from text file fun

void saveed (lists data[], int numberOfItems );             // output to text file fun

void sort (lists data[],int numberOfItems);                 // sort by name fun

void search (lists data[],int numberOfItems);               // search fun

void List (string Main[]);                                   //display list for user fun   
                 
void adding (lists data[], int &numberOfItems , int size);   // adding fun

void printing (lists data[],int numberOfItems );             // display fun

void Updating (lists data[], int &numberOfItems);             // Update fun

void Delete (lists data[], int &numberOfItems);              // Delete fun


//----------------------------------------------------------------------fun Headers end----------------------------------------------------------------------------




//------------------------------------------------------------------ start of main Program-------------------------------------------------------------------------	


int main()
{
  // size is array limet                                           
int size=100, numberOfItems=0, k=0;
lists data[size];
string fName="output.txt"; 
string Main[9]{"Adding","Search ","Update ","Delete","Sort","Display","Stop","Save","PRINT IN TEXT FILE"};
load(data,numberOfItems,size); 
string	PickItUp;
do{
cout<<endl<<"Main Services: "<<endl;
List (Main);        //display list for user fun   
getline(cin>>ws,PickItUp);   // ws for fixing some issues
transform(PickItUp.begin(), PickItUp.end(), PickItUp.begin(), ::toupper); // toupper input PickItUp

if (PickItUp =="STOP"){
	break;}
//----------------------------------------	
if (PickItUp =="ADDING"){
 adding (data,numberOfItems,size);}
//----------------------------------------	
 if (PickItUp =="UPDATE"){
 	Updating (data,numberOfItems);}
//----------------------------------------	 	
else if (PickItUp =="DELETE"){
Delete (data,numberOfItems);}
//----------------------------------------	 		
else if(PickItUp =="DISPLAY"){
printing (data,numberOfItems);}
//----------------------------------------	             
else if(PickItUp =="SORT"){
sort (data,numberOfItems);}
//----------------------------------------	                  
else if(PickItUp =="SEARCH"){
 search (data,numberOfItems);}
//----------------------------------------	                       
 else  if(PickItUp =="SAVE"){
	saveed1 (data,numberOfItems);}
//----------------------------------------	
else  if(PickItUp =="NO"){
cout<<numberOfItems;}       //not use just for fixing issuse 
//----------------------------------------						     	
 else  if(PickItUp =="PRINT IN TEXT FILE"){
saveed (data,numberOfItems);}
					            
					        
					            
				}
while (PickItUp != "STOP");   //for stoping when the user wnat
return 0;
}


//--------------------------------------------------------------------- End of main Program------------------------------------------------------------------------




//--------------------------------------------------------------------------fun start------------------------------------------------------------------------------





//------------------------------------------------------------------------adding fun start------------------------------------------------------------------------------    

                    
void adding (lists data[], int &numberOfItems , int size)
{
	string k="hh";
	while(k!="YES")
if (numberOfItems < size)
{
Update NewVl;
	cout<<"Product Name:"<<endl;
	cin>>NewVl.updatedProduct;
	cout<<"Product Company:"<<endl;
	cin>>NewVl.updatedCompany;
	cout<<"Price:"<<endl;
	cin>>NewVl.updatedPrice;
		cout<<"Quantity in Stock"<<endl;
	cin>>NewVl.updatedQuantity;                                                                         
		cout<<"Number of Sells"<<endl;
	cin>>NewVl.updatedSells;
data[numberOfItems].Product= NewVl.updatedProduct;
data[numberOfItems].Company= NewVl.updatedCompany;
data[numberOfItems].Price= NewVl.updatedPrice;
data[numberOfItems].Quantity= NewVl.updatedQuantity;
data[numberOfItems].Sells= NewVl.updatedSells;
numberOfItems++;
cout<<"Stop?";     	 
cin>>k;
transform(k.begin(), k.end(), k.begin(), ::toupper);}   // toupper input k 
} 


//----------------------------------------------------------------------adding fun end-------------------------------------------------------------------------------------------




//-----------------------------------------------------------------display list for user fun start-------------------------------------------------------------------------------


void printing (lists data[],int numberOfItems )
{
	cout<<"Product Name:"<<endl<<"\t \t";
	for(int i=0;i<numberOfItems;i++){
	cout<<data[i].Product<<"\t \t";}
	cout<<endl;
	cout<<"Product Company:"<<endl<<"\t \t";
		for(int i=0;i<numberOfItems;i++){
	cout<<data[i].Company<<"\t \t";}
		cout<<endl;
			cout<<"Price:"<<endl<<"\t \t";
		for(int i=0;i<numberOfItems;i++){                                                         
	cout<<data[i].Price<<"\t \t";}
		cout<<endl;
			cout<<"Quantity in Stock:"<<endl<<"\t \t";
			for(int i=0;i<numberOfItems;i++){
	cout<<data[i].Quantity<<"\t \t";}
		cout<<endl;
			cout<<"Number of Sells:"<<endl<<"\t \t";
			for(int i=0;i<numberOfItems;i++){
	cout<<data[i].Sells<<"\t \t";}
}


 //-----------------------------------------------------------------display list for user fun end-----------------------------------------------------------------------------------
 
 
 
 
//---------------------------------------------------------------------------Update fun start---------------------------------------------------------------------------------------


void Updating (lists data[], int &numberOfItems){
int k=0;
Update NewVl ;
string sName;
cout<<"Product Name Need Updating:";
cin>>sName;
for (int i=0;i< numberOfItems ;i++)
{
if (data[i].Product== sName) {
cout<<"Enter new Product Name:"<<endl;
cin>>NewVl.updatedProduct ;
data[i].Product= NewVl.updatedProduct;
cout<<"Enter Product Company:" <<endl;
cin>>NewVl.updatedCompany ;
data[i].Company= NewVl.updatedCompany;
cout<<"Enter Price:"<<endl;
cin>>NewVl.updatedPrice ;                                                                         
data[i].Price= NewVl.updatedPrice;
cout<<"Enter Quantity in Stock:"<<endl;
cin>>NewVl.updatedQuantity ;
data[i].Quantity= NewVl.updatedQuantity;
cout<<"Enter Number of Sells:"<<endl;
cin>>NewVl.updatedSells ;
data[i].Sells= NewVl.updatedSells;
 k=1;
break ;}}
cout<<"Product Updated";
if (k<=0){
cout<<"Product Not Found!"<<endl;}}


//----------------------------------------------------------------------------Update fun end-------------------------------------------------------------------------------------------




//-----------------------------------------------------------------------------Delete fun start----------------------------------------------------------------------------------------


void Delete (lists data[], int &numberOfItems){
	int k=0;
	if (numberOfItems > 0)
 {
 string sName;
  cout<<"Enter Product Name Want to Delete: "<<endl;
cin>>sName;
for (int i=0;i< numberOfItems;i++){
  if (data[i].Product== sName) {
   for (int j=i; j< numberOfItems-1; j++)
    {
     data[j].Product =data[j+1].Product;
    data[j].Company =data[j+1].Company;
       data[j].Price =data[j+1].Price;                                                                   
    data[j].Quantity=data[j+1].Quantity;
      data[j].Sells =data[j+1].Sells;
      k=1;
    }
    cout<<"Product Deleted";
     numberOfItems--;
break ;}}
if (k<=0){
cout<<"Product Not Found!"<<endl;}}}


//-----------------------------------------------------------------------------Delete fun end----------------------------------------------------------------------------------------




//------------------------------------------------------------------------display list for user fun start-----------------------------------------------------------------------------
 
 
void List (string Main[])
{

	for(int i=0;i<8;i++){
	cout<<"\t \t \t \t "<<Main[i]<<endl<<"----------------------------------------------------------------------------"<<endl;}	
	cout<<"\t \t \t "<<Main[8]<<endl<<"----------------------------------------------------------------------------"<<endl;	
}


//------------------------------------------------------------------------display list for user fun end-------------------------------------------------------------------------------




//------------------------------------------------------------------------------sort by name fun start---------------------------------------------------------------------------------

void sort (lists data[],int numberOfItems)
{
lists temp[numberOfItems];
for(int i = 1; i < numberOfItems; ++i) {
for(int j = 0; j < numberOfItems -1;++j){                                                                  
if(data[j].Product > data[j+1].Product) {
temp[j] = data[j]; 
data[j] = data[j+1]; 
data[j+1] = temp[j];
}
}
}
}


//------------------------------------------------------------------------------- sort by name fun end ---------------------------------------------------------------------------------




//-------------------------------------------------------------------------------------search fun start---------------------------------------------------------------------------------


void search (lists data[],int numberOfItems){
 string sName;
 int k;
  cout<<"Enter Product Name Want to search: "<<endl;
cin>>sName;
for (int i=0;i< numberOfItems ;i++)
{
if (data[i].Product== sName) {
	cout<<"Product Found in :"<< i+1;                                                                        
	break;
	k=1;}}
	if (k<=0){
cout<<"Product Not Found!"<<endl;}}


//---------------------------------------------------------------------------------------search fun end------------------------------------------------------------------------------------




//---------------------------------------------------------------------------------input from text file fun start---------------------------------------------------------------------------


void load(lists data[],int &numberOfItems,int size){
	ifstream inFile("input.txt"); 
if(inFile.is_open())
  {
 	int counter =0;
      while(!inFile.eof()) {
    getline (inFile,data[counter].Product);
	   getline (inFile,data[counter].Company);
         getline (inFile,data[counter].Price);                                                          
          getline (inFile,data[counter].Quantity);                                       
          getline (inFile,data[counter].Sells);
			counter++;   }
              numberOfItems=counter-1; 
inFile.close();
  }
else cout << "Failed  !" <<endl;  

}


//----------------------------------------------------------------------------------input from text file fun end---------------------------------------------------------------------------




//-----------------------------------------------------------------------------------output to text file fun start-------------------------------------------------------------------------


void saveed (lists data[],int numberOfItems){
		ofstream inFile("outPut2.txt",ios::app);
		if(inFile.is_open()){
	time_t t;
	struct tm * tt;               //printing time
	time (&t);                     //printing time
	 tt = localtime(&t);         //printing time	
		for (int i;i<numberOfItems;i++){
inFile << data[i].Product << "\n";
inFile <<data[i].Company<< "\n";                                                                        
inFile <<data[i].Price<< "\n";
inFile <<data[i].Quantity<< "\n";
inFile <<data[i].Sells<< "\n";}
 inFile<< asctime(tt);   //printing time
inFile.close();
cout << "\nData Saved successfully\n";}
else cout<<"Failed !!";

}


//----------------------------------------------------------------------------------output to text file fun end-------------------------------------------------------------------------------------




//---------------------------------------------------------------------------------update input text file  fun start--------------------------------------------------------------------------------


void saveed1 (lists data[],int numberOfItems){
		ofstream inFile("inPut.txt",ios::out);
		if(inFile.is_open()){
		
		for (int i;i<numberOfItems;i++){
inFile << data[i].Product << endl;
inFile <<data[i].Company<< endl;
inFile <<data[i].Price<< endl;                                                                         
inFile <<data[i].Quantity<< endl;
inFile <<data[i].Sells<<endl;}
inFile.close();
cout << "\nData Saved successfully\n";}
else cout<<"Failed !!!";

}


//---------------------------------------------------------------------------------update input text file  fun end--------------------------------------------------------------------------------------




//----------------------------------------------------------------------------------------fun end------------------------------------------------------------------------------


















//-------------------------------------------------------------------------------------------------  END <3  -------------------------------------------------------------------------------------------------------
