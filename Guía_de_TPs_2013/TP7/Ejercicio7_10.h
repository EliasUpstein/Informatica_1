#define N 30

struct Automovil
{
    int numeroDominio;
    int numeroMotor;
    char marca[N];
    char modelo[N];
    int tamanoMotor;
    char color[N];
};

struct Automovil crearAuto();
void cambiarColor(struct Automovil *estructura, char *color_nuevo);
void mostrarAuto(struct Automovil estructura);
void clonarAuto(struct Automovil original, struct Automovil *clon);