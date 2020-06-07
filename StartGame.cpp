/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "StartGame.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* StartGame::createScene()
{
	return StartGame::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartGame::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto start_label = Label::createWithTTF("Start Game", "fonts/Marker Felt.ttf", 35);
	start_label->setTextColor(cocos2d::Color4B::RED);

	// ��lambda���ʽ��Ϊ�˵��ص�
	auto start_menu_item = MenuItemLabel::create(start_label, [&](Ref* sender) {
		CCLOG("click start game"); // ע�⣬ֻ��debugģʽ�Ż����CCLOG

		// ת������Ϸ������
		auto StartGame_effect = SimpleAudioEngine::getInstance();

		StartGame_effect->playEffect("StartGameEffect.mp3", false,1.0f, 1.0f, 1.0f);

		auto main_game_scene = GameScene::createScene();

		auto transition = TransitionFade::create(0.5f, main_game_scene, Color3B(255, 255, 255));

		Director::getInstance()->replaceScene(transition);
		});
	start_menu_item->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

	auto menu = Menu::createWithItem(start_menu_item);
	menu->setPosition(Vec2::ZERO);

	addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Demo", "fonts/Marker Felt.ttf", 36);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height-20));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("StartGame.png");
	if (sprite == nullptr)
	{
		problemLoading("'StartGame.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}
	//4.add background

	auto background = SimpleAudioEngine::getInstance();

	background->playBackgroundMusic("BackGround.mp3", true);


	return true;
}


void StartGame::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->replaceScene(GameScene::createScene());

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
