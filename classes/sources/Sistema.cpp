#include "../headers/Sistema.h"
Sistema::Sistema()
{
    this->videojuegos = new OrderedDictionary;
    this->categorias = new OrderedDictionary;
    this->jugadores = new OrderedDictionary;
    this->desarrolladores = new OrderedDictionary;
    this->fechaDelSistema = new DtFecha(03, 07, 2022, 00, 30, 10);
}

// Alta de usuario
void Sistema::menuCaso1(Sistema* s)
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        string email, contrasenia;
        std::cout << "Ingresar email: ";
        std::cin.ignore();
        getline(std::cin, email);
        std::cout << "Ingresar contrasenia: ";
        std::cin.ignore();
        getline(std::cin, contrasenia);

        int tipo;

        std::cout << "Indicar tipo (1-jugador 2-desarrollador)" << std::endl;
        std::cin >> tipo;

        if (tipo == 1)
        {
            // AGREGAR JUGADOR
            string nick;
            std::cout << "Ingresar nick: ";
            std::cin.ignore();
            getline(std::cin, nick);

            string descripcion;
            std::cout << "Ingresar descripcion: ";
            std::cin.ignore();
            getline(std::cin, descripcion);
            s->agregarJugador(email, contrasenia, nick, descripcion);
        }
        else
        {
            // AGREGAR DESARROLLADOR
            std::cout << "Ingresar empresa: ";
            string empresa;
            std::cin.ignore();
            getline(std::cin, empresa);
            s->agregarDesarrollador(email, contrasenia, empresa);
        }

        break;
    }
}

void Sistema::agregarJugador(std::string email, std::string contrasenia, std::string nick, std::string desc)
{
    StringKey *key = new StringKey(email);
    Jugador *jug = new Jugador(email, contrasenia, nick, desc);
    jugadores->add(key, jug);
}

void Sistema::agregarDesarrollador(std::string email, std::string contrasenia, std::string empresa)
{
    StringKey *key = new StringKey(email);
    Desarrollador *des = new Desarrollador(email, contrasenia, empresa);
    desarrolladores->add(key, des);
}

// Iniciar sesión
void Sistema::menuCaso2(Sistema* s)
{
    std::string email, contrasenia;
    bool bandera = true;
    int opcionUsuario;
    try
    {
        while (bandera == true)
        {

            std::cout << "\nIngrese email: ";
            std::cin >> email;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\nIngrese contraseña: ";
            std::cin >> contrasenia;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            opcionUsuario = iniciarSesion(email, contrasenia);
            switch (opcionUsuario)
            {
            case 0:
            {
                int op;
                std::cout << "Los datos de acceso son incorrectos" << std::endl;
                std::cout << "Desea cancelar el inicio de sesion?" << std::endl;
                std::cout << "1- Si" << std::endl;
                std::cout << "2- No" << std::endl;
                std::cin >> op;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                if (op == 1)
                {
                    bandera = false;
                }
                break;
            }
            case 1:
            {
                std::cout << "Sesion iniciada como Jugador" << std::endl;
                usuarioActual = s->obtenerJugadorActual(email);
                imprimirMenuJugador();
                break;
            }
            case 2:
            {
                std::cout << "Sesion iniciada como Desarrollador" << std::endl;
                usuarioActual = s->obtenerDesarrolladorActual(email);
                desarrolladorActual = s->obtenerDesarrolladorActual(email);
                imprimirMenuDesarrollador();
                break;
            }

            default:
                std::cout.flush();
                throw std::invalid_argument("\n\e[0;31mLa opcion ingresada no es correcta.\n\e[0m");
            }
        }
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int Sistema::iniciarSesion(string email, string contrasenia)
{
    StringKey *key = new StringKey(email);
    // int validador=0;

    // Verifica si ese email pertenece a un jugador o a un desarrollador
    bool validarJugador = jugadores->member(key);
    bool validarDesarrollador = desarrolladores->member(key);

    if (validarJugador == true)
    {
        Jugador *auxJugador = dynamic_cast<Jugador *>(jugadores->find(key));
        // Es usuario el que tiene contrasenia. Jugador debe tener constructor de todo entonces
        if (contrasenia == auxJugador->getContrasenia())
        {
            return 1;
        }
    }

    if (validarDesarrollador == true)
    {
        Desarrollador *auxDesarrollador = dynamic_cast<Desarrollador *>(desarrolladores->find(key));
        if (contrasenia == auxDesarrollador->getContrasenia())
        {
            return 2;
        }
    }

    return 0;
}

Jugador *Sistema::obtenerJugadorActual(string email)
{
    StringKey *key = new StringKey(email);
    Jugador *auxJugador = dynamic_cast<Jugador *>(jugadores->find(key));
    return auxJugador;
}

Desarrollador *Sistema::obtenerDesarrolladorActual(string email)
{
    StringKey *key = new StringKey(email);
    Desarrollador *auxDesarrollador = dynamic_cast<Desarrollador *>(desarrolladores->find(key));
    return auxDesarrollador;
}

// Cargar datos de prueba
void Sistema::menuCaso3(int i, Sistema* s)
{
    if (i == 0)
    {
        Desarrollador *d1 = new Desarrollador("ironhide@mail.com", "123", "Ironhide Game Studio");
        Desarrollador *d2 = new Desarrollador("epic@mail.com", "123", "Epic Games");
        Desarrollador *d3 = new Desarrollador("mojang@mail.com", "123", "Mojang Studios");
        Desarrollador *d4 = new Desarrollador("ea@mail.com", "123", "EA Sports");
        Jugador *j1 = new Jugador("gamer@mail.com", "123", "gamer", "descripcionJ1");
        Jugador *j2 = new Jugador("ari@mail.com", "123", "ari", "descripcionJ2");
        Jugador *j3 = new Jugador("ibai@mail.com", "123", "ibai", "descripcionJ3");
        Jugador *j4 = new Jugador("camila@mail.com", "123", "camila", "descripcionJ4");
        Categoria *c1 = new Categoria("PC", "Descripcion Categoria PC", "Plataforma");
        Categoria *c2 = new Categoria("PS4", "Descripcion Categoria PS4", "Plataforma");
        Categoria *c3 = new Categoria("Xbox One", "Descripcion Categoria Xbox", "Plataforma");
        Categoria *c4 = new Categoria("Deporte", "Descripcion Categoria Deporte", "Género");
        Categoria *c5 = new Categoria("Supervivencia", "Descripcion Categoria Supervivencia", "Género");
        Categoria *c6 = new Categoria("Estrategia", "Descripcion Categoria Estrategia", "Género");
        Categoria *c7 = new Categoria("Teen", "Su contenido está dirigido a jóvenes de 13 años en adelante.", "Otro");
        Categoria *c8 = new Categoria("E", "Su contenido está dirigido para todo público", "Otro");
        Categoria *c9 = new Categoria("Acción", "Descripcion Categoria Acción", "Género");
        Categoria *c10 = new Categoria("Aventura", "Descripcion Categoria Aventura", "Género");
        Categoria *c11 = new Categoria("Switch", "Descripcion Categoria Switch", "Plataforma");
        Categoria *c12 = new Categoria("Xbox", "Descripcion Categoria Xbox", "Plataforma");
        Categoria *c13 = new Categoria("PS5", "Descripcion Categoria PS5", "Plataforma");

        Estadistica *est1 = new Estadistica(4, 1); // TODO Hacer la cuenta de la duracionPartidaPorJugador
        Estadistica *est2 = new Estadistica(5, 1); // Revisar Los datos de prueba en "Puntajes a videojuegos"
        Estadistica *est3 = new Estadistica(5, 1);
        Estadistica *est4 = new Estadistica(3, 1);

        Videojuego *vj1 = new Videojuego("KingdomRush", "Descripcion KingdomRush", 1, 2, 7, 14, est1);
        Videojuego *vj2 = new Videojuego("Fortnite", "Descripcion Fortnite", 3, 8, 30, 60, est2);
        Videojuego *vj3 = new Videojuego("Minecraft", "Descripcion Minecraft", 2, 5, 20, 40, est3);
        Videojuego *vj4 = new Videojuego("FIFA 21", "Descripcion FIFA 21", 3, 8, 28, 50, est4);

        DtFecha *fecha1 = new DtFecha(01, 06, 2021, 0, 00, 9);
        Suscripcion *sus1 = new Suscripcion(fecha1, MetodoPago::Paypal, Valor::TresMeses, false, vj1 ,j1);
        fecha1 = new DtFecha(02, 06, 2021, 0, 00, 11);
        Suscripcion *sus2 = new Suscripcion(fecha1, MetodoPago::Tarjeta, Valor::TresMeses, false, vj2, j2);
        fecha1 = new DtFecha(04, 06, 2021, 0, 00, 9);
        Suscripcion *sus3 = new Suscripcion(fecha1, MetodoPago::Paypal, Valor::UnMes, false, vj2, j3);
        fecha1 = new DtFecha(11, 06, 2021, 0, 00, 9);
        Suscripcion *sus4 = new Suscripcion(fecha1, MetodoPago::Tarjeta, Valor::Anio, false, vj3, j4);
        fecha1 = new DtFecha(03, 06, 2021, 0, 00, 7);
        Suscripcion *sus5 = new Suscripcion(fecha1, MetodoPago::Tarjeta, Valor::UnMes, false, vj2, j1);
        fecha1 = new DtFecha(21, 12, 2020, 0, 00, 15);
        Suscripcion *sus6 = new Suscripcion(fecha1, MetodoPago::Tarjeta, Valor::Vitalicia, false,vj2, j2);

        vj1->setCategoria(c1);
        vj1->setCategoria(c2);
        vj1->setCategoria(c6);
        vj1->setCategoria(c8);
        vj2->setCategoria(c1);
        vj2->setCategoria(c2);
        vj2->setCategoria(c3);
        vj2->setCategoria(c5);
        vj2->setCategoria(c7);
        vj3->setCategoria(c1);
        vj3->setCategoria(c5);
        vj3->setCategoria(c8);
        vj4->setCategoria(c1);
        vj4->setCategoria(c2);
        vj4->setCategoria(c3);
        vj4->setCategoria(c4);
        vj4->setCategoria(c8);
        vj1->setSuscripcion(sus1);
        vj2->setSuscripcion(sus2);
        vj2->setSuscripcion(sus3);
        vj3->setSuscripcion(sus4);
        vj2->setSuscripcion(sus5);
        vj3->setSuscripcion(sus6);
    }
}

// Publicar videojuego
void Sistema::publicarVideojuego(Sistema *s)
{
    std::string nom, desc;
    float cMensual, cTristral, cAnual, cVitalicio;

    std::cout << "\nIngrese nombre: ";
    std::cin >> nom;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "\nIngrese descripcion: ";
    std::cin >> desc;
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    std::cout << "\nIngrese costo menusal: ";
    std::cin >> cMensual;
    std::cout << "\nIngrese costo trimestral: ";
    std::cin >> cTristral;
    std::cout << "\nIngrese costo anual: ";
    std::cin >> cAnual;
    std::cout << "\nIngrese costo vitalicio: ";
    std::cin >> cVitalicio;

    bool deseaAgregar = true;
    int op2 = 1;
    List *aux_categorias = new List();

    while (deseaAgregar == true)
    {

        s->mostrarCategorias(); // ***Sin implementar***

        std::string cat;
        std::cout << "\nSeleccione una categoria: ";
        std::cin >> cat;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        Categoria *aux = s->obtenerCategoria(cat);

        if (aux_categorias->member(aux))
        {
            // La categoria ya habia sido agregada a la lista auxiliar anteriormente
            std::cout << "\nEsa categoria ya fue seleccionada anteriormente";
        }
        else
        {
            aux_categorias->add(aux);
        }

        std::cout << "\nDesea asignar otra categoria?";
        std::cout << "1- Si";
        std::cout << "2- No";
        std::cin >> op2;

        if (op2 == 1)
        {
            deseaAgregar = false;
        }
    }

    // MOSTRAR LOS DATOS:
    std::cout << "\nDatos del videojuego:\n";
    std::cout << "\nNombre: " << nom;
    std::cout << "\nDescripcion: " << desc;
    std::cout << "\nCosto mensual: " << cMensual;
    std::cout << "\nCosto trimestral: " << cTristral;
    std::cout << "\nCosto anual: " << cAnual;
    std::cout << "\nCosto vitalicio: " << cVitalicio;
    std::cout << "\nCategorias: ";
    s->mostrarListaCategorias(aux_categorias);

    int op3;
    std::cout << "\nDesea publicar el videojuego?";
    std::cout << "1- Si";
    std::cout << "2- No";
    std::cin >> op3;

    if (op3==1){
        //Confirma publicar el videojuego
        Videojuego* videojuegoAux = new Videojuego(nom,desc,cMensual,cTristral,cAnual,cVitalicio,aux_categorias);
    }

}

void Sistema::mostrarCategorias(){

}

Categoria *Sistema::obtenerCategoria(std::string categoria)
{
    StringKey *key = new StringKey(categoria);
    Categoria *aux = dynamic_cast<Categoria *>(categorias->find(key));
    return aux;
}

void Sistema::mostrarListaCategorias(List* lista){
    IIterator* it= lista->getIterator();

    while(it->hasCurrent()){
        Categoria* aux= dynamic_cast<Categoria*>(it->getCurrent());

        std::cout << aux->Getnombre();

        it->next();
    }

}

Videojuego *Sistema::obtenerVideojuegodesarrollador(std::string videojuego)
{
    StringKey *key = new StringKey(videojuego);
    Videojuego *aux = dynamic_cast<Videojuego *>(videojuegos->find(key));
    return aux;
}

void Sistema::mostrarListaVideojuegos(List *lista){
    
    IIterator* it= lista->getIterator();

    while(it->hasCurrent()){
        Videojuego* aux= dynamic_cast<Videojuego*>(it->getCurrent());
        std::cout << aux->Getnombre();
        it->next();
    }

}



//Suscribirse a videojuego

void Sistema::suscribirseVideojuego(){
    mostrarVideojuegos();

    std::string nombreVideojuego;
    std::cout << "\nIndicar el nombre del videojuego: ";
    std::cin >> nombreVideojuego;
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    StringKey* key = new StringKey(nombreVideojuego);

    if (videojuegos->member(key)){
        
        if(jugadorActual->verificarSuscripcion(nombreVideojuego)){
            //Ya tiene una suscripcion activa para ese videojuego.

            if(jugadorActual->verificarEsVitalicia(nombreVideojuego)){
                //La suscripcion es vitalicia
                std::cout << "\nLas suscripciones vitalicias no se pueden cancelar";
            } else {
                //La suscripcion no es vitalicia
                int op2;
                std::cout << "\nDesea cancelar la suscripcion para el videojuego?";
                std::cout << "1- Si";
                std::cout << "2- No";
                std::cin >> op2;

                jugadorActual->cancelarSuscripcion(GetUnVideojuego(key));

                //Avisar a videojuego:
                Videojuego* auxVideojuego1 = dynamic_cast<Videojuego*>(videojuegos->find(key));
                auxVideojuego1->cancelarSuscripcion(jugadorActual->Getnick());
            }

        } else{
            //No tiene una suscripcion para ese videojuego.

            int op3;
            std::cout << "\nSeleccionar metodo de pago:";
            std::cout << "1- Tarjeta";
            std::cout << "2- Paypal";
            std::cin >> op3;
            MetodoPago metodo;
            if (op3==1){
                metodo=Tarjeta;
            } else {
                metodo=Paypal;
            }

            int op4;
            std::cout << "\nSeleccionar renovacion:";
            std::cout << "1- Vitalicia";
            std::cout << "2- Mensual";
            std::cout << "3- Trimestral";
            std::cout << "4- Anual";
            std::cin >> op4;
            Valor valor;

            switch (op4){
            case 1: valor=Vitalicia; 
            break;

            case 2: valor=UnMes;
            break;

            case 3: valor=TresMeses;
            break;

            case 4: valor=Anio;
            break; 
            }      

            int op5;
            std::cout << "\nDesea confirmar la suscripcion?";
            std::cout << "1- Si";
            std::cout << "2- No";
            std::cin >> op5;

            if (op5==1){
                Suscripcion* susAux = new Suscripcion(fechaDelSistema, metodo, valor, false, dynamic_cast<Videojuego*>(videojuegos->find(key)),jugadorActual);
                jugadorActual->setSuscripcion(susAux);

                //Avisar a videojuego:
                Videojuego* auxVideojuego2 = dynamic_cast<Videojuego*>(videojuegos->find(key));
                auxVideojuego2->setSuscripcion(susAux);
            }

        }

    } else {
        std::cout << "\nEl videojuego no existe";
    }

}

void Sistema::mostrarVideojuegos(){
    IIterator* it= videojuegos->getIterator();

    while(it->hasCurrent()){
        Videojuego* aux= dynamic_cast<Videojuego*>(it->getCurrent());
        std::cout << aux->Getnombre();
        it->next();
    }
}

Videojuego* Sistema::GetUnVideojuego(StringKey* nombreVideojuego){
    Videojuego* aux =dynamic_cast<Videojuego*>(videojuegos->find(nombreVideojuego));
    return aux;
}






// Eliminar Videojuego
void Sistema::EliminarVideojuego(Desarrollador *d, Sistema *s)
{
    string nom;
    d->mostrarVideojuegosDesarrollador();
    std::cout << "\nIngrese nombre del videojuego a eliminar; ";
    std::cin >> nom;
    Videojuego *aux = s->obtenerVideojuegodesarrollador(nom);

    int op3;
    std::cout << "\nDesea eliminar el videojuego?";
    std::cout << "1- Si";
    std::cout << "2- No";
    std::cin >> op3;

    if (op3==1){
        //Confirma eliminar el videojuego
        d->EliminarEsteJuego(aux);
    }
}

void Sistema::imprimirMenuDesarrollador()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        Sistema::imprimirTextoDelDesarrollador();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        try
        {
            switch (opcionUsuario)
            {
            case 1: // Publicar Videojuego
            {
                publicarVideojuego(this);
                break;
            }
            case 2: // Eliminar Videojuego
            {
                EliminarVideojuego(desarrolladorActual, this);
                break;
            }

            case 3: // CASO SALIDA DE SISTEMA
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
            std::cerr << e.what() << std::endl;
        }
    }
}

void Sistema::imprimirMenuJugador()
{
    int opcionUsuario;
    bool bandera = true;
    while (bandera == true)
    {
        Sistema::imprimirTextoDelJugador();
        std::cin >> opcionUsuario;
        std::cout << "\e[0m";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        try
        {
            switch (opcionUsuario)
            {
            case 1: // Suscribirse a videojuego
            {
                break;
            }
            case 2: // Iniciar partida
            {
                break;
            }
            case 3: // Finalizar partida
            {
                break;
            }
            case 4: // Ver información de videojuego
            {
                break;
            }

            case 5: // CASO SALIDA DE SISTEMA
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
            std::cerr << e.what() << std::endl;
        }
    }
}

void Sistema::imprimirTextoPrincipal()
{
    std::cout << "\e[0;92mBienvenido - Elija una opción\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m Alta de usuario.\n";
    std::cout << "\e[0;92m2)\e[0m Iniciar sesión.\n";
    std::cout << "\e[0;92m3)\e[0m Cargar datos de prueba.\n";
    std::cout << "Pulse \e[0;92m4\e[0m para salir.\n\nOpcion: \e[0;92m";
}

void Sistema::imprimirTextoDelDesarrollador()
{
    std::cout << "\e[0;92mMenú de Desarrollador - Elija una opción\e[0m:";
    std::cout << "\e[0;92m2)\e[0m 1: Publicar videojuego.\n";
    std::cout << "\e[0;92m3)\e[0m 2: Eliminar videojuego.\n";
    std::cout << "Pulse \e[0;92m8\e[0m 3: Para salir.\n\nOpcion: \e[0;92m";
}

void Sistema::imprimirTextoDelJugador()
{
    std::cout << "\e[0;92mMenú de Jugador - Elija una opción\e[0m:";
    std::cout << "\n\e[0;92m1)\e[0m 1: Suscribirse a videojuego.\n";
    std::cout << "\e[0;92m3)\e[0m 2: Iniciar partida.\n";
    std::cout << "\e[0;92m5)\e[0m 3: Finalizar partida.\n";
    std::cout << "\e[0;92m6)\e[0m 4: Ver información de videojuego.\n";
    std::cout << "Pulse \e[0;92m8\e[0m 5: para salir.\n\nOpcion: \e[0;92m";
}

Sistema::~Sistema() {}
