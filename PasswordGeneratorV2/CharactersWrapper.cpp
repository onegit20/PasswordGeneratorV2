#include "pch.h"
#include "CharactersWrapper.h"

CharactersWrapper::CharactersWrapper()
	: uppercase_letters_chk1_(L"")
	, lowercase_letters_chk2_(L"")
	, numbers_chk3_(L"")
	, symbols_chk4_(L"")
	, symbols_chk5_(L"")
	, symbols_chk6_(L"")
	, symbols_chk7_(L"")
	, symbols_chk8_(L"")
	, include_characters_edit3_(L"")
	, exclude_characters_edit4_(L"")
	, exclude_alike_characters_chk10_(L"")
	, total_(L"")
	, groups_count_(0)
{

}

// getter
std::wstring CharactersWrapper::uppercase_letters_chk1() {
	return uppercase_letters_chk1_;
}

std::wstring CharactersWrapper::lowercase_letters_chk2() {
	return lowercase_letters_chk2_;
}

std::wstring CharactersWrapper::numbers_chk3(){
	return numbers_chk3_;
}

std::wstring CharactersWrapper::symbols_chk4(){
	return symbols_chk4_;
}

std::wstring CharactersWrapper::symbols_chk5(){
	return symbols_chk5_;
}

std::wstring CharactersWrapper::symbols_chk6(){
	return symbols_chk6_;
}

std::wstring CharactersWrapper::symbols_chk7(){
	return symbols_chk7_;
}

std::wstring CharactersWrapper::symbols_chk8() {
	return symbols_chk8_;
}

std::wstring CharactersWrapper::include_characters_edit3() {
	return include_characters_edit3_;
}

std::wstring CharactersWrapper::exclude_characters_edit4() {
	return exclude_characters_edit4_;
}

std::wstring CharactersWrapper::exclude_alike_characters_chk10() {
	return exclude_alike_characters_chk10_;
}

std::wstring CharactersWrapper::total() {
	return total_;
}

int CharactersWrapper::groups_count() {
	return groups_count_;
}

// setter
void CharactersWrapper::set_uppercase_letters_chk1(std::wstring uppercase_letters_chk1) {
	uppercase_letters_chk1_ = uppercase_letters_chk1;
}

void CharactersWrapper::set_lowercase_letters_chk2(std::wstring lowercase_letters_chk2) {
	lowercase_letters_chk2_ = lowercase_letters_chk2;
}

void CharactersWrapper::set_numbers_chk3(std::wstring numbers_chk3){
	numbers_chk3_ = numbers_chk3;
}

void CharactersWrapper::set_symbols_chk4(std::wstring symbols_chk4){
	symbols_chk4_ = symbols_chk4;
}

void CharactersWrapper::set_symbols_chk5(std::wstring symbols_chk5){
	symbols_chk5_ = symbols_chk5;
}

void CharactersWrapper::set_symbols_chk6(std::wstring symbols_chk6){
	symbols_chk6_ = symbols_chk6;
}

void CharactersWrapper::set_symbols_chk7(std::wstring symbols_chk7){
	symbols_chk7_ = symbols_chk7;
}

void CharactersWrapper::set_symbols_chk8(std::wstring symbols_chk8){
	symbols_chk8_ = symbols_chk8;
}

void CharactersWrapper::set_include_characters_edit3(std::wstring include_characters_edit3) {
	include_characters_edit3_ = include_characters_edit3;
}

void CharactersWrapper::set_exclude_characters_edit4(std::wstring exclude_characters_edit4) {
	exclude_characters_edit4_ = exclude_characters_edit4;
}

void CharactersWrapper::set_exclude_alike_characters_chk10(std::wstring exclude_alike_characters_chk10) {
	exclude_alike_characters_chk10_ = exclude_alike_characters_chk10;
}

void CharactersWrapper::set_total(std::wstring total) {
	total_ = total;
}

void CharactersWrapper::set_groups_count(int groups_count) {
	groups_count_ = groups_count;
}
