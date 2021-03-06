﻿#ifndef __PROMPT_LAYER__H__
#define __PROMPT_LAYER__H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace std;
using namespace ui;
using namespace cocostudio;

//提示类型
enum PROMPT_TYPE
{
	BUY_GOLD,
	BUY_FISH,
	BUY_MINT,
	WEAR_WEAPON,
	LV_NOT_REACH	//等级不足
};

//提示界面
class PromptLayer : public Layer
{
private:
	PROMPT_TYPE m_Type;
	Button* m_CloseBt;
	Button* m_SureBt;
public:
	static PromptLayer* create(PROMPT_TYPE type, string desc);
	bool init(PROMPT_TYPE type, string desc);
	void onEnter();
	void onExit();
	void buttonHandle(Ref* pSender, TouchEventType type);
};

#endif 