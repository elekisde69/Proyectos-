#include <iostream>
#include <string>
using namespace std;

struct Moto {
    string placa;
    string marca;
    string modelo;
    double cilindrada;
    Moto* sig;
    Moto* ant;
};

string getCadena(const string& txt) {
    string cdx;
    cout << txt;
    getline(cin, cdx);
    return cdx;
}

int getEntero(const string& txt) {
    int nx;
    cout << txt;
    cin >> nx;
    cin.ignore();
    return nx;
}

double getDouble(const string& txt) {
    double nx;
    cout << txt;
    cin >> nx;
    cin.ignore();
    return nx;
}

Moto* crearMoto() {
    Moto* aux = new Moto();
    aux->placa = getCadena("Ingrese placa: ");
    aux->marca = getCadena("Ingrese marca: ");
    aux->modelo = getCadena("Ingrese modelo: ");
    aux->cilindrada = getDouble("Ingrese cilindrada (cc): ");
    aux->sig = NULL;
    aux->ant = NULL;
    return aux;
}

void adicionarMoto(Moto** lst) {
    Moto* nuevaMoto = crearMoto();
    if(*lst==NULL){
    	*lst=nuevaMoto;
    	cout << "\n*** Moto adicionada exitosamente ***\n\n";
    	return;
	}
	
	Moto* aux=*lst;
	Moto* ant=NULL;
	
	while(aux && aux->placa < nuevaMoto->placa){
		ant=aux;
		aux=aux->sig;
	}
	
	if(ant==NULL){
		nuevaMoto->sig=*lst;
		(*lst)->ant=nuevaMoto;
		*lst=nuevaMoto;
	}else{
		nuevaMoto->sig=aux;
		nuevaMoto->ant=ant;
		ant->sig=nuevaMoto;
		if(aux){
			aux->ant=nuevaMoto;
		}
	}
    
    cout << "\n*** Moto adicionada exitosamente ***\n\n";
}

void mostrarMoto(Moto* moto) {
    if (moto) {
        cout << "\n===== INFORMACION DE MOTO =====\n";
        cout << "Placa: " << moto->placa << "\n";
        cout << "Marca: " << moto->marca << "\n";
        cout << "Modelo: " << moto->modelo << "\n";
        cout << "Cilindrada: " << moto->cilindrada << " cc\n";
        cout << "===============================\n\n";
    }
}

Moto* buscarMoto(Moto* lst, const string& placa) {
    while (lst) {
        if (lst->placa == placa) return lst;
        lst = lst->sig;
    }
    return NULL;
}

// Función corregida: cuenta pares e impares y devuelve por referencia
void digitsPlaca(const string& placa, int& pares, int& impares) {
    const int MAX = 8;
    int digitos[MAX];
    int contador = 0;
    for (int i = 0; i <placa.size(); i++) {
        if (isdigit(placa[i])) {
            if (contador < MAX) {  // evita overflow
                digitos[contador] = placa[i] - '0';
                contador++;
            }
        }
    }

}

void eliminarMoto(Moto** lst) {
    if (*lst == NULL) {
        cout << "\nNo hay motos registradas\n\n";
        return;
    }
    string placa = getCadena("Ingrese placa de la moto a eliminar: ");
    Moto* aux = *lst;
    while (aux && aux->placa != placa){
    	aux = aux->sig;
	} 
	
    if (!aux) {
        cout << "\nMoto no encontrada\n\n";
        return;
    }

    // Comparar con nodos adyacentes
    if (aux->sig && aux->placa > aux->sig->placa) {
        Moto* nodoEliminar = aux->sig;
        aux->sig = nodoEliminar->sig;
        if (nodoEliminar->sig){
        	nodoEliminar->sig->ant = aux;
		}
            
        cout << "\n*** Nodo posterior eliminado exitosamente ***\n";
        mostrarMoto(nodoEliminar);
        delete nodoEliminar;
    } 
    else if (aux->ant && aux->placa < aux->ant->placa) {
        
        Moto* nodoEliminar = aux->ant;
        if (nodoEliminar->ant) {
            nodoEliminar->ant->sig = aux;
            aux->ant = nodoEliminar->ant;
        } else {
            *lst = aux;
            aux->ant = NULL;
        }
        cout << "\n*** Nodo anterior eliminado exitosamente ***\n";
        mostrarMoto(nodoEliminar);
        delete nodoEliminar;
    } 
    else {
        
        if (aux == *lst) {
            *lst = aux->sig;
            if (*lst) (*lst)->ant = NULL;
        } else {
            if (aux->ant) aux->ant->sig = aux->sig;
            if (aux->sig) aux->sig->ant = aux->ant;
        }
        cout << "\n*** Nodo actual eliminado exitosamente ***\n";
        mostrarMoto(aux);
        delete aux;
    }
}

void insertarMoto(Moto** lst) {
    if (*lst == NULL) {
        cout << "La lista está vacía. No se puede insertar por placa.\n";
        return;
    }
    string placaBuscar = getCadena("Ingrese la placa de la moto de referencia para insertar: ");
    Moto* aux = *lst;
    Moto* ant = NULL;
    while (aux && aux->placa != placaBuscar) {
        ant = aux;
        aux = aux->sig;
    }
    if (!aux) {
        cout << "No se encontró la moto con placa " << placaBuscar << ".\n";
        return;
    }
    
    Moto* nuevaMoto = crearMoto();
    
	while(aux && aux->placa < nuevaMoto->placa){
		ant=aux;
		aux=aux->sig;
	}

	if(ant==NULL){
		nuevaMoto->sig=*lst;
		(*lst)->ant=nuevaMoto;
		*lst=nuevaMoto;
	}else{
		nuevaMoto->sig=aux;
		nuevaMoto->ant=ant;
		ant->sig=nuevaMoto;
	}
    cout << "\n*** Moto insertada exitosamente ***\n\n";
}

void listarMotos(Moto* lst) {
    if (!lst) {
        cout << "\nNo hay motos registradas\n\n";
        return;
    }
    cout << "\n===== LISTADO DE MOTOS =====\n";
    int contador = 1;
    while (lst) {
        cout << "Moto #" << contador++ << "\n";
        cout << "Placa: " << lst->placa << "\n";
        cout << "Marca: " << lst->marca << "\n";
        cout << "Modelo: " << lst->modelo << "\n";
        cout << "Cilindrada: " << lst->cilindrada << " cc\n";
        cout << "----------------------------\n";
        lst = lst->sig;
    }
    cout << "\n";
}

void menu() {
    Moto* listaMotos = NULL;
    int opcion;
    do {
        cout << "\n===== BIENVENIDO A SUPERBIKES =====\n";
        cout << "1. Adicionar moto\n2. Eliminar moto\n3. Insertar moto basado en placa\n";
        cout << "4. Listar todas las motos\n5. Buscar moto por placa\n6. Salir\n";
        cout << "===================================\n";
        opcion = getEntero("Seleccione una opcion: ");

        switch (opcion) {
            case 1: adicionarMoto(&listaMotos); break;
            case 2: eliminarMoto(&listaMotos); break;
            case 3: insertarMoto(&listaMotos); break;
            case 4: listarMotos(listaMotos); break;
            case 5: {
                string placa = getCadena("Ingrese placa a buscar: ");
                Moto* moto = buscarMoto(listaMotos, placa);
                if (moto) mostrarMoto(moto);
                else cout << "\nMoto no encontrada\n\n";
                break;
            }
            case 6:
                cout << "\nGracias por usar SuperBikes\n";
                break;
            default:
                cout << "\nOpcion invalida\n\n";
        }
    } while (opcion != 6);
}

int main() {
	setlocale(LC_ALL,"Spanish");
    menu();
    return 0;
}


