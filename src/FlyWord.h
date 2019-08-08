#ifndef __FLYWORD_H__
#define __FLYWORD_H__
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT; 
class FlyWord: public CCNode{
public:

	//��������Ʈ��,create �� init ������һ���,����create��ʱ���Ȼ�����init
	static FlyWord* create(const char *word,const int fontSize,CCPoint begin);
	//init��������3���������ֱ���Ʈ����ַ����������С�������￪ʼƮ��,init������������Ҫ�ǳ�ʼ��FloatWord���õ�Label
	bool init(const char *word,const int fontSize,CCPoint begin);

	//���ִ��µ���Ʈ��
	void Flying();
	//����Ʈ����ɾ�����ж���
	void Flyend();
private:
	int _fontSize;//�����С
	CCPoint _begin;//Ҫ��ӵ��Ĺ�������ĵ�
	CCLabelTTF* m_plabel;//��������

};
#endif // __FLYWORD_H__
