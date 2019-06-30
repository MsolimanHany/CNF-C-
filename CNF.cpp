#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool equal(string A,string B)
{
 bool s=1;
 if(A.length()==B.length())
 {
  for(int i=0;i<A.length();i++)
  {
        if(A[i]!=B[i])
        {
         s=0;
         break;             
        }               
}                                 
}
else
{
s=0;
}
return s;                             
 }

string retstart(string N)
{
 string B;      
 for(int  i=0;i<N.length();i++)
 {
     if(N[i]=='-')
     break;
     else
     B+=N[i];     
          }  
      return B;       
}        
bool inlist2(int arr[],int f,int m){
         bool t=0;
         for(int i=0;i<f;i++)
         if(arr[i]==m)
         t=1;
         return t;
         }
//function to remove start state from right
//check for start
char Rstart(string N) 
 {
 	char s;
 	if(N.length()>0)
 	{
 	
 	for(int i=0;i<N.length();i++)
 	{
 		if(N[i]!=NULL)
 		{
 			s=N[i];
 			break;
 		}
 		
 	}
 }
 
 	return s;
 } 
 bool inlist(string N,char m){
         bool t=0;
         for(int i=0;i<N.length();i++)
         if(N[i]==m)
         t=1;
         return t;
         }
 //fuction for checking  $
 bool search$(string N,int i)
 {
 	bool A=0;
 	for(int j=i;j<N.length();j++)
 	{
 		if(N[j]=='$')
 		{
 			A=1;
 			break;
 		}
 		if(N[j]==','||N[j]=='.')
 		break;
 	}
 	return A;
 }
 //search for LHS (NON terminal)
 char RLHS(string N,int i) 
 {
 		char m;
 	if(N.length()>0)
 	{
 	
 	for(int s=i;s<N.length();s++)
 	{
 		if(N[s]!=NULL)
 		{
 			m=N[s];
 			break;
 		}
 		
 	}
 }
 return m;
 	
 }
  
 //check for start in RHS
 bool checkR1(string N,char s)
 {
 	bool A=0;
 	
 	for(int i=0;i<N.length();i++)
 	{
 	if(A==1)
	 break;	
 	if(N[i]=='>')
	 {
	 	
 	for(int j=i+1;j<N.length();j++)
	 {
	 if(N[j]==s)
	 {
	 	A=1;
	 	i=j;
	 	break;
	 }	
	 	if(N[j]==','|N[j]=='.')
	 	{
	 		i=j;
	 		break;
	 	}
	 	
	 }	
}
}
	 return A;
}
//Rule 1 eliminate the start symbol from the right 	 
 string R1(string N,bool A,char s)
{
	string p;
	
if(A)	
{
	p+="SS->";
	p+=s;
	p+=",";
	for(int i=0;i<N.length();i++)
	{
    if(N[i]!=NULL)        
	p+=N[i];
}
}
else
{
	for(int i=0;i<N.length();i++)
	{
    if(N[i]!=NULL)        
	p+=N[i];
}
}

return p;
} 	
//Rule 2
// ignore the start state
// eliminate the $ from RHS for the other rules
string R2A(string N)
{
string epslon;

for(int i=0;i<N.length();i++)
{
	if(N[i]==',')
	{
	i++;
	char s=RLHS(N,i);
	
	if(search$(N,i))
{
epslon+=s;	                                
	
}
}
}
 return epslon;
}		
string R2B(string N,string e)
{
  string p;
  
    
  for(int i=0;i<N.length();i++)
  {
          
  p+=N[i];
  
  if(N[i]==',')
  {
    i++;
    p+=N[i];
    if(inlist(e,N[i]))
    {
                       
    p+="->";
    i+=3;
    for(int j=i;j<N.length();j++)
    {
            
    if(N[j]!=','&& N[j]!='.' && N[j]!='$')
    {
                                       
    p+=N[j];
}
    else if(N[j]=='$')
    {
         
     int pp=j; //pre and post    
      if(N[pp-1]=='>'&&N[pp+1]=='|')
      {
                                    
         j++;
         }
       else if(N[pp-1]=='|'&&N[pp+1]=='|')
       {
         
       j++;
       }
       else if(  N[pp-1]=='|')
       {
            
            
          i=j;  
          string s;
          s+=p;
          p="";  
          for(int i=0;i<s.length()-1;i++)
          p+=s[i];
          s="";
          break; 
          } 
        }
        else
        {
            
        i=j-1;  // waiting for comma or dot.
        break;    
        }
    } 
                   
               }        
}          
       } 	
 return p;
}
string R2C(string N,string e,string S)
{
   string B;    
 string NewN;
 string LHS;
 string add;
 

     for(int i=0;i<e.length();i++)
     {
      
                   
        for(int j=0;j<N.length();j++)
        {
 
   
    if(N[j]!='-'&&N[j]!='>')
        LHS+=N[j];         
             
   
   
   if(N[j]=='>')
   {
                
                
                
     j++; 
 

               
   while(N[j]!=','&&N[j]!='.')
   {
                              
     
  int flag=0;
  int arr[1000]={0};  
   B="";                          
  while(N[j]!='|'&&N[j]!=','&&N[j]!='.')
  {
    B+=N[j];
    j++;
}



int g=j;
if(N[j]=='|')
{

j++;
}
if(B.length()>0)
{
                
              
int in=0;
 for(int p=0;p<B.length();p++)
 {
    if(B[p]==e[i])
    {
    flag++;
    arr[in]=p;
    in++;     
    
         }
         
}

                                         
//cases (4)

if(flag>0)
{
          
add+=LHS;
 add+="("; 
           
if(B.length()>1&& flag==1)
{
                  
for(int m=0;m<B.length();m++)
{
  if(!inlist2(arr,flag,m))
  add+=B[m];      
        }
     add+=")";     
    
                        
}   
else if( B.length()==1&& flag==1)
       {
                     
        if(equal(LHS,S))
        { 
                                 
         add+="$)";
         
         }
         else
         add+=" )";
  
         
             
       }
             
  else 
  {
       //important verrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrry
 if(N[j]=='.'|N[j]==',')
       NewN+='|';
       int set_size=flag;
       
       int arr2[1000]={0};
 int pow_set_size = pow(2, set_size);
 
    int counter, j;
 
 
    if(flag==B.length())//BBB
    pow_set_size--;
    for(counter = 1; counter < pow_set_size; counter++)
    {
                for(int m=0;m<set_size;m++)
                arr2[m]=-1;
      for(j = 0; j < set_size; j++)
       {
            
    
          if(counter & (1<<j))
          {
           arr2[j]=arr[j];
           
           }
           
       }
       
    
      for(int k=0;k<B.length();k++)
      {
        
        if(!inlist2(arr2,set_size,k))      
        add+=B[k];
          }
         int f=pow_set_size;       
          if(counter -(f-1)!=0)
          add+="|";    
              }
     add+=")";         
                          
  }
                  }                              
}                             
}  
  LHS="";       
        }
        }
        }
       
     return add;   
        }  
 string R2D( string N,string S)
 {
        int m;
        int g;
  string A;
   string New;
    string LHS;
   for(int j=0;j<N.length();j++)
        {
                                
       if(j>0)
       New+=",";                         

  LHS=""; 
    while(N[j]!='-'&&N[j]!='>')
    {
  New+=N[j];                             
        LHS+=N[j];
        
  j++;               
}

j+=2;
  New+="->";
while(N[j]!=','&&N[j]!='.')
{
       New+=N[j];
       j++;                    
                           }
                            
    for(int i=0;i<S.length();i++)
    {
    string v="";        
    while(S[i]!='(')
    {        
      v+=S[i];
      i++;
      } 
 
      if(equal(LHS,v))
      {
               
        i++;                
       if(S[i]!=' ')
           New+="|";                 
        for(int a=i;a<S.length();a++)
        {
       if(S[a]!=NULL&&S[a]!=')'&&S[a]!=' ')
            New+=S[a];
         if(S[a]==')')
         {
           
           g=a;           
          break;
                      
         }
         
         g=a;
         }
         i=g;
         }
         else
         {
          while(S[i]!=')')
          i++;
           
         }
         v="";
                            
                }                
      }  
      int gf=New.length()-1;
      if(New[gf]!='.')
        New+=".";                   
                                             
return New;
} 
string R2Final(string N)
{
       int m=0;
       int y=0;
       int rep=0;
       string A;
        string B;
        int bv=0;
   string New;
  for(int i=0;i<N.length();i++)//All
  {
          
  while(N[i]!='>')
  {        
  New+=N[i];
  i++;
}   
  
  New+=N[i];
  
  i++;
  
  
  for(int j=i;j<N.length();j++) //one rule
  {
          
          
  
                             
     A="";     
  while(N[j]!='.'&&N[j]!='|'&&N[j]!=',')// left or  or ,    or .
  {
    A+=N[j];
    j++;                                    
}

 if(N[j]=='.'||N[j]==',')
     {
     New+=A;
                         
       New+=N[j];
       i=j;
       break;                     
     } 

 m=j;
 m++;


y=j;    
 for(int k=m;k<N.length();k++)//comparison
 {
   rep=0;      
      if(N[k]=='|')
      k++;
        
      if(N[k]==','||N[k]=='.')
        break;   
     B="";
        
  while(N[k]!='|'&&N[k]!=','&&N[k]!='.') //left or  or ,    or .
  {
                                         
  
                                        
      B+=N[k];
      k++;
                                       
      }
     
 k--;     
    
      
                                                           
    if(equal(A,B))
    {
    
                                                
      rep++;
    break; 
      }
       
    
}

if(rep==0)
{
          
New+=A;

if(N[y]=='|')
New+='|';
}


        
      
}
      
}
string ALL;
string F;
for(int m=0;m<New.length();m++)// for any c->,    or    c->.
{
 while(New[m]!='>')
 {
  ALL+=New[m];
  m++;                 
}     
  ALL+=New[m];
  m++;
 
  if(New[m]==','||New[m]=='.')
   {
 ALL="";                                               
} 
    else
    {
   F+=ALL;
   while(New[m]!=','&&New[m]!='.')
   {
    F+=New[m];
    m++;                              
}   

F+= New[m];
ALL="";   
}                         
    }      
       
 return F;       
} 
// step 3   unit rule
// delete ex: A->A 
string R3A(string N)
{
       
 string New;
 string sub;
 string LHS;
 string sub2;
       
       for(int i=0;i<N.length();i++)
{
  sub="";    
  while(N[i]!=','&&N[i]!='.')//, .
  {
                              
    sub+=N[i];
    i++; // .  ,                             
}
 
int len=sub.length();  
for(int j=0;j<len;j++)
{
  //looping with count=1
  if(j==0)
  {      
  LHS="";
  
 while(sub[j]!='-')
 {
                      
 LHS+=sub[j];
 New+=sub[j];
 j++;               
}
 
New+="->";
               
j+=2;
}
sub2="";
while(sub[j]!='|'&&j!=len)
{
sub2+=sub[j];
j++;                  
}
   
if(sub2.length()>1) //option 1 for ex:BAB
{
      
  New+=sub2;
   
   
  if(sub[j]=='|')
  New+=sub[j];  
}
else
{
    
 if(sub2.length()==1)
 {
 char c=sub2[0]; 
 if(equal(sub2,"$")||!isupper(c)||!equal(LHS,sub2))
 {
                                 
      New+=sub2;
  
  if(sub[j]=='|')
 {
  New+=sub[j];  
}
                           
}


else
{
if(j==sub.length())
{
                   
string New2;
New2+=New;
New="";
for(int e=0;e<New2.length()-1;e++)
    New+=New2[e];
   New2=""; 
}
               
}                  
}

}

if(j==sub.length())
{
                  
New+=N[i];
}                                                  
}                             
}                                

        
return New; 
}
string R3B(string N)
{

string New;


string sub;
string LHS;
string sub2;
bool count=0;
string subloop;


for(int i=0;i<N.length();i++)
{
   sub="";   
  while(N[i]!=','&&N[i]!='.')
  {
                             
    sub+=N[i];
    i++; // .  ,                             
}
 
int len=sub.length();
  
for(int j=0;j<len;j++)
{
        
  //looping with count=1  
  if(j==0)
  {    
       
  LHS="";
  
 while(sub[j]!='-')
 {
                   
                  
 LHS+=sub[j];
 subloop+=sub[j];
 j++;               
}

subloop+="->";                    
j+=2;

}


sub2="";
while(sub[j]!='|'&&j!=sub.length())
{
sub2+=sub[j];
j++;                  
}
   
if(sub2.length()>1) //option 1 for ex:BAB
{
      
  subloop+=sub2;
  if(sub[j]=='|')
  subloop+=sub[j];
    
}
else
{
    
 if(sub2.length()==1)
 {
                   
 char c=sub2[0]; 
                                
 if(equal(sub2,"$")||!isupper(c))
 {
                                 
      subloop+=sub2;
      if(sub[j]=='|')
  subloop+=sub[j];
                           
}
else if(equal(LHS,sub2))//////////////////////////////////////////////
{

if(j==sub.length())
{
                   
string New2;
New2+=subloop;
subloop="";
for(int e=0;e<New2.length()-1;e++)
    subloop+=New2[e];
   New2=""; 

               
}     
}  
else
{
 
 count=1;
  
 for(int k=0;k<N.length();k++)
 {
         
string LHS2="";         
 while(N[k]!='-')
 { 
                                      
 LHS2+=N[k];
 k++;               
} 
k+=2;
              
//cout<<sub2<<LHS2<<endl;
if(!equal(sub2,LHS2))
{
                                
while(N[k]!='.'&&N[k]!=',')
{
k++;
               
}                    
}
   
else 

{
 
    
while(N[k]!='.'&&N[k]!=',')
{
              
  subloop+=N[k];
  k++;   
  
                          
}
 if(sub[j]=='|')
 subloop+=sub[j];
 break;                         
}
                             
}          
}
//end else         
}                                                       
} 
if(j==sub.length()&&count==1)
{

  j=-1; 
   count=0;
   sub="";
   
   sub+=subloop;
   subloop=""; 
   len=sub.length();
                        
   }
  else 
  {
       
    if(j==sub.length()&&count==0)
    {
                                 
                                  
      New+=sub;
      subloop="";
      
      New+=N[i];
}   
} 
                                                 
}                             
}     
                
        
return New;                 
}           
string prefinal(string N,int &m)
{
string add;
string New;


string sub;

string sub2;

int NRULE=0;
char A='T';

for(int i=0;i<N.length();i++)
{
        
   sub="";   
  while(N[i]!=','&&N[i]!='.')
  {
                             
    sub+=N[i];
    i++; // .  ,                             
}
 
int len=sub.length();
  
for(int j=0;j<len;j++)
{
      
  //looping with count=1  
  if(j==0)
  {    
        
 while(sub[j]!='>')
 {
               
 New+=sub[j];
 j++;               
}

New+=sub[j];
                    
j++;

}


sub2="";
while(sub[j]!='|'&&j!=sub.length())
{
                                  
sub2+=sub[j];
j++;                  
}

string B="";
if(sub2.length()<3&&sub2.length()>0) 
{
                                     
 string v;                    
if(sub2.length()==2)	
 {
                     
 if(!isupper(sub2[0])&&!isupper(sub2[1]))	
 {
  std::stringstream oss1;                                         
                                          
 oss1 << NRULE;

 B+="#"; 	
 add+="#";
 add+=A;
 B+=A;
  B+=oss1.str();
 add+=oss1.str();
 B+="#";
 add+="#";
 add+="->";
 add+=sub2[0];
 add+=",";
 
 New+=B;
 
 NRULE++;	
 B="";
 //2
 std::stringstream oss2;
  oss2 << NRULE;

 B+="#"; 	
 add+="#";
 add+=A;
 B+=A;
  B+=oss2.str();
 add+=oss2.str();
 B+="#";
 add+="#";
 add+="->";
 add+=sub2[1];
 add+=",";
 New+=B;
 
 NRULE++;	
 B="";
 	
 }
else if(isupper(sub2[0])&&!isupper(sub2[1])) 
 {
 New+=sub2[0];    
 std::stringstream oss3; 
  oss3 << NRULE;
     B+="#";
     add+="#";
     add+=A;
     B+=A;
      B+=oss3.str();
     add+=oss3.str();
 B+="#";
 add+="#";
 add+="->";
 add+=sub2[1];
 
 add+=",";
 New+=B;
 NRULE++;	
 B="";
        
}   
else if(!isupper(sub2[0])&&isupper(sub2[1]))
{
     
 New+=sub2[1];    
  std::stringstream oss4;
  oss4 << NRULE;
     B+="#";
     add+="#";
     add+=A;
     B+=A;
      B+=oss4.str();
     add+=oss4.str();
 B+="#";
 add+="#";
 add+="->";
 add+=sub2[0];
 add+=",";
 New+=B;
 NRULE++;	
 B="";     
         
}    
else 
{ 
     
         
 New+=sub2;

    
}

if(sub[j]=='|')
{
             
New+=sub[j]; 
} 
    
 }

else
{
    
    
 New+=sub2;
 if(sub[j]=='|')
  New+=sub[j]; 
    
}                         
                   
}
   
else
{   
 
int length=sub2.length();

char d;
int x=0;
int x2=1;

 while(length>=2)
 {
 char d ;
  if(!isupper(sub2[x])&&!isupper(sub2[x2]))	
 {
       std::stringstream oss5;                                      
                                            

  oss5 << NRULE;
 B+="#"; 	
 add+="#";
 add+=A;
 B+=A;
  B+=oss5.str();
 add+=oss5.str();
 B+="#";
 add+="#";
 add+="->";
 add+=sub2[x];
 add+=",";
 New+=B;
 NRULE++;	
 B="";
 //2
 std::stringstream oss6; 
 oss6 << NRULE;
 B+="#"; 	
 add+="#";
 add+=A;
  B+=oss6.str();
 add+=oss6.str();
 B+="#";
 add+="#";
 add+="->";
 add+=sub2[x2];
 
 add+=",";
 New+=B;
 NRULE++;	
 B="";	
 }
 else if(isupper(sub2[x])&&!isupper(sub2[x2])) 
 {
 New+=sub2[x];
  std::stringstream oss7;    
 oss7 << NRULE;
     B+="#";
     add+="#";
     add+=A;
     B+=A;
      B+=oss7.str();
     add+=oss7.str();
 B+="#";
 add+="#";
 add+="->";
 add+=sub2[x2];
 
 add+=",";
 New+=B;
 NRULE++;	
 B="";
        
}   
 else if(!isupper(sub2[x])&&isupper(sub2[x2]))
{
 New+=sub2[x2];
  std::stringstream oss8;    
 oss8 << NRULE;
     B+="#";
     add+="#";
     add+=A;
     B+=A;
      B+=oss8.str();
     add+=oss8.str();
 B+="#";
 add+="#";
 add+="->";
 add+=sub2[x];
 
 add+=",";
 New+=B;
 NRULE++;	
 B="";     
         
}    
else
{
   
 std::stringstream oss9;
   oss9 << NRULE;
     B+="#";
     add+="#";
     add+=A;
     B+=A;
      B+=oss9.str();
     add+=oss9.str();
 B+="#";
 add+="#";
 add+="->";
 add+=sub2[x];
 add+=sub2[x2];
 
  
 add+=",";
 New+=B;
 
 NRULE++;
 	
 B="";
}                                     
                              
length-=2;


x++; x2++;

}

 if(length==1)
 {
              
New+=sub2[x2];
                            
}
if(sub[j]=='|')
  New+=sub[j];
     
                            
}
if(j==len&&N[i]!='.')
 New+=N[i];  
} 

                            
}
if(add.length()!=0)
{
New+="@";

for(int y=0;y<add.length()-1;y++)
       New+=add[y];
}
else
m=0;
 
return New;       
}
string CFGtoCNF(string N)
{
       string add;
string New;
string subloop;

string sub;

string sub2;

int NRULE=0;
char A='Y';
int m;

//Main point divide the array
////////////////////////////////////
string b="";
b+=N;
N="";
for(int c=0;c<b.length();c++)
{
      if(b[c]=='@')
      {
       m=c;
       break;            
      }      
   else
   {
     N+=b[c];  
   }           
}

for(int c=m+1;c<b.length();c++)
{
        add+=b[c];           
}

add+=',';
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//start for
for(int i=0;i<N.length();i++)
{
        
   sub="";   
  while(N[i]!=','&&i!=N.length())
  {
                             
    sub+=N[i];
    i++; // .  ,                             
}
 
int len=sub.length();
 //start for j 
 bool count =0;
 
for(int j=0;j<len;j++)
{
        
      
  //looping with count=1  
  if(j==0)
  {             
        
 while(sub[j]!='>')
 {
               
 New+=sub[j];
 j++;               
}

New+=sub[j];
                    
j++;

}


sub2="";
while(sub[j]!='|'&&j!=sub.length())
{
                                  
sub2+=sub[j];
j++;                  
}

//calculate the new length
int Newlen=0;

//cout<<"sssssssss"<<New<<endl;
for(int p=0;p<sub2.length();p++)
{
        
  if(sub2[p]=='#')
  {
    p++;              
 while(sub2[p]!='#')
       p++;
       
   Newlen++;
}
else
Newlen++;    
}                
                     


if(Newlen>2)
{
            
  string B="";
string ws="";
int m=0;
count=1;          
 while( Newlen>=2)
 {
        
    if(sub2[m]=='#')
    {
                    
    ws+=sub2[m];
    m++;             
    while(sub2[m]!='#')
    {
       ws+=sub2[m];              
        m++;
}   
ws+=sub2[m]; 
  m++;
}
else
{
 ws+=sub2[m];
 m++;   
}
    if(sub2[m]=='#')
    {
    ws+=sub2[m];
    m++;             
    while(sub2[m]!='#')
    {
       ws+=sub2[m];              
        m++;
}
ws+=sub2[m];    
  m++;
 
}
else
{
 ws+=sub2[m];
 m++;   
}
Newlen-=2;
       std::stringstream oss5;                                      
  oss5 << NRULE;
 B+="#"; 	
 add+="#";
 add+=A;
 B+=A;
  B+=oss5.str();
 add+=oss5.str();
 B+="#";
 add+="#";
 add+="->";
 add+=ws;
 
 
 add+=",";
 New+=B;
 NRULE++;
 	
 B="";
 ws="";
 //2
}

 if( Newlen==1)
 {
     
  while(m<sub2.length())
  {           
New+=sub2[m];
m++;
}                         
}
if(sub[j]=='|')
  New+=sub[j];
                                 
}
else
{
if(Newlen<=2)
{
  New+=sub2;
   if(sub[j]=='|')
  New+=sub[j];          
}                
}   


   
 if(count==1&&j==len)
 {
 
 count=0;
 sub="";
 sub+=New;
 len=sub.length();
 New="";
 j=-1;           
} 
else
{
    
if(j==len&&count==0)
{
                           
  subloop+=sub;
  New=""; 
  if(N[i]==',')
    subloop+=N[i]; 
} 
}
}
}
subloop+=",";
subloop+=add;
subloop+=".";
return subloop;       
}      
                      
int main(int argc, char** argv) {
	// $ means epslon
	string input;
	cout<<"                    CONVERT FROM CFG TO CNF"<<endl;
	cout<<"Hint: (# , . () )are reserved words for my program   and    $ means epslon"<<endl; 
	cout<<"Please enter your Context free grammer:      Hint: the entering in this form EX:  A->00|a,B->GF.   divide the rules with comma and end with dot(.)"<<endl;
	cout<<"ENTER(every LHS contains only one uppercase letter)"<<endl;
    cin>>input;
    bool check=0;
    int g1=input.length()-1;
    int g2=input.length()-2;
    if(input[g1]!='.'||input[g2]==',')
    {
                                     
     check=1;
     cout<<"Please enter Your input in True Form"<<endl;  
                    
    }                 
    else
    {
    for(int i=0;i<g1;i++)
    {
    if(check==1)
    break;        
     char a=input[i];
            
      if(a=='#'||a=='.'||a=='-'||a=='>'||a=='('||a==')')
      {
                                         
        check=1;
       cout<<"Please enter Your input in True Form"<<endl; 
       
        break;                
      }
      if(!isupper(a))
      {
                      
                      check=1;
       cout<<"Please enter Your input in True Form"<<endl; 
      
        break;
      }       
      i++;
      
      a=input[i];
       if(a!='-')
      {
     
                      check=1;
       cout<<"Please enter Your input in True Form"<<endl; 
      
        break;
      } 
       i++;
      a=input[i];
       if(a!='>')
      {
                  
                      check=1;
       cout<<"Please enter Your input in True Form"<<endl;
        
        break;
      } 
      i++;
       a=input[i];
       if(a=='#'||a=='.'||a=='-'||a=='>'||a=='('||a==')')
      {
                                            
        check=1;
       cout<<"Please enter Your input in True Form"<<endl; 
      
        break;                
      }
      while(a!=',')
      {
         if(a=='#'||a=='.'||a=='-'||a=='>'||a=='('||a==')')
      {
                                            
        check=1;
       cout<<"Please enter Your input in True Form"<<endl;
      
        break;                
      }
      
      
      int d=i;
      int v=i;
      if((a=='|'&&input[d+1]=='|')||(a=='|'&&input[v-1]=='|')||(a=='|'&&input[v-1]==',')||(input[v-1]=='.')||(a=='|'&&input[v-1]=='>'))
      {
                                                                                                                                       
      check=1;
       cout<<"Please enter Your input in True Form"<<endl; 
       
        break;                                                                                                                                                                                                                                                                  
      }
      if(a==',')
      {
      if(input[d+1]==','||((a==',')&&(i==g2)))
       {
       check=1;
       cout<<"Please enter Your input in True Form"<<endl; 
      
        break;                  
       }                         
      } 
      i++;
      
      a=input[i];
      if(a=='.'&&i==g1)
      break;
   if(check==1)
   break;              
      }          
                           
    }       
}
//check for missing
string see1="";
string sub1; 
for(int i=0;i<input.length();i++)
{
        
 i+=3;
 
 while(input[i]!=','&&input[i]!='.')
  {
   if(input[i]=='|')
   i++;                                 
   while(input[i]!=','&&input[i]!='|'&&input[i]!='.')
   {
  sub1+=input[i];
  i++;                                    
}
   
for(int j=0;j<sub1.length();j++)
{
        
 if(!inlist(see1,sub1[j])&&isupper(sub1[j]))
 see1+=sub1[j];
        
}
sub1="";                                                                        
                                    
  }                                                
}
  
bool z=0;
int aq=see1.length();
  for(int i=0;i<input.length();i++)
  {
  if(inlist(see1,input[i]))
  {
 aq--;                         
}     
while(input[i]!=','&&input[i]!='.')
i++;                          
}
if(aq>0)
{
cout<<"ERROR MISSING RULE"<<endl;        
z=1;         
}          
//check for A->A|$. infinite loop.
bool x=0;
bool n=0,b=0;
string s;       
 string a; 
 string problem;    
for(int i=0;i<input.length();i++)
{
 if(n==1&&b==1)
 break;       
 n=0,b=0;        
 
 a+=input[i];
 i+=3;
 while(input[i]!=','&&input[i]!='.')
 {
  if(input[i]=='|')
  i++;                   
 while(input[i]!='|'&&input[i]!=','&&input[i]!='.')
 {
 s+=input[i];
 i++;                                                  
}
if(equal(s,a))
{
n=1;
problem+=s;
}
if(equal(s,"$"))
b=1;
if(n==1&&b==1)
  break;
 s="";
 a="";                                                       
}            
} 
if(n==1&&b==1)
{
cout<<"if we execute CNF in this CFG (infinite looooooop will happend with) "<<problem<<endl;
x=1;
}
    cout<<"*************************************"<<endl;
                                  
if(x==0&&z==0)
{
        	cout<<"Your chomsky normal form:"<<endl;
	char start=Rstart(input);
	bool r1=checkR1(input,start);
	string y=R1(input,r1,start);
	string start2;
	start2+=retstart(y);
	string epslon;
	epslon+=R2A(y);
	string y2;
	y2=R2B(y,epslon);
	string y2A;
	y2A=R2C(y2,epslon,start2);
	string y2B;
     y2B=R2D(y2,y2A);
     
   	string y2final=R2Final( y2B);
   	
     	string y3=R3A(y2final);
     	string y3final=R3B(y3);
     	int m=1;
         string prefinal1=prefinal(y3final,m); 	
     string CNF;
     
      CNF=CFGtoCNF(prefinal1);
     	
     for(int i=0;i<CNF.length();i++)
     {
    if(CNF[i]!=NULL &&CNF[i]!=','&&CNF[i]!='.')         
   cout<<CNF[i];
   if(CNF[i]==','||i==(CNF.length()-1))          	
    cout<<endl;
}
}


    system("PAUSE");
    return EXIT_SUCCESS;
}
