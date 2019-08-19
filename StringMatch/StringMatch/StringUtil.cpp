#include "StringUtil.h"
#include <iostream>
/*
	//首先寻找与第一个字符一样的字符，若存在，查找从此处开始的子字符串中的最小周期字符串，
	//然后将其与子字符串之前的整体进行对比，若相同，为最小周期字符串，否则，返回其本身
*/
/*
	输入：字符串
	返回：最小长度的周期字符串
*/
std::string StringUtil::GetCyclicSubStr(std::string str)
{
	int length = str.length();
	if (length > 1) {
		std::string result;
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
