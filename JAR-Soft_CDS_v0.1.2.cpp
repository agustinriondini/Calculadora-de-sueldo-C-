#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(){

	//UI
	string shortDLine = "====================", longDLine = "========================================", noLine = " ", shortSLine = "--------------------", boolSMS = "1 PARA SI | 0 PARA NO";
	//version
	string versionCompilacion = "v1.0.2_update_19/02/2024";

	//Program_vars
	string nombreEmpleado, periodo;
	int antiguedad = 0, enDeuda = 0, fullTime = 0, presentismo = 0, partTime = 0, dni = 0, horasTrabajadas = 0, valorHora = 0, horasExtra  = 0, sueldoBruto = 0, auxAntiguedad = 0, sueldoNeto = 0, year = 1111, sueldoBase = 0, importeHsExtra = 0, valorHoraExtra = 0;
	float aportes = 0, impuestos = 0, dtos = 0;
	bool rta, tipoContrato, justificar, validarPresentismo;
	
	//comienzo interfaz cabecera
    string contenido = "----------------JARSOFT CALCULADORA DE SUELDOS----------------";
    int contentLength = contenido.length();
    int lineLength = contentLength + 4;
    cout << '+' << string(lineLength - 2, '=') << '+' << endl;
    cout << "|" << setw(lineLength - 2) << left << contenido << "|" << endl;
    cout << "|" << setw(lineLength - 2) << left << "Version: " + versionCompilacion << "|" << endl;
    cout << '+' << string(lineLength - 2, '=') << '+' << endl;
	//fin interfaz cabecera
	
	//interaccion con el usuario
	cout << "COMPLETE LOS CAMPOS SOLICITADOS PARA GENERAR EL RECIBO..." << endl << endl;
	do{
		cout << "INGRESE EL NOMBRE DEL MES A LIQUIDAR" << noLine; cin >> periodo;
	}while(periodo.empty());
	do{
		cout << "INGRESE EL ANHO: YYYY:" << noLine; cin >> year;
	}while(cin.fail() || year < 2020 && year > 2024);
	
	cout << "DEFINA REMUNERACION POR HORA:" << noLine << "$"; cin >> valorHora;
	
	cout << "INGRESE EL APELLIDO DEL EMPLEADO:" << noLine; cin >> nombreEmpleado;
	
	cout << "INGRESE EL DNI DEL EMPLEADO:" << noLine << "DNI N° "; cin >> dni;

	cout << "ES EL EMPLEADO FULL TIME (160HS MENSUALES)?" << noLine << boolSMS << noLine; cin >> tipoContrato;
	
	cout << "CANTIDAD DE HORAS TOTALES REALIZADAS EN EL PERIODO: (HORAS COMPLETAS)" << noLine << "#"; cin >> horasTrabajadas;
	
	if (tipoContrato == true && horasTrabajadas >= 160){
		cout << "Confirma plus presentismo?:" << noLine << boolSMS << noLine; cin >> validarPresentismo;
	}else if (tipoContrato == false && horasTrabajadas >= 80){
		cout << "Confirma plus presentismo?:" << boolSMS << noLine; cin >> validarPresentismo;
	}

	cout << "ANTIGUEDAD DEL EMPLEADO (ANHOS COMPLETOS CUMPLIDOS): " << noLine << "#"; cin >> antiguedad;
	
	//determinar contrato
	if (tipoContrato == true){
		fullTime = 160;
		sueldoBase = fullTime * valorHora;
	}else{
		partTime = 80;
		sueldoBase = partTime * valorHora;
	}
	valorHoraExtra = valorHora * 2;
	//liquidacion hs extra con el limite maximo permitido por contrato, un 10%
	if (tipoContrato == true && horasTrabajadas <= 160){
		horasExtra = 0;
		enDeuda = fullTime - horasTrabajadas;
		cout << "El empleado " << nombreEmpleado << " debe compensar " << enDeuda << "Hs." << endl << "Justificar?" << noLine << boolSMS << noLine; cin >> justificar;
		if (justificar == true){
			horasTrabajadas = 160;//compensa por justificar
		}else{
			dtos = enDeuda * valorHora;
		}
	}else if (tipoContrato == true && horasTrabajadas > 160 && horasTrabajadas <= 176){
		horasExtra = (horasTrabajadas - fullTime)*valorHoraExtra;
	}else if (tipoContrato == true && horasTrabajadas > 176){
		horasExtra = 16 * valorHoraExtra;
	}else if (tipoContrato != true && horasTrabajadas <= 80){
		horasExtra = 0;
		enDeuda = fullTime - horasTrabajadas;
		cout << "El empleado " << nombreEmpleado << " debe compensar " << enDeuda << "Hs." << endl << "Justificar?" << noLine << boolSMS << noLine; cin >> justificar;
		if (justificar == true){
			horasTrabajadas = 80; //compensa por justificar
		}else{
			dtos = enDeuda * valorHora;
		}
	}else if (tipoContrato != true && horasTrabajadas > 80 && horasTrabajadas <= 88){
		horasExtra = (horasTrabajadas - partTime)*valorHoraExtra;
	}else if(tipoContrato != true && horasTrabajadas > 88){
		horasExtra = 8 * valorHoraExtra;
	}
	//calculo presentismo
	if (validarPresentismo == true){
		presentismo = sueldoBase * 0.8;//8% presentismo
	}else {
		presentismo = 0;
	}
	sueldoBruto = sueldoBase + presentismo + horasExtra - dtos;//ajuste eventual aca para evitar que pague impuestos sobre dtos
	//determinacion impuestos y aportes
	aportes = sueldoBruto * 0.11; //11% para aportes
	impuestos = sueldoBruto * 0.10; //10% impuestos del gremio
	auxAntiguedad = (antiguedad*sueldoBase)/100; //porcentaje del sueldo, +1% por año trabajado

	sueldoNeto = sueldoBruto + auxAntiguedad - aportes - impuestos;
	
	cout << longDLine << longDLine << endl;
	cout << shortDLine << noLine << nombreEmpleado << noLine << shortDLine << noLine << dni << shortDLine << noLine << shortDLine << endl;
	cout << left;

    cout << setw(40) << "SUELDO BASICO DE CONVENIO" << left << "$" << sueldoBase << endl;
    cout << setw(40) << "EXTRA POR ANTIGUEDAD EN LA EMPRESA" << left << "$" << auxAntiguedad << endl;
	cout << setw(40) << "PRESENTISMO" << left << "$" << presentismo << endl << endl;
    cout << setw(40) << "HORAS EXTRA ADICIONALES" << left << "$" << horasExtra << endl << endl;
    cout << setw(40) << "AJUSTE (SOLO SI CORRESPONDE)" << left << "-$" << dtos << endl << endl;
    cout << setw(40) << "REMUNERACION BRUTA" << left << "$" << sueldoBruto << endl;
    cout << longDLine << longDLine << endl;
    cout << shortSLine << "DESCUENTOS Y RETENCIONES" << shortSLine << endl << endl;
    cout << setw(40) << "JUBILACION / LEY MOVILIDAD          11%" << left << "-$" << aportes << endl;
    cout << setw(40) << "IMPUESTOS DEL GREMIO Y RETENCIONES  10%" << left << "-$" << impuestos << endl;
    cout << longDLine << longDLine << endl << endl;
    cout << setw(40) << "REMUNERACION NETA A LIQUIDAR" << left << "$" << sueldoNeto << endl << endl << endl;
	
	//reiniciar el programa
	cout << "DESEA GENERAR UNA NUEVA LIQUIDACION??" << noLine << boolSMS << noLine;
	cin >> rta;
	
	if (rta == true){
		return main();
	}else{
		return 0;
	}
    system("pause>nul");
    return 0;
}

