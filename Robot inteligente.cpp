#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<windows.h>

int recran(float tablero[][3],int alto, int ancho, int alant, int anant);
void relltab(float tablero[][3],int alto,int ancho);
void pasos(float tablero[][3],int alin, int anin);

int main()
{
	srand(time(NULL));
	
	float tablero[5][3];
	
	puts("***INICIO DEL PROGRAMA***");
	
	for(int a=0;a<5;a++)
	{
		for(int b=0;b<3;b++)
		{
			tablero[a][b]=0;
		}
	}
	tablero[1][1]=-2;//BLOQUE
	tablero[4][1]=-1;//FUEGO
	tablero[4][2]=1;//RECOMPENZA
	
	int alto,ancho,alant,anant;
	
	alant=anant=alto=ancho=0;
	
	recran(tablero,alto,ancho,alant,anant);
	
	puts("***FIN DEL PROGRAMA***");
	
	system("pause");
	return 0;
}

int recran(float tablero[][3],int alto, int ancho, int alant, int anant)
{
	puts("-RECORRIDO ALEATORIO-");
	while(tablero[alto][ancho]!=1)
	{
		alant=anant=alto=ancho=0;
		while(tablero[alto][ancho]!=-1&&tablero[alto][ancho]!=1)
		{
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
					if(alto==0||tablero[alto-1][ancho]==-2||alto-1==alant)
					{
						break;
					}
					else
					{
						alant=alto;
						alto--;
						printf("[%d][%d]\t", alto, ancho);
					}
					break;
				case 2://izquierda
					if(ancho==0||tablero[alto][ancho-1]==-2||ancho-1==anant)
					{
						break;
					}
					else
					{
						anant=ancho;
						ancho--;
						printf("[%d][%d]\t", alto, ancho);
					}
					break;
				case 3://abajo
					if(alto==4||tablero[alto+1][ancho]==-2||alto+1==alant)
					{
						break;
					}
					else
					{
						alant=alto;
						alto++;
						printf("[%d][%d]\t", alto, ancho);
					}
					break;
				case 4://derecha
					if(ancho==2||tablero[alto][ancho+1]==-2||ancho+1==anant)
					{
						break;
					}
					else
					{
						anant=ancho;
						ancho++;
						printf("[%d][%d]\t", alto, ancho);
					}
					break;
			}
		}
		puts("");
	}
	
	relltab(tablero,alto, ancho);
}

void relltab(float tablero[][3],int alto,int ancho)
{
	int alin, anin,aceptar,viaje,z,w,a,paso;
	
	float mayor;
	for(z=ancho;z>=0;z--)
	{
		for(w=alto;w>=0;w--)
		{
			mayor=0;
			if(tablero[w][z]==0)
			{
				if(w>0)
				{
					if(tablero[w-1][z]>mayor)
					{
						mayor=tablero[w-1][z];
					}
				}
	
				if(z>0)
				{
					if(tablero[w][z-1]==mayor)
					{
						paso=rand()%2+1;
						if(paso==1)
						{
							mayor=0;
						}
					}
					if(tablero[w][z-1]>mayor)
					{
						mayor=tablero[w][z-1];
					}
				}
	
				if(w<4)
				{
					if(tablero[w+1][z]==mayor)
					{
						paso=rand()%2+1;
						if(paso==1)
						{
							mayor=0;
						}
					}
					if(tablero[w+1][z]>mayor)
					{
					mayor=tablero[w+1][z];
					}
				}
				if(z<2)
				{
					if(tablero[w][z+1]==mayor)
					{
						paso=rand()%2+1;
						if(paso==1)
						{
							mayor=0;
						}
					}
					if(tablero[w][z+1]>mayor)
					{
						mayor=tablero[w][z+1];
					}
				}
				
				tablero[w][z]=mayor*.9;
			}
		}
	}
	
	puts("\nDAME LA CANTIDAD DE VIAJES QUE QUEIRAS REALIZAR: ");
	scanf("%d",&viaje);
	for(a=1;a<=viaje;a++)
	{
		puts("\n");
		do
		{
			printf("\nElige la posicion inicial del robot:\nAlto: ");
			scanf("%d",&alin);
			printf("Ancho: ");
			scanf("%d",&anin);
			aceptar=1;
			if(alin<0||alin>4||anin<0||anin>2)//BLOQUE
			{
				aceptar=0;
			}
			if(alin==1&&anin==1)//BLOQUE
			{
				aceptar=0;
			}
			if(alin==4&&anin==1)//FUEGO
			{
				aceptar=0;
			}
			if(alin==4&&anin==2)//RECOMPENZA
			{
				aceptar=0;
			}
		}while(aceptar<1);
		
		printf("\nVIAJE %d:\n\t",a);
		
		pasos(tablero,alin,anin);
		
		puts("\n");
	}
	
}

void pasos(float tablero[][3],int alin, int anin)
{
	while(tablero[alin][anin]!=1)
	{
		int opc;
		int paso=0;
		
		float mayor=0;
	
		if(alin>0)
		{
			if(tablero[alin-1][anin]>mayor)
			{
				mayor=tablero[alin-1][anin];
				opc=1;
			}
		}
	
		if(anin>0)
		{
			if(tablero[alin][anin-1]==mayor)
			{
				paso=rand()%2+1;
				if(paso==1)
				{
					mayor=0;
				}
			}
			if(tablero[alin][anin-1]>mayor)
			{
				mayor=tablero[alin][anin-1];
				opc=2;
			}
		}
	
		if(alin<4)
		{
			if(tablero[alin+1][anin]==mayor)
			{
				paso=rand()%2+1;
				if(paso==1)
				{
					mayor=0;
				}
			}
			if(tablero[alin+1][anin]>mayor)
			{
				mayor=tablero[alin+1][anin];
				opc=3;
			}
		}
		if(anin<2)
		{
			if(tablero[alin][anin+1]==mayor)
			{
				paso=rand()%2+1;
				if(paso==1)
				{
					mayor=0;
				}
			}
			if(tablero[alin][anin+1]>mayor)
			{
				mayor=tablero[alin][anin+1];
				opc=4;
			}
		}
		switch(opc)
		{
			case 1://arriba
				alin--;
				printf("[%d][%d]\t", alin, anin);
				break;
			case 2://izquierda
				anin--;
				printf("[%d][%d]\t", alin, anin);
				break;
			case 3://abajo
				alin++;
				printf("[%d][%d]\t", alin, anin);
				break;
			case 4://derecha
				anin++;
				printf("[%d][%d]\t", alin, anin);
				break;
		}
	}
}
