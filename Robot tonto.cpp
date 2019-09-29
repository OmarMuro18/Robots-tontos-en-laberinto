#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<windows.h>

int main()
{
	srand(time(NULL));	
	int tablero[5][3],ganador[5][3];
	for(int a=0;a<5;a++)
	{
		for(int b=0;b<3;b++)
		{
			tablero[a][b]=1;
		}
	}
	tablero[1][1]=5;//BLOQUE
	tablero[4][1]=6;//FUEGO
	tablero[4][2]=7;//RECOMPENZA
	
	int robot,cantrob, alto,ancho,perd=0,ganad=0,alant,anant,movgan=0;
	
	puts("CUANTOS ROBOTS DESEA GENERAR?\nROBOTS: ");
	scanf("%d",&cantrob);
	
	for(robot=1;robot<=cantrob;robot++)
	{
		printf("ROBOT No. %d :\n",robot);
		puts("Casillas recoridas");

		int mov=0;
		alto=ancho=0;
		while(tablero[alto][ancho]!=6&&tablero[alto][ancho]!=7)
		{
			//direccion(alto,ancho);
						
			int opc;
			fflush(stdin);
			opc=((rand()%4+1)-rand()%2);
			fflush(stdin);
			if(opc<1)
			{
				opc=rand()%4+1;
			}
			
			switch(opc)
			{
				case 1://arriba
					if(alto==0||tablero[alto-1][ancho]==5)
					{
						break;
					}
					else
					{
						alto--;
						mov++;
						printf("[%d][%d]\t", alto, ancho);
					}
					break;
				case 2://izquierda
					if(ancho==0||tablero[alto][ancho-1]==5)
					{
						break;
					}
					else
					{
						ancho--;
						mov++;
						printf("[%d][%d]\t", alto, ancho);
					}
					break;
				case 3://abajo
					if(alto==4||tablero[alto+1][ancho]==5)
					{
						break;
					}
					else
					{
						alto++;
						mov++;
						printf("[%d][%d]\t", alto, ancho);
					}
					break;
				case 4://derecha
					if(ancho==2||tablero[alto][ancho+1]==5)
					{
						break;
					}
					else
					{
						ancho++;
						mov++;
						printf("[%d][%d]\t", alto, ancho);
					}
					break;
			}
			
			//system("pause");
		}
		printf("\nMovimientos:\t%d\n",mov);
		
		if(tablero[alto][ancho]==6)
		{
			perd++;
			printf("Se incendio\n\n");
		}
		if(tablero[alto][ancho]==7)
		{
			ganad++;
			puts("Gano\n");
		}
	}
	printf("De los %d robots generados:\n\t%d se incendiaron\n\t%dganaron\n\n",robot-1,perd,ganad);
		
	system("pause");
	return 0;
}

//int direccion(int alto, int ancho)

