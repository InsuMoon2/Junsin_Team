#pragma once

#include "CScene.h"

class CStage03 : public CScene
{
public:
	CStage03();
	virtual ~CStage03();

public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;
	void Release() override;

};

