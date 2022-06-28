#include "./classes/headers/Fabrica.h"

using namespace std;

int main()
{
    Fabrica f;
    ISistema *s = f.getSistema();

    // Sistema* sis=new Sistema();

    int opcionUsuario;
    int cargaDatosPrueba = 0;
    bool bandera = true;
    while (bandera == true)
    {
        s->imprimirTextoPrincipal();
        std::cin >> opcionUsuario;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\e[0m";
        try
        {
            switch (opcionUsuario)
            {
            case 1: // Alta de usuario
            {
                s->menuCaso1(/*sis*/);
                break;
            }
            case 2: // Iniciar sesion
            {
                s->menuCaso2(/*sis*/);
                break;
            }
            case 3: // Cargar datos de prueba
            {
                s->menuCaso3(cargaDatosPrueba /*, sis*/);
                std::cout << "\n\e[1;33mDatos de prueba cargados\n\e[0m";
                cargaDatosPrueba++;
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
    return 0;
}