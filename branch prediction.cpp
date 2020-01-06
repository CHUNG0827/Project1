#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void state(int table)
{  
  switch(table) //SN WN WT ST
  {  
   	 case 0 : cout<<"SN";
   	 break;
   	 case 1 : cout<<"WN";
   	 break;
   	 case 2 : cout<<"WT";
   	 break;
	 case 3 : cout<<"ST";
     break;	    
  }
}
int stage(int *pointer, int *K, int PRED , bool OUT, bool miss)
{
  cout << pointer[0]<< pointer[1]; cout<<"   ";
  state(*K); cout<<"   ";
  state(*(K+1)); cout<<"   ";
  state(*(K+2)); cout<<"   ";
  state(*(K+3)); cout<<"   ";
  if((PRED - 2) < 0) 
  { 
    cout << "    N     "; 
  }
  else cout << "    T    ";
  if(OUT) 
  { 
    cout << "     T    ";
  }
  else cout << "    N	    ";
  if (miss) 
  { 
    cout << "miss"; 
  }
  cout << endl;
  return miss;
}
   
int main(int argc, char *argv[])  
{  
    /*read file*/
	ifstream file;
	string input;
	file.open("input.txt", ios::in);
	if (file.is_open())
	{
      getline(file,input);
	  file.close();
	}
	else
	{
      cout << " Can not open the file " << endl;
	}
	
   int pointer[2] = {0,0};  // 00 01 10 11 
   int now = 0;
   int miss = 0;
   int table[4] = {0,0,0,0}; // SN SN SN SN 
   bool sta;
   
   for(int i = 0; i<input.size(); i++)
   {
    now = pointer[0]*2+pointer[1];  // 00 = 0, 01 = 1, 10 = 2 , 11 = 3; 
	if(input[i]==78)
	{
	     if(table[now] < 2 && 0==0) 
         { 
           sta=false; 
         }
         else if(table[now] > 1 &&  0==1 )
         {
           sta=false; 
         }
         else 
         { 
           sta=true; 
         }  
	   // if == N
	   if (stage(pointer,table,table[now],0,sta)) 
	   {
	     miss++;
	   }// stage
       table[now]--;//EX:11 - 1  = 10  ST => WT
       switch(table[now])
       {   
         case 4: table[now] = 3; // ST taken(ST)
         break;
         case -1: table[now] = 1; // SN not taken(SN)
         break;
       }
	   pointer[0] = pointer[1];
	   pointer[1] = 0; 		
	}
    else if(input[i]==84)
	{ 
	   if(table[now] < 2 && 1==0) 
       { 
         sta=false; 
       }
       else if(table[now] > 1 &&  1==1 )
       {
         sta=false; 
       }
       else 
       { 
         sta=true; 
       }  
	  // if== T
	  if (stage(pointer,table,table[now],1,sta)) 
	  {
	    miss++;
	  }
      table[now]++;    // EX: 00+1 = 01  SN => WN
      switch(table[now])
      {   
         case 4: table[now] = 3; // ST taken(ST)
         break;
         case -1: table[now] = 1; // SN not taken(SN)
         break;
       }
	   pointer[0] = pointer[1];
	   pointer[1] = 1; 		
	}
	else 
	{
	  cout << " Not a valid input " << endl;
	  break;
	}
   }
	cout << endl;
	cout << "Total miss: " << miss << endl;

	char output[] = "output.txt";
	fstream fp;
	fp.open(output, ios::out);
	if (!fp) 
	{
	  cout << " Can not open the file: " << output << endl;
	}
	fp << "Total miss: " << miss << endl;
	fp.close();
	system("pause");
	return 0;
}
