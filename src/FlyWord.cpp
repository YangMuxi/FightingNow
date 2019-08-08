#include "FlyWord.h"
FlyWord* FlyWord::create(const char *word,const int fontSize,CCPoint begin){

	FlyWord* ret = new FlyWord();
	//����д����ȫһЩ
	if(ret && ret->init(word,fontSize,begin)){
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);//��ȫɾ��
	return nullptr;
}

bool FlyWord::init(const char *word,const int fontSize,CCPoint begin){
	if(!CCNode::init()){
		return false;
	}
	//��ʼ��
	_begin = begin;
	m_plabel = CCLabelTTF::create(word,"Marker Felt",fontSize);

	//������ɫ
	ccColor3B RGB;
	RGB.r=255;
	RGB.g=0;
	RGB.b=0;
	m_plabel->setColor(RGB);

	this->addChild(m_plabel);
	this->setPosition(ccp(begin.x,begin.y));
	//��ʼ����ɺ�Ϳ�ʼƮ����
	Flying();
	return true;
}

//���ִ��µ���Ʈ��
void FlyWord::Flying()
{
	
	CCMoveBy* moveact=CCMoveBy::create(0.5f,CCPointMake(0,70));//0.5�������ƶ�70

	//�����ص�����������Ʈ�����
	CCCallFunc* callFunc=CCCallFunc::create(this,callfunc_selector(FlyWord::Flyend));
	//������������
	CCActionInterval* act=CCSequence::create(moveact,callFunc,NULL);
	//setVisible(true);
	this->runAction(act);


}
//����Ʈ����ɾ�����ж���
void FlyWord::Flyend()
{
	//���֮��Ѹö�����ڴ���ɾ����
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParentAndCleanup(true);
}