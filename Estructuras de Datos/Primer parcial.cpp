 //Desarrolle un programa que elimine una lista simple de viveres creada por usted, los productos repetidos, garantizando que solo quede un solo producto de dicha 
//especificacion; diseñe el tipo de dato para que contenga los siguientes atributos:
	//codigo,descripcion,cantidad ;reporte adecuadamente los resultados del proceso(antes y despues de); separe responsabilidades 
#include<iostream>

using namespace std;

struct Productos{
	int cantidad;
	string cod;
	string producto;
	string descrip;
	double precio;
	Productos* next;
};

string getCadena(string txt){
	cout<<txt;
	string cdx;
	getline(cin,cdx);
	return cdx;
}

string producto(string txt){
	string prod;
	cout << txt;
	getline(cin,prod);
	return prod;
}

string cod(string txt){
	string cod;
	cout << txt;
	getline(cin,cod);
	return cod;
}

string desc(string txt){
	string desc;
	cout << txt;
	getline(cin,desc);
	return desc;
}

int cantidad(string txt){
	int nx;
	cout << txt;
	cin >> nx;
	cin.ignore();
	return nx;
}

double precio(string txt){
	double nx;
	cout << txt;
	cin >> nx;
	cin.ignore();
	return nx;
}

Productos* getnode() {
    Productos* aux = new Productos();
    aux->producto = producto("Ingrese el producto que quiere en la lista: ");
    aux->cod = cod("Ingrese código: ");
    aux->descrip = desc("Ingrese descripcion: ");
    aux->cantidad = cantidad("Ingrese cantidad: ");
    aux->precio = precio("Ingrese precio: ");
    aux->next = NULL;  
    return aux;
}


void getlist(Productos** cadena) {
    Productos* aux;
    Productos* d;
    char op;
    do {
        aux = getnode();  
        if (*cadena) {  
            d = *cadena;
            while (d->next) {  
                d = d->next;
            }
            d->next = aux;  
        } else {
            *cadena = aux;  
        }
        cout << "Desea ingresar otro producto? (s/n): ";
        cin >> op;
        cin.ignore();  
    } while (op == 's' || op == 'S');
}


void printlist(Productos* lst) {
    cout << "Listado de productos...\n";
    if (!lst) {
        cout << "La lista está vacía.\n";
        return;
    }
    while (lst) {  // Mientras la lista no esté vacía
        cout << "Producto: " << lst->producto << "\n";
        cout << "Codigo: " << lst->cod << "\n";
        cout << "Cantidad: " << lst->cantidad << "\n";
        cout << "Descripcion: " << lst->descrip << "\n";
        cout << "Precio: " << lst->precio << "\n";
        lst = lst->next;  // Mover al siguinte nodo
    }
}

void menu(){
	cout<< "Menu de seleccion: \n";
	cout<< "1. Ingresar producto y carac.\n";
	cout<< "2. Revise sus productos.\n";
	cout<< "3. Productos repetidos\n";
	cout<< "4. Acabar programa.\n";
}

void eliminarRepetidos(Productos* cabeza) {
    Productos* actual = cabeza;

    while (actual != NULL) {
        Productos* anterior = actual;
        Productos* siguiente = actual->next;

        
        while (siguiente != NULL) {
           
            if (actual->cod == siguiente->cod) {
            
                anterior->next = siguiente->next;
                delete siguiente;  
                siguiente = anterior->next;  
            } else {
                anterior = siguiente;
                siguiente = siguiente->next;
            }
        }
        actual = actual->next;
    }
}


void proceso() {
    Productos* lst = NULL;
    int op;

    do {
        menu();  
        cin >> op;  
        cin.ignore();

        switch (op) {
            case 1: {
                getlist(&lst);  
                break;
            }
            case 2: {
                printlist(lst);  
                break;
            }
            case 3: {
                eliminarRepetidos(lst);  
                cout << "Productos repetidos eliminados.\n";
                printlist(lst);  
                break;
            }
            case 4: {
                cout << "Terminando programa...\n";
                break;
            }
            default: {
                cout << "Opción no encontrada. Intente nuevamente.\n";
                break;
            }
        }
    } while (op != 4);  
}




int main(){
	
	proceso();
	
	return 0;
}
