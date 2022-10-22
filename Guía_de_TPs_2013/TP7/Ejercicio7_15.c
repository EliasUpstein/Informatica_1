/* Escribir un programa que permita manejar información sobre Estudiantes. Se
necesita conocer el padrón (identificador único para cada Estudiante), cinco
calificaciones en punto flotante, fecha de ingreso a la Facultad, Carrera en la que
están inscriptos. Las funciones para manipular un Estudiante son:
a) crearEstudiante: genera un Estudiante con un número de padrón que recibe.
b) agregarCalificacion: agrega una nota de las cinco notas que puede tener un
estudiante.
c) calcularPromedio: devuelve el promedio de las notas que pertenecen a un
Estudiante.*/

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct estudiante
{
    int padron;
    float calificaciones[5];
    struct Fecha ingreso;
    char carrera[30];
};

struct estudiante crearEstudiante(int padron)
{
    struct estudiante nuevo;

    nuevo.padron = padron;

    //Inicializa todas las calificaciones en 0
    for (int i = 0; i < 5; i++)
    {
        nuevo.calificaciones[i] = 0;
    }
    
    return nuevo;
}

//Guarda en la primera posición igual a 0 (no cargada)
void agregarCalificacion(struct estudiante *alumno, float nota)
{
    for (int i = 0; i < 5; i++)
    {
        if (alumno->calificaciones[i] == 0)
        {
            alumno->calificaciones[i] = nota;
            return;
        }
    }
}

float calcularPromedio(struct estudiante *alumno)
{
    int aux = 0;
    float promedio = 0;

    for (int i = 0; i < 5; i++)
    {
        if (alumno->calificaciones[i] != 0)
        {
            promedio += alumno->calificaciones[i];
            aux++;
        }
    }

    return promedio/aux;
}