#pragma once
#include <MiraiCP.hpp>
#include <vector>

using namespace std;
using namespace MiraiCP;

namespace sbl {

	/*群信息*/
	class ActiveGroupInfo
	{
	public:
		ActiveGroupInfo();
		~ActiveGroupInfo();

		ActiveGroupInfo(QQID gID, QQID bID, bool status = false);
		/*群号*/
		QQID GroupID;
		/*使用的机器人账号*/
		QQID BotID;
		/*群状态 启用/未启用（前提机器人在群里）*/
		bool Status;

		bool operator== (ActiveGroupInfo const& gIF);
		bool operator!= (ActiveGroupInfo const& gIF);
	private:

	};

	static vector<ActiveGroupInfo> ActiveGroups;

	bool addActiveGroup(QQID groupID, QQID botID, bool status = true);
	bool addActiveGroup(ActiveGroupInfo const& info);
	bool removeActiveGroup(QQID groupID, QQID botID);
	bool removeActiveGroup(ActiveGroupInfo const& info);
	bool isGroupActive(QQID groupID, QQID botID);
	bool isGroupActive(ActiveGroupInfo const& info);
}