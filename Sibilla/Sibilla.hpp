#pragma once
#include <json.hpp>
#include <MiraiCP.hpp>
#include "Sibilla.hpp"

#include "GroupManager/ActiveGroup.hpp"
#include "Ability/Ability.h"

using namespace MiraiCP;
using namespace sbl;

const PluginConfig CPPPlugin::config{
		"com.DragonheartLX.Sibilla",            // 插件id
		"SibillaBot",                           // 插件名称
		"0.0.0alpha",                           // 插件版本
		"DragonheartLX",                        // 插件作者
		"A QQ Bot"                              // 可选：插件描述
		/*__DATE__*/                            // 可选：日期
};

// 插件实例
class Main : public CPPPlugin {
public:
	// 配置插件信息
	Main() : CPPPlugin() {}
	~Main() override = default;

	// 入口函数
	void onEnable() override;
	// 退出函数
	void onDisable() override;

	void messageProcess(GroupMessageEvent event);
	void initEnvironment();


	KeyWordsRespond KWR;
};

// 绑定当前插件实例
void MiraiCP::enrollPlugin() {MiraiCP::enrollPlugin(new Main);
}
