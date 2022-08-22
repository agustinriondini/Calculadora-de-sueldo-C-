#include <iostream>
using namespace std;
#include <cstdlib>

int main(){
	
	string surname, programVer = "V-0.1.2", developer = " RIONDINI JUAN AGUSTIN ", company = "J.A.R-SOFT", periodo;
	int sueldoBruto, edad, antiguedad, dni, anho, horasTrabajadas;
	float sueldoBasico = 45000, horaExtra = 458;
	bool exit;

	
	cout << "============================================================= " << programVer <<" ===========================" << endl;
	cout << "=================================================================================================" << endl;
	cout << "================================= " << company << " BY " << developer << "==========================" << endl;
	cout << "========= LIQUIDADOR DE SUELDOS =================================================================" << endl << endl;
	
	cout << "======================= INGRESE EL PERIODO A LIQUIDAR Y LUEGO EL ANHO ===========================" << endl;
	cin >> periodo >> anho;
	
	cout << "======================= INGRESE EL APELLIDO DEL EMPLEADO Y LUEGO EL DNI =========================" << endl;
	cin >> surname >> dni;
	
	cout << "======================= INGRESE LA ANTIGUEDAD EN LA EMPRESA (ANHOS CUMPLIDOS) ===================" << endl;
	cin >> antiguedad;
	
	cout << "======================= INGRESE LA CANTIDAD DE HORAS COMPLETAS TRABAJADAS POR EL EMPLEADO =======" << endl;
	cin >> horasTrabajadas;
	
	cout << "============================================================================== SUELDO PROCESADO =" << endl;
	
	cout << periodo << anho << surname << dni << antiguedad << horasTrabajadas;
	
	
	
	return 0;
}
