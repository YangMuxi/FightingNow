#ifndef __GameString_SCENE_H__
#define __GameString_SCENE_H__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "ChineseString.h"
#include "HelloWorldScene.h"//������Ϸ�����ͷ�ļ�
USING_NS_CC;
USING_NS_CC_EXT;
class GameString : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameString);
	//��Ļ������ɺ����
	void RollEnd();
	//������ť���¼�
	void menuCloseCallback(CCObject* pSender);
};

#endif // __GameString_SCENE_H__
