#pragma once

class Npc
{
public:
	Npc() = default;
	~Npc() = default;

	virtual void Render() = 0;
};