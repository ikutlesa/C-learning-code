//ilustracuja rada s opercijama nad stringovima tj. sa datotekom cstring
//u kojoj su definirane za kpiranje nizova (strcpy),nadovezivanje nizova
//(strcat), pretrazivanje nizova,usporedba nizova(strcmp), odredjivanje 
//(strlen), pretvorbe velika-mala slova(tolower) i sl. to je upravo 
//opisano u ovom programu

#include <iostream>
#include <cstring>
using namespace std;

int main()
	{
	  char *prvi="mali";
	  char *drugi="princ";
	  char *praznina=" ";
	  int ukupnaDuljina=strlen(prvi)+strlen(praznina)+strlen(drugi);
	  char *oba=new char[ukupnaDuljina+1];
	  strcpy(oba,prvi);
	  strcat(oba,praznina);
	  strcat(oba,drugi);
	  cout<<oba<<endl;
	  int usporedba=strcmp(oba,prvi);
	  if(usporedba)
		{
		  if (usporedba>0)
			  cout<<"\""<<oba<<"\" je veci od \""
			      <<prvi<<"\""<<endl;
		  else
			  cout<<"\""<<prvi<<"\" je veci od \""
				  <<oba<<"\""<<endl;
	  }
	  else
		  cout <<" \""<<prvi<<"\" i \""<<oba
			   <<"\" su jednaki" <<endl;
	  return 0;
	}


