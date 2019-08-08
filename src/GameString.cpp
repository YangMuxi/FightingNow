#include "GameString.h"
CCScene* GameString::scene()
{
    CCScene *scene = CCScene::create();
    GameString *layer = GameString::create();
    scene->addChild(layer);
    return scene;
}
bool GameString::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	//�Ӹ���ť
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"exct.png",
		"exct.png",
		this,
		menu_selector(GameString::menuCloseCallback));

	pCloseItem->setPosition(ccp( visibleSize.width -80 ,visibleSize.height-60));
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);


  //�ӱ���
    CCSprite* pSprite = CCSprite::create("enter.png");
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);


	//����Ҫ��ʾ������
	CCLabelTTF* pLabel=CCLabelTTF::create(ChineseString::GBKToUTF8("�����ֱ���Evankaka����\n������Ϸ������Ҫ�񶷡�\n��ӭ�����ҵ����硫����\n�����ֱ���Evankaka����\n������Ϸ������Ҫ�񶷡�\n��ӭ�����ҵ����硫����\n�����ֱ���Evankaka����\n������Ϸ������Ҫ�񶷡�"),"Arial",25);
	pLabel->setAnchorPoint(CCPointZero);
	ccColor3B color = ccc3(255,255,0);
	pLabel->setColor(color);
	pLabel->setPosition(ccp(50, -200));//Y��ע��Ϊ��,X���Ӧ�����point[4]��50�������Ƕ���

	//���Ʋü�����
	CCDrawNode* shap = CCDrawNode::create();
	CCPoint point[4] = {ccp(50,0), ccp(400,0), ccp(400,200), ccp(50,200)};//���Ը��������ʵ��޸��´�С
	shap->drawPolygon(point,4,ccc4f(255,255,255,255),0, ccc4f(255,255,255,255));//�����ı���


	////��������
	CCClippingNode* pClip = CCClippingNode::create();
	pClip->setInverted(false);
	pClip->setStencil(shap);//һ��Ҫ�У�Ҫ���ᱨ��
	pClip->addChild(pLabel);
	this->addChild(pClip);
	
	//��ʼ����Ļ������
	CCMoveBy* moveact=CCMoveBy::create(10.0f,CCPointMake(0,400));//0.5�������ƶ�70
	CCCallFunc* callFunc=CCCallFunc::create(this,callfunc_selector(GameString::RollEnd));//�����ص�����������Ʈ�����
	CCActionInterval* act=CCSequence::create(moveact,callFunc,NULL);//������������
	pLabel->runAction(act);

    return true;
}

void GameString::RollEnd()
{
CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());//������Ϸ������
}

void GameString::menuCloseCallback(CCObject* pSender)
{
	RollEnd();
}


