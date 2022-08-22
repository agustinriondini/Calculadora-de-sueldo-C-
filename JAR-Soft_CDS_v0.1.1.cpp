#include <iostream>
using namespace std;
#include <cstdlib>

int main(){

	
	string nombreEmpleado, periodo, displayMedioPago;
	int edad, antiguedad, auxAntiguedad, horasTrabajadas, horasExtra, sueldoBruto, auxEdad, sueldoNeto, dni, year = 2022;
	float aportes, impuestos;
	bool rta, medioPago;
	
	int sueldoBase = 75000;
	int valorHoraExtra = 468;


	
	cout << "CALCULADORA DE SUELDOS V-0.1.1 J.A.R SOFTWARE" << endl << "===============================================" << endl << "===============================================" << endl;
	cout << "PERIODO O MES A LIQUIDAR: " << endl;
	
	cin >> periodo;
	
	cout << "APELLIDO DEL EMPLEADO" << endl;
	
	cin >> nombreEmpleado;
	
	cout << "INGRESE EL DNI DEL EMPLEADO: " << endl;
	
	cin >> dni;
	
	cout << "EDAD DEL EMPLEADO: " << endl;
	
	cin >> edad;
	
	cout << "CANTIDAD DE HORAS TOTALES REALIZADAS EN EL PERIODO: (HORAS COMPLETAS)" << endl;
	
	cin >> horasTrabajadas;
	
	cout << "ANTIGUEDAD DEL EMPLEADO (ANHOS CUMPLIDOS): " << endl;
	
	cin >> antiguedad;
	
	cout << "MEDIO DE PAGO (EFECTIVO (1) - BANCO(0)" << endl;
	
	cin >> medioPago;
	
		
	if (horasTrabajadas > 160){
		horasExtra = (horasTrabajadas - 160)*valorHoraExtra;
	}else{
		horasExtra = 0;
	}
	
	
	if (edad > 50){
		auxEdad = ((sueldoBase*0.2));
	}else if(40 < edad > 49){
		auxEdad = ((sueldoBase*0.1));
		}else{
			auxEdad = 0;
		}
	
	
	if (medioPago = 1){
		displayMedioPago = "EFECTIVO";
	}else{
		displayMedioPago ="BANCO";
	}
	
	
	auxAntiguedad = (antiguedad*sueldoBase)/100;
	
	sueldoBruto = int(sueldoBase)+int(horasExtra)+int(auxAntiguedad)+int(auxEdad);
	
	aportes = (sueldoBruto - (sueldoBruto*89)/100);
	
	impuestos = (sueldoBruto - (sueldoBruto*90)/100);
	
	sueldoNeto = sueldoBruto - aportes - impuestos;
	
	
	cout << "==============================================================================" << endl;
	cout << "=======  " << nombreEmpleado << " ==== "<< dni << " ===================== " << displayMedioPago << " === " << endl;
	cout << "============================RECIBO DE SUELDO===============" << periodo << " === "<< year << "===" << endl << endl;
	cout << "SUELDO BASICO DE CONVENIO                                  $" << sueldoBase << endl;
	cout << "EXTRA POR ANTIGUEDAD EN LA EMPRESA                         $" << auxAntiguedad << endl;
	cout << "BONO POR EDAD (A PARTIR DE 40 ANH0S DE EDAD                $" << auxEdad << endl;
	cout << "HORAS EXTRA ADICIONALES                                    $" << horasExtra << endl << endl;
	cout << "REMUNERACION BRUTA                                         $" << sueldoBruto << endl;
	cout << "==============================================================================" << endl;
	cout << "=========================DESCUENTOS Y RETENCIONES ============================" << endl << endl;
	cout << "JUBILACION / LEY MOVILIDAD                                -$" << aportes << endl;
	cout << "IMPUESTOS DEL GREMIO Y RETENCIONES                        -$" << impuestos << endl;
	cout << "=============================================================================" << endl << endl;
	cout << "REMUNERACION NETA A LIQUIDAR A                             $" << sueldoNeto << endl << endl << endl;
	
	cout << "DESEA GENERAR UNA NUEVA LIQUIDACION??" << endl << "1 PARA SI // 0 PARA NO" << endl;
	
	cin >> rta;
	
	if (rta == true){
		return main();
	}else{
		return 0;
	}

	
    
    


    system("pause>nul");
    return 0;
}

