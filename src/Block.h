#pragma once
class Block
{
public:
	Block(int posX, int posY);
	~Block();
	void setPosX(const int& posX);
	const int &getPosX() const;
	void setPosY(const int& posY);
	const int &getPosY() const;
private:
	int posX_;
	int posY_;
};

