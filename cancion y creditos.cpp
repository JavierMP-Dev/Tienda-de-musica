#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
using namespace std;
const int NUM=10;
struct Cancion {
 	int clave;
 	string nombre;
 	string autor;
 	string genero;
 	double precio;
	};
Cancion cancion[NUM];
string reemplazarEspacios(string);
string reemplazarSharp(string);
void insertar(int,string,string,string,double);
void mostrarDatos();
void escribirEnArchivo();
void recuperarDeArchivo();
void pedirDatos();
void  inicializar();
int buscarlugarVacio();
void menu();
void escribirPaginaWeb();
void ordenacionBurbujaPorPrecioCancion();
void ordenacionBurbujaPorNombre();
int busquedaSecuencial(int);
void borrar(int);
void cambiar(int);
void menuCambiar();
void mostrarRegistro(int);
//variables de ususarios
int desicion();
int clave, plu;
//fin de variables de usuarios
int creditos();
int comprarcancion();
int credito=100,abono, nuevo=0;//variables de la funcion creditos
int claveC;
int clavescanciones[12];//arreglo de canciones compradas
int listacanciones();
int main(){
	int clave, plu;
 	inicializar();
 	recuperarDeArchivo();
 	int opcion, resultado;
 	desicion();
  	do {
	 	menu();
 		cout<<"?";
	 	cin>>opcion;
 		switch(opcion){
 			case 1:system("cls");
 		 		pedirDatos();
			 	escribirEnArchivo();
	 		    break;
		   	case 2:system("cls");
		 		mostrarDatos();
		 		system("pause");
		 		system("cls");
		 		//system("pause");
		 	    break;
		 	case 3:system("cls");
		 		escribirPaginaWeb();
		 		system("cancion.html");
		 	    break;
		 	case 4:system("cls");
		 		ordenacionBurbujaPorPrecioCancion();
		 		mostrarDatos();
		 		system("pause");
		 		system("cls");
		 		break;
		 	case 5:system("cls");
		 		ordenacionBurbujaPorNombre();
		 		mostrarDatos();
		 		system("pause");
		 		system("cls");
		 		break;
		    case 6:system("cls");
				int buscar;
				mostrarDatos();
		    	cout<<"Ingresar clave de la cancion a buscar--->";
		    	cin>>buscar;
		    	resultado=busquedaSecuencial(buscar);
		    	if(resultado == -1){
		    		cout<<"No encontrado :("<<endl;
				}else{
					mostrarRegistro(resultado);
				}
				system("pause");
		 		system("cls");
				break;
			case 7:system("cls");
				int claveB;
				mostrarDatos();
		    	cout<<"\nDame la clave del elemento a borrar: ";
		    	cin>>claveB;
		    	borrar(claveB);
		    	mostrarDatos();
		    	system("pause");
		 		system("cls");
				break;
			case 8:system("cls");
				int claveM;
				mostrarDatos();
		    	cout<<"\nDame la clave del elemento a modificar: ";
		    	cin>>claveM;
		    	cambiar(claveM);
		    	mostrarDatos();
		    	system("pause");
		 		system("cls");
				break;
			case 9:
				break;
		  	default:
		 		cout << "Opcion no valida" << endl;
		 	    break;
			}
	 	} while (opcion != 9);
	 	
 	return 0;
	}

void menu(){
 	cout<<"DATOS DE LAS CANCIONES"<<endl;
   	cout<<"Elige una opcion"<<endl;
 	cout<<"1.-Alta de canciones"<<endl;
  	cout<<"2.-Reporte general"<<endl;
 	cout<<"3.-Ver pagina web"<<endl;
 	cout<<"4.-Ordenar por precio de la cancion"<<endl;
 	cout<<"5.-Ordenar por titulo de la cancion"<<endl;
 	cout<<"6. Buscar un elemento  "<<endl;
 	cout<<"7. Borrar un elemento  "<<endl;
 	cout<<"8. Editar un elemento"<<endl;
 	cout<<"9.-Salir"<<endl;
	}
void pedirDatos(){
 	int clavex;
 	string nombrex;
 	string autorx;
 	string generox;
 	double preciox;
 	cout<<"Escribe los datos de la cancion."<<endl;
 	cout<<"Clave:";
 	cin>>clavex;
 	for(int i=0; i<NUM; i++){
		while(clavex==cancion[i].clave){
			cout<<"La clave ya existe, Ingresa nueva clave: ";
			cin>>clavex;
			i=0;
		}
	}
 	cout<<"Nombre:";
 	getline(cin, nombrex);
 	getline(cin, nombrex);
 	cout<<"\nAutor:";
 	getline(cin, autorx);
 	cout<<"\nGenero:";
 	getline(cin, generox);
 	cout<<"\nCosto de la cancion:";
  	cin>>preciox;
 	insertar(clavex,nombrex,autorx,generox,preciox);
	}
string reemplazarEspacios(string texto){
 	for (int i= 0;i<( int)texto.length();++i) {
		if (texto[i]==' '){
		 	texto.replace(i,1,"#");
			}
		}
 	return texto;
	}
string reemplazarSharp(string texto){
 	for ( int i=0;i<(int)texto.length();++i){
  		if (texto[i] == '#'){
 			texto.replace(i, 1," ");
			}
 		}
 	return texto;
	}
void insertar(int clavex,string nombrex,string autorx,string generox,double preciox) {
 	int lugarVacio=buscarlugarVacio();
 	if (lugarVacio==-1){
	 	cout<<"No hay espacio"<<endl;
	 	return;
		}
 	cancion[lugarVacio].clave=clavex;
 	cancion[lugarVacio].nombre=nombrex;
 	cancion[lugarVacio].autor=autorx;
 	cancion[lugarVacio].genero=generox;
 	cancion[lugarVacio].precio=preciox;
	}
void mostrarDatos(){
	cout<<endl;
 	cout<<setw(6)<<"Clave"
	 	<<setw(20)<<"Nombre"
 		<<setw(15)<<"Autor"
 		<<setw(16)<<"Genero"
 		<<setw(15)<<"Precio"<<endl;
 	for ( int i=0;i<NUM;i++){
		if (cancion[i].clave!=0){
	 		cout <<setw(6)<<cancion[i].clave
	 			 <<setw(20)<<cancion[i].nombre
	 			 <<setw(15)<<cancion[i].autor
	 			 <<setw(16)<<cancion[i].genero
	 			 <<setw(15)<<cancion[i].precio<<endl;
			}
		}
	}

void recuperarDeArchivo(){
 	ifstream lecturaArchivo("canciones.txt", ios::in);
 	if (!lecturaArchivo){
 	 	cerr<<"No se puede abrir el archivo"<<endl;
	 	exit(1);
		}
 	int clavex;
 	string nombrex;
 	string autorx;
 	string generox;
 	double preciox;
 	while (lecturaArchivo>>clavex>>nombrex>>autorx>>generox>>preciox){
	 	insertar(clavex,
	 	reemplazarSharp(nombrex),
	 	reemplazarSharp(autorx),reemplazarSharp(generox),
	 	preciox);
		}
	}
void escribirEnArchivo(){
 	ofstream salidaArchivo("canciones.txt", ios::out);
 	if (!salidaArchivo){
  		cerr<<"No se puede abrir archivo"<<endl;
	 	exit(1);
		}
 	for (int i=0;i<NUM;i++){
 		if (cancion[i].clave!=0){
 			salidaArchivo
		 	<<cancion[i].clave<<' '
 			<<reemplazarEspacios(cancion[i].nombre)<<' '
  			<<reemplazarEspacios(cancion[i].autor)<<' '
  			<<reemplazarEspacios(cancion[i].genero)<<' '
		 	<<cancion[i].precio<< ' '<<endl;
			}
		}
	}
void inicializar(){
 	for (int i=0;i<NUM;i++){
 		cancion[i].clave=0;
 		cancion[i].autor="";
 		cancion[i].genero="";
	 	cancion[i].precio=0;
		}
	}
int buscarlugarVacio(){
 	for (int i=0;i<NUM;i++){
 		if (cancion[i].clave==0){
 			return i;
			}
		}
 	return-1;
	}
	void escribirPaginaWeb(){
		ofstream salidaArchivo("cancion.html",ios::out);
		if(!salidaArchivo){
			cerr<<"No se pudo abrir el archivo"<<endl;
			exit(1);
		}
		salidaArchivo<<"<!doctype html>"<<endl;
		salidaArchivo<<"<html>"<<endl;
		salidaArchivo<<"<head>"<<endl;
		salidaArchivo<<"<meta charset='UTF-8'>"<<endl;
		salidaArchivo<<"<title>Lista de canciones</title>"<<endl;
		salidaArchivo<<"</head>"<<endl;
		salidaArchivo<<"<body>"<<endl;
		salidaArchivo<<"<h1>LISTA DE CANCIONES</h1>"<<endl;
		salidaArchivo<<"<table border=1>"<<endl;
		salidaArchivo<<"<thead> <tr>"<<endl;
		salidaArchivo<<"<th>Clave</th><th>Nombre</th>"<<endl;
		salidaArchivo<<"<th>Autor</th><th>Genero</th><th>Precio</th>"<<endl;
		salidaArchivo<<"</tr></thead>"<<endl;
		salidaArchivo<<"<tbody>"<<endl;
		for(int i=0;i<NUM;i++){
			if(cancion[i].clave !=0){
				salidaArchivo<<"<tr>"
				             <<"<td>"<<cancion[i].clave<<"</td>"
				             <<"<td>"<<cancion[i].nombre<<"</td>"
				             <<"<td>"<<cancion[i].autor<<"</td>"
				             <<"<td>"<<cancion[i].genero<<"</td>"
				             <<"<td>"<<cancion[i].precio<<"</td>"
							 <<"</tr>"<<endl;
			}
		}
		salidaArchivo<<"</body>"<<endl;
		salidaArchivo<<"</table>"<<endl;
		salidaArchivo<<"</body>"<<endl;
		salidaArchivo<<"</html>"<<endl;
	}
	Cancion aux;
	void ordenacionBurbujaPorPrecioCancion(){
		for(int i=0;i<NUM-1;i++){
			for(int j=0;j<NUM-1;j++){
				if(cancion[j].precio>cancion[j+1].precio){
					aux=cancion[j];
					cancion[j]=cancion[j+1];
					cancion[j+1]=aux;
				}
			}
		}
	}
	void ordenacionBurbujaPorNombre(){
		for(int i=0;i<NUM-1;i++){
			for(int j=0;j<NUM-1;j++){
				if(cancion[j].nombre>cancion[j+1].nombre){
					aux=cancion[j];
					cancion[j]=cancion[j+1];
					cancion[j+1]=aux;
				}
			}
		}
	}
	void mostrarRegistro(int i){
	cout<<"Nombre actual->"<<cancion[i].nombre<<"\n";
	cout<<"Autor actual->"<<cancion[i].autor<<"\n";
	cout<<"Genero actual->"<<cancion[i].genero<<"\n";
	cout<<"Precio actual->"<<cancion[i].precio<<"\n";
}

 int busquedaSecuencial(int b){
	for(int i=0; i<NUM; i++){
		if(cancion[i].clave==b){
			return i;
		}
	}
	return -1;
}
void borrar(int clavex){
	for(int i=0; i<NUM; i++){
		if(cancion[i].clave==clavex){
			cout<<"Quieres borrar el elemento?(1.-si, 2.-no) ";
			int res;
			cin>>res;
			if(res==1){
				cancion[i].clave=0;//no lo borra en realidad
				cout<<"Elemento eliminado"<<"\n";
				escribirEnArchivo();
			}
			return;
		}
	}
	cout<<"Elemento no encontrado."<<"\n";
}

void menuCambiar(){
	cout<<"Que desea cambiar: "<<"\n";
	cout<<"1.Nombre"<<"\n";
	cout<<"2.Autor."<<"\n";
	cout<<"3.Genero."<<"\n";
	cout<<"4.Precio."<<"\n";
	cout<<"5.Cancelar."<<"\n";
	cout<<"Ingresar opcion---> ";
}

void cambiar(int clavex){
	for(int i=0; i<NUM; i++){
		if(cancion[i].clave==clavex){
			int opcion;
			cout<<"Titulo actual: "<<cancion[i].nombre<<"\n";
			cout<<"Autor actual: "<<cancion[i].autor<<"\n";
			cout<<"Genero actual:"<<cancion[i].genero<<"\n";
			cout<<"Precio actual: "<<cancion[i].precio<<"\n";
			menuCambiar();
			cin>>opcion;
			switch(opcion){
				case 1:
					cout<<"Ingresar nuevo titulo: ";
					getline(cin, cancion[i].nombre);
					getline(cin, cancion[i].nombre);
					escribirEnArchivo;
					break;
				case 2:
					cout<<"Ingresar nuevo autor: ";
					getline(cin, cancion[i].autor);
					getline(cin, cancion[i].autor);
					escribirEnArchivo();
					break;
                case 3:
                	cout<<"Ingresar nuevo genero: ";
					getline(cin, cancion[i].genero);
					getline(cin, cancion[i].genero);
					escribirEnArchivo();
                	break;
				case 4:
					cout<<"Ingresar nuevo precio: ";
					cin>>cancion[i].precio;
					escribirEnArchivo();
					break;
				case 5:
					break;
				default:
					cout<<"Opcion invalida:("<<"\n";
					break;
			}
			return;
		}
	}
	cout<<"\nElemento no encontrado:("<<"\n";
}

int desicion(){
	int opcion;
cout<<"Ingresa tu clave--->";
	cin>>clave;
	if (clave==345){
		
	}else if (clave!=345){
		cout<<"Usuario\n";
		do{
		cout<<"1. Ver catalogo de canciones "<<"\n";
		cout<<"2. Comprar canciones "<<"\n";
		cout<<"3. Ver lista de canciones compradas"<<"\n";
		cout<<"4. Tu saldo\n";
		cout<<"5. Ver pagina web"<<"\n";
		cout<<"Elige una opcion--->";
		cin>>plu;
		switch(plu){
			case 1:system("cls");
			    cout<<"Registro de canciones\n";
				mostrarDatos();
				system("pause");
				system("cls");
				break;
			case 2:system("cls");
			cout<<"Lista de canciones disponibles\n";
		 		comprarcancion();
				
				break;
			case 3:system("cls");
			     listacanciones();
		 	     int resp;
		 	     if (resp==-1){
		 	     	cout<<"Aun no hay canciones para mostrar\n";
				  }
				cout<<"\n\n";
				system("pause");
            	system("cls");
		 		break;
		 	case 4:system("cls");
		 		creditos();
		 		cout<<"\n\n";
		 		system("pause");
            	system("cls");
		 		break ;
		 	case 5: system("cls");
		 	     escribirPaginaWeb();
		 	     system("cancion.html");
		 	     break;
		
		 	default:
		 		cout<<"Opcion no valida"<<"\n";
				break;
			
		}
}while (opcion!=6);
	}			
}

int creditos(){
	  char respuesta,s;
		cout<<"Credito Actual: "<<credito<<"\n";
		cout<<"\nAbonar saldo-->(a)\nRestar saldo-->(r)\nRegresar a menu principal-->(o)";
		cin>>respuesta;
		if (respuesta=='a' || respuesta=='A'){
		cout<<"Cuanto deseas abonar?--->";
		cin>>abono;
		credito=credito+abono;
		cout<<"\nSaldo recargado="<<credito<<"\n";
	    }else
		if (respuesta=='r' || respuesta=='R'){
		cout<<"\nCuanto deseas restar?--->";
		cin>>abono;
		credito=credito-abono;
		cout<<"\nSaldo restado="<<credito<<"\n"; 
	    }else if (respuesta=='o' || respuesta=='O'){
	    	return 1;
		}
}

int comprarcancion(){
		 		mostrarDatos();	
				 cout<<"Ingresa la clave de la cancion a comprar--->";
				 cin>>claveC;
				 
		 	    cout<<endl;
 				cout<<setw(6)<<"Clave"
	 			<<setw(20)<<"Nombre"
 				<<setw(15)<<"Autor"
 				<<setw(16)<<"Genero"
 				<<setw(15)<<"Precio"<<endl;
 				for ( int i=0;i<NUM;i++){
					if (cancion[i].clave==claveC){
						if (credito>cancion[i].precio){
							credito=credito-cancion[i].precio;
						cancion[i].clave=clavescanciones[i];
	 				cout <<setw(6)<<cancion[i].clave
	 					 <<setw(20)<<cancion[i].nombre
	 					 <<setw(15)<<cancion[i].autor
	 					 <<setw(16)<<cancion[i].genero
	 					 <<setw(15)<<cancion[i].precio<<endl;
						  }else{
	 					 	cout<<"No puedes comprar la cancion"<<"\n";
						  }
			}
		}
		cout<<"\nAhora tu credito es="<<credito<<"\n\n";
		system("pause");
		system("cls");
}

int listacanciones(){
	cout<<"\nLista de canciones compradas\n\n";
    		cout<<setw(6)<<"Clave"
	 			<<setw(20)<<"Nombre"
 				<<setw(15)<<"Autor"
 				<<setw(16)<<"Genero"
 				<<setw(15)<<"Precio"<<endl;
 				for ( int i=0;i<NUM;i++){
					if (cancion[i].clave==clavescanciones[i]){
	 				cout <<setw(6)<<cancion[i].clave
	 					 <<setw(20)<<cancion[i].nombre
	 					 <<setw(15)<<cancion[i].autor
	 					 <<setw(16)<<cancion[i].genero
	 					 <<setw(15)<<cancion[i].precio<<endl;
		           }else{
		           	return -1;
				   }
			}
      cout<<"\n\n";
	}
	

