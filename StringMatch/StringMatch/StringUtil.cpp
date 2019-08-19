#include "StringUtil.h"
#include <iostream>
/*
	//首先寻找与第一个字符一样的字符，若存在，紧随其后查找第相连字符是否与之相同
	//若相同，继续进行，直到搜索到达了相同字符串的起始位置，仍保持相同，则满足前两组匹配
*/
/*
	输入：字符串
	返回：最小长度的周期字符串
*/
std::string StringUtil::GetCyclicSubStr(std::string str)
{
	int length = str.length();
	if (length > 1) {
		std::string result;//加一个'\0'
		int i = 1;
		while (i <= (length / 2)) {
			if (str[0] == str[i])
			{
				result = str.substr(0, i);//[0,i-1]   substr(i) --> [i, end]
				std::string cyclicStr = GetCyclicSubStr(str.substr(i));//获取从此位置开始的子字符串的周期字符串
				if (result == cyclicStr)
					return result;
			}
			i++;
		}
	}
	return str;
}

std::string StringUtil::GetCyclicSubStr(char * str) {
	return GetCyclicSubStr(std::string(str));
}
