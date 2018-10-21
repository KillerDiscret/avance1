#pragma once
#include "circuloPadre.h"
class cm : public padre
{private:
	int orientacion;
public:
	cm(Graphics^g, int dx, int dy, int radio, int tiempo, int veces);
	void mover(Graphics ^gr);
	int get_tiempo();
	int get_veces();
	~cm(void);
};
cm::cm(Graphics^g, int dx, int dy, int radio, int tiempo, int veces) : padre(g, dx, dy, radio, tiempo, veces)
{
	Random r;
	int aux;
	aux = r.Next(1, 5);
	if (aux == 1)
	{
		orientacion = 1;
	}
	if (aux == 2)
	{
		orientacion = 2;
	}
	if (aux == 3)
	{
		orientacion = 3;
	}
	if (aux == 4)
	{
		orientacion = 4;
	}
}
void cm::mover(Graphics ^gr)
{
	int direccion;
	bool activador=false;
	bool aux = true;
	borrar(gr);
	if (orientacion==1&&aux==true)
	{
		x++;
		if(x==gr->VisibleClipBounds.Width)
		{
			aux = false;
			activador = true;
		}
		x += dx;
	}
	if (orientacion == 2 && aux == true)
	{
		x--;
		if (x ==0)
		{
			aux = false;
			activador = true;
		}
		x += dx;
	}
	if (orientacion == 3 && aux == true)
	{
		y++;
		if (y == gr->VisibleClipBounds.Height)
		{
			aux = false;
			activador = true;
		}
		y += dy;
	}
	if (orientacion == 4 && aux == true)
	{
		y--;
		if (y ==0)
		{
			aux = false;
			activador = true;
		}
		y += dy;
	}
	if (activador == true)
	{
		/*
		if ((x >= 0||x<=gr->ClipBounds.Width )&&y == 0) direccion = 0;
		if (x == gr->ClipBounds.Width && (y >= 0||y<=gr->ClipBounds.Height))direccion = 1;
		if ((x <= gr->ClipBounds.Width||x>=0) && y ==gr->ClipBounds.Height)direccion = 2;
		if (x == 0 && (y <= gr->ClipBounds.Height||y>=0)) direccion = 3;
		*/
		int acomodar;
		bool aux2 = true;
		if(aux2==true)
		{
		if (y == 0)
		{
			acomodar = 0;
		}
		if (y == int(gr->ClipBounds.Height))
		{
			acomodar = 1;
		}
		if (x == 0)
		{
			acomodar = 2;
		}
		if (x == int(gr->ClipBounds.Width))
		{
			acomodar = 3;
		}
		if (acomodar == 0 && x != int(gr->ClipBounds.Width))
		{
			x++;
			if (x== int(gr->ClipBounds.Width))
			{
				aux2 = false;
			}
		}
		if (acomodar == 1 && x != 0)
		{
			x--;
			if (x == 0)
			{
				aux2 = false;
			}
		}
		if (acomodar == 2 && y != 0)
		{
			y--;
			if (y==0)
			{
				aux2 = false;
			}
		}
		if (acomodar == 3 && y != int(gr->ClipBounds.Height))
		{
			y++;
			if (y == int(gr->ClipBounds.Height))
			{
				aux2 = false;
			}
		}
		}
		if (aux2==false)
		{
			if (x == 0 && y == 0) direccion = 0;
			if (x == 79 && y == 0)direccion = 1;
			if (x == 79 && y == 30)direccion = 2;
			if (x == 0 && y == 30) direccion = 3;
		}
		x += dx;
		y += dy;
	}

		

	dibujar(gr);
}
int cm::get_tiempo()
{
	return tiempo;
}
int cm::get_veces()
{
	return veces;
}
cm::~cm()
{

}
