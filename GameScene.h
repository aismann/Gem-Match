//
//  GameScene.h
//  ttgame
//
//  Created by zhao on 14-9-3.
//
//

#ifndef __ttgame__GameScene__
#define __ttgame__GameScene__
#include "cocos2d.h"
#include "Card.h"
using namespace cocos2d;
enum class GAMEDIR {
	DIR_UP,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_DOWN
};
class GameScene :public Layer {
public:
	CREATE_FUNC(GameScene);
	static Scene* createScene();
	bool init();
	int startX, startY;
	Card* map[7][7];//7��7�е�����
	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	virtual void onTouchMoved(Touch* touch, Event* unused_event);
	virtual void onTouchEnded(Touch* touch, Event* unused_event);
	void moveCard(GAMEDIR d, int r, int c);
	bool removeCard();//������Ƭ
	void autoDownCard();//�Զ�����
	void down();//����
};
#endif /* defined(__ttgame__GameScene__) */
