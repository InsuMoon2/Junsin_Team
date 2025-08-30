#pragma once

#include "CScene.h"

class CTempStage : public CScene
{
public:
	CTempStage();
	virtual ~CTempStage();

public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;
	void Release() override;

private:

};

