#pragma once

#include "CScene.h"

class CStage02 : public CScene
{
public:
	CStage02();
	virtual ~CStage02();

public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;
	void Release() override;

public:


private:

};

