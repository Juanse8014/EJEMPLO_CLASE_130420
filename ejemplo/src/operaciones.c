#include "ejemplo.h"

void def_op(char *argv1,int *operation,char *opc)
{
	*operation=strcmp(argv1,opc);		//devuelve 0 si las cadenas son iguales
}


void ped_lim(int *lim_c,int *lim_f,int con)//esta subfunncion es para pedir los datos si son ingresados manualmente
{
	printf("\n\t ingrese el limite de columnas de la matriz %d:\n",con+1);
	scanf("%d",&(*lim_c)); // aqui se mod
	printf("\n\t ingrese el limite de filas de la matriz %d:\n",con+1);
	scanf("%d",&(*lim_f));
}


void comp_lim(int lim_c[MAX],int lim_f[MAX],int *comp,int *comp_1)//esta subfuncion es para comparar si los limites son iguales 
{
	int con=0;
	if(lim_c[con]==lim_c[con+1])
		*comp=0;
	else
		*comp=1;
	if(lim_f[con]==lim_f[con+1])
		*comp_1=0;
	else
		*comp_1=1;
}


void llen_mat(float mat[MAX_F][MAX_C],int lim_c,int lim_f)//esta funcion es para llenar las matrices manualmente
{
	int cont1,cont2;
	printf("\n\n Ingrese los datos de la matriz (este se llena de columna a fila):\n"); 	
	for(cont1=0;cont1<lim_f;cont1++)
	{	 
		for(cont2=0;cont2<lim_c;cont2++)
			scanf("%f",&mat[cont1][cont2]);
	}
}


void org_dat(char *argv,char buf[MAX_FILE],float mat[MAX_F][MAX_C],int *lim_c,int *lim_f)
{
	long dim=0;
	FILE *fd_arch;
	int con=0,com=0,con_1=0;
	int lon_1=0,lon_2=0,lon_3=0,lon_4=0,lon_5=0;
	char *dir,*dir_1,*dir_2,*dir_3,*dir_4,cad_1[MAX_FILE];
	
	fd_arch=fopen(argv,"r");
	fseek(fd_arch,0,SEEK_END);
	dim=ftell(fd_arch);
	rewind(fd_arch);
	fread(buf,1,dim,fd_arch);
	fclose(fd_arch);
	
	*lim_c=1;
	*lim_f=1;
	dir=buf;//obtener la direccion inicial de la cadena de caracteres(buf)
	dir_1=strchr(buf,';');//obtener la direccion de ese caracter dentro de la cadena(buf)
	dir_2=strchr(buf,'\r');//obtener la direccion de ese caracter dentro de la cadena(buf)
	dir_3=strchr(buf,'\0');//obtener la direccion de ese caracter dentro de la cadena(buf)
	dir_4=strchr(buf,'\n');//obtener la direccion de ese caracter dentro de la cadena(buf)
	con=(dir_3-dir);//aqui se tiene la longitud total de la cadena de caracteres(buf)
	lon_2=(dir_2-dir);//aqui se obtiene la longitud desde el inicio de la cadena hasta ese caracter(buf)
	lon_1=(dir_1-dir);//aqui se obtiene la longitud desde el inicio de la cadena hasta ese caracter(buf)
	lon_5=(dir_4-dir);//aqui se obtiene la longitud desde el inicio de la cadena hasta ese caracter(buf)
	strncpy(cad_1,buf,lon_1);//aqui se copia del buf lo que realmente se necesita
	
	mat[con_1][com]=atof(cad_1);//aqui se convierte ese caracter en un numero float
	com=com+1;//aqui se cambia la posicion de la columna de la matriz donde se va a guardar
	lon_1=lon_1+1;//para cambiar la posicion para poder mirar dentro del buf 
	lon_3=lon_1;//se va a utilizar para ver que tanto nos movemos dentro del buf
	
	while(lon_3<con)//ciclo1
	{
		while(lon_3<lon_5)//ciclo2 
		{
			dir_1=strchr(buf+lon_1,';');//obtener la direccion de ese caracter dentro de la cadena(buf)
			lon_4=(dir_1-dir);//aqui se obtiene la longitud desde el inicio de la cadena hasta ese caracter(buf)
			if(lon_4<lon_5)//condicion 1 para poder copiar lo que se necesita
			{			
				strncpy(cad_1,buf+lon_1,lon_4);//aqui se copia del buf lo que realmente se necesita
				mat[con_1][com]=atof(cad_1);//aqui se convierte ese caracter en un numero float
				com=com+1;//aqui se cambia la posicion de la columna de la matriz donde se va a guardar
				lon_1=lon_4+1;//para cambiar la posicion para poder mirar dentro del buf
				lon_3=lon_1;//se va a utilizar para ver que tanto nos movemos dentro del buf
			}
			else//condicion 2 para poder copiar lo que se necesita
			{
				strncpy(cad_1,buf+lon_1,lon_5);//aqui se copia del buf lo que realmente se necesita
				mat[con_1][com]=atof(cad_1);//aqui se convierte ese caracter en un numero float
				com=com+1;//aqui se cambia la posicion de la columna de la matriz donde se va a guardar
				lon_1=lon_5+1;//para cambiar la posicion para poder mirar dentro del buf
				lon_3=lon_1;//se va a utilizar para ver que tanto nos movemos dentro del buf
			}	
		}
		*lim_c=com;//aqui se guarda el numero de columnas que se va a obtener del ciclo2
		if(lon_1>lon_5)//condicion 1 para cambiar la fila de la matriz
		{
			dir_4=strchr(buf+lon_1,'\n');//obtener la direccion de ese caracter dentro de la cadena(buf) 
			lon_5=(dir_4-dir);//aqui se obtiene la longitud desde el inicio de la cadena hasta ese caracter(buf)
			dir_2=strchr(buf+lon_1,'\r');//obtener la direccion de ese caracter dentro de la cadena(buf)
			lon_2=(dir_2-dir);//aqui se obtiene la longitud desde el inicio de la cadena hasta ese caracter(buf)	
			com=0;//se reinicia el conteo de el numero de las columnas de la matriz
			con_1=con_1+1;//se usa para incrementar el numero de filas que se va a obtener del buf
			*lim_f=con_1;//aqui se guarda el numero de filas que se va a obtener al entrar en la condicion 1
			if((con-lon_2)<MAX)//condicion 2 para finaliza el ciclo 1
			{
				lon_3=con;
			}	
		}	
	}	
	memset(buf,0,MAX_FILE);// se va a utilizar para inicializar el buf con otro contenido
}


void sum_mat(float mat[MAX_F][MAX_C],float mat_1[MAX_F][MAX_C],float mat_2[MAX_F][MAX_C],int limc,int limf)
{   //subfuncion para sumar las dos matrices
	int con1,con2;
	for(con1=0;con1<limf;con1++)
	{
		for(con2=0;con2<limc;con2++)
			mat_2[con1][con2]=mat[con1][con2]+mat_1[con1][con2];
	}	
}


void res_mat(float mat[MAX_F][MAX_C],float mat_1[MAX_F][MAX_C],float mat_2[MAX_F][MAX_C],int limc,int limf)
{   //subfuncion para restar las dos matrices
	int con1,con2;
	for(con1=0;con1<limf;con1++)
	{
		for(con2=0;con2<limc;con2++)
			mat_2[con1][con2]=mat[con1][con2]-mat_1[con1][con2];
	}
}


void most_res(float mat[MAX_F][MAX_C],int limc,int limf)
{   //subfuncion para mostrar el resultado de la operacion 
	int cont1,cont2;
	printf("\n\n\t el resultado de la operacion es:\n");
	for(cont1=0;cont1<limf;cont1++)
	{
		for(cont2=0;cont2<limc;cont2++)
		{
			printf("\t %f",mat[cont1][cont2]);
		}
		printf("\n");
	}
}


void save_res_csv(char *argv2,char buf[MAX_FILE],float mat[MAX_F][MAX_C],int limc,int limf)
{   //subfuncion para guardar el resultado de la operacion en un archivo csv
	FILE *fd_arch;
	long dim=0;
	int con,com;
	char *dir,*dir_1,cad_1[MAX_FILE];
	for(con=0;con<limf;con++)//aqui se mueve la constante en las filas de la matriz
	{
		for(com=0;com<limc;com++)//aqui se mueve la constante en las columnas de la matriz
		{
			sprintf(cad_1,"%g",mat[con][com]);//aqui se convierte el numero en un caracter y se guardar en la cadena
			strcat(buf,cad_1);//aqui se guarda de una cadena a la otra
			if(limc-com==1)//condicion 1
			{
				strcat(buf,"\r");//aqui se agrega estos caracteres para cambio de linea o cambiar de fila en al archivo
				strcat(buf,"\n");
			}
			else//condicion 2
			{	
				strcat(buf,";");//se usa para separar los numeros entre columnas
			}	
		}
	}
	dir=buf;//se obtiene la direccion de inicio del buf
	dir_1=strchr(buf,'\0');//se obtiene la direccion de inicio del buf
	dim=(dir_1-dir);//se obtiene la longitud del buf
	fd_arch=fopen(argv2,"w");//se abre el archivo donde se va a guardar
	fwrite(buf,1,dim,fd_arch);//se guarda el contenido del buf en el archivo
	fclose(fd_arch);//se cierra el archivo de desstino
}