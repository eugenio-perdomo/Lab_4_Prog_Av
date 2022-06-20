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
    return 0;
}