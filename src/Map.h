#ifndef __MAP_H__
#define __MAP_H__
#include "cocos2d.h"
USING_NS_CC; 
class Map:public CCNode
{
public:
	 Map();
	~Map();
	//��ʼ����ͼ,window_sizeoΪ����̨��С
	void InitMap(const char *map_name,const CCSize &window_size);
	//���ݾ����λ���ƶ���ͼ��visibleSizeΪ��ǰ���ڵĴ�С
	void MoveMap(CCNode *hero,CCSize visibleSize);
	//�жϵ�ͼ�Ƿ񵽴��Ե
	bool JudgeMap(CCNode *hero,CCSize visibleSize);
	//virtual void update(float delta);
	CREATE_FUNC(Map);
	
private:
	CCSprite *m_map;//��ͼ����

};
#endif // __MAP_H__