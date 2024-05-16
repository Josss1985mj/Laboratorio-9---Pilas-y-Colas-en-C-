#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <limits> // Para limpiar el buffer de entrada
#include <iomanip> // Para setw

using namespace std;

// Definición de la clase Tarea
class Tarea {
private:
    string descripcion;

public:
    Tarea(const string& desc) : descripcion(desc) {}
    void mostrar() const {
        cout << " - " << descripcion << endl;
    }
};

// Prototipos de funciones para la interfaz del usuario
void agregarTarea(stack<Tarea>&, queue<Tarea>&);
void completarUltimaTarea(stack<Tarea>&);
void atenderTareaMasAntigua(queue<Tarea>&);
void mostrarTodasLasTareas(const stack<Tarea>&, const queue<Tarea>&);

int main() {
    stack<Tarea> pilaTareas;
    queue<Tarea> colaTareas;
    int opcion = 0;

    do {
        system("clear"); // Limpiar la pantalla antes de mostrar el menú
        cout << "\n\t==============================================" << endl;
        cout << "\t             MENU DE GESTION DE TAREAS         " << endl;
        cout << "\t==============================================" << endl;
        cout << setw(30) << "1. Agregar tarea" << endl;
        cout << setw(30) << "2. Completar ultima tarea" << endl;
        cout << setw(30) << "3. Atender tarea más antigua" << endl;
        cout << setw(30) << "4. Mostrar todas las tareas" << endl;
        cout << setw(30) << "5. Salir" << endl;
        cout << "\t==============================================" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        // Limpiar el buffer de entrada en caso de que se ingrese un valor no válido
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                agregarTarea(pilaTareas, colaTareas);
                break;
            case 2:
                completarUltimaTarea(pilaTareas);
                break;
            case 3:
                atenderTareaMasAntigua(colaTareas);
                break;
            case 4:
                mostrarTodasLasTareas(pilaTareas, colaTareas);
                break;
            case 5:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpción inválida. Por favor, intente nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}

// Implementación de las funciones de la interfaz del usuario
void agregarTarea(stack<Tarea>& pila, queue<Tarea>& cola) {
    string descripcion;
    cout << "\nIngrese la descripción de la tarea: ";
    getline(cin, descripcion);
    Tarea nuevaTarea(descripcion);
    pila.push(nuevaTarea);
    cola.push(nuevaTarea);
    cout << "\nTarea agregada exitosamente.\n";
}

void completarUltimaTarea(stack<Tarea>& pila) {
    if (!pila.empty()) {
        pila.pop();
        cout << "\nLa última tarea ha sido completada.\n";
    } else {
        cout << "\nNo hay tareas pendientes para completar.\n";
    }
}

void atenderTareaMasAntigua(queue<Tarea>& cola) {
    if (!cola.empty()) {
        cola.pop();
        cout << "\nLa tarea más antigua ha sido atendida.\n";
    } else {
        cout << "\nNo hay tareas pendientes para atender.\n";
    }
}

void mostrarTodasLasTareas(const stack<Tarea>& pila, const queue<Tarea>& cola) {
    if (pila.empty() && cola.empty()) {
        cout << "\nNo hay tareas pendientes.\n";
        return;
    }

    cout << "\nTareas pendientes en la pila (última tarea primero):\n";
    stack<Tarea> pilaTemp = pila;
    while (!pilaTemp.empty()) {
        pilaTemp.top().mostrar();
        pilaTemp.pop();
    }

    cout << "\nTareas pendientes en la cola (primera tarea primero):\n";
    queue<Tarea> colaTemp = cola;
    while (!colaTemp.empty()) {
        colaTemp.front().mostrar();
        colaTemp.pop();
    }
}
