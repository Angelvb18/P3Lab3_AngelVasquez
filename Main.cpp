#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int** CPredefinida();
void conway(int** mat, int x, int y, int turnos);
void actualizargen(int **& mat , int ** matt , int , int); 
int** Random(int);
void menu();
void imp(int** , int);
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
				int x , y;
				cout << "Ingrese el tamano en x del tablero\n:";
				cin >> x;
				cout << "Ingrese el tamano en y del tablero\n:";
				cin >> y;
				int ** mat = NULL; 
				//conway(mat, x, y, turnos);
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
void imp(int** mat, int size){
     if(mat != NULL){
     	for(int j = 0; j < size ; j++){
			cout << "#";
		}
		cout << endl; 
	    for(int i = 0; i < size ; i++){
			for(int j = 0; j < size ; j++){
				if(j == 0){
				   cout << "#";
				}
			    if(mat[i][j] == 0){
				   cout << " ";
				}
				else{
				   cout << "*";
				}
			}
			cout <<"#"<< endl;
		}
		for(int j = 0; j < size ; j++){
			cout << "#";
		}
		cout << endl;
	 }
}
void actualizargen(int **& mat , int ** mat2 , int x , int y){
	for(int i = 0 ; i < x ; i++){
	    for(int j = 0 ; j < y ; j++){
		    if(j == 0 && mat[i][j] != 0 && i > 0 && i < y|| j == y-1 && mat[i][j] != 0 && i > 0 && i < y){
		    	
			}else{
				if(i == 0 && mat[i][j] != 0 && j > 0 && j < x|| i == x-1 && mat[i][j] != 0 && j > 0 && j < y){
				}
				else{
					
				}
			}
		}
	}
}

void conway(int** mat, int x, int y, int turnos){
    if(turnos == 0 ){
    	
	}else{
		actualizargen(mat,mat,x,y);
	    conway(mat,  x,  y,  turnos-1);
	}
	   
	
}
