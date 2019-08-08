#include "HelloWorldScene.h"
#include "FlyWord.h"
#include "Gamepause.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "iconv/iconv.h"

USING_NS_CC;
USING_NS_CC_EXT; 

CCScene* HelloWorld::scene()
{

    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{

    if ( !CCLayer::init() )
    {
        return false;
    }
    //�õ����ڵĴ�С
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

   // �޸ı���ͼƬ,����Ϊ�Լ�����ĵ�ͼ
	mymap=Map::create();
	mymap->InitMap("12.png",visibleSize);
	this->addChild(mymap,0);//�����0��ʾ������ײ�
    
	//���ҡ��
	rocker = HRocker::createHRocker("Direction_bt.png","Direction_bc.png",ccp(110,60));//���е�һ��ͼƬΪҡ�˵İ�ť���ڶ���Ϊ����
	this->addChild(rocker,2);
	rocker->startRocker(false);//true��ʾֻ����Ӧ���Ĵ���


	//������ƾ���
	hero=Hero::create();
	hero->InitHeroSprite("hero.png");
	hero->setPosition(ccp(200,200));
	this->addChild(hero,1);
	
	//��ӹ�����ť
	btn=ControlButton::create();
	btn->CreateButton("bt.png");
	btn->setPosition(ccp(visibleSize.width-50,50));
	this->addChild(btn,2);

	//��Ӽ��ܰ�ť
	btn_skill=SkillButton::create("skill_back.png","skill_fore.png");
	btn_skill->setPosition(ccp(visibleSize.width-150,60));
	this->addChild(btn_skill,2);


	//����Ӣ�۵�Ѫ�� 
	m_pProgressView = new ProgressView();  
	m_pProgressView->setPosition(ccp(150, 450));  
	m_pProgressView->setScale(2.2f);  
	m_pProgressView->setBackgroundTexture("xue_back.png");  
	m_pProgressView->setForegroundTexture("xue_fore.png");  
	m_pProgressView->setTotalProgress(1000.0f);  
	m_pProgressView->setCurrentProgress(1000.0f); 
	//����������Ϊ����Ѫ�����úÿ�
	CCSprite *xuekuang=CCSprite::create("kuang.png");//���Ѫ���Ŀ��
	xuekuang->setPosition(ccp(m_pProgressView->getPositionX(),m_pProgressView->getPositionY()));
	CCSprite *touxiang=CCSprite::create("touxiang.png");//���Ӣ�۵����Ͻǵ�Сͷ��
	touxiang->setPosition(ccp(m_pProgressView->getPositionX()-120,m_pProgressView->getPositionY()));
	this->addChild(touxiang,2);
	this->addChild(xuekuang,2);
	this->addChild(m_pProgressView, 2);  


	//��ӹ���
	monster1=Monster::create();
	monster1->InitMonsterSprite("monster.png","xue_back.png","xue_fore.png");
	monster1->setPosition(ccp(visibleSize.width-50,visibleSize.height/2));
	mymap->addChild(monster1);//��������ӵ���ͼ�У���������������ͼ�ƶ�
	monster1->StartListen(hero,mymap);
  	

	//�����ͣ��ť
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create("play.png","pause.png",this,menu_selector(HelloWorld::menuPauseCallback));
	pCloseItem->setPosition(ccp(visibleSize.width - pCloseItem->getContentSize().width/2 , visibleSize.height - pCloseItem->getContentSize().height/2));
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	//����updata�¼�
	this->scheduleUpdate();

    return true;
}

void HelloWorld::update(float delta)
{
	
	//�ж��Ƿ���ҡ�˼�������
	CCSize visibleSize1 = CCDirector::sharedDirector()->getVisibleSize();//�õ����ڴ�С
	if(!hero->IsAttack)//������ʱ�ſ�����
	{
	switch(rocker->rocketDirection)
	{
	case  1:	
		hero->SetAnimation("hero_run",8,rocker->rocketRun);	
		if(hero->getPositionX()<=visibleSize1.width-8)//���þ��鳬���ұ�,8���Ըĳ���ϲ����
		{
			if(!hero->JudgePositona(visibleSize1)||mymap->JudgeMap(hero,visibleSize1))//����û���ﴰ���м�λ�û��ߵ�ͼ�Ѿ��ƶ�����Ե�ˣ�����ſ����ƶ�������ֻ���Ŷ���
				hero->setPosition(ccp(hero->getPosition().x+1,hero->getPosition().y)); //������
			//�������ƶ���ͼ
			mymap->MoveMap(hero,visibleSize1);
		}
		break;
	case  2:
		hero->SetAnimation("hero_run",8,rocker->rocketRun);
		hero->setPosition(ccp(hero->getPosition().x, hero->getPosition().y+1));   //������
		break;
	case 3:
		hero->SetAnimation("hero_run",8,rocker->rocketRun);
		if(hero->getPositionX()>=8)//���þ��鳬�����,8���Ըĳ���ϲ����
			hero->setPosition(ccp(hero->getPosition().x-1,hero->getPosition().y));   //������
		break;
	case 4:
		hero->SetAnimation("hero_run",8,rocker->rocketRun);
		hero->setPosition(ccp(hero->getPosition().x,hero->getPosition().y-1));   //������
		break;
	case 0:
		hero->StopAnimation();//ֹͣ���ж������˶�
		break;
	}
	}


	//�ж��Ƿ��������
	if(btn->isTouch)
	{
		if(hero->IsAttack)
			return;//Ӣ�����ڹ���
		hero->AttackAnimation("hero_attack",20,rocker->rocketRun);
	}


	if(hero->IsAttack)//Ӣ�����ڹ���
	{
	  if(!monster1->Isdead)//���ﻹû��
	  {
	    if(abs(hero->getPositionY()-monster1->getPositionY()-mymap->getPositionY())<30)//�����Ӣ��Ӧ����һ������ˮƽ�߶��ϣ���������Ч
	    {
         //����Ƿ���ײ������
	      if (this->isRectCollision(CCRectMake(hero->getPositionX(), hero->getPositionY(),hero->GetSprite()->getContentSize().width-70, hero->GetSprite()->getContentSize().height-30), CCRectMake(monster1->getPositionX()+mymap->getPositionX(), monster1->getPositionY()+mymap->getPositionY(), monster1->GetSprite()->getContentSize().width-30,monster1->GetSprite()->getContentSize().height-20))) 
	         {
		        monster1->HurtAnimation("monster_hurt",2,monster1->MonsterDirecton);//����
	         }
	     }
	  }
	}

	
	if(!monster1->Isdead)//����û��
	{
		if(monster1->IsAttack)//�������ڹ���
		{
			if(abs(hero->getPositionY()-monster1->getPositionY()-mymap->getPositionY())<30)//�����Ӣ��Ӧ����һ������ˮƽ�߶��ϣ���������Ч
			{
				//����Ƿ���ײ��Ӣ��
				if (this->isRectCollision(CCRectMake(hero->getPositionX(), hero->getPositionY(),hero->GetSprite()->getContentSize().width-70, hero->GetSprite()->getContentSize().height-30), CCRectMake(monster1->getPositionX()+mymap->getPositionX(), monster1->getPositionY()+mymap->getPositionY(), monster1->GetSprite()->getContentSize().width-30,monster1->GetSprite()->getContentSize().height-20))) 
				{
					
					m_pProgressView->setCurrentProgress(m_pProgressView->getCurrentProgress()-1);
					
				}

		    }
	}
	}

}
///��ײ���
bool HelloWorld::isRectCollision (CCRect rect1, CCRect rect2)
{
	float x1 = rect1.origin.x;//����1���ĵ�ĺ�����
	float y1 = rect1.origin.y;//����1���ĵ��������
	float w1 = rect1.size.width;//����1�Ŀ��
	float h1 = rect1.size.height;//����1�ĸ߶�
	float x2 = rect2.origin.x;
	float y2 = rect2.origin.y;
	float w2 = rect2.size.width;
	float h2 = rect2.size.height;

	if (x1+w1*0.5<x2-w2*0.5)  
		return false;//����1�ھ���2�󷽣���������ײ
	else if (x1-w1*0.5>x2+w2*0.5)
		return false;//����1�ھ���2�ҷ�����������ײ
	else if (y1+h1*0.5<y2-h2*0.5)
		return false;//����1�ھ���2�·�����������ײ
	else if (y1-h1*0.5>y2+h2*0.5)
		return false;//����1�ھ���2�Ϸ�����������ײ

	return true;
}
//��ͣ����
void HelloWorld::menuPauseCallback(CCObject* pSender)
{
	//�õ����ڵĴ�С
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCRenderTexture *renderTexture = CCRenderTexture::create(visibleSize.width,visibleSize.height);

	//������ǰ��������ӽڵ���Ϣ������renderTexture�С�
	//�������ƽ�ͼ��
	renderTexture->begin(); 
	this->getParent()->visit();
	renderTexture->end();
	//����Ϸ������ͣ��ѹ�볡����ջ�����л���GamePause����
	CCDirector::sharedDirector()->pushScene(Gamepause::scene(renderTexture));

}







