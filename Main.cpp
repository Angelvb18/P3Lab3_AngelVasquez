#include<iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::cin;
using std::endl;
int** creatematiz(int,int);
int** CPredefinida();
void conway(int** mat, int x, int y, int turnos);
void actualizargen(int**& mat , int , int); 
int** Random(int);
void menu();
void imp(int** , int, int);
int main(){
    menu();
}

void menu(){
	int op;
    do{
    	cout <<"Bienvenido al juego de la vida de Conway!!!\n";
    	cout << "1.Jugar con matriz random\n2.Jugar con matriz predefinida" <<
    			"\n3.Salir\n:";
    	cin >> op;
    	switch(op){
			case 1:{
				int x , y, turnos;
				cout << "Ingrese el tamano en x del tablero\n:";
				cin >> x;
				cout << "Ingrese el tamano en y del tablero\n:";
				cin >> y;
				cout << "Ingrese cantidad de turnos por hacer\n:";
				cin >> turnos;
				int** mat = creatematiz(x,y);
				conway(mat, x, y, turnos);
				break;
			}
			case 2:{
				int si = 20 , gens;
				int** mat = NULL;
				mat = CPredefinida();
				cout << "Ingrese cantidad de turnos por hacer\n:";
				cin >> gens;
				conway(mat, si, si, gens);
				break;
			}
			case 3:{
				cout << "Adios" << endl;
				break;
			}
		}
	}while(op != 3);
}
int** CPredefinida(){
	int x=20 , y = 20;
	int temp_mat [20][20] = {	
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0},
		{0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0},
		{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
		};
	int ** mat = new int*[y];
	for(int i = 0; i < y ; i++){
		mat[i] = new int[x];
		for(int j = 0; j < x ; j++){
			mat[i][j] = temp_mat[i][j];
		} 
   }
   return mat;
}
void imp(int** mat, int size, int size2){
     if(mat != NULL){
     	for(int j = 0; j < size ; j++){
			cout << "###";
		}
		cout << endl; 
	    for(int i = 0; i < size ; i++){
			for(int j = 0; j < size2 ; j++){
				if(j == 0){
				   cout << "#";
				}
			    if(mat[i][j] == 0){
				   cout << "   ";
				}
				else{
				   cout << " * ";
				}
			}
			cout <<"#"<< endl;
		}
		for(int j = 0; j < size ; j++){
			cout << "###";
		}
		cout << endl;
	 }
}
void actualizargen(int**& mat , int x , int y){
	int** mat2 = NULL;
    mat2 = new int*[x];
    for(int i = 0 ; i < x ; i++){
		mat2[i] = new int[y];
	}
    for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < y ; j++){
		   mat2[i][j]= mat[i][j];
		}
	}
	cout<< "s";
	for(int i = 0 ; i < x ; i++){
	    for(int j = 0 ; j < y ; j++){
		    if(j == 0 || j < y){
		    	
			}else{
				if(i == 0 || i < x){
				}
				else{
					int cont = 0  ,cont2 = 0;
					for(int t = -1 ; t < 2 ; t++){
					    if(mat2 [i][j+t] != 0){
						   cont++;
						}
					}
					for(int t = -1 ; t < 2 ; t++){
					    if(mat2 [i+t][j] != 0 ){
						   cont2++;
						}
					}
					if(cont+cont2 <=3 && cont+cont2 >1){
					    if(mat2[i][j] == 0 && cont+cont2 == 3 ){
					        mat[i][j] = 1;
						}
					}else{
					    if(cont+cont2 > 3){
						    if(mat2[i][j] != 0){
							   mat2[i][j] = 0;
							}
						}else{
							if(cont+cont2 < 2){
							    if(mat2[i][j] != 0){
								    mat[i][j] = 1;
								}
							}
						}
					}
					
				}
			}
		}
	}
	cout << "asdasmdñ" << endl;
}
int** creatematiz(int x , int y){
    int** ma = NULL;
    ma = new int*[x];
    srand(time (NULL));
    for(int i = 0 ; i < x ; i++){
		ma[i] = new int[y];
	}
    for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < y ; j++){
		   ma[i][j]= 0 + rand ()% ( 2 );
		}
	}
    return ma;
}
void conway(int** mat, int x, int y, int turnos){
    /*if(turnos == 0 ){
    	
	}else{
		actualizargen(mat,mat,x,y);
		imp(mat,x,y);
	    conway(mat,  x,  y,  turnos-1);
	}*/
	for(int k = 0 ; k < turnos ; k++){
		 actualizargen(mat,x,y); 
		imp(mat,x,y);
	}
	
}
