#include "Hero.h"
USING_NS_CC; 
Hero::Hero(void)
{
	IsRunning=false;//û�ڷŶ���
	HeroDirecton=false;//�����˶�
	Hero_name=NULL;
	IsAttack=false;
	m_HeroSprite=NULL;
}

Hero::~Hero(void)
{
	//ע�����һ��Ҫ�ͷ���Ϣ����������й¶
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this,"MessageSkill");
}
 void Hero::InitHeroSprite(char *hero_name)
 {
	Hero_name=hero_name;
	this->m_HeroSprite=CCSprite::create(hero_name);
	this->addChild(m_HeroSprite);

	//ע��MessageSkill��������յ��ˣ�ִ��SkillAmiation
	CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(Hero::SkillAmiation),"MessageSkill",NULL);
 }
 void Hero::SetAnimation(const char *name_each,unsigned int num,bool run_directon)
 {
	 if(HeroDirecton!=run_directon)
	 {   HeroDirecton=run_directon;
	     m_HeroSprite->setFlipX(run_directon);
	 }
	 if(IsRunning)
		 return;
	 CCAnimation* animation = CCAnimation::create();  
	 for( int i=1;i<=num;i++)  
	 {  
		 char szName[100] = {0};  
		 sprintf(szName,"%s%d.png",name_each,i);  
		 animation->addSpriteFrameWithFileName(szName); //���ض�����֡  
	 }  
	 animation->setDelayPerUnit(0.1f);  
	 animation->setRestoreOriginalFrame(true);  
	 animation->setLoops(-1); //����ѭ��
	 if(HeroDirecton!=run_directon)
	 {   HeroDirecton=run_directon;

	 }
	 //��������װ��һ������
	 CCAnimate* act=CCAnimate::create(animation);
	
	 m_HeroSprite->runAction(act);
	 IsRunning=true;

 }
 void Hero::StopAnimation()
 {
	 if(!IsRunning)
		 return;
	m_HeroSprite->stopAllActions();//��ǰ����ֹͣ���ж���

	//�ָ�����ԭ���ĳ�ʼ����ͼ 
	this->removeChild(m_HeroSprite,TRUE);//��ԭ���ľ���ɾ����
	m_HeroSprite=CCSprite::create(Hero_name);//�ָ�����ԭ������ͼ����
	m_HeroSprite->setFlipX(HeroDirecton);
	this->addChild(m_HeroSprite);
	IsRunning=false;
 }
  void Hero::AttackAnimation(const char *name_each,const unsigned int num,bool run_directon)
  {
	  if(IsAttack)
		  return;
	  IsAttack=true;
	  CCAnimation* animation = CCAnimation::create();  
	  for( int i=1;i<=num;i++)  
	  {  
		  char szName[100] = {0};  
		  sprintf(szName,"%s%d.png",name_each,i);  
		  animation->addSpriteFrameWithFileName(szName); //���ض�����֡  
	  }  
	  animation->setDelayPerUnit(0.05f);  
	  animation->setRestoreOriginalFrame(true);  
	  animation->setLoops(1); //����ѭ��
	  if(HeroDirecton!=run_directon)
	  {   HeroDirecton=run_directon;

	  }
	  //��������װ��һ������
	  CCAnimate* act=CCAnimate::create(animation);


	  //�����ص��������������������AttackEnd()
	  CCCallFunc* callFunc=CCCallFunc::create(this,callfunc_selector(Hero::AttackEnd));
	  //������������
	 CCActionInterval* attackact=CCSequence::create(act,callFunc,NULL);
	  
	  m_HeroSprite->runAction(attackact); 

  }
  void Hero::AttackEnd()
  {
	  m_HeroSprite->setFlipX(HeroDirecton);
	   IsAttack=false;
  }
  bool Hero::JudgePositona (CCSize visibleSize)
  {
	  if(this->getPositionX()!=visibleSize.width/2)//���鵽�����
		  return false;
	  else
		  return true;//�����м�λ��
  }
CCSprite* Hero::GetSprite()
{
	return m_HeroSprite;
}

//������Ч
void Hero::SkillAmiation(CCObject * object)
{

	m_HeroSprite->stopAllActions();//��ǰ����ֹͣ���ж���
	CCAnimation* animation = CCAnimation::create();  
	for( int i=1;i<=6;i++)  
	{  
		char szName[100] = {0};  
		sprintf(szName,"skill_%d.png",i);  
		animation->addSpriteFrameWithFileName(szName); //���ض�����֡  
	}  
	animation->setDelayPerUnit(0.1f);  
	animation->setRestoreOriginalFrame(true);  
	animation->setLoops(5); //����ѭ��
	//��������װ��һ������
	CCAnimate* act=CCAnimate::create(animation);

	//�����ص��������������������AttackEnd()
	CCCallFunc* callFunc=CCCallFunc::create(this,callfunc_selector(Hero::AttackEnd));
	//������������
	CCActionInterval* skillattack=CCSequence::create(act,callFunc,NULL);
	 IsAttack=true;
	m_HeroSprite->runAction(skillattack);

}