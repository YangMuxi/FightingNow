#ifndef __GameAbout_SCENE_H__
#define __GameAbout_SCENE_H__
#include "cocos2d.h"

#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace gui;//�ص�Ҫ�ǵã�Ҫ�������error C2065: ��SEL_TouchEvent��: δ�����ı�ʶ��
class GameAbout : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameAbout);

	//���ؿ�ʼ����Ļص��¼�
	void TouchBackLoginButton(cocos2d::CCObject* obj,gui::TouchEventType type);
};

#endif // __GameAbout_SCENE_H__
