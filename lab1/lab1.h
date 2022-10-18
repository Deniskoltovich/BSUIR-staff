#pragma once
#include<vector>
#include<fstream>
#include<string>
using namespace std;

/// ����� Alphabet
/// \details ����� Alphabet ��������� �������
class Alphabet{
private:
	//! �������� �������
	string pattern;
public:
	void setPattern(string&);
	string getPattern();
	/*!
����� �������� ������������� �� ����� ��������
\param word �����
\see std::string word
*/
	bool is_valid(const string& word);
	/*!
����� �������� ������������� �� ������� ��������
\param a ����� ����� �������
\param b ������ ����� �������
*/
	bool is_valid(const string& a, const string& b);

};

/// ����� Tape
/// \details ����� Tape ��������� ����� ����������� ������
class Tape {
	//! ������ ������ Alphabet
	Alphabet alphabet;
	//! ����������� �������
	pair<string, string> action;
	//! �������
	string pattern;
	//! ���������������� �����
	string word;
	//! �������� ������ ��� �������������
	vector<pair<string, string>> rules;
public:
	void setAlphabet(string&);
	void setRules(vector<pair<string, string>>&);
	void setWord(string&);
	vector<pair<string, string>>& getRules();
	void setAction(pair<string, string>);
	string getWord();
	/*!
����� ��������� ������ ������� � ������� ��� �� �����
\param index ������ �������, ������� ����� �������
\see std::vector<std::pair<std::string, string>> rules
*/
	void delete_rule(int index);
	/*!
������� ��� ������� �� �����
\see std::vector<std::pair<std::string, string>> rules
*/
	void deleteRules();
/*!
������ ���� �� ������
\param[in] index ������ �������, ������� ����� ��������
\param[in] a ����� ����� �������
\param[in] b ������ ����� �������
\see std::vector<std::pair<std::string, string>> rules
*/
	void changeRule(int index, string& a, string& b);

/*!
���������� ������ ������� � ����� 
\param a ����� ����� �������
\param b ������ ����� �������
\see std::vector<std::pair<std::string, string>> rules
*/
	void addRule(string& a, string& b);
	void getInfo(string&);

/*!
��������� � ������� �������, ����� � �������
\see std::vector<std::pair<std::string, string>> rules
\see std::string word
\see std::string pattern
*/
	void Read();

	/*!
��������� �� ����� �������, ����� � �������
\param filename ���� � �����, � ������� ���������� ��������� ��������� ������
\see std::vector<std::pair<std::string, string>> rules
\see std::string word
\see std::string pattern
*/
	void operator>>(const string& filename);
/*!
	������� � ������� �������, ����� � �������
	\see std::vector<std::pair<std::string, string>> rules
	\see std::string word
	\see std::string pattern
	*/

	void Write();
	
};

/// ����� Interpretator
/// \details ����� Interpretator ��������� ���������� ���� ������ ��� ������
class Interpretator  {
private:
	//! ���������������� �����
    string word;
	//! ����������, ������� ������� � ���, ��� �� ������� �������� "-log" � �������
	bool log = false;
	//! ����� ����������� ������
	Tape tape;
	//! ����������, ������������ ����� ���������������� ������
	bool flag = false;
public:
	/*!
	�����������, � ������� �������� ����� �������� ���������������� ����� ��� �������� ������� ��������������
	\param word ����� ��� �������������
	\see std::string word
	*/
	Interpretator(string& word);
	string getWord();
	void setWord(string&);
	/*!
	�����, ����������� ������������ � �����
	\param left ���������, ������� ���� �������� � �����
	\param right ���������, �� ������� �� ������ left
	*/
	void rule_executing(string& left, string& right);
	void changeLog(); /// \brief ������ ���� log � ������, ���� ��� ������� ��������� "-log" � �������
	/*!
	�����, ������� ���������� ������� ��� ������������� � ������������ � ��������� ���������� ���������� �������
	\param rules �������� ����������� ������
	\see std::vector<std::pair<std::string, string>> rules

	*/
	void execute(vector<pair<string, string>>& rules);
};

