#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tilemap.h"
#include "Platform.h"
#include "Crate.h"

const sf::Vector2f WINDOW_SIZE(960, 640);

const int levelSizeX = 30, levelSizeY = 30;

const int levelMainMenu[levelSizeY][levelSizeX] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000};

void Tilemap::LoadLevelZero()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = levelMainMenu[i][j];
}

const int level1[30][30] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 999, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 191, 191, 191, 192, 000, 000, 000, 903, 000, 000, 000, 190, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 290, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 390, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000};

void Tilemap::LoadLevelOne()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level1[i][j];

	//pushback moving platforms
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
			if(m_levelMap[i][j] == 903)
			{
				Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
		}
	}

	//populate map with trees, rocks, shrooms, whatever
	sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(2*64, 7*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(4*64, 7*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(16*64, 7*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(0*64, 7*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(0*64, 7*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(1*64, 7*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(14*64 - 12, 7*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	sf::Sprite *bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(0, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(3*64 + 12, 7*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);

	bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(m_bushesTexture.getSize().x*2/4, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(14*64 + 12, 7*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);
}

const int level2[30][30] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 191, 191, 191, 192, 000, 000, 000, 900, 000, 000, 000, 190, 191, 191, 191, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 290, 291, 291, 291, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 390, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 999, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 490, 500, 191, 191, 191, 191, 192, 000, 000, 000, 900, 000, 000, 000, 000, 190, 191, 192, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 392, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000};

void Tilemap::LoadLevelTwo()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level2[i][j];

	//pushback moving platforms
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
			if(m_levelMap[i][j] == 900)
			{
				Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
		}
	}

	//populate with crates
	Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(3*64, 6*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(4*64 - 24, 6*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(11*64, 13*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(12*64 - 24, 13*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	//populate map with trees, rocks, shrooms, whatever
	sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(2*64, 7*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(13*64, 7*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(7*64 + 5, 14*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(0*64, 7*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(0*64, 7*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(3*64, 7*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(13*64 - 12, 7*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	sf::Sprite *bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(0, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(3*64 + 12, 7*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);

	bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(m_bushesTexture.getSize().x*2/4, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(15*64 + 12, 7*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);
}

const int level3[levelSizeY][levelSizeX] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 999, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 190, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 290, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 290, 291, 291, 291, 490, 500, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 290, 291, 291, 291, 291, 291, 490, 500, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 290, 291, 291, 291, 291, 291, 291, 291, 292, 000, 000, 000, 000, 904, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 390, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 191, 192, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 291, 292, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 502, 492, 291, 291, 292, 000, 000,
	190, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 192, 000, 000, 000, 900, 000, 000, 000, 390, 391, 391, 391, 391, 391, 392, 000, 000,
	390, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000};

void Tilemap::LoadLevelThree()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level3[i][j];

	//pushback moving platforms
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
			if(m_levelMap[i][j] == 900)
			{
				Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 904)
			{
				Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
		}
	}

	//populate with crates
	Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(3*64, 12*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(9*64, 12*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(10*64 - 24, 12*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(10*64 - 38, 11*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(23*64, 11*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(23*64 + 16, 10*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(10*64 + 16, 5*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(10*64 + 16, 6*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	//populate map with trees, rocks, shrooms, whatever
	sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(2*64, 13*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(4*64, 13*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(21*64, 12*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(8*64, 5*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(0*64, 13*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(1*64, 13*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(1*64, 13*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(22*64, 12*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	sf::Sprite *bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(0, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(3*64 + 12, 13*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);

	bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(m_bushesTexture.getSize().x*2/4, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(12*64 + 12, 13*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);
}

const int level4[levelSizeY][levelSizeX] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 191, 191, 191, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 190, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 190, 191, 191, 191, 191, 191, 191, 191, 191, 191, 502, 492, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 390, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 999, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 190, 191, 191, 191, 191, 191, 191, 192, 000, 000, 000, 190, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 290, 291, 291, 291, 291, 291, 291, 292, 000, 000, 000, 390, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 390, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000};

void Tilemap::LoadLevelFour()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level4[i][j];

	//populate with crates
	Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(1*64, 2*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(11*64, 11*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	//populate map with trees, rocks, shrooms, whatever
	sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(3*64, 8*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(0*64, 8*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(9*64, 12*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(6*64, 17*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(0*64, 8*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(1*64, 8*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(3*64, 8*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(4*64 - 34, 8*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	sf::Sprite *bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(0, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(6*64, 8*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);

	bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(m_bushesTexture.getSize().x/4, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(1*64, 17*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);

	bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(m_bushesTexture.getSize().x*3/4, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(7*64, 17*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);
}

const int level5[levelSizeY][levelSizeX] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 999, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 191, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000};

void Tilemap::LoadLevelFive()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level5[i][j];

	//populate with crates
	Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(5*64, 4*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(5*64, 3*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(9*64, 2*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(10*64 - 24, 2*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(13*64, 2*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(13*64 - 9, 1*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	//populate map with trees, rocks, shrooms, whatever
	sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(3*64, 5*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(1*64, 5*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(2*64, 5*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(13*64, 3*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(0*64, 5*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(3*64, 5*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	sf::Sprite *bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(0, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(4*64, 5*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);
}

const int level6[30][30] = {
	000, 100, 102, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 200, 202, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 200, 202, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 999, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 191, 192, 000, 000, 000, 000, 902, 000, 000, 000, 000, 190, 191, 192, 000, 190, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 201, 490, 500, 192, 000, 000, 000, 000, 000, 000, 000, 390, 391, 392, 000, 290, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 201, 201, 201, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 201, 201, 201, 490, 500, 191, 191, 191, 191, 191, 191, 191, 191, 191, 502, 492, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000};

void Tilemap::LoadLevelSix()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level6[i][j];

	//pushback moving platforms
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
			if(m_levelMap[i][j] == 900)
			{
				Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 901)
			{
				Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 902)
			{
				Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 903)
			{
				Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 904)
			{
				Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 905)
			{
				Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
		}
	}

	//populate with crates
	Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(8*64, 6*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(6*64, 6*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(6*64, 5*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	//populate map with trees, rocks, shrooms, whatever
	sf::Sprite *tree1 = new sf::Sprite(); tree1->setTexture(m_treesTexture); tree1->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree1->setPosition(7*64, 6*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree1);

	sf::Sprite *rockshroom1 = new sf::Sprite; rockshroom1->setTexture(m_rockshroomsTexture); rockshroom1->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom1->setPosition(7*64, 6*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom1);

	sf::Sprite *bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(0, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(9*64, 6*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);
}

const int level7[30][30] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 999, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 190, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000,
	190, 192, 000, 000, 290, 201, 292, 000, 000, 000, 903, 000, 000, 000, 000, 000, 000, 390, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000,
	390, 392, 000, 000, 290, 201, 292, 000, 000, 000, 000, 900, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 290, 201, 292, 000, 000, 902, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 290, 201, 292, 000, 000, 000, 000, 000, 905, 000, 000, 000, 000, 000, 190, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 190, 502, 492, 201, 292, 000, 000, 000, 000, 000, 000, 000, 903, 000, 000, 000, 390, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 390, 391, 391, 391, 392, 000, 000, 190, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 390, 392, 000, 000, 902, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 903, 000, 000, 000, 390, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 192, 000, 000, 902, 000, 000, 190, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 392, 000, 000, 000, 000, 000, 390, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000};

void Tilemap::LoadLevelSeven()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level7[i][j];

	//pushback moving platforms
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
			if(m_levelMap[i][j] == 900)
			{
				Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 901)
			{
				Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 902)
			{
				Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 903)
			{
				Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 904)
			{
				Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 905)
			{
				Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
		}
	}

	//no crates this map

	//populate map with trees, rocks, shrooms, whatever
	sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(0*64 - 14, 3*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(2*64 - 12, 7*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(18*64, 6*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(9*64, 8*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(0*64, 3*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(0*64, 12*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(1*64, 12*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(18*64 + 6, 6*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	sf::Sprite *bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(0, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
	bush1->setPosition(9*64 + 12, 8*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);
}

const int level8[30][30] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 191, 191, 191, 191, 192, 000, 000, 000, 190, 191, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 291, 292, 000, 000, 000, 390, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 190, 191, 192, 000, 000, 000, 000, 903, 000, 000, 000, 000, 000, 000, 190, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 390, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 999, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 191, 191, 191, 191, 191, 191, 192, 000, 000, 000, 000, 000, 902, 000, 000, 190, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000
};

void Tilemap::LoadLevelEight()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level8[i][j];

	//for platforms
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
			if(m_levelMap[i][j] == 900)
			{
				Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 901)
			{
				Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 902)
			{
				Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 903)
			{
				Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 904)
			{
				Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 905)
			{
				Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
		}
	}

	//push back crates
	Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(6*64, 3*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(12*64, 3*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(2*64, 6*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	//populate map with trees, rocks, shrooms, whatever
	sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(1*64, 3*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(18*64, 8*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(2*64, 3*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(18*64, 8*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(3*64, 14*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);
}

const int level9[30][30] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 999, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 192, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 192, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 000, 190, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 000, 903, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 000, 390, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 192, 000, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 502, 492, 291, 292, 000, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 904, 000, 000, 000, 000, 390, 391, 391, 391, 391, 392, 000, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 190, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 390, 391, 392, 000, 000, 902, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 292, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 292, 000,
	190, 191, 191, 191, 191, 191, 191, 502, 492, 291, 490, 500, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 502, 492, 291, 292, 000,
	290, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 291, 292, 000,
	390, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 391, 392, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000
};

void Tilemap::LoadLevelNine()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level9[i][j];

	//pushback moving platforms
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
				if(m_levelMap[i][j] == 900)
			{
				Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 901)
			{
				Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 902)
			{
					Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 903)
			{
				Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 904)
			{
				Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 905)
			{
				Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
		}
	}

	//push back crates
	Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(2*64, 15*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(9*64, 13*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(9*64, 14*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(21*64, 7*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(7*64, 5*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(7*64, 4*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate = new Crate; crate->SetPosition(sf::Vector2f(15*64, 1*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	//populate map with trees, rocks, shrooms, whatever
	sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(1*64, 15*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(16*64 - 13, 15*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(15*64, 15*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(18*64, 8*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
	tree->setPosition(8*64, 5*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

	sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(14*64, 15*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(16*64, 15*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(18*64, 8*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

	rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
	rockshroom->setPosition(3*64, 15*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);
}

const int level10[30][30] = {
	000, 000, 000, 000, 000, 000, 000, 190, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 191, 191, 191, 191, 502, 492, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 902, 000, 000, 000, 000, 190, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000,
	000, 190, 191, 191, 191, 191, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000,
	000, 390, 391, 391, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 192, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 390, 392, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 999, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 192, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 390, 392, 000, 000, 000, 000, 000, 000, 000
};

void Tilemap::LoadLevelTen()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level10[i][j];

	//pushback moving platforms
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
			if(m_levelMap[i][j] == 902)
			{
				Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
		}
	}

	//push back crates
	Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(5*64, 7*64 - crate->GetSize().y));
	m_crates.push_back(*crate);
}

const int level11[30][30] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 190, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 190, 192, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 290, 292, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 502, 492, 292, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 391, 391, 392, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 999,
	000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 192,
	000, 000, 000, 000, 000, 000, 390, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 192, 000, 000, 000, 290, 292,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 192, 000, 000, 000, 390, 391, 392, 000, 000, 000, 290, 292,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 192, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292,
	000, 000, 000, 000, 190, 191, 191, 191, 191, 192, 000, 000, 000, 390, 391, 392, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292,
	000, 000, 000, 000, 390, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 490, 500, 191, 192, 000, 190, 191, 191, 191, 502, 492, 292,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 391, 391, 392, 000, 390, 391, 391, 391, 391, 391, 392,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000
};

void Tilemap::LoadLevelEleven()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level11[i][j];

	//no platforms!

	//push back crates
	Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(2*64, 5*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate->SetPosition(sf::Vector2f(2*64, 4*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate->SetPosition(sf::Vector2f(4*64, 12*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate->SetPosition(sf::Vector2f(18*64, 10*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate->SetPosition(sf::Vector2f(22*64, 9*64 - crate->GetSize().y));
	m_crates.push_back(*crate);
}

const int level12[30][30] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 190, 192, 000, 000, 000, 000, 000, 902, 000, 000, 000, 000, 190, 191, 191, 191, 191, 192, 000, 906, 000, 000, 190, 192, //note: this 906 is still and shifted back. Check in the loadLevelTwelve();
	000, 000, 000, 000, 000, 000, 290, 490, 500, 192, 000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 391, 391, 391, 392, 000, 000, 000, 000, 290, 292,
	000, 000, 000, 000, 000, 000, 390, 391, 391, 392, 000, 000, 901, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 905, 000, 000, 000, 000, 000, 190, 191, 192, 000, 190, 191, 500, 492, 292,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 502, 492, 291, 292, 000, 390, 391, 391, 391, 392,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 192, 000, 000, 901, 000, 000, 390, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 502, 492, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 191, 191, 191, 191, 191, 192, 000, 390, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 291, 291, 291, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	390, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 999,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 192,
	000, 000, 000, 000, 190, 191, 191, 191, 191, 191, 192, 000, 000, 000, 900, 000, 000, 000, 000, 190, 192, 000, 000, 190, 192, 000, 000, 000, 390, 392,
	000, 000, 000, 000, 390, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 390, 392, 000, 000, 290, 292, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 290, 292, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 390, 392, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000
};

void Tilemap::LoadLevelTwelve()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level12[i][j];

	//pushback moving platforms
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
				if(m_levelMap[i][j] == 900)
			{
				Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 901)
			{
				Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 902)
			{
					Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 903)
			{
				Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 904)
			{
				Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 905)
			{
				Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 906)
			{
				Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x - 33, i * m_size.y));
				m_platforms.push_back(*p);
			}
		}
	}
}

const int level13[30][30] = {
	000, 000, 000, 000, 000, 000, 999, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 190, 191, 191, 192, 000, 900, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	190, 192, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 000, 000, 903, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292, 000, 000, 901, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 902, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 904, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 000, 000, 000, 901, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 000, 190, 191, 191, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 000, 390, 391, 391, 391, 391, 392, 000, 000, 000, 902, 000, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 192, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 902, 000, 000, 000, 390, 392, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 000, 000, 000, 000, 000, 190, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292, 000, 000, 000, 000, 903, 000, 000, 000, 390, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 292
	, 000, 000, 000, 000, 000, 902, 000, 000, 000, 000, 000, 000, 190, 191, 192, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 290, 291, 291, 490, 500, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 392, 000, 000, 000, 000, 000, 000,
	290, 292, 000, 000, 000, 390, 391, 391, 391, 391, 391, 391, 392, 000, 000, 900, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 192, 000, 000, 000,
	290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 190, 191, 191, 502, 492, 292, 000, 000, 000,
	290, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 902, 000, 000, 290, 291, 291, 291, 291, 292, 000, 000, 000,
	290, 490, 500, 191, 191, 191, 192, 000, 000, 190, 191, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 290, 291, 291, 291, 291, 292, 000, 000, 000,
	390, 391, 391, 391, 391, 391, 392, 000, 000, 390, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 390, 391, 391, 391, 391, 392, 000, 000, 000
};

void Tilemap::LoadLevelThirteen()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level13[i][j];

	//pushback moving platforms
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
				if(m_levelMap[i][j] == 900)
			{
				Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 901)
			{
				Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 902)
			{
					Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 903)
			{
				Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 904)
			{
				Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
			else if(m_levelMap[i][j] == 905)
			{
				Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
				m_platforms.push_back(*p);
			}
		}
	}

	//push back crates
	Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(4*64, 17*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate->SetPosition(sf::Vector2f(4*64, 18*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate->SetPosition(sf::Vector2f(7*64 - 2, 18*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate->SetPosition(sf::Vector2f(26*64, 15*64 - crate->GetSize().y));
	m_crates.push_back(*crate);
	
	crate->SetPosition(sf::Vector2f(26*64, 14*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate->SetPosition(sf::Vector2f(19*64, 16*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate->SetPosition(sf::Vector2f(21*64, 10*64 - crate->GetSize().y));
	m_crates.push_back(*crate);

	crate->SetPosition(sf::Vector2f(15*64, 10*64 - crate->GetSize().y));
	m_crates.push_back(*crate);
}

const int level14[30][30] = {
	000, 000, 000, 000, 102, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 202, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 202, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 190, 000, 191, 000, 192, 000, 000, 000, 190, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 290, 000, 201, 000, 292, 000, 000, 000, 390, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 290, 000, 201, 191, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 290, 000, 000, 000, 490, 000, 191, 191, 191, 191, 191, 192, 000, 000, 902, 000, 000, 190, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 390, 000, 000, 000, 391, 000, 391, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 200, 204, 208, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000
};

void Tilemap::LoadLevelFourteen()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level14[i][j];
}

const int level15[30][30] = {
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 190, 000, 191, 191, 192, 000, 000, 000, 190, 191, 192, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 290, 000, 191, 000, 000, 000, 000, 000, 390, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 290, 000, 291, 191, 292, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 290, 000, 000, 000, 490, 000, 000, 191, 191, 191, 191, 192, 000, 000, 902, 000, 000, 190, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 390, 000, 191, 191, 391, 000, 000, 391, 391, 391, 391, 392, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 200, 204, 208, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,
	000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000
};

void Tilemap::LoadLevelFifteen()
{
	//empty
	m_crates.clear();
	m_bushes.clear();
	m_rockshrooms.clear();
	m_trees.clear();
	m_platforms.clear();

	//set m_levelMap to the current level
	for(int i = 0; i < levelSizeY; i++)
		for(int j = 0; j < levelSizeX; j++)
			m_levelMap[i][j] = level15[i][j];
}

int Tilemap::getLevelMap(int y, int x)
{
	return m_levelMap[y][x];
}

int Tilemap::getLevel()
{
	return m_level;
}

float Tilemap::getPlatformSize()
{
	return m_platforms.size();
}

float Tilemap::getPlatformTop(int i)
{
	return m_platforms[i].getTop();
}

float Tilemap::getPlatformBottom(int i)
{
	return m_platforms[i].getBottom();
}

float Tilemap::getPlatformLeft(int i)
{
	return m_platforms[i].getLeft();
}

float Tilemap::getPlatformRight(int i)
{
	return m_platforms[i].getRight();
}

sf::Vector2f Tilemap::getPlatformMovement(int i)
{
	return m_platforms[i].getMovement();
}

float Tilemap::getCrateSize()
{
	return m_crates.size();
}

float Tilemap::getCrateTop(int i)
{
	return m_crates[i].getTop();
}

float Tilemap::getCrateBottom(int i)
{
	return m_crates[i].getBottom();
}

float Tilemap::getCrateLeft(int i)
{
	return m_crates[i].getLeft();
}

float Tilemap::getCrateRight(int i)
{
	return m_crates[i].getRight();
}

void Tilemap::setCratePos(int i, sf::Vector2f pos)
{
	m_crates[i].SetPosition(pos);
}

bool Tilemap::getCrateOnLeft(int i)
{
	return m_crates[i].getOnLeft();
}

bool Tilemap::getCrateOnRight(int i)
{
	return m_crates[i].getOnRight();
}

sf::Vector2f Tilemap::getCrateMovement(int i)
{
	return m_crates[i].getMovement();
}

void Tilemap::CrateCrateCollision(sf::RenderWindow &window)
{
	for(int i = 0; i < getCrateSize(); i++)
	{
		for(int j = 0; j < getCrateSize(); j++)
		{
			/*if(m_crates[i].getBottom() < window.getView().getCenter().y - window.getSize().y/2 || 
				m_crates[i].getTop() > window.getView().getCenter().y + window.getSize().y/2 ||
				m_crates[i].getRight() < window.getView().getCenter().x - window.getSize().x/2 ||
				m_crates[i].getLeft() > window.getView().getCenter().x + window.getSize().x/2)
			{}*/
			//else
			//{
				m_crates[i].CrateCollide(getCrateTop(j), getCrateBottom(j), getCrateLeft(j), getCrateRight(j));
				if(m_crates[i].getOnCrate() == true)
					break;
			//}
		}
	}
}

void Tilemap::setMap(sf::RenderWindow &window)
{
	m_level += 1;
	std::cout<<m_level<<std::endl;
	setMap(m_level, window);
}

void Tilemap::setMap(int i, sf::RenderWindow &window)
{
	if(window.getSize().x > 10)
	{
		m_loadingScreen.setScale(window.getSize().x / m_loadingScreen.getGlobalBounds().width, window.getSize().y / m_loadingScreen.getGlobalBounds().height); /*2000 is width and height of the loading screen texture*/
		m_loadingScreen.setPosition(window.getView().getCenter().x - window.getSize().x/2, window.getView().getCenter().y - window.getSize().y/2);
		m_loadingText.setPosition(window.getView().getCenter().x - m_loadingText.getGlobalBounds().width/2, window.getView().getCenter().y - m_loadingText.getGlobalBounds().height/2);
	}
	else
	{
		m_loadingScreen.setScale(0.48f, 0.32f);
		m_loadingScreen.setPosition(window.getView().getCenter().x - window.getSize().x/2, window.getView().getCenter().y - window.getSize().y/2);
		m_loadingText.setPosition(window.getView().getCenter().x - m_loadingText.getGlobalBounds().width/2, window.getView().getCenter().y - m_loadingText.getGlobalBounds().height/2);
	}

	window.clear();
	window.draw(m_loadingScreen);
	window.draw(m_loadingText);
	window.display();

	m_loadingScreen.setScale(1, 1);

	m_level = i;

	m_platforms.clear();
	m_crates.clear();
	m_rockshrooms.clear();
	m_trees.clear();

	switch(i)
	{
	case -1:
		LoadLevelZero();
		break;
	case 0:
		LoadLevelOne();
		break;
	case 1:
		LoadLevelTwo();
		break;
	case 2:
		LoadLevelThree();
		break;
	case 3:
		LoadLevelFour();
		break;
	case 4:
		LoadLevelFive();
		break;
	case 5:
		LoadLevelSix();
		break;
	case 6:
		LoadLevelSeven();
		break;
	case 7:
		LoadLevelEight();
		break;
	case 8:
		LoadLevelNine();
		break;
	case 9:
		LoadLevelTen();
		break;
	case 10:
		LoadLevelEleven();
		break;
	case 11:
		LoadLevelTwelve();
		break;
	case 12:
		LoadLevelThirteen();
		break;
	case 13:
		LoadLevelFourteen();
		break;
	case 14:
		LoadLevelFifteen();
		break;
	}

	/*

	if(i == -1)
	{
		//empty
		m_crates.clear();
		m_bushes.clear();
		m_rockshrooms.clear();
		m_trees.clear();
		m_platforms.clear();

		//set m_levelMap to the current level
		for(int i = 0; i < levelSizeY; i++)
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = levelMainMenu[i][j];
	}
	else if(i == 0)
	{
		//empty
		m_crates.clear();
		m_bushes.clear();
		m_rockshrooms.clear();
		m_trees.clear();
		m_platforms.clear();

		//set m_levelMap to the current level
		for(int i = 0; i < levelSizeY; i++)
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level1[i][j];

		//pushback moving platforms
		for(int i = 0; i < levelSizeY; i++)
		{
			for(int j = 0; j < levelSizeX; j++)
			{
				if(m_levelMap[i][j] == 900)
				{
					Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 901)
				{
					Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 902)
				{
					Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 903)
				{
					Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 904)
				{
					Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 905)
				{
					Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
			}
		}

		//populate with crates
		Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(8*64, 6*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(6*64, 6*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(6*64, 5*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		//populate map with trees, rocks, shrooms, whatever
		sf::Sprite *tree1 = new sf::Sprite(); tree1->setTexture(m_treesTexture); tree1->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree1->setPosition(7*64, 6*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree1);

		sf::Sprite *rockshroom1 = new sf::Sprite; rockshroom1->setTexture(m_rockshroomsTexture); rockshroom1->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom1->setPosition(7*64, 6*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom1);

		sf::Sprite *bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(0, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
		bush1->setPosition(9*64, 6*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);
	}
	else if(i == 1)
	{
		//empty
		m_crates.clear();
		m_bushes.clear();
		m_rockshrooms.clear();
		m_trees.clear();
		m_platforms.clear();

		//set m_levelMap to the current level
		for(int i = 0; i < levelSizeY; i++)
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level2[i][j];

		//pushback moving platforms
		for(int i = 0; i < levelSizeY; i++)
		{
			for(int j = 0; j < levelSizeX; j++)
			{
				if(m_levelMap[i][j] == 900)
				{
					Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 901)
				{
					Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 902)
				{
					Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 903)
				{
					Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 904)
				{
					Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 905)
				{
					Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
			}
		}

		//no crates this map

		//populate map with trees, rocks, shrooms, whatever
		sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(0*64 - 14, 3*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(2*64 - 12, 7*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(18*64, 6*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(9*64, 8*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(0*64, 3*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(0*64, 12*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(1*64, 12*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(18*64 + 6, 6*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		sf::Sprite *bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(0, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
		bush1->setPosition(9*64 + 12, 8*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);
	}
	else if(i == 2)
	{
		//empty
		m_crates.clear();
		m_bushes.clear();
		m_rockshrooms.clear();
		m_trees.clear();
		m_platforms.clear();

		//set m_levelMap to the current level
		for(int i = 0; i < levelSizeY; i++)
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level3[i][j];

		//for platforms
		for(int i = 0; i < levelSizeY; i++)
		{
			for(int j = 0; j < levelSizeX; j++)
			{
				if(m_levelMap[i][j] == 900)
				{
					Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 901)
				{
					Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 902)
				{
					Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 903)
				{
					Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 904)
				{
					Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 905)
				{
					Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
			}
		}

		//push back crates
		Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(0*64, 6*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(3*64, 6*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(2*64, 6*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(2*64, 5*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(17*64, 6*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(17*64, 5*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(17*64, 4*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(24*64, 6*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		//populate map with trees, rocks, shrooms, whatever
		sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(2*64, 6*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(7*64, 3*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(18*64, 6*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(2*64, 6*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(18*64, 6*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(14*64, 6*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		sf::Sprite *bush1 = new sf::Sprite; bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(0, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
		bush1->setPosition(7*64 + 12, 3*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);

		bush1->setTexture(m_bushesTexture); bush1->setTextureRect(sf::IntRect(m_bushesTexture.getSize().x*3/4, 0, m_bushesTexture.getSize().x/4, m_bushesTexture.getSize().y));
		bush1->setPosition(9*64 + 12, 6*64 - m_bushesTexture.getSize().y); m_bushes.push_back(*bush1);
	}
	else if(i == 3)
	{
		//empty
		m_crates.clear();
		m_bushes.clear();
		m_rockshrooms.clear();
		m_trees.clear();
		m_platforms.clear();

		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level4[i][j];

		//for platforms
		for(int i = 0; i < levelSizeY; i++)
		{
			for(int j = 0; j < levelSizeX; j++)
			{
				if(m_levelMap[i][j] == 900)
				{
					Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 901)
				{
					Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 902)
				{
					Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 903)
				{
					Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 904)
				{
					Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 905)
				{
					Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
			}
		}

		//push back crates
		Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(6*64, 3*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(12*64, 3*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(2*64, 6*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		//populate map with trees, rocks, shrooms, whatever
		sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(1*64, 3*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(18*64, 8*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(2*64, 3*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(18*64, 8*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(3*64, 14*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);
	}
	else if(i == 4)
	{
		//empty
		m_crates.clear();
		m_bushes.clear();
		m_rockshrooms.clear();
		m_trees.clear();
		m_platforms.clear();

		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level5[i][j];

		//pushback moving platforms
		for(int i = 0; i < levelSizeY; i++)
		{
			for(int j = 0; j < levelSizeX; j++)
			{
				if(m_levelMap[i][j] == 900)
				{
					Platform *p = new Platform((j) * m_size.x, (j) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 901)
				{
					Platform *p = new Platform((j - 1) * m_size.x, (j + 1) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 902)
				{
					Platform *p = new Platform((j - 2) * m_size.x, (j + 2) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 903)
				{
					Platform *p = new Platform((j - 3) * m_size.x, (j + 3) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 904)
				{
					Platform *p = new Platform((j - 4) * m_size.x, (j + 4) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
				else if(m_levelMap[i][j] == 905)
				{
					Platform *p = new Platform((j - 5) * m_size.x, (j + 5) * m_size.x, sf::Vector2f(j * m_size.x, i * m_size.y));
					m_platforms.push_back(*p);
				}
			}
		}

		//push back crates
		Crate *crate = new Crate; crate->SetPosition(sf::Vector2f(2*64, 15*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(9*64, 13*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(9*64, 14*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(21*64, 7*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(7*64, 5*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(7*64, 4*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		crate = new Crate; crate->SetPosition(sf::Vector2f(15*64, 1*64 - crate->GetSize().y));
		m_crates.push_back(*crate);

		//populate map with trees, rocks, shrooms, whatever
		sf::Sprite *tree = new sf::Sprite(); tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(1*64, 15*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(16*64 - 13, 15*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(15*64, 15*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(0, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(18*64, 8*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		tree->setTexture(m_treesTexture); tree->setTextureRect(sf::IntRect(m_treesTexture.getSize().x/2, 0, m_treesTexture.getSize().x/2, m_treesTexture.getSize().y));
		tree->setPosition(8*64, 5*64 - m_treesTexture.getSize().y); m_trees.push_back(*tree);

		sf::Sprite *rockshroom = new sf::Sprite; rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(14*64, 15*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(16*64, 15*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(0, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(18*64, 8*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);

		rockshroom->setTexture(m_rockshroomsTexture); rockshroom->setTextureRect(sf::IntRect(m_rockshroomsTexture.getSize().x*2/3, 0, m_rockshroomsTexture.getSize().x/3, m_rockshroomsTexture.getSize().y));
		rockshroom->setPosition(3*64, 15*64 - m_rockshroomsTexture.getSize().y); m_rockshrooms.push_back(*rockshroom);
	}
	else if(i == 5)
	{
		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level6[i][j];
	}
	else if(i == 6)
	{
		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level7[i][j];
	}
	else if(i == 7)
		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level8[i][j];
	else if(i == 8)
		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level9[i][j];
	else if(i == 9)
		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level10[i][j];
	else if(i == 10)
		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level11[i][j];
	else if(i == 11)
		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level12[i][j];
	else if(i == 12)
		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level13[i][j];
	else if(i == 13)
		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level14[i][j];
	else if(i == 14)
		for(int i = 0; i < levelSizeY; i++) //set m_levelMap to the current level
			for(int j = 0; j < levelSizeX; j++)
				m_levelMap[i][j] = level15[i][j];

	*/
}

Tilemap::Tilemap(sf::RenderWindow &window)
{
	m_size = sf::Vector2f(64, 64);

	m_texture.loadFromFile("Assets/tileMap.png");
	m_sprite.setTexture(m_texture);

	m_treesTexture.loadFromFile("Assets/trees.png");
	m_rockshroomsTexture.loadFromFile("Assets/rockshrooms.png");
	m_bushesTexture.loadFromFile("Assets/bushes.png");

	m_level = 0; //set map to 0
	setMap(m_level, window);

	m_loadingScreenTexture.loadFromFile("Assets/loadingScreen.png");
	m_loadingScreen.setTexture(m_loadingScreenTexture);
	m_loadingScreen.setTextureRect(sf::IntRect(0, 0, 2000, 2000));

	m_loadingText.setTexture(m_loadingScreenTexture);
	m_loadingText.setTextureRect(sf::IntRect(0, 2001, 340, 56));
}

void Tilemap::Update(sf::Time &deltaTime, sf::RenderWindow &window)
{
	for(int i = 0; i < m_platforms.size(); i++)
	{
		m_platforms[i].Update();
		m_platforms[i].Move(deltaTime);
	}

	deleted:
	for(int i = 0; i < m_crates.size(); i++)
	{
		m_crates[i].Update(deltaTime, m_levelMap, m_platforms);
		if(m_crates[i].getBottom() > 40*64)
		{
			m_crates.erase(m_crates.begin() + i);
			goto deleted;
		}
		CrateCrateCollision(window);
	}

}

void Tilemap::Draw(sf::RenderWindow &window)
{
	for(int i = 0; i < levelSizeY; i++)
	{
		for(int j = 0; j < levelSizeX; j++)
		{
			if(m_levelMap[i][j] == 000) //nothing
				continue;

			else if(m_levelMap[i][j] == 100 || m_levelMap[i][j] == 190) //top ground blocks
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 0, 0, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 101 || m_levelMap[i][j] == 191)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 1, 0, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 102 || m_levelMap[i][j] == 192)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 2, 0, m_size.x, m_size.y));

			else if(m_levelMap[i][j] == 200 || m_levelMap[i][j] == 290) //middle ground blocks
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 0, m_size.y * 1, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 201 || m_levelMap[i][j] == 291)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 1, m_size.y * 1, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 202 || m_levelMap[i][j] == 292)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 2, m_size.y * 1, m_size.x, m_size.y));

			else if(m_levelMap[i][j] == 300 || m_levelMap[i][j] == 390) //bottom ground blocks
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 0, m_size.y * 2, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 301 || m_levelMap[i][j] == 391)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 1, m_size.y * 2, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 302 || m_levelMap[i][j] == 392)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 2, m_size.y * 2, m_size.x, m_size.y));

			else if(m_levelMap[i][j] == 400 || m_levelMap[i][j] == 490) //lead off blocks
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 0, m_size.y * 3, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 401 || m_levelMap[i][j] == 491)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 1, m_size.y * 3, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 402 || m_levelMap[i][j] == 492)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 2, m_size.y * 3, m_size.x, m_size.y));

			else if(m_levelMap[i][j] == 500 || m_levelMap[i][j] == 590) //lead off grass ground blocks
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 0, m_size.y * 4, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 501 || m_levelMap[i][j] == 591)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 1, m_size.y * 4, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 502 || m_levelMap[i][j] == 592)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 2, m_size.y * 4, m_size.x, m_size.y));

			else if(m_levelMap[i][j] == 600) //platform blocks
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 0, m_size.y * 5, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 601)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 1, m_size.y * 5, m_size.x, m_size.y));
			else if(m_levelMap[i][j] == 602)
				m_sprite.setTextureRect(sf::IntRect(m_size.x * 2, m_size.y * 5, m_size.x, m_size.y));

			else if(m_levelMap[i][j] == 999) //portal
				m_sprite.setTextureRect(sf::IntRect(0, m_size.y * 6, m_size.x, m_size.y));

			else
				continue;

			m_sprite.setPosition(j * m_size.x, i * m_size.y);

			window.draw(m_sprite);

			for(int i = 0; i < m_platforms.size(); i++)
				m_platforms[i].Draw(window);
			for(int i = 0; i < m_trees.size(); i++)
				window.draw(m_trees[i]);
			for(int i = 0; i < m_rockshrooms.size(); i++)
				window.draw(m_rockshrooms[i]);
			for(int i = 0; i < m_bushes.size(); i++)
				window.draw(m_bushes[i]);
			for(int i = 0; i < m_crates.size(); i++)
				m_crates[i].Draw(window);
		}
	}
}