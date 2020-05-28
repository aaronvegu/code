#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>
#include "vector.cpp"

using namespace std;

string repeat();
bool isNumber(string);

int main(){
	Vector v;
	v.buildVector();
	int option,value;
	bool out = false;
	do{
		cout<<" == Menu == "<<endl;
		cout<<"\n0.- Salir. \n1.- Agregar. \n2.- Obtener. \n3.- Eliminar. \n4.- Eliminar al. \n5.- Vector a String. \n6.- Capacidad. \n7.- Tamanio. \n8.- Liberar espacio. \n9.- Contiene. \n10.- Esta lleno. \n11.- Limpiar."<<endl;
		cout<<"\nEscribe la opcion deseada: "<<endl;
		option = atoi(repeat().c_str());
				
		switch(option){
			case 0:
				out = true;
				cout<<"\nPrograma terminado";
			break;
			case 1:
				cout<<"\nIngresa el valor a ingresar: "<<endl;
				value = atoi(repeat().c_str());
				v.add(value);
			break;
			case 2:
				cout<<"\nIngresa el index: "<<endl;
				value = atoi(repeat().c_str());
				cout<<"\nThe value is: "<<v.get(value)<<"."<<endl;
			break;
			case 3:
				cout<<"\nIngresa el valor a eliminar: "<<endl;
				value = atoi(repeat().c_str());
				v.remove(value);
			break;
			case 4:
				cout<<"\nIngresa el index a eliminar: "<<endl;
				value = atoi(repeat().c_str());
				v.removeAt(value);
			break;
			case 5:
				v.toString();	
			break;
			case 6:
				cout<<"\nLa capacidad del vector es: "<<v.capacity()<<endl;
			break;
			case 7:
				cout<<"\nEspacios en uso: "<<v.size()<<endl;
			break;
			case 8:
				cout<<"\nLiberar espacio en el indice: "<<v.freeAt()<<endl;
			break;
			case 9:
				cout<<"\nIngresa el valor a buscar: "<<endl;
				value = atoi(repeat().c_str());
				if(v.contains(value)){
					cout<<"\nEl valor se encuentra en el vector."<<endl;
				}else{
					cout<<"\nEl valor NO se encuentra en el vector."<<endl;
				}
			break;
			case 10:
				if(v.isFull()){
					cout<<"\nEl vector esta lleno"<<endl;
				}else{
					cout<<"\nEl vector tiene espacio"<<endl;
				}
			break;
			case 11:
				v.clear();
			break;
				
			default: cout<<"\nOpcion no valida."<<endl;
		}
		cout<<"\n";
	}while(!out);
	
	cin.get();
	return 0;
}

string repeat(){
	string ns;
	bool repeat = true;
	do{
		getline(cin,ns);
		if(isNumber(ns)){
			repeat = false;
		}
	}while(repeat);
	return ns;
}
bool isNumber(string ns){
	int length = ns.size();	
	if(length==0||(length==1&&!isdigit(ns[0]))){
		return false;
	}else{
		int var;
		while(var<length){
			if(!isdigit(ns[var])){
				return false;
				break;
			}
			var++;
		}
	}
	return true;
}