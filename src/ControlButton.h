#ifndef __ControlButton_H__
#define __ControlButton_H__
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT; 
class ControlButton :public CCNode
{
public:
	ControlButton();
	~ControlButton();
	CREATE_FUNC(ControlButton);
	//������ͨ��ť,����name_pngΪ��ť�ı���ͼƬ��button_titleΪ��ťͼƬ��Ҫ��ʾ�����֣�numΪ���ֵ�͸����0-100��0Ϊ͸��
	 void CreateButton(const char* name_png,const char* button_title="0",unsigned int num=0);

	//��д��ť�¼� 
	void BindButtonEven();


	/* ����괦�ڰ��²��������а�ťʱ���򴥷�һ�� */ 
	virtual void touchDownAction(CCObject* pSender, CCControlEvent event); 
	/* ����괦�ڰ��²��������а�ť��״̬�£������밴ť��Χ���򴥷�һ�� */  
	virtual void touchDragEnter(CCObject* pSender, CCControlEvent event);  
	/* ����괦�ڰ��²��������а�ť��״̬�£�����뿪��ť��Χ���򴥷�һ�� */  
	 virtual void touchDragExit(CCObject* pSender, CCControlEvent event);  
	/* ����괦�ڰ��²��������а�ť��״̬�£������밴ť��Χ���򴥷���ֻҪ�ﵽ�������Ͳ��ϴ��� */  
	 virtual void touchDragInside(CCObject* pSender, CCControlEvent event);  
	/* ����괦�ڰ��²��������а�ť��״̬�£�����뿪��ť��Χ���򴥷���ֻҪ�ﵽ�������Ͳ��ϴ��� */ 
	 virtual void touchDragOutside(CCObject* pSender, CCControlEvent event);  
	/* ����괦�ڰ��²��������а�ť��״̬�£�����ɿ����ڰ�ť��Χ�ڣ��򴥷�һ�� */
	 virtual void touchUpInside(CCObject* pSender, CCControlEvent event);  
	/* ����괦�ڰ��²��������а�ť��״̬�£�����ɿ����ڰ�ť��Χ�⣬�򴥷�һ�� */  
	 virtual void touchUpOutside(CCObject* pSender, CCControlEvent event);  
	/* ��ʱû�з���������괥������¼��Ĳ���������ע�ͣ�Ӧ�����������¼��жϰ�ť�¼��������� */ 
	virtual void touchCancel(CCObject* pSender, CCControlEvent event);

	//�Ƿ��°�ť
	bool isTouch;
	//��ť�ؼ�����
	CCControlButton* controlBtn;
private:

};
#endif 