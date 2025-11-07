#include <iostream>
#include <locale.h>
#include <string>
#include <cstdlib>
#include <limits>
#include <cctype>
#include "credenciales.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "spanish");

    int opc;
    int currentUserPos = -1;

    system("cls");
    contarLineasCodigoPrincipal();
    system("pause");

    do {
        system("cls");
        opc = menu();

        if (cin.fail() || opc < 1 || opc > 6) {
            cout << "Opción inválida. Por favor, elija una opción entre 1 y 6.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            continue;
        }

        switch (opc) {
            case 1:
                imprimirDetallesPlanNormal();
                cout << "\n¿Desea continuar?\n1. Pagar\n2. Cancelar\n";
                cout << "Opción: ";
                int planOption;
                while (!(cin >> planOption) || (planOption != 1 && planOption != 2)) {
                    cout << "Entrada inválida. Por favor, ingrese 1 para Pagar o 2 para Cancelar: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                system("cls");

                if (planOption == 1) {
                    if (totalusers < tam) {
                        cout << "Gracias por su compra del Plan Normal.\n";
                        cout << "\n--- Registro de usuario ---\n";
                        leeruser(1);
                        imprimiruser(totalusers - 1);
                    } else {
                        cout << "Lo sentimos, no hay espacio para más registros.\n";
                    }
                } else {
                    cout << "\tCancelando... Regresando al menú principal.\n";
                }
                break;

            case 2:
                imprimirDetallesPlanRolo();
                cout << "\n¿Desea continuar?\n1. Pagar\n2. Cancelar\n";
                cout << "Opción: ";
                int planOptionRolo;
                while (!(cin >> planOptionRolo) || (planOptionRolo != 1 && planOptionRolo != 2)) {
                    cout << "Entrada inválida. Por favor, ingrese 1 para Pagar o 2 para Cancelar: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                system("cls");

                if (planOptionRolo == 1) {
                    if (totalusers < tam) {
                        cout << "Gracias por su compra del Plan Rolo.\n";
                        cout << "\n--- Registro de usuario ---\n";
                        leeruser(2);
                        imprimiruser(totalusers - 1);
                    } else {
                        cout << "Lo sentimos, no hay espacio para más registros.\n";
                    }
                } else {
                    cout << "\tCancelando... Regresando al menú principal.\n";
                }
                break;
                
            case 3:{
            	char ver;
            	cout << "Desea ver usuarios?(S/N)\n";
            	cin >>ver;
            	if (ver == 's'||ver=='S'){
            		imprimirmatriz();
            		
				} if(tf>0){
		int sumacostos= sumarColumnaMatriz(M,tf,3);
		int *ap=&sumacostos;
		cout<<"\n La ganancia de nuestro gimnasio rolo es:"<<sumacostos<<"k\t\n";
		double tazI=*ap*0.15;
		*ap=sumacostos-*ap*0.15;
		
		cout<<"\n Las ganancias con el impuesto de nuestro gim es :"<<sumacostos<<"k\t\n";
		cout<<"\n La direcion de memoria de sumacostos es:"<<ap<<"\t\n";
		cout<<"\n La taza de impuesto para el gimnasio equivale a:\t"<<tazI<<"k\t\n";
		}else{
			cout<<"\nError no hay ningun usuario reginstrado por ende no hay ganancias :("<<endl;
		} 	
				break;			
			}

            case 4: {
                string nombre, contra;
                cout << "\n\t--- Inicio de sesión ---\n";
                cout << "Ingrese su usuario: ";
                cin >> nombre;
                cout << "Ingrese su contraseña: ";
                cin >> contra;

                currentUserPos = valUs(nombre, contra);
                if (currentUserPos != -1) {
                    cout << "Inicio de sesión exitoso.\n";
                    cout << "--- Bienvenido " << nom[currentUserPos] << ", su Plan es " << (tipoPlan[currentUserPos] == 1 ? "Normal" : "Rolo") << " ---\n";

                    int memberMenuOption;
                    do {
                        system("pause");
                        system("cls");
                        memberMenuOption = menuM();

                        switch (memberMenuOption) {
                            case 1:
                                cout << "\n\t--- Cambiar de Plan ---\n";
                                cout << "Su plan actual es: " << (tipoPlan[currentUserPos] == 1 ? "Normal" : "Rolo") << "\n";
                                cout << "¿A qué plan desea cambiar?\n";
                                cout << "1. Plan Normal\n";
                                cout << "2. Plan Rolo\n";
                                cout << "Opción: ";
                                int newPlanChoice;
                                while (!(cin >> newPlanChoice) || (newPlanChoice != 1 && newPlanChoice != 2)) {
                                    cout << "Entrada inválida. Por favor, ingrese 1 para Plan Normal o 2 para Plan Rolo: ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }

                                if (newPlanChoice == tipoPlan[currentUserPos]) {
                                    cout << "Ya tiene ese plan. No se requiere cambio.\n";
                                } else {
                                    tipoPlan[currentUserPos] = newPlanChoice;
                                    cout << "Su plan ha sido cambiado a: " << (tipoPlan[currentUserPos] == 1 ? "Normal" : "Rolo") << "\n";
                                }
                                break;
                            case 2:
                                renovarPlan(currentUserPos);
                                break;
                            case 3:{
                            	int cambiar;
                            	cout << "\n\t--- Qué desea cambiar? ---\n"
                            	<<"\t1. Nombre\n"
                            	<<"\t2. Contraseña\n"
                            	<< "\nOpción: ";
                            	cin>>cambiar;
                            	if(cambiar==1){
                            		cambiarnom(currentUserPos);
								}else if (cambiar ==2){
									cambiarcontra(currentUserPos);
								}
								break;
							}    
                            case 4:{
							
                                cout << "\n\t--- Cancelar Plan ---\n";
                                cout << "¿Está seguro que desea cancelar su plan? (S/N): ";
                                char confirmCancel;
                                cin >> confirmCancel;
                                if (toupper(confirmCancel) == 'S') {
                                    eliminaruser(currentUserPos);
                                    cout << "Su plan ha sido cancelado y su cuenta eliminada.\n";
                                    memberMenuOption = 4;
                                    currentUserPos = -1;
                                    break;
								}
							}
                             
                            case 5:
                                cout << "Saliendo del menú de miembro.\n";
                                break;
                            default:
                                cout << "Opción inválida. Por favor, elija una opción válida.\n";
                                break;
                        }
                    } while (memberMenuOption != 5 && currentUserPos != -1);
                } else {
                    cout << "Usuario o contraseña incorrectos, o no existe el usuario.\n";
                }
                break;
            }
            
            case 5:{
            	string contra="Fernanfloo";
            	string fernan;
            	cout << "Ingrese contraseña de desarrollador: ";
            	cin >> fernan;
            	if (fernan == contra){
            		do{
            			system("cls");
            			opc=menuadmin();
            			switch(opc){
            				case 1:{
            					char guardar;
            					cout << "Desea guardar su archivo? Este incluye los registros de los clientes(S/N)\n";
            					cin >> guardar;
            					if (guardar =='s'||guardar=='S'){
            						guardardatos();
            						cout << "Guardando...\n";
									break;           						
								}else{
									cout << "Regresando...\n";
								}
								break;
							}
							case 2:{
            					char cargar;
            					cout << "Desea cargar su archivo? Este incluye los registros de los clientes(S/N)\n";
            					cin >> cargar;
            					if (cargar =='s'||cargar=='S'){
            						cargardatos();
									break;           						
								}else{
									cout << "Regresando...\n";
								}
								break;								
							}
							case 3:{
								cout << "Volviendo al menu principal...\n";
								break;
							}
						}
						if (opc!=3){
							system ("pause");
						}
					}while (opc!=3);
				}else{
					cout << "Contraseña incorrecta, regresando...\n";
					break;
				}
				break;
			}

            case 6:
                cout << "¡Hasta luego! ¡Nos vemos pronto!\n";
                break;
        }

        if (opc != 6) {
            system("pause");
        }

    } while (opc != 6);

    return 0;
}
