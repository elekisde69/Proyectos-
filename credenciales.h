#ifndef CREDENCIALES_H
#define CREDENCIALES_H

#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <cstdlib>

#define tc 4
#define tam 50

using namespace std;


string nom[tam];
string contra[tam];
int tipoPlan[tam];
int totalusers = 0;
int tf=0;
int (*M)[tc] = NULL;

int menu();
int menuM();
void imprimirDetallesPlanNormal();
void imprimirDetallesPlanRolo();
void leeruser(int planElegido);
void imprimiruser(int pos);
void imprimirmatriz();
int valUs(string name, string password);
void eliminaruser(int pos);
void renovarPlan(int posUsuario);
void contarLineasCodigoPrincipal();
void guardardatos();
int sumaColumnamatriz(int(*matriz)[tc],int numFilas,int indiceColumna);

int menuadmin(){
	int admin;
    cout << "\n\t--- Bienvenido admin ---\n"
         << "\n\tElija la opción que desea:\n"
         << "\t1. Guardar archivo\n"
         << "\t2. Cargar archivo\n"
         << "\t3. Salir\n"
         << "\nOpción: ";
    while (!(cin >> admin)) {
        cout << "Entrada inválida. Por favor, ingrese un número: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return admin;		 	
	
}

int menu() {
    int pl;
    cout << "\n\t--- Bienvenido al Gimnasio Rolo ---\n"
         << "\n\tElija el plan que desea contratar:\n"
         << "\t1. Plan Normal\n"
         << "\t2. Plan Rolo\n"
         << "\t3. Leer miembros\n"
         << "\t4. Ya soy miembro\n"
         << "\t5. Soy desarrollador\n"
         << "\t6. Salir\n"
         << "\nOpción: ";
    while (!(cin >> pl)) {
        cout << "Entrada inválida. Por favor, ingrese un número: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return pl;
}

int menuM() {
    int Rs;
    cout << "\n\t--- Bienvenido al Gimnasio Rolo, querido usuario ---\n"
         << "\n\t¿Qué desea hacer ahora?\n"
         << "\t1. Cambiar de plan\n"
         << "\t2. Renovar mi plan\n"
         << "\t3. Cambiar contraseña/usuario\n"
         << "\t4. Cancelar mi plan\n"
         << "\t5. Salir al menú principal\n"
         << "\nOpción: ";
    while (!(cin >> Rs)) {
        cout << "Entrada inválida. Por favor, ingrese un número: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return Rs;
}

void imprimirDetallesPlanNormal() {
    cout << "\n\t--- Plan Normal ---\n"
         << "\tCosto: 50.000 COP\n"
         << "\tBeneficios:\n"
         << "\t- Asesoramiento Personalizado\n"
         << "\t- Acceso Móvil\n"
         << "\t- Acceso a todas las áreas\n";
}

void imprimirDetallesPlanRolo() {
    cout << "\n\t--- Plan Rolo ---\n"
         << "\tCosto: 100.000 COP\n"
         << "\tBeneficios:\n"
         << "\t- Asesoramiento Personalizado\n"
         << "\t- Acceso Móvil\n"
         << "\t- Acceso a todas las áreas\n"
         << "\t- Acceso a zona de relajación\n"
         << "\t- Acceso en todas las sedes\n"
         << "\t- Derecho a traer Invitado 5 Veces/mes\n";
}

void leeruser(int planElegido) {
    if (totalusers >= tam) {
        cout << "No se pueden registrar más usuarios. Capacidad máxima alcanzada.\n";
        return;
    }
    
    // Solicitar datos del usuario 
    cout << "\n\tPor favor, ingrese sus datos:\n";
    cout << "Nombre: ";
    cin >> nom[totalusers];
    cout << "Contraseña: ";
    cin >> contra[totalusers];
    
    tipoPlan[totalusers] = planElegido;
    
    // Redimensionar matriz M
    int (*temp)[tc] = (int (*)[tc])realloc(M, (tf + 1) * sizeof(int[tc]));
    if (temp == NULL) {
        cout << "Error: No se pudo asignar memoria.\n";
        exit(1);
    }
    M = temp;
    
    M[tf][0] = totalusers + 1;      // ID del usuario
    M[tf][1] = planElegido;         // Tipo de plan 
    M[tf][2] = 1;                   // Estado (1=Activo)
    M[tf][3] = (planElegido == 1) ? 50 : 100; // Costo
    
    totalusers++;
    tf++;
    cout << "¡Registro exitoso!\n";
}

void cambiarnom(int pos){
	if (pos>=0 && pos < totalusers){
     cout << "\n\tPor favor, ingrese su nuevo nombre:\n";
     cout << "Nombre: ";
     cin >> nom[pos];	
	 nom[pos]=nom[pos];
	 
	}	
}

void cambiarcontra(int pos){
	if (pos>=0 && pos < totalusers){
     cout << "\n\tPor favor, ingrese su nueva contraseña:\n";
     cout << "Contraseña: ";
     cin >> contra[pos];	
	 contra[pos]=contra[pos];
	}	
}

void imprimiruser(int pos) {
    if (pos >= 0 && pos < totalusers) {
        cout << "\n\t--- Información de usuario ---\n"
             << "Usuario: " << nom[pos] << "\n"
             << "Contraseña: " << contra[pos] << "\n"
             << "Tipo de plan: " << (tipoPlan[pos] == 1 ? "Normal" : "Rolo") << "\n\n";
    } else {
        cout << "Error: Posición de usuario inválida para imprimir.\n";
    }
}

void imprimirmatriz() {
    if (tf == 0) {
        cout << "No hay usuarios registrados.\n";
        return;
    }
    
    cout << "\nUsuarios Nombres  Plan    Coste\n";
    cout << "--------------------------------\n";
    
    for (int f = 0; f < tf; f++) {
        cout << M[f][0] << "\t" ;
        cout << nom[f] << "   \t";
        cout << (M[f][1] == 1 ? "  Normal" : "  Rolo  ")<<"   ";
        cout << M[f][3] << "k\n";
    }
}int sumarColumnaMatriz(int (*matriz)[tc], int numFilas, int indiceColumna) {	
	int suma =0;
	if(indiceColumna<0|| indiceColumna>= tc){
		cout<<"Error indice de columnas invalido\n";
		return 0;
	}	
		 for (int i = 0; i < numFilas; i++) {
		 	suma += matriz[i][indiceColumna];
		 	
}
	return suma;
}



int valUs(string name, string password) {
    for (int i = 0; i < totalusers; i++) {
        if (name == nom[i] && password == contra[i]) {
            return i;
        }
    }
    return -1;
}

void eliminaruser(int pos) {
    if (pos >= 0 && pos < totalusers) {
        // Mover datos en los arreglos
        for (int i = pos; i < totalusers - 1; i++) {
            nom[i] = nom[i + 1];
            contra[i] = contra[i + 1];
            tipoPlan[i] = tipoPlan[i + 1];
            
            // Mover datos en la matriz M
            for (int j = 0; j < tc; j++) {
                M[i][j] = M[i+1][j];
            }
            M[i][0] = i+1; // Actualizar ID
        }
        
        totalusers--;
        tf--;
        
        // Redimensionar matriz
        int (*temp)[tc] = (int (*)[tc])realloc(M, tf * sizeof(int[tc]));
        if (tf > 0 && temp == NULL) {
            cout << "Error al redimensionar la matriz después de eliminar.\n";
            return;
        }
        M = temp;
        
        cout << "El usuario ha sido eliminado exitosamente.\n";
    } else {
        cout << "Error: Posición de usuario inválida para eliminar.\n";
    }
}

void renovarPlan(int posUsuario) {
    if (posUsuario < 0 || posUsuario >= totalusers) {
        cout << "Error: Usuario no válido para renovación.\n";
        return;
    }

    string planNombre = (tipoPlan[posUsuario] == 1) ? "Normal" : "Rolo";
    int costo = (tipoPlan[posUsuario] == 1) ? 50000 : 100000;

    cout << "\n\t--- Renovar Plan ---\n";
    cout << "Su plan actual es: " << planNombre << ".\n";
    cout << "El costo de renovación es: " << costo << " COP.\n";
    cout << "¿Desea continuar con la renovación?\n1. Pagar\n2. Cancelar\n";
    cout << "Opción: ";

    int opcionRenovar;
    while (!(cin >> opcionRenovar) || (opcionRenovar != 1 && opcionRenovar != 2)) {
        cout << "Entrada inválida. Por favor, ingrese 1 para Pagar o 2 para Cancelar: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (opcionRenovar == 1) {
        cout << "¡Gracias por renovar su plan " << planNombre << "!\n";
        cout << "Su plan ha sido renovado exitosamente.\n";
    } else {
        cout << "Renovación cancelada. Regresando al menú de miembro.\n";
    }
}

void contarLineasCodigoPrincipal() {
    ifstream file("gim Esc.cpp");
    string line;
    int count = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            count++;
        }
        file.close();
        cout << "\n--- Información del programa ---\n";
        cout << "El archivo 'main.cpp' tiene " << count << " líneas de código.\n";
    } else {
        cout << "No se pudo abrir el archivo 'main.cpp' para contar las líneas.\n";
        cout << "Asegúrese de que 'main.cpp' esté en el mismo directorio que el ejecutable.\n";
    }
}

void guardardatos(){
	ofstream gArch("gym.txt");
    if (gArch.fail()) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
        gArch <<"\nUsuarios Nombres  Plan    Coste\n"
              << "--------------------------------\n";
    for (int i=0;i<totalusers;i++){

        gArch << M[i][0] << "\t" << nom[i] << "   \t";
	    gArch << (M[i][1] == 1 ? "  Normal" : "  Rolo  ")<<"   ";
        gArch << M[i][3] << "k\n";     
	}
		
}

void cargardatos(){
	ifstream gArch("gym.txt");
	if(gArch.fail()) {
		cout << "Error: No se pudo abrir el archivo."<<endl;
		return;
	}
	
	string linea;
	
	while (getline(gArch, linea)) {
        cout << linea << endl;
    }

    gArch.close();
	
}


#endif // CREDENCIALES_H
