#pragma once

#include <string>

class CharactersWrapper
{
public:
	CharactersWrapper();

	std::wstring uppercase_letters_chk1();
	std::wstring lowercase_letters_chk2();
	std::wstring numbers_chk3();
	std::wstring symbols_chk4();
	std::wstring symbols_chk5();
	std::wstring symbols_chk6();
	std::wstring symbols_chk7();
	std::wstring symbols_chk8();
	std::wstring include_characters_edit3();
	std::wstring exclude_characters_edit4();
	std::wstring exclude_alike_characters_chk10();
	std::wstring total();
	int groups_count();

	void set_uppercase_letters_chk1(std::wstring uppercase_letters_chk1);
	void set_lowercase_letters_chk2(std::wstring lowercase_letters_chk2);
	void set_numbers_chk3(std::wstring numbers_chk3);
	void set_symbols_chk4(std::wstring symbols_chk4);
	void set_symbols_chk5(std::wstring symbols_chk5);
	void set_symbols_chk6(std::wstring symbols_chk6);
	void set_symbols_chk7(std::wstring symbols_chk7);
	void set_symbols_chk8(std::wstring symbols_chk8);
	void set_include_characters_edit3(std::wstring include_characters_edit3);
	void set_exclude_characters_edit4(std::wstring exclude_characters_edit4);
	void set_exclude_alike_characters_chk10(std::wstring exclude_alike_characters_chk10);
	void set_total(std::wstring total);
	void set_groups_count(int groups_count);
private:
	std::wstring uppercase_letters_chk1_;
	std::wstring lowercase_letters_chk2_;
	std::wstring numbers_chk3_;
	std::wstring symbols_chk4_;
	std::wstring symbols_chk5_;
	std::wstring symbols_chk6_;
	std::wstring symbols_chk7_;
	std::wstring symbols_chk8_;
	std::wstring include_characters_edit3_;
	std::wstring exclude_characters_edit4_;
	std::wstring exclude_alike_characters_chk10_;
	std::wstring total_;
	int groups_count_;
};
