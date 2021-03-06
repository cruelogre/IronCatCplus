﻿#ifndef __GAMEMAIN_SCENE_H__
#define __GAMEMAIN_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "StarsView.h"
#include "NodeMsg.h"
#include "PayCBDelegate.h"
USING_NS_CC;
using namespace ui;
using namespace std;
using namespace cocostudio;

#define GAMEMANISCENETIP "GAME_MANI_SCENE_TIP"	//主场景资源显示更新


class GameMainScene : public Layer ,public NodeMsg,public EfficiencyDelegate
{
public:
	GameMainScene();
	static Scene* createScene();
	CREATE_FUNC(GameMainScene);
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	void onEnterTransitionDidFinish() override;
	void updateTopLayer();
	void itemCallBack(Integer* sid);
	void childCloseCB(const std::string& childName);
	void queryBack(const std::vector<EfficiencyValue>& effvalues);
	void querySelfBack(const EfficiencyValue& evalue);
	void update(float delta);
private:

	int m_CurStarSid;
	Node* m_MyCsb;					//csb

	Button* m_ShopBt;				//商店 按钮
	Button* m_WeaponBt;				//武器 按钮
	Button* m_CatHomeBt;			//喵屋 按钮
	Button* m_SetingBt;				//设置 按钮
	Button* m_SignBtn;				//签到 按钮

	TextBMFont* m_videoInfo; //视频按钮下边的提示字
	Sprite* m_videoSp; //视频按钮下边的图片
	TextBMFont* m_LvText;			//玩家等级 文本
	TextBMFont* m_ExpText;			//经验数量 文本
	LoadingBar* m_ExpBar;
	StarsView* m_StarsView;

	void updateGiftBag();
	virtual const char* getClassName(){ return "GameMainScene"; }
	virtual void exeMsg(MsgType type, int data, cocos2d::Ref * pob);
	static bool isFirstEnterMain;

	//播放视频
	void updateVideoDot();

	Armature * m_heidong;
	void callHeidong();
	void callLiuXing();
	void callYunshi();

	void lazyInit();
};

#endif 