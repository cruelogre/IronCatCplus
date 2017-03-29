#ifndef __ROLLINGROLEMENU_H__
#define __ROLLINGROLEMENU_H__

#include "cocos2d.h"
USING_NS_CC;

class RollingRoleMenu : public Layer {
public:
	CREATE_FUNC(RollingRoleMenu);
	void addMenuItem(MenuItem* item);
	void updatePosition();
	void updatePositionWithAnimation();
	//位置矫正 修改位置forward为移动方向 当超过1/3,进1
	void rectify(bool forward);
	virtual bool init();
	//重置 显示所引号设置为0
	void reset();
private:
	//设置当前显示索引
	void setIndex(int index);
	//设置当前显示菜单项的索引号
	float getIndex();
	//返回被选中的item
	MenuItem* getCurrentItem();
	//公式 width * index / (abs(index) + CALC_A),CALC_A为常数
	float calcFunction(float index, float width);
private:
	//菜单项的索引号
	float _index;
	//上一次菜单项的索引号
	float _lastIndex;
	//菜单项集合，_children顺序会变化，新建数组保存顺序
	Vector<cocos2d::MenuItem*> _items;
	//监听函数
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	//动画完结调用函数，确定哪一个菜单在前面
	void actionEndCallback(float dx);
	//当前被选择的item
	MenuItem* _selectedItem;
};

#endif
