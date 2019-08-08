#include "SkillButton.h"
SkillButton* SkillButton::create(const char* fore_name,const char* back_name){

	SkillButton* ret = new SkillButton();

	//����д����ȫһЩ
	if(ret&&ret->init(fore_name,back_name)){
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);//��ȫɾ��
	return nullptr;
}
bool SkillButton::init(const char* fore_name,const char* back_name)
{
	if(!CCLayer::init()){
		return false;
	}

	this->setTouchEnabled(true);//��������
	fore=CCSprite::create(fore_name);//fore_name�ǽ�����ͼƬ 
	this->addChild(fore,1);  

	back=CCSprite::create(back_name);//back_name�ǽϰ���ͼƬ  
	pt=CCProgressTimer::create(back);
	this->addChild(pt,2);  
	
	IsSkilling=false;
	
	return true;

}
//��ʼ��ȴ����
void SkillButton::BeginSkill()
{
	if(IsSkilling)
		return;
	//תȦ��CDʵ��  
	pt->setType(cocos2d::CCProgressTimerType(kCCProgressTimerTypeRadial)); 
	CCProgressTo *waittime=CCProgressTo::create(8,100);
	//�����ص�������������ȴ���������EndSkill()
	CCCallFunc* callFunc=CCCallFunc::create(this,callfunc_selector(SkillButton::EndSkill));
	//������������
	CCActionInterval* act=CCSequence::create(waittime,callFunc,NULL);
	pt->setVisible(true);
	IsSkilling=true;
	pt->runAction(act); 
	//��һ����������Ϣ�����֣��ڶ���������CCObject * ���͵���Ϣֵ��Ҳ������Ҫ���͵Ķ���
	CCNotificationCenter::sharedNotificationCenter()->postNotification("MessageSkill",NULL);

}
//��ȴ���ܽ�����
void SkillButton::EndSkill()
{
	pt->setVisible(false);
	IsSkilling=false;
}

//�ж��Ƿ����ķ�ΧΪ���� �������ִ�ж���  
void SkillButton::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)  
{  
	if(IsSkilling)
		return;
	//�ж��Ƿ����ھ�������
	CCPoint touchPoint = convertTouchToNodeSpace(pTouch);  
	if(fore->boundingBox().containsPoint(touchPoint))  
	{  

		BeginSkill();
	}  
}  

//����true��ʾ֧�ִ��� ����false��ʾ����   
bool SkillButton::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)  
{  
	return true;  
} 
///ע�ᴥ������֧��,���еڶ�������Ϊ��������Ӧ�ȼ� ֵԽС ��Ӧ�ȼ�Խ��  
void SkillButton::registerWithTouchDispatcher()  
{  
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);//true��ʾֻ�е�ǰ���ܽ�ȡ�������¼�
}




