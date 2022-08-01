#include "KeyWordsRespond.h"

sbl::KeyWordsRespond::KeyWordsRespond()
{
}

sbl::KeyWordsRespond::~KeyWordsRespond()
{
}

sbl::KeyWordsRespond::KeyWordsRespond(string filePath)
{
	loadFromFile(filePath);
}

void sbl::KeyWordsRespond::loadFromFile(string filePath)
{
	_filePath = filePath;
	fstream file(filePath, ios::in);
	if (!file.is_open())
	{
		Logger::logger.error("关键词加载失败，请检查文件路径！");
	}

	string word;
	vector<string> words;
	while (getline(file, word, '\n'))
	{
		words.push_back(word);
	}

	if (words.size() % 2 != 0)
	{
		Logger::logger.error("关键词数量不匹配，请确保关键词与回复一一对应");
	}

	for (int i = 0; i < words.size(); i += 2)
	{
		_keyAndResp.insert(pair(words[i], words[i + 1]));
	}

	file.close();
}

void sbl::KeyWordsRespond::save()
{

	if (_keyAndResp.empty())
	{
		return;
	};

	fstream file(_filePath, ios::out | ios::trunc);
	string out;

	for (map<string, string>::iterator it = _keyAndResp.begin(); it != _keyAndResp.end(); it++)
	{
		out += (it->first + "\n" + it->second + "\n");
	};

	file.write(out.c_str(),out.size());
	file.close();
}

void sbl::KeyWordsRespond::Main(GroupMessageEvent event)
{
	string mes = event.message.toMiraiCode();
	if (mes[0] == '#')
	{
		stringstream mesStream(mes);
		string temp;
		vector<string> mesVec;
		while (getline(mesStream, temp, ' '))
			mesVec.push_back(temp);

		if (mesVec.at(0) == "#添加关键词") {
			addKeyWord(mesVec.at(1), mesVec.at(2));
			event.group.sendMessage("已添加关键词！");
		}
		if (mesVec.at(0) == "#删除关键词") {
			removeKeyWord(mesVec.at(1), mesVec.at(2));
			event.group.sendMessage("已删除关键词！");
		}
		if (mesVec.at(0) == "#关键词列表")
			event.group.sendMessage(showKeyWordsList());
			
	}


	if (_keyAndResp.empty())
	{
		return;
	}

	for (map<string, string>::iterator it = _keyAndResp.begin(); it != _keyAndResp.end(); it++)
	{
		if (MessageChain(PlainText(it->first)) == event.message)
		{
			event.group.sendMessage(it->second);
		}
	}
}

void sbl::KeyWordsRespond::addKeyWord(string key, string resp)
{
	_keyAndResp.insert(pair(key, resp));
}

void sbl::KeyWordsRespond::removeKeyWord(string key, string resp)
{
	if (_keyAndResp.empty())
	{
		return;
	}

	for (map<string, string>::iterator it = _keyAndResp.begin(); it != _keyAndResp.end();)
	{
		if (it->first == key && it->second == resp) {
			_keyAndResp.erase(it++);
		}
		else
		{
			it++;
		};

		if (_keyAndResp.empty())
		{
			return;
		}
	}
}

string sbl::KeyWordsRespond::showKeyWordsList()
{
	string mes;
	mes += "已有一下关键词：";
	if (_keyAndResp.empty())
	{
		return mes;
	}

	mes += "\n";

	for (map<string, string>::iterator it = _keyAndResp.begin(); it != _keyAndResp.end(); it++)
	{
		mes += (it->first + " " + it->second + "\n");
	}

	return mes;
}
