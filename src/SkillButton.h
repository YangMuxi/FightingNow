#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT; 
class SkillButton:public cocos2d::CCLayer{
public:
	//������ȴ���ܰ�ť,create �� init ������һ���,����create��ʱ���Ȼ�����init
	static SkillButton* create(const char* fore_name,const char* back_name);
	//��ʼ����ť
	bool init(const char* fore_name,const char* back_name);

	//��ʼ��ȴ����
	void BeginSkill();
	//��ȴ���ܽ�����
	void EndSkill();
	//�ж��Ƿ�����ȴ����
	bool IsSkilling;

	//��ʼ����
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);  
	//��������
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent); 
	///ע�ᴥ������֧��
	void registerWithTouchDispatcher(); 



private:
	CCSprite *fore;//fore�ǽ�����ͼƬ  
	CCSprite *back;//back�ǽϰ���ͼƬ  
	CCProgressTimer *pt;//����Ч��
	

};