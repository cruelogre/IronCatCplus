﻿#ifndef __ROLE__UPLV__DIALOG__H__
#define __ROLE__UPLV__DIALOG__H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
using namespace std;
using namespace ui;
using namespace cocostudio;

class RoleUpLvDialog : public Layer
{
	Label* m_bfDescribe;   //升级描述
	TextBMFont* m_bfExp;		//经验文本
	TextAtlas* m_bfLv;			//经验等级	

	LoadingBar* m_lbExp;		//进度条经验
	Sprite* m_imageRow[3];

	int m_curLv;
	float m_exp;
	float m_maxExp;
	float m_addExp;
	std::function<void()> closefunc;
public:
	RoleUpLvDialog();
	static RoleUpLvDialog* create(int addExp, std::function<void()> closeCB = nullptr);
	virtual bool init(int addExp);
	virtual void update(float delta);
	void setLvText();
	void setLBPercent(float t);
	
};




#endif 