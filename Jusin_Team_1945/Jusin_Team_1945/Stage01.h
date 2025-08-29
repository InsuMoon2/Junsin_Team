#pragma once

#include "Scene.h"

class Stage01 : public Scene
{
public:
	Stage01();
	virtual ~Stage01();

public:
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

public:

private:


};

