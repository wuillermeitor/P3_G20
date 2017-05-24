#pragma once
#include <fstream>
#include <iostream>
#include "Input.inl.hh"
#include <conio.h>
#include <queue>

struct vector {
	int filas = 36, columnas = 74;
};

enum class symbols :char {
	MONTA�A='X', AGUA='O', 
	BOSQUE=':', TIERRA='.',

	ENTIO1 = '1', ENTIO2 = '2', ENTIO3 = '3',
	ENTIO4 = '4', ENTIO5 = '5', ENTIO6 = '6',

	ENTIOA = 'A', ENTIOB = 'B', ENTIOC = 'C',
	ENTIOD = 'D', ENTIOE = 'E', ENTIOF = 'F',

	EMPTY=' '
};

class Map {
	//con los "friend class" permitimos a otras clases acceder a los atributos y m�todos del mapa.
	friend class Player;
public:
	void ReadMap(std::ifstream &file, std::string filename);
	void drawMap(bool _player1Torn);//m�todo que crea el mapa.
	symbols posicion(const vector & location);
	void modificar(const vector & target, const symbols & value);//m�todo que modifica una posici�n del mapa.
	void dibujar();//m�todo que dibuja el mapa en la consola.
	~Map();//destructor del Map.
private:
	vector dimensiones;
	symbols**infoMap;
	char**map;
};








/*
class Map {
public:
	//M�todos

	Map(int _rows, int _columns);
	void readMap(std::ifstream &file, std::string filename);
	void drawMap();
	~Map();

	//Atributos
	int row;
	int column;
	char**map;
};

class Player {
public:
	//M�todos
	Player(int posx, int posy, Map &mapa);
	void PlayerMovement(const enti::InputKey & key, int posx, int posy, int entioactual);
	~Player();

	//Atributos
	Map &map;
	int newx, newy;
	int currentx, currenty;
	int alifeEntios;

	std::priority_queue<int> entiosPlayerA;
	std::priority_queue<int> entiosPlayerB;
};

class Entio {
public:
	//M�todos
	Entio(char identificador, int x, int y);
	~Entio();

	//Atributos
	char entio;
	int posx, posy;
	int vida;
	int fatiga;
	int flechas;
};
*/