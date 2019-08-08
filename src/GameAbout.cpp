#include "GameAbout.h"
#include "GameLogin.h"
CCScene* GameAbout::scene()
{

    CCScene *scene = CCScene::create();
    GameAbout *layer = GameAbout::create();
    scene->addChild(layer);
    return scene;
}

bool GameAbout::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	//����cocos studio�����Ľ���
	gui::TouchGroup* ul = gui::TouchGroup::create(); 
	gui::Layout* equipe_root =dynamic_cast<gui::Layout*>(GUIReader::shareReader()->widgetFromJsonFile("About_1.json"));
	ul->addWidget(equipe_root); 
	this->addChild(ul,2);

	//����ʼ��ť����¼�����
	gui::Button *Btn_Back_Login = dynamic_cast<gui::Button*>(equipe_root->getChildByName("Back_Login"));//Begin_GameΪ��Cocos Studio�ж���İ�ť������
	Btn_Back_Login->addTouchEventListener(this,toucheventselector(GameAbout::TouchBackLoginButton));
    
    return true;
}
void GameAbout::TouchBackLoginButton(cocos2d::CCObject* obj,gui::TouchEventType type)
{

      if(type==gui::TouchEventType::TOUCH_EVENT_BEGAN)
	  {
		  CCDirector::sharedDirector()->replaceScene(GameLogin::scene());//���������ʧ������Ϸ������
	  }

}




