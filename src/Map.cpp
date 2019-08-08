#include "Map.h"
Map::Map():m_map(NULL)
{

}
Map::~Map()
{

}
void Map::InitMap(const char *map_name,const CCSize &window_size)
{
	this->m_map=CCSprite::create(map_name);
	m_map->setAnchorPoint(ccp(0,0));//����ê��
	this->setAnchorPoint(ccp(0,0));//����ê��
	this->addChild(m_map);



}
void Map::MoveMap(CCNode *hero,CCSize visibleSize)//
{
	if(hero->getPositionX()==visibleSize.width/2)//�����˶����м䣬��ͼ���ƶ�
	{
		if(this->getPositionX()!=-(m_map->getContentSize().width-visibleSize.width))//��ֹ��ͼ����˶��󳬳���Ե
		this->setPosition(this->getPositionX()-1,this->getPositionY());
	}
}
bool Map::JudgeMap(CCNode *hero,CCSize visibleSize)
{
	if(this->getPositionX()!=-(m_map->getContentSize().width-visibleSize.width))//��ֹ��ͼ����˶��󳬳���Ե
		return false;
	else //��ͼ�Ѿ��ƶ������Ե
	return true;
}

