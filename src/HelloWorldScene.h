#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "HRocker.h"
#include "Hero.h"
#include "ControlButton.h"
#include "Map.h"
#include "ProgressView.h" 
#include "Monster.h"
#include "SkillButton.h"
class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
	//ÿ֡����ʱ���õ��¼�
	virtual void update(float delta);
	//������ײ���
	bool isRectCollision (CCRect rect1, CCRect rect2);
	//��ͣ����
	void  menuPauseCallback(CCObject* pSender);	

private:
	 HRocker* rocker;//ҡ��
	 Hero*    hero;///����
	 ControlButton* btn;//��ť�ؼ�����
	 Map*     mymap;//��ͼ  
	 ProgressView *m_pProgressView;  //Ѫ��
	 Monster *monster1;//��������1
	 SkillButton* btn_skill;//���ܰ�ť
};

#endif // __HELLOWORLD_SCENE_H__
