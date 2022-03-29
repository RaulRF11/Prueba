//
//  tipoalumno_plantilla1.cpp
//  
//
//  Created by Jaime Matas Bustos on 13/2/18.
//

#include <iostream>
using namespace std;
const int DIM_NOMBRE = 31, filas = 6, columnas = 4, DIM_NOTAS = 6;
/***************************************
** Definición del TIPO DE DATO Alumno **
****************************************/
struct Alumno{
    char nombre[DIM_NOMBRE]; //nombre del alumno como máximo de 30 de caracteres
    unsigned int edad;
    char nombres_asignaturas[filas][columnas];
    int notas[DIM_NOTAS]; //vector con las notas
};

/**********************************************************
 ** Definición de los Prototipos del Tipo de Dato Alumno **
 **********************************************************/
/**
 * @brief Devuelve por copia la cadena de caracteres de una variable estructurada de tipo Alumno.
 */
char getNombre(const Alumno &a, int i) {
	return a.nombre[i];
}
/**
 * @brief Calcula el tamaño que tiene el nombre de una variable estructurada de tipo Alumno. Para ello contará el número de caracteres totales desde el primero hasta el carácter centinela.
 */
int getTamanioNombre(const Alumno &a) {
	int contador = 0;
	for(int i = 0; a.nombre[i] != '\0'; i++) {
		contador++;
	}
	return contador;
}
/**
 * @brief Devuelve la edad una variable estructurada de tipo Alumno.
 */
unsigned int getEdad(const Alumno &a) {
	return a.edad;
}
char getNombresAsignaturas(const Alumno &a) {
	return a.nombres_asignaturas[filas][columnas];
}
int getNotas(const Alumno &a, int i) {
	return a.notas[i];
}
/**
 * @brief Asigna a la variable estructurada de tipo Alumno, el nombre que se pasa a través de la cadena de caracteres.
 * @pre El tamaño del vector nombre debe estar filtrado a 30 caracteres (+ el /0).
 */
void setNombre(Alumno &a, char nombre[]) {
	int i;
	for(i = 0; nombre[i] != '\0';i++) {   
		a.nombre[i] = nombre[i];
	}
	a.nombre[i] = '\0';
}
/**
 * @brief Asigna a la variable estructurada de tipo Alumno, la edad que se le pasa como parámetro.
 * @pre La edad debe de estar filtrada entre 0 y 120.
 */
void setEdad(Alumno &a, unsigned int edad) {
	a.edad = edad;
}
/**
 * @brief Establece en la matriz de nombres de asignaturas de una variable de tipo Alumno, los siguientes nombres: PRO, BD, ED, SI, FOL, LM.
 */
void setNombresAsignaturas(Alumno &a, char nombres_asignaturas[filas][columnas]) {
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++) {
			a.nombres_asignaturas[i][j] = nombres_asignaturas[i][j];
		}
	}
}
/**
 * @brief Asigna a la variable estructurada de tipo Alumno, un vector con sus calificaciones en cada asignatura. El orden de las asignaturas será PRO, BD, ED, SI, FOL, LM.
 * @pre El tamaño del vector notas debe estar filtrado e incluir 6 notas (ni más ni menos).
 */
void setNotas(Alumno &a, int notas[]) {
	for(int i = 0; i < DIM_NOTAS; i++) {
        	a.notas[i] = notas[i];
	}
}
/**
 * @brief Imprime por pantalla el contenido de una variable de tipo Alumno.
 */
void printAlumno(Alumno &a){
    	//OBSERVAR EL USO DE LOS MÓDULOS GET VS NO UTILIZARLOS...
    	//¿QUÉ PASARÍA SI CAMBIÁSEMOS EL NOMBRE DEL VECTOR DE NOTAS?
    	cout << "Nombre Alumno: ";
	for(int i = 0; i < getTamanioNombre(a); i++) {
		cout << getNombre(a,i);
	}
	cout << endl;
    	cout << "Edad: " << getEdad(a) << endl;
    	cout << "-----Calificaciones-----" << endl;
    	for(int i = 0; i < filas; i++) {
		cout << " - ";
		for(int j = 0; j < columnas; j++) {
			cout << a.nombres_asignaturas[i][j];
		}
		cout << ": " << getNotas(a,i) << endl;
	}
}

/**
 * @brief Intercambia el contenido de dos variables de tipo Alumno.
 */
void intercambiarAlumnos(Alumno &a, Alumno &b, Alumno &c){
	//Fijaros como la asignación de estructuras HACE LA COPIA DE VECTORES AUTOMÁTICAMENTE
    	c = b; //"QUÉ POTEEEEENSIAAAAAA QUE ME LO COPIA TÓ COMPAE VIEO SIN TENER QUE HASER UN FOR NI NÁ"
    	setNombre(c,a.nombre);
    	printAlumno(c);
    	c = a;
    	setNombre(c,b.nombre);
    	printAlumno(c);
}

/**
 * @brief Calcula y devuelve la media de calificaciones de una variable de tipo Alumno.
 */
double calcularMediaCalificacionesAlumno(Alumno &a){
	int media = 0;
	for(int i = 0; i < DIM_NOTAS; i++) {
		media += a.notas[i];
	}
	media /= 6;
	return media;
}

int main(){
    	Alumno Berrios, Jaime, alumnocopiado;
    	char nombreberrios[DIM_NOMBRE] = {'B','e','r','r','i','o','s','\0'};
    	int notasberrios[DIM_NOTAS] = {5,6,5,8,6,7};
    	char nombrejaime[DIM_NOMBRE] = {'J','a','i','m','e','\0'};
    	int notasjaime[DIM_NOTAS] = {5,6,5,7,7,6};
	char nombres_asignaturas[filas][columnas] = {{'P','R','O','\0'},{'B','D','\0'},{'L','M','\0'},{'S','I','\0'},{'E','D','\0'},{'F','O','L','\0'}};
    
    	//Preparo los datos del Alumno Berrios
    	setNombre(Berrios, nombreberrios);
	getTamanioNombre(Berrios);
    	setEdad(Berrios, 22);
    	setNombresAsignaturas(Berrios,nombres_asignaturas);
    	setNotas(Berrios,notasberrios);
    	printAlumno(Berrios);
    
    	//Preparo los datos del Alumno Jaime
    	setNombre(Jaime, nombrejaime);
	getTamanioNombre(Jaime);
    	setEdad(Jaime, 23);
    	setNombresAsignaturas(Jaime,nombres_asignaturas);
    	setNotas(Jaime, notasjaime);
    	printAlumno(Jaime);
    	
    	/*Aquí habría que incluir el código para probar los módulos Intercambiar Alumnos y Calcular Calificaciones Medias*/

    	// 1) Probamos Intercambiar Alumnos y mostramos por pantalla los alumnos intercambiados.
    	intercambiarAlumnos(Jaime,Berrios,alumnocopiado);
    	// 2) Probamos Calcular Calificación Media de los Alumnos y las mostramos por pantalla.
	cout << "La media de Berrios es: " << calcularMediaCalificacionesAlumno(Berrios) << endl;
	cout << "Y la media de Jaime es: " << calcularMediaCalificacionesAlumno(Jaime) << endl;

}






