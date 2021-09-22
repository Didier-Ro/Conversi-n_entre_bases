#include <iostream>
#include <map> //map es un contenedor para lista de parejas de valores únicos asociados como clave/valor

using namespace std;

int main(int argc, char const* argv[])
{
	map<char, int> map; //Definiendo que tipos de datos estaran en el map, el primero es un char y el segundo es entero
	string number;
	int base1, base2; //variables para definir la base que tiene el numero y a la que quieres cambiar
	int index = 1, integerresult = 0;//varibles que ayudan a tener el número en la base original
	string result = ""; //resultado final
	string bases = "0123456789ABCDEF"; //Arreglo para construir los números en las distintas bases

	map['0'] = 0; //Aqui se crean los contenedores para tener la pareja de valores, char y entero
	map['1'] = 1;  //Ayuda a que cuando el usuario escriba una letra, ejem F en base 16 y lo quiere en base 10
	map['2'] = 2;  //se pueda pasar a un número y poder hacer los calculos que estan más adelante
	map['3'] = 3;
	map['4'] = 4;
	map['5'] = 5;
	map['6'] = 6;
	map['7'] = 7;
	map['8'] = 8;
	map['9'] = 9;
	map['A'] = 10;
	map['B'] = 11;
	map['C'] = 12;
	map['D'] = 13;
	map['E'] = 14;
	map['F'] = 15;

	cout << "Escriba: [numero] [base 1] [base 2]" << endl; //Se pide el número y la base en la que esta y que la base lo quieres convertir
	cin >> number >> base1 >> base2; //Se almacenan las varibles

	for (int i = number.size() - 1; i >= 0; i--) /*el number.size - 1 nos ayudara a saber cuantas veces se hara el ciclo
		                                          si el número es de un dígito se ejecutara 1 vez y si es de 2, 2 veces*/
	{ 
		integerresult += map[number[i]] * index;//integerresult es igual al valor de map * index, que es 1 en este momento
		index *= base1; // el valor de index que tenga en ese momento se le multiplica por la base 1
	}
	
	while (integerresult > 0) { //mientras integerresult sea mayor a cero se ejecutara
		result = bases[integerresult % base2] + result;//el resultado es igual a la posición del arreglo que se obtiene del residuo-
		integerresult /= base2;//división para ir moviendo el valor de integerresult    //-de integerresult y base 2
		
	}
	cout<< result; //se muestra el resultado
	return 0;
}

