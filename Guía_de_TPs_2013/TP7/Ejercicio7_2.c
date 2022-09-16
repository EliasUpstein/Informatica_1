/* Escriba una función que reciba la hora con formato de 24 hs. y la devuelva en el
formato AM/PM. */

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

struct ampm convertToAMPM(struct veinticuatro hora)
{
    struct ampm horaSalida;

    if (hora.hora > 12)
    {
        horaSalida.hora = hora.hora - 12;
        horaSalida.ampm = 1;
    }
    else
    {
        horaSalida.hora = hora.hora;
        horaSalida.ampm = 0;
    }

    horaSalida.minutos = hora.minutos;
    horaSalida.segundos = hora.segundos;
    
    return horaSalida;
}