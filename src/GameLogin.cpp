#include "GameLogin.h"
#include "GameAbout.h"
#include "HelloWorldScene.h"//������Ϸ�����ͷ�ļ�
#include "SimpleAudioEngine.h"
#include "GameString.h"
using namespace CocosDenshion;
CCScene* GameLogin::scene()
{
    CCScene *scene = CCScene::create();
    GameLogin *layer = GameLogin::create();
    scene->addChild(layer);
    return scene;
}

bool GameLogin::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	//����cocos studio�����Ľ���
	gui::TouchGroup* ul = gui::TouchGroup::create(); 
	gui::Layout* equipe_root =dynamic_cast<gui::Layout*>(GUIReader::shareReader()->widgetFromJsonFile("MyLogin_1.ExportJson"));
	ul->addWidget(equipe_root); 
	this->addChild(ul,2);

	//����ʼ��ť����¼�����
	gui::Button *Btn_Begin = dynamic_cast<gui::Button*>(equipe_root->getChildByName("Begin_Game"));//Begin_GameΪ��Cocos Studio�ж���İ�ť������
	Btn_Begin->addTouchEventListener(this,toucheventselector(GameLogin::TouchBeginButton));
	//�����ð�ť����¼�����
	gui::Button *Btn_Set = dynamic_cast<gui::Button*>(equipe_root->getChildByName("Set_Game")); //Set_GameΪ��Cocos Studio�ж���İ�ť������
	Btn_Set->addTouchEventListener(this,toucheventselector(GameLogin::TouchSetnButton));
	//����ʼ��ť����¼�����
	gui::Button *Btn_Exit = dynamic_cast<gui::Button*>(equipe_root->getChildByName("Exit_Game")); //Exit_GameΪ��Cocos Studio�ж���İ�ť������
	Btn_Exit->addTouchEventListener(this,toucheventselector(GameLogin::TouchExitButton));
	
	gui::CheckBox *Check_Music=dynamic_cast<gui::CheckBox*>(equipe_root->getChildByName("CheckBox_Music"));
	//gui::CheckBox *Check_Music = static_cast<CheckBox*>(GameLogin::seekWidgetByName(ul,"CheckBox_Music"));
	Check_Music->addEventListenerCheckBox(this,checkboxselectedeventselector(GameLogin::TouchCheckMusic));

	//�������
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic( "backmusic.mp3");    //���ر����� 
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);//��������0.0-1.0
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("backmusic.mp3",true);     //��������,true��ʾ�ظ�

    return true;
}
void GameLogin::TouchBeginButton(cocos2d::CCObject* obj,gui::TouchEventType type)
{

      if(type==gui::TouchEventType::TOUCH_EVENT_BEGAN)
	  {
		CCDirector::sharedDirector()->replaceScene(GameString::scene());//������Ϸ������
	  }

}

//������Ϸ��ť�Ļص��¼�
void GameLogin::TouchSetnButton(cocos2d::CCObject* obj,gui::TouchEventType type)
{
	if(type==gui::TouchEventType::TOUCH_EVENT_BEGAN)
	{
		CCDirector::sharedDirector()->replaceScene(GameAbout::scene());//������Ϸ����������
	}
}
//�˳���Ϸ��ť�Ļص��¼�
void GameLogin::TouchExitButton(cocos2d::CCObject* obj,gui::TouchEventType type)
{
	if(type==gui::TouchEventType::TOUCH_EVENT_BEGAN)   
	CCDirector::sharedDirector()->end();
}
//��������
void GameLogin::TouchCheckMusic(cocos2d::CCObject* obj,gui::CheckBoxEventType type)
{
	switch (type)
	{
	case CHECKBOX_STATE_EVENT_SELECTED:
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();//ֹͣ��������
		break;
	case CHECKBOX_STATE_EVENT_UNSELECTED:
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();//���¿�ʼ��������
		break;
	default:
		break;
	}
}


