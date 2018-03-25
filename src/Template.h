#pragma once
class Template
{
public:
	Template();
	Template(int posX, int posY, int dir);
	virtual ~Template();
	void setPosX(const int& posX);
	const int &getPosX() const;
	void setPosY(const int& posY);
	const int &getPosY() const;
	void setDir(const int& dir);
	const int &getDir() const;
private:
	int posX_;
	int posY_;
	int dir_;
};

