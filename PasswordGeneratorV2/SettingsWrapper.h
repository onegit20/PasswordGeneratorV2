#pragma once

#include<string>

class SettingsWrapper
{
public:
	SettingsWrapper();

	int password_length();
	bool b_uppercase_letters_chk1();
	bool b_lowercase_letters_chk2();
	bool b_numbers_chk3();
	bool b_symbols_chk4();
	bool b_symbols_chk5();
	bool b_symbols_chk6();
	bool b_symbols_chk7();
	bool b_symbols_chk8();
	std::wstring include_characters_edit3();
	std::wstring exclude_characters_edit4();
	bool b_each_character_most_once_chk9();
	bool b_exclude_alike_characters_chk10();
	bool b_pick_characters_every_group_chk11();

	void set_password_length(int password_length);
	void set_b_uppercase_letters_chk1(bool b_uppercase_letters_chk1);
	void set_b_lowercase_letters_chk2(bool b_lowercase_letters_chk2);
	void set_b_numbers_chk3(bool b_numbers_chk3);
	void set_b_symbols_chk4(bool b_symbols_chk4);
	void set_b_symbols_chk5(bool b_symbols_chk5);
	void set_b_symbols_chk6(bool b_symbols_chk6);
	void set_b_symbols_chk7(bool b_symbols_chk7);
	void set_b_symbols_chk8(bool b_symbols_chk8);
	void set_include_characters_edit3(std::wstring include_characters_edit3);
	void set_exclude_characters_edit4(std::wstring exclude_characters_edit4);
	void set_b_each_character_most_once_chk9(bool b_each_character_most_once_chk9);
	void set_b_exclude_alike_characters_chk10(bool b_exclude_alike_characters_chk10);
	void set_b_pick_characters_every_group_chk11(bool b_pick_characters_every_group_chk11);
private:
	int password_length_;
	bool b_uppercase_letters_chk1_;
	bool b_lowercase_letters_chk2_;
	bool b_numbers_chk3_;
	bool b_symbols_chk4_;
	bool b_symbols_chk5_;
	bool b_symbols_chk6_;
	bool b_symbols_chk7_;
	bool b_symbols_chk8_;
	std::wstring include_characters_edit3_;
	std::wstring exclude_characters_edit4_;
	bool b_each_character_most_once_chk9_;
	bool b_exclude_alike_characters_chk10_;
	bool b_pick_characters_every_group_chk11_;
};
