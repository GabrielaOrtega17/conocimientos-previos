#include <iostream>
#include <cstring>

class Empleado {
private:
    int claveEmpleado;
    char nombre[100];
    char domicilio[100];
    float sueldo;
    char reportaA[100];

public:
    // Constructor
    Empleado(int clave, const char* nombre, const char* domicilio, float sueldo, const char* reportaA) {
        claveEmpleado = clave;
        strcpy(this->nombre, nombre);
        strcpy(this->domicilio, domicilio);
        this->sueldo = sueldo;
        strcpy(this->reportaA, reportaA);
    }

    // Método para imprimir los datos del empleado
    void imprime() {
        std::cout << "Clave de Empleado: " << claveEmpleado << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Domicilio: " << domicilio << std::endl;
        std::cout << "Sueldo: " << sueldo << std::endl;
        std::cout << "Reporta a: " << reportaA << std::endl;
    }

    // Método para cambiar el domicilio
    void cambiaDomic(const char* nuevoDomicilio) {
        strcpy(domicilio, nuevoDomicilio);
    }

    // Método para cambiar el supervisor al que reporta
    void cambiaReportaA(const char* nuevoSupervisor) {
        strcpy(reportaA, nuevoSupervisor);
    }

    // Método para actualizar el sueldo
    void actualSueldo(float nuevoSueldo) {
        sueldo = nuevoSueldo;
    }
    bool operator == (const Empleado&);
    bool operator < (const Empleado&);
    bool operator <= (const Empleado&);
    bool operator > (const Empleado&);
    bool operator >= (const Empleado&);
    friend std::istream operator >> (std::istream&, Empleado&);
    friend std::ostream operator << (std::ostream&, const Empleado&);

};

int main() {
    // Crear dos objetos de la clase Empleado
    Empleado empleado1(1, "Juan Perez", "Calle 123", 2500.0, "Supervisor A");
    Empleado empleado2(2, "Maria Rodriguez", "Calle 456", 2800.0, "Supervisor B");

    int opc,domicilioN,sueldoN,supervisorN;

    do{
        system("cls");

        std::cout << " 1. Cambiar el domicilio de un empleado" << std::endl;
        std::cout << " 2. Actualizar sueldo " << std::endl;
        std::cout << " 3. Imprimir datos de un empleado" << std::endl;
        std::cout << " 4. Cambiar el nombre de quien reporta " << std::endl;
        std::cout << " Elige una opcion: " << std::endl << std::endl;
        std::cin >> opc;

        switch(opc){
            case 1: std::cout << " Escribe el nuevo domicilio: ";
                    std::cin >> domicilioN;
                    cambiaDomic(domicilioN);
                break;

            case 2: std::cout << " Escribe el nuevo sueldo: ";
                    std::cin >> sueldoN;
                    actualSueldo(sueldoN);
                break;

            case 3: imprime();
                break;

            case 4: std::cout << " Escribe el supervisor al que reporta: ";
                    std::cin >> supervisorN;
                    cambiaReportA(supervisorN);
                break;

            default: std::cout << " Esta opcion no existe..." << std::endl << std::endl;


        }

    }while(opc!=4);

    return 0;

}
