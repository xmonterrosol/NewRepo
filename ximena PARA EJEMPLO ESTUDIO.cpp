 #include <iostream>
#include <string>

using namespace std;

// Clase padre: Empleado
class Empleado {
protected:
    string nombre;
    int edad;
    double salario;

public:
    // Constructor
    Empleado(string nombre, int edad, double salario)
        : nombre(nombre), edad(edad), salario(salario) {
    }

    // M�todo para mostrar datos
    virtual void mostrarDatos() {
        cout << "Nombre: " << nombre << "\nEdad: " << edad << "\nSalario: $" << salario << endl;
    }
};

// Clase hija: Gerente
class Gerente : public Empleado {
public:
    // Constructor
    Gerente(string nombre, int edad, double salario)
        : Empleado(nombre, edad, salario) {
    }

    // M�todo para mostrar datos
    void mostrarDatos() override {
        Empleado::mostrarDatos();
    }
};

// Clase hija: Tecnico
class Tecnico : public Empleado {
    string especialidad; // Atributo nuevo

public:
    // Constructor
    Tecnico(string nombre, int edad, double salario, string especialidad)
        : Empleado(nombre, edad, salario), especialidad(especialidad) {
    }

    // M�todo para mostrar datos
    void mostrarDatos() override {
        Empleado::mostrarDatos();
        cout << "Especialidad: " << especialidad << endl;
    }
};

void mostrarMenu() {
    cout << "Men� principal:\n1. Registrar Gerente\n2. Registrar T�cnico\n3. Mostrar Datos del Empleado\n4. Salir\n";
}

int main() {
    int opcion, edad;
    double salario;
    string nombre, especialidad;
    Empleado* empleado = nullptr;

    do {
        mostrarMenu();
        cout << "Ingrese su opci�n: ";
        cin >> opcion;

        switch (opcion) {   
        case 1:
            cout << "Ingrese nombre: ";
            cin >> nombre;
            cout << "Ingrese edad: ";
            cin >> edad;
            cout << "Ingrese salario: ";
            cin >> salario;
            empleado = new Gerente(nombre, edad, salario);
            cout << "Gerente registrado exitosamente." << endl;
            break;

        case 2:
            cout << "Ingrese nombre: ";
            cin >> nombre;
            cout << "Ingrese edad: ";
            cin >> edad;
            cout << "Ingrese salario: ";
            cin >> salario;
            cout << "Ingrese especialidad: ";
            cin >> especialidad;
            empleado = new Tecnico(nombre, edad, salario, especialidad);
            cout << "T�cnico registrado exitosamente." << endl;
            break;

        case 3:
            if (empleado) empleado->mostrarDatos();
            else cout << "No hay empleado registrado." << endl;
            break;

        case 4:
            cout << "Saliendo