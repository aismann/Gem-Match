

#ifndef __ttgame__Card__
#define __ttgame__Card__

#include "cocos2d.h"

using namespace cocos2d;
class Card :public Node
{
public:
	int number;//���ֱ�� ������
	int row, col;
	bool canRemove;//�Ƿ�Ҫ����
	Sprite* sp;
	CREATE_FUNC(Card);
	static Card* createCard(int num, int r, int c);
	bool init();
	void moveTo(int r, int c);
};
#endif /* defined(__ttgame__Card__) */
