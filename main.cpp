#include "./classes/headers/Fabrica.h"

using namespace std;

int main()
{
    Fabrica f;
    ISistema *s = f.getSistema();
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {

        s->imprimirTextoPrincipal();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        cin.ignore(10000, '\n');
        try
        {
            switch (opcionUsuario)
            {
            case 1: // Alta de usuario
            {
                std::cout << "Entra aca";
                s->menuCaso1();
                break;
            }
            case 2: // Iniciar sesión
            {
                s->menuCaso2();
                break;
            }
            case 3: // Cargar datos de prueba
            {
                s->menuCaso3();
                break;
            }
            case 4: // Salir
            {
                bandera = false;
                break;
            }
            default:
                std::cout.flush();
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
                break;
            }
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << endl;
        }
    }
    /*
    // Menu de prueba de Alta de usuario e Iniciar Sesion******

    sistema *s = new sistema();

    int tipoUsuario = 0; // 0-Desconectado 1-Usuario 2-Desarrollador
    jugador *jugadorActual;
    desarrollador *desarrolladorActual;

    int opcion = 1;

    while (opcion != 0)
    {
        cout << "" << endl;
        cout << "1- Alta usuario" << endl;
        cout << "2- Iniciar sesion" << endl;
        cout << "0- Salir" << endl;
        cin >> opcion;

        // CASO1
        // Debe verificar que el email no exista.
        // En caso de no existir, el usuario puede reintentar las veces que desee
        // Luego debe consultar si confirma la creacion del usuario

        switch (opcion)
        {
        case 1:
        {
            string email, contrasenia;
            cout << "Ingresar email: ";
            cin.ignore();
            getline(cin, email);
            cout << "Ingresar contrasenia: ";
            cin.ignore();
            getline(cin, contrasenia);

            int tipo;

            cout << "Indicar tipo (1-jugador 2-desarrollador)" << endl;
            cin >> tipo;

            if (tipo == 1)
            {
                // AGREGAR JUGADOR
                string nick;
                cout << "Ingresar nick: ";
                cin.ignore();
                getline(cin, nick);

                string descripcion;
                cout << "Ingresar descripcion: ";
                cin.ignore();
                getline(cin, descripcion);
                s->agregarJugador(email, contrasenia, nick, descripcion);
            }
            else
            {
                // AGREGAR DESARROLLADOR
                cout << "Ingresar empresa: ";
                string empresa;
                cin.ignore();
                getline(cin, empresa);
                s->agregarDesarrollador(email, contrasenia, empresa);
            }

            break;
        }

        case 2:
        {

            bool salir = 1;

            while (salir != 0)
            {
                string email, contrasenia;
                cout << "Ingresar email: ";
                cin.ignore();
                getline(cin, email);
                cout << "Ingresar contrasenia: ";
                cin.ignore();
                getline(cin, contrasenia);

                tipoUsuario = s->iniciarSesion(email, contrasenia);

                cout << "Resultado: " << tipoUsuario << endl;

                switch (tipoUsuario)
                {
                case 1:
                {
                    cout << "Sesion iniciada como Jugador" << endl;
                    jugadorActual = s->obtenerJugadorActual(email);
                    salir = 0;
                    break;
                }

                case 2:
                {
                    cout << "Sesion iniciada como Desarrollador" << endl;
                    desarrolladorActual = s->obtenerDesarrolladorActual(email);
                    salir = 0;
                    break;
                }

                case 0:
                {
                    cout << "Los datos de acceso son incorrectos" << endl;

                    int op;
                    cout << "Desea cancelar el inicio de sesion?" << endl;
                    cout << "1- Si" << endl;
                    cout << "2- No" << endl;
                    cin >> op;

                    if (op == 1)
                    {
                        salir = 0;
                    }
                    break;
                }
                }
            }
            break;
        }

        case 3:
        {
            cout << "Adios" << endl;
            break;
        }
        }

    }*/

    return 0;
}