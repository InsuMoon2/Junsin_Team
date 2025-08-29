#pragma once

class Scene
{
public:
	Scene();
	virtual ~Scene();

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;

protected:

};
