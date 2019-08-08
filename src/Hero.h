#ifndef __HERO_H__
#define __HERO_H__
#include "cocos2d.h"
using namespace cocos2d;
 class Hero:public cocos2d::CCNode
 {
 public:
	   Hero(void);
	  ~Hero(void);
	 //����ͼƬ������Ӣ��
	 void InitHeroSprite(char *hero_name);
	 //���ص�ǰӢ��
	 CCSprite* GetSprite();

	 //���ö���,numΪͼƬ��Ŀ��run_directonΪ����������false����,name_eachΪname_png��ÿһС��ͼƬ�Ĺ������Ʋ���
	 void SetAnimation(const char *name_each,const unsigned int num,bool run_directon);
	//ֹͣ����
	 void StopAnimation();

	 //��������
	 void AttackAnimation(const char *name_each,const unsigned int num,bool run_directon);
	 //������������
	 void AttackEnd();
	 //�ж�Ӣ���Ƿ��˶����˴��ڵ��м�λ��,visibleSizeΪ��ǰ���ڵĴ�С  
	 bool JudgePositona(CCSize visibleSize);  

	 //������Ч
	 void SkillAmiation(CCObject * object);//ע��Ҫ�в�������Ϊ�ǹ۲���ģʽ�ĵ��ú�����Ҫ������ʾ������ת����: �޷��ӡ�void (__thiscall Hero::* )(void)��ת��Ϊ��cocos2d::SEL_CallFuncO��




	//�ж��Ƿ����ܶ���
	 bool IsRunning;
	 //�ж��Ƿ��ڹ�������
	 bool IsAttack;
	 //Ӣ���˶��ķ���
	 bool HeroDirecton;

	 

	 CREATE_FUNC(Hero);
 private:
	 CCSprite* m_HeroSprite;//����
	 char *Hero_name;//���������ʼ״̬�ľ���ͼƬ����
 };
#endif // __HERO_H__