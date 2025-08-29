#pragma once

#include "Scene.h"

class Stage02 : public Scene
{
public:
	Stage02();
	virtual ~Stage02();

public:
	void Initialize() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

public:


private:

};

