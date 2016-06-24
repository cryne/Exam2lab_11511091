#include <iostream>
#include <cstring>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
void incriptar(char*);
void desincriptar(char*);
int main(int argc, char const *argv[])
{
	int opcion=0;
	while(opcion!=4){
		cout<<"A que desea entrar?\n1-incriptar caesar\n2-Desincriptar caesar\n3-verificacion de tarjeta\n4-salir"<<endl;
		cin>>opcion;
		if (opcion==1)
		{
			int opcion2=0;
			while(opcion2==0){
				char* palabra=new char[126];
				cout<<"Ingrese lo que desea incriptar"<<endl;
				cout<<"Ejemplo: abc xyz->incriptado=defabc"<<endl;
				cin.ignore(126,'\n');	
				cin.getline(palabra,126,'\n');
				incriptar(palabra);
				delete[] palabra;	
				cout<<"desea continuar incriptando\n0-si\n1-no"<<endl;	
				cin>>opcion2;
			}
			
		}
		if (opcion==2)
		{
			int opcion2=0;
			while(opcion2==0){
				char* palabra=new char[126];
				cout<<"Ingrese lo que desea desincriptar"<<endl;
				cout<<"Ejemplo: abc krod->desincriptado=hola"<<endl;
				cin.ignore(126,'\n');	
				cin.getline(palabra,126,'\n');
				desincriptar(palabra);
				delete[] palabra;	
				cout<<"desea continuar desincriptando\n0-si\n1-no"<<endl;	
				cin>>opcion2;
			}
		}
		if (opcion==3)
		{
			/* code */
		}
	}
	return 0;
}

void incriptar(char* palabra){
	char abecedario[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
	char Abecedario[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
	int tama=strlen(palabra);
	string incriptado="";
	for (int i = 0; i < tama; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if(abecedario[j]==palabra[i]){
				int x=j+3;
				if(x>=26){
					incriptado.push_back(abecedario[x-26]);
				}else{
					incriptado.push_back(abecedario[x]);
				}
			}
			if(Abecedario[j]==palabra[i]){
				int x=j+3;
				if(x>=26){
					incriptado.push_back(Abecedario[x-26]);
				}else{
					incriptado.push_back(Abecedario[x]);
				}
			}
		}
	}
	cout<<"desincriptacion: "<<incriptado<<endl;
}
void desincriptar(char* palabra){
	char abecedario[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
	char Abecedario[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
	int tama=strlen(palabra);
	string incriptado="";
	for (int i = 0; i < tama; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if(abecedario[j]==palabra[i]){
				int x=j-3;
				if(x<0){
					incriptado.push_back(abecedario[x+26]);
				}else{
					incriptado.push_back(abecedario[x]);
				}
			}
			if(Abecedario[j]==palabra[i]){
				int x=j-3;
				if(x<0){
					incriptado.push_back(Abecedario[x+26]);
				}else{
					incriptado.push_back(Abecedario[x]);
				}
			}
		}
	}
	cout<<"desincriptacion: "<<incriptado<<endl;
}