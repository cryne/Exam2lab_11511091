#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::atoi;
void incriptar(char*);
void desincriptar(char*);
void validar(char*);
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
				cout<<"Ejemplo: krod->desincriptado=hola"<<endl;
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
			int opcion2=0;
			while(opcion2==0){
				char* palabra=new char[126];
				cout<<"Ingrese el numero de la tarjeta que desea saber si es valido"<<endl;
				cout<<"se el solicita al usuario que unicamente solo ingrese 16 numero sin ningun otro caracter que no sea numero"<<endl;
				cout<<"ejemplo:8273123273510569"<<endl;
				cin.ignore(126,'\n');	
				cin.getline(palabra,126,'\n');
				validar(palabra);
				delete[] palabra;	
				cout<<"desea continuar revisando mas tarjetas\n0-si\n1-no"<<endl;	
				cin>>opcion2;
			}
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
void validar(char* palabra){
	int acumulado=0;
	for (int i = 16; i >= 0;--i)
	{
		if (i%2==0)
		{
			string y="";
			y.push_back(palabra[i]);
			int x=2*atoi(y.c_str());

			if(x>9){
				x=x-9;
			}
			acumulado=acumulado+x;
		}else{
			string y="";
			y.push_back(palabra[i]);
			int x=atoi(y.c_str());
			acumulado=acumulado+x;
		}
	}
	cout<<acumulado<<endl;
	if (acumulado%10==0)
	{
		cout<<"codigo de tarjeta valido"<<endl;
	}else{
		cout<<"codigo de tarjeta no valido"<<endl;
	}
}
