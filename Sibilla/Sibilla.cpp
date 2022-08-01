#include "Sibilla.hpp"

void Main::onEnable() {
	initEnvironment();

	// 请在此处监听
	Event::registerEvent<GroupMessageEvent>([&](GroupMessageEvent event) {

		if (event.message == MessageChain(PlainText(".莉丝上班")))
		{
			if(addActiveGroup(event.group.id(), event.bot.id, true))
				event.group.sendMessage("Sibilla enabled.");
			return;
		};

		if (event.message == MessageChain(PlainText(".莉丝下班")))
		{
			if(removeActiveGroup(event.group.id(), event.bot.id))
				event.group.sendMessage("Sibilla disabled.");
			return;
		};

		if (isGroupActive(event.group.id(), event.bot.id))
		{
			messageProcess(event);
		};

		});

}

void Main::onDisable() {
	/*插件结束前执行
	保存配置，功能数据
	*/
	KWR.save();
}

//处理启用群组的消息并分发至功能
void  Main::messageProcess(GroupMessageEvent event) {

	KWR.Main(event);
};

void  Main::initEnvironment() {

	/*获取配置文件（如果初次启动创建默认配置文件）
	关键词
	功能激活情况
	功能的数据
	*/
	KWR.loadFromFile("KWR.txt");
};
