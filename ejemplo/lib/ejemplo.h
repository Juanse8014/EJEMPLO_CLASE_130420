#ifndef EJEMPLO_H 
#define EJEMPLO_H
	#include<stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stdint.h>
	#define MAX_FILE 500
	#define MAX_F 100
	#define MAX_C 100
	#define MAX 2

	void def_op(char* ,int *,char*);
	void ped_lim(int *,int *,int);
	void comp_lim(int [MAX],int [MAX],int*,int*);
	void llen_mat(float [MAX_F][MAX_C],int,int);
	void org_dat(char*,char[MAX_FILE],float [MAX_F][MAX_C],int*,int*);
	void sum_mat(float [MAX_F][MAX_C],float [MAX_F][MAX_C],float [MAX_F][MAX_C],int,int);
	void res_mat(float [MAX_F][MAX_C],float [MAX_F][MAX_C],float [MAX_F][MAX_C],int,int);
	void most_res(float [MAX_F][MAX_C],int,int);
	void save_res_csv(char*,char[MAX_FILE],float [MAX_F][MAX_C],int,int);
#endif