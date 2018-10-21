#pragma once
#include "circuloPadre.h"
class cm : public padre
{private:
	int orientacion;
	bool habilita=true;
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
	aux = r.Next(1, 2);
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
		borrar(gr);
		if (habilita == true)
		{

			if (orientacion == 1)
			{
				//derecha
				x++;
				x = x + dx;
				if (x + dx + radio >=gr->VisibleClipBounds.Width)
				{
					x = 300;
					habilita = false;
				}
			}
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
