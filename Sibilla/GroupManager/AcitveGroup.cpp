#include "ActiveGroup.hpp"

sbl::ActiveGroupInfo::ActiveGroupInfo()
{
	GroupID = 0;
	BotID = 0;
	Status = false;
}

sbl::ActiveGroupInfo::~ActiveGroupInfo()
{
}

sbl::ActiveGroupInfo::ActiveGroupInfo(QQID gID, QQID bID, bool status)
{
	GroupID = gID;
	BotID = bID;
	Status = status;
}

bool sbl::ActiveGroupInfo::operator==(ActiveGroupInfo const& gIF)
{
	if (GroupID == gIF.GroupID && BotID == gIF.BotID)
		return true;

	return false;
}

bool sbl::ActiveGroupInfo::operator!=(ActiveGroupInfo const& gIF)
{
	return *this == gIF;
}



bool sbl::addActiveGroup(QQID groupID, QQID botID, bool status) {

	if (ActiveGroups.empty())
	{
		ActiveGroups.push_back(ActiveGroupInfo(groupID, botID, status));
		return true;
	}

	if (find(ActiveGroups.begin(), ActiveGroups.end(), ActiveGroupInfo(groupID, botID, true)) == ActiveGroups.end()) {
		ActiveGroups.push_back(ActiveGroupInfo(groupID, botID, status));
		return true;
	}

	return false;
};

bool sbl::addActiveGroup(ActiveGroupInfo const& info) {

	if (ActiveGroups.empty())
	{
		ActiveGroups.push_back(info);
		return true;
	}

	if (find(ActiveGroups.begin(), ActiveGroups.end(), info) == ActiveGroups.end()) {
		ActiveGroups.push_back(info);
		return true;
	}

	return false;
};

bool sbl::removeActiveGroup(QQID groupID, QQID botID) {

	if (ActiveGroups.empty())
	{
		return true;
	}

	for (vector<ActiveGroupInfo>::iterator it = ActiveGroups.begin(); it != ActiveGroups.end();)
	{
		if (it->GroupID == groupID && it->BotID == botID) {
			ActiveGroups.erase(it);
			return true;
		}
		else {
			it++;
		}

		if (ActiveGroups.empty())
		{
			return true;
		}
	}

	return false;
};

bool sbl::removeActiveGroup(ActiveGroupInfo const& info) {

	if (ActiveGroups.empty())
	{
		return true;
	}

	for (vector<ActiveGroupInfo>::iterator it = ActiveGroups.begin(); it != ActiveGroups.end();)
	{
		if (*it == info) {
			ActiveGroups.erase(it);
			return true;
		}
		else
		{
			it++;
		}

		if (ActiveGroups.empty())
		{
			return true;
		}
	}

	return false;
};

bool sbl::isGroupActive(QQID groupID, QQID botID) {

	if (ActiveGroups.empty())
	{
		return false;
	};

	for (vector<ActiveGroupInfo>::iterator it = ActiveGroups.begin(); it != ActiveGroups.end(); it++)
	{
		if (it->GroupID == groupID && it->BotID == botID)
			return true;
	}
	
	return false;
}

bool sbl::isGroupActive(ActiveGroupInfo const& info)
{
	if (ActiveGroups.empty())
	{
		return false;
	}

	for (vector<ActiveGroupInfo>::iterator it = ActiveGroups.begin(); it != ActiveGroups.end(); it++)
	{
		if (*it == info)
			return true;
	}

	return false;
}

