#include "ejemplo.h"

void main (int argc,char *argv[])
{
	printf("ESTE ES UN TEXTO DE PRUEBA");
	int op_1,op_2,op_3,limf[MAX],limc[MAX];
	int con=0,com=0,com_1=0,com_2=1;
	char buff[MAX_FILE],*opc1="-a",*opc2="-p",*opc3="-s";
	float mat1[MAX_F][MAX_C],mat2[MAX_F][MAX_C],mat3[MAX_F][MAX_C];
	
	if(argc < 3)
	{
		printf("\n\n\t error, faltan mas opciones\n\n");
	}
	else
	{
		def_op(argv[1],&op_1,opc1);		//op_1 <-- Tipo de operación			Son iguales si es 0 -> -a ->Suma
		def_op(argv[2],&op_2,opc2);		//op_2 <-- Tipo de entrada de datos 	Son iguales si es 0 -> -p ->csv
		if(op_2==0)
		{
			org_dat(argv[3],buff,mat1,&limc[0],&limf[0]);//aqui es para organizar los datos de la matriz obtenida a traves de archivos csv
			org_dat(argv[4],buff,mat2,&limc[1],&limf[1]);//aqui es para organizar los datos de la matriz obtenida a traves de archivos csv
			comp_lim(limc,limf,&com,&com_1);//aqui miramos si los limites de las dos matrices csv son iguales
		}
		else
		{
			while(com_2==1)//este ciclo 1 es para poder ingresar mas de una ves los datos por si el usuario se equivoco
			{	
				for(con=0;con < MAX;con++)
					ped_lim(&limc[con],&limf[con],con);//ciclo 2 para pedir los limites de las matrices
				comp_lim(limc,limf,&com,&com_1);//aqui miramos si los limites son iguales
				if(com==0 && com_1==0)//esta condicion es para poder ingresar a llenar las matrices
				{	
					llen_mat(mat1,limc[0],limf[0]);//aqui se llena la matriz
					llen_mat(mat2,limc[1],limf[1]);//aqui se llena la matriz
					com_2=0;//aqui es para salir del ciclo 1
					def_op(argv[3],&op_3,opc3);//aqui miramos si usuario quiere guardar ese resultado de la operacion
					if(op_3==0 && argc == 5)//aqui miramos si cumple para poder guardar ese resultado
					{	
						save_res_csv(argv[4],buff,mat3,limc[0],limf[0]);//aqui guardamos ese resultado
					}	
					else
					{	
						printf("\n\n\terror falta la direccion de destino\n");
					}
				}
				else
					printf("\n\tlos limites no son iguales\n");	
			}	
		}
		if(com==0 && com_1==0)//si los limites son iguales podemos realizar la operacion que el usuario quiere
		{	
			if(op_1==0)//aqui miramos si se cumple la condicion de la operacion de suma 
			{
				sum_mat(mat1,mat2,mat3,limc[1],limf[1]);	
			}	
			else//sino se cumple hace la de resta 
			{	
				res_mat(mat1,mat2,mat3,limc[0],limf[0]);
			}	
			most_res(mat3,limc[0],limf[0]);//mostramos resultados
			if(argc > 5)//condicion si el usuario quiere guardar el resultado pero los datos fueron ingresados por archivos csv
			{	
				def_op(argv[5],&op_3,opc3);//se define si el argumento es el correcto para guardarlo
				if(op_3==0 && argc == 7)//si tiene la direccion de destino donde se va  guardar
				{	
					save_res_csv(argv[6],buff,mat3,limc[0],limf[0]);//se guarda el resultado
				}	
				else
				{	
					printf("\n\n\terror falta la direccion de destino\n");
				}
			}
		}
		else
			printf("\n\tlos limites no son iguales\n");
	}	
}