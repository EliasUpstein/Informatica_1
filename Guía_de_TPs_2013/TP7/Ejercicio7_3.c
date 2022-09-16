/* Ídem anterior, pero recibiendo la hora en formato AM/PM, y retornando en
sistema de 24 hs. */

struct veinticuatro{
    int hora;
    int minutos;
    int segundos;
};

struct ampm{
    int hora;
    int minutos;
    int segundos;
    int ampm;       //0 = AM, 1 = PM
};

struct veinticuatro convertToAMPM(struct ampm hora)
{
    struct veinticuatro horaSalida;

    if (hora.ampm == 1)
        horaSalida.hora = hora.hora + 12;
    else
        horaSalida.hora = hora.hora;

    horaSalida.minutos = hora.minutos;
    horaSalida.segundos = hora.segundos;
    
    return horaSalida;
}