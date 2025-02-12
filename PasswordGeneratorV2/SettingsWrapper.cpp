#include "pch.h"
#include "SettingsWrapper.h"

SettingsWrapper::SettingsWrapper()
	: password_length_(0)
	, b_uppercase_letters_chk1_(false)
	, b_lowercase_letters_chk2_(false)
	, b_numbers_chk3_(false)
	, b_symbols_chk4_(false)
	, b_symbols_chk5_(false)
	, b_symbols_chk6_(false)
	, b_symbols_chk7_(false)
	, b_symbols_chk8_(false)
	, include_characters_edit3_(L"")
	, exclude_characters_edit4_(L"")
	, b_each_character_most_once_chk9_(false)
	, b_exclude_alike_characters_chk10_(false)
	, b_pick_characters_every_group_chk11_(false)
{

}

// getter
int SettingsWrapper::password_length() {
	return this->password_length_;
}

bool SettingsWrapper::b_uppercase_letters_chk1() {
	return this->b_uppercase_letters_chk1_;
}

bool SettingsWrapper::b_lowercase_letters_chk2() {
	return this->b_lowercase_letters_chk2_;
}

bool SettingsWrapper::b_numbers_chk3() {
	return this->b_numbers_chk3_;
}

bool SettingsWrapper::b_symbols_chk4() {
	return this->b_symbols_chk4_;
}

bool SettingsWrapper::b_symbols_chk5() {
	return this->b_symbols_chk5_;
}

bool SettingsWrapper::b_symbols_chk6() {
	return this->b_symbols_chk6_;
}

bool SettingsWrapper::b_symbols_chk7() {
	return this->b_symbols_chk7_;
}

bool SettingsWrapper::b_symbols_chk8() {
	return this->b_symbols_chk8_;
}

std::wstring SettingsWrapper::include_characters_edit3() {
	return this->include_characters_edit3_;
}

std::wstring SettingsWrapper::exclude_characters_edit4() {
	return this->exclude_characters_edit4_;
}

bool SettingsWrapper::b_each_character_most_once_chk9() {
	return this->b_each_character_most_once_chk9_;
}

bool SettingsWrapper::b_exclude_alike_characters_chk10() {
	return this->b_exclude_alike_characters_chk10_;
}

bool SettingsWrapper::b_pick_characters_every_group_chk11() {
	return this->b_pick_characters_every_group_chk11_;
}

// setter
void SettingsWrapper::set_password_length(int password_length) {
	this->password_length_ = password_length;
}

void SettingsWrapper::set_b_uppercase_letters_chk1(bool b_uppercase_letters_chk1) {
	this->b_uppercase_letters_chk1_ = b_uppercase_letters_chk1;
}

void SettingsWrapper::set_b_lowercase_letters_chk2(bool b_lowercase_letters_chk2) {
	this->b_lowercase_letters_chk2_ = b_lowercase_letters_chk2;
}

void SettingsWrapper::set_b_numbers_chk3(bool b_numbers_chk3) {
	this->b_numbers_chk3_ = b_numbers_chk3;
}

void SettingsWrapper::set_b_symbols_chk4(bool b_symbols_chk4) {
	this->b_symbols_chk4_ = b_symbols_chk4;
}

void SettingsWrapper::set_b_symbols_chk5(bool b_symbols_chk5) {
	this->b_symbols_chk5_ = b_symbols_chk5;
}

void SettingsWrapper::set_b_symbols_chk6(bool b_symbols_chk6) {
	this->b_symbols_chk6_ = b_symbols_chk6;
}

void SettingsWrapper::set_b_symbols_chk7(bool b_symbols_chk7) {
	this->b_symbols_chk7_ = b_symbols_chk7;
}

void SettingsWrapper::set_b_symbols_chk8(bool b_symbols_chk8) {
	this->b_symbols_chk8_ = b_symbols_chk8;
}

void SettingsWrapper::set_include_characters_edit3(std::wstring include_characters_edit3) {
	this->include_characters_edit3_ = include_characters_edit3;
}

void SettingsWrapper::set_exclude_characters_edit4(std::wstring exclude_characters_edit4) {
	this->exclude_characters_edit4_ = exclude_characters_edit4;
}

void SettingsWrapper::set_b_each_character_most_once_chk9(bool b_each_character_most_once_chk9) {
	this->b_each_character_most_once_chk9_ = b_each_character_most_once_chk9;
}

void SettingsWrapper::set_b_exclude_alike_characters_chk10(bool b_exclude_alike_characters_chk10) {
	this->b_exclude_alike_characters_chk10_ = b_exclude_alike_characters_chk10;
}

void SettingsWrapper::set_b_pick_characters_every_group_chk11(bool b_pick_characters_every_group_chk11) {
	this->b_pick_characters_every_group_chk11_ = b_pick_characters_every_group_chk11;
}
