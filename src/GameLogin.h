#ifndef __GameLogin_SCENE_H__
#define __GameLogin_SCENE_H__
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace gui;//�ص�Ҫ�ǵã�Ҫ�������error C2065: ��SEL_TouchEvent��: δ�����ı�ʶ��
class GameLogin : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameLogin);

	//��ʼ��Ϸ��ť�Ļص��¼�
	void TouchBeginButton(cocos2d::CCObject* obj,gui::TouchEventType type);
	//������Ϸ��ť�Ļص��¼�
	void TouchSetnButton(cocos2d::CCObject* obj,gui::TouchEventType type);
	//�˳���Ϸ��ť�Ļص��¼�
	void TouchExitButton(cocos2d::CCObject* obj,gui::TouchEventType type);
	//��������
	void TouchCheckMusic(cocos2d::CCObject* obj,gui::CheckBoxEventType type);


};

#endif // __GameLogin_SCENE_H__
