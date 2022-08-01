#pragma once
#include <iostream>
#include <map>
#include <MiraiCP.hpp>
#include <fstream>

using namespace MiraiCP;
using namespace std;

namespace sbl {

	class KeyWordsRespond
	{
	public:
		KeyWordsRespond();
		~KeyWordsRespond();

		KeyWordsRespond(string filePath);
		void Main(GroupMessageEvent event);
		void loadFromFile(string filePath);
		void save();
		void addKeyWord(string key, string resp);
		void removeKeyWord(string key, string resp);
		string showKeyWordsList();
	private:
		map<string, string> _keyAndResp;
		string _filePath;
	};

}